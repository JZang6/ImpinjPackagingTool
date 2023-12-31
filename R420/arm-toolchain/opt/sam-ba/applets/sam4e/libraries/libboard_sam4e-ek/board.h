/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \page sam4e_ek_board_desc SAM4E-EK - Board Description
 *
 * \section Purpose
 *
 * This file is dedicated to describe the SAM4E-EK board.
 *
 * \section Contents
 *
 *  - For SAM4E-EK information, see \subpage sam4e_ek_board_info.
 *  - For operating frequency information, see \subpage sam4e_ek_opfreq.
 *  - For using portable PIO definitions, see \subpage sam4e_ek_piodef.
 *  - For on-board memories, see \subpage sam4e_ek_mem.
 *  - Several USB definitions are included here, see \subpage sam4e_ek_usb.
 *  - For External components, see \subpage sam4e_ek_extcomp.
 *  - For Individual chip definition, see \subpage sam4e_ek_chipdef.
 *
 * To get more software details and the full list of parameters related to the
 * SAM4E-EK board configuration, please have a look at the source file:
 * \ref board.h\n
 *
 * \section Usage
 *
 *  - The code for booting the board is provided by board_cstartup_xxx.c and
 *    board_lowlevel.c.
 *  - For using board PIOs, board characteristics (clock, etc.) and external
 *    components, see board.h.
 *  - For manipulating memories, see board_memories.h.
 *
 * This file can be used as a template and modified to fit a custom board, with
 * specific PIOs usage or memory connections.
 */

/**
 *  \file board.h
 *
 *  Definition of SAM4E-EK characteristics, PIOs and
 *  external components interface.
 */

#ifndef _BOARD_H_
#define _BOARD_H_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "chip.h"

#include "include/board_lowlevel.h"
#include "include/board_memories.h"
#include "include/hamming.h"
#include "include/math.h"
#include "include/uart_console.h"
#include "include/at25d.h"
#include "include/at25_spi.h"

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * \page sam4e_ek_board_info "SAM4E-EK - Board informations"
 * This page lists several definition related to the board description.
 *
 * \section Definitions
 * - \ref BOARD_NAME
 */

/** Name of the board */
#define BOARD_NAME "SAM4E-EK"

/*----------------------------------------------------------------------------*/
/**
 *  \page sam4e_ek_opfreq "SAM4E-EK - Operating frequencies"
 *  This page lists several definition related to the board operating frequency
 *  (when using the initialization done by board_lowlevel.c).
 *
 *  \section Definitions
 *  - \ref BOARD_MAINOSC
 *  - \ref BOARD_MCK
 */

/** Frequency of the board main oscillator */
#define BOARD_MAINOSC           12000000

/** Master clock frequency (when using board_lowlevel.c) */
#define BOARD_MCK               48000000

/*----------------------------------------------------------------------------*/
/**
 * \page sam4e_ek_piodef "SAM4E-EK - PIO definitions"
 * This pages lists all the pio definitions contained in board.h. The constants
 * are named using the following convention: PIN_* for a constant which defines
 * a single Pin instance (but may include several PIOs sharing the same
 * controller), and PINS_* for a list of Pin instances.
 *
 * UART
 * - \ref PINS_UART
 *
 * EBI
 * - \ref PIN_EBI_DATA_BUS
 * - \ref PIN_EBI_NRD
 * - \ref PIN_EBI_NWE
 * - \ref PIN_EBI_NCS0
 * - \ref PIN_EBI_PSRAM_ADDR_BUS
 * - \ref PIN_EBI_PSRAM_NBS
 * - \ref PIN_EBI_A1
 * - \ref PIN_EBI_LCD_CS
 * - \ref PIN_EBI_LCD_RS
 *
 * LEDs
 * - \ref PIN_LED_0
 * - \ref PIN_LED_1
 * - \ref PIN_LED_2
 * - \ref PIN_LED_3
 * - \ref PINS_LEDS
 *
 * MCI
 * - \ref PINS_MCI
 *
 * Push buttons
 * - \ref PIN_PUSHBUTTON_0
 * - \ref PIN_PUSHBUTTON_1
 * - \ref PIN_PUSHBUTTON_2
 * - \ref PIN_PUSHBUTTON_3
 * - \ref PINS_PUSHBUTTONS
 * - \ref PUSHBUTTON_BP0
 * - \ref PUSHBUTTON_BP1
 * - \ref PUSHBUTTON_BP2
 * - \ref PUSHBUTTON_BP3
 *
 * PWMC
 * - \ref PIN_PWMC_PWMH0
 * - \ref PIN_PWMC_PWMH1
 * - \ref PIN_PWM_LED0
 * - \ref PIN_PWM_LED1
 * - \ref CHANNEL_PWM_LED0
 * - \ref CHANNEL_PWM_LED1
 *
 * SPI
 * - \ref PIN_SPI_MISO
 * - \ref PIN_SPI_MOSI
 * - \ref PIN_SPI_SPCK
 * - \ref PINS_SPI
 * - \ref PIN_SPI_NPCS0_PA11
 *
 * PCK0
 * - \ref PIN_PCK0
 *
 * PIO PARALLEL CAPTURE
 * - \ref PIN_PIODCEN1
 * - \ref PIN_PIODCEN2
 *
 * TWI
 * - \ref TWI_V3XX
 * - \ref PIN_TWI_TWD0
 * - \ref PIN_TWI_TWCK0
 * - \ref PINS_TWI0
 *
 * USART0
 * - \ref PIN_USART0_RXD
 * - \ref PIN_USART0_TXD
 * - \ref PIN_USART0_CTS
 * - \ref PIN_USART0_RTS
 * - \ref PIN_USART0_SCK
 *
 * USB
 * - \ref PIN_USB_VBUS
 *
 * NandFlash
 * - \ref PIN_EBI_NANDOE
 * - \ref PIN_EBI_NANDWE
 * - \ref PIN_EBI_NANDCLE
 * - \ref PIN_EBI_NANDALE
 * - \ref PIN_EBI_NANDIO
 * - \ref BOARD_NF_CE_PIN
 * - \ref BOARD_NF_RB_PIN
 * - \ref PINS_NANDFLASH
 */

/** UART pins (UTXD0 and URXD0) definitions, PA9,10. */
#define PINS_UART  {PIO_PA9A_URXD0 | PIO_PA10A_UTXD0, PIOA, ID_PIOA, \
		PIO_PERIPH_A, PIO_DEFAULT}

/** EBI Data Bus pins */
#define PIN_EBI_DATA_BUS   {0xFF, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** EBI NRD pin */
#define PIN_EBI_NRD        {1 << 11, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** EBI NWE pin */
#define PIN_EBI_NWE        {1 << 8, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** EBI NCS0 pin */
#define PIN_EBI_NCS0       {1 << 14, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}

/** EBI A1 pin */
#define PIN_EBI_A1         {1 << 19, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/* LCD CS pin (NCS3) */
#define PIN_EBI_LCD_CS     {1 << 18, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}
/* LCD RS pin (A1) */
#define PIN_EBI_LCD_RS     {1 << 19, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}

#define LED_BLUE      0
#define LED_AMBER     1
#define LED_GREEN     2
#define LED_RED       3

/** LED #0 pin definition (BLUE). */
#define PIN_LED_0   {PIO_PA0, PIOA, ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}
/** LED #0 pin definition (AMBER). */
#define PIN_LED_1   {PIO_PD20, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
/** LED #1 pin definition (GREEN). */
#define PIN_LED_2   {PIO_PD21, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
/** LED #2 pin definition (RED). */
#define PIN_LED_3   {PIO_PD22, PIO2, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}

/** List of all LEDs definitions. */
#define PINS_LEDS   {PIN_LED_0, PIN_LED_1, PIN_LED_2, PIN_LED_3}

/** MCI pins definition. */
#define PINS_MCI   {0x3fUL << 26, PIOA, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP}
/** MCI pin Card Detect. */
#define PIN_MCI_CD {PIO_PA6, PIOA, ID_PIOA, PIO_INPUT, PIO_PULLUP}

/** 
 * Push button #0 definition. 
 * Attributes = pull-up + debounce + interrupt on rising edge.
 */
#define PIN_PUSHBUTTON_0    {PIO_PA19, PIOA, ID_PIOA, PIO_INPUT, \
		PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE}
/** 
 * Push button #1 definition. 
 * Attributes = pull-up + debounce + interrupt on rising edge.
 */
#define PIN_PUSHBUTTON_1    {PIO_PA20, PIOA, ID_PIOA, PIO_INPUT, \
		PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE}
/** 
 * Push button #2 definition.
 * Attributes = pull-up + debounce + interrupt on rising edge.
 */
#define PIN_PUSHBUTTON_2    {PIO_PA1, PIOA, ID_PIOA, PIO_INPUT, \
		PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE}
/** 
 * Push button #3 definition. 
 * Attributes = pull-up + debounce + interrupt on rising edge.
 */
#define PIN_PUSHBUTTON_3    {PIO_PA2, PIOA, ID_PIOA, PIO_INPUT, \
		PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE}
/** List of all push button definitions. */
#define PINS_PUSHBUTTONS    {PIN_PUSHBUTTON_0, PIN_PUSHBUTTON_1, \
		PIN_PUSHBUTTON_2, PIN_PUSHBUTTON_3}

/** Push button #0 index. */
#define PUSHBUTTON_BP0   0
/** Push button #1 index. */
#define PUSHBUTTON_BP1   1
/** Push button #2 index. */
#define PUSHBUTTON_BP2   2
/** Push button #3 index. */
#define PUSHBUTTON_BP3   3

/** PWMC PWM0 pin definition: Output High. */
#define PIN_PWMC_PWMH0  {PIO_PD20A_PWMH0, PIOD, ID_PIOD, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** PWMC PWM1 pin definition: Output High. */
#define PIN_PWMC_PWMH1  {PIO_PD21A_PWMH1, PIOD, ID_PIOD, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** PWM pins definition for LED0 */
#define PIN_PWM_LED0 PIN_PWMC_PWMH0
/** PWM pins definition for LED1 */
#define PIN_PWM_LED1 PIN_PWMC_PWMH1
/** PWM channel for LED0 */
#define CHANNEL_PWM_LED0 0
/** PWM channel for LED1 */
#define CHANNEL_PWM_LED1 1

/** SPI MISO pin definition. */
#define PIN_SPI_MISO    {PIO_PA12A_MISO, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** SPI MOSI pin definition. */
#define PIN_SPI_MOSI    {PIO_PA13A_MOSI, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** SPI SPCK pin definition. */
#define PIN_SPI_SPCK    {PIO_PA14A_SPCK, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** SPI chip select pin definition. */
#define PIN_SPI_NPCS3_AT25 {PIO_PA5B_NPCS3, PIOA, ID_PIOA, \
		PIO_PERIPH_B, PIO_DEFAULT}
/** List of SPI pin definitions (MISO, MOSI & SPCK). */
#define PINS_SPI        PIN_SPI_MISO, PIN_SPI_MOSI, PIN_SPI_SPCK

/** PCK0 */
#define PIN_PCK0  {PIO_PA6B_PCK0, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** PCK1 */
#define PIN_PCK1  {PIO_PA17B_PCK1, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}

/** PIO PARALLEL CAPTURE */
/** Parallel Capture Mode Data Enable1 */
#define PIN_PIODCEN1    PIO_PA15
/** Parallel Capture Mode Data Enable2 */
#define PIN_PIODCEN2    PIO_PA16

/** TWI ver 3.xx */
#define TWI_V3XX
/** TWI0 data pin */
#define PIN_TWI_TWD0   {PIO_PA3A_TWD0, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** TWI0 clock pin */
#define PIN_TWI_TWCK0  {PIO_PA4A_TWCK0, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** TWI0 pins */
#define PINS_TWI0      {PIN_TWI_TWD0, PIN_TWI_TWCK0}
/** TWI1 data pin */
#define PIN_TWI_TWD1   {PIO_PB4A_TWD1, PIOB, ID_PIOB, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** TWI1 clock pin */
#define PIN_TWI_TWCK1  {PIO_PB5A_TWCK1, PIOB, ID_PIOB, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** TWI1 pins */
#define PINS_TWI1      {PIN_TWI_TWD1, PIN_TWI_TWCK1}

/** USART0 pin RX */
#define PIN_USART0_RXD    {PIO_PB0C_RXD0, PIOB, ID_PIOB, PIO_PERIPH_C, \
		PIO_DEFAULT}
/** USART0 pin TX */
#define PIN_USART0_TXD    {PIO_PB1C_TXD0, PIOB, ID_PIOB, PIO_PERIPH_C, \
		PIO_DEFAULT}
/** USART0 pin CTS */
#define PIN_USART0_CTS    {PIO_PB2C_CTS0, PIOB, ID_PIOB, PIO_PERIPH_C, \
		PIO_DEFAULT}
/** USART0 pin RTS */
#define PIN_USART0_RTS    {PIO_PB3C_RTS0, PIOB, ID_PIOB, PIO_PERIPH_C, \
		PIO_DEFAULT}
/** USART0 pin SCK */
#define PIN_USART0_SCK    {PIO_PB13C_SCK0, PIOB, ID_PIOB, PIO_PERIPH_C, \
		PIO_DEFAULT}

/** USART1 pin RX */
#define PIN_USART1_RXD    {PIO_PA21A_RXD1, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** USART1 pin TX */
#define PIN_USART1_TXD    {PIO_PA22A_TXD1, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** USART1 pin CTS */
#define PIN_USART1_CTS    {PIO_PA25A_CTS1, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** USART1 pin RTS */
#define PIN_USART1_RTS    {PIO_PA24A_RTS1, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}
/** USART1 pin ENABLE */
#define PIN_USART1_EN     {PIO_PA23A_SCK1, PIOA, ID_PIOA, PIO_OUTPUT_0, \
		PIO_DEFAULT}
/** USART1 pin SCK */
#define PIN_USART1_SCK    {PIO_PA23A_SCK1, PIOA, ID_PIOA, PIO_PERIPH_A, \
		PIO_DEFAULT}

/** USB VBus monitoring pin definition. */
#define PIN_USB_VBUS    {PIO_PC21, PIOC, ID_PIOC, PIO_INPUT, PIO_DEFAULT}

/** NandFlash pins definition: OE. */
#define PIN_EBI_NANDOE   {PIO_PC9,  PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** NandFlash pins definition: WE. */
#define PIN_EBI_NANDWE   {PIO_PC10, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** NandFlash pins definition: CLE. */
#define PIN_EBI_NANDCLE  {PIO_PC17, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** NandFlash pins definition: ALE. */
#define PIN_EBI_NANDALE  {PIO_PC16, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** NandFlash pins definition: DATA. */
#define PIN_EBI_NANDIO   {0x000000FF, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP}
/** Nandflash chip enable pin definition. */
#define BOARD_NF_CE_PIN  {PIO_PC14, PIOC, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
/** Nandflash ready/busy pin definition. */
#define BOARD_NF_RB_PIN  {0, 0, 0, 0, 0}

/** Nandflash controller peripheral pins definition. */
#define PINS_NANDFLASH   {PIN_EBI_NANDIO, BOARD_NF_CE_PIN, BOARD_NF_RB_PIN, \
		PIN_EBI_NANDOE, PIN_EBI_NANDWE, PIN_EBI_NANDCLE, PIN_EBI_NANDALE}

/*----------------------------------------------------------------------------*/
/**
 * \page sam4e_ek_usb "SAM4E-EK - USB device"
 *
 * \section Definitions
 * - \ref BOARD_USB_BMATTRIBUTES
 * - \ref CHIP_USB_UDP
 * - \ref CHIP_USB_PULLUP_INTERNAL
 * - \ref CHIP_USB_NUMENDPOINTS
 * - \ref CHIP_USB_ENDPOINTS_MAXPACKETSIZE
 * - \ref CHIP_USB_ENDPOINTS_BANKS
 */

/** 
 * USB attributes configuration descriptor (bus or self powered, 
 * remote wakeup)
 */
#define BOARD_USB_BMATTRIBUTES  USBConfigurationDescriptor_SELFPOWERED_RWAKEUP

/** Indicates chip has an UDP Full Speed. */
#define CHIP_USB_UDP

/** Indicates chip has an internal pull-up. */
#define CHIP_USB_PULLUP_INTERNAL

/** Number of USB endpoints */
#define CHIP_USB_NUMENDPOINTS 8

/** Endpoints max paxcket size */
#define CHIP_USB_ENDPOINTS_MAXPACKETSIZE(i) \
   ((i == 0) ? 64  : \
   ((i == 1) ? 64  : \
   ((i == 2) ? 64  : \
   ((i == 3) ? 64  : \
   ((i == 4) ? 512 : \
   ((i == 5) ? 512 : \
   ((i == 6) ? 64  : \
   ((i == 7) ? 64  : 0 ))))))))

/** Endpoints Number of Bank */
#define CHIP_USB_ENDPOINTS_BANKS(i) \
   ((i == 0) ? 1 : \
   ((i == 1) ? 2 : \
   ((i == 2) ? 2 : \
   ((i == 3) ? 1 : \
   ((i == 4) ? 2 : \
   ((i == 5) ? 2 : \
   ((i == 6) ? 2 : \
   ((i == 7) ? 2 : 0 ))))))))

/*----------------------------------------------------------------------------*/
/**
 * \page sam4e_ek_extcomp "SAM4E-EK - External components"
 * This page lists the definitions related to external on-board components
 * located in the board.h file for the SAM4E-EK.
 *
 * SD Card
 * - \ref BOARD_SD_PINS
 * - \ref BOARD_SD_PIN_CD
 *
 * LCD
 * - \ref BOARD_LCD_ILI9325
 * - \ref BOARD_LCD_PINS
 * - \ref BOARD_BACKLIGHT_PIN
 * - \ref BOARD_LCD_BASE
 * - \ref BOARD_LCD_RS
 * - \ref BOARD_LCD_WIDTH
 * - \ref BOARD_LCD_HEIGHT
 *
 * TouchScreen
 * - \ref BOARD_TSC_ADS7843
 * - \ref PIN_TCS_IRQ
 * - \ref PIN_TCS_BUSY
 * - \ref BOARD_TSC_SPI_BASE
 * - \ref BOARD_TSC_SPI_ID
 * - \ref BOARD_TSC_SPI_PINS
 * - \ref BOARD_TSC_NPCS
 * - \ref BOARD_TSC_NPCS_PIN
 *
 * SmartCard
 * - \ref SMARTCARD_CONNECT_PIN
 * - \ref PIN_ISO7816_RSTMC
 * - \ref PINS_ISO7816
 */

/** MCI pins that shall be configured to access the SD card. */
#define BOARD_SD_PINS    PINS_MCI
/** MCI Card Detect pin. */
#define BOARD_SD_PIN_CD  PIN_MCI_CD

/** Indicates board has an ILI9325 external component to manage LCD. */
#define BOARD_LCD_ILI9325

/** LCD pins definition. */
#define BOARD_LCD_PINS  {PIN_EBI_DATA_BUS, PIN_EBI_NRD, PIN_EBI_NWE, \
		PIN_EBI_NCS1, PIN_EBI_LCD_RS}
/** Backlight pin definition. */
#define BOARD_BACKLIGHT_PIN  {PIO_PC13, PIOC, ID_PIOC, PIO_OUTPUT_0, \
		PIO_DEFAULT}
/** Define ILI9325 base address. */
#define BOARD_LCD_BASE              0x61000000
/** Define ILI9325 register select signal. */
#define BOARD_LCD_RS                (1 << 1)
/** Display width in pixels. */
#define BOARD_LCD_WIDTH             240
/** Display height in pixels. */
#define BOARD_LCD_HEIGHT            320

/** Indicates board has an ADS7843 external component to manage Touch Screen */
#define BOARD_TSC_ADS7843

/** Touchscreen controller IRQ pin definition. */
#define PIN_TSC_IRQ         {PIO_PA16, PIOA, ID_PIOA, PIO_INPUT, PIO_PULLUP}
#define PIN_TSC_IRQ_WUP_ID  (1 << 15)
/** Touchscreen controller Busy pin definition. */
#define PIN_TSC_BUSY        {PIO_PA17, PIOA, ID_PIOA, PIO_INPUT, PIO_PULLUP}

/** Base address of SPI peripheral connected to the touchscreen controller. */
#define BOARD_TSC_SPI_BASE  SPI
/** Identifier of SPI peripheral connected to the touchscreen controller. */
#define BOARD_TSC_SPI_ID    ID_SPI
/** Pins of the SPI peripheral connected to the touchscreen controller. */
#define BOARD_TSC_SPI_PINS  PINS_SPI
/** Chip select connected to the touchscreen controller. */
#define BOARD_TSC_NPCS      0
/** Chip select pin connected to the touchscreen controller. */
#define BOARD_TSC_NPCS_PIN  PIN_SPI_NPCS0_PA11


/*----------------------------------------------------------------------------*/
/**
 * \page sam4e_ek_mem "SAM4E-EK - Memories"
 * This page lists definitions related to internal & external on-board memories.
 *
 * \section NandFlash
 * - \ref BOARD_NF_COMMAND_ADDR
 * - \ref BOARD_NF_ADDRESS_ADDR
 * - \ref BOARD_NF_DATA_ADDR
 *
 * \section NorFlash
 * - \ref BOARD_NORFLASH_ADDR
 * - \ref BOARD_NORFLASH_DFT_BUS_SIZE
 */

/** Address for transferring command bytes to the nandflash. */
#define BOARD_NF_COMMAND_ADDR   0x60400000
/** Address for transferring address bytes to the nandflash. */
#define BOARD_NF_ADDRESS_ADDR   0x60200000
/** Address for transferring data bytes to the nandflash. */
#define BOARD_NF_DATA_ADDR      0x60000000

/** Address for transferring command bytes to the norflash. */
#define BOARD_NORFLASH_ADDR     0x60000000
/** Default NOR bus size after power up reset */
#define BOARD_NORFLASH_DFT_BUS_SIZE 8

/*----------------------------------------------------------------------------*/
/**
 * \page sam4e_ek_chipdef "SAM4E-EK - Individual chip definition"
 * This page lists the definitions related to different chip's definition
 *
 * \section USART
 * - \ref BOARD_PIN_USART_RXD
 * - \ref BOARD_PIN_USART_TXD
 * - \ref BOARD_PIN_USART_CTS
 * - \ref BOARD_PIN_USART_RTS
 * - \ref BOARD_PIN_USART_EN
 * - \ref BOARD_USART_BASE
 * - \ref BOARD_ID_USART
 */

/** Rtc */
#define BOARD_RTC_ID              ID_RTC

/** TWI ID for QTouch application to use */
#define BOARD_ID_TWI_AT42         ID_TWI0
/** TWI Base for QTouch application to use */
#define BOARD_BASE_TWI_AT42       TWI0
/** TWI pins for QTouch application to use */
#define BOARD_PINS_TWI_AT42       PINS_TWI0

/** USART RX pin for application */
#define BOARD_PIN_USART_RXD        PIN_USART1_RXD
/** USART TX pin for application */
#define BOARD_PIN_USART_TXD        PIN_USART1_TXD
/** USART CTS pin for application */
#define BOARD_PIN_USART_CTS        PIN_USART1_CTS
/** USART RTS pin for application */
#define BOARD_PIN_USART_RTS        PIN_USART1_RTS
/** USART ENABLE pin for application */
#define BOARD_PIN_USART_EN         PIN_USART1_EN
/** USART Base for application */
#define BOARD_USART_BASE           USART1
/** USART ID for application */
#define BOARD_ID_USART             ID_USART1

#endif /* #ifndef _BOARD_H_ */

