/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2014, Atmel Corporation
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
 * \page sam9xx5_ek_board_desc SAM9XX5-EK - Board Description
 *
 * \section Purpose
 *
 * This file is dedicated to describe the SAM9XX5-EK board.
 *
 * \section Contents
 *
 *  - SAM9XX5-EK (include SAM9G15-EK, SAM9G25-EK, SAM9G35-EK, SAM9X25-EK and SAM9X35-EK)
 *  - For SAM9XX5-EK information, see \subpage sam9xx5_ek_board_info.
 *  - For operating frequency information, see \subpage sam9xx5_ek_opfreq.
 *  - For using portable PIO definitions, see \subpage sam9xx5_ek_piodef.
 *  - For on-board memories, see \subpage sam9xx5_ek_mem.
 *  - Several USB definitions are included here, see \subpage sam9xx5_ek_usb.
 *  - For External components, see \subpage sam9xx5_ek_extcomp.
 *  - For Individual chip definition, see \subpage sam9xx5_ek_chipdef.
 *
 * To get more software details and the full list of parameters related to the
 * SAM9XX5-EK board configuration, please have a look at the source file:
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
 *  Definition of SAM9XX5-EK (include SAM9G15-EK, SAM9G25-EK, SAM9G35-EK, SAM9X25-EK and SAM9X35-EK) 
 *  characteristics, SAM9XX5-dependant PIOs and external components interfacing.
 */

#ifndef _BOARD_
#define _BOARD_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "chip.h"

/**
 * Libc porting layers
 */
#if defined   ( __CC_ARM   ) /* Keil uvision 4 */
#    include "include/rand.h"
#elif defined ( __ICCARM__ ) /* IAR Ewarm 5.41+ */
#    include "include/rand.h"
#elif defined (  __GNUC__  ) /* GCC CS3 2009q3-68/2010q1-188 */
#    include "include/syscalls.h" /** RedHat Newlib minimal stub */
#endif

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * \page sam9xx5_ek_board_info "SAM9XX5-EK - Board informations"
 * This page lists several definition related to the board description.
 *
 * \section Definitions
 * - \ref BOARD_NAME
 */

/** Name of the board */
#define BOARD_NAME "SAM9XX5-EK"
/** Board definition */
#define sam9xx5ek
/** Family definition (already defined) */
#define sam9xx5
/** Core definition */
#define ARM926EJS


//#define BOARD_REV_A_VB
//#define BOARD_REV_A_EK
#define BOARD_REV_B_EK

/*----------------------------------------------------------------------------*/
/**
 *  \page sam9xx5_ek_opfreq "SAM9XX5-EK - Operating frequencies"
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
#define BOARD_MCK                ((unsigned long)((BOARD_MAINOSC / 3 / 2 / 3) * 200 ))

/*----------------------------------------------------------------------------*/
/**
 * \page sam9xx5_ek_piodef "SAM9XX5-EK - PIO definitions"
 * This pages lists all the pio definitions contained in board.h. The constants
 * are named using the following convention: PIN_* for a constant which defines
 * a single Pin instance (but may include several PIOs sharing the same
 * controller), and PINS_* for a list of Pin instances.
 *
 * DBGU
 * - \ref PINS_DBGU
 *
 * USART0
 * - \ref PIN_USART0_TXD
 * - \ref PIN_USART0_RXD
 * - \ref PIN_USART0_RTS
 * - \ref PIN_USART0_CTS
 * - \ref PIN_USART0_SCK
 * 
 * TWI0
 * - \ref PIN_TWI_TWD0
 * - \ref PIN_TWI_TWCK0
 * - \ref PINS_TWI0
 *
 * SPI0
 * - \ref PIN_SPI0_MISO
 * - \ref PIN_SPI0_MOSI
 * - \ref PIN_SPI0_SPCK
 * - \ref PIN_SPI0_NPCS0
 * - \ref PINS_SPI0
 *
 * SSC
 * - \ref PIN_SSC_TD
 * - \ref PIN_SSC_TK
 * - \ref PIN_SSC_TF
 * - \ref PIN_SSC_RD
 * - \ref PIN_SSC_RK
 * - \ref PIN_SSC_RF
 * - \ref PINS_SSC_CODEC
 *
 * EMAC0
 * - \ref PIN_EMAC0_TXCK
 * - \ref PIN_EMAC0_TX0
 * - \ref PIN_EMAC0_TX1
 * - \ref PIN_EMAC0_TX2
 * - \ref PIN_EMAC0_TX3
 * - \ref PIN_EMAC0_TXEN
 * - \ref PIN_EMAC0_RXER
 * - \ref PIN_EMAC0_RXDV
 * - \ref PIN_EMAC0_RX0
 * - \ref PIN_EMAC0_RX1
 * - \ref PIN_EMAC0_RX2
 * - \ref PIN_EMAC0_RX3
 * - \ref PIN_EMAC0_MDC
 * - \ref PIN_EMAC0_MDIO
 * - \ref PIN_EMAC0_INTR
 * - \ref PINS_EMAC0_MII
 * - \ref PINS_EMAC0_RMII
 * LCD
 * - \ref PINS_LCD
 *
 * ADC
 * - \ref PIN_ADTRG
 *
 * ISI
 * - \ref PIN_ISI_MCK
 * - \ref PIN_ISI_VSYNC
 * - \ref PIN_ISI_HSYNC
 * - \ref PIN_ISI_PCK
 * - \ref PIN_ISI_PINS_DATA
 * - \ref PINS_ISI 
 */

/** List of all DBGU pin definitions. */

/** DBGU Monitor IO pin (detect any DBGU operation). */
#define PIN_DBGU_MON {PIO_PA9A_DRXD, PIOA, ID_PIOA, PIO_INPUT, PIO_IT_RISE_EDGE}
/** DBGU pin definition. */
#define PINS_DBGU   {PIO_PA9A_DRXD | PIO_PA10A_DTXD, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

/** List of all USART pin definitions. */

/** USART0 TXD pin definition. */
#define PIN_USART0_TXD  {PIO_PA0A_TXD0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART0 RXD pin definition. */
#define PIN_USART0_RXD  {PIO_PA1A_RXD0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART0 RTS pin definition. */
#define PIN_USART0_RTS  {PIO_PA2A_RTS0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART0 CTS pin definition. */
#define PIN_USART0_CTS  {PIO_PA3A_CTS0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART0 SCK pin definition. */
#define PIN_USART0_SCK  {PIO_PA4A_SCK0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

/** USART1 TXD pin definition. */
#define PIN_USART1_TXD  {PIO_PA5A_TXD1, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART1 RXD pin definition. */
#define PIN_USART1_RXD  {PIO_PA6A_RXD1, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART1 RTS pin definition. */
#define PIN_USART1_RTS  {PIO_PC27C_RTS1, PIOC, ID_PIOC, PIO_PERIPH_C, PIO_DEFAULT}
/** USART1 CTS pin definition. */
#define PIN_USART1_CTS  {PIO_PC28C_CTS1, PIOC, ID_PIOC, PIO_PERIPH_C, PIO_DEFAULT}
/** USART1 SCK pin definition. */
#define PIN_USART1_SCK  {PIO_PC29C_SCK1, PIOC, ID_PIOC, PIO_PERIPH_C, PIO_DEFAULT}

/** USART2 TXD pin definition. */
#define PIN_USART2_TXD  {PIO_PA7A_TXD2, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART2 RXD pin definition. */
#define PIN_USART2_RXD  {PIO_PA8A_RXD2, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** USART2 RTS pin definition. */
#define PIN_USART2_RTS  {PIO_PB0B_RTS2, PIOB, ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}
/** USART2 CTS pin definition. */
#define PIN_USART2_CTS  {PIO_PB1B_CTS2, PIOB, ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}
/** USART2 SCK pin definition. */
#define PIN_USART2_SCK  {PIO_PB2B_SCK2, PIOB, ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}


/** List of all TWI pin definitions. */

/** TWI0 data pin */
#define PIN_TWI_TWD0   {PIO_PA30A_TWD0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** TWI0 clock pin */
#define PIN_TWI_TWCK0  {PIO_PA31A_TWCK0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** TWI0 pins */
#define PINS_TWI0      PIN_TWI_TWD0, PIN_TWI_TWCK0

/** List of all SPI pin definitions. */

/** SPI0 MISO pin definition. */
#define PIN_SPI0_MISO     {PIO_PA11A_SPI0_MISO, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** SPI0 MOSI pin definition. */
#define PIN_SPI0_MOSI     {PIO_PA12A_SPI0_MOSI, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** SPI0 SPCK pin definition. */
#define PIN_SPI0_SPCK     {PIO_PA13A_SPI0_SPCK, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** SPI0 chip select pin definition. */
#define PIN_SPI0_NPCS0    {PIO_PA14A_SPI0_NPCS0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** List of SPI0 pin definitions (MISO, MOSI & SPCK). */
#define PINS_SPI0         PIN_SPI0_MISO, PIN_SPI0_MOSI, PIN_SPI0_SPCK

/** SPI1 MISO pin definition. */
#define PIN_SPI1_MISO     {PIO_PA21B_SPI1_MISO, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SPI1 MOSI pin definition. */
#define PIN_SPI1_MOSI     {PIO_PA22B_SPI1_MOSI, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SPI1 SPCK pin definition. */
#define PIN_SPI1_SPCK     {PIO_PA23B_SPI1_SPCK, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SPI1 chip select pin definition. */
#define PIN_SPI1_NPCS0    {PIO_PA8B_SPI1_NPCS0, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** List of SPI1 pin definitions (MISO, MOSI & SPCK). */
#define PINS_SPI1         PIN_SPI1_MISO, PIN_SPI1_MOSI, PIN_SPI1_SPCK

/** List of all SSC pin definitions. */

/** SSC pin Transmitter Data (TD) */
#define PIN_SSC_TD        {PIO_PA26B_TD, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SSC pin Transmitter Clock (TK) */
#define PIN_SSC_TK        {PIO_PA24B_TK, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SSC pin Transmitter FrameSync (TF) */
#define PIN_SSC_TF        {PIO_PA25B_TF, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SSC pin RD */
#define PIN_SSC_RD        {PIO_PA27B_RD, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SSC pin RK */
#define PIN_SSC_RK        {PIO_PA28B_RK, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SSC pin RF */
#define PIN_SSC_RF        {PIO_PA29B_RF, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** SSC pins definition for codec. */
#define PINS_SSC_CODEC    PIN_SSC_TD, PIN_SSC_TK, PIN_SSC_TF, \
                          PIN_SSC_RD, PIN_SSC_RK, PIN_SSC_RF

#if defined(CAN0)
/** List of all CAN pin deinitions. */

/** CAN0 pin TX */
#define PIN_CAN0_TX     {PIO_PA10B_CANTX0, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** CAN0 pin RX */
#define PIN_CAN0_RX     {PIO_PA9B_CANRX0, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** CAN0 pins */
#define PINS_CAN0       {(0x3u << 9), PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** CAN1 pin TX */
#define PIN_CAN1_TX     {PIO_PA5B_CANTX1, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** CAN1 pin RX */
#define PIN_CAN1_RX     {PIO_PA6B_CANRX1, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/** CAN0 pins */
#define PINS_CAN1       {(0x3u << 5), PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
#endif

#if defined(EMAC)
/** List of all EMAC pin definitions. */

/** EMAC pin TXCK */
#define PIN_EMAC0_TXCK    {PIO_PB4A_ETXCK,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX0 */
#define PIN_EMAC0_TX0     {PIO_PB9A_ETX0, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX1 */
#define PIN_EMAC0_TX1     {PIO_PB10A_ETX1,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX2 */
#define PIN_EMAC0_TX2     {PIO_PB11A_ETX2,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX3 */
#define PIN_EMAC0_TX3     {PIO_PB12A_ETX3,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TXEN */
#define PIN_EMAC0_TXEN    {PIO_PB7A_ETXEN,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX0 */
#define PIN_EMAC0_RXER    {PIO_PB2A_ERXER,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RXDV */
#define PIN_EMAC0_RXDV    {PIO_PB3A_ERXDV,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX0 */
#define PIN_EMAC0_RX0     {PIO_PB0A_ERX0, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX1 */
#define PIN_EMAC0_RX1     {PIO_PB1A_ERX1, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX2 */
#define PIN_EMAC0_RX2     {PIO_PB13A_ERX2,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX3 */
#define PIN_EMAC0_RX3     {PIO_PB14A_ERX3,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}

/** PHY pin MDC */
#define PIN_EMAC0_MDC     {PIO_PB6A_EMDC, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** PHY pin MDIO */
#define PIN_EMAC0_MDIO    {PIO_PB5A_EMDIO,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** PHY pin INTR */
#define PIN_EMAC0_INTR    {PIO_PB8A_ETXER,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}

/** EMAC pins definition for MII */
#define PINS_EMAC0_MII  PIN_EMAC0_TXCK, PIN_EMAC0_TXEN, \
                        PIN_EMAC0_TX0, PIN_EMAC0_TX1, PIN_EMAC0_TX2, PIN_EMAC0_TX3, \
                        PIN_EMAC0_RXDV, PIN_EMAC0_RXER, \
                        PIN_EMAC0_RX0, PIN_EMAC0_RX1, PIN_EMAC0_RX2, PIN_EMAC0_RX3, \
                        PIN_EMAC0_MDC, PIN_EMAC0_MDIO/*, PIN_EMAC0_INTR*/

/** EMAC pins definition for RMII */
#define PINS_EMAC0_RMII PIN_EMAC0_TXCK, PIN_EMAC0_TXEN, \
                        PIN_EMAC0_TX0, PIN_EMAC0_TX1, \
                        PIN_EMAC0_RX0, PIN_EMAC0_RX1, \
                        PIN_EMAC0_RXDV, PIN_EMAC0_RXER, \
                        PIN_EMAC0_MDC, PIN_EMAC0_MDIO/*, PIN_EMAC0_INTR*/
#endif
#if defined(EMAC0)
/** List of all EMAC pin definitions. */

/** EMAC pin TXCK */
#define PIN_EMAC0_TXCK    {PIO_PB4A_E0_TXCK,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX0 */
#define PIN_EMAC0_TX0     {PIO_PB9A_E0_TX0, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX1 */
#define PIN_EMAC0_TX1     {PIO_PB10A_E0_TX1,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX2 */
#define PIN_EMAC0_TX2     {PIO_PB11A_E0_TX2,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TX3 */
#define PIN_EMAC0_TX3     {PIO_PB12A_E0_TX3,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin TXEN */
#define PIN_EMAC0_TXEN    {PIO_PB7A_E0_TXEN,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX0 */
#define PIN_EMAC0_RXER    {PIO_PB2A_E0_RXER,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RXDV */
#define PIN_EMAC0_RXDV    {PIO_PB3A_E0_RXDV,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX0 */
#define PIN_EMAC0_RX0     {PIO_PB0A_E0_RX0, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX1 */
#define PIN_EMAC0_RX1     {PIO_PB1A_E0_RX1, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX2 */
#define PIN_EMAC0_RX2     {PIO_PB13A_E0_RX2,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** EMAC pin RX3 */
#define PIN_EMAC0_RX3     {PIO_PB14A_E0_RX3,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}

/** PHY pin MDC */
#define PIN_EMAC0_MDC     {PIO_PB6A_E0_MDC, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** PHY pin MDIO */
#define PIN_EMAC0_MDIO    {PIO_PB5A_E0_MDIO,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/** PHY pin INTR */
#define PIN_EMAC0_INTR    {PIO_PB8A_E0_TXER,PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}

/** EMAC pins definition for MII */
#define PINS_EMAC0_MII  PIN_EMAC0_TXCK, PIN_EMAC0_TXEN, \
                        PIN_EMAC0_TX0, PIN_EMAC0_TX1, PIN_EMAC0_TX2, PIN_EMAC0_TX3, \
                        PIN_EMAC0_RXDV, PIN_EMAC0_RXER, \
                        PIN_EMAC0_RX0, PIN_EMAC0_RX1, PIN_EMAC0_RX2, PIN_EMAC0_RX3, \
                        PIN_EMAC0_MDC, PIN_EMAC0_MDIO, PIN_EMAC0_INTR

/** EMAC pins definition for RMII */
#define PINS_EMAC0_RMII PIN_EMAC0_TXCK, PIN_EMAC0_TXEN, \
                        PIN_EMAC0_TX0, PIN_EMAC0_TX1, \
                        PIN_EMAC0_RX0, PIN_EMAC0_RX1, \
                        PIN_EMAC0_RXDV, PIN_EMAC0_RXER, \
                        PIN_EMAC0_MDC, PIN_EMAC0_MDIO, PIN_EMAC0_INTR

#endif

/** LCD pin list. */
#define PINS_LCD        {0x7DFFFFFF, PIOC, ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}

/** ADC ADTRG pin (PB18). */
#define PIN_ADTRG       {PIO_PB18B_ADTRG, PIOB, ID_PIOB, PIO_PERIPH_B, PIO_PULLUP}


#if defined(ISI)
#if defined(BOARD_REV_A_VB)
/** List of ISI pins that must be configured for use by the application. */
#define BOARD_ISI_PIO_RST   {(1<<28), PIOA, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
#define BOARD_ISI_PIO_PWD   {(1<<29), PIOA, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
/** PCK1 use instead of ISI_MCK */
#define BOARD_ISI_PCK       {(1<<12), PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_VSYNC     {(1<<13), PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_HSYNC     {(1<<14), PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_MCK       {(1<<15), PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_PINS_DATA {(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8)|(1<<9)|(1<<10)|(1<<11),\
                             PIOC, ID_PIOC, PIO_PERIPH_B, PIO_PULLUP}

#else

/** List of ISI pins that must be configured for use by the application. */
#define BOARD_ISI_PIO_RST   {PIO_PA7, PIOA, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
#define BOARD_ISI_PIO_PWD   {PIO_PA13, PIOA, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
/** PCK1 use instead of ISI_MCK */
#define BOARD_ISI_PCK       {PIO_PC12B_ISI_PCK, PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_VSYNC     {PIO_PC13B_ISI_VSYNC, PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_HSYNC     {PIO_PC14B_ISI_HSYNC, PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_MCK       {PIO_PC15B_ISI_MCK, PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#define BOARD_ISI_PINS_DATA   {PIO_PC0B_ISI_D0 | PIO_PC1B_ISI_D1 | PIO_PC2B_ISI_D2 | PIO_PC3B_ISI_D3 \
                             | PIO_PC4B_ISI_D4 | PIO_PC5B_ISI_D5 | PIO_PC6B_ISI_D6 | PIO_PC7B_ISI_D7 \
                             | PIO_PC8B_ISI_D8 | PIO_PC9B_ISI_D9 | PIO_PC10B_ISI_D10 | PIO_PC11B_ISI_D11,\
                             PIOC, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
#endif

/** List of ISI pins that must be configured for use by the application. */
#define BOARD_PINS_ISI BOARD_ISI_PIO_RST,\
                       BOARD_ISI_PIO_PWD,\
                       BOARD_ISI_MCK,\
                       BOARD_ISI_VSYNC,\
                       BOARD_ISI_HSYNC,\
                       BOARD_ISI_PCK,\
                       BOARD_ISI_PINS_DATA
#endif

/*----------------------------------------------------------------------------*/
/**
 * \page sam9xx5_ek_usb "SAM9XX5-EK - USB device"
 *
 * \section Definitions
 * - \ref BOARD_USB_BMATTRIBUTES
 * - \ref CHIP_USB_UDP
 * - \ref CHIP_USB_PULLUP_INTERNAL
 * - \ref CHIP_USB_NUMENDPOINTS
 * - \ref CHIP_USB_ENDPOINTS_MAXPACKETSIZE
 * - \ref CHIP_USB_ENDPOINTS_BANKS
 */

#if defined(BOARD_REV_A_VB)
/** USB VBus pin (PC0). */
#define PIN_USB_VBUS      {PIO_PC0, PIOC, ID_PIOC, PIO_INPUT, PIO_DEFAULT}
#elif defined(BOARD_REV_A_EK)
/** USB VBus pin (PB8). */
#define PIN_USB_VBUS      {PIO_PB8, PIOB, ID_PIOB, PIO_INPUT, PIO_DEFAULT}
/** USB OverCurrent detection (PD12) */
#define PIN_USB_OVCUR     {PIO_PD12, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** USB Power Enable A:MicroAB:Active low (PD9) */
#define PIN_USB_POWER_ENA {PIO_PD9, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
/** USB Power Enable B:A:Active low (PD10) */
#define PIN_USB_POWER_ENB {PIO_PD10, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
/** USB Power Enable C:A:Active low (PD11) */
#define PIN_USB_POWER_ENC {PIO_PD11, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
#elif defined(BOARD_REV_B_EK)
/** USB VBus pin (PB16). */
#define PIN_USB_VBUS      {PIO_PB16, PIOB, ID_PIOB, PIO_INPUT, PIO_DEFAULT}
/** USB OverCurrent detection (PB17) */
#define PIN_USB_OVCUR     {PIO_PB17, PIOB, ID_PIOB, PIO_INPUT, PIO_PULLUP}
/** USB Power Enable A:MicroAB:Active low (PD18) */
#define PIN_USB_POWER_ENA {PIO_PD18, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
/** USB Power Enable B:A:Active low (PD19) */
#define PIN_USB_POWER_ENB {PIO_PD19, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
/** USB Power Enable C:A:Active low (PD20) */
#define PIN_USB_POWER_ENC {PIO_PD20, PIOD, ID_PIOD, PIO_OUTPUT_1, PIO_DEFAULT}
#endif

/** USB attributes configuration descriptor (bus or self powered, remote wakeup) */
#define BOARD_USB_BMATTRIBUTES   USBConfigurationDescriptor_SELFPOWERED_NORWAKEUP

/*----------------------------------------------------------------------------*/
/**
 * \page sam9xx5_ek_mem "SAM9XX5-EK - Memories"
 * This page lists definitions related to internal & external on-board memories.
 *
 * \section Sdram
 *
 * - \ref EBI_SDRAM_PINS
 *
 * \section Nandflash
 * - \ref PINS_NANDFLASH
 * - \ref BOARD_NF_IO_PINS
 * - \ref BOARD_NF_CE_PIN
 * - \ref BOARD_NF_RB_PIN
 */

/** EBI SDRAM pins definition. */
#define EBI_SDRAM_PINS  { 0x003FFFCF, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}

#ifdef BOARD_REV_A_VB
/** Nandflash IO pin definition.(PD0-PD3, PD6-PD13)*/
#define BOARD_NF_IO_PINS        {0x00003FCF, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}
/** Nandflash chip enable pin definition.*/
#define BOARD_NF_CE_PIN         {PIO_PD4, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}
/** Nandflash ready/busy pin definition.*/
#define BOARD_NF_RB_PIN         {PIO_PD5, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** Nandflash controller peripheral pins definition. */
#define PINS_NANDFLASH          BOARD_NF_IO_PINS, BOARD_NF_CE_PIN, BOARD_NF_RB_PIN
#endif

#ifdef BOARD_REV_A_EK
/** Nandflash IO pin definition.(PD0-PD3)*/
#define BOARD_NF_IO_PINS        {0x0000000F, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}
/** Nandflash chip enable pin definition.*/
#define BOARD_NF_CE_PIN         {PIO_PD4, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}
/** Nandflash ready/busy pin definition.*/
#define BOARD_NF_RB_PIN         {PIO_PD6, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** Nandflash controller peripheral pins definition. */
#define PINS_NANDFLASH          BOARD_NF_IO_PINS, BOARD_NF_CE_PIN, BOARD_NF_RB_PIN
#endif

#ifdef BOARD_REV_B_EK
/** Nandflash IO pin definition.(PD0-PD3, PD6-PD13)*/
#define BOARD_NF_IO_PINS        {0x00003FCF, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}
/** Nandflash chip enable pin definition.*/
#define BOARD_NF_CE_PIN         {PIO_PD4, PIOD, ID_PIOD, PIO_PERIPH_A, PIO_PULLUP}
/** Nandflash ready/busy pin definition.*/
#define BOARD_NF_RB_PIN         {PIO_PD5, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/* Workaourd for MCI NAND pin conflict */
#define BOARD_MCI0_PIN_CD_PIO   {PIO_PD15, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** Nandflash controller peripheral pins definition. */
#define PINS_NANDFLASH          BOARD_NF_IO_PINS, BOARD_NF_CE_PIN, BOARD_NF_RB_PIN, BOARD_MCI0_PIN_CD_PIO
#endif

/** Address for transferring command bytes to the nandflash, CLE A22*/
#define BOARD_NF_COMMAND_ADDR   0x40400000
/** Address for transferring address bytes to the nandflash, ALE A21*/
#define BOARD_NF_ADDRESS_ADDR   0x40200000 
/** Address for transferring data bytes to the nandflash.*/ 
#define BOARD_NF_DATA_ADDR      0x40000000

/*----------------------------------------------------------------------------*/
/**
 * \page sam9xx5_ek_extcomp "SAM9XX5-EK - External components"
 * This page lists the definitions related to external on-board components
 * located in the board.h file for the SAM9XX5-EK.
 *
 * \section board_sdmmc SD/MMC
 * - \ref BOARD_MCI0_PINS
 * - \ref BOARD_MCI0_PIN_CD
 * - \ref BOARD_MCI1_PINS
 * - \ref BOARD_MCI1_PIN_CD
 * - \ref BOARD_NUM_MCI
 *
 * \section board_emac EMAC
 * - \ref BOARD_EMAC_RST_PINS
 * - \ref BOARD_EMAC_PHY_ADDR
 * - \ref BOARD_EMAC_RUN_PINS
 * 
 * \section board_lcd LCD Properties
 * - \ref BOARD_LCD_WIDTH
 * - \ref BOARD_LCD_HEIGHT
 * - \ref BOARD_LCD_IFWIDTH
 * - \ref BOARD_LCD_FRAMESIZE
 * - \ref BOARD_LCD_TIMING_VFP
 * - \ref BOARD_LCD_TIMING_VBP
 * - \ref BOARD_LCD_TIMING_VPW
 * - \ref BOARD_LCD_TIMING_HFP
 * - \ref BOARD_LCD_TIMING_HBP
 * - \ref BOARD_LCD_TIMING_HPW
 * - \ref BOARD_LCD_FRAMERATE
 * - \ref BOARD_LCD_PIXELCLOCK
 *
 * \section board_ts Touchscreen ADC Properties
 * - \ref BOARD_TOUCHSCREEN_ADCCLK
 * - \ref BOARD_TOUCHSCREEN_STARTUP
 * - \ref BOARD_TOUCHSCREEN_SHTIM
 * - \ref BOARD_TOUCHSCREEN_DEBOUNCE
 */

#if defined(BOARD_REV_A_EK)
/** MCI0 Card detect pin definition. (PD13) */
#define BOARD_MCI0_PIN_CD       {PIO_PD13, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** MCI0 has no WriteProtect pin */
/** MCI1 Card detect pin definition. (PD14) */
#define BOARD_MCI1_PIN_CD       {PIO_PD14, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** MCI1 Write Protect pin Always to GND */
#elif defined(BOARD_REV_A_VB)
/** MCI0 Card detect pin definition. (PC0) */
#define BOARD_MCI0_PIN_CD       {PIO_PC0, PIOC, ID_PIOC, PIO_INPUT, PIO_PULLUP}
/** MCI0 has no WriteProtect pin */
/** MCI1 Card detect pin definition. (PC1) */
#define BOARD_MCI1_PIN_CD       {PIO_PC1, PIOC, ID_PIOC, PIO_INPUT, PIO_PULLUP}
/** MCI1 Write Protect pin Always to GND */
#elif defined(BOARD_REV_B_EK)
/** MCI0 Card detect pin definition. (PD15) */
#define BOARD_MCI0_PIN_CD       {PIO_PD15, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** MCI0 has no WriteProtect pin */
/** MCI1 Card detect pin definition. (PD14) */
#define BOARD_MCI1_PIN_CD       {PIO_PD14, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP}
/** MCI1 Write Protect pin Always to GND */
#endif

/** Total number of MCI interface */
#define BOARD_NUM_MCI           2
/** MCI0 IO pins definition. (PA15-PA20) */
#define BOARD_MCI0_PINS         {0x001F8000, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/** MCI1 IO pins definition. (PA2-PA4, PA11-PA13) */
#define BOARD_MCI1_PINS         {0x0000381C, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}

/** EMAC power control pin (not defined) */
#define BOARD_EMAC_POWER_ALWAYS_ON
/* #define BOARD_EMAC_PIN_PWRDN */

/** EMAC pins on reset, address (000 XX -> 000 00, RMII mode) */
#define BOARD_EMAC_RST_PINS     {PIO_PB0, PIOB, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}, \
                                {PIO_PB1, PIOB, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}, \
                                {PIO_PB3, PIOB, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
/** EMAC PHY address */
#define BOARD_EMAC_PHY_ADDR     0x00
/** EMAC pins runtime (RMII mode) */
#define BOARD_EMAC_RUN_PINS     PINS_EMAC0_RMII

#define BOARD_EMAC_PHY_COMP_DM9161


/** Display width in pixels. */
#define BOARD_LCD_WIDTH             800
/** Display height in pixels. */
#define BOARD_LCD_HEIGHT            480

/** Display interface width in bits. */
#define BOARD_LCD_IFWIDTH           24
/** Frame size in words (height * width * bpp / 32) */
#define BOARD_LCD_FRAMESIZE         (BOARD_LCD_WIDTH * BOARD_LCD_HEIGHT * BOARD_LCD_IFWIDTH / 32)

/** Vertical front porch in number of lines. */
#define BOARD_LCD_TIMING_VFP        22
/** Vertical back porch in number of lines. */
#define BOARD_LCD_TIMING_VBP        21
/** Vertical pulse width in number of lines. */
#define BOARD_LCD_TIMING_VPW        2
/** Horizontal front porch in LCDDOTCLK cycles. */
#define BOARD_LCD_TIMING_HFP        64
/** Horizontal back porch in LCDDOTCLK cycles. */
#define BOARD_LCD_TIMING_HBP        64
/** Horizontal pulse width in LCDDOTCLK cycles. */
#define BOARD_LCD_TIMING_HPW        128

/** Frame rate in Hz. */
#define BOARD_LCD_FRAMERATE         40

/** Pixel clock rate in Hz (HS period * VS period * BOARD_LCD_FRAMERATE). */
#define BOARD_LCD_PIXELCLOCK        ((BOARD_LCD_TIMING_HPW+BOARD_LCD_TIMING_HBP+BOARD_LCD_WIDTH+BOARD_LCD_TIMING_HFP)\
                                    *(BOARD_LCD_TIMING_VPW+BOARD_LCD_TIMING_VBP+BOARD_LCD_HEIGHT+BOARD_LCD_TIMING_VFP)\
                                    *BOARD_LCD_FRAMERATE)

/** Touchscreen ADC clock frequency to use. */
#define BOARD_TOUCHSCREEN_ADCCLK    300000 /* 8MHz max */
/** Touchscreen ADC startup time in �seconds. */
#define BOARD_TOUCHSCREEN_STARTUP   40
/** Touchscreen ADC track and hold time in nanoseconds. */
#define BOARD_TOUCHSCREEN_SHTIM     2000    /* min 1�s at 8MHz */
/** Touchscreen pen debounce time in nanoseconds. */
#define BOARD_TOUCHSCREEN_DEBOUNCE  10000000

/*----------------------------------------------------------------------------*/
/**
 * \page sam9xx5_ek_chipdef "SAM9XX5-EK - Individual chip definition"
 * This page lists the definitions related to different chip's definition
 * located in the board.h file for the SAM9XX5-EK.
 *
 * LEDs
 * - \ref PIN_LED_0
 * - \ref PIN_LED_1
 * - \ref PIN_LED_2
 * - \ref PINS_LEDS
 *
 * Push buttons
 * - \ref PIN_PUSHBUTTON_1
 * - \ref PIN_PUSHBUTTON_2
 * - \ref PINS_PUSHBUTTONS
 * - \ref PUSHBUTTON_BP1
 * - \ref PUSHBUTTON_BP2
 *
 * PCK0 
 * - \ref PIN_PCK0
 *
 * PCK1 
 * - \ref  PIN_PCK1
 */

#ifdef BOARD_REV_A_VB
#define LED_BLUE      0
#define LED_GREEN     1
#define LED_RED       2
#define LED_YELLOW    3

/** LED #0 pin definition (BLUE). */
#define PIN_LED_0   {PIO_PC20, PIOC, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
/** LED #1 pin definition (GREEN). */
#define PIN_LED_1   {PIO_PC21, PIOC, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
/** LED #2 pin definition (RED). */
#define PIN_LED_2   {PIO_PC25, PIOC, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
/** LED #3 pin definition (YELLOW). */
#define PIN_LED_3   {PIO_PC19, PIOC, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}

/** List of all LEDs definitions. */
#define PINS_LEDS   PIN_LED_0, PIN_LED_1, PIN_LED_2, PIN_LED_3
#endif

#if defined(BOARD_REV_A_EK)||defined(BOARD_REV_B_EK)
#define LED_BLUE      0
#define LED_RED       1

/** LED #0 pin definition (LED_BLUE). */
#define PIN_LED_0   {PIO_PB18, PIOB, ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT}
/** LED #1 pin definition (LED_RED). */
#define PIN_LED_1   {PIO_PD21, PIOD, ID_PIOD, PIO_OUTPUT_0, PIO_DEFAULT}

/** List of all LEDs definitions. */
#define PINS_LEDS   PIN_LED_0, PIN_LED_1
#endif

#ifdef BOARD_REV_A_VB
/** Push button #0 definition. Attributes = pull-up + debounce + interrupt on rising edge. */
#define PIN_PUSHBUTTON_1    {PIO_PC2, PIOC, ID_PIOC, PIO_INPUT, PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE}
/** Push button #1 definition. Attributes = pull-up + debounce + interrupt on falling edge. */
#define PIN_PUSHBUTTON_2    {PIO_PC3, PIOC, ID_PIOC, PIO_INPUT, PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE}
#endif

#ifdef BOARD_REV_A_EK
/** Push button #0 definition. Attributes = pull-up + debounce + interrupt on rising edge. */
#define PIN_PUSHBUTTON_1    {PIO_PD18, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE}
/** Push button #1 definition. Attributes = pull-up + debounce + interrupt on falling edge. */
#define PIN_PUSHBUTTON_2    {PIO_PD19, PIOD, ID_PIOD, PIO_INPUT, PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE}
#endif

#ifdef BOARD_REV_B_EK
#define NO_PUSHBUTTON
#endif

/** List of all push button definitions. */
#define PINS_PUSHBUTTONS    PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2

/** Push button #1 index. */
#define PUSHBUTTON_BP1   0
/** Push button #2 index. */
#define PUSHBUTTON_BP2   1
/** Simulate Joystick Left */
#define JOYSTICK_LEFT    1
/** Simulate Joystick Right */
#define JOYSTICK_RIGHT   0

/** PCK0 */
#define PIN_PCK0        {PIO_PB10B_PCK0, PIOB, ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}
/** PCK1 */
#define PIN_PCK1        {PIO_PB9B_PCK1, PIOB, ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}

/** PWM0 */
#define PIN_PWM0        {PIO_PC10, PIOC, ID_PIOC, PIO_PERIPH_C, PIO_DEFAULT}
/** PWM1 */
#define PIN_PWM1        {PIO_PC11, PIOC, ID_PIOC, PIO_PERIPH_C, PIO_DEFAULT}

/*----------------------------------------------------------------------------
 *        Headers for board
 *----------------------------------------------------------------------------*/
 
#include "include/board_lowlevel.h"
#include "include/board_memories.h"
#include "include/dbgu_console.h"
#include "include/dmad.h"
#include "include/dma_hardware_interface.h"
#include "include/hamming.h"

#include "include/math.h"
//#include "include/timetick.h"

#endif /* #ifndef _BOARD_ */

