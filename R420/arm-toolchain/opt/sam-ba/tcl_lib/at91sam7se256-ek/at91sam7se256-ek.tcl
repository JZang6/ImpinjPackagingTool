#  ----------------------------------------------------------------------------
#          ATMEL Microcontroller Software Support
#  ----------------------------------------------------------------------------
#  Copyright (c) 2014, Atmel Corporation
#
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#
#  - Redistributions of source code must retain the above copyright notice,
#  this list of conditions and the disclaimer below.
#
#  Atmel's name may not be used to endorse or promote products derived from
#  this software without specific prior written permission. 
#
#  DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
#  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
#  DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
#  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
#  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
#  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
#  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#  ----------------------------------------------------------------------------

################################################################################
# Fix is only for ROM Code v2.0 to deal with USB read issue.

global target

if { $target(comType) == 0 } {

    puts "-I- Check to apply SAM7SE Rev.B silicon USB workaround"

    if {[catch {TCL_Close $target(handle)} errMsg] } {
            puts "-E- Cannot close the COM port $target(connection) ($errMsg)"
    }

    if {[catch {TCL_Scan} errMsg] } {
            puts "-E- Cannot scan available COM Ports ($errMsg)"
    }

    puts "-I- Open connection $target(connection)"

    if {$samba_os == "linux"} {
        set fd [open "$target(connection)" w+]
    } else {
        set comNum [string range $target(connection) 11 20]
        set fd [open "\\\\.\\$comNum" w+]
    }

    fconfigure $fd -mode "115200,n,8,1"
    fconfigure $fd -blocking true 
    fconfigure $fd -translation binary

    puts $fd "V#"
    flush $fd

    fconfigure $fd -blocking true 
    after 100
    set dummy [read $fd 2]
    set version [read $fd 4]

    puts $fd "#"
    flush $fd

    puts "-I- Close connection $target(connection)"
    catch {close $fd}

    if {[catch {TCL_Scan} errMsg] } {
            puts "-E- Cannot scan available COM Ports ($errMsg)"
    }

    # Reopen the COM Port
    if {[catch {set target(handle) [TCL_Open $target(connection)]} errMsg] } {
            puts "-E- Cannot open $target(connection) ($errMsg)"
    }


    if { [regexp "v2.0" $version] } {

        puts "-I- ROM Code v2.0. Workaround applied"

        # load the new monitor in internal SRAM
        GENERIC::LoadApplet 0x200000 "$libPath(extLib)/$target(board)/monitor.bin"

        # run the new monitor
        go 0x200000

        if {[catch {TCL_Close $target(handle)} errMsg] } {
                puts "-E- Cannot close the COM port $target(connection) ($errMsg)"
        }

        if {[catch {TCL_Scan} errMsg] } {
                puts "-E- Cannot scan available COM Ports ($errMsg)"
        }

        # Reopen the COM Port
        if {[catch {set target(handle) [TCL_Open $target(connection)]} errMsg] } {
                puts "-E- Cannot open $target(connection) ($errMsg)"
        }
    } else {
        puts "-I- ROM Code v1.4. No workaround needed."
    }
}
################################################################################

#                       CHIP NAME     CHIPID_CIDR
array set devicesList { at91sam7se256 0x272a0940
                      }
set cidr_addr 0xFFFFF240
global target
global commandLineMode
set isValidChipOfBoard 0
set version_mask 0xFFFFFFE0
set chipname_list [array names ::devicesList]
set chip_id [format "0x%08x" [TCL_Read_Int $target(handle) $cidr_addr err_code]]
puts "-I- Read device Chip ID at $cidr_addr --- get $chip_id"
set proc_id_masked [format "0x%08x" [expr $chip_id & $version_mask]]
foreach {key value} [array get devicesList] {
   set masked_chipId_Cidr [format "0x%08x" [expr $value & $version_mask]]
   if {[regexp $proc_id_masked $masked_chipId_Cidr] != 0} {
       puts "-I- Found chip : $key (Chip ID : $chip_id)"
       set isValidChipOfBoard 1
       break
   }
} 

if { $isValidChipOfBoard == 0 } {
    if { $commandLineMode == 1 } {
        puts "-E- Invalid device or board!"
    } else {
        tk_messageBox -title "Invalid chip ID" -message "Can't connect $target(board)\n" -icon error -type ok
    }
    TCL_Close $target(handle)
    exit
}

################################################################################
## BOARD SPECIFIC PARAMETERS
################################################################################
namespace eval BOARD {
    variable sramSize         0x8000
    variable maxBootSize      0

    # Vdd Memory 1.8V = 0 / Vdd Memory 3.3V = 1
    variable extRamVdd 1
    # External SDRAM = 0 / External DDR = 1
    variable extRamType 0
    # Set bus width (16 or 32)
    variable extRamDataBusWidth 16
    # DDRAM Model (not used)
    variable extDDRamModel 0
}

# Source procedures for compatibility with older SAM-BA versions
if { [ catch { source "$libPath(extLib)/common/functions.tcl"} errMsg] } {
    if {$commandLineMode == 0} {
        tk_messageBox -title "File not found" -message "Function file not found:\n$errMsg" -type ok -icon error
    } else {
        puts "-E- Function file not found:\n$errMsg"
        puts "-E- Connection abort"
    }
    exit
}

array set memoryAlgo {
    "SRAM"                    "::at91sam7se256_sram"
    "Flash"                   "::at91sam7se256_flash"
    "DataFlash AT45DB/DCB"    "::at91sam7se256_dataflash"
    "SerialFlash AT25/AT26"   "::at91sam7se256_serialflash"
    "EEPROM AT24"             "::at91sam7se256_eeprom"
    "NandFlash"               "::at91sam7se256_nandflash"
    "NorFlash"                "::at91sam7se256_norflash"
    "NorFlash Map"            "::at91sam7se256_norflash_map"
    "Peripheral"              "::at91sam7se256_peripheral"
    "ROM"                     "::at91sam7se256_rom"
    "REMAP"                   "::at91sam7se256_remap"
}

################################################################################
## Low Level Initialization
################################################################################
if { [ catch { source "$libPath(extLib)/$target(board)/lowlevelinit.tcl"} errMsg] } {
    set continue no
    if {$commandLineMode == 0} {
        set continue [tk_messageBox -title "File not found" -message "Low level initialization file not found.\nContinue anyway ?" -icon warning -type yesno]
    } else {
        puts "-E- Low level initialization file not found."
        puts "-E- Connection abort!"
    }
    if {$continue == no} {
        TCL_Close $target(handle)
        exit
    }
}
LOWLEVEL::Init

################################################################################
## SRAM
################################################################################
array set at91sam7se256_sram {
    dftDisplay  1
    dftDefault  0
    dftAddress  0x00200000
    dftSize     0x8000
    dftSend     "RAM::sendFile"
    dftReceive  "RAM::receiveFile"
    dftScripts  ""
}

################################################################################
## FLASH
################################################################################
array set at91sam7se256_flash {
    dftDisplay  1
    dftDefault  1
    dftAddress  0x100000
    dftSize     0x40000
    dftSend     "FLASH::SendFile"
    dftReceive  "FLASH::ReceiveFile"
    dftScripts  "::at91sam7se256_flash_scripts"
}
set FLASH::appletAddr          0x202000
set FLASH::appletMailboxAddr   0x202004
set FLASH::appletFileName      "$libPath(extLib)/$target(board)/applet-flash-at91sam7se256.bin"

array set at91sam7se256_flash_scripts {
        "Erase All Flash"                      "FLASH::EraseAll"
        "Enable BrownOut Detector (GPNVM0)"    "FLASH::ScriptGPNMV 0"
        "Disable BrownOut Detector (GPNVM0)"   "FLASH::ScriptGPNMV 1"
        "Enable BrownOut Reset (GPNVM1)"       "FLASH::ScriptGPNMV 2"
        "Disable BrownOut Reset (GPNVM1)"      "FLASH::ScriptGPNMV 3"
        "Boot from Flash (GPNVM2)"             "FLASH::ScriptGPNMV 4"
        "Boot from ROM (GPNVM2)"               "FLASH::ScriptGPNMV 5"
        "Enable Security Bit"                  "FLASH::ScriptSetSecurityBit"
        "Enable Flash access"                  "FLASH::Init"
}


################################################################################
## SDRAM
################################################################################
#array set at91sam7se256_sdram {
#    dftDisplay  1
#    dftDefault  0
#    dftAddress  0x20000000
#    dftSize     "$GENERIC::memorySize"
#    dftSend     "RAM::sendFile"
#    dftReceive  "RAM::receiveFile"
#    dftScripts  "::at91sam7se256_sdram_scripts"
#}
#
#puts "-I- External RAM Settings :  extRamVdd=$BOARD::extRamVdd, extRamType=$BOARD::extRamType, extRamDataBusWidth=$BOARD::extRamDataBusWidth, extDDRamModel=$BOARD::extDDRamModel"
#
#set RAM::appletAddr          0x202000
#set RAM::appletMailboxAddr   0x202004
#set RAM::appletFileName      "$libPath(extLib)/$target(board)/applet-extram-at91sam7se256.bin"
#
#array set at91sam7se256_sdram_scripts {
#    "Enable SDRAM"   "GENERIC::Init $RAM::appletAddr $RAM::appletMailboxAddr $RAM::appletFileName [list $::target(comType) $::target(traceLevel) $BOARD::extRamVdd $BOARD::extRamType $BOARD::extRamDataBusWidth $BOARD::extDDRamModel]"
#}
#
#
# Initialize SDRAMC
#if {[catch {GENERIC::Init $RAM::appletAddr $RAM::appletMailboxAddr $RAM::appletFileName [list $::target(comType) $::target(traceLevel) $BOARD::extRamVdd $BOARD::extRamType $BOARD::extRamDataBusWidth $BOARD::extDDRamModel]} dummy_err] } {
#    set continue no
#    if {$commandLineMode == 0} {
#        set continue [tk_messageBox -title "External RAM init" -message "External RAM initialization failed.\nExternal RAM access is required to run applets.\nContinue anyway ?" -icon warning -type yesno]
#    } else {
#        puts "-E- Error during external RAM initialization."
#        puts "-E- External RAM access is required to run applets."
#        puts "-E- Connection abort"
#    }
#    # Close link
#    if {$continue == no} {
#        TCL_Close $target(handle)
#        exit
#    }
#} else {
#        puts "-I- External RAM initialized"
#}

# Initialize FLASH after external memory
if {[catch {FLASH::Init } dummy_err] } {
    set continue no
    if {$commandLineMode == 0} {
        set continue [tk_messageBox -title "FLASH init" -message "Failed to initialize FLASH accesses.\nContinue anyway ?" -icon warning -type yesno]
    } else {
        puts "-E- Error during FLASH initialization."
    }
    # Close link
    if {$continue == no} {
        TCL_Close $target(handle)
        exit
    }
} else {
        puts "-I- FLASH initialized"
}

################################################################################
## DATAFLASH
################################################################################

array set at91sam7se256_dataflash {
    dftDisplay  1
    dftDefault  0
    dftAddress  0x0
    dftSize     "$GENERIC::memorySize"
    dftSend     "GENERIC::SendFile"
    dftReceive  "GENERIC::ReceiveFile"
    dftScripts  "::at91sam7se256_dataflash_scripts"
}

array set at91sam7se256_dataflash_scripts {
    "Enable Dataflash (SPI0 CS0)"                        "DATAFLASH::Init 0"
    "Set DF in Power-Of-2 Page Size mode (Binary mode)"  "DATAFLASH::BinaryPage"
    "Erase All"                                          "DATAFLASH::EraseAll"
}

set DATAFLASH::appletAddr          0x20000000
set DATAFLASH::appletMailboxAddr   0x20000004
set DATAFLASH::appletFileName      "$libPath(extLib)/$target(board)/applet-dataflash-at91sam7se256.bin"

################################################################################
## SERIALFLASH
################################################################################

array set at91sam7se256_serialflash {
    dftDisplay  1
    dftDefault  0
    dftAddress  0x0
    dftSize     "$GENERIC::memorySize"
    dftSend     "GENERIC::SendFile"
    dftReceive  "GENERIC::ReceiveFile"
    dftScripts  "::at91sam7se256_serialflash_scripts"
}

array set at91sam7se256_serialflash_scripts {
    "Enable Serialflash (SPI0 CS0)"   "SERIALFLASH::Init 0"
    "Erase All"                       "SERIALFLASH::EraseAll"
}

set SERIALFLASH::appletAddr          0x20000000
set SERIALFLASH::appletMailboxAddr   0x20000004
set SERIALFLASH::appletFileName      "$libPath(extLib)/$target(board)/applet-serialflash-at91sam7se256.bin"

################################################################################
## EEPROM
################################################################################
array set at91sam7se256_eeprom {
    dftDisplay  1
    dftDefault  0
    dftAddress  0x0
    dftSize     "$GENERIC::memorySize"
    dftSend     "GENERIC::SendFile"
    dftReceive  "GENERIC::ReceiveFile"
    dftScripts  "::at91sam7se256_eeprom_scripts"
}

array set at91sam7se256_eeprom_scripts {
    "Enable EEPROM AT24C01x"          "EEPROM::Init 0"
    "Enable EEPROM AT24C02x"          "EEPROM::Init 1"
    "Enable EEPROM AT24C04x"          "EEPROM::Init 2"
    "Enable EEPROM AT24C08x"          "EEPROM::Init 3"
    "Enable EEPROM AT24C16x"          "EEPROM::Init 4"
    "Enable EEPROM AT24C32x"          "EEPROM::Init 5"
    "Enable EEPROM AT24C64x"          "EEPROM::Init 6"
    "Enable EEPROM AT24C128x"         "EEPROM::Init 7"
    "Enable EEPROM AT24C256x"         "EEPROM::Init 8"
    "Enable EEPROM AT24C512x"         "EEPROM::Init 9"
    "Enable EEPROM AT24C1024x"        "EEPROM::Init 10"
}

set EEPROM::appletAddr          0x20000000
set EEPROM::appletMailboxAddr   0x20000004
set EEPROM::appletFileName      "$libPath(extLib)/$target(board)/applet-eeprom-at91sam7se256.bin"

################################################################################
## NANDFLASH
################################################################################
array set at91sam7se256_nandflash {
    dftDisplay  1
    dftDefault  0
    dftAddress  0x0
    dftSize     "$GENERIC::memorySize"
    dftSend     "GENERIC::SendFile"
    dftReceive  "GENERIC::ReceiveFile"
    dftScripts  "::at91sam7se256_nandflash_scripts"
}

array set at91sam7se256_nandflash_scripts {
    "Enable NandFlash"    "NANDFLASH::Init"
    "Erase All"           "NANDFLASH::EraseAll"
    "Scrub NandFlash"     "NANDFLASH::EraseAll $NANDFLASH::scrubErase"
    "List Bad Blocks"     "NANDFLASH::BadBlockList"
}
set NANDFLASH::appletAddr          0x20000000
set NANDFLASH::appletMailboxAddr   0x20000004
set NANDFLASH::appletFileName      "$libPath(extLib)/$target(board)/applet-nandflash-at91sam7se256.bin"

#TCL_Write_Int $target(handle) 0x4000000 0xfffff410
#TCL_Write_Int $target(handle) 0x4000000 0xfffff430

################################################################################
## NORFLASH
################################################################################
array set at91sam7se256_norflash {
    dftDisplay  1
    dftDefault  0
    dftAddress  0x0
    dftSize     "$GENERIC::memorySize"
    dftSend     "GENERIC::SendFile"
    dftReceive  "GENERIC::ReceiveFile"
    dftScripts  "::at91sam7se256_norflash_scripts"
}

array set at91sam7se256_norflash_scripts {
    "Enable NorFlash "    "NORFLASH::Init"
    "Erase All"           "NORFLASH::EraseAll" 
}
set NORFLASH::appletAddr          0x20000000
set NORFLASH::appletMailboxAddr   0x20000004
set NORFLASH::appletFileName      "$libPath(extLib)/$target(board)/applet-norflash-at91sam7se256.bin"

################################################################################
array set at91sam7se256_norflash_map {
    dftDisplay  0
    dftDefault  0
    dftAddress  0x10000000
    dftSize     0x10000000
    dftSend     ""
    dftReceive  ""
    dftScripts  ""
}

array set at91sam7se256_peripheral {
    dftDisplay  0
    dftDefault  0
    dftAddress  0xF0000000
    dftSize     0x10000000
    dftSend     ""
    dftReceive  ""
    dftScripts  ""
}

array set at91sam7se256_rom {
    dftDisplay  0
    dftDefault  0
    dftAddress  0x300000
    dftSize     0x8000
    dftSend     ""
    dftReceive  ""
    dftScripts  ""
}

array set at91sam7se256_remap {
    dftDisplay  0
    dftDefault  0
    dftAddress  0x00000000
    dftSize     0x8000
    dftSend     ""
    dftReceive  ""
    dftScripts  ""
}
