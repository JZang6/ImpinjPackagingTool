/* ---------------------------------------------------------------------------- */
/*                  ATMEL Microcontroller Software Support                      */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2011, ATMEL Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#ifndef SAM3S16_H
#define SAM3S16_H

/** \addtogroup SAM3S16_definitions SAM3S16 definitions
  This file defines all structures and symbols for SAM3S16:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/
/*@{*/

#ifdef __cplusplus
 extern "C" {
#endif 

#ifndef __ASSEMBLY__
#include <stdint.h>
#ifndef __cplusplus
typedef volatile const uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */
#else
typedef volatile       uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */
#endif
typedef volatile       uint32_t WoReg; /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile       uint32_t RwReg; /**< Read-Write 32-bit register (volatile unsigned int) */
#define CAST(type, value) ((type *)(value))
#define REG_ACCESS(type, address) (*(type*)(address)) /**< C code: Register value */
#else
#define CAST(type, value) (value) 
#define REG_ACCESS(type, address) (address) /**< Assembly code: Register address */
#endif

/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR SAM3S16 */
/* ************************************************************************** */
/** \addtogroup SAM3S16_cmsis CMSIS Definitions */
/*@{*/

/**< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ******************************/
  NonMaskableInt_IRQn   = -14, /**<  2 Non Maskable Interrupt                */
  MemoryManagement_IRQn = -12, /**<  4 Cortex-M3 Memory Management Interrupt */
  BusFault_IRQn         = -11, /**<  5 Cortex-M3 Bus Fault Interrupt         */
  UsageFault_IRQn       = -10, /**<  6 Cortex-M3 Usage Fault Interrupt       */
  SVCall_IRQn           = -5,  /**< 11 Cortex-M3 SV Call Interrupt           */
  DebugMonitor_IRQn     = -4,  /**< 12 Cortex-M3 Debug Monitor Interrupt     */
  PendSV_IRQn           = -2,  /**< 14 Cortex-M3 Pend SV Interrupt           */
  SysTick_IRQn          = -1,  /**< 15 Cortex-M3 System Tick Interrupt       */
/******  SAM3S16 specific Interrupt Numbers *********************************/
  
  SUPC_IRQn            =  0, /**<  0 SAM3S16 Supply Controller (SUPC) */
  RSTC_IRQn            =  1, /**<  1 SAM3S16 Reset Controller (RSTC) */
  RTC_IRQn             =  2, /**<  2 SAM3S16 Real Time Clock (RTC) */
  RTT_IRQn             =  3, /**<  3 SAM3S16 Real Time Timer (RTT) */
  WDT_IRQn             =  4, /**<  4 SAM3S16 Watchdog Timer (WDT) */
  PMC_IRQn             =  5, /**<  5 SAM3S16 Power Management Controller (PMC) */
  EFC_IRQn             =  6, /**<  6 SAM3S16 Enhanced Embedded Flash Controller (EFC) */
  UART0_IRQn           =  8, /**<  8 SAM3S16 UART 0 (UART0) */
  UART1_IRQn           =  9, /**<  9 SAM3S16 UART 1 (UART1) */
  SMC_IRQn             = 10, /**< 10 SAM3S16 SMC (SMC) */
  PIOA_IRQn            = 11, /**< 11 SAM3S16 Parallel I/O Controller A (PIOA) */
  PIOB_IRQn            = 12, /**< 12 SAM3S16 Parallel I/O Controller B (PIOB) */
  PIOC_IRQn            = 13, /**< 13 SAM3S16 Parallel I/O Controller C (PIOC) */
  USART0_IRQn          = 14, /**< 14 SAM3S16 USART 0 (USART0) */
  USART1_IRQn          = 15, /**< 15 SAM3S16 USART 1 (USART1) */
  HSMCI_IRQn           = 18, /**< 18 SAM3S16 High Speed Multimedia Card Interface (HSMCI) */
  TWI0_IRQn            = 19, /**< 19 SAM3S16 Two Wire Interface 0 (TWI0) */
  TWI1_IRQn            = 20, /**< 20 SAM3S16 Two Wire Interface 1 (TWI1) */
  SPI_IRQn             = 21, /**< 21 SAM3S16 Serial Peripheral Interface (SPI) */
  SSC_IRQn             = 22, /**< 22 SAM3S16 Synchronous Serial Controller (SSC) */
  TC0_IRQn             = 23, /**< 23 SAM3S16 Timer/Counter 0 (TC0) */
  TC1_IRQn             = 24, /**< 24 SAM3S16 Timer/Counter 1 (TC1) */
  TC2_IRQn             = 25, /**< 25 SAM3S16 Timer/Counter 2 (TC2) */
  TC3_IRQn             = 26, /**< 26 SAM3S16 Timer/Counter 3 (TC3) */
  TC4_IRQn             = 27, /**< 27 SAM3S16 Timer/Counter 4 (TC4) */
  TC5_IRQn             = 28, /**< 28 SAM3S16 Timer/Counter 5 (TC5) */
  ADC_IRQn             = 29, /**< 29 SAM3S16 Analog-to-Digital Converter (ADC) */
  DACC_IRQn            = 30, /**< 30 SAM3S16 Digital-to-Analog Converter (DACC) */
  PWM_IRQn             = 31, /**< 31 SAM3S16 Pulse Width Modulation (PWM) */
  CRCCU_IRQn           = 32, /**< 32 SAM3S16 CRC Calculation Unit (CRCCU) */
  ACC_IRQn             = 33, /**< 33 SAM3S16 Analog Comparator (ACC) */
  UDP_IRQn             = 34  /**< 34 SAM3S16 USB Device Port (UDP) */
} IRQn_Type;

/**
 * \brief Configuration of the Cortex-M3 Processor and Core Peripherals 
 */

#define __MPU_PRESENT          1 /**< SAM3S16 does provide a MPU */
#define __NVIC_PRIO_BITS       4 /**< SAM3S16 uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig 0 /**< Set to 1 if different SysTick Config is used */

/*@}*/

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR SAM3S16 */
/* ************************************************************************** */
/** \addtogroup SAM3S16_api Peripheral Software API */
/*@{*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Analog Comparator Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_ACC Analog Comparator Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Acc hardware registers */
typedef struct {
  WoReg ACC_CR;        /**< \brief (Acc Offset: 0x00) Control Register */
  RwReg ACC_MR;        /**< \brief (Acc Offset: 0x04) Mode Register */
  RoReg Reserved1[7];
  WoReg ACC_IER;       /**< \brief (Acc Offset: 0x24) Interrupt Enable Register */
  WoReg ACC_IDR;       /**< \brief (Acc Offset: 0x28) Interrupt Disable Register */
  RoReg ACC_IMR;       /**< \brief (Acc Offset: 0x2C) Interrupt Mask Register */
  RoReg ACC_ISR;       /**< \brief (Acc Offset: 0x30) Interrupt Status Register */
  RoReg Reserved2[24];
  RwReg ACC_ACR;       /**< \brief (Acc Offset: 0x94) Analog Control Register */
  RoReg Reserved3[19];
  RwReg ACC_WPMR;      /**< \brief (Acc Offset: 0xE4) Write Protect Mode Register */
  RoReg ACC_WPSR;      /**< \brief (Acc Offset: 0xE8) Write Protect Status Register */
} Acc;
#endif /* __ASSEMBLY__ */
/* -------- ACC_CR : (ACC Offset: 0x00) Control Register -------- */
#define ACC_CR_SWRST (0x1u << 0) /**< \brief (ACC_CR) SoftWare ReSeT */
/* -------- ACC_MR : (ACC Offset: 0x04) Mode Register -------- */
#define ACC_MR_SELMINUS_Pos 0
#define ACC_MR_SELMINUS_Msk (0x7u << ACC_MR_SELMINUS_Pos) /**< \brief (ACC_MR) SELection for MINUS comparator input */
#define   ACC_MR_SELMINUS_TS (0x0u << 0) /**< \brief (ACC_MR) SelectTS */
#define   ACC_MR_SELMINUS_ADVREF (0x1u << 0) /**< \brief (ACC_MR) Select ADVREF */
#define   ACC_MR_SELMINUS_DAC0 (0x2u << 0) /**< \brief (ACC_MR) Select DAC0 */
#define   ACC_MR_SELMINUS_DAC1 (0x3u << 0) /**< \brief (ACC_MR) Select DAC1 */
#define   ACC_MR_SELMINUS_AD0 (0x4u << 0) /**< \brief (ACC_MR) Select AD0 */
#define   ACC_MR_SELMINUS_AD1 (0x5u << 0) /**< \brief (ACC_MR) Select AD1 */
#define   ACC_MR_SELMINUS_AD2 (0x6u << 0) /**< \brief (ACC_MR) Select AD2 */
#define   ACC_MR_SELMINUS_AD3 (0x7u << 0) /**< \brief (ACC_MR) Select AD3 */
#define ACC_MR_SELPLUS_Pos 4
#define ACC_MR_SELPLUS_Msk (0x7u << ACC_MR_SELPLUS_Pos) /**< \brief (ACC_MR) SELection for PLUS comparator input */
#define   ACC_MR_SELPLUS_AD0 (0x0u << 4) /**< \brief (ACC_MR) Select AD0 */
#define   ACC_MR_SELPLUS_AD1 (0x1u << 4) /**< \brief (ACC_MR) Select AD1 */
#define   ACC_MR_SELPLUS_AD2 (0x2u << 4) /**< \brief (ACC_MR) Select AD2 */
#define   ACC_MR_SELPLUS_AD3 (0x3u << 4) /**< \brief (ACC_MR) Select AD3 */
#define   ACC_MR_SELPLUS_AD4 (0x4u << 4) /**< \brief (ACC_MR) Select AD4 */
#define   ACC_MR_SELPLUS_AD5 (0x5u << 4) /**< \brief (ACC_MR) Select AD5 */
#define   ACC_MR_SELPLUS_AD6 (0x6u << 4) /**< \brief (ACC_MR) Select AD6 */
#define   ACC_MR_SELPLUS_AD7 (0x7u << 4) /**< \brief (ACC_MR) Select AD7 */
#define ACC_MR_ACEN (0x1u << 8) /**< \brief (ACC_MR) Analog Comparator ENable */
#define   ACC_MR_ACEN_DIS (0x0u << 8) /**< \brief (ACC_MR) Analog Comparator Disabled. */
#define   ACC_MR_ACEN_EN (0x1u << 8) /**< \brief (ACC_MR) Analog Comparator Enabled. */
#define ACC_MR_EDGETYP_Pos 9
#define ACC_MR_EDGETYP_Msk (0x3u << ACC_MR_EDGETYP_Pos) /**< \brief (ACC_MR) EDGE TYPe */
#define   ACC_MR_EDGETYP_RISING (0x0u << 9) /**< \brief (ACC_MR) only rising edge of comparator output */
#define   ACC_MR_EDGETYP_FALLING (0x1u << 9) /**< \brief (ACC_MR) falling edge of comparator output */
#define   ACC_MR_EDGETYP_ANY (0x2u << 9) /**< \brief (ACC_MR) any edge of comparator output */
#define ACC_MR_INV (0x1u << 12) /**< \brief (ACC_MR) INVert comparator output */
#define   ACC_MR_INV_DIS (0x0u << 12) /**< \brief (ACC_MR) Analog Comparator output is directly processed. */
#define   ACC_MR_INV_EN (0x1u << 12) /**< \brief (ACC_MR) Analog Comparator output is inverted prior to being processed. */
#define ACC_MR_SELFS (0x1u << 13) /**< \brief (ACC_MR) SELection of Fault Source */
#define   ACC_MR_SELFS_CF (0x0u << 13) /**< \brief (ACC_MR) the CF flag is used to drive the FAULT output. */
#define   ACC_MR_SELFS_OUTPUT (0x1u << 13) /**< \brief (ACC_MR) the output of the Analog Comparator flag is used to drive the FAULT output. */
#define ACC_MR_FE (0x1u << 14) /**< \brief (ACC_MR) Fault Enable */
#define   ACC_MR_FE_DIS (0x0u << 14) /**< \brief (ACC_MR) the FAULT output is tied to 0. */
#define   ACC_MR_FE_EN (0x1u << 14) /**< \brief (ACC_MR) the FAULT output is driven by the signal defined by SELFS. */
/* -------- ACC_IER : (ACC Offset: 0x24) Interrupt Enable Register -------- */
#define ACC_IER_CE (0x1u << 0) /**< \brief (ACC_IER) Comparison Edge */
/* -------- ACC_IDR : (ACC Offset: 0x28) Interrupt Disable Register -------- */
#define ACC_IDR_CE (0x1u << 0) /**< \brief (ACC_IDR) Comparison Edge */
/* -------- ACC_IMR : (ACC Offset: 0x2C) Interrupt Mask Register -------- */
#define ACC_IMR_CE (0x1u << 0) /**< \brief (ACC_IMR) Comparison Edge */
/* -------- ACC_ISR : (ACC Offset: 0x30) Interrupt Status Register -------- */
#define ACC_ISR_CE (0x1u << 0) /**< \brief (ACC_ISR) Comparison Edge */
#define ACC_ISR_SCO (0x1u << 1) /**< \brief (ACC_ISR) Synchronized Comparator Output */
#define ACC_ISR_MASK (0x1u << 31) /**< \brief (ACC_ISR)  */
/* -------- ACC_ACR : (ACC Offset: 0x94) Analog Control Register -------- */
#define ACC_ACR_ISEL (0x1u << 0) /**< \brief (ACC_ACR) Current SELection */
#define   ACC_ACR_ISEL_LOPW (0x0u << 0) /**< \brief (ACC_ACR) low power option. */
#define   ACC_ACR_ISEL_HISP (0x1u << 0) /**< \brief (ACC_ACR) high speed option. */
#define ACC_ACR_HYST_Pos 1
#define ACC_ACR_HYST_Msk (0x3u << ACC_ACR_HYST_Pos) /**< \brief (ACC_ACR) HYSTeresis selection */
#define ACC_ACR_HYST(value) ((ACC_ACR_HYST_Msk & ((value) << ACC_ACR_HYST_Pos)))
/* -------- ACC_WPMR : (ACC Offset: 0xE4) Write Protect Mode Register -------- */
#define ACC_WPMR_WPEN (0x1u << 0) /**< \brief (ACC_WPMR) Write Protect Enable */
#define ACC_WPMR_WPKEY_Pos 8
#define ACC_WPMR_WPKEY_Msk (0xffffffu << ACC_WPMR_WPKEY_Pos) /**< \brief (ACC_WPMR) Write Protect KEY */
#define ACC_WPMR_WPKEY(value) ((ACC_WPMR_WPKEY_Msk & ((value) << ACC_WPMR_WPKEY_Pos)))
/* -------- ACC_WPSR : (ACC Offset: 0xE8) Write Protect Status Register -------- */
#define ACC_WPSR_WPROTERR (0x1u << 0) /**< \brief (ACC_WPSR) Write PROTection ERRor */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Analog-to-digital Converter */
/* ============================================================================= */
/** \addtogroup SAM3S16_ADC Analog-to-digital Converter */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Adc hardware registers */
typedef struct {
  WoReg ADC_CR;        /**< \brief (Adc Offset: 0x00) Control Register */
  RwReg ADC_MR;        /**< \brief (Adc Offset: 0x04) Mode Register */
  RwReg ADC_SEQR1;     /**< \brief (Adc Offset: 0x08) Channel Sequence Register 1 */
  RwReg ADC_SEQR2;     /**< \brief (Adc Offset: 0x0C) Channel Sequence Register 2 */
  WoReg ADC_CHER;      /**< \brief (Adc Offset: 0x10) Channel Enable Register */
  WoReg ADC_CHDR;      /**< \brief (Adc Offset: 0x14) Channel Disable Register */
  RoReg ADC_CHSR;      /**< \brief (Adc Offset: 0x18) Channel Status Register */
  RoReg Reserved1[1];
  RoReg ADC_LCDR;      /**< \brief (Adc Offset: 0x20) Last Converted Data Register */
  WoReg ADC_IER;       /**< \brief (Adc Offset: 0x24) Interrupt Enable Register */
  WoReg ADC_IDR;       /**< \brief (Adc Offset: 0x28) Interrupt Disable Register */
  RoReg ADC_IMR;       /**< \brief (Adc Offset: 0x2C) Interrupt Mask Register */
  RoReg ADC_ISR;       /**< \brief (Adc Offset: 0x30) Interrupt Status Register */
  RoReg Reserved2[2];
  RoReg ADC_OVER;      /**< \brief (Adc Offset: 0x3C) Overrun Status Register */
  RwReg ADC_EMR;       /**< \brief (Adc Offset: 0x40) Extended Mode Register */
  RwReg ADC_CWR;       /**< \brief (Adc Offset: 0x44) Compare Window Register */
  RwReg ADC_CGR;       /**< \brief (Adc Offset: 0x48) Channel Gain Register */
  RwReg ADC_COR;       /**< \brief (Adc Offset: 0x4C) Channel Offset Register */
  RoReg ADC_CDR[15];   /**< \brief (Adc Offset: 0x50) Channel Data Register */
  RoReg Reserved3[2];
  RwReg ADC_ACR;       /**< \brief (Adc Offset: 0x94) Analog Control Register */
  RoReg Reserved4[10];
  RwReg ADC_TRGR;      /**< \brief (Adc Offset: 0xC0) Trigger Register */
  RoReg Reserved5[8];
  RwReg ADC_WPMR;      /**< \brief (Adc Offset: 0xE4) Write Protect Mode Register */
  RoReg ADC_WPSR;      /**< \brief (Adc Offset: 0xE8) Write Protect Status Register */
  RoReg Reserved6[5];
  RwReg ADC_RPR;       /**< \brief (Adc Offset: 0x100) Receive Pointer Register */
  RwReg ADC_RCR;       /**< \brief (Adc Offset: 0x104) Receive Counter Register */
  RwReg ADC_TPR;       /**< \brief (Adc Offset: 0x108) Transmit Pointer Register */
  RwReg ADC_TCR;       /**< \brief (Adc Offset: 0x10C) Transmit Counter Register */
  RwReg ADC_RNPR;      /**< \brief (Adc Offset: 0x110) Receive Next Pointer Register */
  RwReg ADC_RNCR;      /**< \brief (Adc Offset: 0x114) Receive Next Counter Register */
  RwReg ADC_TNPR;      /**< \brief (Adc Offset: 0x118) Transmit Next Pointer Register */
  RwReg ADC_TNCR;      /**< \brief (Adc Offset: 0x11C) Transmit Next Counter Register */
  WoReg ADC_PTCR;      /**< \brief (Adc Offset: 0x120) Transfer Control Register */
  RoReg ADC_PTSR;      /**< \brief (Adc Offset: 0x124) Transfer Status Register */
} Adc;
#endif /* __ASSEMBLY__ */
/* -------- ADC_CR : (ADC Offset: 0x00) Control Register -------- */
#define ADC_CR_SWRST (0x1u << 0) /**< \brief (ADC_CR) Software Reset */
#define ADC_CR_START (0x1u << 1) /**< \brief (ADC_CR) Start Conversion */
/* -------- ADC_MR : (ADC Offset: 0x04) Mode Register -------- */
#define ADC_MR_TRGEN (0x1u << 0) /**< \brief (ADC_MR) Trigger Enable */
#define   ADC_MR_TRGEN_DIS (0x0u << 0) /**< \brief (ADC_MR) Hardware triggers are disabled. Starting a conversion is only possible by software. */
#define   ADC_MR_TRGEN_EN (0x1u << 0) /**< \brief (ADC_MR) Hardware trigger selected by TRGSEL field is enabled. */
#define ADC_MR_TRGSEL_Pos 1
#define ADC_MR_TRGSEL_Msk (0x7u << ADC_MR_TRGSEL_Pos) /**< \brief (ADC_MR) Trigger Selection */
#define   ADC_MR_TRGSEL_ADC_TRIG0 (0x0u << 1) /**< \brief (ADC_MR) External trigger */
#define   ADC_MR_TRGSEL_ADC_TRIG1 (0x1u << 1) /**< \brief (ADC_MR) TIO Output of the Timer Counter Channel 0 */
#define   ADC_MR_TRGSEL_ADC_TRIG2 (0x2u << 1) /**< \brief (ADC_MR) TIO Output of the Timer Counter Channel 1 */
#define   ADC_MR_TRGSEL_ADC_TRIG3 (0x3u << 1) /**< \brief (ADC_MR) TIO Output of the Timer Counter Channel 2 */
#define   ADC_MR_TRGSEL_ADC_TRIG4 (0x4u << 1) /**< \brief (ADC_MR) PWM Event Line 0 */
#define   ADC_MR_TRGSEL_ADC_TRIG5 (0x5u << 1) /**< \brief (ADC_MR) PWM Event Line 1 */
#define ADC_MR_LOWRES (0x1u << 4) /**< \brief (ADC_MR) Resolution */
#define   ADC_MR_LOWRES_BITS_12 (0x0u << 4) /**< \brief (ADC_MR) 12-bit resolution */
#define   ADC_MR_LOWRES_BITS_10 (0x1u << 4) /**< \brief (ADC_MR) 10-bit resolution */
#define ADC_MR_SLEEP (0x1u << 5) /**< \brief (ADC_MR) Sleep Mode */
#define   ADC_MR_SLEEP_NORMAL (0x0u << 5) /**< \brief (ADC_MR) Normal Mode: The ADC Core and reference voltage circuitry are kept ON between conversions */
#define   ADC_MR_SLEEP_SLEEP (0x1u << 5) /**< \brief (ADC_MR) Sleep Mode: The ADC Core and reference voltage circuitry are OFF between conversions */
#define ADC_MR_FWUP (0x1u << 6) /**< \brief (ADC_MR) Fast Wake Up */
#define   ADC_MR_FWUP_OFF (0x0u << 6) /**< \brief (ADC_MR) Normal Sleep Mode: The sleep mode is defined by the SLEEP bit */
#define   ADC_MR_FWUP_ON (0x1u << 6) /**< \brief (ADC_MR) Fast Wake Up Sleep Mode: The Voltage reference is ON between conversions and ADC Core is OFF */
#define ADC_MR_FREERUN (0x1u << 7) /**< \brief (ADC_MR) Free Run Mode */
#define   ADC_MR_FREERUN_OFF (0x0u << 7) /**< \brief (ADC_MR) Normal Mode */
#define   ADC_MR_FREERUN_ON (0x1u << 7) /**< \brief (ADC_MR) Free Run Mode: Never wait for any trigger. */
#define ADC_MR_PRESCAL_Pos 8
#define ADC_MR_PRESCAL_Msk (0xffu << ADC_MR_PRESCAL_Pos) /**< \brief (ADC_MR) Prescaler Rate Selection */
#define ADC_MR_PRESCAL(value) ((ADC_MR_PRESCAL_Msk & ((value) << ADC_MR_PRESCAL_Pos)))
#define ADC_MR_STARTUP_Pos 16
#define ADC_MR_STARTUP_Msk (0xfu << ADC_MR_STARTUP_Pos) /**< \brief (ADC_MR) Start Up Time */
#define   ADC_MR_STARTUP_SUT0 (0x0u << 16) /**< \brief (ADC_MR) 0 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT8 (0x1u << 16) /**< \brief (ADC_MR) 8 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT16 (0x2u << 16) /**< \brief (ADC_MR) 16 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT24 (0x3u << 16) /**< \brief (ADC_MR) 24 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT64 (0x4u << 16) /**< \brief (ADC_MR) 64 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT80 (0x5u << 16) /**< \brief (ADC_MR) 80 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT96 (0x6u << 16) /**< \brief (ADC_MR) 96 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT112 (0x7u << 16) /**< \brief (ADC_MR) 112 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT512 (0x8u << 16) /**< \brief (ADC_MR) 512 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT576 (0x9u << 16) /**< \brief (ADC_MR) 576 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT640 (0xAu << 16) /**< \brief (ADC_MR) 640 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT704 (0xBu << 16) /**< \brief (ADC_MR) 704 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT768 (0xCu << 16) /**< \brief (ADC_MR) 768 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT832 (0xDu << 16) /**< \brief (ADC_MR) 832 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT896 (0xEu << 16) /**< \brief (ADC_MR) 896 periods of ADCClock */
#define   ADC_MR_STARTUP_SUT960 (0xFu << 16) /**< \brief (ADC_MR) 960 periods of ADCClock */
#define ADC_MR_SETTLING_Pos 20
#define ADC_MR_SETTLING_Msk (0x3u << ADC_MR_SETTLING_Pos) /**< \brief (ADC_MR) Analog Settling Time */
#define   ADC_MR_SETTLING_AST3 (0x0u << 20) /**< \brief (ADC_MR) 3 periods of ADCClock */
#define   ADC_MR_SETTLING_AST5 (0x1u << 20) /**< \brief (ADC_MR) 5 periods of ADCClock */
#define   ADC_MR_SETTLING_AST9 (0x2u << 20) /**< \brief (ADC_MR) 9 periods of ADCClock */
#define   ADC_MR_SETTLING_AST17 (0x3u << 20) /**< \brief (ADC_MR) 17 periods of ADCClock */
#define ADC_MR_ANACH (0x1u << 23) /**< \brief (ADC_MR) Analog Change */
#define   ADC_MR_ANACH_NONE (0x0u << 23) /**< \brief (ADC_MR) No analog change on channel switching: DIFF0, GAIN0 and OFF0 are used for all channels */
#define   ADC_MR_ANACH_ALLOWED (0x1u << 23) /**< \brief (ADC_MR) Allows different analog settings for each channel. See ADC_CGR and ADC_COR Registers */
#define ADC_MR_TRACKTIM_Pos 24
#define ADC_MR_TRACKTIM_Msk (0xfu << ADC_MR_TRACKTIM_Pos) /**< \brief (ADC_MR) Tracking Time */
#define ADC_MR_TRACKTIM(value) ((ADC_MR_TRACKTIM_Msk & ((value) << ADC_MR_TRACKTIM_Pos)))
#define ADC_MR_TRANSFER_Pos 28
#define ADC_MR_TRANSFER_Msk (0x3u << ADC_MR_TRANSFER_Pos) /**< \brief (ADC_MR) Transfer Period */
#define ADC_MR_TRANSFER(value) ((ADC_MR_TRANSFER_Msk & ((value) << ADC_MR_TRANSFER_Pos)))
#define ADC_MR_USEQ (0x1u << 31) /**< \brief (ADC_MR) Use Sequence Enable */
#define   ADC_MR_USEQ_NUM_ORDER (0x0u << 31) /**< \brief (ADC_MR) Normal Mode: The controller converts channels in a simple numeric order. */
#define   ADC_MR_USEQ_REG_ORDER (0x1u << 31) /**< \brief (ADC_MR) User Sequence Mode: The sequence respects what is defined in ADC_SEQR1 and ADC_SEQR2 registers. */
/* -------- ADC_SEQR1 : (ADC Offset: 0x08) Channel Sequence Register 1 -------- */
#define ADC_SEQR1_USCH1_Pos 0
#define ADC_SEQR1_USCH1_Msk (0xfu << ADC_SEQR1_USCH1_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 1 */
#define ADC_SEQR1_USCH1(value) ((ADC_SEQR1_USCH1_Msk & ((value) << ADC_SEQR1_USCH1_Pos)))
#define ADC_SEQR1_USCH2_Pos 4
#define ADC_SEQR1_USCH2_Msk (0xfu << ADC_SEQR1_USCH2_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 2 */
#define ADC_SEQR1_USCH2(value) ((ADC_SEQR1_USCH2_Msk & ((value) << ADC_SEQR1_USCH2_Pos)))
#define ADC_SEQR1_USCH3_Pos 8
#define ADC_SEQR1_USCH3_Msk (0xfu << ADC_SEQR1_USCH3_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 3 */
#define ADC_SEQR1_USCH3(value) ((ADC_SEQR1_USCH3_Msk & ((value) << ADC_SEQR1_USCH3_Pos)))
#define ADC_SEQR1_USCH4_Pos 12
#define ADC_SEQR1_USCH4_Msk (0xfu << ADC_SEQR1_USCH4_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 4 */
#define ADC_SEQR1_USCH4(value) ((ADC_SEQR1_USCH4_Msk & ((value) << ADC_SEQR1_USCH4_Pos)))
#define ADC_SEQR1_USCH5_Pos 16
#define ADC_SEQR1_USCH5_Msk (0xfu << ADC_SEQR1_USCH5_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 5 */
#define ADC_SEQR1_USCH5(value) ((ADC_SEQR1_USCH5_Msk & ((value) << ADC_SEQR1_USCH5_Pos)))
#define ADC_SEQR1_USCH6_Pos 20
#define ADC_SEQR1_USCH6_Msk (0xfu << ADC_SEQR1_USCH6_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 6 */
#define ADC_SEQR1_USCH6(value) ((ADC_SEQR1_USCH6_Msk & ((value) << ADC_SEQR1_USCH6_Pos)))
#define ADC_SEQR1_USCH7_Pos 24
#define ADC_SEQR1_USCH7_Msk (0xfu << ADC_SEQR1_USCH7_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 7 */
#define ADC_SEQR1_USCH7(value) ((ADC_SEQR1_USCH7_Msk & ((value) << ADC_SEQR1_USCH7_Pos)))
#define ADC_SEQR1_USCH8_Pos 28
#define ADC_SEQR1_USCH8_Msk (0xfu << ADC_SEQR1_USCH8_Pos) /**< \brief (ADC_SEQR1) User Sequence Number 8 */
#define ADC_SEQR1_USCH8(value) ((ADC_SEQR1_USCH8_Msk & ((value) << ADC_SEQR1_USCH8_Pos)))
/* -------- ADC_SEQR2 : (ADC Offset: 0x0C) Channel Sequence Register 2 -------- */
#define ADC_SEQR2_USCH9_Pos 0
#define ADC_SEQR2_USCH9_Msk (0xfu << ADC_SEQR2_USCH9_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 9 */
#define ADC_SEQR2_USCH9(value) ((ADC_SEQR2_USCH9_Msk & ((value) << ADC_SEQR2_USCH9_Pos)))
#define ADC_SEQR2_USCH10_Pos 4
#define ADC_SEQR2_USCH10_Msk (0xfu << ADC_SEQR2_USCH10_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 10 */
#define ADC_SEQR2_USCH10(value) ((ADC_SEQR2_USCH10_Msk & ((value) << ADC_SEQR2_USCH10_Pos)))
#define ADC_SEQR2_USCH11_Pos 8
#define ADC_SEQR2_USCH11_Msk (0xfu << ADC_SEQR2_USCH11_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 11 */
#define ADC_SEQR2_USCH11(value) ((ADC_SEQR2_USCH11_Msk & ((value) << ADC_SEQR2_USCH11_Pos)))
#define ADC_SEQR2_USCH12_Pos 12
#define ADC_SEQR2_USCH12_Msk (0xfu << ADC_SEQR2_USCH12_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 12 */
#define ADC_SEQR2_USCH12(value) ((ADC_SEQR2_USCH12_Msk & ((value) << ADC_SEQR2_USCH12_Pos)))
#define ADC_SEQR2_USCH13_Pos 16
#define ADC_SEQR2_USCH13_Msk (0xfu << ADC_SEQR2_USCH13_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 13 */
#define ADC_SEQR2_USCH13(value) ((ADC_SEQR2_USCH13_Msk & ((value) << ADC_SEQR2_USCH13_Pos)))
#define ADC_SEQR2_USCH14_Pos 20
#define ADC_SEQR2_USCH14_Msk (0xfu << ADC_SEQR2_USCH14_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 14 */
#define ADC_SEQR2_USCH14(value) ((ADC_SEQR2_USCH14_Msk & ((value) << ADC_SEQR2_USCH14_Pos)))
#define ADC_SEQR2_USCH15_Pos 24
#define ADC_SEQR2_USCH15_Msk (0xfu << ADC_SEQR2_USCH15_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 15 */
#define ADC_SEQR2_USCH15(value) ((ADC_SEQR2_USCH15_Msk & ((value) << ADC_SEQR2_USCH15_Pos)))
#define ADC_SEQR2_USCH16_Pos 28
#define ADC_SEQR2_USCH16_Msk (0xfu << ADC_SEQR2_USCH16_Pos) /**< \brief (ADC_SEQR2) User Sequence Number 16 */
#define ADC_SEQR2_USCH16(value) ((ADC_SEQR2_USCH16_Msk & ((value) << ADC_SEQR2_USCH16_Pos)))
/* -------- ADC_CHER : (ADC Offset: 0x10) Channel Enable Register -------- */
#define ADC_CHER_CH0 (0x1u << 0) /**< \brief (ADC_CHER) Channel 0 Enable */
#define ADC_CHER_CH1 (0x1u << 1) /**< \brief (ADC_CHER) Channel 1 Enable */
#define ADC_CHER_CH2 (0x1u << 2) /**< \brief (ADC_CHER) Channel 2 Enable */
#define ADC_CHER_CH3 (0x1u << 3) /**< \brief (ADC_CHER) Channel 3 Enable */
#define ADC_CHER_CH4 (0x1u << 4) /**< \brief (ADC_CHER) Channel 4 Enable */
#define ADC_CHER_CH5 (0x1u << 5) /**< \brief (ADC_CHER) Channel 5 Enable */
#define ADC_CHER_CH6 (0x1u << 6) /**< \brief (ADC_CHER) Channel 6 Enable */
#define ADC_CHER_CH7 (0x1u << 7) /**< \brief (ADC_CHER) Channel 7 Enable */
#define ADC_CHER_CH8 (0x1u << 8) /**< \brief (ADC_CHER) Channel 8 Enable */
#define ADC_CHER_CH9 (0x1u << 9) /**< \brief (ADC_CHER) Channel 9 Enable */
#define ADC_CHER_CH10 (0x1u << 10) /**< \brief (ADC_CHER) Channel 10 Enable */
#define ADC_CHER_CH11 (0x1u << 11) /**< \brief (ADC_CHER) Channel 11 Enable */
#define ADC_CHER_CH12 (0x1u << 12) /**< \brief (ADC_CHER) Channel 12 Enable */
#define ADC_CHER_CH13 (0x1u << 13) /**< \brief (ADC_CHER) Channel 13 Enable */
#define ADC_CHER_CH14 (0x1u << 14) /**< \brief (ADC_CHER) Channel 14 Enable */
#define ADC_CHER_CH15 (0x1u << 15) /**< \brief (ADC_CHER) Channel 15 Enable */
/* -------- ADC_CHDR : (ADC Offset: 0x14) Channel Disable Register -------- */
#define ADC_CHDR_CH0 (0x1u << 0) /**< \brief (ADC_CHDR) Channel 0 Disable */
#define ADC_CHDR_CH1 (0x1u << 1) /**< \brief (ADC_CHDR) Channel 1 Disable */
#define ADC_CHDR_CH2 (0x1u << 2) /**< \brief (ADC_CHDR) Channel 2 Disable */
#define ADC_CHDR_CH3 (0x1u << 3) /**< \brief (ADC_CHDR) Channel 3 Disable */
#define ADC_CHDR_CH4 (0x1u << 4) /**< \brief (ADC_CHDR) Channel 4 Disable */
#define ADC_CHDR_CH5 (0x1u << 5) /**< \brief (ADC_CHDR) Channel 5 Disable */
#define ADC_CHDR_CH6 (0x1u << 6) /**< \brief (ADC_CHDR) Channel 6 Disable */
#define ADC_CHDR_CH7 (0x1u << 7) /**< \brief (ADC_CHDR) Channel 7 Disable */
#define ADC_CHDR_CH8 (0x1u << 8) /**< \brief (ADC_CHDR) Channel 8 Disable */
#define ADC_CHDR_CH9 (0x1u << 9) /**< \brief (ADC_CHDR) Channel 9 Disable */
#define ADC_CHDR_CH10 (0x1u << 10) /**< \brief (ADC_CHDR) Channel 10 Disable */
#define ADC_CHDR_CH11 (0x1u << 11) /**< \brief (ADC_CHDR) Channel 11 Disable */
#define ADC_CHDR_CH12 (0x1u << 12) /**< \brief (ADC_CHDR) Channel 12 Disable */
#define ADC_CHDR_CH13 (0x1u << 13) /**< \brief (ADC_CHDR) Channel 13 Disable */
#define ADC_CHDR_CH14 (0x1u << 14) /**< \brief (ADC_CHDR) Channel 14 Disable */
#define ADC_CHDR_CH15 (0x1u << 15) /**< \brief (ADC_CHDR) Channel 15 Disable */
/* -------- ADC_CHSR : (ADC Offset: 0x18) Channel Status Register -------- */
#define ADC_CHSR_CH0 (0x1u << 0) /**< \brief (ADC_CHSR) Channel 0 Status */
#define ADC_CHSR_CH1 (0x1u << 1) /**< \brief (ADC_CHSR) Channel 1 Status */
#define ADC_CHSR_CH2 (0x1u << 2) /**< \brief (ADC_CHSR) Channel 2 Status */
#define ADC_CHSR_CH3 (0x1u << 3) /**< \brief (ADC_CHSR) Channel 3 Status */
#define ADC_CHSR_CH4 (0x1u << 4) /**< \brief (ADC_CHSR) Channel 4 Status */
#define ADC_CHSR_CH5 (0x1u << 5) /**< \brief (ADC_CHSR) Channel 5 Status */
#define ADC_CHSR_CH6 (0x1u << 6) /**< \brief (ADC_CHSR) Channel 6 Status */
#define ADC_CHSR_CH7 (0x1u << 7) /**< \brief (ADC_CHSR) Channel 7 Status */
#define ADC_CHSR_CH8 (0x1u << 8) /**< \brief (ADC_CHSR) Channel 8 Status */
#define ADC_CHSR_CH9 (0x1u << 9) /**< \brief (ADC_CHSR) Channel 9 Status */
#define ADC_CHSR_CH10 (0x1u << 10) /**< \brief (ADC_CHSR) Channel 10 Status */
#define ADC_CHSR_CH11 (0x1u << 11) /**< \brief (ADC_CHSR) Channel 11 Status */
#define ADC_CHSR_CH12 (0x1u << 12) /**< \brief (ADC_CHSR) Channel 12 Status */
#define ADC_CHSR_CH13 (0x1u << 13) /**< \brief (ADC_CHSR) Channel 13 Status */
#define ADC_CHSR_CH14 (0x1u << 14) /**< \brief (ADC_CHSR) Channel 14 Status */
#define ADC_CHSR_CH15 (0x1u << 15) /**< \brief (ADC_CHSR) Channel 15 Status */
/* -------- ADC_LCDR : (ADC Offset: 0x20) Last Converted Data Register -------- */
#define ADC_LCDR_LDATA_Pos 0
#define ADC_LCDR_LDATA_Msk (0xfffu << ADC_LCDR_LDATA_Pos) /**< \brief (ADC_LCDR) Last Data Converted */
#define ADC_LCDR_CHNB_Pos 12
#define ADC_LCDR_CHNB_Msk (0xfu << ADC_LCDR_CHNB_Pos) /**< \brief (ADC_LCDR) Channel Number */
/* -------- ADC_IER : (ADC Offset: 0x24) Interrupt Enable Register -------- */
#define ADC_IER_EOC0 (0x1u << 0) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 0 */
#define ADC_IER_EOC1 (0x1u << 1) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 1 */
#define ADC_IER_EOC2 (0x1u << 2) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 2 */
#define ADC_IER_EOC3 (0x1u << 3) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 3 */
#define ADC_IER_EOC4 (0x1u << 4) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 4 */
#define ADC_IER_EOC5 (0x1u << 5) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 5 */
#define ADC_IER_EOC6 (0x1u << 6) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 6 */
#define ADC_IER_EOC7 (0x1u << 7) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 7 */
#define ADC_IER_EOC8 (0x1u << 8) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 8 */
#define ADC_IER_EOC9 (0x1u << 9) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 9 */
#define ADC_IER_EOC10 (0x1u << 10) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 10 */
#define ADC_IER_EOC11 (0x1u << 11) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 11 */
#define ADC_IER_EOC12 (0x1u << 12) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 12 */
#define ADC_IER_EOC13 (0x1u << 13) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 13 */
#define ADC_IER_EOC14 (0x1u << 14) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 14 */
#define ADC_IER_EOC15 (0x1u << 15) /**< \brief (ADC_IER) End of Conversion Interrupt Enable 15 */
#define ADC_IER_DRDY (0x1u << 24) /**< \brief (ADC_IER) Data Ready Interrupt Enable */
#define ADC_IER_GOVRE (0x1u << 25) /**< \brief (ADC_IER) General Overrun Error Interrupt Enable */
#define ADC_IER_COMPE (0x1u << 26) /**< \brief (ADC_IER) Comparison Event Interrupt Enable */
#define ADC_IER_ENDRX (0x1u << 27) /**< \brief (ADC_IER) End of Receive Buffer Interrupt Enable */
#define ADC_IER_RXBUFF (0x1u << 28) /**< \brief (ADC_IER) Receive Buffer Full Interrupt Enable */
/* -------- ADC_IDR : (ADC Offset: 0x28) Interrupt Disable Register -------- */
#define ADC_IDR_EOC0 (0x1u << 0) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 0 */
#define ADC_IDR_EOC1 (0x1u << 1) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 1 */
#define ADC_IDR_EOC2 (0x1u << 2) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 2 */
#define ADC_IDR_EOC3 (0x1u << 3) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 3 */
#define ADC_IDR_EOC4 (0x1u << 4) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 4 */
#define ADC_IDR_EOC5 (0x1u << 5) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 5 */
#define ADC_IDR_EOC6 (0x1u << 6) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 6 */
#define ADC_IDR_EOC7 (0x1u << 7) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 7 */
#define ADC_IDR_EOC8 (0x1u << 8) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 8 */
#define ADC_IDR_EOC9 (0x1u << 9) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 9 */
#define ADC_IDR_EOC10 (0x1u << 10) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 10 */
#define ADC_IDR_EOC11 (0x1u << 11) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 11 */
#define ADC_IDR_EOC12 (0x1u << 12) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 12 */
#define ADC_IDR_EOC13 (0x1u << 13) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 13 */
#define ADC_IDR_EOC14 (0x1u << 14) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 14 */
#define ADC_IDR_EOC15 (0x1u << 15) /**< \brief (ADC_IDR) End of Conversion Interrupt Disable 15 */
#define ADC_IDR_DRDY (0x1u << 24) /**< \brief (ADC_IDR) Data Ready Interrupt Disable */
#define ADC_IDR_GOVRE (0x1u << 25) /**< \brief (ADC_IDR) General Overrun Error Interrupt Disable */
#define ADC_IDR_COMPE (0x1u << 26) /**< \brief (ADC_IDR) Comparison Event Interrupt Disable */
#define ADC_IDR_ENDRX (0x1u << 27) /**< \brief (ADC_IDR) End of Receive Buffer Interrupt Disable */
#define ADC_IDR_RXBUFF (0x1u << 28) /**< \brief (ADC_IDR) Receive Buffer Full Interrupt Disable */
/* -------- ADC_IMR : (ADC Offset: 0x2C) Interrupt Mask Register -------- */
#define ADC_IMR_EOC0 (0x1u << 0) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 0 */
#define ADC_IMR_EOC1 (0x1u << 1) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 1 */
#define ADC_IMR_EOC2 (0x1u << 2) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 2 */
#define ADC_IMR_EOC3 (0x1u << 3) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 3 */
#define ADC_IMR_EOC4 (0x1u << 4) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 4 */
#define ADC_IMR_EOC5 (0x1u << 5) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 5 */
#define ADC_IMR_EOC6 (0x1u << 6) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 6 */
#define ADC_IMR_EOC7 (0x1u << 7) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 7 */
#define ADC_IMR_EOC8 (0x1u << 8) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 8 */
#define ADC_IMR_EOC9 (0x1u << 9) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 9 */
#define ADC_IMR_EOC10 (0x1u << 10) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 10 */
#define ADC_IMR_EOC11 (0x1u << 11) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 11 */
#define ADC_IMR_EOC12 (0x1u << 12) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 12 */
#define ADC_IMR_EOC13 (0x1u << 13) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 13 */
#define ADC_IMR_EOC14 (0x1u << 14) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 14 */
#define ADC_IMR_EOC15 (0x1u << 15) /**< \brief (ADC_IMR) End of Conversion Interrupt Mask 15 */
#define ADC_IMR_DRDY (0x1u << 24) /**< \brief (ADC_IMR) Data Ready Interrupt Mask */
#define ADC_IMR_GOVRE (0x1u << 25) /**< \brief (ADC_IMR) General Overrun Error Interrupt Mask */
#define ADC_IMR_COMPE (0x1u << 26) /**< \brief (ADC_IMR) Comparison Event Interrupt Mask */
#define ADC_IMR_ENDRX (0x1u << 27) /**< \brief (ADC_IMR) End of Receive Buffer Interrupt Mask */
#define ADC_IMR_RXBUFF (0x1u << 28) /**< \brief (ADC_IMR) Receive Buffer Full Interrupt Mask */
/* -------- ADC_ISR : (ADC Offset: 0x30) Interrupt Status Register -------- */
#define ADC_ISR_EOC0 (0x1u << 0) /**< \brief (ADC_ISR) End of Conversion 0 */
#define ADC_ISR_EOC1 (0x1u << 1) /**< \brief (ADC_ISR) End of Conversion 1 */
#define ADC_ISR_EOC2 (0x1u << 2) /**< \brief (ADC_ISR) End of Conversion 2 */
#define ADC_ISR_EOC3 (0x1u << 3) /**< \brief (ADC_ISR) End of Conversion 3 */
#define ADC_ISR_EOC4 (0x1u << 4) /**< \brief (ADC_ISR) End of Conversion 4 */
#define ADC_ISR_EOC5 (0x1u << 5) /**< \brief (ADC_ISR) End of Conversion 5 */
#define ADC_ISR_EOC6 (0x1u << 6) /**< \brief (ADC_ISR) End of Conversion 6 */
#define ADC_ISR_EOC7 (0x1u << 7) /**< \brief (ADC_ISR) End of Conversion 7 */
#define ADC_ISR_EOC8 (0x1u << 8) /**< \brief (ADC_ISR) End of Conversion 8 */
#define ADC_ISR_EOC9 (0x1u << 9) /**< \brief (ADC_ISR) End of Conversion 9 */
#define ADC_ISR_EOC10 (0x1u << 10) /**< \brief (ADC_ISR) End of Conversion 10 */
#define ADC_ISR_EOC11 (0x1u << 11) /**< \brief (ADC_ISR) End of Conversion 11 */
#define ADC_ISR_EOC12 (0x1u << 12) /**< \brief (ADC_ISR) End of Conversion 12 */
#define ADC_ISR_EOC13 (0x1u << 13) /**< \brief (ADC_ISR) End of Conversion 13 */
#define ADC_ISR_EOC14 (0x1u << 14) /**< \brief (ADC_ISR) End of Conversion 14 */
#define ADC_ISR_EOC15 (0x1u << 15) /**< \brief (ADC_ISR) End of Conversion 15 */
#define ADC_ISR_DRDY (0x1u << 24) /**< \brief (ADC_ISR) Data Ready */
#define ADC_ISR_GOVRE (0x1u << 25) /**< \brief (ADC_ISR) General Overrun Error */
#define ADC_ISR_COMPE (0x1u << 26) /**< \brief (ADC_ISR) Comparison Error */
#define ADC_ISR_ENDRX (0x1u << 27) /**< \brief (ADC_ISR) End of RX Buffer */
#define ADC_ISR_RXBUFF (0x1u << 28) /**< \brief (ADC_ISR) RX Buffer Full */
/* -------- ADC_OVER : (ADC Offset: 0x3C) Overrun Status Register -------- */
#define ADC_OVER_OVRE0 (0x1u << 0) /**< \brief (ADC_OVER) Overrun Error 0 */
#define ADC_OVER_OVRE1 (0x1u << 1) /**< \brief (ADC_OVER) Overrun Error 1 */
#define ADC_OVER_OVRE2 (0x1u << 2) /**< \brief (ADC_OVER) Overrun Error 2 */
#define ADC_OVER_OVRE3 (0x1u << 3) /**< \brief (ADC_OVER) Overrun Error 3 */
#define ADC_OVER_OVRE4 (0x1u << 4) /**< \brief (ADC_OVER) Overrun Error 4 */
#define ADC_OVER_OVRE5 (0x1u << 5) /**< \brief (ADC_OVER) Overrun Error 5 */
#define ADC_OVER_OVRE6 (0x1u << 6) /**< \brief (ADC_OVER) Overrun Error 6 */
#define ADC_OVER_OVRE7 (0x1u << 7) /**< \brief (ADC_OVER) Overrun Error 7 */
#define ADC_OVER_OVRE8 (0x1u << 8) /**< \brief (ADC_OVER) Overrun Error 8 */
#define ADC_OVER_OVRE9 (0x1u << 9) /**< \brief (ADC_OVER) Overrun Error 9 */
#define ADC_OVER_OVRE10 (0x1u << 10) /**< \brief (ADC_OVER) Overrun Error 10 */
#define ADC_OVER_OVRE11 (0x1u << 11) /**< \brief (ADC_OVER) Overrun Error 11 */
#define ADC_OVER_OVRE12 (0x1u << 12) /**< \brief (ADC_OVER) Overrun Error 12 */
#define ADC_OVER_OVRE13 (0x1u << 13) /**< \brief (ADC_OVER) Overrun Error 13 */
#define ADC_OVER_OVRE14 (0x1u << 14) /**< \brief (ADC_OVER) Overrun Error 14 */
#define ADC_OVER_OVRE15 (0x1u << 15) /**< \brief (ADC_OVER) Overrun Error 15 */
/* -------- ADC_EMR : (ADC Offset: 0x40) Extended Mode Register -------- */
#define ADC_EMR_CMPMODE_Pos 0
#define ADC_EMR_CMPMODE_Msk (0x3u << ADC_EMR_CMPMODE_Pos) /**< \brief (ADC_EMR) Comparison Mode */
#define   ADC_EMR_CMPMODE_LOW (0x0u << 0) /**< \brief (ADC_EMR) Generates an event when the converted data is lower than the low threshold of the window. */
#define   ADC_EMR_CMPMODE_HIGH (0x1u << 0) /**< \brief (ADC_EMR) Generates an event when the converted data is higher than the high threshold of the window. */
#define   ADC_EMR_CMPMODE_IN (0x2u << 0) /**< \brief (ADC_EMR) Generates an event when the converted data is in the comparison window. */
#define   ADC_EMR_CMPMODE_OUT (0x3u << 0) /**< \brief (ADC_EMR) Generates an event when the converted data is out of the comparison window. */
#define ADC_EMR_CMPSEL_Pos 4
#define ADC_EMR_CMPSEL_Msk (0xfu << ADC_EMR_CMPSEL_Pos) /**< \brief (ADC_EMR) Comparison Selected Channel */
#define ADC_EMR_CMPSEL(value) ((ADC_EMR_CMPSEL_Msk & ((value) << ADC_EMR_CMPSEL_Pos)))
#define ADC_EMR_CMPALL (0x1u << 9) /**< \brief (ADC_EMR) Compare All Channels */
#define ADC_EMR_TAG (0x1u << 24) /**< \brief (ADC_EMR) TAG of ADC_LDCR register */
/* -------- ADC_CWR : (ADC Offset: 0x44) Compare Window Register -------- */
#define ADC_CWR_LOWTHRES_Pos 0
#define ADC_CWR_LOWTHRES_Msk (0xfffu << ADC_CWR_LOWTHRES_Pos) /**< \brief (ADC_CWR) Low Threshold */
#define ADC_CWR_LOWTHRES(value) ((ADC_CWR_LOWTHRES_Msk & ((value) << ADC_CWR_LOWTHRES_Pos)))
#define ADC_CWR_HIGHTHRES_Pos 16
#define ADC_CWR_HIGHTHRES_Msk (0xfffu << ADC_CWR_HIGHTHRES_Pos) /**< \brief (ADC_CWR) High Threshold */
#define ADC_CWR_HIGHTHRES(value) ((ADC_CWR_HIGHTHRES_Msk & ((value) << ADC_CWR_HIGHTHRES_Pos)))
/* -------- ADC_CGR : (ADC Offset: 0x48) Channel Gain Register -------- */
#define ADC_CGR_GAIN0_Pos 0
#define ADC_CGR_GAIN0_Msk (0x3u << ADC_CGR_GAIN0_Pos) /**< \brief (ADC_CGR) Gain for channel 0 */
#define ADC_CGR_GAIN0(value) ((ADC_CGR_GAIN0_Msk & ((value) << ADC_CGR_GAIN0_Pos)))
#define ADC_CGR_GAIN1_Pos 2
#define ADC_CGR_GAIN1_Msk (0x3u << ADC_CGR_GAIN1_Pos) /**< \brief (ADC_CGR) Gain for channel 1 */
#define ADC_CGR_GAIN1(value) ((ADC_CGR_GAIN1_Msk & ((value) << ADC_CGR_GAIN1_Pos)))
#define ADC_CGR_GAIN2_Pos 4
#define ADC_CGR_GAIN2_Msk (0x3u << ADC_CGR_GAIN2_Pos) /**< \brief (ADC_CGR) Gain for channel 2 */
#define ADC_CGR_GAIN2(value) ((ADC_CGR_GAIN2_Msk & ((value) << ADC_CGR_GAIN2_Pos)))
#define ADC_CGR_GAIN3_Pos 6
#define ADC_CGR_GAIN3_Msk (0x3u << ADC_CGR_GAIN3_Pos) /**< \brief (ADC_CGR) Gain for channel 3 */
#define ADC_CGR_GAIN3(value) ((ADC_CGR_GAIN3_Msk & ((value) << ADC_CGR_GAIN3_Pos)))
#define ADC_CGR_GAIN4_Pos 8
#define ADC_CGR_GAIN4_Msk (0x3u << ADC_CGR_GAIN4_Pos) /**< \brief (ADC_CGR) Gain for channel 4 */
#define ADC_CGR_GAIN4(value) ((ADC_CGR_GAIN4_Msk & ((value) << ADC_CGR_GAIN4_Pos)))
#define ADC_CGR_GAIN5_Pos 10
#define ADC_CGR_GAIN5_Msk (0x3u << ADC_CGR_GAIN5_Pos) /**< \brief (ADC_CGR) Gain for channel 5 */
#define ADC_CGR_GAIN5(value) ((ADC_CGR_GAIN5_Msk & ((value) << ADC_CGR_GAIN5_Pos)))
#define ADC_CGR_GAIN6_Pos 12
#define ADC_CGR_GAIN6_Msk (0x3u << ADC_CGR_GAIN6_Pos) /**< \brief (ADC_CGR) Gain for channel 6 */
#define ADC_CGR_GAIN6(value) ((ADC_CGR_GAIN6_Msk & ((value) << ADC_CGR_GAIN6_Pos)))
#define ADC_CGR_GAIN7_Pos 14
#define ADC_CGR_GAIN7_Msk (0x3u << ADC_CGR_GAIN7_Pos) /**< \brief (ADC_CGR) Gain for channel 7 */
#define ADC_CGR_GAIN7(value) ((ADC_CGR_GAIN7_Msk & ((value) << ADC_CGR_GAIN7_Pos)))
#define ADC_CGR_GAIN8_Pos 16
#define ADC_CGR_GAIN8_Msk (0x3u << ADC_CGR_GAIN8_Pos) /**< \brief (ADC_CGR) Gain for channel 8 */
#define ADC_CGR_GAIN8(value) ((ADC_CGR_GAIN8_Msk & ((value) << ADC_CGR_GAIN8_Pos)))
#define ADC_CGR_GAIN9_Pos 18
#define ADC_CGR_GAIN9_Msk (0x3u << ADC_CGR_GAIN9_Pos) /**< \brief (ADC_CGR) Gain for channel 9 */
#define ADC_CGR_GAIN9(value) ((ADC_CGR_GAIN9_Msk & ((value) << ADC_CGR_GAIN9_Pos)))
#define ADC_CGR_GAIN10_Pos 20
#define ADC_CGR_GAIN10_Msk (0x3u << ADC_CGR_GAIN10_Pos) /**< \brief (ADC_CGR) Gain for channel 10 */
#define ADC_CGR_GAIN10(value) ((ADC_CGR_GAIN10_Msk & ((value) << ADC_CGR_GAIN10_Pos)))
#define ADC_CGR_GAIN11_Pos 22
#define ADC_CGR_GAIN11_Msk (0x3u << ADC_CGR_GAIN11_Pos) /**< \brief (ADC_CGR) Gain for channel 11 */
#define ADC_CGR_GAIN11(value) ((ADC_CGR_GAIN11_Msk & ((value) << ADC_CGR_GAIN11_Pos)))
#define ADC_CGR_GAIN12_Pos 24
#define ADC_CGR_GAIN12_Msk (0x3u << ADC_CGR_GAIN12_Pos) /**< \brief (ADC_CGR) Gain for channel 12 */
#define ADC_CGR_GAIN12(value) ((ADC_CGR_GAIN12_Msk & ((value) << ADC_CGR_GAIN12_Pos)))
#define ADC_CGR_GAIN13_Pos 26
#define ADC_CGR_GAIN13_Msk (0x3u << ADC_CGR_GAIN13_Pos) /**< \brief (ADC_CGR) Gain for channel 13 */
#define ADC_CGR_GAIN13(value) ((ADC_CGR_GAIN13_Msk & ((value) << ADC_CGR_GAIN13_Pos)))
#define ADC_CGR_GAIN14_Pos 28
#define ADC_CGR_GAIN14_Msk (0x3u << ADC_CGR_GAIN14_Pos) /**< \brief (ADC_CGR) Gain for channel 14 */
#define ADC_CGR_GAIN14(value) ((ADC_CGR_GAIN14_Msk & ((value) << ADC_CGR_GAIN14_Pos)))
#define ADC_CGR_GAIN15_Pos 30
#define ADC_CGR_GAIN15_Msk (0x3u << ADC_CGR_GAIN15_Pos) /**< \brief (ADC_CGR) Gain for channel 15 */
#define ADC_CGR_GAIN15(value) ((ADC_CGR_GAIN15_Msk & ((value) << ADC_CGR_GAIN15_Pos)))
/* -------- ADC_COR : (ADC Offset: 0x4C) Channel Offset Register -------- */
#define ADC_COR_OFF0 (0x1u << 0) /**< \brief (ADC_COR) Offset for channel 0 */
#define ADC_COR_OFF1 (0x1u << 1) /**< \brief (ADC_COR) Offset for channel 1 */
#define ADC_COR_OFF2 (0x1u << 2) /**< \brief (ADC_COR) Offset for channel 2 */
#define ADC_COR_OFF3 (0x1u << 3) /**< \brief (ADC_COR) Offset for channel 3 */
#define ADC_COR_OFF4 (0x1u << 4) /**< \brief (ADC_COR) Offset for channel 4 */
#define ADC_COR_OFF5 (0x1u << 5) /**< \brief (ADC_COR) Offset for channel 5 */
#define ADC_COR_OFF6 (0x1u << 6) /**< \brief (ADC_COR) Offset for channel 6 */
#define ADC_COR_OFF7 (0x1u << 7) /**< \brief (ADC_COR) Offset for channel 7 */
#define ADC_COR_OFF8 (0x1u << 8) /**< \brief (ADC_COR) Offset for channel 8 */
#define ADC_COR_OFF9 (0x1u << 9) /**< \brief (ADC_COR) Offset for channel 9 */
#define ADC_COR_OFF10 (0x1u << 10) /**< \brief (ADC_COR) Offset for channel 10 */
#define ADC_COR_OFF11 (0x1u << 11) /**< \brief (ADC_COR) Offset for channel 11 */
#define ADC_COR_OFF12 (0x1u << 12) /**< \brief (ADC_COR) Offset for channel 12 */
#define ADC_COR_OFF13 (0x1u << 13) /**< \brief (ADC_COR) Offset for channel 13 */
#define ADC_COR_OFF14 (0x1u << 14) /**< \brief (ADC_COR) Offset for channel 14 */
#define ADC_COR_OFF15 (0x1u << 15) /**< \brief (ADC_COR) Offset for channel 15 */
#define ADC_COR_DIFF0 (0x1u << 16) /**< \brief (ADC_COR) Differential inputs for channel 0 */
#define ADC_COR_DIFF1 (0x1u << 17) /**< \brief (ADC_COR) Differential inputs for channel 1 */
#define ADC_COR_DIFF2 (0x1u << 18) /**< \brief (ADC_COR) Differential inputs for channel 2 */
#define ADC_COR_DIFF3 (0x1u << 19) /**< \brief (ADC_COR) Differential inputs for channel 3 */
#define ADC_COR_DIFF4 (0x1u << 20) /**< \brief (ADC_COR) Differential inputs for channel 4 */
#define ADC_COR_DIFF5 (0x1u << 21) /**< \brief (ADC_COR) Differential inputs for channel 5 */
#define ADC_COR_DIFF6 (0x1u << 22) /**< \brief (ADC_COR) Differential inputs for channel 6 */
#define ADC_COR_DIFF7 (0x1u << 23) /**< \brief (ADC_COR) Differential inputs for channel 7 */
#define ADC_COR_DIFF8 (0x1u << 24) /**< \brief (ADC_COR) Differential inputs for channel 8 */
#define ADC_COR_DIFF9 (0x1u << 25) /**< \brief (ADC_COR) Differential inputs for channel 9 */
#define ADC_COR_DIFF10 (0x1u << 26) /**< \brief (ADC_COR) Differential inputs for channel 10 */
#define ADC_COR_DIFF11 (0x1u << 27) /**< \brief (ADC_COR) Differential inputs for channel 11 */
#define ADC_COR_DIFF12 (0x1u << 28) /**< \brief (ADC_COR) Differential inputs for channel 12 */
#define ADC_COR_DIFF13 (0x1u << 29) /**< \brief (ADC_COR) Differential inputs for channel 13 */
#define ADC_COR_DIFF14 (0x1u << 30) /**< \brief (ADC_COR) Differential inputs for channel 14 */
#define ADC_COR_DIFF15 (0x1u << 31) /**< \brief (ADC_COR) Differential inputs for channel 15 */
/* -------- ADC_CDR[15] : (ADC Offset: 0x50) Channel Data Register -------- */
#define ADC_CDR_DATA_Pos 0
#define ADC_CDR_DATA_Msk (0xfffu << ADC_CDR_DATA_Pos) /**< \brief (ADC_CDR[15]) Converted Data */
/* -------- ADC_ACR : (ADC Offset: 0x94) Analog Control Register -------- */
#define ADC_ACR_TSON (0x1u << 4) /**< \brief (ADC_ACR) Temperature Sensor On */
#define ADC_ACR_IBCTL_Pos 8
#define ADC_ACR_IBCTL_Msk (0x3u << ADC_ACR_IBCTL_Pos) /**< \brief (ADC_ACR) ADC Bias Current Control */
#define ADC_ACR_IBCTL(value) ((ADC_ACR_IBCTL_Msk & ((value) << ADC_ACR_IBCTL_Pos)))
/* -------- ADC_TRGR : (ADC Offset: 0xC0) Trigger Register -------- */
#define ADC_TRGR_TRGMOD_Pos 0
#define ADC_TRGR_TRGMOD_Msk (0x7u << ADC_TRGR_TRGMOD_Pos) /**< \brief (ADC_TRGR) Trigger Mode */
#define   ADC_TRGR_TRGMOD_NO_TRIGGER (0x0u << 0) /**< \brief (ADC_TRGR) No trigger, only software trigger can start conversions */
#define   ADC_TRGR_TRGMOD_EXT_TRIG_RISE (0x1u << 0) /**< \brief (ADC_TRGR) External Trigger Rising Edge */
#define   ADC_TRGR_TRGMOD_EXT_TRIG_FALL (0x2u << 0) /**< \brief (ADC_TRGR) External Trigger Falling Edge */
#define   ADC_TRGR_TRGMOD_EXT_TRIG_ANY (0x3u << 0) /**< \brief (ADC_TRGR) External Trigger Any Edge */
#define   ADC_TRGR_TRGMOD_PERIOD_TRIG (0x5u << 0) /**< \brief (ADC_TRGR) Periodic Trigger (TRGPER shall be initiated appropriately) */
#define   ADC_TRGR_TRGMOD_CONTINUOUS (0x6u << 0) /**< \brief (ADC_TRGR) Continuous Mode */
#define ADC_TRGR_TRGPER_Pos 16
#define ADC_TRGR_TRGPER_Msk (0xffffu << ADC_TRGR_TRGPER_Pos) /**< \brief (ADC_TRGR) Trigger Period */
#define ADC_TRGR_TRGPER(value) ((ADC_TRGR_TRGPER_Msk & ((value) << ADC_TRGR_TRGPER_Pos)))
/* -------- ADC_WPMR : (ADC Offset: 0xE4) Write Protect Mode Register -------- */
#define ADC_WPMR_WPEN (0x1u << 0) /**< \brief (ADC_WPMR) Write Protect Enable */
#define ADC_WPMR_WPKEY_Pos 8
#define ADC_WPMR_WPKEY_Msk (0xffffffu << ADC_WPMR_WPKEY_Pos) /**< \brief (ADC_WPMR) Write Protect KEY */
#define ADC_WPMR_WPKEY(value) ((ADC_WPMR_WPKEY_Msk & ((value) << ADC_WPMR_WPKEY_Pos)))
/* -------- ADC_WPSR : (ADC Offset: 0xE8) Write Protect Status Register -------- */
#define ADC_WPSR_WPVS (0x1u << 0) /**< \brief (ADC_WPSR) Write Protect Violation Status */
#define ADC_WPSR_WPVSRC_Pos 8
#define ADC_WPSR_WPVSRC_Msk (0xffffu << ADC_WPSR_WPVSRC_Pos) /**< \brief (ADC_WPSR) Write Protect Violation Source */
/* -------- ADC_RPR : (ADC Offset: 0x100) Receive Pointer Register -------- */
#define ADC_RPR_RXPTR_Pos 0
#define ADC_RPR_RXPTR_Msk (0xffffffffu << ADC_RPR_RXPTR_Pos) /**< \brief (ADC_RPR) Receive Pointer Register */
#define ADC_RPR_RXPTR(value) ((ADC_RPR_RXPTR_Msk & ((value) << ADC_RPR_RXPTR_Pos)))
/* -------- ADC_RCR : (ADC Offset: 0x104) Receive Counter Register -------- */
#define ADC_RCR_RXCTR_Pos 0
#define ADC_RCR_RXCTR_Msk (0xffffu << ADC_RCR_RXCTR_Pos) /**< \brief (ADC_RCR) Receive Counter Register */
#define ADC_RCR_RXCTR(value) ((ADC_RCR_RXCTR_Msk & ((value) << ADC_RCR_RXCTR_Pos)))
/* -------- ADC_TPR : (ADC Offset: 0x108) Transmit Pointer Register -------- */
#define ADC_TPR_TXPTR_Pos 0
#define ADC_TPR_TXPTR_Msk (0xffffffffu << ADC_TPR_TXPTR_Pos) /**< \brief (ADC_TPR) Transmit Counter Register */
#define ADC_TPR_TXPTR(value) ((ADC_TPR_TXPTR_Msk & ((value) << ADC_TPR_TXPTR_Pos)))
/* -------- ADC_TCR : (ADC Offset: 0x10C) Transmit Counter Register -------- */
#define ADC_TCR_TXCTR_Pos 0
#define ADC_TCR_TXCTR_Msk (0xffffu << ADC_TCR_TXCTR_Pos) /**< \brief (ADC_TCR) Transmit Counter Register */
#define ADC_TCR_TXCTR(value) ((ADC_TCR_TXCTR_Msk & ((value) << ADC_TCR_TXCTR_Pos)))
/* -------- ADC_RNPR : (ADC Offset: 0x110) Receive Next Pointer Register -------- */
#define ADC_RNPR_RXNPTR_Pos 0
#define ADC_RNPR_RXNPTR_Msk (0xffffffffu << ADC_RNPR_RXNPTR_Pos) /**< \brief (ADC_RNPR) Receive Next Pointer */
#define ADC_RNPR_RXNPTR(value) ((ADC_RNPR_RXNPTR_Msk & ((value) << ADC_RNPR_RXNPTR_Pos)))
/* -------- ADC_RNCR : (ADC Offset: 0x114) Receive Next Counter Register -------- */
#define ADC_RNCR_RXNCTR_Pos 0
#define ADC_RNCR_RXNCTR_Msk (0xffffu << ADC_RNCR_RXNCTR_Pos) /**< \brief (ADC_RNCR) Receive Next Counter */
#define ADC_RNCR_RXNCTR(value) ((ADC_RNCR_RXNCTR_Msk & ((value) << ADC_RNCR_RXNCTR_Pos)))
/* -------- ADC_TNPR : (ADC Offset: 0x118) Transmit Next Pointer Register -------- */
#define ADC_TNPR_TXNPTR_Pos 0
#define ADC_TNPR_TXNPTR_Msk (0xffffffffu << ADC_TNPR_TXNPTR_Pos) /**< \brief (ADC_TNPR) Transmit Next Pointer */
#define ADC_TNPR_TXNPTR(value) ((ADC_TNPR_TXNPTR_Msk & ((value) << ADC_TNPR_TXNPTR_Pos)))
/* -------- ADC_TNCR : (ADC Offset: 0x11C) Transmit Next Counter Register -------- */
#define ADC_TNCR_TXNCTR_Pos 0
#define ADC_TNCR_TXNCTR_Msk (0xffffu << ADC_TNCR_TXNCTR_Pos) /**< \brief (ADC_TNCR) Transmit Counter Next */
#define ADC_TNCR_TXNCTR(value) ((ADC_TNCR_TXNCTR_Msk & ((value) << ADC_TNCR_TXNCTR_Pos)))
/* -------- ADC_PTCR : (ADC Offset: 0x120) Transfer Control Register -------- */
#define ADC_PTCR_RXTEN (0x1u << 0) /**< \brief (ADC_PTCR) Receiver Transfer Enable */
#define ADC_PTCR_RXTDIS (0x1u << 1) /**< \brief (ADC_PTCR) Receiver Transfer Disable */
#define ADC_PTCR_TXTEN (0x1u << 8) /**< \brief (ADC_PTCR) Transmitter Transfer Enable */
#define ADC_PTCR_TXTDIS (0x1u << 9) /**< \brief (ADC_PTCR) Transmitter Transfer Disable */
/* -------- ADC_PTSR : (ADC Offset: 0x124) Transfer Status Register -------- */
#define ADC_PTSR_RXTEN (0x1u << 0) /**< \brief (ADC_PTSR) Receiver Transfer Enable */
#define ADC_PTSR_TXTEN (0x1u << 8) /**< \brief (ADC_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Chip Identifier */
/* ============================================================================= */
/** \addtogroup SAM3S16_CHIPID Chip Identifier */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Chipid hardware registers */
typedef struct {
  RoReg CHIPID_CIDR; /**< \brief (Chipid Offset: 0x0) Chip ID Register */
  RoReg CHIPID_EXID; /**< \brief (Chipid Offset: 0x4) Chip ID Extension Register */
} Chipid;
#endif /* __ASSEMBLY__ */
/* -------- CHIPID_CIDR : (CHIPID Offset: 0x0) Chip ID Register -------- */
#define CHIPID_CIDR_VERSION_Pos 0
#define CHIPID_CIDR_VERSION_Msk (0x1fu << CHIPID_CIDR_VERSION_Pos) /**< \brief (CHIPID_CIDR) Version of the Device */
#define CHIPID_CIDR_EPROC_Pos 5
#define CHIPID_CIDR_EPROC_Msk (0x7u << CHIPID_CIDR_EPROC_Pos) /**< \brief (CHIPID_CIDR) Embedded Processor */
#define   CHIPID_CIDR_EPROC_ARM946ES (0x1u << 5) /**< \brief (CHIPID_CIDR) ARM946ES */
#define   CHIPID_CIDR_EPROC_ARM7TDMI (0x2u << 5) /**< \brief (CHIPID_CIDR) ARM7TDMI */
#define   CHIPID_CIDR_EPROC_CM3 (0x3u << 5) /**< \brief (CHIPID_CIDR) Cortex-M3 */
#define   CHIPID_CIDR_EPROC_ARM920T (0x4u << 5) /**< \brief (CHIPID_CIDR) ARM920T */
#define   CHIPID_CIDR_EPROC_ARM926EJS (0x5u << 5) /**< \brief (CHIPID_CIDR) ARM926EJS */
#define   CHIPID_CIDR_EPROC_CA5 (0x6u << 5) /**< \brief (CHIPID_CIDR) Cortex-A5 */
#define   CHIPID_CIDR_EPROC_CM4 (0x7u << 5) /**< \brief (CHIPID_CIDR) Cortex-M4 */
#define CHIPID_CIDR_NVPSIZ_Pos 8
#define CHIPID_CIDR_NVPSIZ_Msk (0xfu << CHIPID_CIDR_NVPSIZ_Pos) /**< \brief (CHIPID_CIDR) Nonvolatile Program Memory Size */
#define   CHIPID_CIDR_NVPSIZ_NONE (0x0u << 8) /**< \brief (CHIPID_CIDR) None */
#define   CHIPID_CIDR_NVPSIZ_8K (0x1u << 8) /**< \brief (CHIPID_CIDR) 8K bytes */
#define   CHIPID_CIDR_NVPSIZ_16K (0x2u << 8) /**< \brief (CHIPID_CIDR) 16K bytes */
#define   CHIPID_CIDR_NVPSIZ_32K (0x3u << 8) /**< \brief (CHIPID_CIDR) 32K bytes */
#define   CHIPID_CIDR_NVPSIZ_64K (0x5u << 8) /**< \brief (CHIPID_CIDR) 64K bytes */
#define   CHIPID_CIDR_NVPSIZ_128K (0x7u << 8) /**< \brief (CHIPID_CIDR) 128K bytes */
#define   CHIPID_CIDR_NVPSIZ_256K (0x9u << 8) /**< \brief (CHIPID_CIDR) 256K bytes */
#define   CHIPID_CIDR_NVPSIZ_512K (0xAu << 8) /**< \brief (CHIPID_CIDR) 512K bytes */
#define   CHIPID_CIDR_NVPSIZ_1024K (0xCu << 8) /**< \brief (CHIPID_CIDR) 1024K bytes */
#define   CHIPID_CIDR_NVPSIZ_2048K (0xEu << 8) /**< \brief (CHIPID_CIDR) 2048K bytes */
#define CHIPID_CIDR_NVPSIZ2_Pos 12
#define CHIPID_CIDR_NVPSIZ2_Msk (0xfu << CHIPID_CIDR_NVPSIZ2_Pos) /**< \brief (CHIPID_CIDR) Second Nonvolatile Program Memory Size */
#define   CHIPID_CIDR_NVPSIZ2_NONE (0x0u << 12) /**< \brief (CHIPID_CIDR) None */
#define   CHIPID_CIDR_NVPSIZ2_8K (0x1u << 12) /**< \brief (CHIPID_CIDR) 8K bytes */
#define   CHIPID_CIDR_NVPSIZ2_16K (0x2u << 12) /**< \brief (CHIPID_CIDR) 16K bytes */
#define   CHIPID_CIDR_NVPSIZ2_32K (0x3u << 12) /**< \brief (CHIPID_CIDR) 32K bytes */
#define   CHIPID_CIDR_NVPSIZ2_64K (0x5u << 12) /**< \brief (CHIPID_CIDR) 64K bytes */
#define   CHIPID_CIDR_NVPSIZ2_128K (0x7u << 12) /**< \brief (CHIPID_CIDR) 128K bytes */
#define   CHIPID_CIDR_NVPSIZ2_256K (0x9u << 12) /**< \brief (CHIPID_CIDR) 256K bytes */
#define   CHIPID_CIDR_NVPSIZ2_512K (0xAu << 12) /**< \brief (CHIPID_CIDR) 512K bytes */
#define   CHIPID_CIDR_NVPSIZ2_1024K (0xCu << 12) /**< \brief (CHIPID_CIDR) 1024K bytes */
#define   CHIPID_CIDR_NVPSIZ2_2048K (0xEu << 12) /**< \brief (CHIPID_CIDR) 2048K bytes */
#define CHIPID_CIDR_SRAMSIZ_Pos 16
#define CHIPID_CIDR_SRAMSIZ_Msk (0xfu << CHIPID_CIDR_SRAMSIZ_Pos) /**< \brief (CHIPID_CIDR) Internal SRAM Size */
#define   CHIPID_CIDR_SRAMSIZ_48K (0x0u << 16) /**< \brief (CHIPID_CIDR) 48K bytes */
#define   CHIPID_CIDR_SRAMSIZ_1K (0x1u << 16) /**< \brief (CHIPID_CIDR) 1K bytes */
#define   CHIPID_CIDR_SRAMSIZ_2K (0x2u << 16) /**< \brief (CHIPID_CIDR) 2K bytes */
#define   CHIPID_CIDR_SRAMSIZ_6K (0x3u << 16) /**< \brief (CHIPID_CIDR) 6K bytes */
#define   CHIPID_CIDR_SRAMSIZ_24K (0x4u << 16) /**< \brief (CHIPID_CIDR) 24K bytes */
#define   CHIPID_CIDR_SRAMSIZ_4K (0x5u << 16) /**< \brief (CHIPID_CIDR) 4K bytes */
#define   CHIPID_CIDR_SRAMSIZ_80K (0x6u << 16) /**< \brief (CHIPID_CIDR) 80K bytes */
#define   CHIPID_CIDR_SRAMSIZ_160K (0x7u << 16) /**< \brief (CHIPID_CIDR) 160K bytes */
#define   CHIPID_CIDR_SRAMSIZ_8K (0x8u << 16) /**< \brief (CHIPID_CIDR) 8K bytes */
#define   CHIPID_CIDR_SRAMSIZ_16K (0x9u << 16) /**< \brief (CHIPID_CIDR) 16K bytes */
#define   CHIPID_CIDR_SRAMSIZ_32K (0xAu << 16) /**< \brief (CHIPID_CIDR) 32K bytes */
#define   CHIPID_CIDR_SRAMSIZ_64K (0xBu << 16) /**< \brief (CHIPID_CIDR) 64K bytes */
#define   CHIPID_CIDR_SRAMSIZ_128K (0xCu << 16) /**< \brief (CHIPID_CIDR) 128K bytes */
#define   CHIPID_CIDR_SRAMSIZ_256K (0xDu << 16) /**< \brief (CHIPID_CIDR) 256K bytes */
#define   CHIPID_CIDR_SRAMSIZ_96K (0xEu << 16) /**< \brief (CHIPID_CIDR) 96K bytes */
#define   CHIPID_CIDR_SRAMSIZ_512K (0xFu << 16) /**< \brief (CHIPID_CIDR) 512K bytes */
#define CHIPID_CIDR_ARCH_Pos 20
#define CHIPID_CIDR_ARCH_Msk (0xffu << CHIPID_CIDR_ARCH_Pos) /**< \brief (CHIPID_CIDR) Architecture Identifier */
#define   CHIPID_CIDR_ARCH_AT91SAM9xx (0x19u << 20) /**< \brief (CHIPID_CIDR) AT91SAM9xx Series */
#define   CHIPID_CIDR_ARCH_AT91SAM9XExx (0x29u << 20) /**< \brief (CHIPID_CIDR) AT91SAM9XExx Series */
#define   CHIPID_CIDR_ARCH_AT91x34 (0x34u << 20) /**< \brief (CHIPID_CIDR) AT91x34 Series */
#define   CHIPID_CIDR_ARCH_CAP7 (0x37u << 20) /**< \brief (CHIPID_CIDR) CAP7 Series */
#define   CHIPID_CIDR_ARCH_CAP9 (0x39u << 20) /**< \brief (CHIPID_CIDR) CAP9 Series */
#define   CHIPID_CIDR_ARCH_CAP11 (0x3Bu << 20) /**< \brief (CHIPID_CIDR) CAP11 Series */
#define   CHIPID_CIDR_ARCH_AT91x40 (0x40u << 20) /**< \brief (CHIPID_CIDR) AT91x40 Series */
#define   CHIPID_CIDR_ARCH_AT91x42 (0x42u << 20) /**< \brief (CHIPID_CIDR) AT91x42 Series */
#define   CHIPID_CIDR_ARCH_AT91x55 (0x55u << 20) /**< \brief (CHIPID_CIDR) AT91x55 Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7Axx (0x60u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7Axx Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7AQxx (0x61u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7AQxx Series */
#define   CHIPID_CIDR_ARCH_AT91x63 (0x63u << 20) /**< \brief (CHIPID_CIDR) AT91x63 Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7Sxx (0x70u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7Sxx Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7XCxx (0x71u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7XCxx Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7SExx (0x72u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7SExx Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7Lxx (0x73u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7Lxx Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7Xxx (0x75u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7Xxx Series */
#define   CHIPID_CIDR_ARCH_AT91SAM7SLxx (0x76u << 20) /**< \brief (CHIPID_CIDR) AT91SAM7SLxx Series */
#define   CHIPID_CIDR_ARCH_SAM3UxC (0x80u << 20) /**< \brief (CHIPID_CIDR) SAM3UxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3UxE (0x81u << 20) /**< \brief (CHIPID_CIDR) SAM3UxE Series (144-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3AxC (0x83u << 20) /**< \brief (CHIPID_CIDR) SAM3AxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM4AxC (0x83u << 20) /**< \brief (CHIPID_CIDR) SAM4AxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3XxC (0x84u << 20) /**< \brief (CHIPID_CIDR) SAM3XxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM4XxC (0x84u << 20) /**< \brief (CHIPID_CIDR) SAM4XxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3XxE (0x85u << 20) /**< \brief (CHIPID_CIDR) SAM3XxE Series (144-pin version) */
#define   CHIPID_CIDR_ARCH_SAM4XxE (0x85u << 20) /**< \brief (CHIPID_CIDR) SAM4XxE Series (144-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3XxG (0x86u << 20) /**< \brief (CHIPID_CIDR) SAM3XxG Series (208/217-pin version) */
#define   CHIPID_CIDR_ARCH_SAM4XxG (0x86u << 20) /**< \brief (CHIPID_CIDR) SAM4XxG Series (208/217-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3SxA (0x88u << 20) /**< \brief (CHIPID_CIDR) SAM3SxASeries (48-pin version) */
#define   CHIPID_CIDR_ARCH_SAM4SxA (0x88u << 20) /**< \brief (CHIPID_CIDR) SAM4SxA Series (48-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3SxB (0x89u << 20) /**< \brief (CHIPID_CIDR) SAM3SxB Series (64-pin version) */
#define   CHIPID_CIDR_ARCH_SAM4SxB (0x89u << 20) /**< \brief (CHIPID_CIDR) SAM4SxB Series (64-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3SxC (0x8Au << 20) /**< \brief (CHIPID_CIDR) SAM3SxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM4SxC (0x8Au << 20) /**< \brief (CHIPID_CIDR) SAM4SxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_AT91x92 (0x92u << 20) /**< \brief (CHIPID_CIDR) AT91x92 Series */
#define   CHIPID_CIDR_ARCH_SAM3NxA (0x93u << 20) /**< \brief (CHIPID_CIDR) SAM3NxA Series (48-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3NxB (0x94u << 20) /**< \brief (CHIPID_CIDR) SAM3NxB Series (64-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3NxC (0x95u << 20) /**< \brief (CHIPID_CIDR) SAM3NxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3SDxB (0x99u << 20) /**< \brief (CHIPID_CIDR) SAM3SDxB Series (64-pin version) */
#define   CHIPID_CIDR_ARCH_SAM3SDxC (0x9Au << 20) /**< \brief (CHIPID_CIDR) SAM3SDxC Series (100-pin version) */
#define   CHIPID_CIDR_ARCH_SAM5A (0xA5u << 20) /**< \brief (CHIPID_CIDR) SAM5A */
#define   CHIPID_CIDR_ARCH_AT75Cxx (0xF0u << 20) /**< \brief (CHIPID_CIDR) AT75Cxx Series */
#define CHIPID_CIDR_NVPTYP_Pos 28
#define CHIPID_CIDR_NVPTYP_Msk (0x7u << CHIPID_CIDR_NVPTYP_Pos) /**< \brief (CHIPID_CIDR) Nonvolatile Program Memory Type */
#define   CHIPID_CIDR_NVPTYP_ROM (0x0u << 28) /**< \brief (CHIPID_CIDR) ROM */
#define   CHIPID_CIDR_NVPTYP_ROMLESS (0x1u << 28) /**< \brief (CHIPID_CIDR) ROMless or on-chip Flash */
#define   CHIPID_CIDR_NVPTYP_FLASH (0x2u << 28) /**< \brief (CHIPID_CIDR) Embedded Flash Memory */
#define   CHIPID_CIDR_NVPTYP_ROM_FLASH (0x3u << 28) /**< \brief (CHIPID_CIDR) ROM and Embedded Flash MemoryNVPSIZ is ROM size      NVPSIZ2 is Flash size */
#define   CHIPID_CIDR_NVPTYP_SRAM (0x4u << 28) /**< \brief (CHIPID_CIDR) SRAM emulating ROM */
#define CHIPID_CIDR_EXT (0x1u << 31) /**< \brief (CHIPID_CIDR) Extension Flag */
/* -------- CHIPID_EXID : (CHIPID Offset: 0x4) Chip ID Extension Register -------- */
#define CHIPID_EXID_EXID_Pos 0
#define CHIPID_EXID_EXID_Msk (0xffffffffu << CHIPID_EXID_EXID_Pos) /**< \brief (CHIPID_EXID) Chip ID Extension */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Cyclic Redundancy Check Calculation Unit */
/* ============================================================================= */
/** \addtogroup SAM3S16_CRCCU Cyclic Redundancy Check Calculation Unit */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Crccu hardware registers */
typedef struct {
  RwReg CRCCU_DSCR;    /**< \brief (Crccu Offset: 0x00000000) CRCCU Descriptor Base Register */
  RoReg Reserved1[1];
  WoReg CRCCU_DMA_EN;  /**< \brief (Crccu Offset: 0x00000008) CRCCU DMA Enable Register */
  WoReg CRCCU_DMA_DIS; /**< \brief (Crccu Offset: 0x0000000C) CRCCU DMA Disable Register */
  RoReg CRCCU_DMA_SR;  /**< \brief (Crccu Offset: 0x00000010) CRCCU DMA Status Register */
  WoReg CRCCU_DMA_IER; /**< \brief (Crccu Offset: 0x00000014) CRCCU DMA Interrupt Enable Register */
  WoReg CRCCU_DMA_IDR; /**< \brief (Crccu Offset: 0x00000018) CRCCU DMA Interrupt Disable Register */
  RoReg CRCCU_DMA_IMR; /**< \brief (Crccu Offset: 0x0000001C) CRCCU DMA Interrupt Mask Register */
  RoReg CRCCU_DMA_ISR; /**< \brief (Crccu Offset: 0x00000020) CRCCU DMA Interrupt Status Register */
  RoReg Reserved2[4];
  WoReg CRCCU_CR;      /**< \brief (Crccu Offset: 0x00000034) CRCCU Control Register */
  RwReg CRCCU_MR;      /**< \brief (Crccu Offset: 0x00000038) CRCCU Mode Register */
  RoReg CRCCU_SR;      /**< \brief (Crccu Offset: 0x0000003C) CRCCU Status Register */
  WoReg CRCCU_IER;     /**< \brief (Crccu Offset: 0x00000040) CRCCU Interrupt Enable Register */
  WoReg CRCCU_IDR;     /**< \brief (Crccu Offset: 0x00000044) CRCCU Interrupt Disable Register */
  RoReg CRCCU_IMR;     /**< \brief (Crccu Offset: 0x00000048) CRCCU Interrupt Mask Register */
  RoReg CRCCU_ISR;     /**< \brief (Crccu Offset: 0x0000004C) CRCCU Interrupt Status Register */
} Crccu;
#endif /* __ASSEMBLY__ */
/* -------- CRCCU_DSCR : (CRCCU Offset: 0x00000000) CRCCU Descriptor Base Register -------- */
#define CRCCU_DSCR_DSCR_Pos 9
#define CRCCU_DSCR_DSCR_Msk (0x7fffffu << CRCCU_DSCR_DSCR_Pos) /**< \brief (CRCCU_DSCR) Descriptor Base Address */
#define CRCCU_DSCR_DSCR(value) ((CRCCU_DSCR_DSCR_Msk & ((value) << CRCCU_DSCR_DSCR_Pos)))
/* -------- CRCCU_DMA_EN : (CRCCU Offset: 0x00000008) CRCCU DMA Enable Register -------- */
#define CRCCU_DMA_EN_DMAEN (0x1u << 0) /**< \brief (CRCCU_DMA_EN) DMA Enable Register */
/* -------- CRCCU_DMA_DIS : (CRCCU Offset: 0x0000000C) CRCCU DMA Disable Register -------- */
#define CRCCU_DMA_DIS_DMADIS (0x1u << 0) /**< \brief (CRCCU_DMA_DIS) DMA Disable Register */
/* -------- CRCCU_DMA_SR : (CRCCU Offset: 0x00000010) CRCCU DMA Status Register -------- */
#define CRCCU_DMA_SR_DMASR (0x1u << 0) /**< \brief (CRCCU_DMA_SR) DMA Status Register */
/* -------- CRCCU_DMA_IER : (CRCCU Offset: 0x00000014) CRCCU DMA Interrupt Enable Register -------- */
#define CRCCU_DMA_IER_DMAIER (0x1u << 0) /**< \brief (CRCCU_DMA_IER) Interrupt Enable register */
/* -------- CRCCU_DMA_IDR : (CRCCU Offset: 0x00000018) CRCCU DMA Interrupt Disable Register -------- */
#define CRCCU_DMA_IDR_DMAIDR (0x1u << 0) /**< \brief (CRCCU_DMA_IDR) Interrupt Disable register */
/* -------- CRCCU_DMA_IMR : (CRCCU Offset: 0x0000001C) CRCCU DMA Interrupt Mask Register -------- */
#define CRCCU_DMA_IMR_DMAIMR (0x1u << 0) /**< \brief (CRCCU_DMA_IMR) Interrupt Mask Register */
/* -------- CRCCU_DMA_ISR : (CRCCU Offset: 0x00000020) CRCCU DMA Interrupt Status Register -------- */
#define CRCCU_DMA_ISR_DMAISR (0x1u << 0) /**< \brief (CRCCU_DMA_ISR) Interrupt Status register */
/* -------- CRCCU_CR : (CRCCU Offset: 0x00000034) CRCCU Control Register -------- */
#define CRCCU_CR_RESET (0x1u << 0) /**< \brief (CRCCU_CR) CRC Computation Reset */
/* -------- CRCCU_MR : (CRCCU Offset: 0x00000038) CRCCU Mode Register -------- */
#define CRCCU_MR_ENABLE (0x1u << 0) /**< \brief (CRCCU_MR) CRC Enable */
#define CRCCU_MR_COMPARE (0x1u << 1) /**< \brief (CRCCU_MR) CRC Compare */
#define CRCCU_MR_PTYPE_Pos 2
#define CRCCU_MR_PTYPE_Msk (0x3u << CRCCU_MR_PTYPE_Pos) /**< \brief (CRCCU_MR) Primitive Polynomial */
#define   CRCCU_MR_PTYPE_CCIT8023 (0x0u << 2) /**< \brief (CRCCU_MR) Polynom 0x04C11DB7 */
#define   CRCCU_MR_PTYPE_CASTAGNOLI (0x1u << 2) /**< \brief (CRCCU_MR) Polynom 0x1EDC6F41 */
#define   CRCCU_MR_PTYPE_CCIT16 (0x2u << 2) /**< \brief (CRCCU_MR) Polynom 0x1021 */
#define CRCCU_MR_DIVIDER_Pos 4
#define CRCCU_MR_DIVIDER_Msk (0xfu << CRCCU_MR_DIVIDER_Pos) /**< \brief (CRCCU_MR) Request Divider */
#define CRCCU_MR_DIVIDER(value) ((CRCCU_MR_DIVIDER_Msk & ((value) << CRCCU_MR_DIVIDER_Pos)))
/* -------- CRCCU_SR : (CRCCU Offset: 0x0000003C) CRCCU Status Register -------- */
#define CRCCU_SR_CRC_Pos 0
#define CRCCU_SR_CRC_Msk (0xffffffffu << CRCCU_SR_CRC_Pos) /**< \brief (CRCCU_SR) Cyclic Redundancy Check Value */
/* -------- CRCCU_IER : (CRCCU Offset: 0x00000040) CRCCU Interrupt Enable Register -------- */
#define CRCCU_IER_ERRIER (0x1u << 0) /**< \brief (CRCCU_IER) CRC Error Interrupt Enable */
/* -------- CRCCU_IDR : (CRCCU Offset: 0x00000044) CRCCU Interrupt Disable Register -------- */
#define CRCCU_IDR_ERRIDR (0x1u << 0) /**< \brief (CRCCU_IDR) CRC Error Interrupt Disable */
/* -------- CRCCU_IMR : (CRCCU Offset: 0x00000048) CRCCU Interrupt Mask Register -------- */
#define CRCCU_IMR_ERRIMR (0x1u << 0) /**< \brief (CRCCU_IMR) CRC Error Interrupt Mask */
/* -------- CRCCU_ISR : (CRCCU Offset: 0x0000004C) CRCCU Interrupt Status Register -------- */
#define CRCCU_ISR_ERRISR (0x1u << 0) /**< \brief (CRCCU_ISR) CRC Error Interrupt Status */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Digital-to-Analog Converter Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_DACC Digital-to-Analog Converter Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Dacc hardware registers */
typedef struct {
  WoReg DACC_CR;       /**< \brief (Dacc Offset: 0x00) Control Register */
  RwReg DACC_MR;       /**< \brief (Dacc Offset: 0x04) Mode Register */
  RoReg Reserved1[2];
  WoReg DACC_CHER;     /**< \brief (Dacc Offset: 0x10) Channel Enable Register */
  WoReg DACC_CHDR;     /**< \brief (Dacc Offset: 0x14) Channel Disable Register */
  RoReg DACC_CHSR;     /**< \brief (Dacc Offset: 0x18) Channel Status Register */
  RoReg Reserved2[1];
  WoReg DACC_CDR;      /**< \brief (Dacc Offset: 0x20) Conversion Data Register */
  WoReg DACC_IER;      /**< \brief (Dacc Offset: 0x24) Interrupt Enable Register */
  WoReg DACC_IDR;      /**< \brief (Dacc Offset: 0x28) Interrupt Disable Register */
  RoReg DACC_IMR;      /**< \brief (Dacc Offset: 0x2C) Interrupt Mask Register */
  RoReg DACC_ISR;      /**< \brief (Dacc Offset: 0x30) Interrupt Status Register */
  RoReg Reserved3[24];
  RwReg DACC_ACR;      /**< \brief (Dacc Offset: 0x94) Analog Current Register */
  RoReg Reserved4[19];
  RwReg DACC_WPMR;     /**< \brief (Dacc Offset: 0xE4) Write Protect Mode register */
  RoReg DACC_WPSR;     /**< \brief (Dacc Offset: 0xE8) Write Protect Status register */
  RoReg Reserved5[5];
  RwReg DACC_RPR;      /**< \brief (Dacc Offset: 0x100) Receive Pointer Register */
  RwReg DACC_RCR;      /**< \brief (Dacc Offset: 0x104) Receive Counter Register */
  RwReg DACC_TPR;      /**< \brief (Dacc Offset: 0x108) Transmit Pointer Register */
  RwReg DACC_TCR;      /**< \brief (Dacc Offset: 0x10C) Transmit Counter Register */
  RwReg DACC_RNPR;     /**< \brief (Dacc Offset: 0x110) Receive Next Pointer Register */
  RwReg DACC_RNCR;     /**< \brief (Dacc Offset: 0x114) Receive Next Counter Register */
  RwReg DACC_TNPR;     /**< \brief (Dacc Offset: 0x118) Transmit Next Pointer Register */
  RwReg DACC_TNCR;     /**< \brief (Dacc Offset: 0x11C) Transmit Next Counter Register */
  WoReg DACC_PTCR;     /**< \brief (Dacc Offset: 0x120) Transfer Control Register */
  RoReg DACC_PTSR;     /**< \brief (Dacc Offset: 0x124) Transfer Status Register */
} Dacc;
#endif /* __ASSEMBLY__ */
/* -------- DACC_CR : (DACC Offset: 0x00) Control Register -------- */
#define DACC_CR_SWRST (0x1u << 0) /**< \brief (DACC_CR) Software Reset */
/* -------- DACC_MR : (DACC Offset: 0x04) Mode Register -------- */
#define DACC_MR_TRGEN (0x1u << 0) /**< \brief (DACC_MR) Trigger Enable */
#define   DACC_MR_TRGEN_DIS (0x0u << 0) /**< \brief (DACC_MR) External trigger mode disabled. DACC in free running mode. */
#define   DACC_MR_TRGEN_EN (0x1u << 0) /**< \brief (DACC_MR) External trigger mode enabled. */
#define DACC_MR_TRGSEL_Pos 1
#define DACC_MR_TRGSEL_Msk (0x7u << DACC_MR_TRGSEL_Pos) /**< \brief (DACC_MR) Trigger Selection */
#define DACC_MR_TRGSEL(value) ((DACC_MR_TRGSEL_Msk & ((value) << DACC_MR_TRGSEL_Pos)))
#define DACC_MR_WORD (0x1u << 4) /**< \brief (DACC_MR) Word Transfer */
#define   DACC_MR_WORD_HALF (0x0u << 4) /**< \brief (DACC_MR) Half-Word transfer */
#define   DACC_MR_WORD_WORD (0x1u << 4) /**< \brief (DACC_MR) Word Transfer */
#define DACC_MR_SLEEP (0x1u << 5) /**< \brief (DACC_MR) Sleep Mode */
#define DACC_MR_FASTWKUP (0x1u << 6) /**< \brief (DACC_MR) Fast Wake up Mode */
#define DACC_MR_REFRESH_Pos 8
#define DACC_MR_REFRESH_Msk (0xffu << DACC_MR_REFRESH_Pos) /**< \brief (DACC_MR) Refresh Period */
#define DACC_MR_REFRESH(value) ((DACC_MR_REFRESH_Msk & ((value) << DACC_MR_REFRESH_Pos)))
#define DACC_MR_USER_SEL_Pos 16
#define DACC_MR_USER_SEL_Msk (0x3u << DACC_MR_USER_SEL_Pos) /**< \brief (DACC_MR) User Channel Selection */
#define   DACC_MR_USER_SEL_CHANNEL0 (0x0u << 16) /**< \brief (DACC_MR) Channel 0 */
#define   DACC_MR_USER_SEL_CHANNEL1 (0x1u << 16) /**< \brief (DACC_MR) Channel 1 */
#define DACC_MR_TAG (0x1u << 20) /**< \brief (DACC_MR) Tag Selection Mode */
#define   DACC_MR_TAG_DIS (0x0u << 20) /**< \brief (DACC_MR) Tag selection mode disabled. Using USER_SEL to select the channel for the conversion. */
#define   DACC_MR_TAG_EN (0x1u << 20) /**< \brief (DACC_MR) Tag selection mode enabled */
#define DACC_MR_MAXS (0x1u << 21) /**< \brief (DACC_MR) Max Speed Mode */
#define DACC_MR_STARTUP_Pos 24
#define DACC_MR_STARTUP_Msk (0x3fu << DACC_MR_STARTUP_Pos) /**< \brief (DACC_MR) Startup Time Selection */
#define   DACC_MR_STARTUP_0 (0x0u << 24) /**< \brief (DACC_MR) 0 periods of DACClock */
#define   DACC_MR_STARTUP_8 (0x1u << 24) /**< \brief (DACC_MR) 8 periods of DACClock */
#define   DACC_MR_STARTUP_16 (0x2u << 24) /**< \brief (DACC_MR) 16 periods of DACClock */
#define   DACC_MR_STARTUP_24 (0x3u << 24) /**< \brief (DACC_MR) 24 periods of DACClock */
#define   DACC_MR_STARTUP_64 (0x4u << 24) /**< \brief (DACC_MR) 64 periods of DACClock */
#define   DACC_MR_STARTUP_80 (0x5u << 24) /**< \brief (DACC_MR) 80 periods of DACClock */
#define   DACC_MR_STARTUP_96 (0x6u << 24) /**< \brief (DACC_MR) 96 periods of DACClock */
#define   DACC_MR_STARTUP_112 (0x7u << 24) /**< \brief (DACC_MR) 112 periods of DACClock */
#define   DACC_MR_STARTUP_512 (0x8u << 24) /**< \brief (DACC_MR) 512 periods of DACClock */
#define   DACC_MR_STARTUP_576 (0x9u << 24) /**< \brief (DACC_MR) 576 periods of DACClock */
#define   DACC_MR_STARTUP_640 (0xAu << 24) /**< \brief (DACC_MR) 640 periods of DACClock */
#define   DACC_MR_STARTUP_704 (0xBu << 24) /**< \brief (DACC_MR) 704 periods of DACClock */
#define   DACC_MR_STARTUP_768 (0xCu << 24) /**< \brief (DACC_MR) 768 periods of DACClock */
#define   DACC_MR_STARTUP_832 (0xDu << 24) /**< \brief (DACC_MR) 832 periods of DACClock */
#define   DACC_MR_STARTUP_896 (0xEu << 24) /**< \brief (DACC_MR) 896 periods of DACClock */
#define   DACC_MR_STARTUP_960 (0xFu << 24) /**< \brief (DACC_MR) 960 periods of DACClock */
#define   DACC_MR_STARTUP_1024 (0x10u << 24) /**< \brief (DACC_MR) 1024 periods of DACClock */
#define   DACC_MR_STARTUP_1088 (0x11u << 24) /**< \brief (DACC_MR) 1088 periods of DACClock */
#define   DACC_MR_STARTUP_1152 (0x12u << 24) /**< \brief (DACC_MR) 1152 periods of DACClock */
#define   DACC_MR_STARTUP_1216 (0x13u << 24) /**< \brief (DACC_MR) 1216 periods of DACClock */
#define   DACC_MR_STARTUP_1280 (0x14u << 24) /**< \brief (DACC_MR) 1280 periods of DACClock */
#define   DACC_MR_STARTUP_1344 (0x15u << 24) /**< \brief (DACC_MR) 1344 periods of DACClock */
#define   DACC_MR_STARTUP_1408 (0x16u << 24) /**< \brief (DACC_MR) 1408 periods of DACClock */
#define   DACC_MR_STARTUP_1472 (0x17u << 24) /**< \brief (DACC_MR) 1472 periods of DACClock */
#define   DACC_MR_STARTUP_1536 (0x18u << 24) /**< \brief (DACC_MR) 1536 periods of DACClock */
#define   DACC_MR_STARTUP_1600 (0x19u << 24) /**< \brief (DACC_MR) 1600 periods of DACClock */
#define   DACC_MR_STARTUP_1664 (0x1Au << 24) /**< \brief (DACC_MR) 1664 periods of DACClock */
#define   DACC_MR_STARTUP_1728 (0x1Bu << 24) /**< \brief (DACC_MR) 1728 periods of DACClock */
#define   DACC_MR_STARTUP_1792 (0x1Cu << 24) /**< \brief (DACC_MR) 1792 periods of DACClock */
#define   DACC_MR_STARTUP_1856 (0x1Du << 24) /**< \brief (DACC_MR) 1856 periods of DACClock */
#define   DACC_MR_STARTUP_1920 (0x1Eu << 24) /**< \brief (DACC_MR) 1920 periods of DACClock */
#define   DACC_MR_STARTUP_1984 (0x1Fu << 24) /**< \brief (DACC_MR) 1984 periods of DACClock */
/* -------- DACC_CHER : (DACC Offset: 0x10) Channel Enable Register -------- */
#define DACC_CHER_CH0 (0x1u << 0) /**< \brief (DACC_CHER) Channel 0 Enable */
#define DACC_CHER_CH1 (0x1u << 1) /**< \brief (DACC_CHER) Channel 1 Enable */
/* -------- DACC_CHDR : (DACC Offset: 0x14) Channel Disable Register -------- */
#define DACC_CHDR_CH0 (0x1u << 0) /**< \brief (DACC_CHDR) Channel 0 Disable */
#define DACC_CHDR_CH1 (0x1u << 1) /**< \brief (DACC_CHDR) Channel 1 Disable */
/* -------- DACC_CHSR : (DACC Offset: 0x18) Channel Status Register -------- */
#define DACC_CHSR_CH0 (0x1u << 0) /**< \brief (DACC_CHSR) Channel 0 Status */
#define DACC_CHSR_CH1 (0x1u << 1) /**< \brief (DACC_CHSR) Channel 1 Status */
/* -------- DACC_CDR : (DACC Offset: 0x20) Conversion Data Register -------- */
#define DACC_CDR_DATA_Pos 0
#define DACC_CDR_DATA_Msk (0xffffffffu << DACC_CDR_DATA_Pos) /**< \brief (DACC_CDR) Data to Convert */
#define DACC_CDR_DATA(value) ((DACC_CDR_DATA_Msk & ((value) << DACC_CDR_DATA_Pos)))
/* -------- DACC_IER : (DACC Offset: 0x24) Interrupt Enable Register -------- */
#define DACC_IER_TXRDY (0x1u << 0) /**< \brief (DACC_IER) Transmit Ready Interrupt Enable */
#define DACC_IER_EOC (0x1u << 1) /**< \brief (DACC_IER) End of Conversion Interrupt Enable */
#define DACC_IER_ENDTX (0x1u << 2) /**< \brief (DACC_IER) End of Transmit Buffer Interrupt Enable */
#define DACC_IER_TXBUFE (0x1u << 3) /**< \brief (DACC_IER) Transmit Buffer Empty Interrupt Enable */
/* -------- DACC_IDR : (DACC Offset: 0x28) Interrupt Disable Register -------- */
#define DACC_IDR_TXRDY (0x1u << 0) /**< \brief (DACC_IDR) Transmit Ready Interrupt Disable. */
#define DACC_IDR_EOC (0x1u << 1) /**< \brief (DACC_IDR) End of Conversion Interrupt Disable */
#define DACC_IDR_ENDTX (0x1u << 2) /**< \brief (DACC_IDR) End of Transmit Buffer Interrupt Disable */
#define DACC_IDR_TXBUFE (0x1u << 3) /**< \brief (DACC_IDR) Transmit Buffer Empty Interrupt Disable */
/* -------- DACC_IMR : (DACC Offset: 0x2C) Interrupt Mask Register -------- */
#define DACC_IMR_TXRDY (0x1u << 0) /**< \brief (DACC_IMR) Transmit Ready Interrupt Mask */
#define DACC_IMR_EOC (0x1u << 1) /**< \brief (DACC_IMR) End of Conversion Interrupt Mask */
#define DACC_IMR_ENDTX (0x1u << 2) /**< \brief (DACC_IMR) End of Transmit Buffer Interrupt Mask */
#define DACC_IMR_TXBUFE (0x1u << 3) /**< \brief (DACC_IMR) Transmit Buffer Empty Interrupt Mask */
/* -------- DACC_ISR : (DACC Offset: 0x30) Interrupt Status Register -------- */
#define DACC_ISR_TXRDY (0x1u << 0) /**< \brief (DACC_ISR) Transmit Ready Interrupt Flag */
#define DACC_ISR_EOC (0x1u << 1) /**< \brief (DACC_ISR) End of Conversion Interrupt Flag */
#define DACC_ISR_ENDTX (0x1u << 2) /**< \brief (DACC_ISR) End of DMA Interrupt Flag */
#define DACC_ISR_TXBUFE (0x1u << 3) /**< \brief (DACC_ISR) Transmit Buffer Empty */
/* -------- DACC_ACR : (DACC Offset: 0x94) Analog Current Register -------- */
#define DACC_ACR_IBCTLCH0_Pos 0
#define DACC_ACR_IBCTLCH0_Msk (0x3u << DACC_ACR_IBCTLCH0_Pos) /**< \brief (DACC_ACR) Analog Output Current Control */
#define DACC_ACR_IBCTLCH0(value) ((DACC_ACR_IBCTLCH0_Msk & ((value) << DACC_ACR_IBCTLCH0_Pos)))
#define DACC_ACR_IBCTLCH1_Pos 2
#define DACC_ACR_IBCTLCH1_Msk (0x3u << DACC_ACR_IBCTLCH1_Pos) /**< \brief (DACC_ACR) Analog Output Current Control */
#define DACC_ACR_IBCTLCH1(value) ((DACC_ACR_IBCTLCH1_Msk & ((value) << DACC_ACR_IBCTLCH1_Pos)))
#define DACC_ACR_IBCTLDACCORE_Pos 8
#define DACC_ACR_IBCTLDACCORE_Msk (0x3u << DACC_ACR_IBCTLDACCORE_Pos) /**< \brief (DACC_ACR) Bias Current Control for DAC Core */
#define DACC_ACR_IBCTLDACCORE(value) ((DACC_ACR_IBCTLDACCORE_Msk & ((value) << DACC_ACR_IBCTLDACCORE_Pos)))
/* -------- DACC_WPMR : (DACC Offset: 0xE4) Write Protect Mode register -------- */
#define DACC_WPMR_WPEN (0x1u << 0) /**< \brief (DACC_WPMR) Write Protect Enable */
#define DACC_WPMR_WPKEY_Pos 8
#define DACC_WPMR_WPKEY_Msk (0xffffffu << DACC_WPMR_WPKEY_Pos) /**< \brief (DACC_WPMR) Write Protect KEY */
#define DACC_WPMR_WPKEY(value) ((DACC_WPMR_WPKEY_Msk & ((value) << DACC_WPMR_WPKEY_Pos)))
/* -------- DACC_WPSR : (DACC Offset: 0xE8) Write Protect Status register -------- */
#define DACC_WPSR_WPROTERR (0x1u << 0) /**< \brief (DACC_WPSR) Write protection error */
#define DACC_WPSR_WPROTADDR_Pos 8
#define DACC_WPSR_WPROTADDR_Msk (0xffu << DACC_WPSR_WPROTADDR_Pos) /**< \brief (DACC_WPSR) Write protection error address */
/* -------- DACC_RPR : (DACC Offset: 0x100) Receive Pointer Register -------- */
#define DACC_RPR_RXPTR_Pos 0
#define DACC_RPR_RXPTR_Msk (0xffffffffu << DACC_RPR_RXPTR_Pos) /**< \brief (DACC_RPR) Receive Pointer Register */
#define DACC_RPR_RXPTR(value) ((DACC_RPR_RXPTR_Msk & ((value) << DACC_RPR_RXPTR_Pos)))
/* -------- DACC_RCR : (DACC Offset: 0x104) Receive Counter Register -------- */
#define DACC_RCR_RXCTR_Pos 0
#define DACC_RCR_RXCTR_Msk (0xffffu << DACC_RCR_RXCTR_Pos) /**< \brief (DACC_RCR) Receive Counter Register */
#define DACC_RCR_RXCTR(value) ((DACC_RCR_RXCTR_Msk & ((value) << DACC_RCR_RXCTR_Pos)))
/* -------- DACC_TPR : (DACC Offset: 0x108) Transmit Pointer Register -------- */
#define DACC_TPR_TXPTR_Pos 0
#define DACC_TPR_TXPTR_Msk (0xffffffffu << DACC_TPR_TXPTR_Pos) /**< \brief (DACC_TPR) Transmit Counter Register */
#define DACC_TPR_TXPTR(value) ((DACC_TPR_TXPTR_Msk & ((value) << DACC_TPR_TXPTR_Pos)))
/* -------- DACC_TCR : (DACC Offset: 0x10C) Transmit Counter Register -------- */
#define DACC_TCR_TXCTR_Pos 0
#define DACC_TCR_TXCTR_Msk (0xffffu << DACC_TCR_TXCTR_Pos) /**< \brief (DACC_TCR) Transmit Counter Register */
#define DACC_TCR_TXCTR(value) ((DACC_TCR_TXCTR_Msk & ((value) << DACC_TCR_TXCTR_Pos)))
/* -------- DACC_RNPR : (DACC Offset: 0x110) Receive Next Pointer Register -------- */
#define DACC_RNPR_RXNPTR_Pos 0
#define DACC_RNPR_RXNPTR_Msk (0xffffffffu << DACC_RNPR_RXNPTR_Pos) /**< \brief (DACC_RNPR) Receive Next Pointer */
#define DACC_RNPR_RXNPTR(value) ((DACC_RNPR_RXNPTR_Msk & ((value) << DACC_RNPR_RXNPTR_Pos)))
/* -------- DACC_RNCR : (DACC Offset: 0x114) Receive Next Counter Register -------- */
#define DACC_RNCR_RXNCTR_Pos 0
#define DACC_RNCR_RXNCTR_Msk (0xffffu << DACC_RNCR_RXNCTR_Pos) /**< \brief (DACC_RNCR) Receive Next Counter */
#define DACC_RNCR_RXNCTR(value) ((DACC_RNCR_RXNCTR_Msk & ((value) << DACC_RNCR_RXNCTR_Pos)))
/* -------- DACC_TNPR : (DACC Offset: 0x118) Transmit Next Pointer Register -------- */
#define DACC_TNPR_TXNPTR_Pos 0
#define DACC_TNPR_TXNPTR_Msk (0xffffffffu << DACC_TNPR_TXNPTR_Pos) /**< \brief (DACC_TNPR) Transmit Next Pointer */
#define DACC_TNPR_TXNPTR(value) ((DACC_TNPR_TXNPTR_Msk & ((value) << DACC_TNPR_TXNPTR_Pos)))
/* -------- DACC_TNCR : (DACC Offset: 0x11C) Transmit Next Counter Register -------- */
#define DACC_TNCR_TXNCTR_Pos 0
#define DACC_TNCR_TXNCTR_Msk (0xffffu << DACC_TNCR_TXNCTR_Pos) /**< \brief (DACC_TNCR) Transmit Counter Next */
#define DACC_TNCR_TXNCTR(value) ((DACC_TNCR_TXNCTR_Msk & ((value) << DACC_TNCR_TXNCTR_Pos)))
/* -------- DACC_PTCR : (DACC Offset: 0x120) Transfer Control Register -------- */
#define DACC_PTCR_RXTEN (0x1u << 0) /**< \brief (DACC_PTCR) Receiver Transfer Enable */
#define DACC_PTCR_RXTDIS (0x1u << 1) /**< \brief (DACC_PTCR) Receiver Transfer Disable */
#define DACC_PTCR_TXTEN (0x1u << 8) /**< \brief (DACC_PTCR) Transmitter Transfer Enable */
#define DACC_PTCR_TXTDIS (0x1u << 9) /**< \brief (DACC_PTCR) Transmitter Transfer Disable */
/* -------- DACC_PTSR : (DACC Offset: 0x124) Transfer Status Register -------- */
#define DACC_PTSR_RXTEN (0x1u << 0) /**< \brief (DACC_PTSR) Receiver Transfer Enable */
#define DACC_PTSR_TXTEN (0x1u << 8) /**< \brief (DACC_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Embedded Flash Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_EFC Embedded Flash Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Efc hardware registers */
typedef struct {
  RwReg EEFC_FMR; /**< \brief (Efc Offset: 0x00) EEFC Flash Mode Register */
  WoReg EEFC_FCR; /**< \brief (Efc Offset: 0x04) EEFC Flash Command Register */
  RoReg EEFC_FSR; /**< \brief (Efc Offset: 0x08) EEFC Flash Status Register */
  RoReg EEFC_FRR; /**< \brief (Efc Offset: 0x0C) EEFC Flash Result Register */
} Efc;
#endif /* __ASSEMBLY__ */
/* -------- EEFC_FMR : (EFC Offset: 0x00) EEFC Flash Mode Register -------- */
#define EEFC_FMR_FRDY (0x1u << 0) /**< \brief (EEFC_FMR) Ready Interrupt Enable */
#define EEFC_FMR_FWS_Pos 8
#define EEFC_FMR_FWS_Msk (0xfu << EEFC_FMR_FWS_Pos) /**< \brief (EEFC_FMR) Flash Wait State */
#define EEFC_FMR_FWS(value) ((EEFC_FMR_FWS_Msk & ((value) << EEFC_FMR_FWS_Pos)))
#define EEFC_FMR_SCOD (0x1u << 16) /**< \brief (EEFC_FMR) Sequential Code Optimization Disable */
#define EEFC_FMR_FAM (0x1u << 24) /**< \brief (EEFC_FMR) Flash Access Mode */
#define EEFC_FMR_CLOE (0x1u << 26) /**< \brief (EEFC_FMR) Code Loops Optimization Enable */
/* -------- EEFC_FCR : (EFC Offset: 0x04) EEFC Flash Command Register -------- */
#define EEFC_FCR_FCMD_Pos 0
#define EEFC_FCR_FCMD_Msk (0xffu << EEFC_FCR_FCMD_Pos) /**< \brief (EEFC_FCR) Flash Command */
#define EEFC_FCR_FCMD(value) ((EEFC_FCR_FCMD_Msk & ((value) << EEFC_FCR_FCMD_Pos)))
#define EEFC_FCR_FARG_Pos 8
#define EEFC_FCR_FARG_Msk (0xffffu << EEFC_FCR_FARG_Pos) /**< \brief (EEFC_FCR) Flash Command Argument */
#define EEFC_FCR_FARG(value) ((EEFC_FCR_FARG_Msk & ((value) << EEFC_FCR_FARG_Pos)))
#define EEFC_FCR_FKEY_Pos 24
#define EEFC_FCR_FKEY_Msk (0xffu << EEFC_FCR_FKEY_Pos) /**< \brief (EEFC_FCR) Flash Writing Protection Key */
#define EEFC_FCR_FKEY(value) ((EEFC_FCR_FKEY_Msk & ((value) << EEFC_FCR_FKEY_Pos)))
/* -------- EEFC_FSR : (EFC Offset: 0x08) EEFC Flash Status Register -------- */
#define EEFC_FSR_FRDY (0x1u << 0) /**< \brief (EEFC_FSR) Flash Ready Status */
#define EEFC_FSR_FCMDE (0x1u << 1) /**< \brief (EEFC_FSR) Flash Command Error Status */
#define EEFC_FSR_FLOCKE (0x1u << 2) /**< \brief (EEFC_FSR) Flash Lock Error Status */
#define EEFC_FSR_FLERR (0x1u << 3) /**< \brief (EEFC_FSR) Flash Error Status */
/* -------- EEFC_FRR : (EFC Offset: 0x0C) EEFC Flash Result Register -------- */
#define EEFC_FRR_FVALUE_Pos 0
#define EEFC_FRR_FVALUE_Msk (0xffffffffu << EEFC_FRR_FVALUE_Pos) /**< \brief (EEFC_FRR) Flash Result Value */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR General Purpose Backup Register */
/* ============================================================================= */
/** \addtogroup SAM3S16_GPBR General Purpose Backup Register */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Gpbr hardware registers */
typedef struct {
  RwReg SYS_GPBR0; /**< \brief (Gpbr Offset: 0x0) General Purpose Backup Register 0 */
  RwReg SYS_GPBR1; /**< \brief (Gpbr Offset: 0x4) General Purpose Backup Register 1 */
  RwReg SYS_GPBR2; /**< \brief (Gpbr Offset: 0x8) General Purpose Backup Register 2 */
  RwReg SYS_GPBR3; /**< \brief (Gpbr Offset: 0xC) General Purpose Backup Register 3 */
  RwReg SYS_GPBR4; /**< \brief (Gpbr Offset: 0x10) General Purpose Backup Register 4 */
  RwReg SYS_GPBR5; /**< \brief (Gpbr Offset: 0x14) General Purpose Backup Register 5 */
  RwReg SYS_GPBR6; /**< \brief (Gpbr Offset: 0x18) General Purpose Backup Register 6 */
  RwReg SYS_GPBR7; /**< \brief (Gpbr Offset: 0x1C) General Purpose Backup Register 7 */
} Gpbr;
#endif /* __ASSEMBLY__ */
/* -------- SYS_GPBR0 : (GPBR Offset: 0x0) General Purpose Backup Register 0 -------- */
#define SYS_GPBR0_GPBR_VALUE0_Pos 0
#define SYS_GPBR0_GPBR_VALUE0_Msk (0xffffffffu << SYS_GPBR0_GPBR_VALUE0_Pos) /**< \brief (SYS_GPBR0) Value of GPBR x */
#define SYS_GPBR0_GPBR_VALUE0(value) ((SYS_GPBR0_GPBR_VALUE0_Msk & ((value) << SYS_GPBR0_GPBR_VALUE0_Pos)))
/* -------- SYS_GPBR1 : (GPBR Offset: 0x4) General Purpose Backup Register 1 -------- */
#define SYS_GPBR1_GPBR_VALUE1_Pos 0
#define SYS_GPBR1_GPBR_VALUE1_Msk (0xffffffffu << SYS_GPBR1_GPBR_VALUE1_Pos) /**< \brief (SYS_GPBR1) Value of GPBR x */
#define SYS_GPBR1_GPBR_VALUE1(value) ((SYS_GPBR1_GPBR_VALUE1_Msk & ((value) << SYS_GPBR1_GPBR_VALUE1_Pos)))
/* -------- SYS_GPBR2 : (GPBR Offset: 0x8) General Purpose Backup Register 2 -------- */
#define SYS_GPBR2_GPBR_VALUE2_Pos 0
#define SYS_GPBR2_GPBR_VALUE2_Msk (0xffffffffu << SYS_GPBR2_GPBR_VALUE2_Pos) /**< \brief (SYS_GPBR2) Value of GPBR x */
#define SYS_GPBR2_GPBR_VALUE2(value) ((SYS_GPBR2_GPBR_VALUE2_Msk & ((value) << SYS_GPBR2_GPBR_VALUE2_Pos)))
/* -------- SYS_GPBR3 : (GPBR Offset: 0xC) General Purpose Backup Register 3 -------- */
#define SYS_GPBR3_GPBR_VALUE3_Pos 0
#define SYS_GPBR3_GPBR_VALUE3_Msk (0xffffffffu << SYS_GPBR3_GPBR_VALUE3_Pos) /**< \brief (SYS_GPBR3) Value of GPBR x */
#define SYS_GPBR3_GPBR_VALUE3(value) ((SYS_GPBR3_GPBR_VALUE3_Msk & ((value) << SYS_GPBR3_GPBR_VALUE3_Pos)))
/* -------- SYS_GPBR4 : (GPBR Offset: 0x10) General Purpose Backup Register 4 -------- */
#define SYS_GPBR4_GPBR_VALUE4_Pos 0
#define SYS_GPBR4_GPBR_VALUE4_Msk (0xffffffffu << SYS_GPBR4_GPBR_VALUE4_Pos) /**< \brief (SYS_GPBR4) Value of GPBR x */
#define SYS_GPBR4_GPBR_VALUE4(value) ((SYS_GPBR4_GPBR_VALUE4_Msk & ((value) << SYS_GPBR4_GPBR_VALUE4_Pos)))
/* -------- SYS_GPBR5 : (GPBR Offset: 0x14) General Purpose Backup Register 5 -------- */
#define SYS_GPBR5_GPBR_VALUE5_Pos 0
#define SYS_GPBR5_GPBR_VALUE5_Msk (0xffffffffu << SYS_GPBR5_GPBR_VALUE5_Pos) /**< \brief (SYS_GPBR5) Value of GPBR x */
#define SYS_GPBR5_GPBR_VALUE5(value) ((SYS_GPBR5_GPBR_VALUE5_Msk & ((value) << SYS_GPBR5_GPBR_VALUE5_Pos)))
/* -------- SYS_GPBR6 : (GPBR Offset: 0x18) General Purpose Backup Register 6 -------- */
#define SYS_GPBR6_GPBR_VALUE6_Pos 0
#define SYS_GPBR6_GPBR_VALUE6_Msk (0xffffffffu << SYS_GPBR6_GPBR_VALUE6_Pos) /**< \brief (SYS_GPBR6) Value of GPBR x */
#define SYS_GPBR6_GPBR_VALUE6(value) ((SYS_GPBR6_GPBR_VALUE6_Msk & ((value) << SYS_GPBR6_GPBR_VALUE6_Pos)))
/* -------- SYS_GPBR7 : (GPBR Offset: 0x1C) General Purpose Backup Register 7 -------- */
#define SYS_GPBR7_GPBR_VALUE7_Pos 0
#define SYS_GPBR7_GPBR_VALUE7_Msk (0xffffffffu << SYS_GPBR7_GPBR_VALUE7_Pos) /**< \brief (SYS_GPBR7) Value of GPBR x */
#define SYS_GPBR7_GPBR_VALUE7(value) ((SYS_GPBR7_GPBR_VALUE7_Msk & ((value) << SYS_GPBR7_GPBR_VALUE7_Pos)))

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR High Speed MultiMedia Card Interface */
/* ============================================================================= */
/** \addtogroup SAM3S16_HSMCI High Speed MultiMedia Card Interface */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Hsmci hardware registers */
typedef struct {
  WoReg HSMCI_CR;        /**< \brief (Hsmci Offset: 0x00) Control Register */
  RwReg HSMCI_MR;        /**< \brief (Hsmci Offset: 0x04) Mode Register */
  RwReg HSMCI_DTOR;      /**< \brief (Hsmci Offset: 0x08) Data Timeout Register */
  RwReg HSMCI_SDCR;      /**< \brief (Hsmci Offset: 0x0C) SD/SDIO Card Register */
  RwReg HSMCI_ARGR;      /**< \brief (Hsmci Offset: 0x10) Argument Register */
  WoReg HSMCI_CMDR;      /**< \brief (Hsmci Offset: 0x14) Command Register */
  RwReg HSMCI_BLKR;      /**< \brief (Hsmci Offset: 0x18) Block Register */
  RwReg HSMCI_CSTOR;     /**< \brief (Hsmci Offset: 0x1C) Completion Signal Timeout Register */
  RoReg HSMCI_RSPR[4];   /**< \brief (Hsmci Offset: 0x20) Response Register */
  RoReg HSMCI_RDR;       /**< \brief (Hsmci Offset: 0x30) Receive Data Register */
  WoReg HSMCI_TDR;       /**< \brief (Hsmci Offset: 0x34) Transmit Data Register */
  RoReg Reserved1[2];
  RoReg HSMCI_SR;        /**< \brief (Hsmci Offset: 0x40) Status Register */
  WoReg HSMCI_IER;       /**< \brief (Hsmci Offset: 0x44) Interrupt Enable Register */
  WoReg HSMCI_IDR;       /**< \brief (Hsmci Offset: 0x48) Interrupt Disable Register */
  RoReg HSMCI_IMR;       /**< \brief (Hsmci Offset: 0x4C) Interrupt Mask Register */
  RoReg Reserved2[1];
  RwReg HSMCI_CFG;       /**< \brief (Hsmci Offset: 0x54) Configuration Register */
  RoReg Reserved3[35];
  RwReg HSMCI_WPMR;      /**< \brief (Hsmci Offset: 0xE4) Write Protection Mode Register */
  RoReg HSMCI_WPSR;      /**< \brief (Hsmci Offset: 0xE8) Write Protection Status Register */
  RoReg Reserved4[5];
  RwReg HSMCI_RPR;       /**< \brief (Hsmci Offset: 0x100) Receive Pointer Register */
  RwReg HSMCI_RCR;       /**< \brief (Hsmci Offset: 0x104) Receive Counter Register */
  RwReg HSMCI_TPR;       /**< \brief (Hsmci Offset: 0x108) Transmit Pointer Register */
  RwReg HSMCI_TCR;       /**< \brief (Hsmci Offset: 0x10C) Transmit Counter Register */
  RwReg HSMCI_RNPR;      /**< \brief (Hsmci Offset: 0x110) Receive Next Pointer Register */
  RwReg HSMCI_RNCR;      /**< \brief (Hsmci Offset: 0x114) Receive Next Counter Register */
  RwReg HSMCI_TNPR;      /**< \brief (Hsmci Offset: 0x118) Transmit Next Pointer Register */
  RwReg HSMCI_TNCR;      /**< \brief (Hsmci Offset: 0x11C) Transmit Next Counter Register */
  WoReg HSMCI_PTCR;      /**< \brief (Hsmci Offset: 0x120) Transfer Control Register */
  RoReg HSMCI_PTSR;      /**< \brief (Hsmci Offset: 0x124) Transfer Status Register */
  RoReg Reserved5[54];
  RwReg HSMCI_FIFO[256]; /**< \brief (Hsmci Offset: 0x200) FIFO Memory Aperture0 */
} Hsmci;
#endif /* __ASSEMBLY__ */
/* -------- HSMCI_CR : (HSMCI Offset: 0x00) Control Register -------- */
#define HSMCI_CR_MCIEN (0x1u << 0) /**< \brief (HSMCI_CR) Multi-Media Interface Enable */
#define HSMCI_CR_MCIDIS (0x1u << 1) /**< \brief (HSMCI_CR) Multi-Media Interface Disable */
#define HSMCI_CR_PWSEN (0x1u << 2) /**< \brief (HSMCI_CR) Power Save Mode Enable */
#define HSMCI_CR_PWSDIS (0x1u << 3) /**< \brief (HSMCI_CR) Power Save Mode Disable */
#define HSMCI_CR_SWRST (0x1u << 7) /**< \brief (HSMCI_CR) Software Reset */
/* -------- HSMCI_MR : (HSMCI Offset: 0x04) Mode Register -------- */
#define HSMCI_MR_CLKDIV_Pos 0
#define HSMCI_MR_CLKDIV_Msk (0xffu << HSMCI_MR_CLKDIV_Pos) /**< \brief (HSMCI_MR) Clock Divider */
#define HSMCI_MR_CLKDIV(value) ((HSMCI_MR_CLKDIV_Msk & ((value) << HSMCI_MR_CLKDIV_Pos)))
#define HSMCI_MR_PWSDIV_Pos 8
#define HSMCI_MR_PWSDIV_Msk (0x7u << HSMCI_MR_PWSDIV_Pos) /**< \brief (HSMCI_MR) Power Saving Divider */
#define HSMCI_MR_PWSDIV(value) ((HSMCI_MR_PWSDIV_Msk & ((value) << HSMCI_MR_PWSDIV_Pos)))
#define HSMCI_MR_RDPROOF (0x1u << 11) /**< \brief (HSMCI_MR)  */
#define HSMCI_MR_WRPROOF (0x1u << 12) /**< \brief (HSMCI_MR)  */
#define HSMCI_MR_FBYTE (0x1u << 13) /**< \brief (HSMCI_MR) Force Byte Transfer */
#define HSMCI_MR_PADV (0x1u << 14) /**< \brief (HSMCI_MR) Padding Value */
#define HSMCI_MR_PDCMODE (0x1u << 15) /**< \brief (HSMCI_MR) PDC-oriented Mode */
#define HSMCI_MR_BLKLEN_Pos 16
#define HSMCI_MR_BLKLEN_Msk (0xffffu << HSMCI_MR_BLKLEN_Pos) /**< \brief (HSMCI_MR) Data Block Length */
#define HSMCI_MR_BLKLEN(value) ((HSMCI_MR_BLKLEN_Msk & ((value) << HSMCI_MR_BLKLEN_Pos)))
/* -------- HSMCI_DTOR : (HSMCI Offset: 0x08) Data Timeout Register -------- */
#define HSMCI_DTOR_DTOCYC_Pos 0
#define HSMCI_DTOR_DTOCYC_Msk (0xfu << HSMCI_DTOR_DTOCYC_Pos) /**< \brief (HSMCI_DTOR) Data Timeout Cycle Number */
#define HSMCI_DTOR_DTOCYC(value) ((HSMCI_DTOR_DTOCYC_Msk & ((value) << HSMCI_DTOR_DTOCYC_Pos)))
#define HSMCI_DTOR_DTOMUL_Pos 4
#define HSMCI_DTOR_DTOMUL_Msk (0x7u << HSMCI_DTOR_DTOMUL_Pos) /**< \brief (HSMCI_DTOR) Data Timeout Multiplier */
#define   HSMCI_DTOR_DTOMUL_1 (0x0u << 4) /**< \brief (HSMCI_DTOR) DTOCYC */
#define   HSMCI_DTOR_DTOMUL_16 (0x1u << 4) /**< \brief (HSMCI_DTOR) DTOCYC x 16 */
#define   HSMCI_DTOR_DTOMUL_128 (0x2u << 4) /**< \brief (HSMCI_DTOR) DTOCYC x 128 */
#define   HSMCI_DTOR_DTOMUL_256 (0x3u << 4) /**< \brief (HSMCI_DTOR) DTOCYC x 256 */
#define   HSMCI_DTOR_DTOMUL_1024 (0x4u << 4) /**< \brief (HSMCI_DTOR) DTOCYC x 1024 */
#define   HSMCI_DTOR_DTOMUL_4096 (0x5u << 4) /**< \brief (HSMCI_DTOR) DTOCYC x 4096 */
#define   HSMCI_DTOR_DTOMUL_65536 (0x6u << 4) /**< \brief (HSMCI_DTOR) DTOCYC x 65536 */
#define   HSMCI_DTOR_DTOMUL_1048576 (0x7u << 4) /**< \brief (HSMCI_DTOR) DTOCYC x 1048576 */
/* -------- HSMCI_SDCR : (HSMCI Offset: 0x0C) SD/SDIO Card Register -------- */
#define HSMCI_SDCR_SDCSEL_Pos 0
#define HSMCI_SDCR_SDCSEL_Msk (0x3u << HSMCI_SDCR_SDCSEL_Pos) /**< \brief (HSMCI_SDCR) SDCard/SDIO Slot */
#define   HSMCI_SDCR_SDCSEL_SLOTA (0x0u << 0) /**< \brief (HSMCI_SDCR) Slot A is selected. */
#define   HSMCI_SDCR_SDCSEL_SLOTB (0x1u << 0) /**< \brief (HSMCI_SDCR) - */
#define   HSMCI_SDCR_SDCSEL_SLOTC (0x2u << 0) /**< \brief (HSMCI_SDCR) - */
#define   HSMCI_SDCR_SDCSEL_SLOTD (0x3u << 0) /**< \brief (HSMCI_SDCR) - */
#define HSMCI_SDCR_SDCBUS_Pos 6
#define HSMCI_SDCR_SDCBUS_Msk (0x3u << HSMCI_SDCR_SDCBUS_Pos) /**< \brief (HSMCI_SDCR) SDCard/SDIO Bus Width */
#define   HSMCI_SDCR_SDCBUS_1 (0x0u << 6) /**< \brief (HSMCI_SDCR) 1 bit */
#define   HSMCI_SDCR_SDCBUS_4 (0x2u << 6) /**< \brief (HSMCI_SDCR) 4 bit */
#define   HSMCI_SDCR_SDCBUS_8 (0x3u << 6) /**< \brief (HSMCI_SDCR) 8 bit */
/* -------- HSMCI_ARGR : (HSMCI Offset: 0x10) Argument Register -------- */
#define HSMCI_ARGR_ARG_Pos 0
#define HSMCI_ARGR_ARG_Msk (0xffffffffu << HSMCI_ARGR_ARG_Pos) /**< \brief (HSMCI_ARGR) Command Argument */
#define HSMCI_ARGR_ARG(value) ((HSMCI_ARGR_ARG_Msk & ((value) << HSMCI_ARGR_ARG_Pos)))
/* -------- HSMCI_CMDR : (HSMCI Offset: 0x14) Command Register -------- */
#define HSMCI_CMDR_CMDNB_Pos 0
#define HSMCI_CMDR_CMDNB_Msk (0x3fu << HSMCI_CMDR_CMDNB_Pos) /**< \brief (HSMCI_CMDR) Command Number */
#define HSMCI_CMDR_CMDNB(value) ((HSMCI_CMDR_CMDNB_Msk & ((value) << HSMCI_CMDR_CMDNB_Pos)))
#define HSMCI_CMDR_RSPTYP_Pos 6
#define HSMCI_CMDR_RSPTYP_Msk (0x3u << HSMCI_CMDR_RSPTYP_Pos) /**< \brief (HSMCI_CMDR) Response Type */
#define   HSMCI_CMDR_RSPTYP_NORESP (0x0u << 6) /**< \brief (HSMCI_CMDR) No response. */
#define   HSMCI_CMDR_RSPTYP_48_BIT (0x1u << 6) /**< \brief (HSMCI_CMDR) 48-bit response. */
#define   HSMCI_CMDR_RSPTYP_136_BIT (0x2u << 6) /**< \brief (HSMCI_CMDR) 136-bit response. */
#define   HSMCI_CMDR_RSPTYP_R1B (0x3u << 6) /**< \brief (HSMCI_CMDR) R1b response type */
#define HSMCI_CMDR_SPCMD_Pos 8
#define HSMCI_CMDR_SPCMD_Msk (0x7u << HSMCI_CMDR_SPCMD_Pos) /**< \brief (HSMCI_CMDR) Special Command */
#define   HSMCI_CMDR_SPCMD_STD (0x0u << 8) /**< \brief (HSMCI_CMDR) Not a special CMD. */
#define   HSMCI_CMDR_SPCMD_INIT (0x1u << 8) /**< \brief (HSMCI_CMDR) Initialization CMD: 74 clock cycles for initialization sequence. */
#define   HSMCI_CMDR_SPCMD_SYNC (0x2u << 8) /**< \brief (HSMCI_CMDR) Synchronized CMD: Wait for the end of the current data block transfer before sending the pending command. */
#define   HSMCI_CMDR_SPCMD_CE_ATA (0x3u << 8) /**< \brief (HSMCI_CMDR) CE-ATA Completion Signal disable Command. The host cancels the ability for the device to return a command completion signal on the command line. */
#define   HSMCI_CMDR_SPCMD_IT_CMD (0x4u << 8) /**< \brief (HSMCI_CMDR) Interrupt command: Corresponds to the Interrupt Mode (CMD40). */
#define   HSMCI_CMDR_SPCMD_IT_RESP (0x5u << 8) /**< \brief (HSMCI_CMDR) Interrupt response: Corresponds to the Interrupt Mode (CMD40). */
#define   HSMCI_CMDR_SPCMD_BOR (0x6u << 8) /**< \brief (HSMCI_CMDR) Boot Operation Request. Start a boot operation mode, the host processor can read boot data from the MMC device directly. */
#define   HSMCI_CMDR_SPCMD_EBO (0x7u << 8) /**< \brief (HSMCI_CMDR) End Boot Operation. This command allows the host processor to terminate the boot operation mode. */
#define HSMCI_CMDR_OPDCMD (0x1u << 11) /**< \brief (HSMCI_CMDR) Open Drain Command */
#define   HSMCI_CMDR_OPDCMD_PUSHPULL (0x0u << 11) /**< \brief (HSMCI_CMDR) Push pull command. */
#define   HSMCI_CMDR_OPDCMD_OPENDRAIN (0x1u << 11) /**< \brief (HSMCI_CMDR) Open drain command. */
#define HSMCI_CMDR_MAXLAT (0x1u << 12) /**< \brief (HSMCI_CMDR) Max Latency for Command to Response */
#define   HSMCI_CMDR_MAXLAT_5 (0x0u << 12) /**< \brief (HSMCI_CMDR) 5-cycle max latency. */
#define   HSMCI_CMDR_MAXLAT_64 (0x1u << 12) /**< \brief (HSMCI_CMDR) 64-cycle max latency. */
#define HSMCI_CMDR_TRCMD_Pos 16
#define HSMCI_CMDR_TRCMD_Msk (0x3u << HSMCI_CMDR_TRCMD_Pos) /**< \brief (HSMCI_CMDR) Transfer Command */
#define   HSMCI_CMDR_TRCMD_NO_DATA (0x0u << 16) /**< \brief (HSMCI_CMDR) No data transfer */
#define   HSMCI_CMDR_TRCMD_START_DATA (0x1u << 16) /**< \brief (HSMCI_CMDR) Start data transfer */
#define   HSMCI_CMDR_TRCMD_STOP_DATA (0x2u << 16) /**< \brief (HSMCI_CMDR) Stop data transfer */
#define HSMCI_CMDR_TRDIR (0x1u << 18) /**< \brief (HSMCI_CMDR) Transfer Direction */
#define   HSMCI_CMDR_TRDIR_WRITE (0x0u << 18) /**< \brief (HSMCI_CMDR) Write. */
#define   HSMCI_CMDR_TRDIR_READ (0x1u << 18) /**< \brief (HSMCI_CMDR) Read. */
#define HSMCI_CMDR_TRTYP_Pos 19
#define HSMCI_CMDR_TRTYP_Msk (0x7u << HSMCI_CMDR_TRTYP_Pos) /**< \brief (HSMCI_CMDR) Transfer Type */
#define   HSMCI_CMDR_TRTYP_SINGLE (0x0u << 19) /**< \brief (HSMCI_CMDR) MMC/SDCard Single Block */
#define   HSMCI_CMDR_TRTYP_MULTIPLE (0x1u << 19) /**< \brief (HSMCI_CMDR) MMC/SDCard Multiple Block */
#define   HSMCI_CMDR_TRTYP_STREAM (0x2u << 19) /**< \brief (HSMCI_CMDR) MMC Stream */
#define   HSMCI_CMDR_TRTYP_BYTE (0x4u << 19) /**< \brief (HSMCI_CMDR) SDIO Byte */
#define   HSMCI_CMDR_TRTYP_BLOCK (0x5u << 19) /**< \brief (HSMCI_CMDR) SDIO Block */
#define HSMCI_CMDR_IOSPCMD_Pos 24
#define HSMCI_CMDR_IOSPCMD_Msk (0x3u << HSMCI_CMDR_IOSPCMD_Pos) /**< \brief (HSMCI_CMDR) SDIO Special Command */
#define   HSMCI_CMDR_IOSPCMD_STD (0x0u << 24) /**< \brief (HSMCI_CMDR) Not an SDIO Special Command */
#define   HSMCI_CMDR_IOSPCMD_SUSPEND (0x1u << 24) /**< \brief (HSMCI_CMDR) SDIO Suspend Command */
#define   HSMCI_CMDR_IOSPCMD_RESUME (0x2u << 24) /**< \brief (HSMCI_CMDR) SDIO Resume Command */
#define HSMCI_CMDR_ATACS (0x1u << 26) /**< \brief (HSMCI_CMDR) ATA with Command Completion Signal */
#define   HSMCI_CMDR_ATACS_NORMAL (0x0u << 26) /**< \brief (HSMCI_CMDR) Normal operation mode. */
#define   HSMCI_CMDR_ATACS_COMPLETION (0x1u << 26) /**< \brief (HSMCI_CMDR) This bit indicates that a completion signal is expected within a programmed amount of time (HSMCI_CSTOR). */
#define HSMCI_CMDR_BOOT_ACK (0x1u << 27) /**< \brief (HSMCI_CMDR) Boot Operation Acknowledge. */
/* -------- HSMCI_BLKR : (HSMCI Offset: 0x18) Block Register -------- */
#define HSMCI_BLKR_BCNT_Pos 0
#define HSMCI_BLKR_BCNT_Msk (0xffffu << HSMCI_BLKR_BCNT_Pos) /**< \brief (HSMCI_BLKR) MMC/SDIO Block Count - SDIO Byte Count */
#define   HSMCI_BLKR_BCNT_MULTIPLE (0x0u << 0) /**< \brief (HSMCI_BLKR) MMC/SDCARD Multiple BlockFrom 1 to 65635: Value 0 corresponds to an infinite block transfer. */
#define   HSMCI_BLKR_BCNT_BYTE (0x4u << 0) /**< \brief (HSMCI_BLKR) SDIO ByteFrom 1 to 512 bytes: Value 0 corresponds to a 512-byte transfer.Values from 0x200 to 0xFFFF are forbidden. */
#define   HSMCI_BLKR_BCNT_BLOCK (0x5u << 0) /**< \brief (HSMCI_BLKR) SDIO BlockFrom 1 to 511 blocks: Value 0 corresponds to an infinite block transfer.Values from 0x200 to 0xFFFF are forbidden. */
#define HSMCI_BLKR_BLKLEN_Pos 16
#define HSMCI_BLKR_BLKLEN_Msk (0xffffu << HSMCI_BLKR_BLKLEN_Pos) /**< \brief (HSMCI_BLKR) Data Block Length */
#define HSMCI_BLKR_BLKLEN(value) ((HSMCI_BLKR_BLKLEN_Msk & ((value) << HSMCI_BLKR_BLKLEN_Pos)))
/* -------- HSMCI_CSTOR : (HSMCI Offset: 0x1C) Completion Signal Timeout Register -------- */
#define HSMCI_CSTOR_CSTOCYC_Pos 0
#define HSMCI_CSTOR_CSTOCYC_Msk (0xfu << HSMCI_CSTOR_CSTOCYC_Pos) /**< \brief (HSMCI_CSTOR) Completion Signal Timeout Cycle Number */
#define HSMCI_CSTOR_CSTOCYC(value) ((HSMCI_CSTOR_CSTOCYC_Msk & ((value) << HSMCI_CSTOR_CSTOCYC_Pos)))
#define HSMCI_CSTOR_CSTOMUL_Pos 4
#define HSMCI_CSTOR_CSTOMUL_Msk (0x7u << HSMCI_CSTOR_CSTOMUL_Pos) /**< \brief (HSMCI_CSTOR) Completion Signal Timeout Multiplier */
#define   HSMCI_CSTOR_CSTOMUL_1 (0x0u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 1 */
#define   HSMCI_CSTOR_CSTOMUL_16 (0x1u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 16 */
#define   HSMCI_CSTOR_CSTOMUL_128 (0x2u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 128 */
#define   HSMCI_CSTOR_CSTOMUL_256 (0x3u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 256 */
#define   HSMCI_CSTOR_CSTOMUL_1024 (0x4u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 1024 */
#define   HSMCI_CSTOR_CSTOMUL_4096 (0x5u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 4096 */
#define   HSMCI_CSTOR_CSTOMUL_65536 (0x6u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 65536 */
#define   HSMCI_CSTOR_CSTOMUL_1048576 (0x7u << 4) /**< \brief (HSMCI_CSTOR) CSTOCYC x 1048576 */
/* -------- HSMCI_RSPR[4] : (HSMCI Offset: 0x20) Response Register -------- */
#define HSMCI_RSPR_RSP_Pos 0
#define HSMCI_RSPR_RSP_Msk (0xffffffffu << HSMCI_RSPR_RSP_Pos) /**< \brief (HSMCI_RSPR[4]) Response */
/* -------- HSMCI_RDR : (HSMCI Offset: 0x30) Receive Data Register -------- */
#define HSMCI_RDR_DATA_Pos 0
#define HSMCI_RDR_DATA_Msk (0xffffffffu << HSMCI_RDR_DATA_Pos) /**< \brief (HSMCI_RDR) Data to Read */
/* -------- HSMCI_TDR : (HSMCI Offset: 0x34) Transmit Data Register -------- */
#define HSMCI_TDR_DATA_Pos 0
#define HSMCI_TDR_DATA_Msk (0xffffffffu << HSMCI_TDR_DATA_Pos) /**< \brief (HSMCI_TDR) Data to Write */
#define HSMCI_TDR_DATA(value) ((HSMCI_TDR_DATA_Msk & ((value) << HSMCI_TDR_DATA_Pos)))
/* -------- HSMCI_SR : (HSMCI Offset: 0x40) Status Register -------- */
#define HSMCI_SR_CMDRDY (0x1u << 0) /**< \brief (HSMCI_SR) Command Ready */
#define HSMCI_SR_RXRDY (0x1u << 1) /**< \brief (HSMCI_SR) Receiver Ready */
#define HSMCI_SR_TXRDY (0x1u << 2) /**< \brief (HSMCI_SR) Transmit Ready */
#define HSMCI_SR_BLKE (0x1u << 3) /**< \brief (HSMCI_SR) Data Block Ended */
#define HSMCI_SR_DTIP (0x1u << 4) /**< \brief (HSMCI_SR) Data Transfer in Progress */
#define HSMCI_SR_NOTBUSY (0x1u << 5) /**< \brief (HSMCI_SR) HSMCI Not Busy */
#define HSMCI_SR_ENDRX (0x1u << 6) /**< \brief (HSMCI_SR) End of RX Buffer */
#define HSMCI_SR_ENDTX (0x1u << 7) /**< \brief (HSMCI_SR) End of TX Buffer */
#define HSMCI_SR_SDIOIRQA (0x1u << 8) /**< \brief (HSMCI_SR) SDIO Interrupt for Slot A */
#define HSMCI_SR_SDIOWAIT (0x1u << 12) /**< \brief (HSMCI_SR) SDIO Read Wait Operation Status */
#define HSMCI_SR_CSRCV (0x1u << 13) /**< \brief (HSMCI_SR) CE-ATA Completion Signal Received */
#define HSMCI_SR_RXBUFF (0x1u << 14) /**< \brief (HSMCI_SR) RX Buffer Full */
#define HSMCI_SR_TXBUFE (0x1u << 15) /**< \brief (HSMCI_SR) TX Buffer Empty */
#define HSMCI_SR_RINDE (0x1u << 16) /**< \brief (HSMCI_SR) Response Index Error */
#define HSMCI_SR_RDIRE (0x1u << 17) /**< \brief (HSMCI_SR) Response Direction Error */
#define HSMCI_SR_RCRCE (0x1u << 18) /**< \brief (HSMCI_SR) Response CRC Error */
#define HSMCI_SR_RENDE (0x1u << 19) /**< \brief (HSMCI_SR) Response End Bit Error */
#define HSMCI_SR_RTOE (0x1u << 20) /**< \brief (HSMCI_SR) Response Time-out Error */
#define HSMCI_SR_DCRCE (0x1u << 21) /**< \brief (HSMCI_SR) Data CRC Error */
#define HSMCI_SR_DTOE (0x1u << 22) /**< \brief (HSMCI_SR) Data Time-out Error */
#define HSMCI_SR_CSTOE (0x1u << 23) /**< \brief (HSMCI_SR) Completion Signal Time-out Error */
#define HSMCI_SR_FIFOEMPTY (0x1u << 26) /**< \brief (HSMCI_SR) FIFO empty flag */
#define HSMCI_SR_XFRDONE (0x1u << 27) /**< \brief (HSMCI_SR) Transfer Done flag */
#define HSMCI_SR_ACKRCV (0x1u << 28) /**< \brief (HSMCI_SR) Boot Operation Acknowledge Received */
#define HSMCI_SR_ACKRCVE (0x1u << 29) /**< \brief (HSMCI_SR) Boot Operation Acknowledge Error */
#define HSMCI_SR_OVRE (0x1u << 30) /**< \brief (HSMCI_SR) Overrun */
#define HSMCI_SR_UNRE (0x1u << 31) /**< \brief (HSMCI_SR) Underrun */
/* -------- HSMCI_IER : (HSMCI Offset: 0x44) Interrupt Enable Register -------- */
#define HSMCI_IER_CMDRDY (0x1u << 0) /**< \brief (HSMCI_IER) Command Ready Interrupt Enable */
#define HSMCI_IER_RXRDY (0x1u << 1) /**< \brief (HSMCI_IER) Receiver Ready Interrupt Enable */
#define HSMCI_IER_TXRDY (0x1u << 2) /**< \brief (HSMCI_IER) Transmit Ready Interrupt Enable */
#define HSMCI_IER_BLKE (0x1u << 3) /**< \brief (HSMCI_IER) Data Block Ended Interrupt Enable */
#define HSMCI_IER_DTIP (0x1u << 4) /**< \brief (HSMCI_IER) Data Transfer in Progress Interrupt Enable */
#define HSMCI_IER_NOTBUSY (0x1u << 5) /**< \brief (HSMCI_IER) Data Not Busy Interrupt Enable */
#define HSMCI_IER_ENDRX (0x1u << 6) /**< \brief (HSMCI_IER) End of Receive Buffer Interrupt Enable */
#define HSMCI_IER_ENDTX (0x1u << 7) /**< \brief (HSMCI_IER) End of Transmit Buffer Interrupt Enable */
#define HSMCI_IER_SDIOIRQA (0x1u << 8) /**< \brief (HSMCI_IER) SDIO Interrupt for Slot A Interrupt Enable */
#define HSMCI_IER_SDIOWAIT (0x1u << 12) /**< \brief (HSMCI_IER) SDIO Read Wait Operation Status Interrupt Enable */
#define HSMCI_IER_CSRCV (0x1u << 13) /**< \brief (HSMCI_IER) Completion Signal Received Interrupt Enable */
#define HSMCI_IER_RXBUFF (0x1u << 14) /**< \brief (HSMCI_IER) Receive Buffer Full Interrupt Enable */
#define HSMCI_IER_TXBUFE (0x1u << 15) /**< \brief (HSMCI_IER) Transmit Buffer Empty Interrupt Enable */
#define HSMCI_IER_RINDE (0x1u << 16) /**< \brief (HSMCI_IER) Response Index Error Interrupt Enable */
#define HSMCI_IER_RDIRE (0x1u << 17) /**< \brief (HSMCI_IER) Response Direction Error Interrupt Enable */
#define HSMCI_IER_RCRCE (0x1u << 18) /**< \brief (HSMCI_IER) Response CRC Error Interrupt Enable */
#define HSMCI_IER_RENDE (0x1u << 19) /**< \brief (HSMCI_IER) Response End Bit Error Interrupt Enable */
#define HSMCI_IER_RTOE (0x1u << 20) /**< \brief (HSMCI_IER) Response Time-out Error Interrupt Enable */
#define HSMCI_IER_DCRCE (0x1u << 21) /**< \brief (HSMCI_IER) Data CRC Error Interrupt Enable */
#define HSMCI_IER_DTOE (0x1u << 22) /**< \brief (HSMCI_IER) Data Time-out Error Interrupt Enable */
#define HSMCI_IER_CSTOE (0x1u << 23) /**< \brief (HSMCI_IER) Completion Signal Timeout Error Interrupt Enable */
#define HSMCI_IER_FIFOEMPTY (0x1u << 26) /**< \brief (HSMCI_IER) FIFO empty Interrupt enable */
#define HSMCI_IER_XFRDONE (0x1u << 27) /**< \brief (HSMCI_IER) Transfer Done Interrupt enable */
#define HSMCI_IER_ACKRCV (0x1u << 28) /**< \brief (HSMCI_IER) Boot Acknowledge Interrupt Enable */
#define HSMCI_IER_ACKRCVE (0x1u << 29) /**< \brief (HSMCI_IER) Boot Acknowledge Error Interrupt Enable */
#define HSMCI_IER_OVRE (0x1u << 30) /**< \brief (HSMCI_IER) Overrun Interrupt Enable */
#define HSMCI_IER_UNRE (0x1u << 31) /**< \brief (HSMCI_IER) Underrun Interrupt Enable */
/* -------- HSMCI_IDR : (HSMCI Offset: 0x48) Interrupt Disable Register -------- */
#define HSMCI_IDR_CMDRDY (0x1u << 0) /**< \brief (HSMCI_IDR) Command Ready Interrupt Disable */
#define HSMCI_IDR_RXRDY (0x1u << 1) /**< \brief (HSMCI_IDR) Receiver Ready Interrupt Disable */
#define HSMCI_IDR_TXRDY (0x1u << 2) /**< \brief (HSMCI_IDR) Transmit Ready Interrupt Disable */
#define HSMCI_IDR_BLKE (0x1u << 3) /**< \brief (HSMCI_IDR) Data Block Ended Interrupt Disable */
#define HSMCI_IDR_DTIP (0x1u << 4) /**< \brief (HSMCI_IDR) Data Transfer in Progress Interrupt Disable */
#define HSMCI_IDR_NOTBUSY (0x1u << 5) /**< \brief (HSMCI_IDR) Data Not Busy Interrupt Disable */
#define HSMCI_IDR_ENDRX (0x1u << 6) /**< \brief (HSMCI_IDR) End of Receive Buffer Interrupt Disable */
#define HSMCI_IDR_ENDTX (0x1u << 7) /**< \brief (HSMCI_IDR) End of Transmit Buffer Interrupt Disable */
#define HSMCI_IDR_SDIOIRQA (0x1u << 8) /**< \brief (HSMCI_IDR) SDIO Interrupt for Slot A Interrupt Disable */
#define HSMCI_IDR_SDIOWAIT (0x1u << 12) /**< \brief (HSMCI_IDR) SDIO Read Wait Operation Status Interrupt Disable */
#define HSMCI_IDR_CSRCV (0x1u << 13) /**< \brief (HSMCI_IDR) Completion Signal received interrupt Disable */
#define HSMCI_IDR_RXBUFF (0x1u << 14) /**< \brief (HSMCI_IDR) Receive Buffer Full Interrupt Disable */
#define HSMCI_IDR_TXBUFE (0x1u << 15) /**< \brief (HSMCI_IDR) Transmit Buffer Empty Interrupt Disable */
#define HSMCI_IDR_RINDE (0x1u << 16) /**< \brief (HSMCI_IDR) Response Index Error Interrupt Disable */
#define HSMCI_IDR_RDIRE (0x1u << 17) /**< \brief (HSMCI_IDR) Response Direction Error Interrupt Disable */
#define HSMCI_IDR_RCRCE (0x1u << 18) /**< \brief (HSMCI_IDR) Response CRC Error Interrupt Disable */
#define HSMCI_IDR_RENDE (0x1u << 19) /**< \brief (HSMCI_IDR) Response End Bit Error Interrupt Disable */
#define HSMCI_IDR_RTOE (0x1u << 20) /**< \brief (HSMCI_IDR) Response Time-out Error Interrupt Disable */
#define HSMCI_IDR_DCRCE (0x1u << 21) /**< \brief (HSMCI_IDR) Data CRC Error Interrupt Disable */
#define HSMCI_IDR_DTOE (0x1u << 22) /**< \brief (HSMCI_IDR) Data Time-out Error Interrupt Disable */
#define HSMCI_IDR_CSTOE (0x1u << 23) /**< \brief (HSMCI_IDR) Completion Signal Time out Error Interrupt Disable */
#define HSMCI_IDR_FIFOEMPTY (0x1u << 26) /**< \brief (HSMCI_IDR) FIFO empty Interrupt Disable */
#define HSMCI_IDR_XFRDONE (0x1u << 27) /**< \brief (HSMCI_IDR) Transfer Done Interrupt Disable */
#define HSMCI_IDR_ACKRCV (0x1u << 28) /**< \brief (HSMCI_IDR) Boot Acknowledge Interrupt Disable */
#define HSMCI_IDR_ACKRCVE (0x1u << 29) /**< \brief (HSMCI_IDR) Boot Acknowledge Error Interrupt Disable */
#define HSMCI_IDR_OVRE (0x1u << 30) /**< \brief (HSMCI_IDR) Overrun Interrupt Disable */
#define HSMCI_IDR_UNRE (0x1u << 31) /**< \brief (HSMCI_IDR) Underrun Interrupt Disable */
/* -------- HSMCI_IMR : (HSMCI Offset: 0x4C) Interrupt Mask Register -------- */
#define HSMCI_IMR_CMDRDY (0x1u << 0) /**< \brief (HSMCI_IMR) Command Ready Interrupt Mask */
#define HSMCI_IMR_RXRDY (0x1u << 1) /**< \brief (HSMCI_IMR) Receiver Ready Interrupt Mask */
#define HSMCI_IMR_TXRDY (0x1u << 2) /**< \brief (HSMCI_IMR) Transmit Ready Interrupt Mask */
#define HSMCI_IMR_BLKE (0x1u << 3) /**< \brief (HSMCI_IMR) Data Block Ended Interrupt Mask */
#define HSMCI_IMR_DTIP (0x1u << 4) /**< \brief (HSMCI_IMR) Data Transfer in Progress Interrupt Mask */
#define HSMCI_IMR_NOTBUSY (0x1u << 5) /**< \brief (HSMCI_IMR) Data Not Busy Interrupt Mask */
#define HSMCI_IMR_ENDRX (0x1u << 6) /**< \brief (HSMCI_IMR) End of Receive Buffer Interrupt Mask */
#define HSMCI_IMR_ENDTX (0x1u << 7) /**< \brief (HSMCI_IMR) End of Transmit Buffer Interrupt Mask */
#define HSMCI_IMR_SDIOIRQA (0x1u << 8) /**< \brief (HSMCI_IMR) SDIO Interrupt for Slot A Interrupt Mask */
#define HSMCI_IMR_SDIOWAIT (0x1u << 12) /**< \brief (HSMCI_IMR) SDIO Read Wait Operation Status Interrupt Mask */
#define HSMCI_IMR_CSRCV (0x1u << 13) /**< \brief (HSMCI_IMR) Completion Signal Received Interrupt Mask */
#define HSMCI_IMR_RXBUFF (0x1u << 14) /**< \brief (HSMCI_IMR) Receive Buffer Full Interrupt Mask */
#define HSMCI_IMR_TXBUFE (0x1u << 15) /**< \brief (HSMCI_IMR) Transmit Buffer Empty Interrupt Mask */
#define HSMCI_IMR_RINDE (0x1u << 16) /**< \brief (HSMCI_IMR) Response Index Error Interrupt Mask */
#define HSMCI_IMR_RDIRE (0x1u << 17) /**< \brief (HSMCI_IMR) Response Direction Error Interrupt Mask */
#define HSMCI_IMR_RCRCE (0x1u << 18) /**< \brief (HSMCI_IMR) Response CRC Error Interrupt Mask */
#define HSMCI_IMR_RENDE (0x1u << 19) /**< \brief (HSMCI_IMR) Response End Bit Error Interrupt Mask */
#define HSMCI_IMR_RTOE (0x1u << 20) /**< \brief (HSMCI_IMR) Response Time-out Error Interrupt Mask */
#define HSMCI_IMR_DCRCE (0x1u << 21) /**< \brief (HSMCI_IMR) Data CRC Error Interrupt Mask */
#define HSMCI_IMR_DTOE (0x1u << 22) /**< \brief (HSMCI_IMR) Data Time-out Error Interrupt Mask */
#define HSMCI_IMR_CSTOE (0x1u << 23) /**< \brief (HSMCI_IMR) Completion Signal Time-out Error Interrupt Mask */
#define HSMCI_IMR_FIFOEMPTY (0x1u << 26) /**< \brief (HSMCI_IMR) FIFO Empty Interrupt Mask */
#define HSMCI_IMR_XFRDONE (0x1u << 27) /**< \brief (HSMCI_IMR) Transfer Done Interrupt Mask */
#define HSMCI_IMR_ACKRCV (0x1u << 28) /**< \brief (HSMCI_IMR) Boot Operation Acknowledge Received Interrupt Mask */
#define HSMCI_IMR_ACKRCVE (0x1u << 29) /**< \brief (HSMCI_IMR) Boot Operation Acknowledge Error Interrupt Mask */
#define HSMCI_IMR_OVRE (0x1u << 30) /**< \brief (HSMCI_IMR) Overrun Interrupt Mask */
#define HSMCI_IMR_UNRE (0x1u << 31) /**< \brief (HSMCI_IMR) Underrun Interrupt Mask */
/* -------- HSMCI_CFG : (HSMCI Offset: 0x54) Configuration Register -------- */
#define HSMCI_CFG_FIFOMODE (0x1u << 0) /**< \brief (HSMCI_CFG) HSMCI Internal FIFO control mode */
#define HSMCI_CFG_FERRCTRL (0x1u << 4) /**< \brief (HSMCI_CFG) Flow Error flag reset control mode */
#define HSMCI_CFG_HSMODE (0x1u << 8) /**< \brief (HSMCI_CFG) High Speed Mode */
#define HSMCI_CFG_LSYNC (0x1u << 12) /**< \brief (HSMCI_CFG) Synchronize on the last block */
/* -------- HSMCI_WPMR : (HSMCI Offset: 0xE4) Write Protection Mode Register -------- */
#define HSMCI_WPMR_WP_EN (0x1u << 0) /**< \brief (HSMCI_WPMR) Write Protection Enable */
#define HSMCI_WPMR_WP_KEY_Pos 8
#define HSMCI_WPMR_WP_KEY_Msk (0xffffffu << HSMCI_WPMR_WP_KEY_Pos) /**< \brief (HSMCI_WPMR) Write Protection Key password */
#define HSMCI_WPMR_WP_KEY(value) ((HSMCI_WPMR_WP_KEY_Msk & ((value) << HSMCI_WPMR_WP_KEY_Pos)))
/* -------- HSMCI_WPSR : (HSMCI Offset: 0xE8) Write Protection Status Register -------- */
#define HSMCI_WPSR_WP_VS_Pos 0
#define HSMCI_WPSR_WP_VS_Msk (0xfu << HSMCI_WPSR_WP_VS_Pos) /**< \brief (HSMCI_WPSR) Write Protection Violation Status */
#define   HSMCI_WPSR_WP_VS_NONE (0x0u << 0) /**< \brief (HSMCI_WPSR) No Write Protection Violation occurred since the last read of this register (WP_SR) */
#define   HSMCI_WPSR_WP_VS_WRITE (0x1u << 0) /**< \brief (HSMCI_WPSR) Write Protection detected unauthorized attempt to write a control register had occurred (since the last read.) */
#define   HSMCI_WPSR_WP_VS_RESET (0x2u << 0) /**< \brief (HSMCI_WPSR) Software reset had been performed while Write Protection was enabled (since the last read). */
#define   HSMCI_WPSR_WP_VS_BOTH (0x3u << 0) /**< \brief (HSMCI_WPSR) Both Write Protection violation and software reset with Write Protection enabled have occurred since the last read. */
#define HSMCI_WPSR_WP_VSRC_Pos 8
#define HSMCI_WPSR_WP_VSRC_Msk (0xffffu << HSMCI_WPSR_WP_VSRC_Pos) /**< \brief (HSMCI_WPSR) Write Protection Violation SouRCe */
/* -------- HSMCI_RPR : (HSMCI Offset: 0x100) Receive Pointer Register -------- */
#define HSMCI_RPR_RXPTR_Pos 0
#define HSMCI_RPR_RXPTR_Msk (0xffffffffu << HSMCI_RPR_RXPTR_Pos) /**< \brief (HSMCI_RPR) Receive Pointer Register */
#define HSMCI_RPR_RXPTR(value) ((HSMCI_RPR_RXPTR_Msk & ((value) << HSMCI_RPR_RXPTR_Pos)))
/* -------- HSMCI_RCR : (HSMCI Offset: 0x104) Receive Counter Register -------- */
#define HSMCI_RCR_RXCTR_Pos 0
#define HSMCI_RCR_RXCTR_Msk (0xffffu << HSMCI_RCR_RXCTR_Pos) /**< \brief (HSMCI_RCR) Receive Counter Register */
#define HSMCI_RCR_RXCTR(value) ((HSMCI_RCR_RXCTR_Msk & ((value) << HSMCI_RCR_RXCTR_Pos)))
/* -------- HSMCI_TPR : (HSMCI Offset: 0x108) Transmit Pointer Register -------- */
#define HSMCI_TPR_TXPTR_Pos 0
#define HSMCI_TPR_TXPTR_Msk (0xffffffffu << HSMCI_TPR_TXPTR_Pos) /**< \brief (HSMCI_TPR) Transmit Counter Register */
#define HSMCI_TPR_TXPTR(value) ((HSMCI_TPR_TXPTR_Msk & ((value) << HSMCI_TPR_TXPTR_Pos)))
/* -------- HSMCI_TCR : (HSMCI Offset: 0x10C) Transmit Counter Register -------- */
#define HSMCI_TCR_TXCTR_Pos 0
#define HSMCI_TCR_TXCTR_Msk (0xffffu << HSMCI_TCR_TXCTR_Pos) /**< \brief (HSMCI_TCR) Transmit Counter Register */
#define HSMCI_TCR_TXCTR(value) ((HSMCI_TCR_TXCTR_Msk & ((value) << HSMCI_TCR_TXCTR_Pos)))
/* -------- HSMCI_RNPR : (HSMCI Offset: 0x110) Receive Next Pointer Register -------- */
#define HSMCI_RNPR_RXNPTR_Pos 0
#define HSMCI_RNPR_RXNPTR_Msk (0xffffffffu << HSMCI_RNPR_RXNPTR_Pos) /**< \brief (HSMCI_RNPR) Receive Next Pointer */
#define HSMCI_RNPR_RXNPTR(value) ((HSMCI_RNPR_RXNPTR_Msk & ((value) << HSMCI_RNPR_RXNPTR_Pos)))
/* -------- HSMCI_RNCR : (HSMCI Offset: 0x114) Receive Next Counter Register -------- */
#define HSMCI_RNCR_RXNCTR_Pos 0
#define HSMCI_RNCR_RXNCTR_Msk (0xffffu << HSMCI_RNCR_RXNCTR_Pos) /**< \brief (HSMCI_RNCR) Receive Next Counter */
#define HSMCI_RNCR_RXNCTR(value) ((HSMCI_RNCR_RXNCTR_Msk & ((value) << HSMCI_RNCR_RXNCTR_Pos)))
/* -------- HSMCI_TNPR : (HSMCI Offset: 0x118) Transmit Next Pointer Register -------- */
#define HSMCI_TNPR_TXNPTR_Pos 0
#define HSMCI_TNPR_TXNPTR_Msk (0xffffffffu << HSMCI_TNPR_TXNPTR_Pos) /**< \brief (HSMCI_TNPR) Transmit Next Pointer */
#define HSMCI_TNPR_TXNPTR(value) ((HSMCI_TNPR_TXNPTR_Msk & ((value) << HSMCI_TNPR_TXNPTR_Pos)))
/* -------- HSMCI_TNCR : (HSMCI Offset: 0x11C) Transmit Next Counter Register -------- */
#define HSMCI_TNCR_TXNCTR_Pos 0
#define HSMCI_TNCR_TXNCTR_Msk (0xffffu << HSMCI_TNCR_TXNCTR_Pos) /**< \brief (HSMCI_TNCR) Transmit Counter Next */
#define HSMCI_TNCR_TXNCTR(value) ((HSMCI_TNCR_TXNCTR_Msk & ((value) << HSMCI_TNCR_TXNCTR_Pos)))
/* -------- HSMCI_PTCR : (HSMCI Offset: 0x120) Transfer Control Register -------- */
#define HSMCI_PTCR_RXTEN (0x1u << 0) /**< \brief (HSMCI_PTCR) Receiver Transfer Enable */
#define HSMCI_PTCR_RXTDIS (0x1u << 1) /**< \brief (HSMCI_PTCR) Receiver Transfer Disable */
#define HSMCI_PTCR_TXTEN (0x1u << 8) /**< \brief (HSMCI_PTCR) Transmitter Transfer Enable */
#define HSMCI_PTCR_TXTDIS (0x1u << 9) /**< \brief (HSMCI_PTCR) Transmitter Transfer Disable */
/* -------- HSMCI_PTSR : (HSMCI Offset: 0x124) Transfer Status Register -------- */
#define HSMCI_PTSR_RXTEN (0x1u << 0) /**< \brief (HSMCI_PTSR) Receiver Transfer Enable */
#define HSMCI_PTSR_TXTEN (0x1u << 8) /**< \brief (HSMCI_PTSR) Transmitter Transfer Enable */
/* -------- HSMCI_FIFO[256] : (HSMCI Offset: 0x200) FIFO Memory Aperture0 -------- */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR AHB Bus Matrix */
/* ============================================================================= */
/** \addtogroup SAM3S16_MATRIX AHB Bus Matrix */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Matrix hardware registers */
typedef struct {
  RwReg MATRIX_MCFG[4]; /**< \brief (Matrix Offset: 0x0000) Master Configuration Register */
  RoReg Reserved1[12];
  RwReg MATRIX_SCFG[5]; /**< \brief (Matrix Offset: 0x0040) Slave Configuration Register */
  RoReg Reserved2[11];
  RwReg MATRIX_PRAS0;   /**< \brief (Matrix Offset: 0x0080) Priority Register A for Slave 0 */
  RoReg Reserved3[1];
  RwReg MATRIX_PRAS1;   /**< \brief (Matrix Offset: 0x0088) Priority Register A for Slave 1 */
  RoReg Reserved4[1];
  RwReg MATRIX_PRAS2;   /**< \brief (Matrix Offset: 0x0090) Priority Register A for Slave 2 */
  RoReg Reserved5[1];
  RwReg MATRIX_PRAS3;   /**< \brief (Matrix Offset: 0x0098) Priority Register A for Slave 3 */
  RoReg Reserved6[1];
  RwReg MATRIX_PRAS4;   /**< \brief (Matrix Offset: 0x00A0) Priority Register A for Slave 4 */
  RoReg Reserved7[1];
  RoReg Reserved8[27];
  RwReg CCFG_SYSIO;     /**< \brief (Matrix Offset: 0x0114) System I/O Configuration register */
  RoReg Reserved9[1];
  RwReg CCFG_SMCNFCS;   /**< \brief (Matrix Offset: 0x011C) SMC Chip Select NAND Flash Assignment Register */
  RoReg Reserved10[49];
  RwReg MATRIX_WPMR;    /**< \brief (Matrix Offset: 0x1E4) Write Protect Mode Register */
  RoReg MATRIX_WPSR;    /**< \brief (Matrix Offset: 0x1E8) Write Protect Status Register */
} Matrix;
#endif /* __ASSEMBLY__ */
/* -------- MATRIX_MCFG[4] : (MATRIX Offset: 0x0000) Master Configuration Register -------- */
#define MATRIX_MCFG_ULBT_Pos 0
#define MATRIX_MCFG_ULBT_Msk (0x7u << MATRIX_MCFG_ULBT_Pos) /**< \brief (MATRIX_MCFG[4]) Undefined Length Burst Type */
#define MATRIX_MCFG_ULBT(value) ((MATRIX_MCFG_ULBT_Msk & ((value) << MATRIX_MCFG_ULBT_Pos)))
/* -------- MATRIX_SCFG[5] : (MATRIX Offset: 0x0040) Slave Configuration Register -------- */
#define MATRIX_SCFG_SLOT_CYCLE_Pos 0
#define MATRIX_SCFG_SLOT_CYCLE_Msk (0xffu << MATRIX_SCFG_SLOT_CYCLE_Pos) /**< \brief (MATRIX_SCFG[5]) Maximum Number of Allowed Cycles for a Burst */
#define MATRIX_SCFG_SLOT_CYCLE(value) ((MATRIX_SCFG_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG_SLOT_CYCLE_Pos)))
#define MATRIX_SCFG_DEFMSTR_TYPE_Pos 16
#define MATRIX_SCFG_DEFMSTR_TYPE_Msk (0x3u << MATRIX_SCFG_DEFMSTR_TYPE_Pos) /**< \brief (MATRIX_SCFG[5]) Default Master Type */
#define MATRIX_SCFG_DEFMSTR_TYPE(value) ((MATRIX_SCFG_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG_DEFMSTR_TYPE_Pos)))
#define MATRIX_SCFG_FIXED_DEFMSTR_Pos 18
#define MATRIX_SCFG_FIXED_DEFMSTR_Msk (0x7u << MATRIX_SCFG_FIXED_DEFMSTR_Pos) /**< \brief (MATRIX_SCFG[5]) Fixed Default Master */
#define MATRIX_SCFG_FIXED_DEFMSTR(value) ((MATRIX_SCFG_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG_FIXED_DEFMSTR_Pos)))
#define MATRIX_SCFG_ARBT_Pos 24
#define MATRIX_SCFG_ARBT_Msk (0x3u << MATRIX_SCFG_ARBT_Pos) /**< \brief (MATRIX_SCFG[5]) Arbitration Type */
#define MATRIX_SCFG_ARBT(value) ((MATRIX_SCFG_ARBT_Msk & ((value) << MATRIX_SCFG_ARBT_Pos)))
/* -------- MATRIX_PRAS0 : (MATRIX Offset: 0x0080) Priority Register A for Slave 0 -------- */
#define MATRIX_PRAS0_M0PR_Pos 0
#define MATRIX_PRAS0_M0PR_Msk (0x3u << MATRIX_PRAS0_M0PR_Pos) /**< \brief (MATRIX_PRAS0) Master 0 Priority */
#define MATRIX_PRAS0_M0PR(value) ((MATRIX_PRAS0_M0PR_Msk & ((value) << MATRIX_PRAS0_M0PR_Pos)))
#define MATRIX_PRAS0_M1PR_Pos 4
#define MATRIX_PRAS0_M1PR_Msk (0x3u << MATRIX_PRAS0_M1PR_Pos) /**< \brief (MATRIX_PRAS0) Master 1 Priority */
#define MATRIX_PRAS0_M1PR(value) ((MATRIX_PRAS0_M1PR_Msk & ((value) << MATRIX_PRAS0_M1PR_Pos)))
#define MATRIX_PRAS0_M2PR_Pos 8
#define MATRIX_PRAS0_M2PR_Msk (0x3u << MATRIX_PRAS0_M2PR_Pos) /**< \brief (MATRIX_PRAS0) Master 2 Priority */
#define MATRIX_PRAS0_M2PR(value) ((MATRIX_PRAS0_M2PR_Msk & ((value) << MATRIX_PRAS0_M2PR_Pos)))
#define MATRIX_PRAS0_M3PR_Pos 12
#define MATRIX_PRAS0_M3PR_Msk (0x3u << MATRIX_PRAS0_M3PR_Pos) /**< \brief (MATRIX_PRAS0) Master 3 Priority */
#define MATRIX_PRAS0_M3PR(value) ((MATRIX_PRAS0_M3PR_Msk & ((value) << MATRIX_PRAS0_M3PR_Pos)))
#define MATRIX_PRAS0_M4PR_Pos 16
#define MATRIX_PRAS0_M4PR_Msk (0x3u << MATRIX_PRAS0_M4PR_Pos) /**< \brief (MATRIX_PRAS0) Master 4 Priority */
#define MATRIX_PRAS0_M4PR(value) ((MATRIX_PRAS0_M4PR_Msk & ((value) << MATRIX_PRAS0_M4PR_Pos)))
/* -------- MATRIX_PRAS1 : (MATRIX Offset: 0x0088) Priority Register A for Slave 1 -------- */
#define MATRIX_PRAS1_M0PR_Pos 0
#define MATRIX_PRAS1_M0PR_Msk (0x3u << MATRIX_PRAS1_M0PR_Pos) /**< \brief (MATRIX_PRAS1) Master 0 Priority */
#define MATRIX_PRAS1_M0PR(value) ((MATRIX_PRAS1_M0PR_Msk & ((value) << MATRIX_PRAS1_M0PR_Pos)))
#define MATRIX_PRAS1_M1PR_Pos 4
#define MATRIX_PRAS1_M1PR_Msk (0x3u << MATRIX_PRAS1_M1PR_Pos) /**< \brief (MATRIX_PRAS1) Master 1 Priority */
#define MATRIX_PRAS1_M1PR(value) ((MATRIX_PRAS1_M1PR_Msk & ((value) << MATRIX_PRAS1_M1PR_Pos)))
#define MATRIX_PRAS1_M2PR_Pos 8
#define MATRIX_PRAS1_M2PR_Msk (0x3u << MATRIX_PRAS1_M2PR_Pos) /**< \brief (MATRIX_PRAS1) Master 2 Priority */
#define MATRIX_PRAS1_M2PR(value) ((MATRIX_PRAS1_M2PR_Msk & ((value) << MATRIX_PRAS1_M2PR_Pos)))
#define MATRIX_PRAS1_M3PR_Pos 12
#define MATRIX_PRAS1_M3PR_Msk (0x3u << MATRIX_PRAS1_M3PR_Pos) /**< \brief (MATRIX_PRAS1) Master 3 Priority */
#define MATRIX_PRAS1_M3PR(value) ((MATRIX_PRAS1_M3PR_Msk & ((value) << MATRIX_PRAS1_M3PR_Pos)))
#define MATRIX_PRAS1_M4PR_Pos 16
#define MATRIX_PRAS1_M4PR_Msk (0x3u << MATRIX_PRAS1_M4PR_Pos) /**< \brief (MATRIX_PRAS1) Master 4 Priority */
#define MATRIX_PRAS1_M4PR(value) ((MATRIX_PRAS1_M4PR_Msk & ((value) << MATRIX_PRAS1_M4PR_Pos)))
/* -------- MATRIX_PRAS2 : (MATRIX Offset: 0x0090) Priority Register A for Slave 2 -------- */
#define MATRIX_PRAS2_M0PR_Pos 0
#define MATRIX_PRAS2_M0PR_Msk (0x3u << MATRIX_PRAS2_M0PR_Pos) /**< \brief (MATRIX_PRAS2) Master 0 Priority */
#define MATRIX_PRAS2_M0PR(value) ((MATRIX_PRAS2_M0PR_Msk & ((value) << MATRIX_PRAS2_M0PR_Pos)))
#define MATRIX_PRAS2_M1PR_Pos 4
#define MATRIX_PRAS2_M1PR_Msk (0x3u << MATRIX_PRAS2_M1PR_Pos) /**< \brief (MATRIX_PRAS2) Master 1 Priority */
#define MATRIX_PRAS2_M1PR(value) ((MATRIX_PRAS2_M1PR_Msk & ((value) << MATRIX_PRAS2_M1PR_Pos)))
#define MATRIX_PRAS2_M2PR_Pos 8
#define MATRIX_PRAS2_M2PR_Msk (0x3u << MATRIX_PRAS2_M2PR_Pos) /**< \brief (MATRIX_PRAS2) Master 2 Priority */
#define MATRIX_PRAS2_M2PR(value) ((MATRIX_PRAS2_M2PR_Msk & ((value) << MATRIX_PRAS2_M2PR_Pos)))
#define MATRIX_PRAS2_M3PR_Pos 12
#define MATRIX_PRAS2_M3PR_Msk (0x3u << MATRIX_PRAS2_M3PR_Pos) /**< \brief (MATRIX_PRAS2) Master 3 Priority */
#define MATRIX_PRAS2_M3PR(value) ((MATRIX_PRAS2_M3PR_Msk & ((value) << MATRIX_PRAS2_M3PR_Pos)))
#define MATRIX_PRAS2_M4PR_Pos 16
#define MATRIX_PRAS2_M4PR_Msk (0x3u << MATRIX_PRAS2_M4PR_Pos) /**< \brief (MATRIX_PRAS2) Master 4 Priority */
#define MATRIX_PRAS2_M4PR(value) ((MATRIX_PRAS2_M4PR_Msk & ((value) << MATRIX_PRAS2_M4PR_Pos)))
/* -------- MATRIX_PRAS3 : (MATRIX Offset: 0x0098) Priority Register A for Slave 3 -------- */
#define MATRIX_PRAS3_M0PR_Pos 0
#define MATRIX_PRAS3_M0PR_Msk (0x3u << MATRIX_PRAS3_M0PR_Pos) /**< \brief (MATRIX_PRAS3) Master 0 Priority */
#define MATRIX_PRAS3_M0PR(value) ((MATRIX_PRAS3_M0PR_Msk & ((value) << MATRIX_PRAS3_M0PR_Pos)))
#define MATRIX_PRAS3_M1PR_Pos 4
#define MATRIX_PRAS3_M1PR_Msk (0x3u << MATRIX_PRAS3_M1PR_Pos) /**< \brief (MATRIX_PRAS3) Master 1 Priority */
#define MATRIX_PRAS3_M1PR(value) ((MATRIX_PRAS3_M1PR_Msk & ((value) << MATRIX_PRAS3_M1PR_Pos)))
#define MATRIX_PRAS3_M2PR_Pos 8
#define MATRIX_PRAS3_M2PR_Msk (0x3u << MATRIX_PRAS3_M2PR_Pos) /**< \brief (MATRIX_PRAS3) Master 2 Priority */
#define MATRIX_PRAS3_M2PR(value) ((MATRIX_PRAS3_M2PR_Msk & ((value) << MATRIX_PRAS3_M2PR_Pos)))
#define MATRIX_PRAS3_M3PR_Pos 12
#define MATRIX_PRAS3_M3PR_Msk (0x3u << MATRIX_PRAS3_M3PR_Pos) /**< \brief (MATRIX_PRAS3) Master 3 Priority */
#define MATRIX_PRAS3_M3PR(value) ((MATRIX_PRAS3_M3PR_Msk & ((value) << MATRIX_PRAS3_M3PR_Pos)))
#define MATRIX_PRAS3_M4PR_Pos 16
#define MATRIX_PRAS3_M4PR_Msk (0x3u << MATRIX_PRAS3_M4PR_Pos) /**< \brief (MATRIX_PRAS3) Master 4 Priority */
#define MATRIX_PRAS3_M4PR(value) ((MATRIX_PRAS3_M4PR_Msk & ((value) << MATRIX_PRAS3_M4PR_Pos)))
/* -------- MATRIX_PRAS4 : (MATRIX Offset: 0x00A0) Priority Register A for Slave 4 -------- */
#define MATRIX_PRAS4_M0PR_Pos 0
#define MATRIX_PRAS4_M0PR_Msk (0x3u << MATRIX_PRAS4_M0PR_Pos) /**< \brief (MATRIX_PRAS4) Master 0 Priority */
#define MATRIX_PRAS4_M0PR(value) ((MATRIX_PRAS4_M0PR_Msk & ((value) << MATRIX_PRAS4_M0PR_Pos)))
#define MATRIX_PRAS4_M1PR_Pos 4
#define MATRIX_PRAS4_M1PR_Msk (0x3u << MATRIX_PRAS4_M1PR_Pos) /**< \brief (MATRIX_PRAS4) Master 1 Priority */
#define MATRIX_PRAS4_M1PR(value) ((MATRIX_PRAS4_M1PR_Msk & ((value) << MATRIX_PRAS4_M1PR_Pos)))
#define MATRIX_PRAS4_M2PR_Pos 8
#define MATRIX_PRAS4_M2PR_Msk (0x3u << MATRIX_PRAS4_M2PR_Pos) /**< \brief (MATRIX_PRAS4) Master 2 Priority */
#define MATRIX_PRAS4_M2PR(value) ((MATRIX_PRAS4_M2PR_Msk & ((value) << MATRIX_PRAS4_M2PR_Pos)))
#define MATRIX_PRAS4_M3PR_Pos 12
#define MATRIX_PRAS4_M3PR_Msk (0x3u << MATRIX_PRAS4_M3PR_Pos) /**< \brief (MATRIX_PRAS4) Master 3 Priority */
#define MATRIX_PRAS4_M3PR(value) ((MATRIX_PRAS4_M3PR_Msk & ((value) << MATRIX_PRAS4_M3PR_Pos)))
#define MATRIX_PRAS4_M4PR_Pos 16
#define MATRIX_PRAS4_M4PR_Msk (0x3u << MATRIX_PRAS4_M4PR_Pos) /**< \brief (MATRIX_PRAS4) Master 4 Priority */
#define MATRIX_PRAS4_M4PR(value) ((MATRIX_PRAS4_M4PR_Msk & ((value) << MATRIX_PRAS4_M4PR_Pos)))
/* -------- CCFG_SYSIO : (MATRIX Offset: 0x0114) System I/O Configuration register -------- */
#define CCFG_SYSIO_SYSIO4 (0x1u << 4) /**< \brief (CCFG_SYSIO) PB4 or TDI Assignment */
#define CCFG_SYSIO_SYSIO5 (0x1u << 5) /**< \brief (CCFG_SYSIO) PB5 or TDO/TRACESWO Assignment */
#define CCFG_SYSIO_SYSIO6 (0x1u << 6) /**< \brief (CCFG_SYSIO) PB6 or TMS/SWDIO Assignment */
#define CCFG_SYSIO_SYSIO7 (0x1u << 7) /**< \brief (CCFG_SYSIO) PB7 or TCK/SWCLK Assignment */
#define CCFG_SYSIO_SYSIO10 (0x1u << 10) /**< \brief (CCFG_SYSIO) PB10 or DDM Assignment */
#define CCFG_SYSIO_SYSIO11 (0x1u << 11) /**< \brief (CCFG_SYSIO) PB11 or DDP Assignment */
#define CCFG_SYSIO_SYSIO12 (0x1u << 12) /**< \brief (CCFG_SYSIO) PB12 or ERASE Assignment */
/* -------- CCFG_SMCNFCS : (MATRIX Offset: 0x011C) SMC Chip Select NAND Flash Assignment Register -------- */
#define CCFG_SMCNFCS_SMC_NFCS0 (0x1u << 0) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 0 Assignment */
#define CCFG_SMCNFCS_SMC_NFCS1 (0x1u << 1) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 1 Assignment */
#define CCFG_SMCNFCS_SMC_NFCS2 (0x1u << 2) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 2 Assignment */
#define CCFG_SMCNFCS_SMC_NFCS3 (0x1u << 3) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 3 Assignment */
/* -------- MATRIX_WPMR : (MATRIX Offset: 0x1E4) Write Protect Mode Register -------- */
#define MATRIX_WPMR_WPEN (0x1u << 0) /**< \brief (MATRIX_WPMR) Write Protect ENable */
#define MATRIX_WPMR_WPKEY_Pos 8
#define MATRIX_WPMR_WPKEY_Msk (0xffffffu << MATRIX_WPMR_WPKEY_Pos) /**< \brief (MATRIX_WPMR) Write Protect KEY (Write-only) */
#define MATRIX_WPMR_WPKEY(value) ((MATRIX_WPMR_WPKEY_Msk & ((value) << MATRIX_WPMR_WPKEY_Pos)))
/* -------- MATRIX_WPSR : (MATRIX Offset: 0x1E8) Write Protect Status Register -------- */
#define MATRIX_WPSR_WPVS (0x1u << 0) /**< \brief (MATRIX_WPSR) Write Protect Violation Status */
#define MATRIX_WPSR_WPVSRC_Pos 8
#define MATRIX_WPSR_WPVSRC_Msk (0xffffu << MATRIX_WPSR_WPVSRC_Pos) /**< \brief (MATRIX_WPSR) Write Protect Violation Source */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Peripheral DMA Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_PDC Peripheral DMA Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Pdc hardware registers */
typedef struct {
  RoReg Reserved1[64];
  RwReg PERIPH_RPR;    /**< \brief (Pdc Offset: 0x100) Receive Pointer Register */
  RwReg PERIPH_RCR;    /**< \brief (Pdc Offset: 0x104) Receive Counter Register */
  RwReg PERIPH_TPR;    /**< \brief (Pdc Offset: 0x108) Transmit Pointer Register */
  RwReg PERIPH_TCR;    /**< \brief (Pdc Offset: 0x10C) Transmit Counter Register */
  RwReg PERIPH_RNPR;   /**< \brief (Pdc Offset: 0x110) Receive Next Pointer Register */
  RwReg PERIPH_RNCR;   /**< \brief (Pdc Offset: 0x114) Receive Next Counter Register */
  RwReg PERIPH_TNPR;   /**< \brief (Pdc Offset: 0x118) Transmit Next Pointer Register */
  RwReg PERIPH_TNCR;   /**< \brief (Pdc Offset: 0x11C) Transmit Next Counter Register */
  WoReg PERIPH_PTCR;   /**< \brief (Pdc Offset: 0x120) Transfer Control Register */
  RoReg PERIPH_PTSR;   /**< \brief (Pdc Offset: 0x124) Transfer Status Register */
} Pdc;
#endif /* __ASSEMBLY__ */
/* -------- PERIPH_RPR : (PDC Offset: 0x100) Receive Pointer Register -------- */
#define PERIPH_RPR_RXPTR_Pos 0
#define PERIPH_RPR_RXPTR_Msk (0xffffffffu << PERIPH_RPR_RXPTR_Pos) /**< \brief (PERIPH_RPR) Receive Pointer Register */
#define PERIPH_RPR_RXPTR(value) ((PERIPH_RPR_RXPTR_Msk & ((value) << PERIPH_RPR_RXPTR_Pos)))
/* -------- PERIPH_RCR : (PDC Offset: 0x104) Receive Counter Register -------- */
#define PERIPH_RCR_RXCTR_Pos 0
#define PERIPH_RCR_RXCTR_Msk (0xffffu << PERIPH_RCR_RXCTR_Pos) /**< \brief (PERIPH_RCR) Receive Counter Register */
#define PERIPH_RCR_RXCTR(value) ((PERIPH_RCR_RXCTR_Msk & ((value) << PERIPH_RCR_RXCTR_Pos)))
/* -------- PERIPH_TPR : (PDC Offset: 0x108) Transmit Pointer Register -------- */
#define PERIPH_TPR_TXPTR_Pos 0
#define PERIPH_TPR_TXPTR_Msk (0xffffffffu << PERIPH_TPR_TXPTR_Pos) /**< \brief (PERIPH_TPR) Transmit Counter Register */
#define PERIPH_TPR_TXPTR(value) ((PERIPH_TPR_TXPTR_Msk & ((value) << PERIPH_TPR_TXPTR_Pos)))
/* -------- PERIPH_TCR : (PDC Offset: 0x10C) Transmit Counter Register -------- */
#define PERIPH_TCR_TXCTR_Pos 0
#define PERIPH_TCR_TXCTR_Msk (0xffffu << PERIPH_TCR_TXCTR_Pos) /**< \brief (PERIPH_TCR) Transmit Counter Register */
#define PERIPH_TCR_TXCTR(value) ((PERIPH_TCR_TXCTR_Msk & ((value) << PERIPH_TCR_TXCTR_Pos)))
/* -------- PERIPH_RNPR : (PDC Offset: 0x110) Receive Next Pointer Register -------- */
#define PERIPH_RNPR_RXNPTR_Pos 0
#define PERIPH_RNPR_RXNPTR_Msk (0xffffffffu << PERIPH_RNPR_RXNPTR_Pos) /**< \brief (PERIPH_RNPR) Receive Next Pointer */
#define PERIPH_RNPR_RXNPTR(value) ((PERIPH_RNPR_RXNPTR_Msk & ((value) << PERIPH_RNPR_RXNPTR_Pos)))
/* -------- PERIPH_RNCR : (PDC Offset: 0x114) Receive Next Counter Register -------- */
#define PERIPH_RNCR_RXNCTR_Pos 0
#define PERIPH_RNCR_RXNCTR_Msk (0xffffu << PERIPH_RNCR_RXNCTR_Pos) /**< \brief (PERIPH_RNCR) Receive Next Counter */
#define PERIPH_RNCR_RXNCTR(value) ((PERIPH_RNCR_RXNCTR_Msk & ((value) << PERIPH_RNCR_RXNCTR_Pos)))
/* -------- PERIPH_TNPR : (PDC Offset: 0x118) Transmit Next Pointer Register -------- */
#define PERIPH_TNPR_TXNPTR_Pos 0
#define PERIPH_TNPR_TXNPTR_Msk (0xffffffffu << PERIPH_TNPR_TXNPTR_Pos) /**< \brief (PERIPH_TNPR) Transmit Next Pointer */
#define PERIPH_TNPR_TXNPTR(value) ((PERIPH_TNPR_TXNPTR_Msk & ((value) << PERIPH_TNPR_TXNPTR_Pos)))
/* -------- PERIPH_TNCR : (PDC Offset: 0x11C) Transmit Next Counter Register -------- */
#define PERIPH_TNCR_TXNCTR_Pos 0
#define PERIPH_TNCR_TXNCTR_Msk (0xffffu << PERIPH_TNCR_TXNCTR_Pos) /**< \brief (PERIPH_TNCR) Transmit Counter Next */
#define PERIPH_TNCR_TXNCTR(value) ((PERIPH_TNCR_TXNCTR_Msk & ((value) << PERIPH_TNCR_TXNCTR_Pos)))
/* -------- PERIPH_PTCR : (PDC Offset: 0x120) Transfer Control Register -------- */
#define PERIPH_PTCR_RXTEN (0x1u << 0) /**< \brief (PERIPH_PTCR) Receiver Transfer Enable */
#define PERIPH_PTCR_RXTDIS (0x1u << 1) /**< \brief (PERIPH_PTCR) Receiver Transfer Disable */
#define PERIPH_PTCR_TXTEN (0x1u << 8) /**< \brief (PERIPH_PTCR) Transmitter Transfer Enable */
#define PERIPH_PTCR_TXTDIS (0x1u << 9) /**< \brief (PERIPH_PTCR) Transmitter Transfer Disable */
/* -------- PERIPH_PTSR : (PDC Offset: 0x124) Transfer Status Register -------- */
#define PERIPH_PTSR_RXTEN (0x1u << 0) /**< \brief (PERIPH_PTSR) Receiver Transfer Enable */
#define PERIPH_PTSR_TXTEN (0x1u << 8) /**< \brief (PERIPH_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Parallel Input/Output Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_PIO Parallel Input/Output Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Pio hardware registers */
typedef struct {
  WoReg PIO_PER;        /**< \brief (Pio Offset: 0x0000) PIO Enable Register */
  WoReg PIO_PDR;        /**< \brief (Pio Offset: 0x0004) PIO Disable Register */
  RoReg PIO_PSR;        /**< \brief (Pio Offset: 0x0008) PIO Status Register */
  RoReg Reserved1[1];
  WoReg PIO_OER;        /**< \brief (Pio Offset: 0x0010) Output Enable Register */
  WoReg PIO_ODR;        /**< \brief (Pio Offset: 0x0014) Output Disable Register */
  RoReg PIO_OSR;        /**< \brief (Pio Offset: 0x0018) Output Status Register */
  RoReg Reserved2[1];
  WoReg PIO_IFER;       /**< \brief (Pio Offset: 0x0020) Glitch Input Filter Enable Register */
  WoReg PIO_IFDR;       /**< \brief (Pio Offset: 0x0024) Glitch Input Filter Disable Register */
  RoReg PIO_IFSR;       /**< \brief (Pio Offset: 0x0028) Glitch Input Filter Status Register */
  RoReg Reserved3[1];
  WoReg PIO_SODR;       /**< \brief (Pio Offset: 0x0030) Set Output Data Register */
  WoReg PIO_CODR;       /**< \brief (Pio Offset: 0x0034) Clear Output Data Register */
  RwReg PIO_ODSR;       /**< \brief (Pio Offset: 0x0038) Output Data Status Register */
  RoReg PIO_PDSR;       /**< \brief (Pio Offset: 0x003C) Pin Data Status Register */
  WoReg PIO_IER;        /**< \brief (Pio Offset: 0x0040) Interrupt Enable Register */
  WoReg PIO_IDR;        /**< \brief (Pio Offset: 0x0044) Interrupt Disable Register */
  RoReg PIO_IMR;        /**< \brief (Pio Offset: 0x0048) Interrupt Mask Register */
  RoReg PIO_ISR;        /**< \brief (Pio Offset: 0x004C) Interrupt Status Register */
  WoReg PIO_MDER;       /**< \brief (Pio Offset: 0x0050) Multi-driver Enable Register */
  WoReg PIO_MDDR;       /**< \brief (Pio Offset: 0x0054) Multi-driver Disable Register */
  RoReg PIO_MDSR;       /**< \brief (Pio Offset: 0x0058) Multi-driver Status Register */
  RoReg Reserved4[1];
  WoReg PIO_PUDR;       /**< \brief (Pio Offset: 0x0060) Pull-up Disable Register */
  WoReg PIO_PUER;       /**< \brief (Pio Offset: 0x0064) Pull-up Enable Register */
  RoReg PIO_PUSR;       /**< \brief (Pio Offset: 0x0068) Pad Pull-up Status Register */
  RoReg Reserved5[1];
  RwReg PIO_ABCDSR[2];  /**< \brief (Pio Offset: 0x0070) Peripheral Select Register */
  RoReg Reserved6[2];
  WoReg PIO_IFSCDR;     /**< \brief (Pio Offset: 0x0080) Input Filter Slow Clock Disable Register */
  WoReg PIO_IFSCER;     /**< \brief (Pio Offset: 0x0084) Input Filter Slow Clock Enable Register */
  RoReg PIO_IFSCSR;     /**< \brief (Pio Offset: 0x0088) Input Filter Slow Clock Status Register */
  RwReg PIO_SCDR;       /**< \brief (Pio Offset: 0x008C) Slow Clock Divider Debouncing Register */
  WoReg PIO_PPDDR;      /**< \brief (Pio Offset: 0x0090) Pad Pull-down Disable Register */
  WoReg PIO_PPDER;      /**< \brief (Pio Offset: 0x0094) Pad Pull-down Enable Register */
  RoReg PIO_PPDSR;      /**< \brief (Pio Offset: 0x0098) Pad Pull-down Status Register */
  RoReg Reserved7[1];
  WoReg PIO_OWER;       /**< \brief (Pio Offset: 0x00A0) Output Write Enable */
  WoReg PIO_OWDR;       /**< \brief (Pio Offset: 0x00A4) Output Write Disable */
  RoReg PIO_OWSR;       /**< \brief (Pio Offset: 0x00A8) Output Write Status Register */
  RoReg Reserved8[1];
  WoReg PIO_AIMER;      /**< \brief (Pio Offset: 0x00B0) Additional Interrupt Modes Enable Register */
  WoReg PIO_AIMDR;      /**< \brief (Pio Offset: 0x00B4) Additional Interrupt Modes Disables Register */
  RoReg PIO_AIMMR;      /**< \brief (Pio Offset: 0x00B8) Additional Interrupt Modes Mask Register */
  RoReg Reserved9[1];
  WoReg PIO_ESR;        /**< \brief (Pio Offset: 0x00C0) Edge Select Register */
  WoReg PIO_LSR;        /**< \brief (Pio Offset: 0x00C4) Level Select Register */
  RoReg PIO_ELSR;       /**< \brief (Pio Offset: 0x00C8) Edge/Level Status Register */
  RoReg Reserved10[1];
  WoReg PIO_FELLSR;     /**< \brief (Pio Offset: 0x00D0) Falling Edge/Low Level Select Register */
  WoReg PIO_REHLSR;     /**< \brief (Pio Offset: 0x00D4) Rising Edge/ High Level Select Register */
  RoReg PIO_FRLHSR;     /**< \brief (Pio Offset: 0x00D8) Fall/Rise - Low/High Status Register */
  RoReg Reserved11[1];
  RoReg PIO_LOCKSR;     /**< \brief (Pio Offset: 0x00E0) Lock Status */
  RwReg PIO_WPMR;       /**< \brief (Pio Offset: 0x00E4) Write Protect Mode Register */
  RoReg PIO_WPSR;       /**< \brief (Pio Offset: 0x00E8) Write Protect Status Register */
  RoReg Reserved12[5];
  RwReg PIO_SCHMITT;    /**< \brief (Pio Offset: 0x0100) Schmitt Trigger Register */
  RoReg Reserved13[19];
  RwReg PIO_PCMR;       /**< \brief (Pio Offset: 0x150) Parallel Capture Mode Register */
  WoReg PIO_PCIER;      /**< \brief (Pio Offset: 0x154) Parallel Capture Interrupt Enable Register */
  WoReg PIO_PCIDR;      /**< \brief (Pio Offset: 0x158) Parallel Capture Interrupt Disable Register */
  RoReg PIO_PCIMR;      /**< \brief (Pio Offset: 0x15C) Parallel Capture Interrupt Mask Register */
  RoReg PIO_PCISR;      /**< \brief (Pio Offset: 0x160) Parallel Capture Interrupt Status Register */
  RoReg PIO_PCRHR;      /**< \brief (Pio Offset: 0x164) Parallel Capture Reception Holding Register */
  RwReg PIO_RPR;        /**< \brief (Pio Offset: 0x168) Receive Pointer Register */
  RwReg PIO_RCR;        /**< \brief (Pio Offset: 0x16C) Receive Counter Register */
  RwReg PIO_TPR;        /**< \brief (Pio Offset: 0x170) Transmit Pointer Register */
  RwReg PIO_TCR;        /**< \brief (Pio Offset: 0x174) Transmit Counter Register */
  RwReg PIO_RNPR;       /**< \brief (Pio Offset: 0x178) Receive Next Pointer Register */
  RwReg PIO_RNCR;       /**< \brief (Pio Offset: 0x17C) Receive Next Counter Register */
  RwReg PIO_TNPR;       /**< \brief (Pio Offset: 0x180) Transmit Next Pointer Register */
  RwReg PIO_TNCR;       /**< \brief (Pio Offset: 0x184) Transmit Next Counter Register */
  WoReg PIO_PTCR;       /**< \brief (Pio Offset: 0x188) Transfer Control Register */
  RoReg PIO_PTSR;       /**< \brief (Pio Offset: 0x18C) Transfer Status Register */
} Pio;
#endif /* __ASSEMBLY__ */
/* -------- PIO_PER : (PIO Offset: 0x0000) PIO Enable Register -------- */
#define PIO_PER_P0 (0x1u << 0) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P1 (0x1u << 1) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P2 (0x1u << 2) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P3 (0x1u << 3) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P4 (0x1u << 4) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P5 (0x1u << 5) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P6 (0x1u << 6) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P7 (0x1u << 7) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P8 (0x1u << 8) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P9 (0x1u << 9) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P10 (0x1u << 10) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P11 (0x1u << 11) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P12 (0x1u << 12) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P13 (0x1u << 13) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P14 (0x1u << 14) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P15 (0x1u << 15) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P16 (0x1u << 16) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P17 (0x1u << 17) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P18 (0x1u << 18) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P19 (0x1u << 19) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P20 (0x1u << 20) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P21 (0x1u << 21) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P22 (0x1u << 22) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P23 (0x1u << 23) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P24 (0x1u << 24) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P25 (0x1u << 25) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P26 (0x1u << 26) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P27 (0x1u << 27) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P28 (0x1u << 28) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P29 (0x1u << 29) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P30 (0x1u << 30) /**< \brief (PIO_PER) PIO Enable */
#define PIO_PER_P31 (0x1u << 31) /**< \brief (PIO_PER) PIO Enable */
/* -------- PIO_PDR : (PIO Offset: 0x0004) PIO Disable Register -------- */
#define PIO_PDR_P0 (0x1u << 0) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P1 (0x1u << 1) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P2 (0x1u << 2) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P3 (0x1u << 3) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P4 (0x1u << 4) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P5 (0x1u << 5) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P6 (0x1u << 6) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P7 (0x1u << 7) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P8 (0x1u << 8) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P9 (0x1u << 9) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P10 (0x1u << 10) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P11 (0x1u << 11) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P12 (0x1u << 12) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P13 (0x1u << 13) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P14 (0x1u << 14) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P15 (0x1u << 15) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P16 (0x1u << 16) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P17 (0x1u << 17) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P18 (0x1u << 18) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P19 (0x1u << 19) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P20 (0x1u << 20) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P21 (0x1u << 21) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P22 (0x1u << 22) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P23 (0x1u << 23) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P24 (0x1u << 24) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P25 (0x1u << 25) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P26 (0x1u << 26) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P27 (0x1u << 27) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P28 (0x1u << 28) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P29 (0x1u << 29) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P30 (0x1u << 30) /**< \brief (PIO_PDR) PIO Disable */
#define PIO_PDR_P31 (0x1u << 31) /**< \brief (PIO_PDR) PIO Disable */
/* -------- PIO_PSR : (PIO Offset: 0x0008) PIO Status Register -------- */
#define PIO_PSR_P0 (0x1u << 0) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P1 (0x1u << 1) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P2 (0x1u << 2) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P3 (0x1u << 3) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P4 (0x1u << 4) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P5 (0x1u << 5) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P6 (0x1u << 6) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P7 (0x1u << 7) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P8 (0x1u << 8) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P9 (0x1u << 9) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P10 (0x1u << 10) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P11 (0x1u << 11) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P12 (0x1u << 12) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P13 (0x1u << 13) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P14 (0x1u << 14) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P15 (0x1u << 15) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P16 (0x1u << 16) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P17 (0x1u << 17) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P18 (0x1u << 18) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P19 (0x1u << 19) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P20 (0x1u << 20) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P21 (0x1u << 21) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P22 (0x1u << 22) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P23 (0x1u << 23) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P24 (0x1u << 24) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P25 (0x1u << 25) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P26 (0x1u << 26) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P27 (0x1u << 27) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P28 (0x1u << 28) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P29 (0x1u << 29) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P30 (0x1u << 30) /**< \brief (PIO_PSR) PIO Status */
#define PIO_PSR_P31 (0x1u << 31) /**< \brief (PIO_PSR) PIO Status */
/* -------- PIO_OER : (PIO Offset: 0x0010) Output Enable Register -------- */
#define PIO_OER_P0 (0x1u << 0) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P1 (0x1u << 1) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P2 (0x1u << 2) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P3 (0x1u << 3) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P4 (0x1u << 4) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P5 (0x1u << 5) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P6 (0x1u << 6) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P7 (0x1u << 7) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P8 (0x1u << 8) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P9 (0x1u << 9) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P10 (0x1u << 10) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P11 (0x1u << 11) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P12 (0x1u << 12) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P13 (0x1u << 13) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P14 (0x1u << 14) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P15 (0x1u << 15) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P16 (0x1u << 16) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P17 (0x1u << 17) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P18 (0x1u << 18) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P19 (0x1u << 19) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P20 (0x1u << 20) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P21 (0x1u << 21) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P22 (0x1u << 22) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P23 (0x1u << 23) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P24 (0x1u << 24) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P25 (0x1u << 25) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P26 (0x1u << 26) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P27 (0x1u << 27) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P28 (0x1u << 28) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P29 (0x1u << 29) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P30 (0x1u << 30) /**< \brief (PIO_OER) Output Enable */
#define PIO_OER_P31 (0x1u << 31) /**< \brief (PIO_OER) Output Enable */
/* -------- PIO_ODR : (PIO Offset: 0x0014) Output Disable Register -------- */
#define PIO_ODR_P0 (0x1u << 0) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P1 (0x1u << 1) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P2 (0x1u << 2) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P3 (0x1u << 3) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P4 (0x1u << 4) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P5 (0x1u << 5) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P6 (0x1u << 6) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P7 (0x1u << 7) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P8 (0x1u << 8) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P9 (0x1u << 9) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P10 (0x1u << 10) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P11 (0x1u << 11) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P12 (0x1u << 12) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P13 (0x1u << 13) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P14 (0x1u << 14) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P15 (0x1u << 15) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P16 (0x1u << 16) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P17 (0x1u << 17) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P18 (0x1u << 18) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P19 (0x1u << 19) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P20 (0x1u << 20) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P21 (0x1u << 21) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P22 (0x1u << 22) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P23 (0x1u << 23) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P24 (0x1u << 24) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P25 (0x1u << 25) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P26 (0x1u << 26) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P27 (0x1u << 27) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P28 (0x1u << 28) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P29 (0x1u << 29) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P30 (0x1u << 30) /**< \brief (PIO_ODR) Output Disable */
#define PIO_ODR_P31 (0x1u << 31) /**< \brief (PIO_ODR) Output Disable */
/* -------- PIO_OSR : (PIO Offset: 0x0018) Output Status Register -------- */
#define PIO_OSR_P0 (0x1u << 0) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P1 (0x1u << 1) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P2 (0x1u << 2) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P3 (0x1u << 3) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P4 (0x1u << 4) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P5 (0x1u << 5) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P6 (0x1u << 6) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P7 (0x1u << 7) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P8 (0x1u << 8) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P9 (0x1u << 9) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P10 (0x1u << 10) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P11 (0x1u << 11) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P12 (0x1u << 12) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P13 (0x1u << 13) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P14 (0x1u << 14) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P15 (0x1u << 15) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P16 (0x1u << 16) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P17 (0x1u << 17) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P18 (0x1u << 18) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P19 (0x1u << 19) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P20 (0x1u << 20) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P21 (0x1u << 21) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P22 (0x1u << 22) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P23 (0x1u << 23) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P24 (0x1u << 24) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P25 (0x1u << 25) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P26 (0x1u << 26) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P27 (0x1u << 27) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P28 (0x1u << 28) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P29 (0x1u << 29) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P30 (0x1u << 30) /**< \brief (PIO_OSR) Output Status */
#define PIO_OSR_P31 (0x1u << 31) /**< \brief (PIO_OSR) Output Status */
/* -------- PIO_IFER : (PIO Offset: 0x0020) Glitch Input Filter Enable Register -------- */
#define PIO_IFER_P0 (0x1u << 0) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P1 (0x1u << 1) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P2 (0x1u << 2) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P3 (0x1u << 3) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P4 (0x1u << 4) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P5 (0x1u << 5) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P6 (0x1u << 6) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P7 (0x1u << 7) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P8 (0x1u << 8) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P9 (0x1u << 9) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P10 (0x1u << 10) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P11 (0x1u << 11) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P12 (0x1u << 12) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P13 (0x1u << 13) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P14 (0x1u << 14) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P15 (0x1u << 15) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P16 (0x1u << 16) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P17 (0x1u << 17) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P18 (0x1u << 18) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P19 (0x1u << 19) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P20 (0x1u << 20) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P21 (0x1u << 21) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P22 (0x1u << 22) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P23 (0x1u << 23) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P24 (0x1u << 24) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P25 (0x1u << 25) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P26 (0x1u << 26) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P27 (0x1u << 27) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P28 (0x1u << 28) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P29 (0x1u << 29) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P30 (0x1u << 30) /**< \brief (PIO_IFER) Input Filter Enable */
#define PIO_IFER_P31 (0x1u << 31) /**< \brief (PIO_IFER) Input Filter Enable */
/* -------- PIO_IFDR : (PIO Offset: 0x0024) Glitch Input Filter Disable Register -------- */
#define PIO_IFDR_P0 (0x1u << 0) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P1 (0x1u << 1) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P2 (0x1u << 2) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P3 (0x1u << 3) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P4 (0x1u << 4) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P5 (0x1u << 5) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P6 (0x1u << 6) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P7 (0x1u << 7) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P8 (0x1u << 8) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P9 (0x1u << 9) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P10 (0x1u << 10) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P11 (0x1u << 11) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P12 (0x1u << 12) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P13 (0x1u << 13) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P14 (0x1u << 14) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P15 (0x1u << 15) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P16 (0x1u << 16) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P17 (0x1u << 17) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P18 (0x1u << 18) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P19 (0x1u << 19) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P20 (0x1u << 20) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P21 (0x1u << 21) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P22 (0x1u << 22) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P23 (0x1u << 23) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P24 (0x1u << 24) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P25 (0x1u << 25) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P26 (0x1u << 26) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P27 (0x1u << 27) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P28 (0x1u << 28) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P29 (0x1u << 29) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P30 (0x1u << 30) /**< \brief (PIO_IFDR) Input Filter Disable */
#define PIO_IFDR_P31 (0x1u << 31) /**< \brief (PIO_IFDR) Input Filter Disable */
/* -------- PIO_IFSR : (PIO Offset: 0x0028) Glitch Input Filter Status Register -------- */
#define PIO_IFSR_P0 (0x1u << 0) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P1 (0x1u << 1) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P2 (0x1u << 2) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P3 (0x1u << 3) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P4 (0x1u << 4) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P5 (0x1u << 5) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P6 (0x1u << 6) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P7 (0x1u << 7) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P8 (0x1u << 8) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P9 (0x1u << 9) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P10 (0x1u << 10) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P11 (0x1u << 11) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P12 (0x1u << 12) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P13 (0x1u << 13) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P14 (0x1u << 14) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P15 (0x1u << 15) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P16 (0x1u << 16) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P17 (0x1u << 17) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P18 (0x1u << 18) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P19 (0x1u << 19) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P20 (0x1u << 20) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P21 (0x1u << 21) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P22 (0x1u << 22) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P23 (0x1u << 23) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P24 (0x1u << 24) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P25 (0x1u << 25) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P26 (0x1u << 26) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P27 (0x1u << 27) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P28 (0x1u << 28) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P29 (0x1u << 29) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P30 (0x1u << 30) /**< \brief (PIO_IFSR) Input Filer Status */
#define PIO_IFSR_P31 (0x1u << 31) /**< \brief (PIO_IFSR) Input Filer Status */
/* -------- PIO_SODR : (PIO Offset: 0x0030) Set Output Data Register -------- */
#define PIO_SODR_P0 (0x1u << 0) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P1 (0x1u << 1) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P2 (0x1u << 2) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P3 (0x1u << 3) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P4 (0x1u << 4) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P5 (0x1u << 5) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P6 (0x1u << 6) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P7 (0x1u << 7) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P8 (0x1u << 8) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P9 (0x1u << 9) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P10 (0x1u << 10) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P11 (0x1u << 11) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P12 (0x1u << 12) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P13 (0x1u << 13) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P14 (0x1u << 14) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P15 (0x1u << 15) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P16 (0x1u << 16) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P17 (0x1u << 17) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P18 (0x1u << 18) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P19 (0x1u << 19) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P20 (0x1u << 20) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P21 (0x1u << 21) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P22 (0x1u << 22) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P23 (0x1u << 23) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P24 (0x1u << 24) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P25 (0x1u << 25) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P26 (0x1u << 26) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P27 (0x1u << 27) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P28 (0x1u << 28) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P29 (0x1u << 29) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P30 (0x1u << 30) /**< \brief (PIO_SODR) Set Output Data */
#define PIO_SODR_P31 (0x1u << 31) /**< \brief (PIO_SODR) Set Output Data */
/* -------- PIO_CODR : (PIO Offset: 0x0034) Clear Output Data Register -------- */
#define PIO_CODR_P0 (0x1u << 0) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P1 (0x1u << 1) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P2 (0x1u << 2) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P3 (0x1u << 3) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P4 (0x1u << 4) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P5 (0x1u << 5) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P6 (0x1u << 6) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P7 (0x1u << 7) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P8 (0x1u << 8) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P9 (0x1u << 9) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P10 (0x1u << 10) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P11 (0x1u << 11) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P12 (0x1u << 12) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P13 (0x1u << 13) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P14 (0x1u << 14) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P15 (0x1u << 15) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P16 (0x1u << 16) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P17 (0x1u << 17) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P18 (0x1u << 18) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P19 (0x1u << 19) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P20 (0x1u << 20) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P21 (0x1u << 21) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P22 (0x1u << 22) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P23 (0x1u << 23) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P24 (0x1u << 24) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P25 (0x1u << 25) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P26 (0x1u << 26) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P27 (0x1u << 27) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P28 (0x1u << 28) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P29 (0x1u << 29) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P30 (0x1u << 30) /**< \brief (PIO_CODR) Clear Output Data */
#define PIO_CODR_P31 (0x1u << 31) /**< \brief (PIO_CODR) Clear Output Data */
/* -------- PIO_ODSR : (PIO Offset: 0x0038) Output Data Status Register -------- */
#define PIO_ODSR_P0 (0x1u << 0) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P1 (0x1u << 1) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P2 (0x1u << 2) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P3 (0x1u << 3) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P4 (0x1u << 4) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P5 (0x1u << 5) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P6 (0x1u << 6) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P7 (0x1u << 7) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P8 (0x1u << 8) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P9 (0x1u << 9) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P10 (0x1u << 10) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P11 (0x1u << 11) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P12 (0x1u << 12) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P13 (0x1u << 13) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P14 (0x1u << 14) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P15 (0x1u << 15) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P16 (0x1u << 16) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P17 (0x1u << 17) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P18 (0x1u << 18) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P19 (0x1u << 19) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P20 (0x1u << 20) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P21 (0x1u << 21) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P22 (0x1u << 22) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P23 (0x1u << 23) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P24 (0x1u << 24) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P25 (0x1u << 25) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P26 (0x1u << 26) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P27 (0x1u << 27) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P28 (0x1u << 28) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P29 (0x1u << 29) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P30 (0x1u << 30) /**< \brief (PIO_ODSR) Output Data Status */
#define PIO_ODSR_P31 (0x1u << 31) /**< \brief (PIO_ODSR) Output Data Status */
/* -------- PIO_PDSR : (PIO Offset: 0x003C) Pin Data Status Register -------- */
#define PIO_PDSR_P0 (0x1u << 0) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P1 (0x1u << 1) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P2 (0x1u << 2) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P3 (0x1u << 3) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P4 (0x1u << 4) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P5 (0x1u << 5) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P6 (0x1u << 6) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P7 (0x1u << 7) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P8 (0x1u << 8) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P9 (0x1u << 9) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P10 (0x1u << 10) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P11 (0x1u << 11) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P12 (0x1u << 12) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P13 (0x1u << 13) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P14 (0x1u << 14) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P15 (0x1u << 15) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P16 (0x1u << 16) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P17 (0x1u << 17) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P18 (0x1u << 18) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P19 (0x1u << 19) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P20 (0x1u << 20) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P21 (0x1u << 21) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P22 (0x1u << 22) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P23 (0x1u << 23) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P24 (0x1u << 24) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P25 (0x1u << 25) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P26 (0x1u << 26) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P27 (0x1u << 27) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P28 (0x1u << 28) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P29 (0x1u << 29) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P30 (0x1u << 30) /**< \brief (PIO_PDSR) Output Data Status */
#define PIO_PDSR_P31 (0x1u << 31) /**< \brief (PIO_PDSR) Output Data Status */
/* -------- PIO_IER : (PIO Offset: 0x0040) Interrupt Enable Register -------- */
#define PIO_IER_P0 (0x1u << 0) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P1 (0x1u << 1) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P2 (0x1u << 2) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P3 (0x1u << 3) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P4 (0x1u << 4) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P5 (0x1u << 5) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P6 (0x1u << 6) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P7 (0x1u << 7) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P8 (0x1u << 8) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P9 (0x1u << 9) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P10 (0x1u << 10) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P11 (0x1u << 11) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P12 (0x1u << 12) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P13 (0x1u << 13) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P14 (0x1u << 14) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P15 (0x1u << 15) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P16 (0x1u << 16) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P17 (0x1u << 17) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P18 (0x1u << 18) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P19 (0x1u << 19) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P20 (0x1u << 20) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P21 (0x1u << 21) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P22 (0x1u << 22) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P23 (0x1u << 23) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P24 (0x1u << 24) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P25 (0x1u << 25) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P26 (0x1u << 26) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P27 (0x1u << 27) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P28 (0x1u << 28) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P29 (0x1u << 29) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P30 (0x1u << 30) /**< \brief (PIO_IER) Input Change Interrupt Enable */
#define PIO_IER_P31 (0x1u << 31) /**< \brief (PIO_IER) Input Change Interrupt Enable */
/* -------- PIO_IDR : (PIO Offset: 0x0044) Interrupt Disable Register -------- */
#define PIO_IDR_P0 (0x1u << 0) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P1 (0x1u << 1) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P2 (0x1u << 2) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P3 (0x1u << 3) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P4 (0x1u << 4) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P5 (0x1u << 5) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P6 (0x1u << 6) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P7 (0x1u << 7) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P8 (0x1u << 8) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P9 (0x1u << 9) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P10 (0x1u << 10) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P11 (0x1u << 11) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P12 (0x1u << 12) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P13 (0x1u << 13) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P14 (0x1u << 14) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P15 (0x1u << 15) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P16 (0x1u << 16) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P17 (0x1u << 17) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P18 (0x1u << 18) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P19 (0x1u << 19) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P20 (0x1u << 20) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P21 (0x1u << 21) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P22 (0x1u << 22) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P23 (0x1u << 23) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P24 (0x1u << 24) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P25 (0x1u << 25) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P26 (0x1u << 26) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P27 (0x1u << 27) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P28 (0x1u << 28) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P29 (0x1u << 29) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P30 (0x1u << 30) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
#define PIO_IDR_P31 (0x1u << 31) /**< \brief (PIO_IDR) Input Change Interrupt Disable */
/* -------- PIO_IMR : (PIO Offset: 0x0048) Interrupt Mask Register -------- */
#define PIO_IMR_P0 (0x1u << 0) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P1 (0x1u << 1) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P2 (0x1u << 2) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P3 (0x1u << 3) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P4 (0x1u << 4) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P5 (0x1u << 5) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P6 (0x1u << 6) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P7 (0x1u << 7) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P8 (0x1u << 8) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P9 (0x1u << 9) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P10 (0x1u << 10) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P11 (0x1u << 11) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P12 (0x1u << 12) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P13 (0x1u << 13) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P14 (0x1u << 14) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P15 (0x1u << 15) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P16 (0x1u << 16) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P17 (0x1u << 17) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P18 (0x1u << 18) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P19 (0x1u << 19) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P20 (0x1u << 20) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P21 (0x1u << 21) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P22 (0x1u << 22) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P23 (0x1u << 23) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P24 (0x1u << 24) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P25 (0x1u << 25) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P26 (0x1u << 26) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P27 (0x1u << 27) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P28 (0x1u << 28) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P29 (0x1u << 29) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P30 (0x1u << 30) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
#define PIO_IMR_P31 (0x1u << 31) /**< \brief (PIO_IMR) Input Change Interrupt Mask */
/* -------- PIO_ISR : (PIO Offset: 0x004C) Interrupt Status Register -------- */
#define PIO_ISR_P0 (0x1u << 0) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P1 (0x1u << 1) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P2 (0x1u << 2) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P3 (0x1u << 3) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P4 (0x1u << 4) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P5 (0x1u << 5) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P6 (0x1u << 6) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P7 (0x1u << 7) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P8 (0x1u << 8) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P9 (0x1u << 9) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P10 (0x1u << 10) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P11 (0x1u << 11) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P12 (0x1u << 12) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P13 (0x1u << 13) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P14 (0x1u << 14) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P15 (0x1u << 15) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P16 (0x1u << 16) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P17 (0x1u << 17) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P18 (0x1u << 18) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P19 (0x1u << 19) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P20 (0x1u << 20) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P21 (0x1u << 21) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P22 (0x1u << 22) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P23 (0x1u << 23) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P24 (0x1u << 24) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P25 (0x1u << 25) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P26 (0x1u << 26) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P27 (0x1u << 27) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P28 (0x1u << 28) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P29 (0x1u << 29) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P30 (0x1u << 30) /**< \brief (PIO_ISR) Input Change Interrupt Status */
#define PIO_ISR_P31 (0x1u << 31) /**< \brief (PIO_ISR) Input Change Interrupt Status */
/* -------- PIO_MDER : (PIO Offset: 0x0050) Multi-driver Enable Register -------- */
#define PIO_MDER_P0 (0x1u << 0) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P1 (0x1u << 1) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P2 (0x1u << 2) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P3 (0x1u << 3) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P4 (0x1u << 4) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P5 (0x1u << 5) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P6 (0x1u << 6) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P7 (0x1u << 7) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P8 (0x1u << 8) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P9 (0x1u << 9) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P10 (0x1u << 10) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P11 (0x1u << 11) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P12 (0x1u << 12) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P13 (0x1u << 13) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P14 (0x1u << 14) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P15 (0x1u << 15) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P16 (0x1u << 16) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P17 (0x1u << 17) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P18 (0x1u << 18) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P19 (0x1u << 19) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P20 (0x1u << 20) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P21 (0x1u << 21) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P22 (0x1u << 22) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P23 (0x1u << 23) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P24 (0x1u << 24) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P25 (0x1u << 25) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P26 (0x1u << 26) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P27 (0x1u << 27) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P28 (0x1u << 28) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P29 (0x1u << 29) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P30 (0x1u << 30) /**< \brief (PIO_MDER) Multi Drive Enable. */
#define PIO_MDER_P31 (0x1u << 31) /**< \brief (PIO_MDER) Multi Drive Enable. */
/* -------- PIO_MDDR : (PIO Offset: 0x0054) Multi-driver Disable Register -------- */
#define PIO_MDDR_P0 (0x1u << 0) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P1 (0x1u << 1) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P2 (0x1u << 2) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P3 (0x1u << 3) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P4 (0x1u << 4) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P5 (0x1u << 5) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P6 (0x1u << 6) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P7 (0x1u << 7) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P8 (0x1u << 8) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P9 (0x1u << 9) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P10 (0x1u << 10) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P11 (0x1u << 11) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P12 (0x1u << 12) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P13 (0x1u << 13) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P14 (0x1u << 14) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P15 (0x1u << 15) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P16 (0x1u << 16) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P17 (0x1u << 17) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P18 (0x1u << 18) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P19 (0x1u << 19) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P20 (0x1u << 20) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P21 (0x1u << 21) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P22 (0x1u << 22) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P23 (0x1u << 23) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P24 (0x1u << 24) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P25 (0x1u << 25) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P26 (0x1u << 26) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P27 (0x1u << 27) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P28 (0x1u << 28) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P29 (0x1u << 29) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P30 (0x1u << 30) /**< \brief (PIO_MDDR) Multi Drive Disable. */
#define PIO_MDDR_P31 (0x1u << 31) /**< \brief (PIO_MDDR) Multi Drive Disable. */
/* -------- PIO_MDSR : (PIO Offset: 0x0058) Multi-driver Status Register -------- */
#define PIO_MDSR_P0 (0x1u << 0) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P1 (0x1u << 1) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P2 (0x1u << 2) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P3 (0x1u << 3) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P4 (0x1u << 4) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P5 (0x1u << 5) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P6 (0x1u << 6) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P7 (0x1u << 7) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P8 (0x1u << 8) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P9 (0x1u << 9) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P10 (0x1u << 10) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P11 (0x1u << 11) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P12 (0x1u << 12) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P13 (0x1u << 13) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P14 (0x1u << 14) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P15 (0x1u << 15) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P16 (0x1u << 16) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P17 (0x1u << 17) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P18 (0x1u << 18) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P19 (0x1u << 19) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P20 (0x1u << 20) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P21 (0x1u << 21) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P22 (0x1u << 22) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P23 (0x1u << 23) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P24 (0x1u << 24) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P25 (0x1u << 25) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P26 (0x1u << 26) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P27 (0x1u << 27) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P28 (0x1u << 28) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P29 (0x1u << 29) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P30 (0x1u << 30) /**< \brief (PIO_MDSR) Multi Drive Status. */
#define PIO_MDSR_P31 (0x1u << 31) /**< \brief (PIO_MDSR) Multi Drive Status. */
/* -------- PIO_PUDR : (PIO Offset: 0x0060) Pull-up Disable Register -------- */
#define PIO_PUDR_P0 (0x1u << 0) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P1 (0x1u << 1) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P2 (0x1u << 2) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P3 (0x1u << 3) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P4 (0x1u << 4) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P5 (0x1u << 5) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P6 (0x1u << 6) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P7 (0x1u << 7) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P8 (0x1u << 8) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P9 (0x1u << 9) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P10 (0x1u << 10) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P11 (0x1u << 11) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P12 (0x1u << 12) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P13 (0x1u << 13) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P14 (0x1u << 14) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P15 (0x1u << 15) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P16 (0x1u << 16) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P17 (0x1u << 17) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P18 (0x1u << 18) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P19 (0x1u << 19) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P20 (0x1u << 20) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P21 (0x1u << 21) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P22 (0x1u << 22) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P23 (0x1u << 23) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P24 (0x1u << 24) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P25 (0x1u << 25) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P26 (0x1u << 26) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P27 (0x1u << 27) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P28 (0x1u << 28) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P29 (0x1u << 29) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P30 (0x1u << 30) /**< \brief (PIO_PUDR) Pull Up Disable. */
#define PIO_PUDR_P31 (0x1u << 31) /**< \brief (PIO_PUDR) Pull Up Disable. */
/* -------- PIO_PUER : (PIO Offset: 0x0064) Pull-up Enable Register -------- */
#define PIO_PUER_P0 (0x1u << 0) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P1 (0x1u << 1) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P2 (0x1u << 2) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P3 (0x1u << 3) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P4 (0x1u << 4) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P5 (0x1u << 5) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P6 (0x1u << 6) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P7 (0x1u << 7) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P8 (0x1u << 8) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P9 (0x1u << 9) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P10 (0x1u << 10) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P11 (0x1u << 11) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P12 (0x1u << 12) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P13 (0x1u << 13) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P14 (0x1u << 14) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P15 (0x1u << 15) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P16 (0x1u << 16) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P17 (0x1u << 17) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P18 (0x1u << 18) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P19 (0x1u << 19) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P20 (0x1u << 20) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P21 (0x1u << 21) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P22 (0x1u << 22) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P23 (0x1u << 23) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P24 (0x1u << 24) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P25 (0x1u << 25) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P26 (0x1u << 26) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P27 (0x1u << 27) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P28 (0x1u << 28) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P29 (0x1u << 29) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P30 (0x1u << 30) /**< \brief (PIO_PUER) Pull Up Enable. */
#define PIO_PUER_P31 (0x1u << 31) /**< \brief (PIO_PUER) Pull Up Enable. */
/* -------- PIO_PUSR : (PIO Offset: 0x0068) Pad Pull-up Status Register -------- */
#define PIO_PUSR_P0 (0x1u << 0) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P1 (0x1u << 1) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P2 (0x1u << 2) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P3 (0x1u << 3) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P4 (0x1u << 4) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P5 (0x1u << 5) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P6 (0x1u << 6) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P7 (0x1u << 7) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P8 (0x1u << 8) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P9 (0x1u << 9) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P10 (0x1u << 10) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P11 (0x1u << 11) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P12 (0x1u << 12) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P13 (0x1u << 13) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P14 (0x1u << 14) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P15 (0x1u << 15) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P16 (0x1u << 16) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P17 (0x1u << 17) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P18 (0x1u << 18) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P19 (0x1u << 19) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P20 (0x1u << 20) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P21 (0x1u << 21) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P22 (0x1u << 22) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P23 (0x1u << 23) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P24 (0x1u << 24) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P25 (0x1u << 25) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P26 (0x1u << 26) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P27 (0x1u << 27) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P28 (0x1u << 28) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P29 (0x1u << 29) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P30 (0x1u << 30) /**< \brief (PIO_PUSR) Pull Up Status. */
#define PIO_PUSR_P31 (0x1u << 31) /**< \brief (PIO_PUSR) Pull Up Status. */
/* -------- PIO_ABCDSR[2] : (PIO Offset: 0x0070) Peripheral Select Register -------- */
#define PIO_ABCDSR_P0 (0x1u << 0) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P1 (0x1u << 1) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P2 (0x1u << 2) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P3 (0x1u << 3) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P4 (0x1u << 4) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P5 (0x1u << 5) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P6 (0x1u << 6) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P7 (0x1u << 7) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P8 (0x1u << 8) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P9 (0x1u << 9) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P10 (0x1u << 10) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P11 (0x1u << 11) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P12 (0x1u << 12) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P13 (0x1u << 13) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P14 (0x1u << 14) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P15 (0x1u << 15) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P16 (0x1u << 16) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P17 (0x1u << 17) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P18 (0x1u << 18) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P19 (0x1u << 19) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P20 (0x1u << 20) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P21 (0x1u << 21) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P22 (0x1u << 22) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P23 (0x1u << 23) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P24 (0x1u << 24) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P25 (0x1u << 25) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P26 (0x1u << 26) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P27 (0x1u << 27) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P28 (0x1u << 28) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P29 (0x1u << 29) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P30 (0x1u << 30) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
#define PIO_ABCDSR_P31 (0x1u << 31) /**< \brief (PIO_ABCDSR[2]) Peripheral Select. */
/* -------- PIO_IFSCDR : (PIO Offset: 0x0080) Input Filter Slow Clock Disable Register -------- */
#define PIO_IFSCDR_P0 (0x1u << 0) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P1 (0x1u << 1) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P2 (0x1u << 2) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P3 (0x1u << 3) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P4 (0x1u << 4) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P5 (0x1u << 5) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P6 (0x1u << 6) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P7 (0x1u << 7) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P8 (0x1u << 8) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P9 (0x1u << 9) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P10 (0x1u << 10) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P11 (0x1u << 11) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P12 (0x1u << 12) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P13 (0x1u << 13) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P14 (0x1u << 14) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P15 (0x1u << 15) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P16 (0x1u << 16) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P17 (0x1u << 17) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P18 (0x1u << 18) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P19 (0x1u << 19) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P20 (0x1u << 20) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P21 (0x1u << 21) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P22 (0x1u << 22) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P23 (0x1u << 23) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P24 (0x1u << 24) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P25 (0x1u << 25) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P26 (0x1u << 26) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P27 (0x1u << 27) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P28 (0x1u << 28) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P29 (0x1u << 29) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P30 (0x1u << 30) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
#define PIO_IFSCDR_P31 (0x1u << 31) /**< \brief (PIO_IFSCDR) PIO Clock Glitch Filtering Select. */
/* -------- PIO_IFSCER : (PIO Offset: 0x0084) Input Filter Slow Clock Enable Register -------- */
#define PIO_IFSCER_P0 (0x1u << 0) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P1 (0x1u << 1) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P2 (0x1u << 2) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P3 (0x1u << 3) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P4 (0x1u << 4) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P5 (0x1u << 5) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P6 (0x1u << 6) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P7 (0x1u << 7) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P8 (0x1u << 8) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P9 (0x1u << 9) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P10 (0x1u << 10) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P11 (0x1u << 11) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P12 (0x1u << 12) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P13 (0x1u << 13) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P14 (0x1u << 14) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P15 (0x1u << 15) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P16 (0x1u << 16) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P17 (0x1u << 17) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P18 (0x1u << 18) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P19 (0x1u << 19) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P20 (0x1u << 20) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P21 (0x1u << 21) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P22 (0x1u << 22) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P23 (0x1u << 23) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P24 (0x1u << 24) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P25 (0x1u << 25) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P26 (0x1u << 26) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P27 (0x1u << 27) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P28 (0x1u << 28) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P29 (0x1u << 29) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P30 (0x1u << 30) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
#define PIO_IFSCER_P31 (0x1u << 31) /**< \brief (PIO_IFSCER) Debouncing Filtering Select. */
/* -------- PIO_IFSCSR : (PIO Offset: 0x0088) Input Filter Slow Clock Status Register -------- */
#define PIO_IFSCSR_P0 (0x1u << 0) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P1 (0x1u << 1) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P2 (0x1u << 2) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P3 (0x1u << 3) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P4 (0x1u << 4) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P5 (0x1u << 5) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P6 (0x1u << 6) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P7 (0x1u << 7) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P8 (0x1u << 8) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P9 (0x1u << 9) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P10 (0x1u << 10) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P11 (0x1u << 11) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P12 (0x1u << 12) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P13 (0x1u << 13) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P14 (0x1u << 14) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P15 (0x1u << 15) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P16 (0x1u << 16) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P17 (0x1u << 17) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P18 (0x1u << 18) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P19 (0x1u << 19) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P20 (0x1u << 20) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P21 (0x1u << 21) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P22 (0x1u << 22) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P23 (0x1u << 23) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P24 (0x1u << 24) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P25 (0x1u << 25) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P26 (0x1u << 26) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P27 (0x1u << 27) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P28 (0x1u << 28) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P29 (0x1u << 29) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P30 (0x1u << 30) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
#define PIO_IFSCSR_P31 (0x1u << 31) /**< \brief (PIO_IFSCSR) Glitch or Debouncing Filter Selection Status */
/* -------- PIO_SCDR : (PIO Offset: 0x008C) Slow Clock Divider Debouncing Register -------- */
#define PIO_SCDR_DIV_Pos 0
#define PIO_SCDR_DIV_Msk (0x3fffu << PIO_SCDR_DIV_Pos) /**< \brief (PIO_SCDR)  */
#define PIO_SCDR_DIV(value) ((PIO_SCDR_DIV_Msk & ((value) << PIO_SCDR_DIV_Pos)))
/* -------- PIO_PPDDR : (PIO Offset: 0x0090) Pad Pull-down Disable Register -------- */
#define PIO_PPDDR_P0 (0x1u << 0) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P1 (0x1u << 1) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P2 (0x1u << 2) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P3 (0x1u << 3) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P4 (0x1u << 4) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P5 (0x1u << 5) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P6 (0x1u << 6) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P7 (0x1u << 7) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P8 (0x1u << 8) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P9 (0x1u << 9) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P10 (0x1u << 10) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P11 (0x1u << 11) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P12 (0x1u << 12) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P13 (0x1u << 13) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P14 (0x1u << 14) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P15 (0x1u << 15) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P16 (0x1u << 16) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P17 (0x1u << 17) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P18 (0x1u << 18) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P19 (0x1u << 19) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P20 (0x1u << 20) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P21 (0x1u << 21) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P22 (0x1u << 22) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P23 (0x1u << 23) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P24 (0x1u << 24) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P25 (0x1u << 25) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P26 (0x1u << 26) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P27 (0x1u << 27) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P28 (0x1u << 28) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P29 (0x1u << 29) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P30 (0x1u << 30) /**< \brief (PIO_PPDDR) Pull Down Disable. */
#define PIO_PPDDR_P31 (0x1u << 31) /**< \brief (PIO_PPDDR) Pull Down Disable. */
/* -------- PIO_PPDER : (PIO Offset: 0x0094) Pad Pull-down Enable Register -------- */
#define PIO_PPDER_P0 (0x1u << 0) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P1 (0x1u << 1) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P2 (0x1u << 2) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P3 (0x1u << 3) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P4 (0x1u << 4) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P5 (0x1u << 5) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P6 (0x1u << 6) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P7 (0x1u << 7) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P8 (0x1u << 8) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P9 (0x1u << 9) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P10 (0x1u << 10) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P11 (0x1u << 11) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P12 (0x1u << 12) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P13 (0x1u << 13) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P14 (0x1u << 14) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P15 (0x1u << 15) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P16 (0x1u << 16) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P17 (0x1u << 17) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P18 (0x1u << 18) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P19 (0x1u << 19) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P20 (0x1u << 20) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P21 (0x1u << 21) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P22 (0x1u << 22) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P23 (0x1u << 23) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P24 (0x1u << 24) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P25 (0x1u << 25) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P26 (0x1u << 26) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P27 (0x1u << 27) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P28 (0x1u << 28) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P29 (0x1u << 29) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P30 (0x1u << 30) /**< \brief (PIO_PPDER) Pull Down Enable. */
#define PIO_PPDER_P31 (0x1u << 31) /**< \brief (PIO_PPDER) Pull Down Enable. */
/* -------- PIO_PPDSR : (PIO Offset: 0x0098) Pad Pull-down Status Register -------- */
#define PIO_PPDSR_P0 (0x1u << 0) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P1 (0x1u << 1) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P2 (0x1u << 2) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P3 (0x1u << 3) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P4 (0x1u << 4) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P5 (0x1u << 5) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P6 (0x1u << 6) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P7 (0x1u << 7) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P8 (0x1u << 8) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P9 (0x1u << 9) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P10 (0x1u << 10) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P11 (0x1u << 11) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P12 (0x1u << 12) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P13 (0x1u << 13) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P14 (0x1u << 14) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P15 (0x1u << 15) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P16 (0x1u << 16) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P17 (0x1u << 17) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P18 (0x1u << 18) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P19 (0x1u << 19) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P20 (0x1u << 20) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P21 (0x1u << 21) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P22 (0x1u << 22) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P23 (0x1u << 23) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P24 (0x1u << 24) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P25 (0x1u << 25) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P26 (0x1u << 26) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P27 (0x1u << 27) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P28 (0x1u << 28) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P29 (0x1u << 29) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P30 (0x1u << 30) /**< \brief (PIO_PPDSR) Pull Down Status. */
#define PIO_PPDSR_P31 (0x1u << 31) /**< \brief (PIO_PPDSR) Pull Down Status. */
/* -------- PIO_OWER : (PIO Offset: 0x00A0) Output Write Enable -------- */
#define PIO_OWER_P0 (0x1u << 0) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P1 (0x1u << 1) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P2 (0x1u << 2) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P3 (0x1u << 3) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P4 (0x1u << 4) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P5 (0x1u << 5) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P6 (0x1u << 6) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P7 (0x1u << 7) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P8 (0x1u << 8) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P9 (0x1u << 9) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P10 (0x1u << 10) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P11 (0x1u << 11) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P12 (0x1u << 12) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P13 (0x1u << 13) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P14 (0x1u << 14) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P15 (0x1u << 15) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P16 (0x1u << 16) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P17 (0x1u << 17) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P18 (0x1u << 18) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P19 (0x1u << 19) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P20 (0x1u << 20) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P21 (0x1u << 21) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P22 (0x1u << 22) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P23 (0x1u << 23) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P24 (0x1u << 24) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P25 (0x1u << 25) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P26 (0x1u << 26) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P27 (0x1u << 27) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P28 (0x1u << 28) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P29 (0x1u << 29) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P30 (0x1u << 30) /**< \brief (PIO_OWER) Output Write Enable. */
#define PIO_OWER_P31 (0x1u << 31) /**< \brief (PIO_OWER) Output Write Enable. */
/* -------- PIO_OWDR : (PIO Offset: 0x00A4) Output Write Disable -------- */
#define PIO_OWDR_P0 (0x1u << 0) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P1 (0x1u << 1) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P2 (0x1u << 2) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P3 (0x1u << 3) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P4 (0x1u << 4) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P5 (0x1u << 5) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P6 (0x1u << 6) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P7 (0x1u << 7) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P8 (0x1u << 8) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P9 (0x1u << 9) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P10 (0x1u << 10) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P11 (0x1u << 11) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P12 (0x1u << 12) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P13 (0x1u << 13) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P14 (0x1u << 14) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P15 (0x1u << 15) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P16 (0x1u << 16) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P17 (0x1u << 17) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P18 (0x1u << 18) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P19 (0x1u << 19) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P20 (0x1u << 20) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P21 (0x1u << 21) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P22 (0x1u << 22) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P23 (0x1u << 23) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P24 (0x1u << 24) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P25 (0x1u << 25) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P26 (0x1u << 26) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P27 (0x1u << 27) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P28 (0x1u << 28) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P29 (0x1u << 29) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P30 (0x1u << 30) /**< \brief (PIO_OWDR) Output Write Disable. */
#define PIO_OWDR_P31 (0x1u << 31) /**< \brief (PIO_OWDR) Output Write Disable. */
/* -------- PIO_OWSR : (PIO Offset: 0x00A8) Output Write Status Register -------- */
#define PIO_OWSR_P0 (0x1u << 0) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P1 (0x1u << 1) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P2 (0x1u << 2) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P3 (0x1u << 3) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P4 (0x1u << 4) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P5 (0x1u << 5) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P6 (0x1u << 6) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P7 (0x1u << 7) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P8 (0x1u << 8) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P9 (0x1u << 9) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P10 (0x1u << 10) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P11 (0x1u << 11) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P12 (0x1u << 12) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P13 (0x1u << 13) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P14 (0x1u << 14) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P15 (0x1u << 15) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P16 (0x1u << 16) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P17 (0x1u << 17) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P18 (0x1u << 18) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P19 (0x1u << 19) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P20 (0x1u << 20) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P21 (0x1u << 21) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P22 (0x1u << 22) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P23 (0x1u << 23) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P24 (0x1u << 24) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P25 (0x1u << 25) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P26 (0x1u << 26) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P27 (0x1u << 27) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P28 (0x1u << 28) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P29 (0x1u << 29) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P30 (0x1u << 30) /**< \brief (PIO_OWSR) Output Write Status. */
#define PIO_OWSR_P31 (0x1u << 31) /**< \brief (PIO_OWSR) Output Write Status. */
/* -------- PIO_AIMER : (PIO Offset: 0x00B0) Additional Interrupt Modes Enable Register -------- */
#define PIO_AIMER_P0 (0x1u << 0) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P1 (0x1u << 1) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P2 (0x1u << 2) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P3 (0x1u << 3) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P4 (0x1u << 4) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P5 (0x1u << 5) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P6 (0x1u << 6) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P7 (0x1u << 7) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P8 (0x1u << 8) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P9 (0x1u << 9) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P10 (0x1u << 10) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P11 (0x1u << 11) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P12 (0x1u << 12) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P13 (0x1u << 13) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P14 (0x1u << 14) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P15 (0x1u << 15) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P16 (0x1u << 16) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P17 (0x1u << 17) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P18 (0x1u << 18) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P19 (0x1u << 19) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P20 (0x1u << 20) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P21 (0x1u << 21) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P22 (0x1u << 22) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P23 (0x1u << 23) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P24 (0x1u << 24) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P25 (0x1u << 25) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P26 (0x1u << 26) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P27 (0x1u << 27) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P28 (0x1u << 28) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P29 (0x1u << 29) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P30 (0x1u << 30) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
#define PIO_AIMER_P31 (0x1u << 31) /**< \brief (PIO_AIMER) Additional Interrupt Modes Enable. */
/* -------- PIO_AIMDR : (PIO Offset: 0x00B4) Additional Interrupt Modes Disables Register -------- */
#define PIO_AIMDR_P0 (0x1u << 0) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P1 (0x1u << 1) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P2 (0x1u << 2) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P3 (0x1u << 3) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P4 (0x1u << 4) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P5 (0x1u << 5) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P6 (0x1u << 6) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P7 (0x1u << 7) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P8 (0x1u << 8) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P9 (0x1u << 9) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P10 (0x1u << 10) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P11 (0x1u << 11) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P12 (0x1u << 12) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P13 (0x1u << 13) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P14 (0x1u << 14) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P15 (0x1u << 15) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P16 (0x1u << 16) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P17 (0x1u << 17) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P18 (0x1u << 18) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P19 (0x1u << 19) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P20 (0x1u << 20) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P21 (0x1u << 21) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P22 (0x1u << 22) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P23 (0x1u << 23) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P24 (0x1u << 24) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P25 (0x1u << 25) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P26 (0x1u << 26) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P27 (0x1u << 27) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P28 (0x1u << 28) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P29 (0x1u << 29) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P30 (0x1u << 30) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
#define PIO_AIMDR_P31 (0x1u << 31) /**< \brief (PIO_AIMDR) Additional Interrupt Modes Disable. */
/* -------- PIO_AIMMR : (PIO Offset: 0x00B8) Additional Interrupt Modes Mask Register -------- */
#define PIO_AIMMR_P0 (0x1u << 0) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P1 (0x1u << 1) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P2 (0x1u << 2) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P3 (0x1u << 3) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P4 (0x1u << 4) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P5 (0x1u << 5) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P6 (0x1u << 6) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P7 (0x1u << 7) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P8 (0x1u << 8) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P9 (0x1u << 9) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P10 (0x1u << 10) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P11 (0x1u << 11) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P12 (0x1u << 12) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P13 (0x1u << 13) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P14 (0x1u << 14) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P15 (0x1u << 15) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P16 (0x1u << 16) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P17 (0x1u << 17) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P18 (0x1u << 18) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P19 (0x1u << 19) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P20 (0x1u << 20) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P21 (0x1u << 21) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P22 (0x1u << 22) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P23 (0x1u << 23) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P24 (0x1u << 24) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P25 (0x1u << 25) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P26 (0x1u << 26) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P27 (0x1u << 27) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P28 (0x1u << 28) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P29 (0x1u << 29) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P30 (0x1u << 30) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
#define PIO_AIMMR_P31 (0x1u << 31) /**< \brief (PIO_AIMMR) Peripheral CD Status. */
/* -------- PIO_ESR : (PIO Offset: 0x00C0) Edge Select Register -------- */
#define PIO_ESR_P0 (0x1u << 0) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P1 (0x1u << 1) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P2 (0x1u << 2) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P3 (0x1u << 3) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P4 (0x1u << 4) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P5 (0x1u << 5) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P6 (0x1u << 6) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P7 (0x1u << 7) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P8 (0x1u << 8) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P9 (0x1u << 9) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P10 (0x1u << 10) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P11 (0x1u << 11) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P12 (0x1u << 12) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P13 (0x1u << 13) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P14 (0x1u << 14) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P15 (0x1u << 15) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P16 (0x1u << 16) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P17 (0x1u << 17) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P18 (0x1u << 18) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P19 (0x1u << 19) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P20 (0x1u << 20) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P21 (0x1u << 21) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P22 (0x1u << 22) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P23 (0x1u << 23) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P24 (0x1u << 24) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P25 (0x1u << 25) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P26 (0x1u << 26) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P27 (0x1u << 27) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P28 (0x1u << 28) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P29 (0x1u << 29) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P30 (0x1u << 30) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
#define PIO_ESR_P31 (0x1u << 31) /**< \brief (PIO_ESR) Edge Interrupt Selection. */
/* -------- PIO_LSR : (PIO Offset: 0x00C4) Level Select Register -------- */
#define PIO_LSR_P0 (0x1u << 0) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P1 (0x1u << 1) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P2 (0x1u << 2) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P3 (0x1u << 3) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P4 (0x1u << 4) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P5 (0x1u << 5) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P6 (0x1u << 6) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P7 (0x1u << 7) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P8 (0x1u << 8) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P9 (0x1u << 9) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P10 (0x1u << 10) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P11 (0x1u << 11) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P12 (0x1u << 12) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P13 (0x1u << 13) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P14 (0x1u << 14) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P15 (0x1u << 15) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P16 (0x1u << 16) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P17 (0x1u << 17) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P18 (0x1u << 18) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P19 (0x1u << 19) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P20 (0x1u << 20) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P21 (0x1u << 21) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P22 (0x1u << 22) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P23 (0x1u << 23) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P24 (0x1u << 24) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P25 (0x1u << 25) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P26 (0x1u << 26) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P27 (0x1u << 27) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P28 (0x1u << 28) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P29 (0x1u << 29) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P30 (0x1u << 30) /**< \brief (PIO_LSR) Level Interrupt Selection. */
#define PIO_LSR_P31 (0x1u << 31) /**< \brief (PIO_LSR) Level Interrupt Selection. */
/* -------- PIO_ELSR : (PIO Offset: 0x00C8) Edge/Level Status Register -------- */
#define PIO_ELSR_P0 (0x1u << 0) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P1 (0x1u << 1) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P2 (0x1u << 2) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P3 (0x1u << 3) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P4 (0x1u << 4) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P5 (0x1u << 5) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P6 (0x1u << 6) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P7 (0x1u << 7) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P8 (0x1u << 8) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P9 (0x1u << 9) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P10 (0x1u << 10) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P11 (0x1u << 11) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P12 (0x1u << 12) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P13 (0x1u << 13) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P14 (0x1u << 14) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P15 (0x1u << 15) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P16 (0x1u << 16) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P17 (0x1u << 17) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P18 (0x1u << 18) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P19 (0x1u << 19) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P20 (0x1u << 20) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P21 (0x1u << 21) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P22 (0x1u << 22) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P23 (0x1u << 23) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P24 (0x1u << 24) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P25 (0x1u << 25) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P26 (0x1u << 26) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P27 (0x1u << 27) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P28 (0x1u << 28) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P29 (0x1u << 29) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P30 (0x1u << 30) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
#define PIO_ELSR_P31 (0x1u << 31) /**< \brief (PIO_ELSR) Edge/Level Interrupt source selection. */
/* -------- PIO_FELLSR : (PIO Offset: 0x00D0) Falling Edge/Low Level Select Register -------- */
#define PIO_FELLSR_P0 (0x1u << 0) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P1 (0x1u << 1) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P2 (0x1u << 2) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P3 (0x1u << 3) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P4 (0x1u << 4) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P5 (0x1u << 5) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P6 (0x1u << 6) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P7 (0x1u << 7) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P8 (0x1u << 8) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P9 (0x1u << 9) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P10 (0x1u << 10) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P11 (0x1u << 11) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P12 (0x1u << 12) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P13 (0x1u << 13) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P14 (0x1u << 14) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P15 (0x1u << 15) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P16 (0x1u << 16) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P17 (0x1u << 17) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P18 (0x1u << 18) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P19 (0x1u << 19) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P20 (0x1u << 20) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P21 (0x1u << 21) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P22 (0x1u << 22) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P23 (0x1u << 23) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P24 (0x1u << 24) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P25 (0x1u << 25) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P26 (0x1u << 26) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P27 (0x1u << 27) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P28 (0x1u << 28) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P29 (0x1u << 29) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P30 (0x1u << 30) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
#define PIO_FELLSR_P31 (0x1u << 31) /**< \brief (PIO_FELLSR) Falling Edge/Low Level Interrupt Selection. */
/* -------- PIO_REHLSR : (PIO Offset: 0x00D4) Rising Edge/ High Level Select Register -------- */
#define PIO_REHLSR_P0 (0x1u << 0) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P1 (0x1u << 1) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P2 (0x1u << 2) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P3 (0x1u << 3) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P4 (0x1u << 4) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P5 (0x1u << 5) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P6 (0x1u << 6) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P7 (0x1u << 7) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P8 (0x1u << 8) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P9 (0x1u << 9) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P10 (0x1u << 10) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P11 (0x1u << 11) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P12 (0x1u << 12) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P13 (0x1u << 13) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P14 (0x1u << 14) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P15 (0x1u << 15) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P16 (0x1u << 16) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P17 (0x1u << 17) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P18 (0x1u << 18) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P19 (0x1u << 19) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P20 (0x1u << 20) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P21 (0x1u << 21) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P22 (0x1u << 22) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P23 (0x1u << 23) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P24 (0x1u << 24) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P25 (0x1u << 25) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P26 (0x1u << 26) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P27 (0x1u << 27) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P28 (0x1u << 28) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P29 (0x1u << 29) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P30 (0x1u << 30) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
#define PIO_REHLSR_P31 (0x1u << 31) /**< \brief (PIO_REHLSR) Rising Edge /High Level Interrupt Selection. */
/* -------- PIO_FRLHSR : (PIO Offset: 0x00D8) Fall/Rise - Low/High Status Register -------- */
#define PIO_FRLHSR_P0 (0x1u << 0) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P1 (0x1u << 1) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P2 (0x1u << 2) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P3 (0x1u << 3) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P4 (0x1u << 4) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P5 (0x1u << 5) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P6 (0x1u << 6) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P7 (0x1u << 7) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P8 (0x1u << 8) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P9 (0x1u << 9) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P10 (0x1u << 10) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P11 (0x1u << 11) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P12 (0x1u << 12) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P13 (0x1u << 13) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P14 (0x1u << 14) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P15 (0x1u << 15) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P16 (0x1u << 16) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P17 (0x1u << 17) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P18 (0x1u << 18) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P19 (0x1u << 19) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P20 (0x1u << 20) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P21 (0x1u << 21) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P22 (0x1u << 22) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P23 (0x1u << 23) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P24 (0x1u << 24) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P25 (0x1u << 25) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P26 (0x1u << 26) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P27 (0x1u << 27) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P28 (0x1u << 28) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P29 (0x1u << 29) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P30 (0x1u << 30) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
#define PIO_FRLHSR_P31 (0x1u << 31) /**< \brief (PIO_FRLHSR) Edge /Level Interrupt Source Selection. */
/* -------- PIO_LOCKSR : (PIO Offset: 0x00E0) Lock Status -------- */
#define PIO_LOCKSR_P0 (0x1u << 0) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P1 (0x1u << 1) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P2 (0x1u << 2) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P3 (0x1u << 3) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P4 (0x1u << 4) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P5 (0x1u << 5) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P6 (0x1u << 6) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P7 (0x1u << 7) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P8 (0x1u << 8) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P9 (0x1u << 9) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P10 (0x1u << 10) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P11 (0x1u << 11) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P12 (0x1u << 12) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P13 (0x1u << 13) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P14 (0x1u << 14) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P15 (0x1u << 15) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P16 (0x1u << 16) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P17 (0x1u << 17) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P18 (0x1u << 18) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P19 (0x1u << 19) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P20 (0x1u << 20) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P21 (0x1u << 21) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P22 (0x1u << 22) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P23 (0x1u << 23) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P24 (0x1u << 24) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P25 (0x1u << 25) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P26 (0x1u << 26) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P27 (0x1u << 27) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P28 (0x1u << 28) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P29 (0x1u << 29) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P30 (0x1u << 30) /**< \brief (PIO_LOCKSR) Lock Status. */
#define PIO_LOCKSR_P31 (0x1u << 31) /**< \brief (PIO_LOCKSR) Lock Status. */
/* -------- PIO_WPMR : (PIO Offset: 0x00E4) Write Protect Mode Register -------- */
#define PIO_WPMR_WPEN (0x1u << 0) /**< \brief (PIO_WPMR) Write Protect Enable */
#define PIO_WPMR_WPKEY_Pos 8
#define PIO_WPMR_WPKEY_Msk (0xffffffu << PIO_WPMR_WPKEY_Pos) /**< \brief (PIO_WPMR) Write Protect KEY */
#define PIO_WPMR_WPKEY(value) ((PIO_WPMR_WPKEY_Msk & ((value) << PIO_WPMR_WPKEY_Pos)))
/* -------- PIO_WPSR : (PIO Offset: 0x00E8) Write Protect Status Register -------- */
#define PIO_WPSR_WPVS (0x1u << 0) /**< \brief (PIO_WPSR) Write Protect Violation Status */
#define PIO_WPSR_WPVSRC_Pos 8
#define PIO_WPSR_WPVSRC_Msk (0xffffu << PIO_WPSR_WPVSRC_Pos) /**< \brief (PIO_WPSR) Write Protect Violation Source */
/* -------- PIO_SCHMITT : (PIO Offset: 0x0100) Schmitt Trigger Register -------- */
#define PIO_SCHMITT_SCHMITT0 (0x1u << 0) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT1 (0x1u << 1) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT2 (0x1u << 2) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT3 (0x1u << 3) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT4 (0x1u << 4) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT5 (0x1u << 5) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT6 (0x1u << 6) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT7 (0x1u << 7) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT8 (0x1u << 8) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT9 (0x1u << 9) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT10 (0x1u << 10) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT11 (0x1u << 11) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT12 (0x1u << 12) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT13 (0x1u << 13) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT14 (0x1u << 14) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT15 (0x1u << 15) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT16 (0x1u << 16) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT17 (0x1u << 17) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT18 (0x1u << 18) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT19 (0x1u << 19) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT20 (0x1u << 20) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT21 (0x1u << 21) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT22 (0x1u << 22) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT23 (0x1u << 23) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT24 (0x1u << 24) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT25 (0x1u << 25) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT26 (0x1u << 26) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT27 (0x1u << 27) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT28 (0x1u << 28) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT29 (0x1u << 29) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT30 (0x1u << 30) /**< \brief (PIO_SCHMITT)  */
#define PIO_SCHMITT_SCHMITT31 (0x1u << 31) /**< \brief (PIO_SCHMITT)  */
/* -------- PIO_PCMR : (PIO Offset: 0x150) Parallel Capture Mode Register -------- */
#define PIO_PCMR_PCEN (0x1u << 0) /**< \brief (PIO_PCMR) Parallel Capture Mode Enable */
#define PIO_PCMR_DSIZE_Pos 4
#define PIO_PCMR_DSIZE_Msk (0x3u << PIO_PCMR_DSIZE_Pos) /**< \brief (PIO_PCMR) Parallel Capture Mode Data Size */
#define PIO_PCMR_DSIZE(value) ((PIO_PCMR_DSIZE_Msk & ((value) << PIO_PCMR_DSIZE_Pos)))
#define   PIO_PCMR_DSIZE_BYTE (0x0u << 4) /**< \brief (PIO_PCMR) The reception data in the PIO_PCRHR register is a BYTE (8-bit) */
#define   PIO_PCMR_DSIZE_HALFWORD (0x1u << 4) /**< \brief (PIO_PCMR) The reception data in the PIO_PCRHR register is a HALF-WORD (16-bit) */
#define   PIO_PCMR_DSIZE_WORD (0x2u << 4) /**< \brief (PIO_PCMR) The reception data in the PIO_PCRHR register is a WORD (32-bit) */
#define PIO_PCMR_ALWYS (0x1u << 9) /**< \brief (PIO_PCMR) Parallel Capture Mode Always Sampling */
#define PIO_PCMR_HALFS (0x1u << 10) /**< \brief (PIO_PCMR) Parallel Capture Mode Half Sampling */
#define PIO_PCMR_FRSTS (0x1u << 11) /**< \brief (PIO_PCMR) Parallel Capture Mode First Sample */
/* -------- PIO_PCIER : (PIO Offset: 0x154) Parallel Capture Interrupt Enable Register -------- */
#define PIO_PCIER_DRDY (0x1u << 0) /**< \brief (PIO_PCIER) Parallel Capture Mode Data Ready Interrupt Enable */
#define PIO_PCIER_OVRE (0x1u << 1) /**< \brief (PIO_PCIER) Parallel Capture Mode Overrun Error Interrupt Enable */
#define PIO_PCIER_ENDRX (0x1u << 2) /**< \brief (PIO_PCIER) End of Reception Transfer Interrupt Enable */
#define PIO_PCIER_RXBUFF (0x1u << 3) /**< \brief (PIO_PCIER) Reception Buffer Full Interrupt Enable */
/* -------- PIO_PCIDR : (PIO Offset: 0x158) Parallel Capture Interrupt Disable Register -------- */
#define PIO_PCIDR_DRDY (0x1u << 0) /**< \brief (PIO_PCIDR) Parallel Capture Mode Data Ready Interrupt Disable */
#define PIO_PCIDR_OVRE (0x1u << 1) /**< \brief (PIO_PCIDR) Parallel Capture Mode Overrun Error Interrupt Disable */
#define PIO_PCIDR_ENDRX (0x1u << 2) /**< \brief (PIO_PCIDR) End of Reception Transfer Interrupt Disable */
#define PIO_PCIDR_RXBUFF (0x1u << 3) /**< \brief (PIO_PCIDR) Reception Buffer Full Interrupt Disable */
/* -------- PIO_PCIMR : (PIO Offset: 0x15C) Parallel Capture Interrupt Mask Register -------- */
#define PIO_PCIMR_DRDY (0x1u << 0) /**< \brief (PIO_PCIMR) Parallel Capture Mode Data Ready Interrupt Mask */
#define PIO_PCIMR_OVRE (0x1u << 1) /**< \brief (PIO_PCIMR) Parallel Capture Mode Overrun Error Interrupt Mask */
#define PIO_PCIMR_ENDRX (0x1u << 2) /**< \brief (PIO_PCIMR) End of Reception Transfer Interrupt Mask */
#define PIO_PCIMR_RXBUFF (0x1u << 3) /**< \brief (PIO_PCIMR) Reception Buffer Full Interrupt Mask */
/* -------- PIO_PCISR : (PIO Offset: 0x160) Parallel Capture Interrupt Status Register -------- */
#define PIO_PCISR_DRDY (0x1u << 0) /**< \brief (PIO_PCISR) Parallel Capture Mode Data Ready */
#define PIO_PCISR_OVRE (0x1u << 1) /**< \brief (PIO_PCISR) Parallel Capture Mode Overrun Error. */
#define PIO_PCISR_ENDRX (0x1u << 2) /**< \brief (PIO_PCISR) End of Reception Transfer. */
#define PIO_PCISR_RXBUFF (0x1u << 3) /**< \brief (PIO_PCISR) Reception Buffer Full */
/* -------- PIO_PCRHR : (PIO Offset: 0x164) Parallel Capture Reception Holding Register -------- */
#define PIO_PCRHR_RDATA_Pos 0
#define PIO_PCRHR_RDATA_Msk (0xffffffffu << PIO_PCRHR_RDATA_Pos) /**< \brief (PIO_PCRHR) Parallel Capture Mode Reception Data. */
/* -------- PIO_RPR : (PIO Offset: 0x168) Receive Pointer Register -------- */
#define PIO_RPR_RXPTR_Pos 0
#define PIO_RPR_RXPTR_Msk (0xffffffffu << PIO_RPR_RXPTR_Pos) /**< \brief (PIO_RPR) Receive Pointer Register */
#define PIO_RPR_RXPTR(value) ((PIO_RPR_RXPTR_Msk & ((value) << PIO_RPR_RXPTR_Pos)))
/* -------- PIO_RCR : (PIO Offset: 0x16C) Receive Counter Register -------- */
#define PIO_RCR_RXCTR_Pos 0
#define PIO_RCR_RXCTR_Msk (0xffffu << PIO_RCR_RXCTR_Pos) /**< \brief (PIO_RCR) Receive Counter Register */
#define PIO_RCR_RXCTR(value) ((PIO_RCR_RXCTR_Msk & ((value) << PIO_RCR_RXCTR_Pos)))
/* -------- PIO_TPR : (PIO Offset: 0x170) Transmit Pointer Register -------- */
#define PIO_TPR_TXPTR_Pos 0
#define PIO_TPR_TXPTR_Msk (0xffffffffu << PIO_TPR_TXPTR_Pos) /**< \brief (PIO_TPR) Transmit Counter Register */
#define PIO_TPR_TXPTR(value) ((PIO_TPR_TXPTR_Msk & ((value) << PIO_TPR_TXPTR_Pos)))
/* -------- PIO_TCR : (PIO Offset: 0x174) Transmit Counter Register -------- */
#define PIO_TCR_TXCTR_Pos 0
#define PIO_TCR_TXCTR_Msk (0xffffu << PIO_TCR_TXCTR_Pos) /**< \brief (PIO_TCR) Transmit Counter Register */
#define PIO_TCR_TXCTR(value) ((PIO_TCR_TXCTR_Msk & ((value) << PIO_TCR_TXCTR_Pos)))
/* -------- PIO_RNPR : (PIO Offset: 0x178) Receive Next Pointer Register -------- */
#define PIO_RNPR_RXNPTR_Pos 0
#define PIO_RNPR_RXNPTR_Msk (0xffffffffu << PIO_RNPR_RXNPTR_Pos) /**< \brief (PIO_RNPR) Receive Next Pointer */
#define PIO_RNPR_RXNPTR(value) ((PIO_RNPR_RXNPTR_Msk & ((value) << PIO_RNPR_RXNPTR_Pos)))
/* -------- PIO_RNCR : (PIO Offset: 0x17C) Receive Next Counter Register -------- */
#define PIO_RNCR_RXNCTR_Pos 0
#define PIO_RNCR_RXNCTR_Msk (0xffffu << PIO_RNCR_RXNCTR_Pos) /**< \brief (PIO_RNCR) Receive Next Counter */
#define PIO_RNCR_RXNCTR(value) ((PIO_RNCR_RXNCTR_Msk & ((value) << PIO_RNCR_RXNCTR_Pos)))
/* -------- PIO_TNPR : (PIO Offset: 0x180) Transmit Next Pointer Register -------- */
#define PIO_TNPR_TXNPTR_Pos 0
#define PIO_TNPR_TXNPTR_Msk (0xffffffffu << PIO_TNPR_TXNPTR_Pos) /**< \brief (PIO_TNPR) Transmit Next Pointer */
#define PIO_TNPR_TXNPTR(value) ((PIO_TNPR_TXNPTR_Msk & ((value) << PIO_TNPR_TXNPTR_Pos)))
/* -------- PIO_TNCR : (PIO Offset: 0x184) Transmit Next Counter Register -------- */
#define PIO_TNCR_TXNCTR_Pos 0
#define PIO_TNCR_TXNCTR_Msk (0xffffu << PIO_TNCR_TXNCTR_Pos) /**< \brief (PIO_TNCR) Transmit Counter Next */
#define PIO_TNCR_TXNCTR(value) ((PIO_TNCR_TXNCTR_Msk & ((value) << PIO_TNCR_TXNCTR_Pos)))
/* -------- PIO_PTCR : (PIO Offset: 0x188) Transfer Control Register -------- */
#define PIO_PTCR_RXTEN (0x1u << 0) /**< \brief (PIO_PTCR) Receiver Transfer Enable */
#define PIO_PTCR_RXTDIS (0x1u << 1) /**< \brief (PIO_PTCR) Receiver Transfer Disable */
#define PIO_PTCR_TXTEN (0x1u << 8) /**< \brief (PIO_PTCR) Transmitter Transfer Enable */
#define PIO_PTCR_TXTDIS (0x1u << 9) /**< \brief (PIO_PTCR) Transmitter Transfer Disable */
/* -------- PIO_PTSR : (PIO Offset: 0x18C) Transfer Status Register -------- */
#define PIO_PTSR_RXTEN (0x1u << 0) /**< \brief (PIO_PTSR) Receiver Transfer Enable */
#define PIO_PTSR_TXTEN (0x1u << 8) /**< \brief (PIO_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Power Management Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_PMC Power Management Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Pmc hardware registers */
typedef struct {
  WoReg PMC_SCER;      /**< \brief (Pmc Offset: 0x0000) System Clock Enable Register */
  WoReg PMC_SCDR;      /**< \brief (Pmc Offset: 0x0004) System Clock Disable Register */
  RoReg PMC_SCSR;      /**< \brief (Pmc Offset: 0x0008) System Clock Status Register */
  RoReg Reserved1[1];
  WoReg PMC_PCER0;     /**< \brief (Pmc Offset: 0x0010) Peripheral Clock Enable Register 0 */
  WoReg PMC_PCDR0;     /**< \brief (Pmc Offset: 0x0014) Peripheral Clock Disable Register 0 */
  RoReg PMC_PCSR0;     /**< \brief (Pmc Offset: 0x0018) Peripheral Clock Status Register 0 */
  RoReg Reserved2[1];
  RwReg CKGR_MOR;      /**< \brief (Pmc Offset: 0x0020) Main Oscillator Register */
  RoReg CKGR_MCFR;     /**< \brief (Pmc Offset: 0x0024) Main Clock Frequency Register */
  RwReg CKGR_PLLAR;    /**< \brief (Pmc Offset: 0x0028) PLLA Register */
  RwReg CKGR_PLLBR;    /**< \brief (Pmc Offset: 0x002C) PLLB Register */
  RwReg PMC_MCKR;      /**< \brief (Pmc Offset: 0x0030) Master Clock Register */
  RoReg Reserved3[1];
  RwReg PMC_USB;       /**< \brief (Pmc Offset: 0x0038) USB Clock Register */
  RoReg Reserved4[1];
  RwReg PMC_PCK[3];    /**< \brief (Pmc Offset: 0x0040) Programmable Clock 0 Register */
  RoReg Reserved5[5];
  WoReg PMC_IER;       /**< \brief (Pmc Offset: 0x0060) Interrupt Enable Register */
  WoReg PMC_IDR;       /**< \brief (Pmc Offset: 0x0064) Interrupt Disable Register */
  RoReg PMC_SR;        /**< \brief (Pmc Offset: 0x0068) Status Register */
  RoReg PMC_IMR;       /**< \brief (Pmc Offset: 0x006C) Interrupt Mask Register */
  RwReg PMC_FSMR;      /**< \brief (Pmc Offset: 0x0070) Fast Startup Mode Register */
  RwReg PMC_FSPR;      /**< \brief (Pmc Offset: 0x0074) Fast Startup Polarity Register */
  WoReg PMC_FOCR;      /**< \brief (Pmc Offset: 0x0078) Fault Output Clear Register */
  RoReg Reserved6[26];
  RwReg PMC_WPMR;      /**< \brief (Pmc Offset: 0x00E4) Write Protect Mode Register */
  RoReg PMC_WPSR;      /**< \brief (Pmc Offset: 0x00E8) Write Protect Status Register */
  RoReg Reserved7[5];
  WoReg PMC_PCER1;     /**< \brief (Pmc Offset: 0x0100) Peripheral Clock Enable Register 1 */
  WoReg PMC_PCDR1;     /**< \brief (Pmc Offset: 0x0104) Peripheral Clock Disable Register 1 */
  RoReg PMC_PCSR1;     /**< \brief (Pmc Offset: 0x0108) Peripheral Clock Status Register 1 */
  RoReg Reserved8[1];
  RwReg PMC_OCR;       /**< \brief (Pmc Offset: 0x0110) Oscillator Calibration Register */
} Pmc;
#endif /* __ASSEMBLY__ */
/* -------- PMC_SCER : (PMC Offset: 0x0000) System Clock Enable Register -------- */
#define PMC_SCER_UDP (0x1u << 7) /**< \brief (PMC_SCER) USB Device Port Clock Enable */
#define PMC_SCER_PCK0 (0x1u << 8) /**< \brief (PMC_SCER) Programmable Clock 0 Output Enable */
#define PMC_SCER_PCK1 (0x1u << 9) /**< \brief (PMC_SCER) Programmable Clock 1 Output Enable */
#define PMC_SCER_PCK2 (0x1u << 10) /**< \brief (PMC_SCER) Programmable Clock 2 Output Enable */
/* -------- PMC_SCDR : (PMC Offset: 0x0004) System Clock Disable Register -------- */
#define PMC_SCDR_UDP (0x1u << 7) /**< \brief (PMC_SCDR) USB Device Port Clock Disable */
#define PMC_SCDR_PCK0 (0x1u << 8) /**< \brief (PMC_SCDR) Programmable Clock 0 Output Disable */
#define PMC_SCDR_PCK1 (0x1u << 9) /**< \brief (PMC_SCDR) Programmable Clock 1 Output Disable */
#define PMC_SCDR_PCK2 (0x1u << 10) /**< \brief (PMC_SCDR) Programmable Clock 2 Output Disable */
/* -------- PMC_SCSR : (PMC Offset: 0x0008) System Clock Status Register -------- */
#define PMC_SCSR_UDP (0x1u << 7) /**< \brief (PMC_SCSR) USB Device Port Clock Status */
#define PMC_SCSR_PCK0 (0x1u << 8) /**< \brief (PMC_SCSR) Programmable Clock 0 Output Status */
#define PMC_SCSR_PCK1 (0x1u << 9) /**< \brief (PMC_SCSR) Programmable Clock 1 Output Status */
#define PMC_SCSR_PCK2 (0x1u << 10) /**< \brief (PMC_SCSR) Programmable Clock 2 Output Status */
/* -------- PMC_PCER0 : (PMC Offset: 0x0010) Peripheral Clock Enable Register 0 -------- */
#define PMC_PCER0_PID2 (0x1u << 2) /**< \brief (PMC_PCER0) Peripheral Clock 2 Enable */
#define PMC_PCER0_PID3 (0x1u << 3) /**< \brief (PMC_PCER0) Peripheral Clock 3 Enable */
#define PMC_PCER0_PID4 (0x1u << 4) /**< \brief (PMC_PCER0) Peripheral Clock 4 Enable */
#define PMC_PCER0_PID5 (0x1u << 5) /**< \brief (PMC_PCER0) Peripheral Clock 5 Enable */
#define PMC_PCER0_PID6 (0x1u << 6) /**< \brief (PMC_PCER0) Peripheral Clock 6 Enable */
#define PMC_PCER0_PID7 (0x1u << 7) /**< \brief (PMC_PCER0) Peripheral Clock 7 Enable */
#define PMC_PCER0_PID8 (0x1u << 8) /**< \brief (PMC_PCER0) Peripheral Clock 8 Enable */
#define PMC_PCER0_PID9 (0x1u << 9) /**< \brief (PMC_PCER0) Peripheral Clock 9 Enable */
#define PMC_PCER0_PID10 (0x1u << 10) /**< \brief (PMC_PCER0) Peripheral Clock 10 Enable */
#define PMC_PCER0_PID11 (0x1u << 11) /**< \brief (PMC_PCER0) Peripheral Clock 11 Enable */
#define PMC_PCER0_PID12 (0x1u << 12) /**< \brief (PMC_PCER0) Peripheral Clock 12 Enable */
#define PMC_PCER0_PID13 (0x1u << 13) /**< \brief (PMC_PCER0) Peripheral Clock 13 Enable */
#define PMC_PCER0_PID14 (0x1u << 14) /**< \brief (PMC_PCER0) Peripheral Clock 14 Enable */
#define PMC_PCER0_PID15 (0x1u << 15) /**< \brief (PMC_PCER0) Peripheral Clock 15 Enable */
#define PMC_PCER0_PID16 (0x1u << 16) /**< \brief (PMC_PCER0) Peripheral Clock 16 Enable */
#define PMC_PCER0_PID17 (0x1u << 17) /**< \brief (PMC_PCER0) Peripheral Clock 17 Enable */
#define PMC_PCER0_PID18 (0x1u << 18) /**< \brief (PMC_PCER0) Peripheral Clock 18 Enable */
#define PMC_PCER0_PID19 (0x1u << 19) /**< \brief (PMC_PCER0) Peripheral Clock 19 Enable */
#define PMC_PCER0_PID20 (0x1u << 20) /**< \brief (PMC_PCER0) Peripheral Clock 20 Enable */
#define PMC_PCER0_PID21 (0x1u << 21) /**< \brief (PMC_PCER0) Peripheral Clock 21 Enable */
#define PMC_PCER0_PID22 (0x1u << 22) /**< \brief (PMC_PCER0) Peripheral Clock 22 Enable */
#define PMC_PCER0_PID23 (0x1u << 23) /**< \brief (PMC_PCER0) Peripheral Clock 23 Enable */
#define PMC_PCER0_PID24 (0x1u << 24) /**< \brief (PMC_PCER0) Peripheral Clock 24 Enable */
#define PMC_PCER0_PID25 (0x1u << 25) /**< \brief (PMC_PCER0) Peripheral Clock 25 Enable */
#define PMC_PCER0_PID26 (0x1u << 26) /**< \brief (PMC_PCER0) Peripheral Clock 26 Enable */
#define PMC_PCER0_PID27 (0x1u << 27) /**< \brief (PMC_PCER0) Peripheral Clock 27 Enable */
#define PMC_PCER0_PID28 (0x1u << 28) /**< \brief (PMC_PCER0) Peripheral Clock 28 Enable */
#define PMC_PCER0_PID29 (0x1u << 29) /**< \brief (PMC_PCER0) Peripheral Clock 29 Enable */
#define PMC_PCER0_PID30 (0x1u << 30) /**< \brief (PMC_PCER0) Peripheral Clock 30 Enable */
#define PMC_PCER0_PID31 (0x1u << 31) /**< \brief (PMC_PCER0) Peripheral Clock 31 Enable */
/* -------- PMC_PCDR0 : (PMC Offset: 0x0014) Peripheral Clock Disable Register 0 -------- */
#define PMC_PCDR0_PID2 (0x1u << 2) /**< \brief (PMC_PCDR0) Peripheral Clock 2 Disable */
#define PMC_PCDR0_PID3 (0x1u << 3) /**< \brief (PMC_PCDR0) Peripheral Clock 3 Disable */
#define PMC_PCDR0_PID4 (0x1u << 4) /**< \brief (PMC_PCDR0) Peripheral Clock 4 Disable */
#define PMC_PCDR0_PID5 (0x1u << 5) /**< \brief (PMC_PCDR0) Peripheral Clock 5 Disable */
#define PMC_PCDR0_PID6 (0x1u << 6) /**< \brief (PMC_PCDR0) Peripheral Clock 6 Disable */
#define PMC_PCDR0_PID7 (0x1u << 7) /**< \brief (PMC_PCDR0) Peripheral Clock 7 Disable */
#define PMC_PCDR0_PID8 (0x1u << 8) /**< \brief (PMC_PCDR0) Peripheral Clock 8 Disable */
#define PMC_PCDR0_PID9 (0x1u << 9) /**< \brief (PMC_PCDR0) Peripheral Clock 9 Disable */
#define PMC_PCDR0_PID10 (0x1u << 10) /**< \brief (PMC_PCDR0) Peripheral Clock 10 Disable */
#define PMC_PCDR0_PID11 (0x1u << 11) /**< \brief (PMC_PCDR0) Peripheral Clock 11 Disable */
#define PMC_PCDR0_PID12 (0x1u << 12) /**< \brief (PMC_PCDR0) Peripheral Clock 12 Disable */
#define PMC_PCDR0_PID13 (0x1u << 13) /**< \brief (PMC_PCDR0) Peripheral Clock 13 Disable */
#define PMC_PCDR0_PID14 (0x1u << 14) /**< \brief (PMC_PCDR0) Peripheral Clock 14 Disable */
#define PMC_PCDR0_PID15 (0x1u << 15) /**< \brief (PMC_PCDR0) Peripheral Clock 15 Disable */
#define PMC_PCDR0_PID16 (0x1u << 16) /**< \brief (PMC_PCDR0) Peripheral Clock 16 Disable */
#define PMC_PCDR0_PID17 (0x1u << 17) /**< \brief (PMC_PCDR0) Peripheral Clock 17 Disable */
#define PMC_PCDR0_PID18 (0x1u << 18) /**< \brief (PMC_PCDR0) Peripheral Clock 18 Disable */
#define PMC_PCDR0_PID19 (0x1u << 19) /**< \brief (PMC_PCDR0) Peripheral Clock 19 Disable */
#define PMC_PCDR0_PID20 (0x1u << 20) /**< \brief (PMC_PCDR0) Peripheral Clock 20 Disable */
#define PMC_PCDR0_PID21 (0x1u << 21) /**< \brief (PMC_PCDR0) Peripheral Clock 21 Disable */
#define PMC_PCDR0_PID22 (0x1u << 22) /**< \brief (PMC_PCDR0) Peripheral Clock 22 Disable */
#define PMC_PCDR0_PID23 (0x1u << 23) /**< \brief (PMC_PCDR0) Peripheral Clock 23 Disable */
#define PMC_PCDR0_PID24 (0x1u << 24) /**< \brief (PMC_PCDR0) Peripheral Clock 24 Disable */
#define PMC_PCDR0_PID25 (0x1u << 25) /**< \brief (PMC_PCDR0) Peripheral Clock 25 Disable */
#define PMC_PCDR0_PID26 (0x1u << 26) /**< \brief (PMC_PCDR0) Peripheral Clock 26 Disable */
#define PMC_PCDR0_PID27 (0x1u << 27) /**< \brief (PMC_PCDR0) Peripheral Clock 27 Disable */
#define PMC_PCDR0_PID28 (0x1u << 28) /**< \brief (PMC_PCDR0) Peripheral Clock 28 Disable */
#define PMC_PCDR0_PID29 (0x1u << 29) /**< \brief (PMC_PCDR0) Peripheral Clock 29 Disable */
#define PMC_PCDR0_PID30 (0x1u << 30) /**< \brief (PMC_PCDR0) Peripheral Clock 30 Disable */
#define PMC_PCDR0_PID31 (0x1u << 31) /**< \brief (PMC_PCDR0) Peripheral Clock 31 Disable */
/* -------- PMC_PCSR0 : (PMC Offset: 0x0018) Peripheral Clock Status Register 0 -------- */
#define PMC_PCSR0_PID2 (0x1u << 2) /**< \brief (PMC_PCSR0) Peripheral Clock 2 Status */
#define PMC_PCSR0_PID3 (0x1u << 3) /**< \brief (PMC_PCSR0) Peripheral Clock 3 Status */
#define PMC_PCSR0_PID4 (0x1u << 4) /**< \brief (PMC_PCSR0) Peripheral Clock 4 Status */
#define PMC_PCSR0_PID5 (0x1u << 5) /**< \brief (PMC_PCSR0) Peripheral Clock 5 Status */
#define PMC_PCSR0_PID6 (0x1u << 6) /**< \brief (PMC_PCSR0) Peripheral Clock 6 Status */
#define PMC_PCSR0_PID7 (0x1u << 7) /**< \brief (PMC_PCSR0) Peripheral Clock 7 Status */
#define PMC_PCSR0_PID8 (0x1u << 8) /**< \brief (PMC_PCSR0) Peripheral Clock 8 Status */
#define PMC_PCSR0_PID9 (0x1u << 9) /**< \brief (PMC_PCSR0) Peripheral Clock 9 Status */
#define PMC_PCSR0_PID10 (0x1u << 10) /**< \brief (PMC_PCSR0) Peripheral Clock 10 Status */
#define PMC_PCSR0_PID11 (0x1u << 11) /**< \brief (PMC_PCSR0) Peripheral Clock 11 Status */
#define PMC_PCSR0_PID12 (0x1u << 12) /**< \brief (PMC_PCSR0) Peripheral Clock 12 Status */
#define PMC_PCSR0_PID13 (0x1u << 13) /**< \brief (PMC_PCSR0) Peripheral Clock 13 Status */
#define PMC_PCSR0_PID14 (0x1u << 14) /**< \brief (PMC_PCSR0) Peripheral Clock 14 Status */
#define PMC_PCSR0_PID15 (0x1u << 15) /**< \brief (PMC_PCSR0) Peripheral Clock 15 Status */
#define PMC_PCSR0_PID16 (0x1u << 16) /**< \brief (PMC_PCSR0) Peripheral Clock 16 Status */
#define PMC_PCSR0_PID17 (0x1u << 17) /**< \brief (PMC_PCSR0) Peripheral Clock 17 Status */
#define PMC_PCSR0_PID18 (0x1u << 18) /**< \brief (PMC_PCSR0) Peripheral Clock 18 Status */
#define PMC_PCSR0_PID19 (0x1u << 19) /**< \brief (PMC_PCSR0) Peripheral Clock 19 Status */
#define PMC_PCSR0_PID20 (0x1u << 20) /**< \brief (PMC_PCSR0) Peripheral Clock 20 Status */
#define PMC_PCSR0_PID21 (0x1u << 21) /**< \brief (PMC_PCSR0) Peripheral Clock 21 Status */
#define PMC_PCSR0_PID22 (0x1u << 22) /**< \brief (PMC_PCSR0) Peripheral Clock 22 Status */
#define PMC_PCSR0_PID23 (0x1u << 23) /**< \brief (PMC_PCSR0) Peripheral Clock 23 Status */
#define PMC_PCSR0_PID24 (0x1u << 24) /**< \brief (PMC_PCSR0) Peripheral Clock 24 Status */
#define PMC_PCSR0_PID25 (0x1u << 25) /**< \brief (PMC_PCSR0) Peripheral Clock 25 Status */
#define PMC_PCSR0_PID26 (0x1u << 26) /**< \brief (PMC_PCSR0) Peripheral Clock 26 Status */
#define PMC_PCSR0_PID27 (0x1u << 27) /**< \brief (PMC_PCSR0) Peripheral Clock 27 Status */
#define PMC_PCSR0_PID28 (0x1u << 28) /**< \brief (PMC_PCSR0) Peripheral Clock 28 Status */
#define PMC_PCSR0_PID29 (0x1u << 29) /**< \brief (PMC_PCSR0) Peripheral Clock 29 Status */
#define PMC_PCSR0_PID30 (0x1u << 30) /**< \brief (PMC_PCSR0) Peripheral Clock 30 Status */
#define PMC_PCSR0_PID31 (0x1u << 31) /**< \brief (PMC_PCSR0) Peripheral Clock 31 Status */
/* -------- CKGR_MOR : (PMC Offset: 0x0020) Main Oscillator Register -------- */
#define CKGR_MOR_MOSCXTEN (0x1u << 0) /**< \brief (CKGR_MOR) Main Crystal Oscillator Enable */
#define CKGR_MOR_MOSCXTBY (0x1u << 1) /**< \brief (CKGR_MOR) Main Crystal Oscillator Bypass */
#define CKGR_MOR_WAITMODE (0x1u << 2) /**< \brief (CKGR_MOR) Wait Mode Command */
#define CKGR_MOR_MOSCRCEN (0x1u << 3) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Enable */
#define CKGR_MOR_MOSCRCF_Pos 4
#define CKGR_MOR_MOSCRCF_Msk (0x7u << CKGR_MOR_MOSCRCF_Pos) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Frequency Selection */
#define   CKGR_MOR_MOSCRCF_4MHz (0x0u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 4 MHz (default) */
#define   CKGR_MOR_MOSCRCF_8MHz (0x1u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 8 MHz */
#define   CKGR_MOR_MOSCRCF_12MHz (0x2u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 12 MHz */
#define CKGR_MOR_MOSCXTST_Pos 8
#define CKGR_MOR_MOSCXTST_Msk (0xffu << CKGR_MOR_MOSCXTST_Pos) /**< \brief (CKGR_MOR) Main Crystal Oscillator Start-up Time */
#define CKGR_MOR_MOSCXTST(value) ((CKGR_MOR_MOSCXTST_Msk & ((value) << CKGR_MOR_MOSCXTST_Pos)))
#define CKGR_MOR_KEY_Pos 16
#define CKGR_MOR_KEY_Msk (0xffu << CKGR_MOR_KEY_Pos) /**< \brief (CKGR_MOR) Password */
#define CKGR_MOR_KEY(value) ((CKGR_MOR_KEY_Msk & ((value) << CKGR_MOR_KEY_Pos)))
#define CKGR_MOR_MOSCSEL (0x1u << 24) /**< \brief (CKGR_MOR) Main Oscillator Selection */
#define CKGR_MOR_CFDEN (0x1u << 25) /**< \brief (CKGR_MOR) Clock Failure Detector Enable */
/* -------- CKGR_MCFR : (PMC Offset: 0x0024) Main Clock Frequency Register -------- */
#define CKGR_MCFR_MAINF_Pos 0
#define CKGR_MCFR_MAINF_Msk (0xffffu << CKGR_MCFR_MAINF_Pos) /**< \brief (CKGR_MCFR) Main Clock Frequency */
#define CKGR_MCFR_MAINFRDY (0x1u << 16) /**< \brief (CKGR_MCFR) Main Clock Ready */
/* -------- CKGR_PLLAR : (PMC Offset: 0x0028) PLLA Register -------- */
#define CKGR_PLLAR_DIVA_Pos 0
#define CKGR_PLLAR_DIVA_Msk (0xffu << CKGR_PLLAR_DIVA_Pos) /**< \brief (CKGR_PLLAR) Divider */
#define CKGR_PLLAR_DIVA(value) ((CKGR_PLLAR_DIVA_Msk & ((value) << CKGR_PLLAR_DIVA_Pos)))
#define CKGR_PLLAR_PLLACOUNT_Pos 8
#define CKGR_PLLAR_PLLACOUNT_Msk (0x3fu << CKGR_PLLAR_PLLACOUNT_Pos) /**< \brief (CKGR_PLLAR) PLLA Counter */
#define CKGR_PLLAR_PLLACOUNT(value) ((CKGR_PLLAR_PLLACOUNT_Msk & ((value) << CKGR_PLLAR_PLLACOUNT_Pos)))
#define CKGR_PLLAR_MULA_Pos 16
#define CKGR_PLLAR_MULA_Msk (0x7ffu << CKGR_PLLAR_MULA_Pos) /**< \brief (CKGR_PLLAR) PLLA Multiplier */
#define CKGR_PLLAR_MULA(value) ((CKGR_PLLAR_MULA_Msk & ((value) << CKGR_PLLAR_MULA_Pos)))
#define CKGR_PLLAR_STUCKTO1 (0x1u << 29) /**< \brief (CKGR_PLLAR)  */
/* -------- CKGR_PLLBR : (PMC Offset: 0x002C) PLLB Register -------- */
#define CKGR_PLLBR_DIVB_Pos 0
#define CKGR_PLLBR_DIVB_Msk (0xffu << CKGR_PLLBR_DIVB_Pos) /**< \brief (CKGR_PLLBR) Divider */
#define CKGR_PLLBR_DIVB(value) ((CKGR_PLLBR_DIVB_Msk & ((value) << CKGR_PLLBR_DIVB_Pos)))
#define CKGR_PLLBR_PLLBCOUNT_Pos 8
#define CKGR_PLLBR_PLLBCOUNT_Msk (0x3fu << CKGR_PLLBR_PLLBCOUNT_Pos) /**< \brief (CKGR_PLLBR) PLLB Counter */
#define CKGR_PLLBR_PLLBCOUNT(value) ((CKGR_PLLBR_PLLBCOUNT_Msk & ((value) << CKGR_PLLBR_PLLBCOUNT_Pos)))
#define CKGR_PLLBR_MULB_Pos 16
#define CKGR_PLLBR_MULB_Msk (0x7ffu << CKGR_PLLBR_MULB_Pos) /**< \brief (CKGR_PLLBR) PLLB Multiplier */
#define CKGR_PLLBR_MULB(value) ((CKGR_PLLBR_MULB_Msk & ((value) << CKGR_PLLBR_MULB_Pos)))
/* -------- PMC_MCKR : (PMC Offset: 0x0030) Master Clock Register -------- */
#define PMC_MCKR_CSS_Pos 0
#define PMC_MCKR_CSS_Msk (0x3u << PMC_MCKR_CSS_Pos) /**< \brief (PMC_MCKR) Master Clock Source Selection */
#define   PMC_MCKR_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_MCKR) Slow Clock is selected */
#define   PMC_MCKR_CSS_MAIN_CLK (0x1u << 0) /**< \brief (PMC_MCKR) Main Clock is selected */
#define   PMC_MCKR_CSS_PLLA_CLK (0x2u << 0) /**< \brief (PMC_MCKR) PLLA Clock is selected */
#define   PMC_MCKR_CSS_PLLB_CLK (0x3u << 0) /**< \brief (PMC_MCKR) PLLB Clock is selected */
#define PMC_MCKR_PRES_Pos 4
#define PMC_MCKR_PRES_Msk (0x7u << PMC_MCKR_PRES_Pos) /**< \brief (PMC_MCKR) Processor Clock Prescaler */
#define   PMC_MCKR_PRES_CLK (0x0u << 4) /**< \brief (PMC_MCKR) Selected clock */
#define   PMC_MCKR_PRES_CLK_2 (0x1u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 2 */
#define   PMC_MCKR_PRES_CLK_4 (0x2u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 4 */
#define   PMC_MCKR_PRES_CLK_8 (0x3u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 8 */
#define   PMC_MCKR_PRES_CLK_16 (0x4u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 16 */
#define   PMC_MCKR_PRES_CLK_32 (0x5u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 32 */
#define   PMC_MCKR_PRES_CLK_64 (0x6u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 64 */
#define   PMC_MCKR_PRES_CLK_3 (0x7u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 3 */
#define PMC_MCKR_PLLADIV2 (0x1u << 12) /**< \brief (PMC_MCKR) PLLA Divisor by 2 */
#define PMC_MCKR_PLLBDIV2 (0x1u << 13) /**< \brief (PMC_MCKR) PLLB Divisor by 2 */
/* -------- PMC_USB : (PMC Offset: 0x0038) USB Clock Register -------- */
#define PMC_USB_USBS (0x1u << 0) /**< \brief (PMC_USB) USB Input Clock Selection */
#define PMC_USB_USBDIV_Pos 8
#define PMC_USB_USBDIV_Msk (0xfu << PMC_USB_USBDIV_Pos) /**< \brief (PMC_USB) Divider for USB Clock. */
#define PMC_USB_USBDIV(value) ((PMC_USB_USBDIV_Msk & ((value) << PMC_USB_USBDIV_Pos)))
/* -------- PMC_PCK[3] : (PMC Offset: 0x0040) Programmable Clock 0 Register -------- */
#define PMC_PCK_CSS_Pos 0
#define PMC_PCK_CSS_Msk (0x7u << PMC_PCK_CSS_Pos) /**< \brief (PMC_PCK[3]) Master Clock Source Selection */
#define   PMC_PCK_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_PCK[3]) Slow Clock is selected */
#define   PMC_PCK_CSS_MAIN_CLK (0x1u << 0) /**< \brief (PMC_PCK[3]) Main Clock is selected */
#define   PMC_PCK_CSS_PLLA_CLK (0x2u << 0) /**< \brief (PMC_PCK[3]) PLLA Clock is selected */
#define   PMC_PCK_CSS_PLLB_CLK (0x3u << 0) /**< \brief (PMC_PCK[3]) PLLB Clock is selected */
#define   PMC_PCK_CSS_MCK (0x4u << 0) /**< \brief (PMC_PCK[3]) Master Clock is selected */
#define PMC_PCK_PRES_Pos 4
#define PMC_PCK_PRES_Msk (0x7u << PMC_PCK_PRES_Pos) /**< \brief (PMC_PCK[3]) Programmable Clock Prescaler */
#define   PMC_PCK_PRES_CLK (0x0u << 4) /**< \brief (PMC_PCK[3]) Selected clock */
#define   PMC_PCK_PRES_CLK_2 (0x1u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 2 */
#define   PMC_PCK_PRES_CLK_4 (0x2u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 4 */
#define   PMC_PCK_PRES_CLK_8 (0x3u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 8 */
#define   PMC_PCK_PRES_CLK_16 (0x4u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 16 */
#define   PMC_PCK_PRES_CLK_32 (0x5u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 32 */
#define   PMC_PCK_PRES_CLK_64 (0x6u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 64 */
/* -------- PMC_IER : (PMC Offset: 0x0060) Interrupt Enable Register -------- */
#define PMC_IER_MOSCXTS (0x1u << 0) /**< \brief (PMC_IER) Main Crystal Oscillator Status Interrupt Enable */
#define PMC_IER_LOCKA (0x1u << 1) /**< \brief (PMC_IER) PLLA Lock Interrupt Enable */
#define PMC_IER_LOCKB (0x1u << 2) /**< \brief (PMC_IER) PLLB Lock Interrupt Enable */
#define PMC_IER_MCKRDY (0x1u << 3) /**< \brief (PMC_IER) Master Clock Ready Interrupt Enable */
#define PMC_IER_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IER) Programmable Clock Ready 0 Interrupt Enable */
#define PMC_IER_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IER) Programmable Clock Ready 1 Interrupt Enable */
#define PMC_IER_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IER) Programmable Clock Ready 2 Interrupt Enable */
#define PMC_IER_MOSCSELS (0x1u << 16) /**< \brief (PMC_IER) Main Oscillator Selection Status Interrupt Enable */
#define PMC_IER_MOSCRCS (0x1u << 17) /**< \brief (PMC_IER) Main On-Chip RC Status Interrupt Enable */
#define PMC_IER_CFDEV (0x1u << 18) /**< \brief (PMC_IER) Clock Failure Detector Event Interrupt Enable */
/* -------- PMC_IDR : (PMC Offset: 0x0064) Interrupt Disable Register -------- */
#define PMC_IDR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable */
#define PMC_IDR_LOCKA (0x1u << 1) /**< \brief (PMC_IDR) PLLA Lock Interrupt Disable */
#define PMC_IDR_LOCKB (0x1u << 2) /**< \brief (PMC_IDR) PLLB Lock Interrupt Disable */
#define PMC_IDR_MCKRDY (0x1u << 3) /**< \brief (PMC_IDR) Master Clock Ready Interrupt Disable */
#define PMC_IDR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable */
#define PMC_IDR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable */
#define PMC_IDR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IDR) Programmable Clock Ready 2 Interrupt Disable */
#define PMC_IDR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IDR) Main Oscillator Selection Status Interrupt Disable */
#define PMC_IDR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IDR) Main On-Chip RC Status Interrupt Disable */
#define PMC_IDR_CFDEV (0x1u << 18) /**< \brief (PMC_IDR) Clock Failure Detector Event Interrupt Disable */
/* -------- PMC_SR : (PMC Offset: 0x0068) Status Register -------- */
#define PMC_SR_MOSCXTS (0x1u << 0) /**< \brief (PMC_SR) Main XTAL Oscillator Status */
#define PMC_SR_LOCKA (0x1u << 1) /**< \brief (PMC_SR) PLLA Lock Status */
#define PMC_SR_LOCKB (0x1u << 2) /**< \brief (PMC_SR) PLLB Lock Status */
#define PMC_SR_MCKRDY (0x1u << 3) /**< \brief (PMC_SR) Master Clock Status */
#define PMC_SR_OSCSELS (0x1u << 7) /**< \brief (PMC_SR) Slow Clock Oscillator Selection */
#define PMC_SR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_MOSCSELS (0x1u << 16) /**< \brief (PMC_SR) Main Oscillator Selection Status */
#define PMC_SR_MOSCRCS (0x1u << 17) /**< \brief (PMC_SR) Main On-Chip RC Oscillator Status */
#define PMC_SR_CFDEV (0x1u << 18) /**< \brief (PMC_SR) Clock Failure Detector Event */
#define PMC_SR_CFDS (0x1u << 19) /**< \brief (PMC_SR) Clock Failure Detector Status */
#define PMC_SR_FOS (0x1u << 20) /**< \brief (PMC_SR) Clock Failure Detector Fault Output Status */
/* -------- PMC_IMR : (PMC Offset: 0x006C) Interrupt Mask Register -------- */
#define PMC_IMR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask */
#define PMC_IMR_LOCKA (0x1u << 1) /**< \brief (PMC_IMR) PLLA Lock Interrupt Mask */
#define PMC_IMR_LOCKB (0x1u << 2) /**< \brief (PMC_IMR) PLLB Lock Interrupt Mask */
#define PMC_IMR_MCKRDY (0x1u << 3) /**< \brief (PMC_IMR) Master Clock Ready Interrupt Mask */
#define PMC_IMR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask */
#define PMC_IMR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask */
#define PMC_IMR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IMR) Programmable Clock Ready 2 Interrupt Mask */
#define PMC_IMR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IMR) Main Oscillator Selection Status Interrupt Mask */
#define PMC_IMR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IMR) Main On-Chip RC Status Interrupt Mask */
#define PMC_IMR_CFDEV (0x1u << 18) /**< \brief (PMC_IMR) Clock Failure Detector Event Interrupt Mask */
/* -------- PMC_FSMR : (PMC Offset: 0x0070) Fast Startup Mode Register -------- */
#define PMC_FSMR_FSTT0 (0x1u << 0) /**< \brief (PMC_FSMR) Fast Startup Input Enable 0 */
#define PMC_FSMR_FSTT1 (0x1u << 1) /**< \brief (PMC_FSMR) Fast Startup Input Enable 1 */
#define PMC_FSMR_FSTT2 (0x1u << 2) /**< \brief (PMC_FSMR) Fast Startup Input Enable 2 */
#define PMC_FSMR_FSTT3 (0x1u << 3) /**< \brief (PMC_FSMR) Fast Startup Input Enable 3 */
#define PMC_FSMR_FSTT4 (0x1u << 4) /**< \brief (PMC_FSMR) Fast Startup Input Enable 4 */
#define PMC_FSMR_FSTT5 (0x1u << 5) /**< \brief (PMC_FSMR) Fast Startup Input Enable 5 */
#define PMC_FSMR_FSTT6 (0x1u << 6) /**< \brief (PMC_FSMR) Fast Startup Input Enable 6 */
#define PMC_FSMR_FSTT7 (0x1u << 7) /**< \brief (PMC_FSMR) Fast Startup Input Enable 7 */
#define PMC_FSMR_FSTT8 (0x1u << 8) /**< \brief (PMC_FSMR) Fast Startup Input Enable 8 */
#define PMC_FSMR_FSTT9 (0x1u << 9) /**< \brief (PMC_FSMR) Fast Startup Input Enable 9 */
#define PMC_FSMR_FSTT10 (0x1u << 10) /**< \brief (PMC_FSMR) Fast Startup Input Enable 10 */
#define PMC_FSMR_FSTT11 (0x1u << 11) /**< \brief (PMC_FSMR) Fast Startup Input Enable 11 */
#define PMC_FSMR_FSTT12 (0x1u << 12) /**< \brief (PMC_FSMR) Fast Startup Input Enable 12 */
#define PMC_FSMR_FSTT13 (0x1u << 13) /**< \brief (PMC_FSMR) Fast Startup Input Enable 13 */
#define PMC_FSMR_FSTT14 (0x1u << 14) /**< \brief (PMC_FSMR) Fast Startup Input Enable 14 */
#define PMC_FSMR_FSTT15 (0x1u << 15) /**< \brief (PMC_FSMR) Fast Startup Input Enable 15 */
#define PMC_FSMR_RTTAL (0x1u << 16) /**< \brief (PMC_FSMR) RTT Alarm Enable */
#define PMC_FSMR_RTCAL (0x1u << 17) /**< \brief (PMC_FSMR) RTC Alarm Enable */
#define PMC_FSMR_USBAL (0x1u << 18) /**< \brief (PMC_FSMR) USB Alarm Enable */
#define PMC_FSMR_LPM (0x1u << 20) /**< \brief (PMC_FSMR) Low Power Mode */
/* -------- PMC_FSPR : (PMC Offset: 0x0074) Fast Startup Polarity Register -------- */
#define PMC_FSPR_FSTP0 (0x1u << 0) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP1 (0x1u << 1) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP2 (0x1u << 2) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP3 (0x1u << 3) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP4 (0x1u << 4) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP5 (0x1u << 5) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP6 (0x1u << 6) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP7 (0x1u << 7) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP8 (0x1u << 8) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP9 (0x1u << 9) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP10 (0x1u << 10) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP11 (0x1u << 11) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP12 (0x1u << 12) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP13 (0x1u << 13) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP14 (0x1u << 14) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP15 (0x1u << 15) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
/* -------- PMC_FOCR : (PMC Offset: 0x0078) Fault Output Clear Register -------- */
#define PMC_FOCR_FOCLR (0x1u << 0) /**< \brief (PMC_FOCR) Fault Output Clear */
/* -------- PMC_WPMR : (PMC Offset: 0x00E4) Write Protect Mode Register -------- */
#define PMC_WPMR_WPEN (0x1u << 0) /**< \brief (PMC_WPMR) Write Protect Enable */
#define PMC_WPMR_WPKEY_Pos 8
#define PMC_WPMR_WPKEY_Msk (0xffffffu << PMC_WPMR_WPKEY_Pos) /**< \brief (PMC_WPMR) Write Protect KEY */
#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))
/* -------- PMC_WPSR : (PMC Offset: 0x00E8) Write Protect Status Register -------- */
#define PMC_WPSR_WPVS (0x1u << 0) /**< \brief (PMC_WPSR) Write Protect Violation Status */
#define PMC_WPSR_WPVSRC_Pos 8
#define PMC_WPSR_WPVSRC_Msk (0xffffu << PMC_WPSR_WPVSRC_Pos) /**< \brief (PMC_WPSR) Write Protect Violation Source */
/* -------- PMC_PCER1 : (PMC Offset: 0x0100) Peripheral Clock Enable Register 1 -------- */
#define PMC_PCER1_PID32 (0x1u << 0) /**< \brief (PMC_PCER1) Peripheral Clock 32 Enable */
#define PMC_PCER1_PID33 (0x1u << 1) /**< \brief (PMC_PCER1) Peripheral Clock 33 Enable */
#define PMC_PCER1_PID34 (0x1u << 2) /**< \brief (PMC_PCER1) Peripheral Clock 34 Enable */
#define PMC_PCER1_PID35 (0x1u << 3) /**< \brief (PMC_PCER1) Peripheral Clock 35 Enable */
#define PMC_PCER1_PID36 (0x1u << 4) /**< \brief (PMC_PCER1) Peripheral Clock 36 Enable */
#define PMC_PCER1_PID37 (0x1u << 5) /**< \brief (PMC_PCER1) Peripheral Clock 37 Enable */
#define PMC_PCER1_PID38 (0x1u << 6) /**< \brief (PMC_PCER1) Peripheral Clock 38 Enable */
#define PMC_PCER1_PID39 (0x1u << 7) /**< \brief (PMC_PCER1) Peripheral Clock 39 Enable */
#define PMC_PCER1_PID40 (0x1u << 8) /**< \brief (PMC_PCER1) Peripheral Clock 40 Enable */
#define PMC_PCER1_PID41 (0x1u << 9) /**< \brief (PMC_PCER1) Peripheral Clock 41 Enable */
#define PMC_PCER1_PID42 (0x1u << 10) /**< \brief (PMC_PCER1) Peripheral Clock 42 Enable */
#define PMC_PCER1_PID43 (0x1u << 11) /**< \brief (PMC_PCER1) Peripheral Clock 43 Enable */
#define PMC_PCER1_PID44 (0x1u << 12) /**< \brief (PMC_PCER1) Peripheral Clock 44 Enable */
#define PMC_PCER1_PID45 (0x1u << 13) /**< \brief (PMC_PCER1) Peripheral Clock 45 Enable */
#define PMC_PCER1_PID46 (0x1u << 14) /**< \brief (PMC_PCER1) Peripheral Clock 46 Enable */
#define PMC_PCER1_PID47 (0x1u << 15) /**< \brief (PMC_PCER1) Peripheral Clock 47 Enable */
#define PMC_PCER1_PID48 (0x1u << 16) /**< \brief (PMC_PCER1) Peripheral Clock 48 Enable */
#define PMC_PCER1_PID49 (0x1u << 17) /**< \brief (PMC_PCER1) Peripheral Clock 49 Enable */
#define PMC_PCER1_PID50 (0x1u << 18) /**< \brief (PMC_PCER1) Peripheral Clock 50 Enable */
#define PMC_PCER1_PID51 (0x1u << 19) /**< \brief (PMC_PCER1) Peripheral Clock 51 Enable */
#define PMC_PCER1_PID52 (0x1u << 20) /**< \brief (PMC_PCER1) Peripheral Clock 52 Enable */
#define PMC_PCER1_PID53 (0x1u << 21) /**< \brief (PMC_PCER1) Peripheral Clock 53 Enable */
#define PMC_PCER1_PID54 (0x1u << 22) /**< \brief (PMC_PCER1) Peripheral Clock 54 Enable */
#define PMC_PCER1_PID55 (0x1u << 23) /**< \brief (PMC_PCER1) Peripheral Clock 55 Enable */
#define PMC_PCER1_PID56 (0x1u << 24) /**< \brief (PMC_PCER1) Peripheral Clock 56 Enable */
#define PMC_PCER1_PID57 (0x1u << 25) /**< \brief (PMC_PCER1) Peripheral Clock 57 Enable */
#define PMC_PCER1_PID58 (0x1u << 26) /**< \brief (PMC_PCER1) Peripheral Clock 58 Enable */
#define PMC_PCER1_PID59 (0x1u << 27) /**< \brief (PMC_PCER1) Peripheral Clock 59 Enable */
#define PMC_PCER1_PID60 (0x1u << 28) /**< \brief (PMC_PCER1) Peripheral Clock 60 Enable */
#define PMC_PCER1_PID61 (0x1u << 29) /**< \brief (PMC_PCER1) Peripheral Clock 61 Enable */
#define PMC_PCER1_PID62 (0x1u << 30) /**< \brief (PMC_PCER1) Peripheral Clock 62 Enable */
#define PMC_PCER1_PID63 (0x1u << 31) /**< \brief (PMC_PCER1) Peripheral Clock 63 Enable */
/* -------- PMC_PCDR1 : (PMC Offset: 0x0104) Peripheral Clock Disable Register 1 -------- */
#define PMC_PCDR1_PID32 (0x1u << 0) /**< \brief (PMC_PCDR1) Peripheral Clock 32 Disable */
#define PMC_PCDR1_PID33 (0x1u << 1) /**< \brief (PMC_PCDR1) Peripheral Clock 33 Disable */
#define PMC_PCDR1_PID34 (0x1u << 2) /**< \brief (PMC_PCDR1) Peripheral Clock 34 Disable */
#define PMC_PCDR1_PID35 (0x1u << 3) /**< \brief (PMC_PCDR1) Peripheral Clock 35 Disable */
#define PMC_PCDR1_PID36 (0x1u << 4) /**< \brief (PMC_PCDR1) Peripheral Clock 36 Disable */
#define PMC_PCDR1_PID37 (0x1u << 5) /**< \brief (PMC_PCDR1) Peripheral Clock 37 Disable */
#define PMC_PCDR1_PID38 (0x1u << 6) /**< \brief (PMC_PCDR1) Peripheral Clock 38 Disable */
#define PMC_PCDR1_PID39 (0x1u << 7) /**< \brief (PMC_PCDR1) Peripheral Clock 39 Disable */
#define PMC_PCDR1_PID40 (0x1u << 8) /**< \brief (PMC_PCDR1) Peripheral Clock 40 Disable */
#define PMC_PCDR1_PID41 (0x1u << 9) /**< \brief (PMC_PCDR1) Peripheral Clock 41 Disable */
#define PMC_PCDR1_PID42 (0x1u << 10) /**< \brief (PMC_PCDR1) Peripheral Clock 42 Disable */
#define PMC_PCDR1_PID43 (0x1u << 11) /**< \brief (PMC_PCDR1) Peripheral Clock 43 Disable */
#define PMC_PCDR1_PID44 (0x1u << 12) /**< \brief (PMC_PCDR1) Peripheral Clock 44 Disable */
#define PMC_PCDR1_PID45 (0x1u << 13) /**< \brief (PMC_PCDR1) Peripheral Clock 45 Disable */
#define PMC_PCDR1_PID46 (0x1u << 14) /**< \brief (PMC_PCDR1) Peripheral Clock 46 Disable */
#define PMC_PCDR1_PID47 (0x1u << 15) /**< \brief (PMC_PCDR1) Peripheral Clock 47 Disable */
#define PMC_PCDR1_PID48 (0x1u << 16) /**< \brief (PMC_PCDR1) Peripheral Clock 48 Disable */
#define PMC_PCDR1_PID49 (0x1u << 17) /**< \brief (PMC_PCDR1) Peripheral Clock 49 Disable */
#define PMC_PCDR1_PID50 (0x1u << 18) /**< \brief (PMC_PCDR1) Peripheral Clock 50 Disable */
#define PMC_PCDR1_PID51 (0x1u << 19) /**< \brief (PMC_PCDR1) Peripheral Clock 51 Disable */
#define PMC_PCDR1_PID52 (0x1u << 20) /**< \brief (PMC_PCDR1) Peripheral Clock 52 Disable */
#define PMC_PCDR1_PID53 (0x1u << 21) /**< \brief (PMC_PCDR1) Peripheral Clock 53 Disable */
#define PMC_PCDR1_PID54 (0x1u << 22) /**< \brief (PMC_PCDR1) Peripheral Clock 54 Disable */
#define PMC_PCDR1_PID55 (0x1u << 23) /**< \brief (PMC_PCDR1) Peripheral Clock 55 Disable */
#define PMC_PCDR1_PID56 (0x1u << 24) /**< \brief (PMC_PCDR1) Peripheral Clock 56 Disable */
#define PMC_PCDR1_PID57 (0x1u << 25) /**< \brief (PMC_PCDR1) Peripheral Clock 57 Disable */
#define PMC_PCDR1_PID58 (0x1u << 26) /**< \brief (PMC_PCDR1) Peripheral Clock 58 Disable */
#define PMC_PCDR1_PID59 (0x1u << 27) /**< \brief (PMC_PCDR1) Peripheral Clock 59 Disable */
#define PMC_PCDR1_PID60 (0x1u << 28) /**< \brief (PMC_PCDR1) Peripheral Clock 60 Disable */
#define PMC_PCDR1_PID61 (0x1u << 29) /**< \brief (PMC_PCDR1) Peripheral Clock 61 Disable */
#define PMC_PCDR1_PID62 (0x1u << 30) /**< \brief (PMC_PCDR1) Peripheral Clock 62 Disable */
#define PMC_PCDR1_PID63 (0x1u << 31) /**< \brief (PMC_PCDR1) Peripheral Clock 63 Disable */
/* -------- PMC_PCSR1 : (PMC Offset: 0x0108) Peripheral Clock Status Register 1 -------- */
#define PMC_PCSR1_PID32 (0x1u << 0) /**< \brief (PMC_PCSR1) Peripheral Clock 32 Status */
#define PMC_PCSR1_PID33 (0x1u << 1) /**< \brief (PMC_PCSR1) Peripheral Clock 33 Status */
#define PMC_PCSR1_PID34 (0x1u << 2) /**< \brief (PMC_PCSR1) Peripheral Clock 34 Status */
#define PMC_PCSR1_PID35 (0x1u << 3) /**< \brief (PMC_PCSR1) Peripheral Clock 35 Status */
#define PMC_PCSR1_PID36 (0x1u << 4) /**< \brief (PMC_PCSR1) Peripheral Clock 36 Status */
#define PMC_PCSR1_PID37 (0x1u << 5) /**< \brief (PMC_PCSR1) Peripheral Clock 37 Status */
#define PMC_PCSR1_PID38 (0x1u << 6) /**< \brief (PMC_PCSR1) Peripheral Clock 38 Status */
#define PMC_PCSR1_PID39 (0x1u << 7) /**< \brief (PMC_PCSR1) Peripheral Clock 39 Status */
#define PMC_PCSR1_PID40 (0x1u << 8) /**< \brief (PMC_PCSR1) Peripheral Clock 40 Status */
#define PMC_PCSR1_PID41 (0x1u << 9) /**< \brief (PMC_PCSR1) Peripheral Clock 41 Status */
#define PMC_PCSR1_PID42 (0x1u << 10) /**< \brief (PMC_PCSR1) Peripheral Clock 42 Status */
#define PMC_PCSR1_PID43 (0x1u << 11) /**< \brief (PMC_PCSR1) Peripheral Clock 43 Status */
#define PMC_PCSR1_PID44 (0x1u << 12) /**< \brief (PMC_PCSR1) Peripheral Clock 44 Status */
#define PMC_PCSR1_PID45 (0x1u << 13) /**< \brief (PMC_PCSR1) Peripheral Clock 45 Status */
#define PMC_PCSR1_PID46 (0x1u << 14) /**< \brief (PMC_PCSR1) Peripheral Clock 46 Status */
#define PMC_PCSR1_PID47 (0x1u << 15) /**< \brief (PMC_PCSR1) Peripheral Clock 47 Status */
#define PMC_PCSR1_PID48 (0x1u << 16) /**< \brief (PMC_PCSR1) Peripheral Clock 48 Status */
#define PMC_PCSR1_PID49 (0x1u << 17) /**< \brief (PMC_PCSR1) Peripheral Clock 49 Status */
#define PMC_PCSR1_PID50 (0x1u << 18) /**< \brief (PMC_PCSR1) Peripheral Clock 50 Status */
#define PMC_PCSR1_PID51 (0x1u << 19) /**< \brief (PMC_PCSR1) Peripheral Clock 51 Status */
#define PMC_PCSR1_PID52 (0x1u << 20) /**< \brief (PMC_PCSR1) Peripheral Clock 52 Status */
#define PMC_PCSR1_PID53 (0x1u << 21) /**< \brief (PMC_PCSR1) Peripheral Clock 53 Status */
#define PMC_PCSR1_PID54 (0x1u << 22) /**< \brief (PMC_PCSR1) Peripheral Clock 54 Status */
#define PMC_PCSR1_PID55 (0x1u << 23) /**< \brief (PMC_PCSR1) Peripheral Clock 55 Status */
#define PMC_PCSR1_PID56 (0x1u << 24) /**< \brief (PMC_PCSR1) Peripheral Clock 56 Status */
#define PMC_PCSR1_PID57 (0x1u << 25) /**< \brief (PMC_PCSR1) Peripheral Clock 57 Status */
#define PMC_PCSR1_PID58 (0x1u << 26) /**< \brief (PMC_PCSR1) Peripheral Clock 58 Status */
#define PMC_PCSR1_PID59 (0x1u << 27) /**< \brief (PMC_PCSR1) Peripheral Clock 59 Status */
#define PMC_PCSR1_PID60 (0x1u << 28) /**< \brief (PMC_PCSR1) Peripheral Clock 60 Status */
#define PMC_PCSR1_PID61 (0x1u << 29) /**< \brief (PMC_PCSR1) Peripheral Clock 61 Status */
#define PMC_PCSR1_PID62 (0x1u << 30) /**< \brief (PMC_PCSR1) Peripheral Clock 62 Status */
#define PMC_PCSR1_PID63 (0x1u << 31) /**< \brief (PMC_PCSR1) Peripheral Clock 63 Status */
/* -------- PMC_OCR : (PMC Offset: 0x0110) Oscillator Calibration Register -------- */
#define PMC_OCR_CAL4_Pos 0
#define PMC_OCR_CAL4_Msk (0x7fu << PMC_OCR_CAL4_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 4 Mhz */
#define PMC_OCR_CAL4(value) ((PMC_OCR_CAL4_Msk & ((value) << PMC_OCR_CAL4_Pos)))
#define PMC_OCR_SEL4 (0x1u << 7) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 4 Mhz */
#define PMC_OCR_CAL8_Pos 8
#define PMC_OCR_CAL8_Msk (0x7fu << PMC_OCR_CAL8_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 8 Mhz */
#define PMC_OCR_CAL8(value) ((PMC_OCR_CAL8_Msk & ((value) << PMC_OCR_CAL8_Pos)))
#define PMC_OCR_SEL8 (0x1u << 15) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 8 Mhz */
#define PMC_OCR_CAL12_Pos 16
#define PMC_OCR_CAL12_Msk (0x7fu << PMC_OCR_CAL12_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 12 Mhz */
#define PMC_OCR_CAL12(value) ((PMC_OCR_CAL12_Msk & ((value) << PMC_OCR_CAL12_Pos)))
#define PMC_OCR_SEL12 (0x1u << 23) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 12 Mhz */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Pulse Width Modulation Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_PWM Pulse Width Modulation Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief PwmCh_num hardware registers */
typedef struct {
  RwReg      PWM_CMR;       /**< \brief (PwmCh_num Offset: 0x0) PWM Channel Mode Register */
  RwReg      PWM_CDTY;      /**< \brief (PwmCh_num Offset: 0x4) PWM Channel Duty Cycle Register */
  RwReg      PWM_CDTYUPD;   /**< \brief (PwmCh_num Offset: 0x8) PWM Channel Duty Cycle Update Register */
  RwReg      PWM_CPRD;      /**< \brief (PwmCh_num Offset: 0xC) PWM Channel Period Register */
  RwReg      PWM_CPRDUPD;   /**< \brief (PwmCh_num Offset: 0x10) PWM Channel Period Update Register */
  RwReg      PWM_CCNT;      /**< \brief (PwmCh_num Offset: 0x14) PWM Channel Counter Register */
  RwReg      PWM_DT;        /**< \brief (PwmCh_num Offset: 0x18) PWM Channel Dead Time Register */
  RwReg      PWM_DTUPD;     /**< \brief (PwmCh_num Offset: 0x1C) PWM Channel Dead Time Update Register */
} PwmCh_num;
/** \brief PwmCmp hardware registers */
typedef struct {
  RwReg      PWM_CMPV;      /**< \brief (PwmCmp Offset: 0x0) PWM Comparison 0 Value Register */
  RwReg      PWM_CMPVUPD;   /**< \brief (PwmCmp Offset: 0x4) PWM Comparison 0 Value Update Register */
  RwReg      PWM_CMPM;      /**< \brief (PwmCmp Offset: 0x8) PWM Comparison 0 Mode Register */
  RwReg      PWM_CMPMUPD;   /**< \brief (PwmCmp Offset: 0xC) PWM Comparison 0 Mode Update Register */
} PwmCmp;
/** \brief Pwm hardware registers */
#define PWMCMP_NUMBER 8
#define PWMCH_NUM_NUMBER 4
typedef struct {
  RwReg      PWM_CLK;       /**< \brief (Pwm Offset: 0x00) PWM Clock Register */
  WoReg      PWM_ENA;       /**< \brief (Pwm Offset: 0x04) PWM Enable Register */
  WoReg      PWM_DIS;       /**< \brief (Pwm Offset: 0x08) PWM Disable Register */
  RoReg      PWM_SR;        /**< \brief (Pwm Offset: 0x0C) PWM Status Register */
  WoReg      PWM_IER1;      /**< \brief (Pwm Offset: 0x10) PWM Interrupt Enable Register 1 */
  WoReg      PWM_IDR1;      /**< \brief (Pwm Offset: 0x14) PWM Interrupt Disable Register 1 */
  RoReg      PWM_IMR1;      /**< \brief (Pwm Offset: 0x18) PWM Interrupt Mask Register 1 */
  RoReg      PWM_ISR1;      /**< \brief (Pwm Offset: 0x1C) PWM Interrupt Status Register 1 */
  RwReg      PWM_SCM;       /**< \brief (Pwm Offset: 0x20) PWM Sync Channels Mode Register */
  RoReg      Reserved1[1];
  RwReg      PWM_SCUC;      /**< \brief (Pwm Offset: 0x28) PWM Sync Channels Update Control Register */
  RwReg      PWM_SCUP;      /**< \brief (Pwm Offset: 0x2C) PWM Sync Channels Update Period Register */
  WoReg      PWM_SCUPUPD;   /**< \brief (Pwm Offset: 0x30) PWM Sync Channels Update Period Update Register */
  WoReg      PWM_IER2;      /**< \brief (Pwm Offset: 0x34) PWM Interrupt Enable Register 2 */
  WoReg      PWM_IDR2;      /**< \brief (Pwm Offset: 0x38) PWM Interrupt Disable Register 2 */
  RoReg      PWM_IMR2;      /**< \brief (Pwm Offset: 0x3C) PWM Interrupt Mask Register 2 */
  RoReg      PWM_ISR2;      /**< \brief (Pwm Offset: 0x40) PWM Interrupt Status Register 2 */
  RwReg      PWM_OOV;       /**< \brief (Pwm Offset: 0x44) PWM Output Override Value Register */
  RwReg      PWM_OS;        /**< \brief (Pwm Offset: 0x48) PWM Output Selection Register */
  WoReg      PWM_OSS;       /**< \brief (Pwm Offset: 0x4C) PWM Output Selection Set Register */
  WoReg      PWM_OSC;       /**< \brief (Pwm Offset: 0x50) PWM Output Selection Clear Register */
  WoReg      PWM_OSSUPD;    /**< \brief (Pwm Offset: 0x54) PWM Output Selection Set Update Register */
  WoReg      PWM_OSCUPD;    /**< \brief (Pwm Offset: 0x58) PWM Output Selection Clear Update Register */
  RwReg      PWM_FMR;       /**< \brief (Pwm Offset: 0x5C) PWM Fault Mode Register */
  RoReg      PWM_FSR;       /**< \brief (Pwm Offset: 0x60) PWM Fault Status Register */
  WoReg      PWM_FCR;       /**< \brief (Pwm Offset: 0x64) PWM Fault Clear Register */
  RwReg      PWM_FPV;       /**< \brief (Pwm Offset: 0x68) PWM Fault Protection Value Register */
  RwReg      PWM_FPE;       /**< \brief (Pwm Offset: 0x6C) PWM Fault Protection Enable Register */
  RoReg      Reserved2[3];
  RwReg      PWM_ELMR[2];   /**< \brief (Pwm Offset: 0x7C) PWM Event Line 0 Mode Register */
  RoReg      Reserved3[11];
  RwReg      PWM_SMMR;      /**< \brief (Pwm Offset: 0xB0) PWM Stepper Motor Mode Register */
  RoReg      Reserved4[12];
  WoReg      PWM_WPCR;      /**< \brief (Pwm Offset: 0xE4) PWM Write Protect Control Register */
  RoReg      PWM_WPSR;      /**< \brief (Pwm Offset: 0xE8) PWM Write Protect Status Register */
  RoReg      Reserved5[5];
  RwReg      PWM_RPR;       /**< \brief (Pwm Offset: 0x100) Receive Pointer Register */
  RwReg      PWM_RCR;       /**< \brief (Pwm Offset: 0x104) Receive Counter Register */
  RwReg      PWM_TPR;       /**< \brief (Pwm Offset: 0x108) Transmit Pointer Register */
  RwReg      PWM_TCR;       /**< \brief (Pwm Offset: 0x10C) Transmit Counter Register */
  RwReg      PWM_RNPR;      /**< \brief (Pwm Offset: 0x110) Receive Next Pointer Register */
  RwReg      PWM_RNCR;      /**< \brief (Pwm Offset: 0x114) Receive Next Counter Register */
  RwReg      PWM_TNPR;      /**< \brief (Pwm Offset: 0x118) Transmit Next Pointer Register */
  RwReg      PWM_TNCR;      /**< \brief (Pwm Offset: 0x11C) Transmit Next Counter Register */
  WoReg      PWM_PTCR;      /**< \brief (Pwm Offset: 0x120) Transfer Control Register */
  RoReg      PWM_PTSR;      /**< \brief (Pwm Offset: 0x124) Transfer Status Register */
  RoReg      Reserved6[2];
  PwmCmp     PWM_CMP[PWMCMP_NUMBER]; /**< \brief (Pwm Offset: 0x130) 0 .. 7 */
  RoReg      Reserved7[20];
  PwmCh_num  PWM_CH_NUM[PWMCH_NUM_NUMBER]; /**< \brief (Pwm Offset: 0x200) ch_num = 0 .. 3 */
} Pwm;
#endif /* __ASSEMBLY__ */
/* -------- PWM_CLK : (PWM Offset: 0x00) PWM Clock Register -------- */
#define PWM_CLK_DIVA_Pos 0
#define PWM_CLK_DIVA_Msk (0xffu << PWM_CLK_DIVA_Pos) /**< \brief (PWM_CLK) CLKA, CLKB Divide Factor */
#define PWM_CLK_DIVA(value) ((PWM_CLK_DIVA_Msk & ((value) << PWM_CLK_DIVA_Pos)))
#define PWM_CLK_PREA_Pos 8
#define PWM_CLK_PREA_Msk (0xfu << PWM_CLK_PREA_Pos) /**< \brief (PWM_CLK) CLKA, CLKB Source Clock Selection */
#define PWM_CLK_PREA(value) ((PWM_CLK_PREA_Msk & ((value) << PWM_CLK_PREA_Pos)))
#define PWM_CLK_DIVB_Pos 16
#define PWM_CLK_DIVB_Msk (0xffu << PWM_CLK_DIVB_Pos) /**< \brief (PWM_CLK) CLKA, CLKB Divide Factor */
#define PWM_CLK_DIVB(value) ((PWM_CLK_DIVB_Msk & ((value) << PWM_CLK_DIVB_Pos)))
#define PWM_CLK_PREB_Pos 24
#define PWM_CLK_PREB_Msk (0xfu << PWM_CLK_PREB_Pos) /**< \brief (PWM_CLK) CLKA, CLKB Source Clock Selection */
#define PWM_CLK_PREB(value) ((PWM_CLK_PREB_Msk & ((value) << PWM_CLK_PREB_Pos)))
/* -------- PWM_ENA : (PWM Offset: 0x04) PWM Enable Register -------- */
#define PWM_ENA_CHID0 (0x1u << 0) /**< \brief (PWM_ENA) Channel ID */
#define PWM_ENA_CHID1 (0x1u << 1) /**< \brief (PWM_ENA) Channel ID */
#define PWM_ENA_CHID2 (0x1u << 2) /**< \brief (PWM_ENA) Channel ID */
#define PWM_ENA_CHID3 (0x1u << 3) /**< \brief (PWM_ENA) Channel ID */
/* -------- PWM_DIS : (PWM Offset: 0x08) PWM Disable Register -------- */
#define PWM_DIS_CHID0 (0x1u << 0) /**< \brief (PWM_DIS) Channel ID */
#define PWM_DIS_CHID1 (0x1u << 1) /**< \brief (PWM_DIS) Channel ID */
#define PWM_DIS_CHID2 (0x1u << 2) /**< \brief (PWM_DIS) Channel ID */
#define PWM_DIS_CHID3 (0x1u << 3) /**< \brief (PWM_DIS) Channel ID */
/* -------- PWM_SR : (PWM Offset: 0x0C) PWM Status Register -------- */
#define PWM_SR_CHID0 (0x1u << 0) /**< \brief (PWM_SR) Channel ID */
#define PWM_SR_CHID1 (0x1u << 1) /**< \brief (PWM_SR) Channel ID */
#define PWM_SR_CHID2 (0x1u << 2) /**< \brief (PWM_SR) Channel ID */
#define PWM_SR_CHID3 (0x1u << 3) /**< \brief (PWM_SR) Channel ID */
/* -------- PWM_IER1 : (PWM Offset: 0x10) PWM Interrupt Enable Register 1 -------- */
#define PWM_IER1_CHID0 (0x1u << 0) /**< \brief (PWM_IER1) Counter Event on Channel 0 Interrupt Enable */
#define PWM_IER1_CHID1 (0x1u << 1) /**< \brief (PWM_IER1) Counter Event on Channel 1 Interrupt Enable */
#define PWM_IER1_CHID2 (0x1u << 2) /**< \brief (PWM_IER1) Counter Event on Channel 2 Interrupt Enable */
#define PWM_IER1_CHID3 (0x1u << 3) /**< \brief (PWM_IER1) Counter Event on Channel 3 Interrupt Enable */
#define PWM_IER1_FCHID0 (0x1u << 16) /**< \brief (PWM_IER1) Fault Protection Trigger on Channel 0 Interrupt Enable */
#define PWM_IER1_FCHID1 (0x1u << 17) /**< \brief (PWM_IER1) Fault Protection Trigger on Channel 1 Interrupt Enable */
#define PWM_IER1_FCHID2 (0x1u << 18) /**< \brief (PWM_IER1) Fault Protection Trigger on Channel 2 Interrupt Enable */
#define PWM_IER1_FCHID3 (0x1u << 19) /**< \brief (PWM_IER1) Fault Protection Trigger on Channel 3 Interrupt Enable */
/* -------- PWM_IDR1 : (PWM Offset: 0x14) PWM Interrupt Disable Register 1 -------- */
#define PWM_IDR1_CHID0 (0x1u << 0) /**< \brief (PWM_IDR1) Counter Event on Channel 0 Interrupt Disable */
#define PWM_IDR1_CHID1 (0x1u << 1) /**< \brief (PWM_IDR1) Counter Event on Channel 1 Interrupt Disable */
#define PWM_IDR1_CHID2 (0x1u << 2) /**< \brief (PWM_IDR1) Counter Event on Channel 2 Interrupt Disable */
#define PWM_IDR1_CHID3 (0x1u << 3) /**< \brief (PWM_IDR1) Counter Event on Channel 3 Interrupt Disable */
#define PWM_IDR1_FCHID0 (0x1u << 16) /**< \brief (PWM_IDR1) Fault Protection Trigger on Channel 0 Interrupt Disable */
#define PWM_IDR1_FCHID1 (0x1u << 17) /**< \brief (PWM_IDR1) Fault Protection Trigger on Channel 1 Interrupt Disable */
#define PWM_IDR1_FCHID2 (0x1u << 18) /**< \brief (PWM_IDR1) Fault Protection Trigger on Channel 2 Interrupt Disable */
#define PWM_IDR1_FCHID3 (0x1u << 19) /**< \brief (PWM_IDR1) Fault Protection Trigger on Channel 3 Interrupt Disable */
/* -------- PWM_IMR1 : (PWM Offset: 0x18) PWM Interrupt Mask Register 1 -------- */
#define PWM_IMR1_CHID0 (0x1u << 0) /**< \brief (PWM_IMR1) Counter Event on Channel 0 Interrupt Mask */
#define PWM_IMR1_CHID1 (0x1u << 1) /**< \brief (PWM_IMR1) Counter Event on Channel 1 Interrupt Mask */
#define PWM_IMR1_CHID2 (0x1u << 2) /**< \brief (PWM_IMR1) Counter Event on Channel 2 Interrupt Mask */
#define PWM_IMR1_CHID3 (0x1u << 3) /**< \brief (PWM_IMR1) Counter Event on Channel 3 Interrupt Mask */
#define PWM_IMR1_FCHID0 (0x1u << 16) /**< \brief (PWM_IMR1) Fault Protection Trigger on Channel 0 Interrupt Mask */
#define PWM_IMR1_FCHID1 (0x1u << 17) /**< \brief (PWM_IMR1) Fault Protection Trigger on Channel 1 Interrupt Mask */
#define PWM_IMR1_FCHID2 (0x1u << 18) /**< \brief (PWM_IMR1) Fault Protection Trigger on Channel 2 Interrupt Mask */
#define PWM_IMR1_FCHID3 (0x1u << 19) /**< \brief (PWM_IMR1) Fault Protection Trigger on Channel 3 Interrupt Mask */
/* -------- PWM_ISR1 : (PWM Offset: 0x1C) PWM Interrupt Status Register 1 -------- */
#define PWM_ISR1_CHID0 (0x1u << 0) /**< \brief (PWM_ISR1) Counter Event on Channel 0 */
#define PWM_ISR1_CHID1 (0x1u << 1) /**< \brief (PWM_ISR1) Counter Event on Channel 1 */
#define PWM_ISR1_CHID2 (0x1u << 2) /**< \brief (PWM_ISR1) Counter Event on Channel 2 */
#define PWM_ISR1_CHID3 (0x1u << 3) /**< \brief (PWM_ISR1) Counter Event on Channel 3 */
#define PWM_ISR1_FCHID0 (0x1u << 16) /**< \brief (PWM_ISR1) Fault Protection Trigger on Channel 0 */
#define PWM_ISR1_FCHID1 (0x1u << 17) /**< \brief (PWM_ISR1) Fault Protection Trigger on Channel 1 */
#define PWM_ISR1_FCHID2 (0x1u << 18) /**< \brief (PWM_ISR1) Fault Protection Trigger on Channel 2 */
#define PWM_ISR1_FCHID3 (0x1u << 19) /**< \brief (PWM_ISR1) Fault Protection Trigger on Channel 3 */
/* -------- PWM_SCM : (PWM Offset: 0x20) PWM Sync Channels Mode Register -------- */
#define PWM_SCM_SYNC0 (0x1u << 0) /**< \brief (PWM_SCM) Synchronous Channel 0 */
#define PWM_SCM_SYNC1 (0x1u << 1) /**< \brief (PWM_SCM) Synchronous Channel 1 */
#define PWM_SCM_SYNC2 (0x1u << 2) /**< \brief (PWM_SCM) Synchronous Channel 2 */
#define PWM_SCM_SYNC3 (0x1u << 3) /**< \brief (PWM_SCM) Synchronous Channel 3 */
#define PWM_SCM_UPDM_Pos 16
#define PWM_SCM_UPDM_Msk (0x3u << PWM_SCM_UPDM_Pos) /**< \brief (PWM_SCM) Synchronous Channels Update Mode */
#define   PWM_SCM_UPDM_MODE0 (0x0u << 16) /**< \brief (PWM_SCM) Manual write of double buffer registers and manual update of synchronous channels */
#define   PWM_SCM_UPDM_MODE1 (0x1u << 16) /**< \brief (PWM_SCM) Manual write of double buffer registers and automatic update of synchronous channels */
#define   PWM_SCM_UPDM_MODE2 (0x2u << 16) /**< \brief (PWM_SCM) Automatic write of duty-cycle update registers by the PDC and automatic update of synchronous channels */
#define PWM_SCM_PTRM (0x1u << 20) /**< \brief (PWM_SCM) PDC Transfer Request Mode */
#define PWM_SCM_PTRCS_Pos 21
#define PWM_SCM_PTRCS_Msk (0x7u << PWM_SCM_PTRCS_Pos) /**< \brief (PWM_SCM) PDC Transfer Request Comparison Selection */
#define PWM_SCM_PTRCS(value) ((PWM_SCM_PTRCS_Msk & ((value) << PWM_SCM_PTRCS_Pos)))
/* -------- PWM_SCUC : (PWM Offset: 0x28) PWM Sync Channels Update Control Register -------- */
#define PWM_SCUC_UPDULOCK (0x1u << 0) /**< \brief (PWM_SCUC) Synchronous Channels Update Unlock */
/* -------- PWM_SCUP : (PWM Offset: 0x2C) PWM Sync Channels Update Period Register -------- */
#define PWM_SCUP_UPR_Pos 0
#define PWM_SCUP_UPR_Msk (0xfu << PWM_SCUP_UPR_Pos) /**< \brief (PWM_SCUP) Update Period */
#define PWM_SCUP_UPR(value) ((PWM_SCUP_UPR_Msk & ((value) << PWM_SCUP_UPR_Pos)))
#define PWM_SCUP_UPRCNT_Pos 4
#define PWM_SCUP_UPRCNT_Msk (0xfu << PWM_SCUP_UPRCNT_Pos) /**< \brief (PWM_SCUP) Update Period Counter */
#define PWM_SCUP_UPRCNT(value) ((PWM_SCUP_UPRCNT_Msk & ((value) << PWM_SCUP_UPRCNT_Pos)))
/* -------- PWM_SCUPUPD : (PWM Offset: 0x30) PWM Sync Channels Update Period Update Register -------- */
#define PWM_SCUPUPD_UPRUPD_Pos 0
#define PWM_SCUPUPD_UPRUPD_Msk (0xfu << PWM_SCUPUPD_UPRUPD_Pos) /**< \brief (PWM_SCUPUPD) Update Period Update */
#define PWM_SCUPUPD_UPRUPD(value) ((PWM_SCUPUPD_UPRUPD_Msk & ((value) << PWM_SCUPUPD_UPRUPD_Pos)))
/* -------- PWM_IER2 : (PWM Offset: 0x34) PWM Interrupt Enable Register 2 -------- */
#define PWM_IER2_WRDY (0x1u << 0) /**< \brief (PWM_IER2) Write Ready for Synchronous Channels Update Interrupt Enable */
#define PWM_IER2_ENDTX (0x1u << 1) /**< \brief (PWM_IER2) PDC End of TX Buffer Interrupt Enable */
#define PWM_IER2_TXBUFE (0x1u << 2) /**< \brief (PWM_IER2) PDC TX Buffer Empty Interrupt Enable */
#define PWM_IER2_UNRE (0x1u << 3) /**< \brief (PWM_IER2) Synchronous Channels Update Underrun Error Interrupt Enable */
#define PWM_IER2_CMPM0 (0x1u << 8) /**< \brief (PWM_IER2) Comparison 0 Match Interrupt Enable */
#define PWM_IER2_CMPM1 (0x1u << 9) /**< \brief (PWM_IER2) Comparison 1 Match Interrupt Enable */
#define PWM_IER2_CMPM2 (0x1u << 10) /**< \brief (PWM_IER2) Comparison 2 Match Interrupt Enable */
#define PWM_IER2_CMPM3 (0x1u << 11) /**< \brief (PWM_IER2) Comparison 3 Match Interrupt Enable */
#define PWM_IER2_CMPM4 (0x1u << 12) /**< \brief (PWM_IER2) Comparison 4 Match Interrupt Enable */
#define PWM_IER2_CMPM5 (0x1u << 13) /**< \brief (PWM_IER2) Comparison 5 Match Interrupt Enable */
#define PWM_IER2_CMPM6 (0x1u << 14) /**< \brief (PWM_IER2) Comparison 6 Match Interrupt Enable */
#define PWM_IER2_CMPM7 (0x1u << 15) /**< \brief (PWM_IER2) Comparison 7 Match Interrupt Enable */
#define PWM_IER2_CMPU0 (0x1u << 16) /**< \brief (PWM_IER2) Comparison 0 Update Interrupt Enable */
#define PWM_IER2_CMPU1 (0x1u << 17) /**< \brief (PWM_IER2) Comparison 1 Update Interrupt Enable */
#define PWM_IER2_CMPU2 (0x1u << 18) /**< \brief (PWM_IER2) Comparison 2 Update Interrupt Enable */
#define PWM_IER2_CMPU3 (0x1u << 19) /**< \brief (PWM_IER2) Comparison 3 Update Interrupt Enable */
#define PWM_IER2_CMPU4 (0x1u << 20) /**< \brief (PWM_IER2) Comparison 4 Update Interrupt Enable */
#define PWM_IER2_CMPU5 (0x1u << 21) /**< \brief (PWM_IER2) Comparison 5 Update Interrupt Enable */
#define PWM_IER2_CMPU6 (0x1u << 22) /**< \brief (PWM_IER2) Comparison 6 Update Interrupt Enable */
#define PWM_IER2_CMPU7 (0x1u << 23) /**< \brief (PWM_IER2) Comparison 7 Update Interrupt Enable */
/* -------- PWM_IDR2 : (PWM Offset: 0x38) PWM Interrupt Disable Register 2 -------- */
#define PWM_IDR2_WRDY (0x1u << 0) /**< \brief (PWM_IDR2) Write Ready for Synchronous Channels Update Interrupt Disable */
#define PWM_IDR2_ENDTX (0x1u << 1) /**< \brief (PWM_IDR2) PDC End of TX Buffer Interrupt Disable */
#define PWM_IDR2_TXBUFE (0x1u << 2) /**< \brief (PWM_IDR2) PDC TX Buffer Empty Interrupt Disable */
#define PWM_IDR2_UNRE (0x1u << 3) /**< \brief (PWM_IDR2) Synchronous Channels Update Underrun Error Interrupt Disable */
#define PWM_IDR2_CMPM0 (0x1u << 8) /**< \brief (PWM_IDR2) Comparison 0 Match Interrupt Disable */
#define PWM_IDR2_CMPM1 (0x1u << 9) /**< \brief (PWM_IDR2) Comparison 1 Match Interrupt Disable */
#define PWM_IDR2_CMPM2 (0x1u << 10) /**< \brief (PWM_IDR2) Comparison 2 Match Interrupt Disable */
#define PWM_IDR2_CMPM3 (0x1u << 11) /**< \brief (PWM_IDR2) Comparison 3 Match Interrupt Disable */
#define PWM_IDR2_CMPM4 (0x1u << 12) /**< \brief (PWM_IDR2) Comparison 4 Match Interrupt Disable */
#define PWM_IDR2_CMPM5 (0x1u << 13) /**< \brief (PWM_IDR2) Comparison 5 Match Interrupt Disable */
#define PWM_IDR2_CMPM6 (0x1u << 14) /**< \brief (PWM_IDR2) Comparison 6 Match Interrupt Disable */
#define PWM_IDR2_CMPM7 (0x1u << 15) /**< \brief (PWM_IDR2) Comparison 7 Match Interrupt Disable */
#define PWM_IDR2_CMPU0 (0x1u << 16) /**< \brief (PWM_IDR2) Comparison 0 Update Interrupt Disable */
#define PWM_IDR2_CMPU1 (0x1u << 17) /**< \brief (PWM_IDR2) Comparison 1 Update Interrupt Disable */
#define PWM_IDR2_CMPU2 (0x1u << 18) /**< \brief (PWM_IDR2) Comparison 2 Update Interrupt Disable */
#define PWM_IDR2_CMPU3 (0x1u << 19) /**< \brief (PWM_IDR2) Comparison 3 Update Interrupt Disable */
#define PWM_IDR2_CMPU4 (0x1u << 20) /**< \brief (PWM_IDR2) Comparison 4 Update Interrupt Disable */
#define PWM_IDR2_CMPU5 (0x1u << 21) /**< \brief (PWM_IDR2) Comparison 5 Update Interrupt Disable */
#define PWM_IDR2_CMPU6 (0x1u << 22) /**< \brief (PWM_IDR2) Comparison 6 Update Interrupt Disable */
#define PWM_IDR2_CMPU7 (0x1u << 23) /**< \brief (PWM_IDR2) Comparison 7 Update Interrupt Disable */
/* -------- PWM_IMR2 : (PWM Offset: 0x3C) PWM Interrupt Mask Register 2 -------- */
#define PWM_IMR2_WRDY (0x1u << 0) /**< \brief (PWM_IMR2) Write Ready for Synchronous Channels Update Interrupt Mask */
#define PWM_IMR2_ENDTX (0x1u << 1) /**< \brief (PWM_IMR2) PDC End of TX Buffer Interrupt Mask */
#define PWM_IMR2_TXBUFE (0x1u << 2) /**< \brief (PWM_IMR2) PDC TX Buffer Empty Interrupt Mask */
#define PWM_IMR2_UNRE (0x1u << 3) /**< \brief (PWM_IMR2) Synchronous Channels Update Underrun Error Interrupt Mask */
#define PWM_IMR2_CMPM0 (0x1u << 8) /**< \brief (PWM_IMR2) Comparison 0 Match Interrupt Mask */
#define PWM_IMR2_CMPM1 (0x1u << 9) /**< \brief (PWM_IMR2) Comparison 1 Match Interrupt Mask */
#define PWM_IMR2_CMPM2 (0x1u << 10) /**< \brief (PWM_IMR2) Comparison 2 Match Interrupt Mask */
#define PWM_IMR2_CMPM3 (0x1u << 11) /**< \brief (PWM_IMR2) Comparison 3 Match Interrupt Mask */
#define PWM_IMR2_CMPM4 (0x1u << 12) /**< \brief (PWM_IMR2) Comparison 4 Match Interrupt Mask */
#define PWM_IMR2_CMPM5 (0x1u << 13) /**< \brief (PWM_IMR2) Comparison 5 Match Interrupt Mask */
#define PWM_IMR2_CMPM6 (0x1u << 14) /**< \brief (PWM_IMR2) Comparison 6 Match Interrupt Mask */
#define PWM_IMR2_CMPM7 (0x1u << 15) /**< \brief (PWM_IMR2) Comparison 7 Match Interrupt Mask */
#define PWM_IMR2_CMPU0 (0x1u << 16) /**< \brief (PWM_IMR2) Comparison 0 Update Interrupt Mask */
#define PWM_IMR2_CMPU1 (0x1u << 17) /**< \brief (PWM_IMR2) Comparison 1 Update Interrupt Mask */
#define PWM_IMR2_CMPU2 (0x1u << 18) /**< \brief (PWM_IMR2) Comparison 2 Update Interrupt Mask */
#define PWM_IMR2_CMPU3 (0x1u << 19) /**< \brief (PWM_IMR2) Comparison 3 Update Interrupt Mask */
#define PWM_IMR2_CMPU4 (0x1u << 20) /**< \brief (PWM_IMR2) Comparison 4 Update Interrupt Mask */
#define PWM_IMR2_CMPU5 (0x1u << 21) /**< \brief (PWM_IMR2) Comparison 5 Update Interrupt Mask */
#define PWM_IMR2_CMPU6 (0x1u << 22) /**< \brief (PWM_IMR2) Comparison 6 Update Interrupt Mask */
#define PWM_IMR2_CMPU7 (0x1u << 23) /**< \brief (PWM_IMR2) Comparison 7 Update Interrupt Mask */
/* -------- PWM_ISR2 : (PWM Offset: 0x40) PWM Interrupt Status Register 2 -------- */
#define PWM_ISR2_WRDY (0x1u << 0) /**< \brief (PWM_ISR2) Write Ready for Synchronous Channels Update */
#define PWM_ISR2_ENDTX (0x1u << 1) /**< \brief (PWM_ISR2) PDC End of TX Buffer */
#define PWM_ISR2_TXBUFE (0x1u << 2) /**< \brief (PWM_ISR2) PDC TX Buffer Empty */
#define PWM_ISR2_UNRE (0x1u << 3) /**< \brief (PWM_ISR2) Synchronous Channels Update Underrun Error */
#define PWM_ISR2_CMPM0 (0x1u << 8) /**< \brief (PWM_ISR2) Comparison 0 Match */
#define PWM_ISR2_CMPM1 (0x1u << 9) /**< \brief (PWM_ISR2) Comparison 1 Match */
#define PWM_ISR2_CMPM2 (0x1u << 10) /**< \brief (PWM_ISR2) Comparison 2 Match */
#define PWM_ISR2_CMPM3 (0x1u << 11) /**< \brief (PWM_ISR2) Comparison 3 Match */
#define PWM_ISR2_CMPM4 (0x1u << 12) /**< \brief (PWM_ISR2) Comparison 4 Match */
#define PWM_ISR2_CMPM5 (0x1u << 13) /**< \brief (PWM_ISR2) Comparison 5 Match */
#define PWM_ISR2_CMPM6 (0x1u << 14) /**< \brief (PWM_ISR2) Comparison 6 Match */
#define PWM_ISR2_CMPM7 (0x1u << 15) /**< \brief (PWM_ISR2) Comparison 7 Match */
#define PWM_ISR2_CMPU0 (0x1u << 16) /**< \brief (PWM_ISR2) Comparison 0 Update */
#define PWM_ISR2_CMPU1 (0x1u << 17) /**< \brief (PWM_ISR2) Comparison 1 Update */
#define PWM_ISR2_CMPU2 (0x1u << 18) /**< \brief (PWM_ISR2) Comparison 2 Update */
#define PWM_ISR2_CMPU3 (0x1u << 19) /**< \brief (PWM_ISR2) Comparison 3 Update */
#define PWM_ISR2_CMPU4 (0x1u << 20) /**< \brief (PWM_ISR2) Comparison 4 Update */
#define PWM_ISR2_CMPU5 (0x1u << 21) /**< \brief (PWM_ISR2) Comparison 5 Update */
#define PWM_ISR2_CMPU6 (0x1u << 22) /**< \brief (PWM_ISR2) Comparison 6 Update */
#define PWM_ISR2_CMPU7 (0x1u << 23) /**< \brief (PWM_ISR2) Comparison 7 Update */
/* -------- PWM_OOV : (PWM Offset: 0x44) PWM Output Override Value Register -------- */
#define PWM_OOV_OOVH0 (0x1u << 0) /**< \brief (PWM_OOV) Output Override Value for PWMH output of the channel 0 */
#define PWM_OOV_OOVH1 (0x1u << 1) /**< \brief (PWM_OOV) Output Override Value for PWMH output of the channel 1 */
#define PWM_OOV_OOVH2 (0x1u << 2) /**< \brief (PWM_OOV) Output Override Value for PWMH output of the channel 2 */
#define PWM_OOV_OOVH3 (0x1u << 3) /**< \brief (PWM_OOV) Output Override Value for PWMH output of the channel 3 */
#define PWM_OOV_OOVL0 (0x1u << 16) /**< \brief (PWM_OOV) Output Override Value for PWML output of the channel 0 */
#define PWM_OOV_OOVL1 (0x1u << 17) /**< \brief (PWM_OOV) Output Override Value for PWML output of the channel 1 */
#define PWM_OOV_OOVL2 (0x1u << 18) /**< \brief (PWM_OOV) Output Override Value for PWML output of the channel 2 */
#define PWM_OOV_OOVL3 (0x1u << 19) /**< \brief (PWM_OOV) Output Override Value for PWML output of the channel 3 */
/* -------- PWM_OS : (PWM Offset: 0x48) PWM Output Selection Register -------- */
#define PWM_OS_OSH0 (0x1u << 0) /**< \brief (PWM_OS) Output Selection for PWMH output of the channel 0 */
#define PWM_OS_OSH1 (0x1u << 1) /**< \brief (PWM_OS) Output Selection for PWMH output of the channel 1 */
#define PWM_OS_OSH2 (0x1u << 2) /**< \brief (PWM_OS) Output Selection for PWMH output of the channel 2 */
#define PWM_OS_OSH3 (0x1u << 3) /**< \brief (PWM_OS) Output Selection for PWMH output of the channel 3 */
#define PWM_OS_OSL0 (0x1u << 16) /**< \brief (PWM_OS) Output Selection for PWML output of the channel 0 */
#define PWM_OS_OSL1 (0x1u << 17) /**< \brief (PWM_OS) Output Selection for PWML output of the channel 1 */
#define PWM_OS_OSL2 (0x1u << 18) /**< \brief (PWM_OS) Output Selection for PWML output of the channel 2 */
#define PWM_OS_OSL3 (0x1u << 19) /**< \brief (PWM_OS) Output Selection for PWML output of the channel 3 */
/* -------- PWM_OSS : (PWM Offset: 0x4C) PWM Output Selection Set Register -------- */
#define PWM_OSS_OSSH0 (0x1u << 0) /**< \brief (PWM_OSS) Output Selection Set for PWMH output of the channel 0 */
#define PWM_OSS_OSSH1 (0x1u << 1) /**< \brief (PWM_OSS) Output Selection Set for PWMH output of the channel 1 */
#define PWM_OSS_OSSH2 (0x1u << 2) /**< \brief (PWM_OSS) Output Selection Set for PWMH output of the channel 2 */
#define PWM_OSS_OSSH3 (0x1u << 3) /**< \brief (PWM_OSS) Output Selection Set for PWMH output of the channel 3 */
#define PWM_OSS_OSSL0 (0x1u << 16) /**< \brief (PWM_OSS) Output Selection Set for PWML output of the channel 0 */
#define PWM_OSS_OSSL1 (0x1u << 17) /**< \brief (PWM_OSS) Output Selection Set for PWML output of the channel 1 */
#define PWM_OSS_OSSL2 (0x1u << 18) /**< \brief (PWM_OSS) Output Selection Set for PWML output of the channel 2 */
#define PWM_OSS_OSSL3 (0x1u << 19) /**< \brief (PWM_OSS) Output Selection Set for PWML output of the channel 3 */
/* -------- PWM_OSC : (PWM Offset: 0x50) PWM Output Selection Clear Register -------- */
#define PWM_OSC_OSCH0 (0x1u << 0) /**< \brief (PWM_OSC) Output Selection Clear for PWMH output of the channel 0 */
#define PWM_OSC_OSCH1 (0x1u << 1) /**< \brief (PWM_OSC) Output Selection Clear for PWMH output of the channel 1 */
#define PWM_OSC_OSCH2 (0x1u << 2) /**< \brief (PWM_OSC) Output Selection Clear for PWMH output of the channel 2 */
#define PWM_OSC_OSCH3 (0x1u << 3) /**< \brief (PWM_OSC) Output Selection Clear for PWMH output of the channel 3 */
#define PWM_OSC_OSCL0 (0x1u << 16) /**< \brief (PWM_OSC) Output Selection Clear for PWML output of the channel 0 */
#define PWM_OSC_OSCL1 (0x1u << 17) /**< \brief (PWM_OSC) Output Selection Clear for PWML output of the channel 1 */
#define PWM_OSC_OSCL2 (0x1u << 18) /**< \brief (PWM_OSC) Output Selection Clear for PWML output of the channel 2 */
#define PWM_OSC_OSCL3 (0x1u << 19) /**< \brief (PWM_OSC) Output Selection Clear for PWML output of the channel 3 */
/* -------- PWM_OSSUPD : (PWM Offset: 0x54) PWM Output Selection Set Update Register -------- */
#define PWM_OSSUPD_OSSUPH0 (0x1u << 0) /**< \brief (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 0 */
#define PWM_OSSUPD_OSSUPH1 (0x1u << 1) /**< \brief (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 1 */
#define PWM_OSSUPD_OSSUPH2 (0x1u << 2) /**< \brief (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 2 */
#define PWM_OSSUPD_OSSUPH3 (0x1u << 3) /**< \brief (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 3 */
#define PWM_OSSUPD_OSSUPL0 (0x1u << 16) /**< \brief (PWM_OSSUPD) Output Selection Set for PWML output of the channel 0 */
#define PWM_OSSUPD_OSSUPL1 (0x1u << 17) /**< \brief (PWM_OSSUPD) Output Selection Set for PWML output of the channel 1 */
#define PWM_OSSUPD_OSSUPL2 (0x1u << 18) /**< \brief (PWM_OSSUPD) Output Selection Set for PWML output of the channel 2 */
#define PWM_OSSUPD_OSSUPL3 (0x1u << 19) /**< \brief (PWM_OSSUPD) Output Selection Set for PWML output of the channel 3 */
/* -------- PWM_OSCUPD : (PWM Offset: 0x58) PWM Output Selection Clear Update Register -------- */
#define PWM_OSCUPD_OSCUPH0 (0x1u << 0) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 0 */
#define PWM_OSCUPD_OSCUPH1 (0x1u << 1) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 1 */
#define PWM_OSCUPD_OSCUPH2 (0x1u << 2) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 2 */
#define PWM_OSCUPD_OSCUPH3 (0x1u << 3) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 3 */
#define PWM_OSCUPD_OSCUPL0 (0x1u << 16) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 0 */
#define PWM_OSCUPD_OSCUPL1 (0x1u << 17) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 1 */
#define PWM_OSCUPD_OSCUPL2 (0x1u << 18) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 2 */
#define PWM_OSCUPD_OSCUPL3 (0x1u << 19) /**< \brief (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 3 */
/* -------- PWM_FMR : (PWM Offset: 0x5C) PWM Fault Mode Register -------- */
#define PWM_FMR_FPOL_Pos 0
#define PWM_FMR_FPOL_Msk (0xffu << PWM_FMR_FPOL_Pos) /**< \brief (PWM_FMR) Fault Polarity (fault input bit varies from 0 to 5) */
#define PWM_FMR_FPOL(value) ((PWM_FMR_FPOL_Msk & ((value) << PWM_FMR_FPOL_Pos)))
#define PWM_FMR_FMOD_Pos 8
#define PWM_FMR_FMOD_Msk (0xffu << PWM_FMR_FMOD_Pos) /**< \brief (PWM_FMR) Fault Activation Mode (fault input bit varies from 0 to 5) */
#define PWM_FMR_FMOD(value) ((PWM_FMR_FMOD_Msk & ((value) << PWM_FMR_FMOD_Pos)))
#define PWM_FMR_FFIL_Pos 16
#define PWM_FMR_FFIL_Msk (0xffu << PWM_FMR_FFIL_Pos) /**< \brief (PWM_FMR) Fault Filtering (fault input bit varies from 0 to 5) */
#define PWM_FMR_FFIL(value) ((PWM_FMR_FFIL_Msk & ((value) << PWM_FMR_FFIL_Pos)))
/* -------- PWM_FSR : (PWM Offset: 0x60) PWM Fault Status Register -------- */
#define PWM_FSR_FIV_Pos 0
#define PWM_FSR_FIV_Msk (0xffu << PWM_FSR_FIV_Pos) /**< \brief (PWM_FSR) Fault Input Value (fault input bit varies from 0 to 5) */
#define PWM_FSR_FS_Pos 8
#define PWM_FSR_FS_Msk (0xffu << PWM_FSR_FS_Pos) /**< \brief (PWM_FSR) Fault Status (fault input bit varies from 0 to 5) */
/* -------- PWM_FCR : (PWM Offset: 0x64) PWM Fault Clear Register -------- */
#define PWM_FCR_FCLR_Pos 0
#define PWM_FCR_FCLR_Msk (0xffu << PWM_FCR_FCLR_Pos) /**< \brief (PWM_FCR) Fault Clear (fault input bit varies from 0 to 5) */
#define PWM_FCR_FCLR(value) ((PWM_FCR_FCLR_Msk & ((value) << PWM_FCR_FCLR_Pos)))
/* -------- PWM_FPV : (PWM Offset: 0x68) PWM Fault Protection Value Register -------- */
#define PWM_FPV_FPVH0 (0x1u << 0) /**< \brief (PWM_FPV) Fault Protection Value for PWMH output on channel 0 */
#define PWM_FPV_FPVH1 (0x1u << 1) /**< \brief (PWM_FPV) Fault Protection Value for PWMH output on channel 1 */
#define PWM_FPV_FPVH2 (0x1u << 2) /**< \brief (PWM_FPV) Fault Protection Value for PWMH output on channel 2 */
#define PWM_FPV_FPVH3 (0x1u << 3) /**< \brief (PWM_FPV) Fault Protection Value for PWMH output on channel 3 */
#define PWM_FPV_FPVL0 (0x1u << 16) /**< \brief (PWM_FPV) Fault Protection Value for PWML output on channel 0 */
#define PWM_FPV_FPVL1 (0x1u << 17) /**< \brief (PWM_FPV) Fault Protection Value for PWML output on channel 1 */
#define PWM_FPV_FPVL2 (0x1u << 18) /**< \brief (PWM_FPV) Fault Protection Value for PWML output on channel 2 */
#define PWM_FPV_FPVL3 (0x1u << 19) /**< \brief (PWM_FPV) Fault Protection Value for PWML output on channel 3 */
/* -------- PWM_FPE : (PWM Offset: 0x6C) PWM Fault Protection Enable Register -------- */
#define PWM_FPE_FPE0_Pos 0
#define PWM_FPE_FPE0_Msk (0xffu << PWM_FPE_FPE0_Pos) /**< \brief (PWM_FPE) Fault Protection Enable for channel 0 (fault input bit varies from 0 to 5) */
#define PWM_FPE_FPE0(value) ((PWM_FPE_FPE0_Msk & ((value) << PWM_FPE_FPE0_Pos)))
#define PWM_FPE_FPE1_Pos 8
#define PWM_FPE_FPE1_Msk (0xffu << PWM_FPE_FPE1_Pos) /**< \brief (PWM_FPE) Fault Protection Enable for channel 1 (fault input bit varies from 0 to 5) */
#define PWM_FPE_FPE1(value) ((PWM_FPE_FPE1_Msk & ((value) << PWM_FPE_FPE1_Pos)))
#define PWM_FPE_FPE2_Pos 16
#define PWM_FPE_FPE2_Msk (0xffu << PWM_FPE_FPE2_Pos) /**< \brief (PWM_FPE) Fault Protection Enable for channel 2 (fault input bit varies from 0 to 5) */
#define PWM_FPE_FPE2(value) ((PWM_FPE_FPE2_Msk & ((value) << PWM_FPE_FPE2_Pos)))
#define PWM_FPE_FPE3_Pos 24
#define PWM_FPE_FPE3_Msk (0xffu << PWM_FPE_FPE3_Pos) /**< \brief (PWM_FPE) Fault Protection Enable for channel 3 (fault input bit varies from 0 to 5) */
#define PWM_FPE_FPE3(value) ((PWM_FPE_FPE3_Msk & ((value) << PWM_FPE_FPE3_Pos)))
/* -------- PWM_ELMR[2] : (PWM Offset: 0x7C) PWM Event Line 0 Mode Register -------- */
#define PWM_ELMR_CSEL0 (0x1u << 0) /**< \brief (PWM_ELMR[2]) Comparison 0 Selection */
#define PWM_ELMR_CSEL1 (0x1u << 1) /**< \brief (PWM_ELMR[2]) Comparison 1 Selection */
#define PWM_ELMR_CSEL2 (0x1u << 2) /**< \brief (PWM_ELMR[2]) Comparison 2 Selection */
#define PWM_ELMR_CSEL3 (0x1u << 3) /**< \brief (PWM_ELMR[2]) Comparison 3 Selection */
#define PWM_ELMR_CSEL4 (0x1u << 4) /**< \brief (PWM_ELMR[2]) Comparison 4 Selection */
#define PWM_ELMR_CSEL5 (0x1u << 5) /**< \brief (PWM_ELMR[2]) Comparison 5 Selection */
#define PWM_ELMR_CSEL6 (0x1u << 6) /**< \brief (PWM_ELMR[2]) Comparison 6 Selection */
#define PWM_ELMR_CSEL7 (0x1u << 7) /**< \brief (PWM_ELMR[2]) Comparison 7 Selection */
/* -------- PWM_SMMR : (PWM Offset: 0xB0) PWM Stepper Motor Mode Register -------- */
#define PWM_SMMR_GCEN0 (0x1u << 0) /**< \brief (PWM_SMMR) Gray Count ENable */
#define PWM_SMMR_GCEN1 (0x1u << 1) /**< \brief (PWM_SMMR) Gray Count ENable */
#define PWM_SMMR_DOWN0 (0x1u << 16) /**< \brief (PWM_SMMR) DOWN Count */
#define PWM_SMMR_DOWN1 (0x1u << 17) /**< \brief (PWM_SMMR) DOWN Count */
/* -------- PWM_WPCR : (PWM Offset: 0xE4) PWM Write Protect Control Register -------- */
#define PWM_WPCR_WPCMD_Pos 0
#define PWM_WPCR_WPCMD_Msk (0x3u << PWM_WPCR_WPCMD_Pos) /**< \brief (PWM_WPCR) Write Protect Command */
#define PWM_WPCR_WPCMD(value) ((PWM_WPCR_WPCMD_Msk & ((value) << PWM_WPCR_WPCMD_Pos)))
#define PWM_WPCR_WPRG0 (0x1u << 2) /**< \brief (PWM_WPCR) Write Protect Register Group 0 */
#define PWM_WPCR_WPRG1 (0x1u << 3) /**< \brief (PWM_WPCR) Write Protect Register Group 1 */
#define PWM_WPCR_WPRG2 (0x1u << 4) /**< \brief (PWM_WPCR) Write Protect Register Group 2 */
#define PWM_WPCR_WPRG3 (0x1u << 5) /**< \brief (PWM_WPCR) Write Protect Register Group 3 */
#define PWM_WPCR_WPRG4 (0x1u << 6) /**< \brief (PWM_WPCR) Write Protect Register Group 4 */
#define PWM_WPCR_WPRG5 (0x1u << 7) /**< \brief (PWM_WPCR) Write Protect Register Group 5 */
#define PWM_WPCR_WPKEY_Pos 8
#define PWM_WPCR_WPKEY_Msk (0xffffffu << PWM_WPCR_WPKEY_Pos) /**< \brief (PWM_WPCR) Write Protect Key */
#define PWM_WPCR_WPKEY(value) ((PWM_WPCR_WPKEY_Msk & ((value) << PWM_WPCR_WPKEY_Pos)))
/* -------- PWM_WPSR : (PWM Offset: 0xE8) PWM Write Protect Status Register -------- */
#define PWM_WPSR_WPSWS0 (0x1u << 0) /**< \brief (PWM_WPSR) Write Protect SW Status */
#define PWM_WPSR_WPSWS1 (0x1u << 1) /**< \brief (PWM_WPSR) Write Protect SW Status */
#define PWM_WPSR_WPSWS2 (0x1u << 2) /**< \brief (PWM_WPSR) Write Protect SW Status */
#define PWM_WPSR_WPSWS3 (0x1u << 3) /**< \brief (PWM_WPSR) Write Protect SW Status */
#define PWM_WPSR_WPSWS4 (0x1u << 4) /**< \brief (PWM_WPSR) Write Protect SW Status */
#define PWM_WPSR_WPSWS5 (0x1u << 5) /**< \brief (PWM_WPSR) Write Protect SW Status */
#define PWM_WPSR_WPVS (0x1u << 7) /**< \brief (PWM_WPSR) Write Protect Violation Status */
#define PWM_WPSR_WPHWS0 (0x1u << 8) /**< \brief (PWM_WPSR) Write Protect HW Status */
#define PWM_WPSR_WPHWS1 (0x1u << 9) /**< \brief (PWM_WPSR) Write Protect HW Status */
#define PWM_WPSR_WPHWS2 (0x1u << 10) /**< \brief (PWM_WPSR) Write Protect HW Status */
#define PWM_WPSR_WPHWS3 (0x1u << 11) /**< \brief (PWM_WPSR) Write Protect HW Status */
#define PWM_WPSR_WPHWS4 (0x1u << 12) /**< \brief (PWM_WPSR) Write Protect HW Status */
#define PWM_WPSR_WPHWS5 (0x1u << 13) /**< \brief (PWM_WPSR) Write Protect HW Status */
#define PWM_WPSR_WPVSRC_Pos 16
#define PWM_WPSR_WPVSRC_Msk (0xffffu << PWM_WPSR_WPVSRC_Pos) /**< \brief (PWM_WPSR) Write Protect Violation Source */
/* -------- PWM_RPR : (PWM Offset: 0x100) Receive Pointer Register -------- */
#define PWM_RPR_RXPTR_Pos 0
#define PWM_RPR_RXPTR_Msk (0xffffffffu << PWM_RPR_RXPTR_Pos) /**< \brief (PWM_RPR) Receive Pointer Register */
#define PWM_RPR_RXPTR(value) ((PWM_RPR_RXPTR_Msk & ((value) << PWM_RPR_RXPTR_Pos)))
/* -------- PWM_RCR : (PWM Offset: 0x104) Receive Counter Register -------- */
#define PWM_RCR_RXCTR_Pos 0
#define PWM_RCR_RXCTR_Msk (0xffffu << PWM_RCR_RXCTR_Pos) /**< \brief (PWM_RCR) Receive Counter Register */
#define PWM_RCR_RXCTR(value) ((PWM_RCR_RXCTR_Msk & ((value) << PWM_RCR_RXCTR_Pos)))
/* -------- PWM_TPR : (PWM Offset: 0x108) Transmit Pointer Register -------- */
#define PWM_TPR_TXPTR_Pos 0
#define PWM_TPR_TXPTR_Msk (0xffffffffu << PWM_TPR_TXPTR_Pos) /**< \brief (PWM_TPR) Transmit Counter Register */
#define PWM_TPR_TXPTR(value) ((PWM_TPR_TXPTR_Msk & ((value) << PWM_TPR_TXPTR_Pos)))
/* -------- PWM_TCR : (PWM Offset: 0x10C) Transmit Counter Register -------- */
#define PWM_TCR_TXCTR_Pos 0
#define PWM_TCR_TXCTR_Msk (0xffffu << PWM_TCR_TXCTR_Pos) /**< \brief (PWM_TCR) Transmit Counter Register */
#define PWM_TCR_TXCTR(value) ((PWM_TCR_TXCTR_Msk & ((value) << PWM_TCR_TXCTR_Pos)))
/* -------- PWM_RNPR : (PWM Offset: 0x110) Receive Next Pointer Register -------- */
#define PWM_RNPR_RXNPTR_Pos 0
#define PWM_RNPR_RXNPTR_Msk (0xffffffffu << PWM_RNPR_RXNPTR_Pos) /**< \brief (PWM_RNPR) Receive Next Pointer */
#define PWM_RNPR_RXNPTR(value) ((PWM_RNPR_RXNPTR_Msk & ((value) << PWM_RNPR_RXNPTR_Pos)))
/* -------- PWM_RNCR : (PWM Offset: 0x114) Receive Next Counter Register -------- */
#define PWM_RNCR_RXNCTR_Pos 0
#define PWM_RNCR_RXNCTR_Msk (0xffffu << PWM_RNCR_RXNCTR_Pos) /**< \brief (PWM_RNCR) Receive Next Counter */
#define PWM_RNCR_RXNCTR(value) ((PWM_RNCR_RXNCTR_Msk & ((value) << PWM_RNCR_RXNCTR_Pos)))
/* -------- PWM_TNPR : (PWM Offset: 0x118) Transmit Next Pointer Register -------- */
#define PWM_TNPR_TXNPTR_Pos 0
#define PWM_TNPR_TXNPTR_Msk (0xffffffffu << PWM_TNPR_TXNPTR_Pos) /**< \brief (PWM_TNPR) Transmit Next Pointer */
#define PWM_TNPR_TXNPTR(value) ((PWM_TNPR_TXNPTR_Msk & ((value) << PWM_TNPR_TXNPTR_Pos)))
/* -------- PWM_TNCR : (PWM Offset: 0x11C) Transmit Next Counter Register -------- */
#define PWM_TNCR_TXNCTR_Pos 0
#define PWM_TNCR_TXNCTR_Msk (0xffffu << PWM_TNCR_TXNCTR_Pos) /**< \brief (PWM_TNCR) Transmit Counter Next */
#define PWM_TNCR_TXNCTR(value) ((PWM_TNCR_TXNCTR_Msk & ((value) << PWM_TNCR_TXNCTR_Pos)))
/* -------- PWM_PTCR : (PWM Offset: 0x120) Transfer Control Register -------- */
#define PWM_PTCR_RXTEN (0x1u << 0) /**< \brief (PWM_PTCR) Receiver Transfer Enable */
#define PWM_PTCR_RXTDIS (0x1u << 1) /**< \brief (PWM_PTCR) Receiver Transfer Disable */
#define PWM_PTCR_TXTEN (0x1u << 8) /**< \brief (PWM_PTCR) Transmitter Transfer Enable */
#define PWM_PTCR_TXTDIS (0x1u << 9) /**< \brief (PWM_PTCR) Transmitter Transfer Disable */
/* -------- PWM_PTSR : (PWM Offset: 0x124) Transfer Status Register -------- */
#define PWM_PTSR_RXTEN (0x1u << 0) /**< \brief (PWM_PTSR) Receiver Transfer Enable */
#define PWM_PTSR_TXTEN (0x1u << 8) /**< \brief (PWM_PTSR) Transmitter Transfer Enable */
/* -------- PWM_CMPV : (PWM Offset: N/A) PWM Comparison 0 Value Register -------- */
#define PWM_CMPV_CV_Pos 0
#define PWM_CMPV_CV_Msk (0xffffffu << PWM_CMPV_CV_Pos) /**< \brief (PWM_CMPV) Comparison x Value */
#define PWM_CMPV_CV(value) ((PWM_CMPV_CV_Msk & ((value) << PWM_CMPV_CV_Pos)))
#define PWM_CMPV_CVM (0x1u << 24) /**< \brief (PWM_CMPV) Comparison x Value Mode */
/* -------- PWM_CMPVUPD : (PWM Offset: N/A) PWM Comparison 0 Value Update Register -------- */
#define PWM_CMPVUPD_CVUPD_Pos 0
#define PWM_CMPVUPD_CVUPD_Msk (0xffffffu << PWM_CMPVUPD_CVUPD_Pos) /**< \brief (PWM_CMPVUPD) Comparison x Value Update */
#define PWM_CMPVUPD_CVUPD(value) ((PWM_CMPVUPD_CVUPD_Msk & ((value) << PWM_CMPVUPD_CVUPD_Pos)))
#define PWM_CMPVUPD_CVMUPD (0x1u << 24) /**< \brief (PWM_CMPVUPD) Comparison x Value Mode Update */
/* -------- PWM_CMPM : (PWM Offset: N/A) PWM Comparison 0 Mode Register -------- */
#define PWM_CMPM_CEN (0x1u << 0) /**< \brief (PWM_CMPM) Comparison x Enable */
#define PWM_CMPM_CTR_Pos 4
#define PWM_CMPM_CTR_Msk (0xfu << PWM_CMPM_CTR_Pos) /**< \brief (PWM_CMPM) Comparison x Trigger */
#define PWM_CMPM_CTR(value) ((PWM_CMPM_CTR_Msk & ((value) << PWM_CMPM_CTR_Pos)))
#define PWM_CMPM_CPR_Pos 8
#define PWM_CMPM_CPR_Msk (0xfu << PWM_CMPM_CPR_Pos) /**< \brief (PWM_CMPM) Comparison x Period */
#define PWM_CMPM_CPR(value) ((PWM_CMPM_CPR_Msk & ((value) << PWM_CMPM_CPR_Pos)))
#define PWM_CMPM_CPRCNT_Pos 12
#define PWM_CMPM_CPRCNT_Msk (0xfu << PWM_CMPM_CPRCNT_Pos) /**< \brief (PWM_CMPM) Comparison x Period Counter */
#define PWM_CMPM_CPRCNT(value) ((PWM_CMPM_CPRCNT_Msk & ((value) << PWM_CMPM_CPRCNT_Pos)))
#define PWM_CMPM_CUPR_Pos 16
#define PWM_CMPM_CUPR_Msk (0xfu << PWM_CMPM_CUPR_Pos) /**< \brief (PWM_CMPM) Comparison x Update Period */
#define PWM_CMPM_CUPR(value) ((PWM_CMPM_CUPR_Msk & ((value) << PWM_CMPM_CUPR_Pos)))
#define PWM_CMPM_CUPRCNT_Pos 20
#define PWM_CMPM_CUPRCNT_Msk (0xfu << PWM_CMPM_CUPRCNT_Pos) /**< \brief (PWM_CMPM) Comparison x Update Period Counter */
#define PWM_CMPM_CUPRCNT(value) ((PWM_CMPM_CUPRCNT_Msk & ((value) << PWM_CMPM_CUPRCNT_Pos)))
/* -------- PWM_CMPMUPD : (PWM Offset: N/A) PWM Comparison 0 Mode Update Register -------- */
#define PWM_CMPMUPD_CENUPD (0x1u << 0) /**< \brief (PWM_CMPMUPD) Comparison x Enable Update */
#define PWM_CMPMUPD_CTRUPD_Pos 4
#define PWM_CMPMUPD_CTRUPD_Msk (0xfu << PWM_CMPMUPD_CTRUPD_Pos) /**< \brief (PWM_CMPMUPD) Comparison x Trigger Update */
#define PWM_CMPMUPD_CTRUPD(value) ((PWM_CMPMUPD_CTRUPD_Msk & ((value) << PWM_CMPMUPD_CTRUPD_Pos)))
#define PWM_CMPMUPD_CPRUPD_Pos 8
#define PWM_CMPMUPD_CPRUPD_Msk (0xfu << PWM_CMPMUPD_CPRUPD_Pos) /**< \brief (PWM_CMPMUPD) Comparison x Period Update */
#define PWM_CMPMUPD_CPRUPD(value) ((PWM_CMPMUPD_CPRUPD_Msk & ((value) << PWM_CMPMUPD_CPRUPD_Pos)))
#define PWM_CMPMUPD_CUPRUPD_Pos 16
#define PWM_CMPMUPD_CUPRUPD_Msk (0xfu << PWM_CMPMUPD_CUPRUPD_Pos) /**< \brief (PWM_CMPMUPD) Comparison x Update Period Update */
#define PWM_CMPMUPD_CUPRUPD(value) ((PWM_CMPMUPD_CUPRUPD_Msk & ((value) << PWM_CMPMUPD_CUPRUPD_Pos)))
/* -------- PWM_CMR : (PWM Offset: N/A) PWM Channel Mode Register -------- */
#define PWM_CMR_CPRE_Pos 0
#define PWM_CMR_CPRE_Msk (0xfu << PWM_CMR_CPRE_Pos) /**< \brief (PWM_CMR) Channel Pre-scaler */
#define   PWM_CMR_CPRE_MCK (0x0u << 0) /**< \brief (PWM_CMR) Master clock */
#define   PWM_CMR_CPRE_MCK_DIV_2 (0x1u << 0) /**< \brief (PWM_CMR) Master clock/2 */
#define   PWM_CMR_CPRE_MCK_DIV_4 (0x2u << 0) /**< \brief (PWM_CMR) Master clock/4 */
#define   PWM_CMR_CPRE_MCK_DIV_8 (0x3u << 0) /**< \brief (PWM_CMR) Master clock/8 */
#define   PWM_CMR_CPRE_MCK_DIV_16 (0x4u << 0) /**< \brief (PWM_CMR) Master clock/16 */
#define   PWM_CMR_CPRE_MCK_DIV_32 (0x5u << 0) /**< \brief (PWM_CMR) Master clock/32 */
#define   PWM_CMR_CPRE_MCK_DIV_64 (0x6u << 0) /**< \brief (PWM_CMR) Master clock/64 */
#define   PWM_CMR_CPRE_MCK_DIV_128 (0x7u << 0) /**< \brief (PWM_CMR) Master clock/128 */
#define   PWM_CMR_CPRE_MCK_DIV_256 (0x8u << 0) /**< \brief (PWM_CMR) Master clock/256 */
#define   PWM_CMR_CPRE_MCK_DIV_512 (0x9u << 0) /**< \brief (PWM_CMR) Master clock/512 */
#define   PWM_CMR_CPRE_MCK_DIV_1024 (0xAu << 0) /**< \brief (PWM_CMR) Master clock/1024 */
#define   PWM_CMR_CPRE_CLKA (0xBu << 0) /**< \brief (PWM_CMR) Clock A */
#define   PWM_CMR_CPRE_CLKB (0xCu << 0) /**< \brief (PWM_CMR) Clock B */
#define PWM_CMR_CALG (0x1u << 8) /**< \brief (PWM_CMR) Channel Alignment */
#define PWM_CMR_CPOL (0x1u << 9) /**< \brief (PWM_CMR) Channel Polarity */
#define PWM_CMR_CES (0x1u << 10) /**< \brief (PWM_CMR) Counter Event Selection */
#define PWM_CMR_DTE (0x1u << 16) /**< \brief (PWM_CMR) Dead-Time Generator Enable */
#define PWM_CMR_DTHI (0x1u << 17) /**< \brief (PWM_CMR) Dead-Time PWMHx Output Inverted */
#define PWM_CMR_DTLI (0x1u << 18) /**< \brief (PWM_CMR) Dead-Time PWMLx Output Inverted */
/* -------- PWM_CDTY : (PWM Offset: N/A) PWM Channel Duty Cycle Register -------- */
#define PWM_CDTY_CDTY_Pos 0
#define PWM_CDTY_CDTY_Msk (0xffffffu << PWM_CDTY_CDTY_Pos) /**< \brief (PWM_CDTY) Channel Duty-Cycle */
#define PWM_CDTY_CDTY(value) ((PWM_CDTY_CDTY_Msk & ((value) << PWM_CDTY_CDTY_Pos)))
/* -------- PWM_CDTYUPD : (PWM Offset: N/A) PWM Channel Duty Cycle Update Register -------- */
#define PWM_CDTYUPD_CDTYUPD_Pos 0
#define PWM_CDTYUPD_CDTYUPD_Msk (0xffffffu << PWM_CDTYUPD_CDTYUPD_Pos) /**< \brief (PWM_CDTYUPD) Channel Duty-Cycle Update */
#define PWM_CDTYUPD_CDTYUPD(value) ((PWM_CDTYUPD_CDTYUPD_Msk & ((value) << PWM_CDTYUPD_CDTYUPD_Pos)))
/* -------- PWM_CPRD : (PWM Offset: N/A) PWM Channel Period Register -------- */
#define PWM_CPRD_CPRD_Pos 0
#define PWM_CPRD_CPRD_Msk (0xffffffu << PWM_CPRD_CPRD_Pos) /**< \brief (PWM_CPRD) Channel Period */
#define PWM_CPRD_CPRD(value) ((PWM_CPRD_CPRD_Msk & ((value) << PWM_CPRD_CPRD_Pos)))
/* -------- PWM_CPRDUPD : (PWM Offset: N/A) PWM Channel Period Update Register -------- */
#define PWM_CPRDUPD_CPRDUPD_Pos 0
#define PWM_CPRDUPD_CPRDUPD_Msk (0xffffffu << PWM_CPRDUPD_CPRDUPD_Pos) /**< \brief (PWM_CPRDUPD) Channel Period Update */
#define PWM_CPRDUPD_CPRDUPD(value) ((PWM_CPRDUPD_CPRDUPD_Msk & ((value) << PWM_CPRDUPD_CPRDUPD_Pos)))
/* -------- PWM_CCNT : (PWM Offset: N/A) PWM Channel Counter Register -------- */
#define PWM_CCNT_CNT_Pos 0
#define PWM_CCNT_CNT_Msk (0xffffffu << PWM_CCNT_CNT_Pos) /**< \brief (PWM_CCNT) Channel Counter Register */
/* -------- PWM_DT : (PWM Offset: N/A) PWM Channel Dead Time Register -------- */
#define PWM_DT_DTH_Pos 0
#define PWM_DT_DTH_Msk (0xffffu << PWM_DT_DTH_Pos) /**< \brief (PWM_DT) Dead-Time Value for PWMHx Output */
#define PWM_DT_DTH(value) ((PWM_DT_DTH_Msk & ((value) << PWM_DT_DTH_Pos)))
#define PWM_DT_DTL_Pos 16
#define PWM_DT_DTL_Msk (0xffffu << PWM_DT_DTL_Pos) /**< \brief (PWM_DT) Dead-Time Value for PWMLx Output */
#define PWM_DT_DTL(value) ((PWM_DT_DTL_Msk & ((value) << PWM_DT_DTL_Pos)))
/* -------- PWM_DTUPD : (PWM Offset: N/A) PWM Channel Dead Time Update Register -------- */
#define PWM_DTUPD_DTHUPD_Pos 0
#define PWM_DTUPD_DTHUPD_Msk (0xffffu << PWM_DTUPD_DTHUPD_Pos) /**< \brief (PWM_DTUPD) Dead-Time Value Update for PWMHx Output */
#define PWM_DTUPD_DTHUPD(value) ((PWM_DTUPD_DTHUPD_Msk & ((value) << PWM_DTUPD_DTHUPD_Pos)))
#define PWM_DTUPD_DTLUPD_Pos 16
#define PWM_DTUPD_DTLUPD_Msk (0xffffu << PWM_DTUPD_DTLUPD_Pos) /**< \brief (PWM_DTUPD) Dead-Time Value Update for PWMLx Output */
#define PWM_DTUPD_DTLUPD(value) ((PWM_DTUPD_DTLUPD_Msk & ((value) << PWM_DTUPD_DTLUPD_Pos)))

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Reset Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_RSTC Reset Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Rstc hardware registers */
typedef struct {
  WoReg RSTC_CR; /**< \brief (Rstc Offset: 0x00) Control Register */
  RoReg RSTC_SR; /**< \brief (Rstc Offset: 0x04) Status Register */
  RwReg RSTC_MR; /**< \brief (Rstc Offset: 0x08) Mode Register */
} Rstc;
#endif /* __ASSEMBLY__ */
/* -------- RSTC_CR : (RSTC Offset: 0x00) Control Register -------- */
#define RSTC_CR_PROCRST (0x1u << 0) /**< \brief (RSTC_CR) Processor Reset */
#define RSTC_CR_PERRST (0x1u << 2) /**< \brief (RSTC_CR) Peripheral Reset */
#define RSTC_CR_EXTRST (0x1u << 3) /**< \brief (RSTC_CR) External Reset */
#define RSTC_CR_KEY_Pos 24
#define RSTC_CR_KEY_Msk (0xffu << RSTC_CR_KEY_Pos) /**< \brief (RSTC_CR) Password */
#define RSTC_CR_KEY(value) ((RSTC_CR_KEY_Msk & ((value) << RSTC_CR_KEY_Pos)))
/* -------- RSTC_SR : (RSTC Offset: 0x04) Status Register -------- */
#define RSTC_SR_URSTS (0x1u << 0) /**< \brief (RSTC_SR) User Reset Status */
#define RSTC_SR_RSTTYP_Pos 8
#define RSTC_SR_RSTTYP_Msk (0x7u << RSTC_SR_RSTTYP_Pos) /**< \brief (RSTC_SR) Reset Type */
#define RSTC_SR_NRSTL (0x1u << 16) /**< \brief (RSTC_SR) NRST Pin Level */
#define RSTC_SR_SRCMP (0x1u << 17) /**< \brief (RSTC_SR) Software Reset Command in Progress */
/* -------- RSTC_MR : (RSTC Offset: 0x08) Mode Register -------- */
#define RSTC_MR_URSTEN (0x1u << 0) /**< \brief (RSTC_MR) User Reset Enable */
#define RSTC_MR_URSTIEN (0x1u << 4) /**< \brief (RSTC_MR) User Reset Interrupt Enable */
#define RSTC_MR_ERSTL_Pos 8
#define RSTC_MR_ERSTL_Msk (0xfu << RSTC_MR_ERSTL_Pos) /**< \brief (RSTC_MR) External Reset Length */
#define RSTC_MR_ERSTL(value) ((RSTC_MR_ERSTL_Msk & ((value) << RSTC_MR_ERSTL_Pos)))
#define RSTC_MR_KEY_Pos 24
#define RSTC_MR_KEY_Msk (0xffu << RSTC_MR_KEY_Pos) /**< \brief (RSTC_MR) Password */
#define RSTC_MR_KEY(value) ((RSTC_MR_KEY_Msk & ((value) << RSTC_MR_KEY_Pos)))

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Real-time Clock */
/* ============================================================================= */
/** \addtogroup SAM3S16_RTC Real-time Clock */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Rtc hardware registers */
typedef struct {
  RwReg RTC_CR;     /**< \brief (Rtc Offset: 0x00) Control Register */
  RwReg RTC_MR;     /**< \brief (Rtc Offset: 0x04) Mode Register */
  RwReg RTC_TIMR;   /**< \brief (Rtc Offset: 0x08) Time Register */
  RwReg RTC_CALR;   /**< \brief (Rtc Offset: 0x0C) Calendar Register */
  RwReg RTC_TIMALR; /**< \brief (Rtc Offset: 0x10) Time Alarm Register */
  RwReg RTC_CALALR; /**< \brief (Rtc Offset: 0x14) Calendar Alarm Register */
  RoReg RTC_SR;     /**< \brief (Rtc Offset: 0x18) Status Register */
  WoReg RTC_SCCR;   /**< \brief (Rtc Offset: 0x1C) Status Clear Command Register */
  WoReg RTC_IER;    /**< \brief (Rtc Offset: 0x20) Interrupt Enable Register */
  WoReg RTC_IDR;    /**< \brief (Rtc Offset: 0x24) Interrupt Disable Register */
  RoReg RTC_IMR;    /**< \brief (Rtc Offset: 0x28) Interrupt Mask Register */
  RoReg RTC_VER;    /**< \brief (Rtc Offset: 0x2C) Valid Entry Register */
} Rtc;
#endif /* __ASSEMBLY__ */
/* -------- RTC_CR : (RTC Offset: 0x00) Control Register -------- */
#define RTC_CR_UPDTIM (0x1u << 0) /**< \brief (RTC_CR) Update Request Time Register */
#define RTC_CR_UPDCAL (0x1u << 1) /**< \brief (RTC_CR) Update Request Calendar Register */
#define RTC_CR_TIMEVSEL_Pos 8
#define RTC_CR_TIMEVSEL_Msk (0x3u << RTC_CR_TIMEVSEL_Pos) /**< \brief (RTC_CR) Time Event Selection */
#define   RTC_CR_TIMEVSEL_MINUTE (0x0u << 8) /**< \brief (RTC_CR) Minute change */
#define   RTC_CR_TIMEVSEL_HOUR (0x1u << 8) /**< \brief (RTC_CR) Hour change */
#define   RTC_CR_TIMEVSEL_MIDNIGHT (0x2u << 8) /**< \brief (RTC_CR) Every day at midnight */
#define   RTC_CR_TIMEVSEL_NOON (0x3u << 8) /**< \brief (RTC_CR) Every day at noon */
#define RTC_CR_CALEVSEL_Pos 16
#define RTC_CR_CALEVSEL_Msk (0x3u << RTC_CR_CALEVSEL_Pos) /**< \brief (RTC_CR) Calendar Event Selection */
#define   RTC_CR_CALEVSEL_WEEK (0x0u << 16) /**< \brief (RTC_CR) Week change (every Monday at time 00:00:00) */
#define   RTC_CR_CALEVSEL_MONTH (0x1u << 16) /**< \brief (RTC_CR) Month change (every 01 of each month at time 00:00:00) */
#define   RTC_CR_CALEVSEL_YEAR (0x2u << 16) /**< \brief (RTC_CR) Year change (every January 1 at time 00:00:00) */
/* -------- RTC_MR : (RTC Offset: 0x04) Mode Register -------- */
#define RTC_MR_HRMOD (0x1u << 0) /**< \brief (RTC_MR) 12-/24-hour Mode */
/* -------- RTC_TIMR : (RTC Offset: 0x08) Time Register -------- */
#define RTC_TIMR_SEC_Pos 0
#define RTC_TIMR_SEC_Msk (0x7fu << RTC_TIMR_SEC_Pos) /**< \brief (RTC_TIMR) Current Second */
#define RTC_TIMR_SEC(value) ((RTC_TIMR_SEC_Msk & ((value) << RTC_TIMR_SEC_Pos)))
#define RTC_TIMR_MIN_Pos 8
#define RTC_TIMR_MIN_Msk (0x7fu << RTC_TIMR_MIN_Pos) /**< \brief (RTC_TIMR) Current Minute */
#define RTC_TIMR_MIN(value) ((RTC_TIMR_MIN_Msk & ((value) << RTC_TIMR_MIN_Pos)))
#define RTC_TIMR_HOUR_Pos 16
#define RTC_TIMR_HOUR_Msk (0x3fu << RTC_TIMR_HOUR_Pos) /**< \brief (RTC_TIMR) Current Hour */
#define RTC_TIMR_HOUR(value) ((RTC_TIMR_HOUR_Msk & ((value) << RTC_TIMR_HOUR_Pos)))
#define RTC_TIMR_AMPM (0x1u << 22) /**< \brief (RTC_TIMR) Ante Meridiem Post Meridiem Indicator */
/* -------- RTC_CALR : (RTC Offset: 0x0C) Calendar Register -------- */
#define RTC_CALR_CENT_Pos 0
#define RTC_CALR_CENT_Msk (0x7fu << RTC_CALR_CENT_Pos) /**< \brief (RTC_CALR) Current Century */
#define RTC_CALR_CENT(value) ((RTC_CALR_CENT_Msk & ((value) << RTC_CALR_CENT_Pos)))
#define RTC_CALR_YEAR_Pos 8
#define RTC_CALR_YEAR_Msk (0xffu << RTC_CALR_YEAR_Pos) /**< \brief (RTC_CALR) Current Year */
#define RTC_CALR_YEAR(value) ((RTC_CALR_YEAR_Msk & ((value) << RTC_CALR_YEAR_Pos)))
#define RTC_CALR_MONTH_Pos 16
#define RTC_CALR_MONTH_Msk (0x1fu << RTC_CALR_MONTH_Pos) /**< \brief (RTC_CALR) Current Month */
#define RTC_CALR_MONTH(value) ((RTC_CALR_MONTH_Msk & ((value) << RTC_CALR_MONTH_Pos)))
#define RTC_CALR_DAY_Pos 21
#define RTC_CALR_DAY_Msk (0x7u << RTC_CALR_DAY_Pos) /**< \brief (RTC_CALR) Current Day in Current Week */
#define RTC_CALR_DAY(value) ((RTC_CALR_DAY_Msk & ((value) << RTC_CALR_DAY_Pos)))
#define RTC_CALR_DATE_Pos 24
#define RTC_CALR_DATE_Msk (0x3fu << RTC_CALR_DATE_Pos) /**< \brief (RTC_CALR) Current Day in Current Month */
#define RTC_CALR_DATE(value) ((RTC_CALR_DATE_Msk & ((value) << RTC_CALR_DATE_Pos)))
/* -------- RTC_TIMALR : (RTC Offset: 0x10) Time Alarm Register -------- */
#define RTC_TIMALR_SEC_Pos 0
#define RTC_TIMALR_SEC_Msk (0x7fu << RTC_TIMALR_SEC_Pos) /**< \brief (RTC_TIMALR) Second Alarm */
#define RTC_TIMALR_SEC(value) ((RTC_TIMALR_SEC_Msk & ((value) << RTC_TIMALR_SEC_Pos)))
#define RTC_TIMALR_SECEN (0x1u << 7) /**< \brief (RTC_TIMALR) Second Alarm Enable */
#define RTC_TIMALR_MIN_Pos 8
#define RTC_TIMALR_MIN_Msk (0x7fu << RTC_TIMALR_MIN_Pos) /**< \brief (RTC_TIMALR) Minute Alarm */
#define RTC_TIMALR_MIN(value) ((RTC_TIMALR_MIN_Msk & ((value) << RTC_TIMALR_MIN_Pos)))
#define RTC_TIMALR_MINEN (0x1u << 15) /**< \brief (RTC_TIMALR) Minute Alarm Enable */
#define RTC_TIMALR_HOUR_Pos 16
#define RTC_TIMALR_HOUR_Msk (0x3fu << RTC_TIMALR_HOUR_Pos) /**< \brief (RTC_TIMALR) Hour Alarm */
#define RTC_TIMALR_HOUR(value) ((RTC_TIMALR_HOUR_Msk & ((value) << RTC_TIMALR_HOUR_Pos)))
#define RTC_TIMALR_AMPM (0x1u << 22) /**< \brief (RTC_TIMALR) AM/PM Indicator */
#define RTC_TIMALR_HOUREN (0x1u << 23) /**< \brief (RTC_TIMALR) Hour Alarm Enable */
/* -------- RTC_CALALR : (RTC Offset: 0x14) Calendar Alarm Register -------- */
#define RTC_CALALR_MONTH_Pos 16
#define RTC_CALALR_MONTH_Msk (0x1fu << RTC_CALALR_MONTH_Pos) /**< \brief (RTC_CALALR) Month Alarm */
#define RTC_CALALR_MONTH(value) ((RTC_CALALR_MONTH_Msk & ((value) << RTC_CALALR_MONTH_Pos)))
#define RTC_CALALR_MTHEN (0x1u << 23) /**< \brief (RTC_CALALR) Month Alarm Enable */
#define RTC_CALALR_DATE_Pos 24
#define RTC_CALALR_DATE_Msk (0x3fu << RTC_CALALR_DATE_Pos) /**< \brief (RTC_CALALR) Date Alarm */
#define RTC_CALALR_DATE(value) ((RTC_CALALR_DATE_Msk & ((value) << RTC_CALALR_DATE_Pos)))
#define RTC_CALALR_DATEEN (0x1u << 31) /**< \brief (RTC_CALALR) Date Alarm Enable */
/* -------- RTC_SR : (RTC Offset: 0x18) Status Register -------- */
#define RTC_SR_ACKUPD (0x1u << 0) /**< \brief (RTC_SR) Acknowledge for Update */
#define RTC_SR_ALARM (0x1u << 1) /**< \brief (RTC_SR) Alarm Flag */
#define RTC_SR_SEC (0x1u << 2) /**< \brief (RTC_SR) Second Event */
#define RTC_SR_TIMEV (0x1u << 3) /**< \brief (RTC_SR) Time Event */
#define RTC_SR_CALEV (0x1u << 4) /**< \brief (RTC_SR) Calendar Event */
/* -------- RTC_SCCR : (RTC Offset: 0x1C) Status Clear Command Register -------- */
#define RTC_SCCR_ACKCLR (0x1u << 0) /**< \brief (RTC_SCCR) Acknowledge Clear */
#define RTC_SCCR_ALRCLR (0x1u << 1) /**< \brief (RTC_SCCR) Alarm Clear */
#define RTC_SCCR_SECCLR (0x1u << 2) /**< \brief (RTC_SCCR) Second Clear */
#define RTC_SCCR_TIMCLR (0x1u << 3) /**< \brief (RTC_SCCR) Time Clear */
#define RTC_SCCR_CALCLR (0x1u << 4) /**< \brief (RTC_SCCR) Calendar Clear */
/* -------- RTC_IER : (RTC Offset: 0x20) Interrupt Enable Register -------- */
#define RTC_IER_ACKEN (0x1u << 0) /**< \brief (RTC_IER) Acknowledge Update Interrupt Enable */
#define RTC_IER_ALREN (0x1u << 1) /**< \brief (RTC_IER) Alarm Interrupt Enable */
#define RTC_IER_SECEN (0x1u << 2) /**< \brief (RTC_IER) Second Event Interrupt Enable */
#define RTC_IER_TIMEN (0x1u << 3) /**< \brief (RTC_IER) Time Event Interrupt Enable */
#define RTC_IER_CALEN (0x1u << 4) /**< \brief (RTC_IER) Calendar Event Interrupt Enable */
/* -------- RTC_IDR : (RTC Offset: 0x24) Interrupt Disable Register -------- */
#define RTC_IDR_ACKDIS (0x1u << 0) /**< \brief (RTC_IDR) Acknowledge Update Interrupt Disable */
#define RTC_IDR_ALRDIS (0x1u << 1) /**< \brief (RTC_IDR) Alarm Interrupt Disable */
#define RTC_IDR_SECDIS (0x1u << 2) /**< \brief (RTC_IDR) Second Event Interrupt Disable */
#define RTC_IDR_TIMDIS (0x1u << 3) /**< \brief (RTC_IDR) Time Event Interrupt Disable */
#define RTC_IDR_CALDIS (0x1u << 4) /**< \brief (RTC_IDR) Calendar Event Interrupt Disable */
/* -------- RTC_IMR : (RTC Offset: 0x28) Interrupt Mask Register -------- */
#define RTC_IMR_ACK (0x1u << 0) /**< \brief (RTC_IMR) Acknowledge Update Interrupt Mask */
#define RTC_IMR_ALR (0x1u << 1) /**< \brief (RTC_IMR) Alarm Interrupt Mask */
#define RTC_IMR_SEC (0x1u << 2) /**< \brief (RTC_IMR) Second Event Interrupt Mask */
#define RTC_IMR_TIM (0x1u << 3) /**< \brief (RTC_IMR) Time Event Interrupt Mask */
#define RTC_IMR_CAL (0x1u << 4) /**< \brief (RTC_IMR) Calendar Event Interrupt Mask */
/* -------- RTC_VER : (RTC Offset: 0x2C) Valid Entry Register -------- */
#define RTC_VER_NVTIM (0x1u << 0) /**< \brief (RTC_VER) Non-valid Time */
#define RTC_VER_NVCAL (0x1u << 1) /**< \brief (RTC_VER) Non-valid Calendar */
#define RTC_VER_NVTIMALR (0x1u << 2) /**< \brief (RTC_VER) Non-valid Time Alarm */
#define RTC_VER_NVCALALR (0x1u << 3) /**< \brief (RTC_VER) Non-valid Calendar Alarm */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Real-time Timer */
/* ============================================================================= */
/** \addtogroup SAM3S16_RTT Real-time Timer */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Rtt hardware registers */
typedef struct {
  RwReg RTT_MR; /**< \brief (Rtt Offset: 0x00) Mode Register */
  RwReg RTT_AR; /**< \brief (Rtt Offset: 0x04) Alarm Register */
  RoReg RTT_VR; /**< \brief (Rtt Offset: 0x08) Value Register */
  RoReg RTT_SR; /**< \brief (Rtt Offset: 0x0C) Status Register */
} Rtt;
#endif /* __ASSEMBLY__ */
/* -------- RTT_MR : (RTT Offset: 0x00) Mode Register -------- */
#define RTT_MR_RTPRES_Pos 0
#define RTT_MR_RTPRES_Msk (0xffffu << RTT_MR_RTPRES_Pos) /**< \brief (RTT_MR) Real-time Timer Prescaler Value */
#define RTT_MR_RTPRES(value) ((RTT_MR_RTPRES_Msk & ((value) << RTT_MR_RTPRES_Pos)))
#define RTT_MR_ALMIEN (0x1u << 16) /**< \brief (RTT_MR) Alarm Interrupt Enable */
#define RTT_MR_RTTINCIEN (0x1u << 17) /**< \brief (RTT_MR) Real-time Timer Increment Interrupt Enable */
#define RTT_MR_RTTRST (0x1u << 18) /**< \brief (RTT_MR) Real-time Timer Restart */
/* -------- RTT_AR : (RTT Offset: 0x04) Alarm Register -------- */
#define RTT_AR_ALMV_Pos 0
#define RTT_AR_ALMV_Msk (0xffffffffu << RTT_AR_ALMV_Pos) /**< \brief (RTT_AR) Alarm Value */
#define RTT_AR_ALMV(value) ((RTT_AR_ALMV_Msk & ((value) << RTT_AR_ALMV_Pos)))
/* -------- RTT_VR : (RTT Offset: 0x08) Value Register -------- */
#define RTT_VR_CRTV_Pos 0
#define RTT_VR_CRTV_Msk (0xffffffffu << RTT_VR_CRTV_Pos) /**< \brief (RTT_VR) Current Real-time Value */
/* -------- RTT_SR : (RTT Offset: 0x0C) Status Register -------- */
#define RTT_SR_ALMS (0x1u << 0) /**< \brief (RTT_SR) Real-time Alarm Status */
#define RTT_SR_RTTINC (0x1u << 1) /**< \brief (RTT_SR) Real-time Timer Increment */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Static Memory Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_SMC Static Memory Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief SmcCs_number hardware registers */
typedef struct {
  RwReg         SMC_SETUP;        /**< \brief (SmcCs_number Offset: 0x0) SMC Setup Register */
  RwReg         SMC_PULSE;        /**< \brief (SmcCs_number Offset: 0x4) SMC Pulse Register */
  RwReg         SMC_CYCLE;        /**< \brief (SmcCs_number Offset: 0x8) SMC Cycle Register */
  RwReg         SMC_MODE;         /**< \brief (SmcCs_number Offset: 0xC) SMC Mode Register */
} SmcCs_number;
/** \brief Smc hardware registers */
#define SMCCS_NUMBER_NUMBER 5
typedef struct {
  SmcCs_number  SMC_CS_NUMBER[SMCCS_NUMBER_NUMBER]; /**< \brief (Smc Offset: 0x0) CS_number = 0 .. 4 */
  RoReg         Reserved1[12];
  RwReg         SMC_OCMS;         /**< \brief (Smc Offset: 0x80) SMC OCMS MODE Register */
  WoReg         SMC_KEY1;         /**< \brief (Smc Offset: 0x84) SMC OCMS KEY1 Register */
  WoReg         SMC_KEY2;         /**< \brief (Smc Offset: 0x88) SMC OCMS KEY2 Register */
  RoReg         Reserved2[22];
  RwReg         SMC_WPMR;         /**< \brief (Smc Offset: 0xE4) SMC Write Protect Mode Register */
  RoReg         SMC_WPSR;         /**< \brief (Smc Offset: 0xE8) SMC Write Protect Status Register */
} Smc;
#endif /* __ASSEMBLY__ */
/* -------- SMC_SETUP : (SMC Offset: N/A) SMC Setup Register -------- */
#define SMC_SETUP_NWE_SETUP_Pos 0
#define SMC_SETUP_NWE_SETUP_Msk (0x3fu << SMC_SETUP_NWE_SETUP_Pos) /**< \brief (SMC_SETUP) NWE Setup Length */
#define SMC_SETUP_NWE_SETUP(value) ((SMC_SETUP_NWE_SETUP_Msk & ((value) << SMC_SETUP_NWE_SETUP_Pos)))
#define SMC_SETUP_NCS_WR_SETUP_Pos 8
#define SMC_SETUP_NCS_WR_SETUP_Msk (0x3fu << SMC_SETUP_NCS_WR_SETUP_Pos) /**< \brief (SMC_SETUP) NCS Setup Length in WRITE Access */
#define SMC_SETUP_NCS_WR_SETUP(value) ((SMC_SETUP_NCS_WR_SETUP_Msk & ((value) << SMC_SETUP_NCS_WR_SETUP_Pos)))
#define SMC_SETUP_NRD_SETUP_Pos 16
#define SMC_SETUP_NRD_SETUP_Msk (0x3fu << SMC_SETUP_NRD_SETUP_Pos) /**< \brief (SMC_SETUP) NRD Setup Length */
#define SMC_SETUP_NRD_SETUP(value) ((SMC_SETUP_NRD_SETUP_Msk & ((value) << SMC_SETUP_NRD_SETUP_Pos)))
#define SMC_SETUP_NCS_RD_SETUP_Pos 24
#define SMC_SETUP_NCS_RD_SETUP_Msk (0x3fu << SMC_SETUP_NCS_RD_SETUP_Pos) /**< \brief (SMC_SETUP) NCS Setup Length in READ Access */
#define SMC_SETUP_NCS_RD_SETUP(value) ((SMC_SETUP_NCS_RD_SETUP_Msk & ((value) << SMC_SETUP_NCS_RD_SETUP_Pos)))
/* -------- SMC_PULSE : (SMC Offset: N/A) SMC Pulse Register -------- */
#define SMC_PULSE_NWE_PULSE_Pos 0
#define SMC_PULSE_NWE_PULSE_Msk (0x7fu << SMC_PULSE_NWE_PULSE_Pos) /**< \brief (SMC_PULSE) NWE Pulse Length */
#define SMC_PULSE_NWE_PULSE(value) ((SMC_PULSE_NWE_PULSE_Msk & ((value) << SMC_PULSE_NWE_PULSE_Pos)))
#define SMC_PULSE_NCS_WR_PULSE_Pos 8
#define SMC_PULSE_NCS_WR_PULSE_Msk (0x7fu << SMC_PULSE_NCS_WR_PULSE_Pos) /**< \brief (SMC_PULSE) NCS Pulse Length in WRITE Access */
#define SMC_PULSE_NCS_WR_PULSE(value) ((SMC_PULSE_NCS_WR_PULSE_Msk & ((value) << SMC_PULSE_NCS_WR_PULSE_Pos)))
#define SMC_PULSE_NRD_PULSE_Pos 16
#define SMC_PULSE_NRD_PULSE_Msk (0x7fu << SMC_PULSE_NRD_PULSE_Pos) /**< \brief (SMC_PULSE) NRD Pulse Length */
#define SMC_PULSE_NRD_PULSE(value) ((SMC_PULSE_NRD_PULSE_Msk & ((value) << SMC_PULSE_NRD_PULSE_Pos)))
#define SMC_PULSE_NCS_RD_PULSE_Pos 24
#define SMC_PULSE_NCS_RD_PULSE_Msk (0x7fu << SMC_PULSE_NCS_RD_PULSE_Pos) /**< \brief (SMC_PULSE) NCS Pulse Length in READ Access */
#define SMC_PULSE_NCS_RD_PULSE(value) ((SMC_PULSE_NCS_RD_PULSE_Msk & ((value) << SMC_PULSE_NCS_RD_PULSE_Pos)))
/* -------- SMC_CYCLE : (SMC Offset: N/A) SMC Cycle Register -------- */
#define SMC_CYCLE_NWE_CYCLE_Pos 0
#define SMC_CYCLE_NWE_CYCLE_Msk (0x1ffu << SMC_CYCLE_NWE_CYCLE_Pos) /**< \brief (SMC_CYCLE) Total Write Cycle Length */
#define SMC_CYCLE_NWE_CYCLE(value) ((SMC_CYCLE_NWE_CYCLE_Msk & ((value) << SMC_CYCLE_NWE_CYCLE_Pos)))
#define SMC_CYCLE_NRD_CYCLE_Pos 16
#define SMC_CYCLE_NRD_CYCLE_Msk (0x1ffu << SMC_CYCLE_NRD_CYCLE_Pos) /**< \brief (SMC_CYCLE) Total Read Cycle Length */
#define SMC_CYCLE_NRD_CYCLE(value) ((SMC_CYCLE_NRD_CYCLE_Msk & ((value) << SMC_CYCLE_NRD_CYCLE_Pos)))
/* -------- SMC_MODE : (SMC Offset: N/A) SMC Mode Register -------- */
#define SMC_MODE_READ_MODE (0x1u << 0) /**< \brief (SMC_MODE)  */
#define SMC_MODE_WRITE_MODE (0x1u << 1) /**< \brief (SMC_MODE)  */
#define SMC_MODE_EXNW_MODE_Pos 4
#define SMC_MODE_EXNW_MODE_Msk (0x3u << SMC_MODE_EXNW_MODE_Pos) /**< \brief (SMC_MODE) NWAIT Mode */
#define   SMC_MODE_EXNW_MODE_DISABLED (0x0u << 4) /**< \brief (SMC_MODE) Disabled */
#define   SMC_MODE_EXNW_MODE_FROZEN (0x2u << 4) /**< \brief (SMC_MODE) Frozen Mode */
#define   SMC_MODE_EXNW_MODE_READY (0x3u << 4) /**< \brief (SMC_MODE) Ready Mode */
#define SMC_MODE_DBW_Pos 12
#define SMC_MODE_DBW_Msk (0x3u << SMC_MODE_DBW_Pos) /**< \brief (SMC_MODE) Data Bus Width */
#define   SMC_MODE_DBW_8_BIT (0x0u << 12) /**< \brief (SMC_MODE) 8-bit bus */
#define   SMC_MODE_DBW_16_BIT (0x1u << 12) /**< \brief (SMC_MODE) 16-bit bus */
#define   SMC_MODE_DBW_32_BIT (0x2u << 12) /**< \brief (SMC_MODE) 32-bit bus */
#define SMC_MODE_TDF_CYCLES_Pos 16
#define SMC_MODE_TDF_CYCLES_Msk (0xfu << SMC_MODE_TDF_CYCLES_Pos) /**< \brief (SMC_MODE) Data Float Time */
#define SMC_MODE_TDF_CYCLES(value) ((SMC_MODE_TDF_CYCLES_Msk & ((value) << SMC_MODE_TDF_CYCLES_Pos)))
#define SMC_MODE_TDF_MODE (0x1u << 20) /**< \brief (SMC_MODE) TDF Optimization */
#define SMC_MODE_PMEN (0x1u << 24) /**< \brief (SMC_MODE) Page Mode Enabled */
#define SMC_MODE_PS_Pos 28
#define SMC_MODE_PS_Msk (0x3u << SMC_MODE_PS_Pos) /**< \brief (SMC_MODE) Page Size */
#define   SMC_MODE_PS_4_BYTE (0x0u << 28) /**< \brief (SMC_MODE) 4-byte page */
#define   SMC_MODE_PS_8_BYTE (0x1u << 28) /**< \brief (SMC_MODE) 8-byte page */
#define   SMC_MODE_PS_16_BYTE (0x2u << 28) /**< \brief (SMC_MODE) 16-byte page */
#define   SMC_MODE_PS_32_BYTE (0x3u << 28) /**< \brief (SMC_MODE) 32-byte page */
/* -------- SMC_OCMS : (SMC Offset: 0x80) SMC OCMS MODE Register -------- */
#define SMC_OCMS_SMSE (0x1u << 0) /**< \brief (SMC_OCMS) Static Memory Controller Scrambling Enable */
#define SMC_OCMS_CS0SE (0x1u << 16) /**< \brief (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable */
#define SMC_OCMS_CS1SE (0x1u << 17) /**< \brief (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable */
#define SMC_OCMS_CS2SE (0x1u << 18) /**< \brief (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable */
#define SMC_OCMS_CS3SE (0x1u << 19) /**< \brief (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable */
/* -------- SMC_KEY1 : (SMC Offset: 0x84) SMC OCMS KEY1 Register -------- */
#define SMC_KEY1_KEY1_Pos 0
#define SMC_KEY1_KEY1_Msk (0xffffffffu << SMC_KEY1_KEY1_Pos) /**< \brief (SMC_KEY1) Off Chip Memory Scrambling (OCMS) Key Part 1 */
#define SMC_KEY1_KEY1(value) ((SMC_KEY1_KEY1_Msk & ((value) << SMC_KEY1_KEY1_Pos)))
/* -------- SMC_KEY2 : (SMC Offset: 0x88) SMC OCMS KEY2 Register -------- */
#define SMC_KEY2_KEY2_Pos 0
#define SMC_KEY2_KEY2_Msk (0xffffffffu << SMC_KEY2_KEY2_Pos) /**< \brief (SMC_KEY2) Off Chip Memory Scrambling (OCMS) Key Part 2 */
#define SMC_KEY2_KEY2(value) ((SMC_KEY2_KEY2_Msk & ((value) << SMC_KEY2_KEY2_Pos)))
/* -------- SMC_WPMR : (SMC Offset: 0xE4) SMC Write Protect Mode Register -------- */
#define SMC_WPMR_WPEN (0x1u << 0) /**< \brief (SMC_WPMR) Write Protect Enable */
#define SMC_WPMR_WPKEY_Pos 8
#define SMC_WPMR_WPKEY_Msk (0xffffffu << SMC_WPMR_WPKEY_Pos) /**< \brief (SMC_WPMR) Write Protect KEY */
#define SMC_WPMR_WPKEY(value) ((SMC_WPMR_WPKEY_Msk & ((value) << SMC_WPMR_WPKEY_Pos)))
/* -------- SMC_WPSR : (SMC Offset: 0xE8) SMC Write Protect Status Register -------- */
#define SMC_WPSR_WPVS (0x1u << 0) /**< \brief (SMC_WPSR) Write Protect Enable */
#define SMC_WPSR_WPVSRC_Pos 8
#define SMC_WPSR_WPVSRC_Msk (0xffffu << SMC_WPSR_WPVSRC_Pos) /**< \brief (SMC_WPSR) Write Protect Violation Source */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Serial Peripheral Interface */
/* ============================================================================= */
/** \addtogroup SAM3S16_SPI Serial Peripheral Interface */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Spi hardware registers */
typedef struct {
  WoReg SPI_CR;        /**< \brief (Spi Offset: 0x00) Control Register */
  RwReg SPI_MR;        /**< \brief (Spi Offset: 0x04) Mode Register */
  RoReg SPI_RDR;       /**< \brief (Spi Offset: 0x08) Receive Data Register */
  WoReg SPI_TDR;       /**< \brief (Spi Offset: 0x0C) Transmit Data Register */
  RoReg SPI_SR;        /**< \brief (Spi Offset: 0x10) Status Register */
  WoReg SPI_IER;       /**< \brief (Spi Offset: 0x14) Interrupt Enable Register */
  WoReg SPI_IDR;       /**< \brief (Spi Offset: 0x18) Interrupt Disable Register */
  RoReg SPI_IMR;       /**< \brief (Spi Offset: 0x1C) Interrupt Mask Register */
  RoReg Reserved1[4];
  RwReg SPI_CSR[4];    /**< \brief (Spi Offset: 0x30) Chip Select Register */
  RoReg Reserved2[41];
  RwReg SPI_WPMR;      /**< \brief (Spi Offset: 0xE4) Write Protection Control Register */
  RoReg SPI_WPSR;      /**< \brief (Spi Offset: 0xE8) Write Protection Status Register */
  RoReg Reserved3[5];
  RwReg SPI_RPR;       /**< \brief (Spi Offset: 0x100) Receive Pointer Register */
  RwReg SPI_RCR;       /**< \brief (Spi Offset: 0x104) Receive Counter Register */
  RwReg SPI_TPR;       /**< \brief (Spi Offset: 0x108) Transmit Pointer Register */
  RwReg SPI_TCR;       /**< \brief (Spi Offset: 0x10C) Transmit Counter Register */
  RwReg SPI_RNPR;      /**< \brief (Spi Offset: 0x110) Receive Next Pointer Register */
  RwReg SPI_RNCR;      /**< \brief (Spi Offset: 0x114) Receive Next Counter Register */
  RwReg SPI_TNPR;      /**< \brief (Spi Offset: 0x118) Transmit Next Pointer Register */
  RwReg SPI_TNCR;      /**< \brief (Spi Offset: 0x11C) Transmit Next Counter Register */
  WoReg SPI_PTCR;      /**< \brief (Spi Offset: 0x120) Transfer Control Register */
  RoReg SPI_PTSR;      /**< \brief (Spi Offset: 0x124) Transfer Status Register */
} Spi;
#endif /* __ASSEMBLY__ */
/* -------- SPI_CR : (SPI Offset: 0x00) Control Register -------- */
#define SPI_CR_SPIEN (0x1u << 0) /**< \brief (SPI_CR) SPI Enable */
#define SPI_CR_SPIDIS (0x1u << 1) /**< \brief (SPI_CR) SPI Disable */
#define SPI_CR_SWRST (0x1u << 7) /**< \brief (SPI_CR) SPI Software Reset */
#define SPI_CR_LASTXFER (0x1u << 24) /**< \brief (SPI_CR) Last Transfer */
/* -------- SPI_MR : (SPI Offset: 0x04) Mode Register -------- */
#define SPI_MR_MSTR (0x1u << 0) /**< \brief (SPI_MR) Master/Slave Mode */
#define SPI_MR_PS (0x1u << 1) /**< \brief (SPI_MR) Peripheral Select */
#define SPI_MR_PCSDEC (0x1u << 2) /**< \brief (SPI_MR) Chip Select Decode */
#define SPI_MR_MODFDIS (0x1u << 4) /**< \brief (SPI_MR) Mode Fault Detection */
#define SPI_MR_WDRBT (0x1u << 5) /**< \brief (SPI_MR) Wait Data Read Before Transfer */
#define SPI_MR_LLB (0x1u << 7) /**< \brief (SPI_MR) Local Loopback Enable */
#define SPI_MR_PCS_Pos 16
#define SPI_MR_PCS_Msk (0xfu << SPI_MR_PCS_Pos) /**< \brief (SPI_MR) Peripheral Chip Select */
#define SPI_MR_PCS(value) ((SPI_MR_PCS_Msk & ((value) << SPI_MR_PCS_Pos)))
#define SPI_MR_DLYBCS_Pos 24
#define SPI_MR_DLYBCS_Msk (0xffu << SPI_MR_DLYBCS_Pos) /**< \brief (SPI_MR) Delay Between Chip Selects */
#define SPI_MR_DLYBCS(value) ((SPI_MR_DLYBCS_Msk & ((value) << SPI_MR_DLYBCS_Pos)))
/* -------- SPI_RDR : (SPI Offset: 0x08) Receive Data Register -------- */
#define SPI_RDR_RD_Pos 0
#define SPI_RDR_RD_Msk (0xffffu << SPI_RDR_RD_Pos) /**< \brief (SPI_RDR) Receive Data */
#define SPI_RDR_PCS_Pos 16
#define SPI_RDR_PCS_Msk (0xfu << SPI_RDR_PCS_Pos) /**< \brief (SPI_RDR) Peripheral Chip Select */
/* -------- SPI_TDR : (SPI Offset: 0x0C) Transmit Data Register -------- */
#define SPI_TDR_TD_Pos 0
#define SPI_TDR_TD_Msk (0xffffu << SPI_TDR_TD_Pos) /**< \brief (SPI_TDR) Transmit Data */
#define SPI_TDR_TD(value) ((SPI_TDR_TD_Msk & ((value) << SPI_TDR_TD_Pos)))
#define SPI_TDR_PCS_Pos 16
#define SPI_TDR_PCS_Msk (0xfu << SPI_TDR_PCS_Pos) /**< \brief (SPI_TDR) Peripheral Chip Select */
#define SPI_TDR_PCS(value) ((SPI_TDR_PCS_Msk & ((value) << SPI_TDR_PCS_Pos)))
#define SPI_TDR_LASTXFER (0x1u << 24) /**< \brief (SPI_TDR) Last Transfer */
/* -------- SPI_SR : (SPI Offset: 0x10) Status Register -------- */
#define SPI_SR_RDRF (0x1u << 0) /**< \brief (SPI_SR) Receive Data Register Full */
#define SPI_SR_TDRE (0x1u << 1) /**< \brief (SPI_SR) Transmit Data Register Empty */
#define SPI_SR_MODF (0x1u << 2) /**< \brief (SPI_SR) Mode Fault Error */
#define SPI_SR_OVRES (0x1u << 3) /**< \brief (SPI_SR) Overrun Error Status */
#define SPI_SR_ENDRX (0x1u << 4) /**< \brief (SPI_SR) End of RX buffer */
#define SPI_SR_ENDTX (0x1u << 5) /**< \brief (SPI_SR) End of TX buffer */
#define SPI_SR_RXBUFF (0x1u << 6) /**< \brief (SPI_SR) RX Buffer Full */
#define SPI_SR_TXBUFE (0x1u << 7) /**< \brief (SPI_SR) TX Buffer Empty */
#define SPI_SR_NSSR (0x1u << 8) /**< \brief (SPI_SR) NSS Rising */
#define SPI_SR_TXEMPTY (0x1u << 9) /**< \brief (SPI_SR) Transmission Registers Empty */
#define SPI_SR_UNDES (0x1u << 10) /**< \brief (SPI_SR) Underrun Error Status (Slave Mode Only) */
#define SPI_SR_SPIENS (0x1u << 16) /**< \brief (SPI_SR) SPI Enable Status */
/* -------- SPI_IER : (SPI Offset: 0x14) Interrupt Enable Register -------- */
#define SPI_IER_RDRF (0x1u << 0) /**< \brief (SPI_IER) Receive Data Register Full Interrupt Enable */
#define SPI_IER_TDRE (0x1u << 1) /**< \brief (SPI_IER) SPI Transmit Data Register Empty Interrupt Enable */
#define SPI_IER_MODF (0x1u << 2) /**< \brief (SPI_IER) Mode Fault Error Interrupt Enable */
#define SPI_IER_OVRES (0x1u << 3) /**< \brief (SPI_IER) Overrun Error Interrupt Enable */
#define SPI_IER_ENDRX (0x1u << 4) /**< \brief (SPI_IER) End of Receive Buffer Interrupt Enable */
#define SPI_IER_ENDTX (0x1u << 5) /**< \brief (SPI_IER) End of Transmit Buffer Interrupt Enable */
#define SPI_IER_RXBUFF (0x1u << 6) /**< \brief (SPI_IER) Receive Buffer Full Interrupt Enable */
#define SPI_IER_TXBUFE (0x1u << 7) /**< \brief (SPI_IER) Transmit Buffer Empty Interrupt Enable */
#define SPI_IER_NSSR (0x1u << 8) /**< \brief (SPI_IER) NSS Rising Interrupt Enable */
#define SPI_IER_TXEMPTY (0x1u << 9) /**< \brief (SPI_IER) Transmission Registers Empty Enable */
#define SPI_IER_UNDES (0x1u << 10) /**< \brief (SPI_IER) Underrun Error Interrupt Enable */
/* -------- SPI_IDR : (SPI Offset: 0x18) Interrupt Disable Register -------- */
#define SPI_IDR_RDRF (0x1u << 0) /**< \brief (SPI_IDR) Receive Data Register Full Interrupt Disable */
#define SPI_IDR_TDRE (0x1u << 1) /**< \brief (SPI_IDR) SPI Transmit Data Register Empty Interrupt Disable */
#define SPI_IDR_MODF (0x1u << 2) /**< \brief (SPI_IDR) Mode Fault Error Interrupt Disable */
#define SPI_IDR_OVRES (0x1u << 3) /**< \brief (SPI_IDR) Overrun Error Interrupt Disable */
#define SPI_IDR_ENDRX (0x1u << 4) /**< \brief (SPI_IDR) End of Receive Buffer Interrupt Disable */
#define SPI_IDR_ENDTX (0x1u << 5) /**< \brief (SPI_IDR) End of Transmit Buffer Interrupt Disable */
#define SPI_IDR_RXBUFF (0x1u << 6) /**< \brief (SPI_IDR) Receive Buffer Full Interrupt Disable */
#define SPI_IDR_TXBUFE (0x1u << 7) /**< \brief (SPI_IDR) Transmit Buffer Empty Interrupt Disable */
#define SPI_IDR_NSSR (0x1u << 8) /**< \brief (SPI_IDR) NSS Rising Interrupt Disable */
#define SPI_IDR_TXEMPTY (0x1u << 9) /**< \brief (SPI_IDR) Transmission Registers Empty Disable */
#define SPI_IDR_UNDES (0x1u << 10) /**< \brief (SPI_IDR) Underrun Error Interrupt Disable */
/* -------- SPI_IMR : (SPI Offset: 0x1C) Interrupt Mask Register -------- */
#define SPI_IMR_RDRF (0x1u << 0) /**< \brief (SPI_IMR) Receive Data Register Full Interrupt Mask */
#define SPI_IMR_TDRE (0x1u << 1) /**< \brief (SPI_IMR) SPI Transmit Data Register Empty Interrupt Mask */
#define SPI_IMR_MODF (0x1u << 2) /**< \brief (SPI_IMR) Mode Fault Error Interrupt Mask */
#define SPI_IMR_OVRES (0x1u << 3) /**< \brief (SPI_IMR) Overrun Error Interrupt Mask */
#define SPI_IMR_ENDRX (0x1u << 4) /**< \brief (SPI_IMR) End of Receive Buffer Interrupt Mask */
#define SPI_IMR_ENDTX (0x1u << 5) /**< \brief (SPI_IMR) End of Transmit Buffer Interrupt Mask */
#define SPI_IMR_RXBUFF (0x1u << 6) /**< \brief (SPI_IMR) Receive Buffer Full Interrupt Mask */
#define SPI_IMR_TXBUFE (0x1u << 7) /**< \brief (SPI_IMR) Transmit Buffer Empty Interrupt Mask */
#define SPI_IMR_NSSR (0x1u << 8) /**< \brief (SPI_IMR) NSS Rising Interrupt Mask */
#define SPI_IMR_TXEMPTY (0x1u << 9) /**< \brief (SPI_IMR) Transmission Registers Empty Mask */
#define SPI_IMR_UNDES (0x1u << 10) /**< \brief (SPI_IMR) Underrun Error Interrupt Mask */
/* -------- SPI_CSR[4] : (SPI Offset: 0x30) Chip Select Register -------- */
#define SPI_CSR_CPOL (0x1u << 0) /**< \brief (SPI_CSR[4]) Clock Polarity */
#define SPI_CSR_NCPHA (0x1u << 1) /**< \brief (SPI_CSR[4]) Clock Phase */
#define SPI_CSR_CSNAAT (0x1u << 2) /**< \brief (SPI_CSR[4]) Chip Select Not Active After Transfer (Ignored if CSAAT = 1) */
#define SPI_CSR_CSAAT (0x1u << 3) /**< \brief (SPI_CSR[4]) Chip Select Not Active After Transfer (Ignored if CSAAT = 1) */
#define SPI_CSR_BITS_Pos 4
#define SPI_CSR_BITS_Msk (0xfu << SPI_CSR_BITS_Pos) /**< \brief (SPI_CSR[4]) Bits Per Transfer */
#define   SPI_CSR_BITS_8_BIT (0x0u << 4) /**< \brief (SPI_CSR[4]) 8 bits for transfer */
#define   SPI_CSR_BITS_9_BIT (0x1u << 4) /**< \brief (SPI_CSR[4]) 9 bits for transfer */
#define   SPI_CSR_BITS_10_BIT (0x2u << 4) /**< \brief (SPI_CSR[4]) 10 bits for transfer */
#define   SPI_CSR_BITS_11_BIT (0x3u << 4) /**< \brief (SPI_CSR[4]) 11 bits for transfer */
#define   SPI_CSR_BITS_12_BIT (0x4u << 4) /**< \brief (SPI_CSR[4]) 12 bits for transfer */
#define   SPI_CSR_BITS_13_BIT (0x5u << 4) /**< \brief (SPI_CSR[4]) 13 bits for transfer */
#define   SPI_CSR_BITS_14_BIT (0x6u << 4) /**< \brief (SPI_CSR[4]) 14 bits for transfer */
#define   SPI_CSR_BITS_15_BIT (0x7u << 4) /**< \brief (SPI_CSR[4]) 15 bits for transfer */
#define   SPI_CSR_BITS_16_BIT (0x8u << 4) /**< \brief (SPI_CSR[4]) 16 bits for transfer */
#define SPI_CSR_SCBR_Pos 8
#define SPI_CSR_SCBR_Msk (0xffu << SPI_CSR_SCBR_Pos) /**< \brief (SPI_CSR[4]) Serial Clock Baud Rate */
#define SPI_CSR_SCBR(value) ((SPI_CSR_SCBR_Msk & ((value) << SPI_CSR_SCBR_Pos)))
#define SPI_CSR_DLYBS_Pos 16
#define SPI_CSR_DLYBS_Msk (0xffu << SPI_CSR_DLYBS_Pos) /**< \brief (SPI_CSR[4]) Delay Before SPCK */
#define SPI_CSR_DLYBS(value) ((SPI_CSR_DLYBS_Msk & ((value) << SPI_CSR_DLYBS_Pos)))
#define SPI_CSR_DLYBCT_Pos 24
#define SPI_CSR_DLYBCT_Msk (0xffu << SPI_CSR_DLYBCT_Pos) /**< \brief (SPI_CSR[4]) Delay Between Consecutive Transfers */
#define SPI_CSR_DLYBCT(value) ((SPI_CSR_DLYBCT_Msk & ((value) << SPI_CSR_DLYBCT_Pos)))
/* -------- SPI_WPMR : (SPI Offset: 0xE4) Write Protection Control Register -------- */
#define SPI_WPMR_SPIWPEN (0x1u << 0) /**< \brief (SPI_WPMR) SPI Write Protection Enable */
#define SPI_WPMR_SPIWPKEY_Pos 8
#define SPI_WPMR_SPIWPKEY_Msk (0xffffffu << SPI_WPMR_SPIWPKEY_Pos) /**< \brief (SPI_WPMR) SPI Write Protection Key Password */
#define SPI_WPMR_SPIWPKEY(value) ((SPI_WPMR_SPIWPKEY_Msk & ((value) << SPI_WPMR_SPIWPKEY_Pos)))
/* -------- SPI_WPSR : (SPI Offset: 0xE8) Write Protection Status Register -------- */
#define SPI_WPSR_SPIWPVS_Pos 0
#define SPI_WPSR_SPIWPVS_Msk (0x7u << SPI_WPSR_SPIWPVS_Pos) /**< \brief (SPI_WPSR) SPI Write Protection Violation Status */
#define SPI_WPSR_SPIWPVSRC_Pos 8
#define SPI_WPSR_SPIWPVSRC_Msk (0xffu << SPI_WPSR_SPIWPVSRC_Pos) /**< \brief (SPI_WPSR) SPI Write Protection Violation Source */
/* -------- SPI_RPR : (SPI Offset: 0x100) Receive Pointer Register -------- */
#define SPI_RPR_RXPTR_Pos 0
#define SPI_RPR_RXPTR_Msk (0xffffffffu << SPI_RPR_RXPTR_Pos) /**< \brief (SPI_RPR) Receive Pointer Register */
#define SPI_RPR_RXPTR(value) ((SPI_RPR_RXPTR_Msk & ((value) << SPI_RPR_RXPTR_Pos)))
/* -------- SPI_RCR : (SPI Offset: 0x104) Receive Counter Register -------- */
#define SPI_RCR_RXCTR_Pos 0
#define SPI_RCR_RXCTR_Msk (0xffffu << SPI_RCR_RXCTR_Pos) /**< \brief (SPI_RCR) Receive Counter Register */
#define SPI_RCR_RXCTR(value) ((SPI_RCR_RXCTR_Msk & ((value) << SPI_RCR_RXCTR_Pos)))
/* -------- SPI_TPR : (SPI Offset: 0x108) Transmit Pointer Register -------- */
#define SPI_TPR_TXPTR_Pos 0
#define SPI_TPR_TXPTR_Msk (0xffffffffu << SPI_TPR_TXPTR_Pos) /**< \brief (SPI_TPR) Transmit Counter Register */
#define SPI_TPR_TXPTR(value) ((SPI_TPR_TXPTR_Msk & ((value) << SPI_TPR_TXPTR_Pos)))
/* -------- SPI_TCR : (SPI Offset: 0x10C) Transmit Counter Register -------- */
#define SPI_TCR_TXCTR_Pos 0
#define SPI_TCR_TXCTR_Msk (0xffffu << SPI_TCR_TXCTR_Pos) /**< \brief (SPI_TCR) Transmit Counter Register */
#define SPI_TCR_TXCTR(value) ((SPI_TCR_TXCTR_Msk & ((value) << SPI_TCR_TXCTR_Pos)))
/* -------- SPI_RNPR : (SPI Offset: 0x110) Receive Next Pointer Register -------- */
#define SPI_RNPR_RXNPTR_Pos 0
#define SPI_RNPR_RXNPTR_Msk (0xffffffffu << SPI_RNPR_RXNPTR_Pos) /**< \brief (SPI_RNPR) Receive Next Pointer */
#define SPI_RNPR_RXNPTR(value) ((SPI_RNPR_RXNPTR_Msk & ((value) << SPI_RNPR_RXNPTR_Pos)))
/* -------- SPI_RNCR : (SPI Offset: 0x114) Receive Next Counter Register -------- */
#define SPI_RNCR_RXNCTR_Pos 0
#define SPI_RNCR_RXNCTR_Msk (0xffffu << SPI_RNCR_RXNCTR_Pos) /**< \brief (SPI_RNCR) Receive Next Counter */
#define SPI_RNCR_RXNCTR(value) ((SPI_RNCR_RXNCTR_Msk & ((value) << SPI_RNCR_RXNCTR_Pos)))
/* -------- SPI_TNPR : (SPI Offset: 0x118) Transmit Next Pointer Register -------- */
#define SPI_TNPR_TXNPTR_Pos 0
#define SPI_TNPR_TXNPTR_Msk (0xffffffffu << SPI_TNPR_TXNPTR_Pos) /**< \brief (SPI_TNPR) Transmit Next Pointer */
#define SPI_TNPR_TXNPTR(value) ((SPI_TNPR_TXNPTR_Msk & ((value) << SPI_TNPR_TXNPTR_Pos)))
/* -------- SPI_TNCR : (SPI Offset: 0x11C) Transmit Next Counter Register -------- */
#define SPI_TNCR_TXNCTR_Pos 0
#define SPI_TNCR_TXNCTR_Msk (0xffffu << SPI_TNCR_TXNCTR_Pos) /**< \brief (SPI_TNCR) Transmit Counter Next */
#define SPI_TNCR_TXNCTR(value) ((SPI_TNCR_TXNCTR_Msk & ((value) << SPI_TNCR_TXNCTR_Pos)))
/* -------- SPI_PTCR : (SPI Offset: 0x120) Transfer Control Register -------- */
#define SPI_PTCR_RXTEN (0x1u << 0) /**< \brief (SPI_PTCR) Receiver Transfer Enable */
#define SPI_PTCR_RXTDIS (0x1u << 1) /**< \brief (SPI_PTCR) Receiver Transfer Disable */
#define SPI_PTCR_TXTEN (0x1u << 8) /**< \brief (SPI_PTCR) Transmitter Transfer Enable */
#define SPI_PTCR_TXTDIS (0x1u << 9) /**< \brief (SPI_PTCR) Transmitter Transfer Disable */
/* -------- SPI_PTSR : (SPI Offset: 0x124) Transfer Status Register -------- */
#define SPI_PTSR_RXTEN (0x1u << 0) /**< \brief (SPI_PTSR) Receiver Transfer Enable */
#define SPI_PTSR_TXTEN (0x1u << 8) /**< \brief (SPI_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Synchronous Serial Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_SSC Synchronous Serial Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Ssc hardware registers */
typedef struct {
  WoReg SSC_CR;        /**< \brief (Ssc Offset: 0x0) Control Register */
  RwReg SSC_CMR;       /**< \brief (Ssc Offset: 0x4) Clock Mode Register */
  RoReg Reserved1[2];
  RwReg SSC_RCMR;      /**< \brief (Ssc Offset: 0x10) Receive Clock Mode Register */
  RwReg SSC_RFMR;      /**< \brief (Ssc Offset: 0x14) Receive Frame Mode Register */
  RwReg SSC_TCMR;      /**< \brief (Ssc Offset: 0x18) Transmit Clock Mode Register */
  RwReg SSC_TFMR;      /**< \brief (Ssc Offset: 0x1C) Transmit Frame Mode Register */
  RoReg SSC_RHR;       /**< \brief (Ssc Offset: 0x20) Receive Holding Register */
  WoReg SSC_THR;       /**< \brief (Ssc Offset: 0x24) Transmit Holding Register */
  RoReg Reserved2[2];
  RoReg SSC_RSHR;      /**< \brief (Ssc Offset: 0x30) Receive Sync. Holding Register */
  RwReg SSC_TSHR;      /**< \brief (Ssc Offset: 0x34) Transmit Sync. Holding Register */
  RwReg SSC_RC0R;      /**< \brief (Ssc Offset: 0x38) Receive Compare 0 Register */
  RwReg SSC_RC1R;      /**< \brief (Ssc Offset: 0x3C) Receive Compare 1 Register */
  RoReg SSC_SR;        /**< \brief (Ssc Offset: 0x40) Status Register */
  WoReg SSC_IER;       /**< \brief (Ssc Offset: 0x44) Interrupt Enable Register */
  WoReg SSC_IDR;       /**< \brief (Ssc Offset: 0x48) Interrupt Disable Register */
  RoReg SSC_IMR;       /**< \brief (Ssc Offset: 0x4C) Interrupt Mask Register */
  RoReg Reserved3[37];
  RwReg SSC_WPMR;      /**< \brief (Ssc Offset: 0xE4) Write Protect Mode Register */
  RoReg SSC_WPSR;      /**< \brief (Ssc Offset: 0xE8) Write Protect Status Register */
  RoReg Reserved4[5];
  RwReg SSC_RPR;       /**< \brief (Ssc Offset: 0x100) Receive Pointer Register */
  RwReg SSC_RCR;       /**< \brief (Ssc Offset: 0x104) Receive Counter Register */
  RwReg SSC_TPR;       /**< \brief (Ssc Offset: 0x108) Transmit Pointer Register */
  RwReg SSC_TCR;       /**< \brief (Ssc Offset: 0x10C) Transmit Counter Register */
  RwReg SSC_RNPR;      /**< \brief (Ssc Offset: 0x110) Receive Next Pointer Register */
  RwReg SSC_RNCR;      /**< \brief (Ssc Offset: 0x114) Receive Next Counter Register */
  RwReg SSC_TNPR;      /**< \brief (Ssc Offset: 0x118) Transmit Next Pointer Register */
  RwReg SSC_TNCR;      /**< \brief (Ssc Offset: 0x11C) Transmit Next Counter Register */
  WoReg SSC_PTCR;      /**< \brief (Ssc Offset: 0x120) Transfer Control Register */
  RoReg SSC_PTSR;      /**< \brief (Ssc Offset: 0x124) Transfer Status Register */
} Ssc;
#endif /* __ASSEMBLY__ */
/* -------- SSC_CR : (SSC Offset: 0x0) Control Register -------- */
#define SSC_CR_RXEN (0x1u << 0) /**< \brief (SSC_CR) Receive Enable */
#define SSC_CR_RXDIS (0x1u << 1) /**< \brief (SSC_CR) Receive Disable */
#define SSC_CR_TXEN (0x1u << 8) /**< \brief (SSC_CR) Transmit Enable */
#define SSC_CR_TXDIS (0x1u << 9) /**< \brief (SSC_CR) Transmit Disable */
#define SSC_CR_SWRST (0x1u << 15) /**< \brief (SSC_CR) Software Reset */
/* -------- SSC_CMR : (SSC Offset: 0x4) Clock Mode Register -------- */
#define SSC_CMR_DIV_Pos 0
#define SSC_CMR_DIV_Msk (0xfffu << SSC_CMR_DIV_Pos) /**< \brief (SSC_CMR) Clock Divider */
#define SSC_CMR_DIV(value) ((SSC_CMR_DIV_Msk & ((value) << SSC_CMR_DIV_Pos)))
/* -------- SSC_RCMR : (SSC Offset: 0x10) Receive Clock Mode Register -------- */
#define SSC_RCMR_CKS_Pos 0
#define SSC_RCMR_CKS_Msk (0x3u << SSC_RCMR_CKS_Pos) /**< \brief (SSC_RCMR) Receive Clock Selection */
#define   SSC_RCMR_CKS_MCK (0x0u << 0) /**< \brief (SSC_RCMR) Divided Clock */
#define   SSC_RCMR_CKS_TK (0x1u << 0) /**< \brief (SSC_RCMR) TK Clock signal */
#define   SSC_RCMR_CKS_RK (0x2u << 0) /**< \brief (SSC_RCMR) RK pin */
#define SSC_RCMR_CKO_Pos 2
#define SSC_RCMR_CKO_Msk (0x7u << SSC_RCMR_CKO_Pos) /**< \brief (SSC_RCMR) Receive Clock Output Mode Selection */
#define   SSC_RCMR_CKO_NONE (0x0u << 2) /**< \brief (SSC_RCMR) None */
#define   SSC_RCMR_CKO_CONTINUOUS (0x1u << 2) /**< \brief (SSC_RCMR) Continuous Receive Clock */
#define   SSC_RCMR_CKO_TRANSFER (0x2u << 2) /**< \brief (SSC_RCMR) Receive Clock only during data transfers */
#define SSC_RCMR_CKI (0x1u << 5) /**< \brief (SSC_RCMR) Receive Clock Inversion */
#define SSC_RCMR_CKG_Pos 6
#define SSC_RCMR_CKG_Msk (0x3u << SSC_RCMR_CKG_Pos) /**< \brief (SSC_RCMR) Receive Clock Gating Selection */
#define   SSC_RCMR_CKG_NONE (0x0u << 6) /**< \brief (SSC_RCMR) None */
#define   SSC_RCMR_CKG_CONTINUOUS (0x1u << 6) /**< \brief (SSC_RCMR) Continuous Receive Clock */
#define   SSC_RCMR_CKG_TRANSFER (0x2u << 6) /**< \brief (SSC_RCMR) Receive Clock only during data transfers */
#define SSC_RCMR_START_Pos 8
#define SSC_RCMR_START_Msk (0xfu << SSC_RCMR_START_Pos) /**< \brief (SSC_RCMR) Receive Start Selection */
#define   SSC_RCMR_START_CONTINUOUS (0x0u << 8) /**< \brief (SSC_RCMR) Continuous, as soon as the receiver is enabled, and immediately after the end of transfer of the previous data. */
#define   SSC_RCMR_START_TRANSMIT (0x1u << 8) /**< \brief (SSC_RCMR) Transmit start */
#define   SSC_RCMR_START_RF_LOW (0x2u << 8) /**< \brief (SSC_RCMR) Detection of a low level on RF signal */
#define   SSC_RCMR_START_RF_HIGH (0x3u << 8) /**< \brief (SSC_RCMR) Detection of a high level on RF signal */
#define   SSC_RCMR_START_RF_FALLING (0x4u << 8) /**< \brief (SSC_RCMR) Detection of a falling edge on RF signal */
#define   SSC_RCMR_START_RF_RISING (0x5u << 8) /**< \brief (SSC_RCMR) Detection of a rising edge on RF signal */
#define   SSC_RCMR_START_RF_LEVEL (0x6u << 8) /**< \brief (SSC_RCMR) Detection of any level change on RF signal */
#define   SSC_RCMR_START_RF_EDGE (0x7u << 8) /**< \brief (SSC_RCMR) Detection of any edge on RF signal */
#define   SSC_RCMR_START_CMP_0 (0x8u << 8) /**< \brief (SSC_RCMR) Compare 0 */
#define SSC_RCMR_STOP (0x1u << 12) /**< \brief (SSC_RCMR) Receive Stop Selection */
#define SSC_RCMR_STTDLY_Pos 16
#define SSC_RCMR_STTDLY_Msk (0xffu << SSC_RCMR_STTDLY_Pos) /**< \brief (SSC_RCMR) Receive Start Delay */
#define SSC_RCMR_STTDLY(value) ((SSC_RCMR_STTDLY_Msk & ((value) << SSC_RCMR_STTDLY_Pos)))
#define SSC_RCMR_PERIOD_Pos 24
#define SSC_RCMR_PERIOD_Msk (0xffu << SSC_RCMR_PERIOD_Pos) /**< \brief (SSC_RCMR) Receive Period Divider Selection */
#define SSC_RCMR_PERIOD(value) ((SSC_RCMR_PERIOD_Msk & ((value) << SSC_RCMR_PERIOD_Pos)))
/* -------- SSC_RFMR : (SSC Offset: 0x14) Receive Frame Mode Register -------- */
#define SSC_RFMR_DATLEN_Pos 0
#define SSC_RFMR_DATLEN_Msk (0x1fu << SSC_RFMR_DATLEN_Pos) /**< \brief (SSC_RFMR) Data Length */
#define SSC_RFMR_DATLEN(value) ((SSC_RFMR_DATLEN_Msk & ((value) << SSC_RFMR_DATLEN_Pos)))
#define SSC_RFMR_LOOP (0x1u << 5) /**< \brief (SSC_RFMR) Loop Mode */
#define SSC_RFMR_MSBF (0x1u << 7) /**< \brief (SSC_RFMR) Most Significant Bit First */
#define SSC_RFMR_DATNB_Pos 8
#define SSC_RFMR_DATNB_Msk (0xfu << SSC_RFMR_DATNB_Pos) /**< \brief (SSC_RFMR) Data Number per Frame */
#define SSC_RFMR_DATNB(value) ((SSC_RFMR_DATNB_Msk & ((value) << SSC_RFMR_DATNB_Pos)))
#define SSC_RFMR_FSLEN_Pos 16
#define SSC_RFMR_FSLEN_Msk (0xfu << SSC_RFMR_FSLEN_Pos) /**< \brief (SSC_RFMR) Receive Frame Sync Length */
#define SSC_RFMR_FSLEN(value) ((SSC_RFMR_FSLEN_Msk & ((value) << SSC_RFMR_FSLEN_Pos)))
#define SSC_RFMR_FSOS_Pos 20
#define SSC_RFMR_FSOS_Msk (0x7u << SSC_RFMR_FSOS_Pos) /**< \brief (SSC_RFMR) Receive Frame Sync Output Selection */
#define   SSC_RFMR_FSOS_NONE (0x0u << 20) /**< \brief (SSC_RFMR) None */
#define   SSC_RFMR_FSOS_NEGATIVE (0x1u << 20) /**< \brief (SSC_RFMR) Negative Pulse */
#define   SSC_RFMR_FSOS_POSITIVE (0x2u << 20) /**< \brief (SSC_RFMR) Positive Pulse */
#define   SSC_RFMR_FSOS_LOW (0x3u << 20) /**< \brief (SSC_RFMR) Driven Low during data transfer */
#define   SSC_RFMR_FSOS_HIGH (0x4u << 20) /**< \brief (SSC_RFMR) Driven High during data transfer */
#define   SSC_RFMR_FSOS_TOGGLING (0x5u << 20) /**< \brief (SSC_RFMR) Toggling at each start of data transfer */
#define SSC_RFMR_FSEDGE (0x1u << 24) /**< \brief (SSC_RFMR) Frame Sync Edge Detection */
#define   SSC_RFMR_FSEDGE_POSITIVE (0x0u << 24) /**< \brief (SSC_RFMR) Positive Edge Detection */
#define   SSC_RFMR_FSEDGE_NEGATIVE (0x1u << 24) /**< \brief (SSC_RFMR) Negative Edge Detection */
#define SSC_RFMR_FSLEN_EXT_Pos 28
#define SSC_RFMR_FSLEN_EXT_Msk (0xfu << SSC_RFMR_FSLEN_EXT_Pos) /**< \brief (SSC_RFMR) FSLEN Field Extension */
#define SSC_RFMR_FSLEN_EXT(value) ((SSC_RFMR_FSLEN_EXT_Msk & ((value) << SSC_RFMR_FSLEN_EXT_Pos)))
/* -------- SSC_TCMR : (SSC Offset: 0x18) Transmit Clock Mode Register -------- */
#define SSC_TCMR_CKS_Pos 0
#define SSC_TCMR_CKS_Msk (0x3u << SSC_TCMR_CKS_Pos) /**< \brief (SSC_TCMR) Transmit Clock Selection */
#define   SSC_TCMR_CKS_MCK (0x0u << 0) /**< \brief (SSC_TCMR) Divided Clock */
#define   SSC_TCMR_CKS_TK (0x1u << 0) /**< \brief (SSC_TCMR) TK Clock signal */
#define   SSC_TCMR_CKS_RK (0x2u << 0) /**< \brief (SSC_TCMR) RK pin */
#define SSC_TCMR_CKO_Pos 2
#define SSC_TCMR_CKO_Msk (0x7u << SSC_TCMR_CKO_Pos) /**< \brief (SSC_TCMR) Transmit Clock Output Mode Selection */
#define   SSC_TCMR_CKO_NONE (0x0u << 2) /**< \brief (SSC_TCMR) None */
#define   SSC_TCMR_CKO_CONTINUOUS (0x1u << 2) /**< \brief (SSC_TCMR) Continuous Receive Clock */
#define   SSC_TCMR_CKO_TRANSFER (0x2u << 2) /**< \brief (SSC_TCMR) Transmit Clock only during data transfers */
#define SSC_TCMR_CKI (0x1u << 5) /**< \brief (SSC_TCMR) Transmit Clock Inversion */
#define SSC_TCMR_CKG_Pos 6
#define SSC_TCMR_CKG_Msk (0x3u << SSC_TCMR_CKG_Pos) /**< \brief (SSC_TCMR) Transmit Clock Gating Selection */
#define   SSC_TCMR_CKG_NONE (0x0u << 6) /**< \brief (SSC_TCMR) None */
#define   SSC_TCMR_CKG_CONTINUOUS (0x1u << 6) /**< \brief (SSC_TCMR) Transmit Clock enabled only if TF Low */
#define   SSC_TCMR_CKG_TRANSFER (0x2u << 6) /**< \brief (SSC_TCMR) Transmit Clock enabled only if TF High */
#define SSC_TCMR_START_Pos 8
#define SSC_TCMR_START_Msk (0xfu << SSC_TCMR_START_Pos) /**< \brief (SSC_TCMR) Transmit Start Selection */
#define   SSC_TCMR_START_CONTINUOUS (0x0u << 8) /**< \brief (SSC_TCMR) Continuous, as soon as a word is written in the SSC_THR Register (if Transmit is enabled), and immediately after the end of transfer of the previous data. */
#define   SSC_TCMR_START_RECEIVE (0x1u << 8) /**< \brief (SSC_TCMR) Receive start */
#define   SSC_TCMR_START_RF_LOW (0x2u << 8) /**< \brief (SSC_TCMR) Detection of a low level on TF signal */
#define   SSC_TCMR_START_RF_HIGH (0x3u << 8) /**< \brief (SSC_TCMR) Detection of a high level on TF signal */
#define   SSC_TCMR_START_RF_FALLING (0x4u << 8) /**< \brief (SSC_TCMR) Detection of a falling edge on TF signal */
#define   SSC_TCMR_START_RF_RISING (0x5u << 8) /**< \brief (SSC_TCMR) Detection of a rising edge on TF signal */
#define   SSC_TCMR_START_RF_LEVEL (0x6u << 8) /**< \brief (SSC_TCMR) Detection of any level change on TF signal */
#define   SSC_TCMR_START_RF_EDGE (0x7u << 8) /**< \brief (SSC_TCMR) Detection of any edge on TF signal */
#define   SSC_TCMR_START_CMP_0 (0x8u << 8) /**< \brief (SSC_TCMR) Compare 0 */
#define SSC_TCMR_STTDLY_Pos 16
#define SSC_TCMR_STTDLY_Msk (0xffu << SSC_TCMR_STTDLY_Pos) /**< \brief (SSC_TCMR) Transmit Start Delay */
#define SSC_TCMR_STTDLY(value) ((SSC_TCMR_STTDLY_Msk & ((value) << SSC_TCMR_STTDLY_Pos)))
#define SSC_TCMR_PERIOD_Pos 24
#define SSC_TCMR_PERIOD_Msk (0xffu << SSC_TCMR_PERIOD_Pos) /**< \brief (SSC_TCMR) Transmit Period Divider Selection */
#define SSC_TCMR_PERIOD(value) ((SSC_TCMR_PERIOD_Msk & ((value) << SSC_TCMR_PERIOD_Pos)))
/* -------- SSC_TFMR : (SSC Offset: 0x1C) Transmit Frame Mode Register -------- */
#define SSC_TFMR_DATLEN_Pos 0
#define SSC_TFMR_DATLEN_Msk (0x1fu << SSC_TFMR_DATLEN_Pos) /**< \brief (SSC_TFMR) Data Length */
#define SSC_TFMR_DATLEN(value) ((SSC_TFMR_DATLEN_Msk & ((value) << SSC_TFMR_DATLEN_Pos)))
#define SSC_TFMR_DATDEF (0x1u << 5) /**< \brief (SSC_TFMR) Data Default Value */
#define SSC_TFMR_MSBF (0x1u << 7) /**< \brief (SSC_TFMR) Most Significant Bit First */
#define SSC_TFMR_DATNB_Pos 8
#define SSC_TFMR_DATNB_Msk (0xfu << SSC_TFMR_DATNB_Pos) /**< \brief (SSC_TFMR) Data Number per frame */
#define SSC_TFMR_DATNB(value) ((SSC_TFMR_DATNB_Msk & ((value) << SSC_TFMR_DATNB_Pos)))
#define SSC_TFMR_FSLEN_Pos 16
#define SSC_TFMR_FSLEN_Msk (0xfu << SSC_TFMR_FSLEN_Pos) /**< \brief (SSC_TFMR) Transmit Frame Sync Length */
#define SSC_TFMR_FSLEN(value) ((SSC_TFMR_FSLEN_Msk & ((value) << SSC_TFMR_FSLEN_Pos)))
#define SSC_TFMR_FSOS_Pos 20
#define SSC_TFMR_FSOS_Msk (0x7u << SSC_TFMR_FSOS_Pos) /**< \brief (SSC_TFMR) Transmit Frame Sync Output Selection */
#define   SSC_TFMR_FSOS_NONE (0x0u << 20) /**< \brief (SSC_TFMR) None */
#define   SSC_TFMR_FSOS_NEGATIVE (0x1u << 20) /**< \brief (SSC_TFMR) Negative Pulse */
#define   SSC_TFMR_FSOS_POSITIVE (0x2u << 20) /**< \brief (SSC_TFMR) Positive Pulse */
#define   SSC_TFMR_FSOS_LOW (0x3u << 20) /**< \brief (SSC_TFMR) Driven Low during data transfer */
#define   SSC_TFMR_FSOS_HIGH (0x4u << 20) /**< \brief (SSC_TFMR) Driven High during data transfer */
#define   SSC_TFMR_FSOS_TOGGLING (0x5u << 20) /**< \brief (SSC_TFMR) Toggling at each start of data transfer */
#define SSC_TFMR_FSDEN (0x1u << 23) /**< \brief (SSC_TFMR) Frame Sync Data Enable */
#define SSC_TFMR_FSEDGE (0x1u << 24) /**< \brief (SSC_TFMR) Frame Sync Edge Detection */
#define   SSC_TFMR_FSEDGE_POSITIVE (0x0u << 24) /**< \brief (SSC_TFMR) Positive Edge Detection */
#define   SSC_TFMR_FSEDGE_NEGATIVE (0x1u << 24) /**< \brief (SSC_TFMR) Negative Edge Detection */
#define SSC_TFMR_FSLEN_EXT_Pos 28
#define SSC_TFMR_FSLEN_EXT_Msk (0xfu << SSC_TFMR_FSLEN_EXT_Pos) /**< \brief (SSC_TFMR) FSLEN Field Extension */
#define SSC_TFMR_FSLEN_EXT(value) ((SSC_TFMR_FSLEN_EXT_Msk & ((value) << SSC_TFMR_FSLEN_EXT_Pos)))
/* -------- SSC_RHR : (SSC Offset: 0x20) Receive Holding Register -------- */
#define SSC_RHR_RDAT_Pos 0
#define SSC_RHR_RDAT_Msk (0xffffffffu << SSC_RHR_RDAT_Pos) /**< \brief (SSC_RHR) Receive Data */
/* -------- SSC_THR : (SSC Offset: 0x24) Transmit Holding Register -------- */
#define SSC_THR_TDAT_Pos 0
#define SSC_THR_TDAT_Msk (0xffffffffu << SSC_THR_TDAT_Pos) /**< \brief (SSC_THR) Transmit Data */
#define SSC_THR_TDAT(value) ((SSC_THR_TDAT_Msk & ((value) << SSC_THR_TDAT_Pos)))
/* -------- SSC_RSHR : (SSC Offset: 0x30) Receive Sync. Holding Register -------- */
#define SSC_RSHR_RSDAT_Pos 0
#define SSC_RSHR_RSDAT_Msk (0xffffu << SSC_RSHR_RSDAT_Pos) /**< \brief (SSC_RSHR) Receive Synchronization Data */
/* -------- SSC_TSHR : (SSC Offset: 0x34) Transmit Sync. Holding Register -------- */
#define SSC_TSHR_TSDAT_Pos 0
#define SSC_TSHR_TSDAT_Msk (0xffffu << SSC_TSHR_TSDAT_Pos) /**< \brief (SSC_TSHR) Transmit Synchronization Data */
#define SSC_TSHR_TSDAT(value) ((SSC_TSHR_TSDAT_Msk & ((value) << SSC_TSHR_TSDAT_Pos)))
/* -------- SSC_RC0R : (SSC Offset: 0x38) Receive Compare 0 Register -------- */
#define SSC_RC0R_CP0_Pos 0
#define SSC_RC0R_CP0_Msk (0xffffu << SSC_RC0R_CP0_Pos) /**< \brief (SSC_RC0R) Receive Compare Data 0 */
#define SSC_RC0R_CP0(value) ((SSC_RC0R_CP0_Msk & ((value) << SSC_RC0R_CP0_Pos)))
/* -------- SSC_RC1R : (SSC Offset: 0x3C) Receive Compare 1 Register -------- */
#define SSC_RC1R_CP1_Pos 0
#define SSC_RC1R_CP1_Msk (0xffffu << SSC_RC1R_CP1_Pos) /**< \brief (SSC_RC1R) Receive Compare Data 1 */
#define SSC_RC1R_CP1(value) ((SSC_RC1R_CP1_Msk & ((value) << SSC_RC1R_CP1_Pos)))
/* -------- SSC_SR : (SSC Offset: 0x40) Status Register -------- */
#define SSC_SR_TXRDY (0x1u << 0) /**< \brief (SSC_SR) Transmit Ready */
#define SSC_SR_TXEMPTY (0x1u << 1) /**< \brief (SSC_SR) Transmit Empty */
#define SSC_SR_ENDTX (0x1u << 2) /**< \brief (SSC_SR) End of Transmission */
#define SSC_SR_TXBUFE (0x1u << 3) /**< \brief (SSC_SR) Transmit Buffer Empty */
#define SSC_SR_RXRDY (0x1u << 4) /**< \brief (SSC_SR) Receive Ready */
#define SSC_SR_OVRUN (0x1u << 5) /**< \brief (SSC_SR) Receive Overrun */
#define SSC_SR_ENDRX (0x1u << 6) /**< \brief (SSC_SR) End of Reception */
#define SSC_SR_RXBUFF (0x1u << 7) /**< \brief (SSC_SR) Receive Buffer Full */
#define SSC_SR_CP0 (0x1u << 8) /**< \brief (SSC_SR) Compare 0 */
#define SSC_SR_CP1 (0x1u << 9) /**< \brief (SSC_SR) Compare 1 */
#define SSC_SR_TXSYN (0x1u << 10) /**< \brief (SSC_SR) Transmit Sync */
#define SSC_SR_RXSYN (0x1u << 11) /**< \brief (SSC_SR) Receive Sync */
#define SSC_SR_TXEN (0x1u << 16) /**< \brief (SSC_SR) Transmit Enable */
#define SSC_SR_RXEN (0x1u << 17) /**< \brief (SSC_SR) Receive Enable */
/* -------- SSC_IER : (SSC Offset: 0x44) Interrupt Enable Register -------- */
#define SSC_IER_TXRDY (0x1u << 0) /**< \brief (SSC_IER) Transmit Ready Interrupt Enable */
#define SSC_IER_TXEMPTY (0x1u << 1) /**< \brief (SSC_IER) Transmit Empty Interrupt Enable */
#define SSC_IER_ENDTX (0x1u << 2) /**< \brief (SSC_IER) End of Transmission Interrupt Enable */
#define SSC_IER_TXBUFE (0x1u << 3) /**< \brief (SSC_IER) Transmit Buffer Empty Interrupt Enable */
#define SSC_IER_RXRDY (0x1u << 4) /**< \brief (SSC_IER) Receive Ready Interrupt Enable */
#define SSC_IER_OVRUN (0x1u << 5) /**< \brief (SSC_IER) Receive Overrun Interrupt Enable */
#define SSC_IER_ENDRX (0x1u << 6) /**< \brief (SSC_IER) End of Reception Interrupt Enable */
#define SSC_IER_RXBUFF (0x1u << 7) /**< \brief (SSC_IER) Receive Buffer Full Interrupt Enable */
#define SSC_IER_CP0 (0x1u << 8) /**< \brief (SSC_IER) Compare 0 Interrupt Enable */
#define SSC_IER_CP1 (0x1u << 9) /**< \brief (SSC_IER) Compare 1 Interrupt Enable */
#define SSC_IER_TXSYN (0x1u << 10) /**< \brief (SSC_IER) Tx Sync Interrupt Enable */
#define SSC_IER_RXSYN (0x1u << 11) /**< \brief (SSC_IER) Rx Sync Interrupt Enable */
/* -------- SSC_IDR : (SSC Offset: 0x48) Interrupt Disable Register -------- */
#define SSC_IDR_TXRDY (0x1u << 0) /**< \brief (SSC_IDR) Transmit Ready Interrupt Disable */
#define SSC_IDR_TXEMPTY (0x1u << 1) /**< \brief (SSC_IDR) Transmit Empty Interrupt Disable */
#define SSC_IDR_ENDTX (0x1u << 2) /**< \brief (SSC_IDR) End of Transmission Interrupt Disable */
#define SSC_IDR_TXBUFE (0x1u << 3) /**< \brief (SSC_IDR) Transmit Buffer Empty Interrupt Disable */
#define SSC_IDR_RXRDY (0x1u << 4) /**< \brief (SSC_IDR) Receive Ready Interrupt Disable */
#define SSC_IDR_OVRUN (0x1u << 5) /**< \brief (SSC_IDR) Receive Overrun Interrupt Disable */
#define SSC_IDR_ENDRX (0x1u << 6) /**< \brief (SSC_IDR) End of Reception Interrupt Disable */
#define SSC_IDR_RXBUFF (0x1u << 7) /**< \brief (SSC_IDR) Receive Buffer Full Interrupt Disable */
#define SSC_IDR_CP0 (0x1u << 8) /**< \brief (SSC_IDR) Compare 0 Interrupt Disable */
#define SSC_IDR_CP1 (0x1u << 9) /**< \brief (SSC_IDR) Compare 1 Interrupt Disable */
#define SSC_IDR_TXSYN (0x1u << 10) /**< \brief (SSC_IDR) Tx Sync Interrupt Enable */
#define SSC_IDR_RXSYN (0x1u << 11) /**< \brief (SSC_IDR) Rx Sync Interrupt Enable */
/* -------- SSC_IMR : (SSC Offset: 0x4C) Interrupt Mask Register -------- */
#define SSC_IMR_TXRDY (0x1u << 0) /**< \brief (SSC_IMR) Transmit Ready Interrupt Mask */
#define SSC_IMR_TXEMPTY (0x1u << 1) /**< \brief (SSC_IMR) Transmit Empty Interrupt Mask */
#define SSC_IMR_ENDTX (0x1u << 2) /**< \brief (SSC_IMR) End of Transmission Interrupt Mask */
#define SSC_IMR_TXBUFE (0x1u << 3) /**< \brief (SSC_IMR) Transmit Buffer Empty Interrupt Mask */
#define SSC_IMR_RXRDY (0x1u << 4) /**< \brief (SSC_IMR) Receive Ready Interrupt Mask */
#define SSC_IMR_OVRUN (0x1u << 5) /**< \brief (SSC_IMR) Receive Overrun Interrupt Mask */
#define SSC_IMR_ENDRX (0x1u << 6) /**< \brief (SSC_IMR) End of Reception Interrupt Mask */
#define SSC_IMR_RXBUFF (0x1u << 7) /**< \brief (SSC_IMR) Receive Buffer Full Interrupt Mask */
#define SSC_IMR_CP0 (0x1u << 8) /**< \brief (SSC_IMR) Compare 0 Interrupt Mask */
#define SSC_IMR_CP1 (0x1u << 9) /**< \brief (SSC_IMR) Compare 1 Interrupt Mask */
#define SSC_IMR_TXSYN (0x1u << 10) /**< \brief (SSC_IMR) Tx Sync Interrupt Mask */
#define SSC_IMR_RXSYN (0x1u << 11) /**< \brief (SSC_IMR) Rx Sync Interrupt Mask */
/* -------- SSC_WPMR : (SSC Offset: 0xE4) Write Protect Mode Register -------- */
#define SSC_WPMR_WPEN (0x1u << 0) /**< \brief (SSC_WPMR) Write Protect Enable */
#define SSC_WPMR_WPKEY_Pos 8
#define SSC_WPMR_WPKEY_Msk (0xffffffu << SSC_WPMR_WPKEY_Pos) /**< \brief (SSC_WPMR) Write Protect KEY */
#define SSC_WPMR_WPKEY(value) ((SSC_WPMR_WPKEY_Msk & ((value) << SSC_WPMR_WPKEY_Pos)))
/* -------- SSC_WPSR : (SSC Offset: 0xE8) Write Protect Status Register -------- */
#define SSC_WPSR_WPVS (0x1u << 0) /**< \brief (SSC_WPSR) Write Protect Violation Status */
#define SSC_WPSR_WPVSRC_Pos 8
#define SSC_WPSR_WPVSRC_Msk (0xffffu << SSC_WPSR_WPVSRC_Pos) /**< \brief (SSC_WPSR) Write Protect Violation Source */
/* -------- SSC_RPR : (SSC Offset: 0x100) Receive Pointer Register -------- */
#define SSC_RPR_RXPTR_Pos 0
#define SSC_RPR_RXPTR_Msk (0xffffffffu << SSC_RPR_RXPTR_Pos) /**< \brief (SSC_RPR) Receive Pointer Register */
#define SSC_RPR_RXPTR(value) ((SSC_RPR_RXPTR_Msk & ((value) << SSC_RPR_RXPTR_Pos)))
/* -------- SSC_RCR : (SSC Offset: 0x104) Receive Counter Register -------- */
#define SSC_RCR_RXCTR_Pos 0
#define SSC_RCR_RXCTR_Msk (0xffffu << SSC_RCR_RXCTR_Pos) /**< \brief (SSC_RCR) Receive Counter Register */
#define SSC_RCR_RXCTR(value) ((SSC_RCR_RXCTR_Msk & ((value) << SSC_RCR_RXCTR_Pos)))
/* -------- SSC_TPR : (SSC Offset: 0x108) Transmit Pointer Register -------- */
#define SSC_TPR_TXPTR_Pos 0
#define SSC_TPR_TXPTR_Msk (0xffffffffu << SSC_TPR_TXPTR_Pos) /**< \brief (SSC_TPR) Transmit Counter Register */
#define SSC_TPR_TXPTR(value) ((SSC_TPR_TXPTR_Msk & ((value) << SSC_TPR_TXPTR_Pos)))
/* -------- SSC_TCR : (SSC Offset: 0x10C) Transmit Counter Register -------- */
#define SSC_TCR_TXCTR_Pos 0
#define SSC_TCR_TXCTR_Msk (0xffffu << SSC_TCR_TXCTR_Pos) /**< \brief (SSC_TCR) Transmit Counter Register */
#define SSC_TCR_TXCTR(value) ((SSC_TCR_TXCTR_Msk & ((value) << SSC_TCR_TXCTR_Pos)))
/* -------- SSC_RNPR : (SSC Offset: 0x110) Receive Next Pointer Register -------- */
#define SSC_RNPR_RXNPTR_Pos 0
#define SSC_RNPR_RXNPTR_Msk (0xffffffffu << SSC_RNPR_RXNPTR_Pos) /**< \brief (SSC_RNPR) Receive Next Pointer */
#define SSC_RNPR_RXNPTR(value) ((SSC_RNPR_RXNPTR_Msk & ((value) << SSC_RNPR_RXNPTR_Pos)))
/* -------- SSC_RNCR : (SSC Offset: 0x114) Receive Next Counter Register -------- */
#define SSC_RNCR_RXNCTR_Pos 0
#define SSC_RNCR_RXNCTR_Msk (0xffffu << SSC_RNCR_RXNCTR_Pos) /**< \brief (SSC_RNCR) Receive Next Counter */
#define SSC_RNCR_RXNCTR(value) ((SSC_RNCR_RXNCTR_Msk & ((value) << SSC_RNCR_RXNCTR_Pos)))
/* -------- SSC_TNPR : (SSC Offset: 0x118) Transmit Next Pointer Register -------- */
#define SSC_TNPR_TXNPTR_Pos 0
#define SSC_TNPR_TXNPTR_Msk (0xffffffffu << SSC_TNPR_TXNPTR_Pos) /**< \brief (SSC_TNPR) Transmit Next Pointer */
#define SSC_TNPR_TXNPTR(value) ((SSC_TNPR_TXNPTR_Msk & ((value) << SSC_TNPR_TXNPTR_Pos)))
/* -------- SSC_TNCR : (SSC Offset: 0x11C) Transmit Next Counter Register -------- */
#define SSC_TNCR_TXNCTR_Pos 0
#define SSC_TNCR_TXNCTR_Msk (0xffffu << SSC_TNCR_TXNCTR_Pos) /**< \brief (SSC_TNCR) Transmit Counter Next */
#define SSC_TNCR_TXNCTR(value) ((SSC_TNCR_TXNCTR_Msk & ((value) << SSC_TNCR_TXNCTR_Pos)))
/* -------- SSC_PTCR : (SSC Offset: 0x120) Transfer Control Register -------- */
#define SSC_PTCR_RXTEN (0x1u << 0) /**< \brief (SSC_PTCR) Receiver Transfer Enable */
#define SSC_PTCR_RXTDIS (0x1u << 1) /**< \brief (SSC_PTCR) Receiver Transfer Disable */
#define SSC_PTCR_TXTEN (0x1u << 8) /**< \brief (SSC_PTCR) Transmitter Transfer Enable */
#define SSC_PTCR_TXTDIS (0x1u << 9) /**< \brief (SSC_PTCR) Transmitter Transfer Disable */
/* -------- SSC_PTSR : (SSC Offset: 0x124) Transfer Status Register -------- */
#define SSC_PTSR_RXTEN (0x1u << 0) /**< \brief (SSC_PTSR) Receiver Transfer Enable */
#define SSC_PTSR_TXTEN (0x1u << 8) /**< \brief (SSC_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Supply Controller */
/* ============================================================================= */
/** \addtogroup SAM3S16_SUPC Supply Controller */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Supc hardware registers */
typedef struct {
  WoReg SUPC_CR;   /**< \brief (Supc Offset: 0x00) Supply Controller Control Register */
  RwReg SUPC_SMMR; /**< \brief (Supc Offset: 0x04) Supply Controller Supply Monitor Mode Register */
  RwReg SUPC_MR;   /**< \brief (Supc Offset: 0x08) Supply Controller Mode Register */
  RwReg SUPC_WUMR; /**< \brief (Supc Offset: 0x0C) Supply Controller Wake Up Mode Register */
  RwReg SUPC_WUIR; /**< \brief (Supc Offset: 0x10) Supply Controller Wake Up Inputs Register */
  RoReg SUPC_SR;   /**< \brief (Supc Offset: 0x14) Supply Controller Status Register */
} Supc;
#endif /* __ASSEMBLY__ */
/* -------- SUPC_CR : (SUPC Offset: 0x00) Supply Controller Control Register -------- */
#define SUPC_CR_VROFF (0x1u << 2) /**< \brief (SUPC_CR) Voltage Regulator Off */
#define   SUPC_CR_VROFF_NO_EFFECT (0x0u << 2) /**< \brief (SUPC_CR) no effect. */
#define   SUPC_CR_VROFF_STOP_VREG (0x1u << 2) /**< \brief (SUPC_CR) if KEY is correct, asserts vddcore_nreset and stops the voltage regulator. */
#define SUPC_CR_XTALSEL (0x1u << 3) /**< \brief (SUPC_CR) Crystal Oscillator Select */
#define   SUPC_CR_XTALSEL_NO_EFFECT (0x0u << 3) /**< \brief (SUPC_CR) no effect. */
#define   SUPC_CR_XTALSEL_CRYSTAL_SEL (0x1u << 3) /**< \brief (SUPC_CR) if KEY is correct, switches the slow clock on the crystal oscillator output. */
#define SUPC_CR_KEY_Pos 24
#define SUPC_CR_KEY_Msk (0xffu << SUPC_CR_KEY_Pos) /**< \brief (SUPC_CR) Password */
#define SUPC_CR_KEY(value) ((SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos)))
/* -------- SUPC_SMMR : (SUPC Offset: 0x04) Supply Controller Supply Monitor Mode Register -------- */
#define SUPC_SMMR_SMTH_Pos 0
#define SUPC_SMMR_SMTH_Msk (0xfu << SUPC_SMMR_SMTH_Pos) /**< \brief (SUPC_SMMR) Supply Monitor Threshold */
#define   SUPC_SMMR_SMTH_1_9V (0x0u << 0) /**< \brief (SUPC_SMMR) 1.9 V */
#define   SUPC_SMMR_SMTH_2_0V (0x1u << 0) /**< \brief (SUPC_SMMR) 2.0 V */
#define   SUPC_SMMR_SMTH_2_1V (0x2u << 0) /**< \brief (SUPC_SMMR) 2.1 V */
#define   SUPC_SMMR_SMTH_2_2V (0x3u << 0) /**< \brief (SUPC_SMMR) 2.2 V */
#define   SUPC_SMMR_SMTH_2_3V (0x4u << 0) /**< \brief (SUPC_SMMR) 2.3 V */
#define   SUPC_SMMR_SMTH_2_4V (0x5u << 0) /**< \brief (SUPC_SMMR) 2.4 V */
#define   SUPC_SMMR_SMTH_2_5V (0x6u << 0) /**< \brief (SUPC_SMMR) 2.5 V */
#define   SUPC_SMMR_SMTH_2_6V (0x7u << 0) /**< \brief (SUPC_SMMR) 2.6 V */
#define   SUPC_SMMR_SMTH_2_7V (0x8u << 0) /**< \brief (SUPC_SMMR) 2.7 V */
#define   SUPC_SMMR_SMTH_2_8V (0x9u << 0) /**< \brief (SUPC_SMMR) 2.8 V */
#define   SUPC_SMMR_SMTH_2_9V (0xAu << 0) /**< \brief (SUPC_SMMR) 2.9 V */
#define   SUPC_SMMR_SMTH_3_0V (0xBu << 0) /**< \brief (SUPC_SMMR) 3.0 V */
#define   SUPC_SMMR_SMTH_3_1V (0xCu << 0) /**< \brief (SUPC_SMMR) 3.1 V */
#define   SUPC_SMMR_SMTH_3_2V (0xDu << 0) /**< \brief (SUPC_SMMR) 3.2 V */
#define   SUPC_SMMR_SMTH_3_3V (0xEu << 0) /**< \brief (SUPC_SMMR) 3.3 V */
#define   SUPC_SMMR_SMTH_3_4V (0xFu << 0) /**< \brief (SUPC_SMMR) 3.4 V */
#define SUPC_SMMR_SMSMPL_Pos 8
#define SUPC_SMMR_SMSMPL_Msk (0x7u << SUPC_SMMR_SMSMPL_Pos) /**< \brief (SUPC_SMMR) Supply Monitor Sampling Period */
#define   SUPC_SMMR_SMSMPL_SMD (0x0u << 8) /**< \brief (SUPC_SMMR) Supply Monitor disabled */
#define   SUPC_SMMR_SMSMPL_CSM (0x1u << 8) /**< \brief (SUPC_SMMR) Continuous Supply Monitor */
#define   SUPC_SMMR_SMSMPL_32SLCK (0x2u << 8) /**< \brief (SUPC_SMMR) Supply Monitor enabled one SLCK period every 32 SLCK periods */
#define   SUPC_SMMR_SMSMPL_256SLCK (0x3u << 8) /**< \brief (SUPC_SMMR) Supply Monitor enabled one SLCK period every 256 SLCK periods */
#define   SUPC_SMMR_SMSMPL_2048SLCK (0x4u << 8) /**< \brief (SUPC_SMMR) Supply Monitor enabled one SLCK period every 2,048 SLCK periods */
#define SUPC_SMMR_SMRSTEN (0x1u << 12) /**< \brief (SUPC_SMMR) Supply Monitor Reset Enable */
#define   SUPC_SMMR_SMRSTEN_NOT_ENABLE (0x0u << 12) /**< \brief (SUPC_SMMR) the core reset signal "vddcore_nreset" is not affected when a supply monitor detection occurs. */
#define   SUPC_SMMR_SMRSTEN_ENABLE (0x1u << 12) /**< \brief (SUPC_SMMR) the core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs. */
#define SUPC_SMMR_SMIEN (0x1u << 13) /**< \brief (SUPC_SMMR) Supply Monitor Interrupt Enable */
#define   SUPC_SMMR_SMIEN_NOT_ENABLE (0x0u << 13) /**< \brief (SUPC_SMMR) the SUPC interrupt signal is not affected when a supply monitor detection occurs. */
#define   SUPC_SMMR_SMIEN_ENABLE (0x1u << 13) /**< \brief (SUPC_SMMR) the SUPC interrupt signal is asserted when a supply monitor detection occurs. */
/* -------- SUPC_MR : (SUPC Offset: 0x08) Supply Controller Mode Register -------- */
#define SUPC_MR_BODRSTEN (0x1u << 12) /**< \brief (SUPC_MR) Brownout Detector Reset Enable */
#define   SUPC_MR_BODRSTEN_NOT_ENABLE (0x0u << 12) /**< \brief (SUPC_MR) the core reset signal "vddcore_nreset" is not affected when a brownout detection occurs. */
#define   SUPC_MR_BODRSTEN_ENABLE (0x1u << 12) /**< \brief (SUPC_MR) the core reset signal, vddcore_nreset is asserted when a brownout detection occurs. */
#define SUPC_MR_BODDIS (0x1u << 13) /**< \brief (SUPC_MR) Brownout Detector Disable */
#define   SUPC_MR_BODDIS_ENABLE (0x0u << 13) /**< \brief (SUPC_MR) the core brownout detector is enabled. */
#define   SUPC_MR_BODDIS_DISABLE (0x1u << 13) /**< \brief (SUPC_MR) the core brownout detector is disabled. */
#define SUPC_MR_ONREG (0x1u << 14) /**< \brief (SUPC_MR) Voltage Regulator enable */
#define   SUPC_MR_ONREG_ONREG_UNUSED (0x0u << 14) /**< \brief (SUPC_MR) Voltage Regulator is not used */
#define   SUPC_MR_ONREG_ONREG_USED (0x1u << 14) /**< \brief (SUPC_MR) Voltage Regulator is used */
#define SUPC_MR_OSCBYPASS (0x1u << 20) /**< \brief (SUPC_MR) Oscillator Bypass */
#define   SUPC_MR_OSCBYPASS_NO_EFFECT (0x0u << 20) /**< \brief (SUPC_MR) no effect. Clock selection depends on XTALSEL value. */
#define   SUPC_MR_OSCBYPASS_BYPASS (0x1u << 20) /**< \brief (SUPC_MR) the 32-KHz XTAL oscillator is selected and is put in bypass mode. */
#define SUPC_MR_KEY_Pos 24
#define SUPC_MR_KEY_Msk (0xffu << SUPC_MR_KEY_Pos) /**< \brief (SUPC_MR) Password Key */
#define SUPC_MR_KEY(value) ((SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos)))
/* -------- SUPC_WUMR : (SUPC Offset: 0x0C) Supply Controller Wake Up Mode Register -------- */
#define SUPC_WUMR_SMEN (0x1u << 1) /**< \brief (SUPC_WUMR) Supply Monitor Wake Up Enable */
#define   SUPC_WUMR_SMEN_NOT_ENABLE (0x0u << 1) /**< \brief (SUPC_WUMR) the supply monitor detection has no wake up effect. */
#define   SUPC_WUMR_SMEN_ENABLE (0x1u << 1) /**< \brief (SUPC_WUMR) the supply monitor detection forces the wake up of the core power supply. */
#define SUPC_WUMR_RTTEN (0x1u << 2) /**< \brief (SUPC_WUMR) Real Time Timer Wake Up Enable */
#define   SUPC_WUMR_RTTEN_NOT_ENABLE (0x0u << 2) /**< \brief (SUPC_WUMR) the RTT alarm signal has no wake up effect. */
#define   SUPC_WUMR_RTTEN_ENABLE (0x1u << 2) /**< \brief (SUPC_WUMR) the RTT alarm signal forces the wake up of the core power supply. */
#define SUPC_WUMR_RTCEN (0x1u << 3) /**< \brief (SUPC_WUMR) Real Time Clock Wake Up Enable */
#define   SUPC_WUMR_RTCEN_NOT_ENABLE (0x0u << 3) /**< \brief (SUPC_WUMR) the RTC alarm signal has no wake up effect. */
#define   SUPC_WUMR_RTCEN_ENABLE (0x1u << 3) /**< \brief (SUPC_WUMR) the RTC alarm signal forces the wake up of the core power supply. */
#define SUPC_WUMR_WKUPDBC_Pos 12
#define SUPC_WUMR_WKUPDBC_Msk (0x7u << SUPC_WUMR_WKUPDBC_Pos) /**< \brief (SUPC_WUMR) Wake Up Inputs Debouncer Period */
#define   SUPC_WUMR_WKUPDBC_IMMEDIATE (0x0u << 12) /**< \brief (SUPC_WUMR) Immediate, no debouncing, detected active at least on one Slow Clock edge. */
#define   SUPC_WUMR_WKUPDBC_3_SCLK (0x1u << 12) /**< \brief (SUPC_WUMR) WKUPx shall be in its active state for at least 3 SLCK periods */
#define   SUPC_WUMR_WKUPDBC_32_SCLK (0x2u << 12) /**< \brief (SUPC_WUMR) WKUPx shall be in its active state for at least 32 SLCK periods */
#define   SUPC_WUMR_WKUPDBC_512_SCLK (0x3u << 12) /**< \brief (SUPC_WUMR) WKUPx shall be in its active state for at least 512 SLCK periods */
#define   SUPC_WUMR_WKUPDBC_4096_SCLK (0x4u << 12) /**< \brief (SUPC_WUMR) WKUPx shall be in its active state for at least 4,096 SLCK periods */
#define   SUPC_WUMR_WKUPDBC_32768_SCLK (0x5u << 12) /**< \brief (SUPC_WUMR) WKUPx shall be in its active state for at least 32,768 SLCK periods */
/* -------- SUPC_WUIR : (SUPC Offset: 0x10) Supply Controller Wake Up Inputs Register -------- */
#define SUPC_WUIR_WKUPEN0 (0x1u << 0) /**< \brief (SUPC_WUIR) Wake Up Input Enable 0 */
#define   SUPC_WUIR_WKUPEN0_NOT_ENABLE (0x0u << 0) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN0_ENABLE (0x1u << 0) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN1 (0x1u << 1) /**< \brief (SUPC_WUIR) Wake Up Input Enable 1 */
#define   SUPC_WUIR_WKUPEN1_NOT_ENABLE (0x0u << 1) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN1_ENABLE (0x1u << 1) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN2 (0x1u << 2) /**< \brief (SUPC_WUIR) Wake Up Input Enable 2 */
#define   SUPC_WUIR_WKUPEN2_NOT_ENABLE (0x0u << 2) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN2_ENABLE (0x1u << 2) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN3 (0x1u << 3) /**< \brief (SUPC_WUIR) Wake Up Input Enable 3 */
#define   SUPC_WUIR_WKUPEN3_NOT_ENABLE (0x0u << 3) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN3_ENABLE (0x1u << 3) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN4 (0x1u << 4) /**< \brief (SUPC_WUIR) Wake Up Input Enable 4 */
#define   SUPC_WUIR_WKUPEN4_NOT_ENABLE (0x0u << 4) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN4_ENABLE (0x1u << 4) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN5 (0x1u << 5) /**< \brief (SUPC_WUIR) Wake Up Input Enable 5 */
#define   SUPC_WUIR_WKUPEN5_NOT_ENABLE (0x0u << 5) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN5_ENABLE (0x1u << 5) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN6 (0x1u << 6) /**< \brief (SUPC_WUIR) Wake Up Input Enable 6 */
#define   SUPC_WUIR_WKUPEN6_NOT_ENABLE (0x0u << 6) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN6_ENABLE (0x1u << 6) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN7 (0x1u << 7) /**< \brief (SUPC_WUIR) Wake Up Input Enable 7 */
#define   SUPC_WUIR_WKUPEN7_NOT_ENABLE (0x0u << 7) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN7_ENABLE (0x1u << 7) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN8 (0x1u << 8) /**< \brief (SUPC_WUIR) Wake Up Input Enable 8 */
#define   SUPC_WUIR_WKUPEN8_NOT_ENABLE (0x0u << 8) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN8_ENABLE (0x1u << 8) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN9 (0x1u << 9) /**< \brief (SUPC_WUIR) Wake Up Input Enable 9 */
#define   SUPC_WUIR_WKUPEN9_NOT_ENABLE (0x0u << 9) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN9_ENABLE (0x1u << 9) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN10 (0x1u << 10) /**< \brief (SUPC_WUIR) Wake Up Input Enable 10 */
#define   SUPC_WUIR_WKUPEN10_NOT_ENABLE (0x0u << 10) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN10_ENABLE (0x1u << 10) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN11 (0x1u << 11) /**< \brief (SUPC_WUIR) Wake Up Input Enable 11 */
#define   SUPC_WUIR_WKUPEN11_NOT_ENABLE (0x0u << 11) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN11_ENABLE (0x1u << 11) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN12 (0x1u << 12) /**< \brief (SUPC_WUIR) Wake Up Input Enable 12 */
#define   SUPC_WUIR_WKUPEN12_NOT_ENABLE (0x0u << 12) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN12_ENABLE (0x1u << 12) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN13 (0x1u << 13) /**< \brief (SUPC_WUIR) Wake Up Input Enable 13 */
#define   SUPC_WUIR_WKUPEN13_NOT_ENABLE (0x0u << 13) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN13_ENABLE (0x1u << 13) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN14 (0x1u << 14) /**< \brief (SUPC_WUIR) Wake Up Input Enable 14 */
#define   SUPC_WUIR_WKUPEN14_NOT_ENABLE (0x0u << 14) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN14_ENABLE (0x1u << 14) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPEN15 (0x1u << 15) /**< \brief (SUPC_WUIR) Wake Up Input Enable 15 */
#define   SUPC_WUIR_WKUPEN15_NOT_ENABLE (0x0u << 15) /**< \brief (SUPC_WUIR) the corresponding wake-up input has no wake up effect. */
#define   SUPC_WUIR_WKUPEN15_ENABLE (0x1u << 15) /**< \brief (SUPC_WUIR) the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT0 (0x1u << 16) /**< \brief (SUPC_WUIR) Wake Up Input Transition 0 */
#define   SUPC_WUIR_WKUPT0_HIGH_TO_LOW (0x0u << 16) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT0_LOW_TO_HIGH (0x1u << 16) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT1 (0x1u << 17) /**< \brief (SUPC_WUIR) Wake Up Input Transition 1 */
#define   SUPC_WUIR_WKUPT1_HIGH_TO_LOW (0x0u << 17) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT1_LOW_TO_HIGH (0x1u << 17) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT2 (0x1u << 18) /**< \brief (SUPC_WUIR) Wake Up Input Transition 2 */
#define   SUPC_WUIR_WKUPT2_HIGH_TO_LOW (0x0u << 18) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT2_LOW_TO_HIGH (0x1u << 18) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT3 (0x1u << 19) /**< \brief (SUPC_WUIR) Wake Up Input Transition 3 */
#define   SUPC_WUIR_WKUPT3_HIGH_TO_LOW (0x0u << 19) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT3_LOW_TO_HIGH (0x1u << 19) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT4 (0x1u << 20) /**< \brief (SUPC_WUIR) Wake Up Input Transition 4 */
#define   SUPC_WUIR_WKUPT4_HIGH_TO_LOW (0x0u << 20) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT4_LOW_TO_HIGH (0x1u << 20) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT5 (0x1u << 21) /**< \brief (SUPC_WUIR) Wake Up Input Transition 5 */
#define   SUPC_WUIR_WKUPT5_HIGH_TO_LOW (0x0u << 21) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT5_LOW_TO_HIGH (0x1u << 21) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT6 (0x1u << 22) /**< \brief (SUPC_WUIR) Wake Up Input Transition 6 */
#define   SUPC_WUIR_WKUPT6_HIGH_TO_LOW (0x0u << 22) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT6_LOW_TO_HIGH (0x1u << 22) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT7 (0x1u << 23) /**< \brief (SUPC_WUIR) Wake Up Input Transition 7 */
#define   SUPC_WUIR_WKUPT7_HIGH_TO_LOW (0x0u << 23) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT7_LOW_TO_HIGH (0x1u << 23) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT8 (0x1u << 24) /**< \brief (SUPC_WUIR) Wake Up Input Transition 8 */
#define   SUPC_WUIR_WKUPT8_HIGH_TO_LOW (0x0u << 24) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT8_LOW_TO_HIGH (0x1u << 24) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT9 (0x1u << 25) /**< \brief (SUPC_WUIR) Wake Up Input Transition 9 */
#define   SUPC_WUIR_WKUPT9_HIGH_TO_LOW (0x0u << 25) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT9_LOW_TO_HIGH (0x1u << 25) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT10 (0x1u << 26) /**< \brief (SUPC_WUIR) Wake Up Input Transition 10 */
#define   SUPC_WUIR_WKUPT10_HIGH_TO_LOW (0x0u << 26) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT10_LOW_TO_HIGH (0x1u << 26) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT11 (0x1u << 27) /**< \brief (SUPC_WUIR) Wake Up Input Transition 11 */
#define   SUPC_WUIR_WKUPT11_HIGH_TO_LOW (0x0u << 27) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT11_LOW_TO_HIGH (0x1u << 27) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT12 (0x1u << 28) /**< \brief (SUPC_WUIR) Wake Up Input Transition 12 */
#define   SUPC_WUIR_WKUPT12_HIGH_TO_LOW (0x0u << 28) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT12_LOW_TO_HIGH (0x1u << 28) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT13 (0x1u << 29) /**< \brief (SUPC_WUIR) Wake Up Input Transition 13 */
#define   SUPC_WUIR_WKUPT13_HIGH_TO_LOW (0x0u << 29) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT13_LOW_TO_HIGH (0x1u << 29) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT14 (0x1u << 30) /**< \brief (SUPC_WUIR) Wake Up Input Transition 14 */
#define   SUPC_WUIR_WKUPT14_HIGH_TO_LOW (0x0u << 30) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT14_LOW_TO_HIGH (0x1u << 30) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define SUPC_WUIR_WKUPT15 (0x1u << 31) /**< \brief (SUPC_WUIR) Wake Up Input Transition 15 */
#define   SUPC_WUIR_WKUPT15_HIGH_TO_LOW (0x0u << 31) /**< \brief (SUPC_WUIR) a high to low level transition on the corresponding wake-up input forces the wake up of the core power supply. */
#define   SUPC_WUIR_WKUPT15_LOW_TO_HIGH (0x1u << 31) /**< \brief (SUPC_WUIR) a low to high level transition on the corresponding wake-up input forces the wake up of the core power supply. */
/* -------- SUPC_SR : (SUPC Offset: 0x14) Supply Controller Status Register -------- */
#define SUPC_SR_WKUPS (0x1u << 1) /**< \brief (SUPC_SR) WKUP Wake Up Status */
#define   SUPC_SR_WKUPS_NO (0x0u << 1) /**< \brief (SUPC_SR) no wake up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. */
#define   SUPC_SR_WKUPS_PRESENT (0x1u << 1) /**< \brief (SUPC_SR) at least one wake up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. */
#define SUPC_SR_SMWS (0x1u << 2) /**< \brief (SUPC_SR) Supply Monitor Detection Wake Up Status */
#define   SUPC_SR_SMWS_NO (0x0u << 2) /**< \brief (SUPC_SR) no wake up due to a supply monitor detection has occurred since the last read of SUPC_SR. */
#define   SUPC_SR_SMWS_PRESENT (0x1u << 2) /**< \brief (SUPC_SR) at least one wake up due to a supply monitor detection has occurred since the last read of SUPC_SR. */
#define SUPC_SR_BODRSTS (0x1u << 3) /**< \brief (SUPC_SR) Brownout Detector Reset Status */
#define   SUPC_SR_BODRSTS_NO (0x0u << 3) /**< \brief (SUPC_SR) no core brownout rising edge event has been detected since the last read of the SUPC_SR. */
#define   SUPC_SR_BODRSTS_PRESENT (0x1u << 3) /**< \brief (SUPC_SR) at least one brownout output rising edge event has been detected since the last read of the SUPC_SR. */
#define SUPC_SR_SMRSTS (0x1u << 4) /**< \brief (SUPC_SR) Supply Monitor Reset Status */
#define   SUPC_SR_SMRSTS_NO (0x0u << 4) /**< \brief (SUPC_SR) no supply monitor detection has generated a core reset since the last read of the SUPC_SR. */
#define   SUPC_SR_SMRSTS_PRESENT (0x1u << 4) /**< \brief (SUPC_SR) at least one supply monitor detection has generated a core reset since the last read of the SUPC_SR. */
#define SUPC_SR_SMS (0x1u << 5) /**< \brief (SUPC_SR) Supply Monitor Status */
#define   SUPC_SR_SMS_NO (0x0u << 5) /**< \brief (SUPC_SR) no supply monitor detection since the last read of SUPC_SR. */
#define   SUPC_SR_SMS_PRESENT (0x1u << 5) /**< \brief (SUPC_SR) at least one supply monitor detection since the last read of SUPC_SR. */
#define SUPC_SR_SMOS (0x1u << 6) /**< \brief (SUPC_SR) Supply Monitor Output Status */
#define   SUPC_SR_SMOS_HIGH (0x0u << 6) /**< \brief (SUPC_SR) the supply monitor detected VDDIO higher than its threshold at its last measurement. */
#define   SUPC_SR_SMOS_LOW (0x1u << 6) /**< \brief (SUPC_SR) the supply monitor detected VDDIO lower than its threshold at its last measurement. */
#define SUPC_SR_OSCSEL (0x1u << 7) /**< \brief (SUPC_SR) 32-kHz Oscillator Selection Status */
#define   SUPC_SR_OSCSEL_RC (0x0u << 7) /**< \brief (SUPC_SR) the slow clock, SLCK is generated by the embedded 32-kHz RC oscillator. */
#define   SUPC_SR_OSCSEL_CRYST (0x1u << 7) /**< \brief (SUPC_SR) the slow clock, SLCK is generated by the 32-kHz crystal oscillator. */
#define SUPC_SR_WKUPIS0 (0x1u << 16) /**< \brief (SUPC_SR) WKUP Input Status 0 */
#define   SUPC_SR_WKUPIS0_DIS (0x0u << 16) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS0_EN (0x1u << 16) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS1 (0x1u << 17) /**< \brief (SUPC_SR) WKUP Input Status 1 */
#define   SUPC_SR_WKUPIS1_DIS (0x0u << 17) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS1_EN (0x1u << 17) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS2 (0x1u << 18) /**< \brief (SUPC_SR) WKUP Input Status 2 */
#define   SUPC_SR_WKUPIS2_DIS (0x0u << 18) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS2_EN (0x1u << 18) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS3 (0x1u << 19) /**< \brief (SUPC_SR) WKUP Input Status 3 */
#define   SUPC_SR_WKUPIS3_DIS (0x0u << 19) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS3_EN (0x1u << 19) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS4 (0x1u << 20) /**< \brief (SUPC_SR) WKUP Input Status 4 */
#define   SUPC_SR_WKUPIS4_DIS (0x0u << 20) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS4_EN (0x1u << 20) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS5 (0x1u << 21) /**< \brief (SUPC_SR) WKUP Input Status 5 */
#define   SUPC_SR_WKUPIS5_DIS (0x0u << 21) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS5_EN (0x1u << 21) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS6 (0x1u << 22) /**< \brief (SUPC_SR) WKUP Input Status 6 */
#define   SUPC_SR_WKUPIS6_DIS (0x0u << 22) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS6_EN (0x1u << 22) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS7 (0x1u << 23) /**< \brief (SUPC_SR) WKUP Input Status 7 */
#define   SUPC_SR_WKUPIS7_DIS (0x0u << 23) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS7_EN (0x1u << 23) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS8 (0x1u << 24) /**< \brief (SUPC_SR) WKUP Input Status 8 */
#define   SUPC_SR_WKUPIS8_DIS (0x0u << 24) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS8_EN (0x1u << 24) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS9 (0x1u << 25) /**< \brief (SUPC_SR) WKUP Input Status 9 */
#define   SUPC_SR_WKUPIS9_DIS (0x0u << 25) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS9_EN (0x1u << 25) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS10 (0x1u << 26) /**< \brief (SUPC_SR) WKUP Input Status 10 */
#define   SUPC_SR_WKUPIS10_DIS (0x0u << 26) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS10_EN (0x1u << 26) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS11 (0x1u << 27) /**< \brief (SUPC_SR) WKUP Input Status 11 */
#define   SUPC_SR_WKUPIS11_DIS (0x0u << 27) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS11_EN (0x1u << 27) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS12 (0x1u << 28) /**< \brief (SUPC_SR) WKUP Input Status 12 */
#define   SUPC_SR_WKUPIS12_DIS (0x0u << 28) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS12_EN (0x1u << 28) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS13 (0x1u << 29) /**< \brief (SUPC_SR) WKUP Input Status 13 */
#define   SUPC_SR_WKUPIS13_DIS (0x0u << 29) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS13_EN (0x1u << 29) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS14 (0x1u << 30) /**< \brief (SUPC_SR) WKUP Input Status 14 */
#define   SUPC_SR_WKUPIS14_DIS (0x0u << 30) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS14_EN (0x1u << 30) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */
#define SUPC_SR_WKUPIS15 (0x1u << 31) /**< \brief (SUPC_SR) WKUP Input Status 15 */
#define   SUPC_SR_WKUPIS15_DIS (0x0u << 31) /**< \brief (SUPC_SR) the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event. */
#define   SUPC_SR_WKUPIS15_EN (0x1u << 31) /**< \brief (SUPC_SR) the corresponding wake-up input was active at the time the debouncer triggered a wake up event. */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Timer Counter */
/* ============================================================================= */
/** \addtogroup SAM3S16_TC Timer Counter */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief TcChannel hardware registers */
typedef struct {
  RwReg      TC_CCR;        /**< \brief (TcChannel Offset: 0x0) Channel Control Register */
  RwReg      TC_CMR;        /**< \brief (TcChannel Offset: 0x4) Channel Mode Register */
  RwReg      TC_SMMR;       /**< \brief (TcChannel Offset: 0x8) Stepper Motor Mode Register */
  RoReg      Reserved1[1];
  RwReg      TC_CV;         /**< \brief (TcChannel Offset: 0x10) Counter Value */
  RwReg      TC_RA;         /**< \brief (TcChannel Offset: 0x14) Register A */
  RwReg      TC_RB;         /**< \brief (TcChannel Offset: 0x18) Register B */
  RwReg      TC_RC;         /**< \brief (TcChannel Offset: 0x1C) Register C */
  RwReg      TC_SR;         /**< \brief (TcChannel Offset: 0x20) Status Register */
  RwReg      TC_IER;        /**< \brief (TcChannel Offset: 0x24) Interrupt Enable Register */
  RwReg      TC_IDR;        /**< \brief (TcChannel Offset: 0x28) Interrupt Disable Register */
  RwReg      TC_IMR;        /**< \brief (TcChannel Offset: 0x2C) Interrupt Mask Register */
  RoReg      Reserved2[4];
} TcChannel;
/** \brief Tc hardware registers */
#define TCCHANNEL_NUMBER 3
typedef struct {
  TcChannel  TC_CHANNEL[TCCHANNEL_NUMBER]; /**< \brief (Tc Offset: 0x0) channel = 0 .. 2 */
  WoReg      TC_BCR;        /**< \brief (Tc Offset: 0xC0) Block Control Register */
  RwReg      TC_BMR;        /**< \brief (Tc Offset: 0xC4) Block Mode Register */
  WoReg      TC_QIER;       /**< \brief (Tc Offset: 0xC8) QDEC Interrupt Enable Register */
  WoReg      TC_QIDR;       /**< \brief (Tc Offset: 0xCC) QDEC Interrupt Disable Register */
  RoReg      TC_QIMR;       /**< \brief (Tc Offset: 0xD0) QDEC Interrupt Mask Register */
  RoReg      TC_QISR;       /**< \brief (Tc Offset: 0xD4) QDEC Interrupt Status Register */
  RwReg      TC_FMR;        /**< \brief (Tc Offset: 0xD8) Fault Mode Register */
  RoReg      Reserved1[2];
  RwReg      TC_WPMR;       /**< \brief (Tc Offset: 0xE4) Write Protect Mode Register */
} Tc;
#endif /* __ASSEMBLY__ */
/* -------- TC_CCR : (TC Offset: N/A) Channel Control Register -------- */
#define TC_CCR_CLKEN (0x1u << 0) /**< \brief (TC_CCR) Counter Clock Enable Command */
#define TC_CCR_CLKDIS (0x1u << 1) /**< \brief (TC_CCR) Counter Clock Disable Command */
#define TC_CCR_SWTRG (0x1u << 2) /**< \brief (TC_CCR) Software Trigger Command */
/* -------- TC_CMR : (TC Offset: N/A) Channel Mode Register -------- */
#define TC_CMR_TCCLKS_Pos 0
#define TC_CMR_TCCLKS_Msk (0x7u << TC_CMR_TCCLKS_Pos) /**< \brief (TC_CMR) Clock Selection */
#define   TC_CMR_TCCLKS_TIMER_CLOCK1 (0x0u << 0) /**< \brief (TC_CMR) Clock selected: TCLK1 */
#define   TC_CMR_TCCLKS_TIMER_CLOCK2 (0x1u << 0) /**< \brief (TC_CMR) Clock selected: TCLK2 */
#define   TC_CMR_TCCLKS_TIMER_CLOCK3 (0x2u << 0) /**< \brief (TC_CMR) Clock selected: TCLK3 */
#define   TC_CMR_TCCLKS_TIMER_CLOCK4 (0x3u << 0) /**< \brief (TC_CMR) Clock selected: TCLK4 */
#define   TC_CMR_TCCLKS_TIMER_CLOCK5 (0x4u << 0) /**< \brief (TC_CMR) Clock selected: TCLK5 */
#define   TC_CMR_TCCLKS_XC0 (0x5u << 0) /**< \brief (TC_CMR) Clock selected: XC0 */
#define   TC_CMR_TCCLKS_XC1 (0x6u << 0) /**< \brief (TC_CMR) Clock selected: XC1 */
#define   TC_CMR_TCCLKS_XC2 (0x7u << 0) /**< \brief (TC_CMR) Clock selected: XC2 */
#define TC_CMR_CLKI (0x1u << 3) /**< \brief (TC_CMR) Clock Invert */
#define TC_CMR_BURST_Pos 4
#define TC_CMR_BURST_Msk (0x3u << TC_CMR_BURST_Pos) /**< \brief (TC_CMR) Burst Signal Selection */
#define   TC_CMR_BURST_NONE (0x0u << 4) /**< \brief (TC_CMR) The clock is not gated by an external signal. */
#define   TC_CMR_BURST_XC0 (0x1u << 4) /**< \brief (TC_CMR) XC0 is ANDed with the selected clock. */
#define   TC_CMR_BURST_XC1 (0x2u << 4) /**< \brief (TC_CMR) XC1 is ANDed with the selected clock. */
#define   TC_CMR_BURST_XC2 (0x3u << 4) /**< \brief (TC_CMR) XC2 is ANDed with the selected clock. */
#define TC_CMR_LDBSTOP (0x1u << 6) /**< \brief (TC_CMR) Counter Clock Stopped with RB Loading */
#define TC_CMR_LDBDIS (0x1u << 7) /**< \brief (TC_CMR) Counter Clock Disable with RB Loading */
#define TC_CMR_ETRGEDG_Pos 8
#define TC_CMR_ETRGEDG_Msk (0x3u << TC_CMR_ETRGEDG_Pos) /**< \brief (TC_CMR) External Trigger Edge Selection */
#define   TC_CMR_ETRGEDG_NONE (0x0u << 8) /**< \brief (TC_CMR) The clock is not gated by an external signal. */
#define   TC_CMR_ETRGEDG_RISING (0x1u << 8) /**< \brief (TC_CMR) Rising edge */
#define   TC_CMR_ETRGEDG_FALLING (0x2u << 8) /**< \brief (TC_CMR) Falling edge */
#define   TC_CMR_ETRGEDG_EDGE (0x3u << 8) /**< \brief (TC_CMR) Each edge */
#define TC_CMR_ABETRG (0x1u << 10) /**< \brief (TC_CMR) TIOA or TIOB External Trigger Selection */
#define TC_CMR_CPCTRG (0x1u << 14) /**< \brief (TC_CMR) RC Compare Trigger Enable */
#define TC_CMR_WAVE (0x1u << 15) /**< \brief (TC_CMR) Waveform Mode */
#define TC_CMR_LDRA_Pos 16
#define TC_CMR_LDRA_Msk (0x3u << TC_CMR_LDRA_Pos) /**< \brief (TC_CMR) RA Loading Edge Selection */
#define   TC_CMR_LDRA_NONE (0x0u << 16) /**< \brief (TC_CMR) None */
#define   TC_CMR_LDRA_RISING (0x1u << 16) /**< \brief (TC_CMR) Rising edge of TIOA */
#define   TC_CMR_LDRA_FALLING (0x2u << 16) /**< \brief (TC_CMR) Falling edge of TIOA */
#define   TC_CMR_LDRA_EDGE (0x3u << 16) /**< \brief (TC_CMR) Each edge of TIOA */
#define TC_CMR_LDRB_Pos 18
#define TC_CMR_LDRB_Msk (0x3u << TC_CMR_LDRB_Pos) /**< \brief (TC_CMR) RB Loading Edge Selection */
#define   TC_CMR_LDRB_NONE (0x0u << 18) /**< \brief (TC_CMR) None */
#define   TC_CMR_LDRB_RISING (0x1u << 18) /**< \brief (TC_CMR) Rising edge of TIOA */
#define   TC_CMR_LDRB_FALLING (0x2u << 18) /**< \brief (TC_CMR) Falling edge of TIOA */
#define   TC_CMR_LDRB_EDGE (0x3u << 18) /**< \brief (TC_CMR) Each edge of TIOA */
#define TC_CMR_CPCSTOP (0x1u << 6) /**< \brief (TC_CMR) Counter Clock Stopped with RC Compare */
#define TC_CMR_CPCDIS (0x1u << 7) /**< \brief (TC_CMR) Counter Clock Disable with RC Compare */
#define TC_CMR_EEVTEDG_Pos 8
#define TC_CMR_EEVTEDG_Msk (0x3u << TC_CMR_EEVTEDG_Pos) /**< \brief (TC_CMR) External Event Edge Selection */
#define   TC_CMR_EEVTEDG_NONE (0x0u << 8) /**< \brief (TC_CMR) None */
#define   TC_CMR_EEVTEDG_RISING (0x1u << 8) /**< \brief (TC_CMR) Rising edge */
#define   TC_CMR_EEVTEDG_FALLING (0x2u << 8) /**< \brief (TC_CMR) Falling edge */
#define   TC_CMR_EEVTEDG_EDGE (0x3u << 8) /**< \brief (TC_CMR) Each edge */
#define TC_CMR_EEVT_Pos 10
#define TC_CMR_EEVT_Msk (0x3u << TC_CMR_EEVT_Pos) /**< \brief (TC_CMR) External Event Selection */
#define   TC_CMR_EEVT_TIOB (0x0u << 10) /**< \brief (TC_CMR) TIOB */
#define   TC_CMR_EEVT_XC0 (0x1u << 10) /**< \brief (TC_CMR) XC0 */
#define   TC_CMR_EEVT_XC1 (0x2u << 10) /**< \brief (TC_CMR) XC1 */
#define   TC_CMR_EEVT_XC2 (0x3u << 10) /**< \brief (TC_CMR) XC2 */
#define TC_CMR_ENETRG (0x1u << 12) /**< \brief (TC_CMR) External Event Trigger Enable */
#define TC_CMR_WAVSEL_Pos 13
#define TC_CMR_WAVSEL_Msk (0x3u << TC_CMR_WAVSEL_Pos) /**< \brief (TC_CMR) Waveform Selection */
#define   TC_CMR_WAVSEL_UP (0x0u << 13) /**< \brief (TC_CMR) UP mode without automatic trigger on RC Compare */
#define   TC_CMR_WAVSEL_UPDOWN (0x1u << 13) /**< \brief (TC_CMR) UPDOWN mode without automatic trigger on RC Compare */
#define   TC_CMR_WAVSEL_UP_RC (0x2u << 13) /**< \brief (TC_CMR) UP mode with automatic trigger on RC Compare */
#define   TC_CMR_WAVSEL_UPDOWN_RC (0x3u << 13) /**< \brief (TC_CMR) UPDOWN mode with automatic trigger on RC Compare */
#define TC_CMR_ACPA_Pos 16
#define TC_CMR_ACPA_Msk (0x3u << TC_CMR_ACPA_Pos) /**< \brief (TC_CMR) RA Compare Effect on TIOA */
#define   TC_CMR_ACPA_NONE (0x0u << 16) /**< \brief (TC_CMR) None */
#define   TC_CMR_ACPA_SET (0x1u << 16) /**< \brief (TC_CMR) Set */
#define   TC_CMR_ACPA_CLEAR (0x2u << 16) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_ACPA_TOGGLE (0x3u << 16) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_ACPC_Pos 18
#define TC_CMR_ACPC_Msk (0x3u << TC_CMR_ACPC_Pos) /**< \brief (TC_CMR) RC Compare Effect on TIOA */
#define   TC_CMR_ACPC_NONE (0x0u << 18) /**< \brief (TC_CMR) None */
#define   TC_CMR_ACPC_SET (0x1u << 18) /**< \brief (TC_CMR) Set */
#define   TC_CMR_ACPC_CLEAR (0x2u << 18) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_ACPC_TOGGLE (0x3u << 18) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_AEEVT_Pos 20
#define TC_CMR_AEEVT_Msk (0x3u << TC_CMR_AEEVT_Pos) /**< \brief (TC_CMR) External Event Effect on TIOA */
#define   TC_CMR_AEEVT_NONE (0x0u << 20) /**< \brief (TC_CMR) None */
#define   TC_CMR_AEEVT_SET (0x1u << 20) /**< \brief (TC_CMR) Set */
#define   TC_CMR_AEEVT_CLEAR (0x2u << 20) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_AEEVT_TOGGLE (0x3u << 20) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_ASWTRG_Pos 22
#define TC_CMR_ASWTRG_Msk (0x3u << TC_CMR_ASWTRG_Pos) /**< \brief (TC_CMR) Software Trigger Effect on TIOA */
#define   TC_CMR_ASWTRG_NONE (0x0u << 22) /**< \brief (TC_CMR) None */
#define   TC_CMR_ASWTRG_SET (0x1u << 22) /**< \brief (TC_CMR) Set */
#define   TC_CMR_ASWTRG_CLEAR (0x2u << 22) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_ASWTRG_TOGGLE (0x3u << 22) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BCPB_Pos 24
#define TC_CMR_BCPB_Msk (0x3u << TC_CMR_BCPB_Pos) /**< \brief (TC_CMR) RB Compare Effect on TIOB */
#define   TC_CMR_BCPB_NONE (0x0u << 24) /**< \brief (TC_CMR) None */
#define   TC_CMR_BCPB_SET (0x1u << 24) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BCPB_CLEAR (0x2u << 24) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BCPB_TOGGLE (0x3u << 24) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BCPC_Pos 26
#define TC_CMR_BCPC_Msk (0x3u << TC_CMR_BCPC_Pos) /**< \brief (TC_CMR) RC Compare Effect on TIOB */
#define   TC_CMR_BCPC_NONE (0x0u << 26) /**< \brief (TC_CMR) None */
#define   TC_CMR_BCPC_SET (0x1u << 26) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BCPC_CLEAR (0x2u << 26) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BCPC_TOGGLE (0x3u << 26) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BEEVT_Pos 28
#define TC_CMR_BEEVT_Msk (0x3u << TC_CMR_BEEVT_Pos) /**< \brief (TC_CMR) External Event Effect on TIOB */
#define   TC_CMR_BEEVT_NONE (0x0u << 28) /**< \brief (TC_CMR) None */
#define   TC_CMR_BEEVT_SET (0x1u << 28) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BEEVT_CLEAR (0x2u << 28) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BEEVT_TOGGLE (0x3u << 28) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BSWTRG_Pos 30
#define TC_CMR_BSWTRG_Msk (0x3u << TC_CMR_BSWTRG_Pos) /**< \brief (TC_CMR) Software Trigger Effect on TIOB */
#define   TC_CMR_BSWTRG_NONE (0x0u << 30) /**< \brief (TC_CMR) None */
#define   TC_CMR_BSWTRG_SET (0x1u << 30) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BSWTRG_CLEAR (0x2u << 30) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BSWTRG_TOGGLE (0x3u << 30) /**< \brief (TC_CMR) Toggle */
/* -------- TC_SMMR : (TC Offset: N/A) Stepper Motor Mode Register -------- */
#define TC_SMMR_GCEN (0x1u << 0) /**< \brief (TC_SMMR) Gray Count Enable */
#define TC_SMMR_DOWN (0x1u << 1) /**< \brief (TC_SMMR) DOWN Count */
/* -------- TC_CV : (TC Offset: N/A) Counter Value -------- */
#define TC_CV_CV_Pos 0
#define TC_CV_CV_Msk (0xffffffffu << TC_CV_CV_Pos) /**< \brief (TC_CV) Counter Value */
/* -------- TC_RA : (TC Offset: N/A) Register A -------- */
#define TC_RA_RA_Pos 0
#define TC_RA_RA_Msk (0xffffffffu << TC_RA_RA_Pos) /**< \brief (TC_RA) Register A */
#define TC_RA_RA(value) ((TC_RA_RA_Msk & ((value) << TC_RA_RA_Pos)))
/* -------- TC_RB : (TC Offset: N/A) Register B -------- */
#define TC_RB_RB_Pos 0
#define TC_RB_RB_Msk (0xffffffffu << TC_RB_RB_Pos) /**< \brief (TC_RB) Register B */
#define TC_RB_RB(value) ((TC_RB_RB_Msk & ((value) << TC_RB_RB_Pos)))
/* -------- TC_RC : (TC Offset: N/A) Register C -------- */
#define TC_RC_RC_Pos 0
#define TC_RC_RC_Msk (0xffffffffu << TC_RC_RC_Pos) /**< \brief (TC_RC) Register C */
#define TC_RC_RC(value) ((TC_RC_RC_Msk & ((value) << TC_RC_RC_Pos)))
/* -------- TC_SR : (TC Offset: N/A) Status Register -------- */
#define TC_SR_COVFS (0x1u << 0) /**< \brief (TC_SR) Counter Overflow Status */
#define TC_SR_LOVRS (0x1u << 1) /**< \brief (TC_SR) Load Overrun Status */
#define TC_SR_CPAS (0x1u << 2) /**< \brief (TC_SR) RA Compare Status */
#define TC_SR_CPBS (0x1u << 3) /**< \brief (TC_SR) RB Compare Status */
#define TC_SR_CPCS (0x1u << 4) /**< \brief (TC_SR) RC Compare Status */
#define TC_SR_LDRAS (0x1u << 5) /**< \brief (TC_SR) RA Loading Status */
#define TC_SR_LDRBS (0x1u << 6) /**< \brief (TC_SR) RB Loading Status */
#define TC_SR_ETRGS (0x1u << 7) /**< \brief (TC_SR) External Trigger Status */
#define TC_SR_CLKSTA (0x1u << 16) /**< \brief (TC_SR) Clock Enabling Status */
#define TC_SR_MTIOA (0x1u << 17) /**< \brief (TC_SR) TIOA Mirror */
#define TC_SR_MTIOB (0x1u << 18) /**< \brief (TC_SR) TIOB Mirror */
/* -------- TC_IER : (TC Offset: N/A) Interrupt Enable Register -------- */
#define TC_IER_COVFS (0x1u << 0) /**< \brief (TC_IER) Counter Overflow */
#define TC_IER_LOVRS (0x1u << 1) /**< \brief (TC_IER) Load Overrun */
#define TC_IER_CPAS (0x1u << 2) /**< \brief (TC_IER) RA Compare */
#define TC_IER_CPBS (0x1u << 3) /**< \brief (TC_IER) RB Compare */
#define TC_IER_CPCS (0x1u << 4) /**< \brief (TC_IER) RC Compare */
#define TC_IER_LDRAS (0x1u << 5) /**< \brief (TC_IER) RA Loading */
#define TC_IER_LDRBS (0x1u << 6) /**< \brief (TC_IER) RB Loading */
#define TC_IER_ETRGS (0x1u << 7) /**< \brief (TC_IER) External Trigger */
/* -------- TC_IDR : (TC Offset: N/A) Interrupt Disable Register -------- */
#define TC_IDR_COVFS (0x1u << 0) /**< \brief (TC_IDR) Counter Overflow */
#define TC_IDR_LOVRS (0x1u << 1) /**< \brief (TC_IDR) Load Overrun */
#define TC_IDR_CPAS (0x1u << 2) /**< \brief (TC_IDR) RA Compare */
#define TC_IDR_CPBS (0x1u << 3) /**< \brief (TC_IDR) RB Compare */
#define TC_IDR_CPCS (0x1u << 4) /**< \brief (TC_IDR) RC Compare */
#define TC_IDR_LDRAS (0x1u << 5) /**< \brief (TC_IDR) RA Loading */
#define TC_IDR_LDRBS (0x1u << 6) /**< \brief (TC_IDR) RB Loading */
#define TC_IDR_ETRGS (0x1u << 7) /**< \brief (TC_IDR) External Trigger */
/* -------- TC_IMR : (TC Offset: N/A) Interrupt Mask Register -------- */
#define TC_IMR_COVFS (0x1u << 0) /**< \brief (TC_IMR) Counter Overflow */
#define TC_IMR_LOVRS (0x1u << 1) /**< \brief (TC_IMR) Load Overrun */
#define TC_IMR_CPAS (0x1u << 2) /**< \brief (TC_IMR) RA Compare */
#define TC_IMR_CPBS (0x1u << 3) /**< \brief (TC_IMR) RB Compare */
#define TC_IMR_CPCS (0x1u << 4) /**< \brief (TC_IMR) RC Compare */
#define TC_IMR_LDRAS (0x1u << 5) /**< \brief (TC_IMR) RA Loading */
#define TC_IMR_LDRBS (0x1u << 6) /**< \brief (TC_IMR) RB Loading */
#define TC_IMR_ETRGS (0x1u << 7) /**< \brief (TC_IMR) External Trigger */
/* -------- TC_BCR : (TC Offset: 0xC0) Block Control Register -------- */
#define TC_BCR_SYNC (0x1u << 0) /**< \brief (TC_BCR) Synchro Command */
/* -------- TC_BMR : (TC Offset: 0xC4) Block Mode Register -------- */
#define TC_BMR_TC0XC0S_Pos 0
#define TC_BMR_TC0XC0S_Msk (0x3u << TC_BMR_TC0XC0S_Pos) /**< \brief (TC_BMR) External Clock Signal 0 Selection */
#define   TC_BMR_TC0XC0S_TCLK0 (0x0u << 0) /**< \brief (TC_BMR) Signal connected to XC0: TCLK0 */
#define   TC_BMR_TC0XC0S_TIOA1 (0x2u << 0) /**< \brief (TC_BMR) Signal connected to XC0: TIOA1 */
#define   TC_BMR_TC0XC0S_TIOA2 (0x3u << 0) /**< \brief (TC_BMR) Signal connected to XC0: TIOA2 */
#define TC_BMR_TC1XC1S_Pos 2
#define TC_BMR_TC1XC1S_Msk (0x3u << TC_BMR_TC1XC1S_Pos) /**< \brief (TC_BMR) External Clock Signal 1 Selection */
#define   TC_BMR_TC1XC1S_TCLK1 (0x0u << 2) /**< \brief (TC_BMR) Signal connected to XC1: TCLK1 */
#define   TC_BMR_TC1XC1S_TIOA0 (0x2u << 2) /**< \brief (TC_BMR) Signal connected to XC1: TIOA0 */
#define   TC_BMR_TC1XC1S_TIOA2 (0x3u << 2) /**< \brief (TC_BMR) Signal connected to XC1: TIOA2 */
#define TC_BMR_TC2XC2S_Pos 4
#define TC_BMR_TC2XC2S_Msk (0x3u << TC_BMR_TC2XC2S_Pos) /**< \brief (TC_BMR) External Clock Signal 2 Selection */
#define   TC_BMR_TC2XC2S_TCLK2 (0x0u << 4) /**< \brief (TC_BMR) Signal connected to XC2: TCLK2 */
#define   TC_BMR_TC2XC2S_TIOA1 (0x2u << 4) /**< \brief (TC_BMR) Signal connected to XC2: TIOA1 */
#define   TC_BMR_TC2XC2S_TIOA2 (0x3u << 4) /**< \brief (TC_BMR) Signal connected to XC2: TIOA2 */
#define TC_BMR_QDEN (0x1u << 8) /**< \brief (TC_BMR) Quadrature Decoder ENabled */
#define TC_BMR_POSEN (0x1u << 9) /**< \brief (TC_BMR) POSition ENabled */
#define TC_BMR_SPEEDEN (0x1u << 10) /**< \brief (TC_BMR) SPEED ENabled */
#define TC_BMR_QDTRANS (0x1u << 11) /**< \brief (TC_BMR) Quadrature Decoding TRANSparent */
#define TC_BMR_EDGPHA (0x1u << 12) /**< \brief (TC_BMR) EDGe on PHA count mode */
#define TC_BMR_INVA (0x1u << 13) /**< \brief (TC_BMR) INVerted phA */
#define TC_BMR_INVB (0x1u << 14) /**< \brief (TC_BMR) INVerted phB */
#define TC_BMR_INVIDX (0x1u << 15) /**< \brief (TC_BMR) INVerted InDeX */
#define TC_BMR_SWAP (0x1u << 16) /**< \brief (TC_BMR) SWAP PHA and PHB */
#define TC_BMR_IDXPHB (0x1u << 17) /**< \brief (TC_BMR) InDeX pin is PHB pin */
#define TC_BMR_FILTER (0x1u << 19) /**< \brief (TC_BMR)  */
#define TC_BMR_MAXFILT_Pos 20
#define TC_BMR_MAXFILT_Msk (0x3fu << TC_BMR_MAXFILT_Pos) /**< \brief (TC_BMR) MAXimum FILTer */
#define TC_BMR_MAXFILT(value) ((TC_BMR_MAXFILT_Msk & ((value) << TC_BMR_MAXFILT_Pos)))
/* -------- TC_QIER : (TC Offset: 0xC8) QDEC Interrupt Enable Register -------- */
#define TC_QIER_IDX (0x1u << 0) /**< \brief (TC_QIER) InDeX */
#define TC_QIER_DIRCHG (0x1u << 1) /**< \brief (TC_QIER) DIRection CHanGe */
#define TC_QIER_QERR (0x1u << 2) /**< \brief (TC_QIER) Quadrature ERRor */
/* -------- TC_QIDR : (TC Offset: 0xCC) QDEC Interrupt Disable Register -------- */
#define TC_QIDR_IDX (0x1u << 0) /**< \brief (TC_QIDR) InDeX */
#define TC_QIDR_DIRCHG (0x1u << 1) /**< \brief (TC_QIDR) DIRection CHanGe */
#define TC_QIDR_QERR (0x1u << 2) /**< \brief (TC_QIDR) Quadrature ERRor */
/* -------- TC_QIMR : (TC Offset: 0xD0) QDEC Interrupt Mask Register -------- */
#define TC_QIMR_IDX (0x1u << 0) /**< \brief (TC_QIMR) InDeX */
#define TC_QIMR_DIRCHG (0x1u << 1) /**< \brief (TC_QIMR) DIRection CHanGe */
#define TC_QIMR_QERR (0x1u << 2) /**< \brief (TC_QIMR) Quadrature ERRor */
/* -------- TC_QISR : (TC Offset: 0xD4) QDEC Interrupt Status Register -------- */
#define TC_QISR_IDX (0x1u << 0) /**< \brief (TC_QISR) InDeX */
#define TC_QISR_DIRCHG (0x1u << 1) /**< \brief (TC_QISR) DIRection CHanGe */
#define TC_QISR_QERR (0x1u << 2) /**< \brief (TC_QISR) Quadrature ERRor */
#define TC_QISR_DIR (0x1u << 8) /**< \brief (TC_QISR) Direction */
/* -------- TC_FMR : (TC Offset: 0xD8) Fault Mode Register -------- */
#define TC_FMR_ENCF0 (0x1u << 0) /**< \brief (TC_FMR) ENable Compare Fault Channel 0 */
#define TC_FMR_ENCF1 (0x1u << 1) /**< \brief (TC_FMR) ENable Compare Fault Channel 1 */
/* -------- TC_WPMR : (TC Offset: 0xE4) Write Protect Mode Register -------- */
#define TC_WPMR_WPEN (0x1u << 0) /**< \brief (TC_WPMR) Write Protect Enable */
#define TC_WPMR_WPKEY_Pos 8
#define TC_WPMR_WPKEY_Msk (0xffffffu << TC_WPMR_WPKEY_Pos) /**< \brief (TC_WPMR) Write Protect KEY */
#define TC_WPMR_WPKEY(value) ((TC_WPMR_WPKEY_Msk & ((value) << TC_WPMR_WPKEY_Pos)))

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Two-wire Interface */
/* ============================================================================= */
/** \addtogroup SAM3S16_TWI Two-wire Interface */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Twi hardware registers */
typedef struct {
  WoReg TWI_CR;        /**< \brief (Twi Offset: 0x00) Control Register */
  RwReg TWI_MMR;       /**< \brief (Twi Offset: 0x04) Master Mode Register */
  RwReg TWI_SMR;       /**< \brief (Twi Offset: 0x08) Slave Mode Register */
  RwReg TWI_IADR;      /**< \brief (Twi Offset: 0x0C) Internal Address Register */
  RwReg TWI_CWGR;      /**< \brief (Twi Offset: 0x10) Clock Waveform Generator Register */
  RoReg Reserved1[3];
  RoReg TWI_SR;        /**< \brief (Twi Offset: 0x20) Status Register */
  WoReg TWI_IER;       /**< \brief (Twi Offset: 0x24) Interrupt Enable Register */
  WoReg TWI_IDR;       /**< \brief (Twi Offset: 0x28) Interrupt Disable Register */
  RoReg TWI_IMR;       /**< \brief (Twi Offset: 0x2C) Interrupt Mask Register */
  RoReg TWI_RHR;       /**< \brief (Twi Offset: 0x30) Receive Holding Register */
  WoReg TWI_THR;       /**< \brief (Twi Offset: 0x34) Transmit Holding Register */
  RoReg Reserved2[50];
  RwReg TWI_RPR;       /**< \brief (Twi Offset: 0x100) Receive Pointer Register */
  RwReg TWI_RCR;       /**< \brief (Twi Offset: 0x104) Receive Counter Register */
  RwReg TWI_TPR;       /**< \brief (Twi Offset: 0x108) Transmit Pointer Register */
  RwReg TWI_TCR;       /**< \brief (Twi Offset: 0x10C) Transmit Counter Register */
  RwReg TWI_RNPR;      /**< \brief (Twi Offset: 0x110) Receive Next Pointer Register */
  RwReg TWI_RNCR;      /**< \brief (Twi Offset: 0x114) Receive Next Counter Register */
  RwReg TWI_TNPR;      /**< \brief (Twi Offset: 0x118) Transmit Next Pointer Register */
  RwReg TWI_TNCR;      /**< \brief (Twi Offset: 0x11C) Transmit Next Counter Register */
  WoReg TWI_PTCR;      /**< \brief (Twi Offset: 0x120) Transfer Control Register */
  RoReg TWI_PTSR;      /**< \brief (Twi Offset: 0x124) Transfer Status Register */
} Twi;
#endif /* __ASSEMBLY__ */
/* -------- TWI_CR : (TWI Offset: 0x00) Control Register -------- */
#define TWI_CR_START (0x1u << 0) /**< \brief (TWI_CR) Send a START Condition */
#define TWI_CR_STOP (0x1u << 1) /**< \brief (TWI_CR) Send a STOP Condition */
#define TWI_CR_MSEN (0x1u << 2) /**< \brief (TWI_CR) TWI Master Mode Enabled */
#define TWI_CR_MSDIS (0x1u << 3) /**< \brief (TWI_CR) TWI Master Mode Disabled */
#define TWI_CR_SVEN (0x1u << 4) /**< \brief (TWI_CR) TWI Slave Mode Enabled */
#define TWI_CR_SVDIS (0x1u << 5) /**< \brief (TWI_CR) TWI Slave Mode Disabled */
#define TWI_CR_QUICK (0x1u << 6) /**< \brief (TWI_CR) SMBUS Quick Command */
#define TWI_CR_SWRST (0x1u << 7) /**< \brief (TWI_CR) Software Reset */
/* -------- TWI_MMR : (TWI Offset: 0x04) Master Mode Register -------- */
#define TWI_MMR_IADRSZ_Pos 8
#define TWI_MMR_IADRSZ_Msk (0x3u << TWI_MMR_IADRSZ_Pos) /**< \brief (TWI_MMR) Internal Device Address Size */
#define   TWI_MMR_IADRSZ_NONE (0x0u << 8) /**< \brief (TWI_MMR) No internal device address */
#define   TWI_MMR_IADRSZ_1_BYTE (0x1u << 8) /**< \brief (TWI_MMR) One-byte internal device address */
#define   TWI_MMR_IADRSZ_2_BYTE (0x2u << 8) /**< \brief (TWI_MMR) Two-byte internal device address */
#define   TWI_MMR_IADRSZ_3_BYTE (0x3u << 8) /**< \brief (TWI_MMR) Three-byte internal device address */
#define TWI_MMR_MREAD (0x1u << 12) /**< \brief (TWI_MMR) Master Read Direction */
#define TWI_MMR_DADR_Pos 16
#define TWI_MMR_DADR_Msk (0x7fu << TWI_MMR_DADR_Pos) /**< \brief (TWI_MMR) Device Address */
#define TWI_MMR_DADR(value) ((TWI_MMR_DADR_Msk & ((value) << TWI_MMR_DADR_Pos)))
/* -------- TWI_SMR : (TWI Offset: 0x08) Slave Mode Register -------- */
#define TWI_SMR_SADR_Pos 16
#define TWI_SMR_SADR_Msk (0x7fu << TWI_SMR_SADR_Pos) /**< \brief (TWI_SMR) Slave Address */
#define TWI_SMR_SADR(value) ((TWI_SMR_SADR_Msk & ((value) << TWI_SMR_SADR_Pos)))
/* -------- TWI_IADR : (TWI Offset: 0x0C) Internal Address Register -------- */
#define TWI_IADR_IADR_Pos 0
#define TWI_IADR_IADR_Msk (0xffffffu << TWI_IADR_IADR_Pos) /**< \brief (TWI_IADR) Internal Address */
#define TWI_IADR_IADR(value) ((TWI_IADR_IADR_Msk & ((value) << TWI_IADR_IADR_Pos)))
/* -------- TWI_CWGR : (TWI Offset: 0x10) Clock Waveform Generator Register -------- */
#define TWI_CWGR_CLDIV_Pos 0
#define TWI_CWGR_CLDIV_Msk (0xffu << TWI_CWGR_CLDIV_Pos) /**< \brief (TWI_CWGR) Clock Low Divider */
#define TWI_CWGR_CLDIV(value) ((TWI_CWGR_CLDIV_Msk & ((value) << TWI_CWGR_CLDIV_Pos)))
#define TWI_CWGR_CHDIV_Pos 8
#define TWI_CWGR_CHDIV_Msk (0xffu << TWI_CWGR_CHDIV_Pos) /**< \brief (TWI_CWGR) Clock High Divider */
#define TWI_CWGR_CHDIV(value) ((TWI_CWGR_CHDIV_Msk & ((value) << TWI_CWGR_CHDIV_Pos)))
#define TWI_CWGR_CKDIV_Pos 16
#define TWI_CWGR_CKDIV_Msk (0x7u << TWI_CWGR_CKDIV_Pos) /**< \brief (TWI_CWGR) Clock Divider */
#define TWI_CWGR_CKDIV(value) ((TWI_CWGR_CKDIV_Msk & ((value) << TWI_CWGR_CKDIV_Pos)))
/* -------- TWI_SR : (TWI Offset: 0x20) Status Register -------- */
#define TWI_SR_TXCOMP (0x1u << 0) /**< \brief (TWI_SR) Transmission Completed (automatically set / reset) */
#define TWI_SR_RXRDY (0x1u << 1) /**< \brief (TWI_SR) Receive Holding Register Ready (automatically set / reset) */
#define TWI_SR_TXRDY (0x1u << 2) /**< \brief (TWI_SR) Transmit Holding Register Ready (automatically set / reset) */
#define TWI_SR_SVREAD (0x1u << 3) /**< \brief (TWI_SR) Slave Read (automatically set / reset) */
#define TWI_SR_SVACC (0x1u << 4) /**< \brief (TWI_SR) Slave Access (automatically set / reset) */
#define TWI_SR_GACC (0x1u << 5) /**< \brief (TWI_SR) General Call Access (clear on read) */
#define TWI_SR_OVRE (0x1u << 6) /**< \brief (TWI_SR) Overrun Error (clear on read) */
#define TWI_SR_NACK (0x1u << 8) /**< \brief (TWI_SR) Not Acknowledged (clear on read) */
#define TWI_SR_SCLWS (0x1u << 10) /**< \brief (TWI_SR) Clock Wait State (automatically set / reset) */
#define TWI_SR_EOSACC (0x1u << 11) /**< \brief (TWI_SR) End Of Slave Access (clear on read) */
#define TWI_SR_ENDRX (0x1u << 12) /**< \brief (TWI_SR) End of RX buffer */
#define TWI_SR_ENDTX (0x1u << 13) /**< \brief (TWI_SR) End of TX buffer */
#define TWI_SR_RXBUFF (0x1u << 14) /**< \brief (TWI_SR) RX Buffer Full */
#define TWI_SR_TXBUFE (0x1u << 15) /**< \brief (TWI_SR) TX Buffer Empty */
/* -------- TWI_IER : (TWI Offset: 0x24) Interrupt Enable Register -------- */
#define TWI_IER_TXCOMP (0x1u << 0) /**< \brief (TWI_IER) Transmission Completed Interrupt Enable */
#define TWI_IER_RXRDY (0x1u << 1) /**< \brief (TWI_IER) Receive Holding Register Ready Interrupt Enable */
#define TWI_IER_TXRDY (0x1u << 2) /**< \brief (TWI_IER) Transmit Holding Register Ready Interrupt Enable */
#define TWI_IER_SVACC (0x1u << 4) /**< \brief (TWI_IER) Slave Access Interrupt Enable */
#define TWI_IER_GACC (0x1u << 5) /**< \brief (TWI_IER) General Call Access Interrupt Enable */
#define TWI_IER_OVRE (0x1u << 6) /**< \brief (TWI_IER) Overrun Error Interrupt Enable */
#define TWI_IER_NACK (0x1u << 8) /**< \brief (TWI_IER) Not Acknowledge Interrupt Enable */
#define TWI_IER_ARBLST (0x1u << 9) /**< \brief (TWI_IER) Arbitration Lost Interrupt Enable */
#define TWI_IER_SCL_WS (0x1u << 10) /**< \brief (TWI_IER) Clock Wait State Interrupt Enable */
#define TWI_IER_EOSACC (0x1u << 11) /**< \brief (TWI_IER) End Of Slave Access Interrupt Enable */
#define TWI_IER_ENDRX (0x1u << 12) /**< \brief (TWI_IER) End of Receive Buffer Interrupt Enable */
#define TWI_IER_ENDTX (0x1u << 13) /**< \brief (TWI_IER) End of Transmit Buffer Interrupt Enable */
#define TWI_IER_RXBUFF (0x1u << 14) /**< \brief (TWI_IER) Receive Buffer Full Interrupt Enable */
#define TWI_IER_TXBUFE (0x1u << 15) /**< \brief (TWI_IER) Transmit Buffer Empty Interrupt Enable */
/* -------- TWI_IDR : (TWI Offset: 0x28) Interrupt Disable Register -------- */
#define TWI_IDR_TXCOMP (0x1u << 0) /**< \brief (TWI_IDR) Transmission Completed Interrupt Disable */
#define TWI_IDR_RXRDY (0x1u << 1) /**< \brief (TWI_IDR) Receive Holding Register Ready Interrupt Disable */
#define TWI_IDR_TXRDY (0x1u << 2) /**< \brief (TWI_IDR) Transmit Holding Register Ready Interrupt Disable */
#define TWI_IDR_SVACC (0x1u << 4) /**< \brief (TWI_IDR) Slave Access Interrupt Disable */
#define TWI_IDR_GACC (0x1u << 5) /**< \brief (TWI_IDR) General Call Access Interrupt Disable */
#define TWI_IDR_OVRE (0x1u << 6) /**< \brief (TWI_IDR) Overrun Error Interrupt Disable */
#define TWI_IDR_NACK (0x1u << 8) /**< \brief (TWI_IDR) Not Acknowledge Interrupt Disable */
#define TWI_IDR_ARBLST (0x1u << 9) /**< \brief (TWI_IDR) Arbitration Lost Interrupt Disable */
#define TWI_IDR_SCL_WS (0x1u << 10) /**< \brief (TWI_IDR) Clock Wait State Interrupt Disable */
#define TWI_IDR_EOSACC (0x1u << 11) /**< \brief (TWI_IDR) End Of Slave Access Interrupt Disable */
#define TWI_IDR_ENDRX (0x1u << 12) /**< \brief (TWI_IDR) End of Receive Buffer Interrupt Disable */
#define TWI_IDR_ENDTX (0x1u << 13) /**< \brief (TWI_IDR) End of Transmit Buffer Interrupt Disable */
#define TWI_IDR_RXBUFF (0x1u << 14) /**< \brief (TWI_IDR) Receive Buffer Full Interrupt Disable */
#define TWI_IDR_TXBUFE (0x1u << 15) /**< \brief (TWI_IDR) Transmit Buffer Empty Interrupt Disable */
/* -------- TWI_IMR : (TWI Offset: 0x2C) Interrupt Mask Register -------- */
#define TWI_IMR_TXCOMP (0x1u << 0) /**< \brief (TWI_IMR) Transmission Completed Interrupt Mask */
#define TWI_IMR_RXRDY (0x1u << 1) /**< \brief (TWI_IMR) Receive Holding Register Ready Interrupt Mask */
#define TWI_IMR_TXRDY (0x1u << 2) /**< \brief (TWI_IMR) Transmit Holding Register Ready Interrupt Mask */
#define TWI_IMR_SVACC (0x1u << 4) /**< \brief (TWI_IMR) Slave Access Interrupt Mask */
#define TWI_IMR_GACC (0x1u << 5) /**< \brief (TWI_IMR) General Call Access Interrupt Mask */
#define TWI_IMR_OVRE (0x1u << 6) /**< \brief (TWI_IMR) Overrun Error Interrupt Mask */
#define TWI_IMR_NACK (0x1u << 8) /**< \brief (TWI_IMR) Not Acknowledge Interrupt Mask */
#define TWI_IMR_ARBLST (0x1u << 9) /**< \brief (TWI_IMR) Arbitration Lost Interrupt Mask */
#define TWI_IMR_SCL_WS (0x1u << 10) /**< \brief (TWI_IMR) Clock Wait State Interrupt Mask */
#define TWI_IMR_EOSACC (0x1u << 11) /**< \brief (TWI_IMR) End Of Slave Access Interrupt Mask */
#define TWI_IMR_ENDRX (0x1u << 12) /**< \brief (TWI_IMR) End of Receive Buffer Interrupt Mask */
#define TWI_IMR_ENDTX (0x1u << 13) /**< \brief (TWI_IMR) End of Transmit Buffer Interrupt Mask */
#define TWI_IMR_RXBUFF (0x1u << 14) /**< \brief (TWI_IMR) Receive Buffer Full Interrupt Mask */
#define TWI_IMR_TXBUFE (0x1u << 15) /**< \brief (TWI_IMR) Transmit Buffer Empty Interrupt Mask */
/* -------- TWI_RHR : (TWI Offset: 0x30) Receive Holding Register -------- */
#define TWI_RHR_RXDATA_Pos 0
#define TWI_RHR_RXDATA_Msk (0xffu << TWI_RHR_RXDATA_Pos) /**< \brief (TWI_RHR) Master or Slave Receive Holding Data */
/* -------- TWI_THR : (TWI Offset: 0x34) Transmit Holding Register -------- */
#define TWI_THR_TXDATA_Pos 0
#define TWI_THR_TXDATA_Msk (0xffu << TWI_THR_TXDATA_Pos) /**< \brief (TWI_THR) Master or Slave Transmit Holding Data */
#define TWI_THR_TXDATA(value) ((TWI_THR_TXDATA_Msk & ((value) << TWI_THR_TXDATA_Pos)))
/* -------- TWI_RPR : (TWI Offset: 0x100) Receive Pointer Register -------- */
#define TWI_RPR_RXPTR_Pos 0
#define TWI_RPR_RXPTR_Msk (0xffffffffu << TWI_RPR_RXPTR_Pos) /**< \brief (TWI_RPR) Receive Pointer Register */
#define TWI_RPR_RXPTR(value) ((TWI_RPR_RXPTR_Msk & ((value) << TWI_RPR_RXPTR_Pos)))
/* -------- TWI_RCR : (TWI Offset: 0x104) Receive Counter Register -------- */
#define TWI_RCR_RXCTR_Pos 0
#define TWI_RCR_RXCTR_Msk (0xffffu << TWI_RCR_RXCTR_Pos) /**< \brief (TWI_RCR) Receive Counter Register */
#define TWI_RCR_RXCTR(value) ((TWI_RCR_RXCTR_Msk & ((value) << TWI_RCR_RXCTR_Pos)))
/* -------- TWI_TPR : (TWI Offset: 0x108) Transmit Pointer Register -------- */
#define TWI_TPR_TXPTR_Pos 0
#define TWI_TPR_TXPTR_Msk (0xffffffffu << TWI_TPR_TXPTR_Pos) /**< \brief (TWI_TPR) Transmit Counter Register */
#define TWI_TPR_TXPTR(value) ((TWI_TPR_TXPTR_Msk & ((value) << TWI_TPR_TXPTR_Pos)))
/* -------- TWI_TCR : (TWI Offset: 0x10C) Transmit Counter Register -------- */
#define TWI_TCR_TXCTR_Pos 0
#define TWI_TCR_TXCTR_Msk (0xffffu << TWI_TCR_TXCTR_Pos) /**< \brief (TWI_TCR) Transmit Counter Register */
#define TWI_TCR_TXCTR(value) ((TWI_TCR_TXCTR_Msk & ((value) << TWI_TCR_TXCTR_Pos)))
/* -------- TWI_RNPR : (TWI Offset: 0x110) Receive Next Pointer Register -------- */
#define TWI_RNPR_RXNPTR_Pos 0
#define TWI_RNPR_RXNPTR_Msk (0xffffffffu << TWI_RNPR_RXNPTR_Pos) /**< \brief (TWI_RNPR) Receive Next Pointer */
#define TWI_RNPR_RXNPTR(value) ((TWI_RNPR_RXNPTR_Msk & ((value) << TWI_RNPR_RXNPTR_Pos)))
/* -------- TWI_RNCR : (TWI Offset: 0x114) Receive Next Counter Register -------- */
#define TWI_RNCR_RXNCTR_Pos 0
#define TWI_RNCR_RXNCTR_Msk (0xffffu << TWI_RNCR_RXNCTR_Pos) /**< \brief (TWI_RNCR) Receive Next Counter */
#define TWI_RNCR_RXNCTR(value) ((TWI_RNCR_RXNCTR_Msk & ((value) << TWI_RNCR_RXNCTR_Pos)))
/* -------- TWI_TNPR : (TWI Offset: 0x118) Transmit Next Pointer Register -------- */
#define TWI_TNPR_TXNPTR_Pos 0
#define TWI_TNPR_TXNPTR_Msk (0xffffffffu << TWI_TNPR_TXNPTR_Pos) /**< \brief (TWI_TNPR) Transmit Next Pointer */
#define TWI_TNPR_TXNPTR(value) ((TWI_TNPR_TXNPTR_Msk & ((value) << TWI_TNPR_TXNPTR_Pos)))
/* -------- TWI_TNCR : (TWI Offset: 0x11C) Transmit Next Counter Register -------- */
#define TWI_TNCR_TXNCTR_Pos 0
#define TWI_TNCR_TXNCTR_Msk (0xffffu << TWI_TNCR_TXNCTR_Pos) /**< \brief (TWI_TNCR) Transmit Counter Next */
#define TWI_TNCR_TXNCTR(value) ((TWI_TNCR_TXNCTR_Msk & ((value) << TWI_TNCR_TXNCTR_Pos)))
/* -------- TWI_PTCR : (TWI Offset: 0x120) Transfer Control Register -------- */
#define TWI_PTCR_RXTEN (0x1u << 0) /**< \brief (TWI_PTCR) Receiver Transfer Enable */
#define TWI_PTCR_RXTDIS (0x1u << 1) /**< \brief (TWI_PTCR) Receiver Transfer Disable */
#define TWI_PTCR_TXTEN (0x1u << 8) /**< \brief (TWI_PTCR) Transmitter Transfer Enable */
#define TWI_PTCR_TXTDIS (0x1u << 9) /**< \brief (TWI_PTCR) Transmitter Transfer Disable */
/* -------- TWI_PTSR : (TWI Offset: 0x124) Transfer Status Register -------- */
#define TWI_PTSR_RXTEN (0x1u << 0) /**< \brief (TWI_PTSR) Receiver Transfer Enable */
#define TWI_PTSR_TXTEN (0x1u << 8) /**< \brief (TWI_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Universal Asynchronous Receiver Transmitter */
/* ============================================================================= */
/** \addtogroup SAM3S16_UART Universal Asynchronous Receiver Transmitter */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Uart hardware registers */
typedef struct {
  WoReg UART_CR;       /**< \brief (Uart Offset: 0x0000) Control Register */
  RwReg UART_MR;       /**< \brief (Uart Offset: 0x0004) Mode Register */
  WoReg UART_IER;      /**< \brief (Uart Offset: 0x0008) Interrupt Enable Register */
  WoReg UART_IDR;      /**< \brief (Uart Offset: 0x000C) Interrupt Disable Register */
  RoReg UART_IMR;      /**< \brief (Uart Offset: 0x0010) Interrupt Mask Register */
  RoReg UART_SR;       /**< \brief (Uart Offset: 0x0014) Status Register */
  RoReg UART_RHR;      /**< \brief (Uart Offset: 0x0018) Receive Holding Register */
  WoReg UART_THR;      /**< \brief (Uart Offset: 0x001C) Transmit Holding Register */
  RwReg UART_BRGR;     /**< \brief (Uart Offset: 0x0020) Baud Rate Generator Register */
  RoReg Reserved1[55];
  RwReg UART_RPR;      /**< \brief (Uart Offset: 0x100) Receive Pointer Register */
  RwReg UART_RCR;      /**< \brief (Uart Offset: 0x104) Receive Counter Register */
  RwReg UART_TPR;      /**< \brief (Uart Offset: 0x108) Transmit Pointer Register */
  RwReg UART_TCR;      /**< \brief (Uart Offset: 0x10C) Transmit Counter Register */
  RwReg UART_RNPR;     /**< \brief (Uart Offset: 0x110) Receive Next Pointer Register */
  RwReg UART_RNCR;     /**< \brief (Uart Offset: 0x114) Receive Next Counter Register */
  RwReg UART_TNPR;     /**< \brief (Uart Offset: 0x118) Transmit Next Pointer Register */
  RwReg UART_TNCR;     /**< \brief (Uart Offset: 0x11C) Transmit Next Counter Register */
  WoReg UART_PTCR;     /**< \brief (Uart Offset: 0x120) Transfer Control Register */
  RoReg UART_PTSR;     /**< \brief (Uart Offset: 0x124) Transfer Status Register */
} Uart;
#endif /* __ASSEMBLY__ */
/* -------- UART_CR : (UART Offset: 0x0000) Control Register -------- */
#define UART_CR_RSTRX (0x1u << 2) /**< \brief (UART_CR) Reset Receiver */
#define UART_CR_RSTTX (0x1u << 3) /**< \brief (UART_CR) Reset Transmitter */
#define UART_CR_RXEN (0x1u << 4) /**< \brief (UART_CR) Receiver Enable */
#define UART_CR_RXDIS (0x1u << 5) /**< \brief (UART_CR) Receiver Disable */
#define UART_CR_TXEN (0x1u << 6) /**< \brief (UART_CR) Transmitter Enable */
#define UART_CR_TXDIS (0x1u << 7) /**< \brief (UART_CR) Transmitter Disable */
#define UART_CR_RSTSTA (0x1u << 8) /**< \brief (UART_CR) Reset Status Bits */
/* -------- UART_MR : (UART Offset: 0x0004) Mode Register -------- */
#define UART_MR_PAR_Pos 9
#define UART_MR_PAR_Msk (0x7u << UART_MR_PAR_Pos) /**< \brief (UART_MR) Parity Type */
#define   UART_MR_PAR_EVEN (0x0u << 9) /**< \brief (UART_MR) Even parity */
#define   UART_MR_PAR_ODD (0x1u << 9) /**< \brief (UART_MR) Odd parity */
#define   UART_MR_PAR_SPACE (0x2u << 9) /**< \brief (UART_MR) Space: parity forced to 0 */
#define   UART_MR_PAR_MARK (0x3u << 9) /**< \brief (UART_MR) Mark: parity forced to 1 */
#define   UART_MR_PAR_NO (0x4u << 9) /**< \brief (UART_MR) No parity */
#define UART_MR_CHMODE_Pos 14
#define UART_MR_CHMODE_Msk (0x3u << UART_MR_CHMODE_Pos) /**< \brief (UART_MR) Channel Mode */
#define   UART_MR_CHMODE_NORMAL (0x0u << 14) /**< \brief (UART_MR) Normal Mode */
#define   UART_MR_CHMODE_AUTOMATIC (0x1u << 14) /**< \brief (UART_MR) Automatic Echo */
#define   UART_MR_CHMODE_LOCAL_LOOPBACK (0x2u << 14) /**< \brief (UART_MR) Local Loopback */
#define   UART_MR_CHMODE_REMOTE_LOOPBACK (0x3u << 14) /**< \brief (UART_MR) Remote Loopback */
/* -------- UART_IER : (UART Offset: 0x0008) Interrupt Enable Register -------- */
#define UART_IER_RXRDY (0x1u << 0) /**< \brief (UART_IER) Enable RXRDY Interrupt */
#define UART_IER_TXRDY (0x1u << 1) /**< \brief (UART_IER) Enable TXRDY Interrupt */
#define UART_IER_ENDRX (0x1u << 3) /**< \brief (UART_IER) Enable End of Receive Transfer Interrupt */
#define UART_IER_ENDTX (0x1u << 4) /**< \brief (UART_IER) Enable End of Transmit Interrupt */
#define UART_IER_OVRE (0x1u << 5) /**< \brief (UART_IER) Enable Overrun Error Interrupt */
#define UART_IER_FRAME (0x1u << 6) /**< \brief (UART_IER) Enable Framing Error Interrupt */
#define UART_IER_PARE (0x1u << 7) /**< \brief (UART_IER) Enable Parity Error Interrupt */
#define UART_IER_TXEMPTY (0x1u << 9) /**< \brief (UART_IER) Enable TXEMPTY Interrupt */
#define UART_IER_TXBUFE (0x1u << 11) /**< \brief (UART_IER) Enable Buffer Empty Interrupt */
#define UART_IER_RXBUFF (0x1u << 12) /**< \brief (UART_IER) Enable Buffer Full Interrupt */
/* -------- UART_IDR : (UART Offset: 0x000C) Interrupt Disable Register -------- */
#define UART_IDR_RXRDY (0x1u << 0) /**< \brief (UART_IDR) Disable RXRDY Interrupt */
#define UART_IDR_TXRDY (0x1u << 1) /**< \brief (UART_IDR) Disable TXRDY Interrupt */
#define UART_IDR_ENDRX (0x1u << 3) /**< \brief (UART_IDR) Disable End of Receive Transfer Interrupt */
#define UART_IDR_ENDTX (0x1u << 4) /**< \brief (UART_IDR) Disable End of Transmit Interrupt */
#define UART_IDR_OVRE (0x1u << 5) /**< \brief (UART_IDR) Disable Overrun Error Interrupt */
#define UART_IDR_FRAME (0x1u << 6) /**< \brief (UART_IDR) Disable Framing Error Interrupt */
#define UART_IDR_PARE (0x1u << 7) /**< \brief (UART_IDR) Disable Parity Error Interrupt */
#define UART_IDR_TXEMPTY (0x1u << 9) /**< \brief (UART_IDR) Disable TXEMPTY Interrupt */
#define UART_IDR_TXBUFE (0x1u << 11) /**< \brief (UART_IDR) Disable Buffer Empty Interrupt */
#define UART_IDR_RXBUFF (0x1u << 12) /**< \brief (UART_IDR) Disable Buffer Full Interrupt */
/* -------- UART_IMR : (UART Offset: 0x0010) Interrupt Mask Register -------- */
#define UART_IMR_RXRDY (0x1u << 0) /**< \brief (UART_IMR) Mask RXRDY Interrupt */
#define UART_IMR_TXRDY (0x1u << 1) /**< \brief (UART_IMR) Disable TXRDY Interrupt */
#define UART_IMR_ENDRX (0x1u << 3) /**< \brief (UART_IMR) Mask End of Receive Transfer Interrupt */
#define UART_IMR_ENDTX (0x1u << 4) /**< \brief (UART_IMR) Mask End of Transmit Interrupt */
#define UART_IMR_OVRE (0x1u << 5) /**< \brief (UART_IMR) Mask Overrun Error Interrupt */
#define UART_IMR_FRAME (0x1u << 6) /**< \brief (UART_IMR) Mask Framing Error Interrupt */
#define UART_IMR_PARE (0x1u << 7) /**< \brief (UART_IMR) Mask Parity Error Interrupt */
#define UART_IMR_TXEMPTY (0x1u << 9) /**< \brief (UART_IMR) Mask TXEMPTY Interrupt */
#define UART_IMR_TXBUFE (0x1u << 11) /**< \brief (UART_IMR) Mask TXBUFE Interrupt */
#define UART_IMR_RXBUFF (0x1u << 12) /**< \brief (UART_IMR) Mask RXBUFF Interrupt */
/* -------- UART_SR : (UART Offset: 0x0014) Status Register -------- */
#define UART_SR_RXRDY (0x1u << 0) /**< \brief (UART_SR) Receiver Ready */
#define UART_SR_TXRDY (0x1u << 1) /**< \brief (UART_SR) Transmitter Ready */
#define UART_SR_ENDRX (0x1u << 3) /**< \brief (UART_SR) End of Receiver Transfer */
#define UART_SR_ENDTX (0x1u << 4) /**< \brief (UART_SR) End of Transmitter Transfer */
#define UART_SR_OVRE (0x1u << 5) /**< \brief (UART_SR) Overrun Error */
#define UART_SR_FRAME (0x1u << 6) /**< \brief (UART_SR) Framing Error */
#define UART_SR_PARE (0x1u << 7) /**< \brief (UART_SR) Parity Error */
#define UART_SR_TXEMPTY (0x1u << 9) /**< \brief (UART_SR) Transmitter Empty */
#define UART_SR_TXBUFE (0x1u << 11) /**< \brief (UART_SR) Transmission Buffer Empty */
#define UART_SR_RXBUFF (0x1u << 12) /**< \brief (UART_SR) Receive Buffer Full */
/* -------- UART_RHR : (UART Offset: 0x0018) Receive Holding Register -------- */
#define UART_RHR_RXCHR_Pos 0
#define UART_RHR_RXCHR_Msk (0xffu << UART_RHR_RXCHR_Pos) /**< \brief (UART_RHR) Received Character */
/* -------- UART_THR : (UART Offset: 0x001C) Transmit Holding Register -------- */
#define UART_THR_TXCHR_Pos 0
#define UART_THR_TXCHR_Msk (0xffu << UART_THR_TXCHR_Pos) /**< \brief (UART_THR) Character to be Transmitted */
#define UART_THR_TXCHR(value) ((UART_THR_TXCHR_Msk & ((value) << UART_THR_TXCHR_Pos)))
/* -------- UART_BRGR : (UART Offset: 0x0020) Baud Rate Generator Register -------- */
#define UART_BRGR_CD_Pos 0
#define UART_BRGR_CD_Msk (0xffffu << UART_BRGR_CD_Pos) /**< \brief (UART_BRGR) Clock Divisor */
#define UART_BRGR_CD(value) ((UART_BRGR_CD_Msk & ((value) << UART_BRGR_CD_Pos)))
/* -------- UART_RPR : (UART Offset: 0x100) Receive Pointer Register -------- */
#define UART_RPR_RXPTR_Pos 0
#define UART_RPR_RXPTR_Msk (0xffffffffu << UART_RPR_RXPTR_Pos) /**< \brief (UART_RPR) Receive Pointer Register */
#define UART_RPR_RXPTR(value) ((UART_RPR_RXPTR_Msk & ((value) << UART_RPR_RXPTR_Pos)))
/* -------- UART_RCR : (UART Offset: 0x104) Receive Counter Register -------- */
#define UART_RCR_RXCTR_Pos 0
#define UART_RCR_RXCTR_Msk (0xffffu << UART_RCR_RXCTR_Pos) /**< \brief (UART_RCR) Receive Counter Register */
#define UART_RCR_RXCTR(value) ((UART_RCR_RXCTR_Msk & ((value) << UART_RCR_RXCTR_Pos)))
/* -------- UART_TPR : (UART Offset: 0x108) Transmit Pointer Register -------- */
#define UART_TPR_TXPTR_Pos 0
#define UART_TPR_TXPTR_Msk (0xffffffffu << UART_TPR_TXPTR_Pos) /**< \brief (UART_TPR) Transmit Counter Register */
#define UART_TPR_TXPTR(value) ((UART_TPR_TXPTR_Msk & ((value) << UART_TPR_TXPTR_Pos)))
/* -------- UART_TCR : (UART Offset: 0x10C) Transmit Counter Register -------- */
#define UART_TCR_TXCTR_Pos 0
#define UART_TCR_TXCTR_Msk (0xffffu << UART_TCR_TXCTR_Pos) /**< \brief (UART_TCR) Transmit Counter Register */
#define UART_TCR_TXCTR(value) ((UART_TCR_TXCTR_Msk & ((value) << UART_TCR_TXCTR_Pos)))
/* -------- UART_RNPR : (UART Offset: 0x110) Receive Next Pointer Register -------- */
#define UART_RNPR_RXNPTR_Pos 0
#define UART_RNPR_RXNPTR_Msk (0xffffffffu << UART_RNPR_RXNPTR_Pos) /**< \brief (UART_RNPR) Receive Next Pointer */
#define UART_RNPR_RXNPTR(value) ((UART_RNPR_RXNPTR_Msk & ((value) << UART_RNPR_RXNPTR_Pos)))
/* -------- UART_RNCR : (UART Offset: 0x114) Receive Next Counter Register -------- */
#define UART_RNCR_RXNCTR_Pos 0
#define UART_RNCR_RXNCTR_Msk (0xffffu << UART_RNCR_RXNCTR_Pos) /**< \brief (UART_RNCR) Receive Next Counter */
#define UART_RNCR_RXNCTR(value) ((UART_RNCR_RXNCTR_Msk & ((value) << UART_RNCR_RXNCTR_Pos)))
/* -------- UART_TNPR : (UART Offset: 0x118) Transmit Next Pointer Register -------- */
#define UART_TNPR_TXNPTR_Pos 0
#define UART_TNPR_TXNPTR_Msk (0xffffffffu << UART_TNPR_TXNPTR_Pos) /**< \brief (UART_TNPR) Transmit Next Pointer */
#define UART_TNPR_TXNPTR(value) ((UART_TNPR_TXNPTR_Msk & ((value) << UART_TNPR_TXNPTR_Pos)))
/* -------- UART_TNCR : (UART Offset: 0x11C) Transmit Next Counter Register -------- */
#define UART_TNCR_TXNCTR_Pos 0
#define UART_TNCR_TXNCTR_Msk (0xffffu << UART_TNCR_TXNCTR_Pos) /**< \brief (UART_TNCR) Transmit Counter Next */
#define UART_TNCR_TXNCTR(value) ((UART_TNCR_TXNCTR_Msk & ((value) << UART_TNCR_TXNCTR_Pos)))
/* -------- UART_PTCR : (UART Offset: 0x120) Transfer Control Register -------- */
#define UART_PTCR_RXTEN (0x1u << 0) /**< \brief (UART_PTCR) Receiver Transfer Enable */
#define UART_PTCR_RXTDIS (0x1u << 1) /**< \brief (UART_PTCR) Receiver Transfer Disable */
#define UART_PTCR_TXTEN (0x1u << 8) /**< \brief (UART_PTCR) Transmitter Transfer Enable */
#define UART_PTCR_TXTDIS (0x1u << 9) /**< \brief (UART_PTCR) Transmitter Transfer Disable */
/* -------- UART_PTSR : (UART Offset: 0x124) Transfer Status Register -------- */
#define UART_PTSR_RXTEN (0x1u << 0) /**< \brief (UART_PTSR) Receiver Transfer Enable */
#define UART_PTSR_TXTEN (0x1u << 8) /**< \brief (UART_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR USB Device Port */
/* ============================================================================= */
/** \addtogroup SAM3S16_UDP USB Device Port */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Udp hardware registers */
typedef struct {
  RoReg UDP_FRM_NUM;  /**< \brief (Udp Offset: 0x000) Frame Number Register */
  RwReg UDP_GLB_STAT; /**< \brief (Udp Offset: 0x004) Global State Register */
  RwReg UDP_FADDR;    /**< \brief (Udp Offset: 0x008) Function Address Register */
  RoReg Reserved1[1];
  WoReg UDP_IER;      /**< \brief (Udp Offset: 0x010) Interrupt Enable Register */
  WoReg UDP_IDR;      /**< \brief (Udp Offset: 0x014) Interrupt Disable Register */
  RoReg UDP_IMR;      /**< \brief (Udp Offset: 0x018) Interrupt Mask Register */
  RoReg UDP_ISR;      /**< \brief (Udp Offset: 0x01C) Interrupt Status Register */
  WoReg UDP_ICR;      /**< \brief (Udp Offset: 0x020) Interrupt Clear Register */
  RoReg Reserved2[1];
  RwReg UDP_RST_EP;   /**< \brief (Udp Offset: 0x028) Reset Endpoint Register */
  RoReg Reserved3[1];
  RwReg UDP_CSR[8];   /**< \brief (Udp Offset: 0x030) Endpoint Control and Status Register */
  RwReg UDP_FDR[8];   /**< \brief (Udp Offset: 0x050) Endpoint FIFO Data Register */
  RoReg Reserved4[1];
  RwReg UDP_TXVC;     /**< \brief (Udp Offset: 0x074) Transceiver Control Register */
} Udp;
#endif /* __ASSEMBLY__ */
/* -------- UDP_FRM_NUM : (UDP Offset: 0x000) Frame Number Register -------- */
#define UDP_FRM_NUM_FRM_NUM_Pos 0
#define UDP_FRM_NUM_FRM_NUM_Msk (0x7ffu << UDP_FRM_NUM_FRM_NUM_Pos) /**< \brief (UDP_FRM_NUM) Frame Number as Defined in the Packet Field Formats */
#define UDP_FRM_NUM_FRM_ERR (0x1u << 16) /**< \brief (UDP_FRM_NUM) Frame Error */
#define UDP_FRM_NUM_FRM_OK (0x1u << 17) /**< \brief (UDP_FRM_NUM) Frame OK */
/* -------- UDP_GLB_STAT : (UDP Offset: 0x004) Global State Register -------- */
#define UDP_GLB_STAT_FADDEN (0x1u << 0) /**< \brief (UDP_GLB_STAT) Function Address Enable */
#define UDP_GLB_STAT_CONFG (0x1u << 1) /**< \brief (UDP_GLB_STAT) Configured */
#define UDP_GLB_STAT_ESR (0x1u << 2) /**< \brief (UDP_GLB_STAT) Enable Send Resume */
#define UDP_GLB_STAT_RSMINPR (0x1u << 3) /**< \brief (UDP_GLB_STAT)  */
#define UDP_GLB_STAT_RMWUPE (0x1u << 4) /**< \brief (UDP_GLB_STAT) Remote Wake Up Enable */
/* -------- UDP_FADDR : (UDP Offset: 0x008) Function Address Register -------- */
#define UDP_FADDR_FADD_Pos 0
#define UDP_FADDR_FADD_Msk (0x7fu << UDP_FADDR_FADD_Pos) /**< \brief (UDP_FADDR) Function Address Value */
#define UDP_FADDR_FADD(value) ((UDP_FADDR_FADD_Msk & ((value) << UDP_FADDR_FADD_Pos)))
#define UDP_FADDR_FEN (0x1u << 8) /**< \brief (UDP_FADDR) Function Enable */
/* -------- UDP_IER : (UDP Offset: 0x010) Interrupt Enable Register -------- */
#define UDP_IER_EP0INT (0x1u << 0) /**< \brief (UDP_IER) Enable Endpoint 0 Interrupt */
#define UDP_IER_EP1INT (0x1u << 1) /**< \brief (UDP_IER) Enable Endpoint 1 Interrupt */
#define UDP_IER_EP2INT (0x1u << 2) /**< \brief (UDP_IER) Enable Endpoint 2Interrupt */
#define UDP_IER_EP3INT (0x1u << 3) /**< \brief (UDP_IER) Enable Endpoint 3 Interrupt */
#define UDP_IER_EP4INT (0x1u << 4) /**< \brief (UDP_IER) Enable Endpoint 4 Interrupt */
#define UDP_IER_EP5INT (0x1u << 5) /**< \brief (UDP_IER) Enable Endpoint 5 Interrupt */
#define UDP_IER_EP6INT (0x1u << 6) /**< \brief (UDP_IER) Enable Endpoint 6 Interrupt */
#define UDP_IER_EP7INT (0x1u << 7) /**< \brief (UDP_IER) Enable Endpoint 7 Interrupt */
#define UDP_IER_RXSUSP (0x1u << 8) /**< \brief (UDP_IER) Enable UDP Suspend Interrupt */
#define UDP_IER_RXRSM (0x1u << 9) /**< \brief (UDP_IER) Enable UDP Resume Interrupt */
#define UDP_IER_EXTRSM (0x1u << 10) /**< \brief (UDP_IER)  */
#define UDP_IER_SOFINT (0x1u << 11) /**< \brief (UDP_IER) Enable Start Of Frame Interrupt */
#define UDP_IER_WAKEUP (0x1u << 13) /**< \brief (UDP_IER) Enable UDP bus Wakeup Interrupt */
/* -------- UDP_IDR : (UDP Offset: 0x014) Interrupt Disable Register -------- */
#define UDP_IDR_EP0INT (0x1u << 0) /**< \brief (UDP_IDR) Disable Endpoint 0 Interrupt */
#define UDP_IDR_EP1INT (0x1u << 1) /**< \brief (UDP_IDR) Disable Endpoint 1 Interrupt */
#define UDP_IDR_EP2INT (0x1u << 2) /**< \brief (UDP_IDR) Disable Endpoint 2 Interrupt */
#define UDP_IDR_EP3INT (0x1u << 3) /**< \brief (UDP_IDR) Disable Endpoint 3 Interrupt */
#define UDP_IDR_EP4INT (0x1u << 4) /**< \brief (UDP_IDR) Disable Endpoint 4 Interrupt */
#define UDP_IDR_EP5INT (0x1u << 5) /**< \brief (UDP_IDR) Disable Endpoint 5 Interrupt */
#define UDP_IDR_EP6INT (0x1u << 6) /**< \brief (UDP_IDR) Disable Endpoint 6 Interrupt */
#define UDP_IDR_EP7INT (0x1u << 7) /**< \brief (UDP_IDR) Disable Endpoint 7 Interrupt */
#define UDP_IDR_RXSUSP (0x1u << 8) /**< \brief (UDP_IDR) Disable UDP Suspend Interrupt */
#define UDP_IDR_RXRSM (0x1u << 9) /**< \brief (UDP_IDR) Disable UDP Resume Interrupt */
#define UDP_IDR_EXTRSM (0x1u << 10) /**< \brief (UDP_IDR)  */
#define UDP_IDR_SOFINT (0x1u << 11) /**< \brief (UDP_IDR) Disable Start Of Frame Interrupt */
#define UDP_IDR_WAKEUP (0x1u << 13) /**< \brief (UDP_IDR) Disable USB Bus Interrupt */
/* -------- UDP_IMR : (UDP Offset: 0x018) Interrupt Mask Register -------- */
#define UDP_IMR_EP0INT (0x1u << 0) /**< \brief (UDP_IMR) Mask Endpoint 0 Interrupt */
#define UDP_IMR_EP1INT (0x1u << 1) /**< \brief (UDP_IMR) Mask Endpoint 1 Interrupt */
#define UDP_IMR_EP2INT (0x1u << 2) /**< \brief (UDP_IMR) Mask Endpoint 2 Interrupt */
#define UDP_IMR_EP3INT (0x1u << 3) /**< \brief (UDP_IMR) Mask Endpoint 3 Interrupt */
#define UDP_IMR_EP4INT (0x1u << 4) /**< \brief (UDP_IMR) Mask Endpoint 4 Interrupt */
#define UDP_IMR_EP5INT (0x1u << 5) /**< \brief (UDP_IMR) Mask Endpoint 5 Interrupt */
#define UDP_IMR_EP6INT (0x1u << 6) /**< \brief (UDP_IMR) Mask Endpoint 6 Interrupt */
#define UDP_IMR_EP7INT (0x1u << 7) /**< \brief (UDP_IMR) Mask Endpoint 7 Interrupt */
#define UDP_IMR_RXSUSP (0x1u << 8) /**< \brief (UDP_IMR) Mask UDP Suspend Interrupt */
#define UDP_IMR_RXRSM (0x1u << 9) /**< \brief (UDP_IMR) Mask UDP Resume Interrupt. */
#define UDP_IMR_EXTRSM (0x1u << 10) /**< \brief (UDP_IMR)  */
#define UDP_IMR_SOFINT (0x1u << 11) /**< \brief (UDP_IMR) Mask Start Of Frame Interrupt */
#define UDP_IMR_BIT12 (0x1u << 12) /**< \brief (UDP_IMR) UDP_IMR Bit 12 */
#define UDP_IMR_WAKEUP (0x1u << 13) /**< \brief (UDP_IMR) USB Bus WAKEUP Interrupt */
/* -------- UDP_ISR : (UDP Offset: 0x01C) Interrupt Status Register -------- */
#define UDP_ISR_EP0INT (0x1u << 0) /**< \brief (UDP_ISR) Endpoint 0 Interrupt Status */
#define UDP_ISR_EP1INT (0x1u << 1) /**< \brief (UDP_ISR) Endpoint 1 Interrupt Status */
#define UDP_ISR_EP2INT (0x1u << 2) /**< \brief (UDP_ISR) Endpoint 2 Interrupt Status */
#define UDP_ISR_EP3INT (0x1u << 3) /**< \brief (UDP_ISR) Endpoint 3 Interrupt Status */
#define UDP_ISR_EP4INT (0x1u << 4) /**< \brief (UDP_ISR) Endpoint 4 Interrupt Status */
#define UDP_ISR_EP5INT (0x1u << 5) /**< \brief (UDP_ISR) Endpoint 5 Interrupt Status */
#define UDP_ISR_EP6INT (0x1u << 6) /**< \brief (UDP_ISR) Endpoint 6 Interrupt Status */
#define UDP_ISR_EP7INT (0x1u << 7) /**< \brief (UDP_ISR) Endpoint 7Interrupt Status */
#define UDP_ISR_RXSUSP (0x1u << 8) /**< \brief (UDP_ISR) UDP Suspend Interrupt Status */
#define UDP_ISR_RXRSM (0x1u << 9) /**< \brief (UDP_ISR) UDP Resume Interrupt Status */
#define UDP_ISR_EXTRSM (0x1u << 10) /**< \brief (UDP_ISR)  */
#define UDP_ISR_SOFINT (0x1u << 11) /**< \brief (UDP_ISR) Start of Frame Interrupt Status */
#define UDP_ISR_ENDBUSRES (0x1u << 12) /**< \brief (UDP_ISR) End of BUS Reset Interrupt Status */
#define UDP_ISR_WAKEUP (0x1u << 13) /**< \brief (UDP_ISR) UDP Resume Interrupt Status */
/* -------- UDP_ICR : (UDP Offset: 0x020) Interrupt Clear Register -------- */
#define UDP_ICR_RXSUSP (0x1u << 8) /**< \brief (UDP_ICR) Clear UDP Suspend Interrupt */
#define UDP_ICR_RXRSM (0x1u << 9) /**< \brief (UDP_ICR) Clear UDP Resume Interrupt */
#define UDP_ICR_EXTRSM (0x1u << 10) /**< \brief (UDP_ICR)  */
#define UDP_ICR_SOFINT (0x1u << 11) /**< \brief (UDP_ICR) Clear Start Of Frame Interrupt */
#define UDP_ICR_ENDBUSRES (0x1u << 12) /**< \brief (UDP_ICR) Clear End of Bus Reset Interrupt */
#define UDP_ICR_WAKEUP (0x1u << 13) /**< \brief (UDP_ICR) Clear Wakeup Interrupt */
/* -------- UDP_RST_EP : (UDP Offset: 0x028) Reset Endpoint Register -------- */
#define UDP_RST_EP_EP0 (0x1u << 0) /**< \brief (UDP_RST_EP) Reset Endpoint 0 */
#define UDP_RST_EP_EP1 (0x1u << 1) /**< \brief (UDP_RST_EP) Reset Endpoint 1 */
#define UDP_RST_EP_EP2 (0x1u << 2) /**< \brief (UDP_RST_EP) Reset Endpoint 2 */
#define UDP_RST_EP_EP3 (0x1u << 3) /**< \brief (UDP_RST_EP) Reset Endpoint 3 */
#define UDP_RST_EP_EP4 (0x1u << 4) /**< \brief (UDP_RST_EP) Reset Endpoint 4 */
#define UDP_RST_EP_EP5 (0x1u << 5) /**< \brief (UDP_RST_EP) Reset Endpoint 5 */
#define UDP_RST_EP_EP6 (0x1u << 6) /**< \brief (UDP_RST_EP) Reset Endpoint 6 */
#define UDP_RST_EP_EP7 (0x1u << 7) /**< \brief (UDP_RST_EP) Reset Endpoint 7 */
/* -------- UDP_CSR[8] : (UDP Offset: 0x030) Endpoint Control and Status Register -------- */
#define UDP_CSR_TXCOMP (0x1u << 0) /**< \brief (UDP_CSR[8]) Generates an IN Packet with Data Previously Written in the DPR */
#define UDP_CSR_RX_DATA_BK0 (0x1u << 1) /**< \brief (UDP_CSR[8]) Receive Data Bank 0 */
#define UDP_CSR_RXSETUP (0x1u << 2) /**< \brief (UDP_CSR[8]) Received Setup */
#define UDP_CSR_STALLSENT (0x1u << 3) /**< \brief (UDP_CSR[8]) Stall Sent (Control, Bulk Interrupt Endpoints)/ISOERROR (Isochronous Endpoints) */
#define UDP_CSR_ISOERROR (0x1u << 3) /**< \brief (UDP_CSR[8]) Stall Sent (Control, Bulk Interrupt Endpoints)/ISOERROR (Isochronous Endpoints) */
#define UDP_CSR_TXPKTRDY (0x1u << 4) /**< \brief (UDP_CSR[8]) Transmit Packet Ready */
#define UDP_CSR_FORCESTALL (0x1u << 5) /**< \brief (UDP_CSR[8]) Force Stall (used by Control, Bulk and Isochronous Endpoints) */
#define UDP_CSR_RX_DATA_BK1 (0x1u << 6) /**< \brief (UDP_CSR[8]) Receive Data Bank 1 (only used by endpoints with ping-pong attributes) */
#define UDP_CSR_DIR (0x1u << 7) /**< \brief (UDP_CSR[8]) Transfer Direction (only available for control endpoints) */
#define UDP_CSR_EPTYPE_Pos 8
#define UDP_CSR_EPTYPE_Msk (0x7u << UDP_CSR_EPTYPE_Pos) /**< \brief (UDP_CSR[8]) Endpoint Type */
#define   UDP_CSR_EPTYPE_CTRL (0x0u << 8) /**< \brief (UDP_CSR[8]) Control */
#define   UDP_CSR_EPTYPE_ISO_OUT (0x1u << 8) /**< \brief (UDP_CSR[8]) Isochronous OUT */
#define   UDP_CSR_EPTYPE_BULK_OUT (0x2u << 8) /**< \brief (UDP_CSR[8]) Bulk OUT */
#define   UDP_CSR_EPTYPE_INT_OUT (0x3u << 8) /**< \brief (UDP_CSR[8]) Interrupt OUT */
#define   UDP_CSR_EPTYPE_ISO_IN (0x5u << 8) /**< \brief (UDP_CSR[8]) Isochronous IN */
#define   UDP_CSR_EPTYPE_BULK_IN (0x6u << 8) /**< \brief (UDP_CSR[8]) Bulk IN */
#define   UDP_CSR_EPTYPE_INT_IN (0x7u << 8) /**< \brief (UDP_CSR[8]) Interrupt IN */
#define UDP_CSR_DTGLE (0x1u << 11) /**< \brief (UDP_CSR[8]) Data Toggle */
#define UDP_CSR_EPEDS (0x1u << 15) /**< \brief (UDP_CSR[8]) Endpoint Enable Disable */
#define UDP_CSR_RXBYTECNT_Pos 16
#define UDP_CSR_RXBYTECNT_Msk (0x7ffu << UDP_CSR_RXBYTECNT_Pos) /**< \brief (UDP_CSR[8]) Number of Bytes Available in the FIFO */
#define UDP_CSR_RXBYTECNT(value) ((UDP_CSR_RXBYTECNT_Msk & ((value) << UDP_CSR_RXBYTECNT_Pos)))
/* -------- UDP_FDR[8] : (UDP Offset: 0x050) Endpoint FIFO Data Register -------- */
#define UDP_FDR_FIFO_DATA_Pos 0
#define UDP_FDR_FIFO_DATA_Msk (0xffu << UDP_FDR_FIFO_DATA_Pos) /**< \brief (UDP_FDR[8]) FIFO Data Value */
#define UDP_FDR_FIFO_DATA(value) ((UDP_FDR_FIFO_DATA_Msk & ((value) << UDP_FDR_FIFO_DATA_Pos)))
/* -------- UDP_TXVC : (UDP Offset: 0x074) Transceiver Control Register -------- */
#define UDP_TXVC_TXVDIS (0x1u << 8) /**< \brief (UDP_TXVC) Transceiver Disable */
#define UDP_TXVC_PUON (0x1u << 9) /**< \brief (UDP_TXVC) Pullup On */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Universal Synchronous Asynchronous Receiver Transmitter */
/* ============================================================================= */
/** \addtogroup SAM3S16_USART Universal Synchronous Asynchronous Receiver Transmitter */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Usart hardware registers */
typedef struct {
  WoReg US_CR;         /**< \brief (Usart Offset: 0x0000) Control Register */
  RwReg US_MR;         /**< \brief (Usart Offset: 0x0004) Mode Register */
  WoReg US_IER;        /**< \brief (Usart Offset: 0x0008) Interrupt Enable Register */
  WoReg US_IDR;        /**< \brief (Usart Offset: 0x000C) Interrupt Disable Register */
  RoReg US_IMR;        /**< \brief (Usart Offset: 0x0010) Interrupt Mask Register */
  RoReg US_CSR;        /**< \brief (Usart Offset: 0x0014) Channel Status Register */
  RoReg US_RHR;        /**< \brief (Usart Offset: 0x0018) Receiver Holding Register */
  WoReg US_THR;        /**< \brief (Usart Offset: 0x001C) Transmitter Holding Register */
  RwReg US_BRGR;       /**< \brief (Usart Offset: 0x0020) Baud Rate Generator Register */
  RwReg US_RTOR;       /**< \brief (Usart Offset: 0x0024) Receiver Time-out Register */
  RwReg US_TTGR;       /**< \brief (Usart Offset: 0x0028) Transmitter Timeguard Register */
  RoReg Reserved1[5];
  RwReg US_FIDI;       /**< \brief (Usart Offset: 0x0040) FI DI Ratio Register */
  RoReg US_NER;        /**< \brief (Usart Offset: 0x0044) Number of Errors Register */
  RoReg Reserved2[1];
  RwReg US_IF;         /**< \brief (Usart Offset: 0x004C) IrDA Filter Register */
  RwReg US_MAN;        /**< \brief (Usart Offset: 0x0050) Manchester Encoder Decoder Register */
  RoReg Reserved3[36];
  RwReg US_WPMR;       /**< \brief (Usart Offset: 0xE4) Write Protect Mode Register */
  RoReg US_WPSR;       /**< \brief (Usart Offset: 0xE8) Write Protect Status Register */
  RoReg Reserved4[4];
  RoReg US_VERSION;    /**< \brief (Usart Offset: 0xFC) Version Register */
  RwReg US_RPR;        /**< \brief (Usart Offset: 0x100) Receive Pointer Register */
  RwReg US_RCR;        /**< \brief (Usart Offset: 0x104) Receive Counter Register */
  RwReg US_TPR;        /**< \brief (Usart Offset: 0x108) Transmit Pointer Register */
  RwReg US_TCR;        /**< \brief (Usart Offset: 0x10C) Transmit Counter Register */
  RwReg US_RNPR;       /**< \brief (Usart Offset: 0x110) Receive Next Pointer Register */
  RwReg US_RNCR;       /**< \brief (Usart Offset: 0x114) Receive Next Counter Register */
  RwReg US_TNPR;       /**< \brief (Usart Offset: 0x118) Transmit Next Pointer Register */
  RwReg US_TNCR;       /**< \brief (Usart Offset: 0x11C) Transmit Next Counter Register */
  WoReg US_PTCR;       /**< \brief (Usart Offset: 0x120) Transfer Control Register */
  RoReg US_PTSR;       /**< \brief (Usart Offset: 0x124) Transfer Status Register */
} Usart;
#endif /* __ASSEMBLY__ */
/* -------- US_CR : (USART Offset: 0x0000) Control Register -------- */
#define US_CR_RSTRX (0x1u << 2) /**< \brief (US_CR) Reset Receiver */
#define US_CR_RSTTX (0x1u << 3) /**< \brief (US_CR) Reset Transmitter */
#define US_CR_RXEN (0x1u << 4) /**< \brief (US_CR) Receiver Enable */
#define US_CR_RXDIS (0x1u << 5) /**< \brief (US_CR) Receiver Disable */
#define US_CR_TXEN (0x1u << 6) /**< \brief (US_CR) Transmitter Enable */
#define US_CR_TXDIS (0x1u << 7) /**< \brief (US_CR) Transmitter Disable */
#define US_CR_RSTSTA (0x1u << 8) /**< \brief (US_CR) Reset Status Bits */
#define US_CR_STTBRK (0x1u << 9) /**< \brief (US_CR) Start Break */
#define US_CR_STPBRK (0x1u << 10) /**< \brief (US_CR) Stop Break */
#define US_CR_STTTO (0x1u << 11) /**< \brief (US_CR) Start Time-out */
#define US_CR_SENDA (0x1u << 12) /**< \brief (US_CR) Send Address */
#define US_CR_RSTIT (0x1u << 13) /**< \brief (US_CR) Reset Iterations */
#define US_CR_RSTNACK (0x1u << 14) /**< \brief (US_CR) Reset Non Acknowledge */
#define US_CR_RETTO (0x1u << 15) /**< \brief (US_CR) Rearm Time-out */
#define US_CR_DTREN (0x1u << 16) /**< \brief (US_CR) Data Terminal Ready Enable */
#define US_CR_DTRDIS (0x1u << 17) /**< \brief (US_CR) Data Terminal Ready Disable */
#define US_CR_RTSEN (0x1u << 18) /**< \brief (US_CR) Request to Send Enable */
#define US_CR_FCS (0x1u << 18) /**< \brief (US_CR) Force SPI Chip Select */
#define US_CR_RTSDIS (0x1u << 19) /**< \brief (US_CR) Request to Send Disable */
#define US_CR_RCS (0x1u << 19) /**< \brief (US_CR) Release SPI Chip Select */
/* -------- US_MR : (USART Offset: 0x0004) Mode Register -------- */
#define US_MR_USART_MODE_Pos 0
#define US_MR_USART_MODE_Msk (0xfu << US_MR_USART_MODE_Pos) /**< \brief (US_MR)  */
#define   US_MR_USART_MODE_NORMAL (0x0u << 0) /**< \brief (US_MR) Normal mode */
#define   US_MR_USART_MODE_RS485 (0x1u << 0) /**< \brief (US_MR) RS485 */
#define   US_MR_USART_MODE_HW_HANDSHAKING (0x2u << 0) /**< \brief (US_MR) Hardware Handshaking */
#define   US_MR_USART_MODE_MODEM (0x3u << 0) /**< \brief (US_MR) Modem */
#define   US_MR_USART_MODE_IS07816_T_0 (0x4u << 0) /**< \brief (US_MR) IS07816 Protocol: T = 0 */
#define   US_MR_USART_MODE_IS07816_T_1 (0x6u << 0) /**< \brief (US_MR) IS07816 Protocol: T = 1 */
#define   US_MR_USART_MODE_IRDA (0x8u << 0) /**< \brief (US_MR) IrDA */
#define   US_MR_USART_MODE_SPI_MASTER (0xEu << 0) /**< \brief (US_MR) SPI Master */
#define   US_MR_USART_MODE_SPI_SLAVE (0xFu << 0) /**< \brief (US_MR) SPI Slave */
#define US_MR_USCLKS_Pos 4
#define US_MR_USCLKS_Msk (0x3u << US_MR_USCLKS_Pos) /**< \brief (US_MR) Clock Selection */
#define   US_MR_USCLKS_MCK (0x0u << 4) /**< \brief (US_MR) Master Clock MCK is selected */
#define   US_MR_USCLKS_DIV (0x1u << 4) /**< \brief (US_MR) Internal Clock Divided MCK/DIV (DIV=8) is selected */
#define   US_MR_USCLKS_SCK (0x3u << 4) /**< \brief (US_MR) Serial Clock SLK is selected */
#define US_MR_CHRL_Pos 6
#define US_MR_CHRL_Msk (0x3u << US_MR_CHRL_Pos) /**< \brief (US_MR) Character Length. */
#define   US_MR_CHRL_5_BIT (0x0u << 6) /**< \brief (US_MR) Character length is 5 bits */
#define   US_MR_CHRL_6_BIT (0x1u << 6) /**< \brief (US_MR) Character length is 6 bits */
#define   US_MR_CHRL_7_BIT (0x2u << 6) /**< \brief (US_MR) Character length is 7 bits */
#define   US_MR_CHRL_8_BIT (0x3u << 6) /**< \brief (US_MR) Character length is 8 bits */
#define US_MR_SYNC (0x1u << 8) /**< \brief (US_MR) Synchronous Mode Select */
#define US_MR_CPHA (0x1u << 8) /**< \brief (US_MR) SPI Clock Phase */
#define US_MR_PAR_Pos 9
#define US_MR_PAR_Msk (0x7u << US_MR_PAR_Pos) /**< \brief (US_MR) Parity Type */
#define   US_MR_PAR_EVEN (0x0u << 9) /**< \brief (US_MR) Even parity */
#define   US_MR_PAR_ODD (0x1u << 9) /**< \brief (US_MR) Odd parity */
#define   US_MR_PAR_SPACE (0x2u << 9) /**< \brief (US_MR) Parity forced to 0 (Space) */
#define   US_MR_PAR_MARK (0x3u << 9) /**< \brief (US_MR) Parity forced to 1 (Mark) */
#define   US_MR_PAR_NO (0x4u << 9) /**< \brief (US_MR) No parity */
#define   US_MR_PAR_MULTIDROP (0x6u << 9) /**< \brief (US_MR) Multidrop mode */
#define US_MR_NBSTOP_Pos 12
#define US_MR_NBSTOP_Msk (0x3u << US_MR_NBSTOP_Pos) /**< \brief (US_MR) Number of Stop Bits */
#define   US_MR_NBSTOP_1_BIT (0x0u << 12) /**< \brief (US_MR) 1 stop bit */
#define   US_MR_NBSTOP_1_5_BIT (0x1u << 12) /**< \brief (US_MR) 1.5 stop bit (SYNC = 0) or reserved (SYNC = 1) */
#define   US_MR_NBSTOP_2_BIT (0x2u << 12) /**< \brief (US_MR) 2 stop bits */
#define US_MR_CHMODE_Pos 14
#define US_MR_CHMODE_Msk (0x3u << US_MR_CHMODE_Pos) /**< \brief (US_MR) Channel Mode */
#define   US_MR_CHMODE_NORMAL (0x0u << 14) /**< \brief (US_MR) Normal Mode */
#define   US_MR_CHMODE_AUTOMATIC (0x1u << 14) /**< \brief (US_MR) Automatic Echo. Receiver input is connected to the TXD pin. */
#define   US_MR_CHMODE_LOCAL_LOOPBACK (0x2u << 14) /**< \brief (US_MR) Local Loopback. Transmitter output is connected to the Receiver Input. */
#define   US_MR_CHMODE_REMOTE_LOOPBACK (0x3u << 14) /**< \brief (US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin. */
#define US_MR_MSBF (0x1u << 16) /**< \brief (US_MR) Bit Order */
#define US_MR_CPOL (0x1u << 16) /**< \brief (US_MR) SPI Clock Polarity */
#define US_MR_MODE9 (0x1u << 17) /**< \brief (US_MR) 9-bit Character Length */
#define US_MR_CLKO (0x1u << 18) /**< \brief (US_MR) Clock Output Select */
#define US_MR_OVER (0x1u << 19) /**< \brief (US_MR) Oversampling Mode */
#define US_MR_INACK (0x1u << 20) /**< \brief (US_MR) Inhibit Non Acknowledge */
#define US_MR_DSNACK (0x1u << 21) /**< \brief (US_MR) Disable Successive NACK */
#define US_MR_VAR_SYNC (0x1u << 22) /**< \brief (US_MR) Variable Synchronization of Command/Data Sync Start Frame Delimiter */
#define US_MR_INVDATA (0x1u << 23) /**< \brief (US_MR) INverted Data */
#define US_MR_MAX_ITERATION_Pos 24
#define US_MR_MAX_ITERATION_Msk (0x7u << US_MR_MAX_ITERATION_Pos) /**< \brief (US_MR)  */
#define US_MR_MAX_ITERATION(value) ((US_MR_MAX_ITERATION_Msk & ((value) << US_MR_MAX_ITERATION_Pos)))
#define US_MR_FILTER (0x1u << 28) /**< \brief (US_MR) Infrared Receive Line Filter */
#define US_MR_MAN (0x1u << 29) /**< \brief (US_MR) Manchester Encoder/Decoder Enable */
#define US_MR_MODSYNC (0x1u << 30) /**< \brief (US_MR) Manchester Synchronization Mode */
#define US_MR_ONEBIT (0x1u << 31) /**< \brief (US_MR) Start Frame Delimiter Selector */
/* -------- US_IER : (USART Offset: 0x0008) Interrupt Enable Register -------- */
#define US_IER_RXRDY (0x1u << 0) /**< \brief (US_IER) RXRDY Interrupt Enable */
#define US_IER_TXRDY (0x1u << 1) /**< \brief (US_IER) TXRDY Interrupt Enable */
#define US_IER_RXBRK (0x1u << 2) /**< \brief (US_IER) Receiver Break Interrupt Enable */
#define US_IER_ENDRX (0x1u << 3) /**< \brief (US_IER) End of Receive Transfer Interrupt Enable */
#define US_IER_ENDTX (0x1u << 4) /**< \brief (US_IER) End of Transmit Interrupt Enable */
#define US_IER_OVRE (0x1u << 5) /**< \brief (US_IER) Overrun Error Interrupt Enable */
#define US_IER_FRAME (0x1u << 6) /**< \brief (US_IER) Framing Error Interrupt Enable */
#define US_IER_PARE (0x1u << 7) /**< \brief (US_IER) Parity Error Interrupt Enable */
#define US_IER_TIMEOUT (0x1u << 8) /**< \brief (US_IER) Time-out Interrupt Enable */
#define US_IER_TXEMPTY (0x1u << 9) /**< \brief (US_IER) TXEMPTY Interrupt Enable */
#define US_IER_ITER (0x1u << 10) /**< \brief (US_IER) Max number of Repetitions Reached */
#define US_IER_UNRE (0x1u << 10) /**< \brief (US_IER) SPI Underrun Error */
#define US_IER_TXBUFE (0x1u << 11) /**< \brief (US_IER) Buffer Empty Interrupt Enable */
#define US_IER_RXBUFF (0x1u << 12) /**< \brief (US_IER) Buffer Full Interrupt Enable */
#define US_IER_NACK (0x1u << 13) /**< \brief (US_IER) Non AcknowledgeInterrupt Enable */
#define US_IER_RIIC (0x1u << 16) /**< \brief (US_IER) Ring Indicator Input Change Enable */
#define US_IER_DSRIC (0x1u << 17) /**< \brief (US_IER) Data Set Ready Input Change Enable */
#define US_IER_DCDIC (0x1u << 18) /**< \brief (US_IER) Data Carrier Detect Input Change Interrupt Enable */
#define US_IER_CTSIC (0x1u << 19) /**< \brief (US_IER) Clear to Send Input Change Interrupt Enable */
#define US_IER_MANE (0x1u << 24) /**< \brief (US_IER) Manchester Error Interrupt Enable */
/* -------- US_IDR : (USART Offset: 0x000C) Interrupt Disable Register -------- */
#define US_IDR_RXRDY (0x1u << 0) /**< \brief (US_IDR) RXRDY Interrupt Disable */
#define US_IDR_TXRDY (0x1u << 1) /**< \brief (US_IDR) TXRDY Interrupt Disable */
#define US_IDR_RXBRK (0x1u << 2) /**< \brief (US_IDR) Receiver Break Interrupt Disable */
#define US_IDR_ENDRX (0x1u << 3) /**< \brief (US_IDR) End of Receive Transfer Interrupt Disable */
#define US_IDR_ENDTX (0x1u << 4) /**< \brief (US_IDR) End of Transmit Interrupt Disable */
#define US_IDR_OVRE (0x1u << 5) /**< \brief (US_IDR) Overrun Error Interrupt Disable */
#define US_IDR_FRAME (0x1u << 6) /**< \brief (US_IDR) Framing Error Interrupt Disable */
#define US_IDR_PARE (0x1u << 7) /**< \brief (US_IDR) Parity Error Interrupt Disable */
#define US_IDR_TIMEOUT (0x1u << 8) /**< \brief (US_IDR) Time-out Interrupt Disable */
#define US_IDR_TXEMPTY (0x1u << 9) /**< \brief (US_IDR) TXEMPTY Interrupt Disable */
#define US_IDR_ITER (0x1u << 10) /**< \brief (US_IDR) Max number of Repetitions Reached Disable */
#define US_IDR_UNRE (0x1u << 10) /**< \brief (US_IDR) SPI Underrun Error Disable */
#define US_IDR_TXBUFE (0x1u << 11) /**< \brief (US_IDR) Buffer Empty Interrupt Disable */
#define US_IDR_RXBUFF (0x1u << 12) /**< \brief (US_IDR) Buffer Full Interrupt Disable */
#define US_IDR_NACK (0x1u << 13) /**< \brief (US_IDR) Non AcknowledgeInterrupt Disable */
#define US_IDR_RIIC (0x1u << 16) /**< \brief (US_IDR) Ring Indicator Input Change Disable */
#define US_IDR_DSRIC (0x1u << 17) /**< \brief (US_IDR) Data Set Ready Input Change Disable */
#define US_IDR_DCDIC (0x1u << 18) /**< \brief (US_IDR) Data Carrier Detect Input Change Interrupt Disable */
#define US_IDR_CTSIC (0x1u << 19) /**< \brief (US_IDR) Clear to Send Input Change Interrupt Disable */
#define US_IDR_MANE (0x1u << 24) /**< \brief (US_IDR) Manchester Error Interrupt Disable */
/* -------- US_IMR : (USART Offset: 0x0010) Interrupt Mask Register -------- */
#define US_IMR_RXRDY (0x1u << 0) /**< \brief (US_IMR) RXRDY Interrupt Mask */
#define US_IMR_TXRDY (0x1u << 1) /**< \brief (US_IMR) TXRDY Interrupt Mask */
#define US_IMR_RXBRK (0x1u << 2) /**< \brief (US_IMR) Receiver Break Interrupt Mask */
#define US_IMR_ENDRX (0x1u << 3) /**< \brief (US_IMR) End of Receive Transfer Interrupt Mask */
#define US_IMR_ENDTX (0x1u << 4) /**< \brief (US_IMR) End of Transmit Interrupt Mask */
#define US_IMR_OVRE (0x1u << 5) /**< \brief (US_IMR) Overrun Error Interrupt Mask */
#define US_IMR_FRAME (0x1u << 6) /**< \brief (US_IMR) Framing Error Interrupt Mask */
#define US_IMR_PARE (0x1u << 7) /**< \brief (US_IMR) Parity Error Interrupt Mask */
#define US_IMR_TIMEOUT (0x1u << 8) /**< \brief (US_IMR) Time-out Interrupt Mask */
#define US_IMR_TXEMPTY (0x1u << 9) /**< \brief (US_IMR) TXEMPTY Interrupt Mask */
#define US_IMR_ITER (0x1u << 10) /**< \brief (US_IMR) Max number of Repetitions Reached Mask */
#define US_IMR_UNRE (0x1u << 10) /**< \brief (US_IMR) SPI Underrun Error Mask */
#define US_IMR_TXBUFE (0x1u << 11) /**< \brief (US_IMR) Buffer Empty Interrupt Mask */
#define US_IMR_RXBUFF (0x1u << 12) /**< \brief (US_IMR) Buffer Full Interrupt Mask */
#define US_IMR_NACK (0x1u << 13) /**< \brief (US_IMR) Non AcknowledgeInterrupt Mask */
#define US_IMR_RIIC (0x1u << 16) /**< \brief (US_IMR) Ring Indicator Input Change Mask */
#define US_IMR_DSRIC (0x1u << 17) /**< \brief (US_IMR) Data Set Ready Input Change Mask */
#define US_IMR_DCDIC (0x1u << 18) /**< \brief (US_IMR) Data Carrier Detect Input Change Interrupt Mask */
#define US_IMR_CTSIC (0x1u << 19) /**< \brief (US_IMR) Clear to Send Input Change Interrupt Mask */
#define US_IMR_MANE (0x1u << 24) /**< \brief (US_IMR) Manchester Error Interrupt Mask */
/* -------- US_CSR : (USART Offset: 0x0014) Channel Status Register -------- */
#define US_CSR_RXRDY (0x1u << 0) /**< \brief (US_CSR) Receiver Ready */
#define US_CSR_TXRDY (0x1u << 1) /**< \brief (US_CSR) Transmitter Ready */
#define US_CSR_RXBRK (0x1u << 2) /**< \brief (US_CSR) Break Received/End of Break */
#define US_CSR_ENDRX (0x1u << 3) /**< \brief (US_CSR) End of Receiver Transfer */
#define US_CSR_ENDTX (0x1u << 4) /**< \brief (US_CSR) End of Transmitter Transfer */
#define US_CSR_OVRE (0x1u << 5) /**< \brief (US_CSR) Overrun Error */
#define US_CSR_FRAME (0x1u << 6) /**< \brief (US_CSR) Framing Error */
#define US_CSR_PARE (0x1u << 7) /**< \brief (US_CSR) Parity Error */
#define US_CSR_TIMEOUT (0x1u << 8) /**< \brief (US_CSR) Receiver Time-out */
#define US_CSR_TXEMPTY (0x1u << 9) /**< \brief (US_CSR) Transmitter Empty */
#define US_CSR_ITER (0x1u << 10) /**< \brief (US_CSR) Max number of Repetitions Reached */
#define US_CSR_UNRE (0x1u << 10) /**< \brief (US_CSR) SPI Underrun Error */
#define US_CSR_TXBUFE (0x1u << 11) /**< \brief (US_CSR) Transmission Buffer Empty */
#define US_CSR_RXBUFF (0x1u << 12) /**< \brief (US_CSR) Reception Buffer Full */
#define US_CSR_NACK (0x1u << 13) /**< \brief (US_CSR) Non AcknowledgeInterrupt */
#define US_CSR_RIIC (0x1u << 16) /**< \brief (US_CSR) Ring Indicator Input Change Flag */
#define US_CSR_DSRIC (0x1u << 17) /**< \brief (US_CSR) Data Set Ready Input Change Flag */
#define US_CSR_DCDIC (0x1u << 18) /**< \brief (US_CSR) Data Carrier Detect Input Change Flag */
#define US_CSR_CTSIC (0x1u << 19) /**< \brief (US_CSR) Clear to Send Input Change Flag */
#define US_CSR_RI (0x1u << 20) /**< \brief (US_CSR) Image of RI Input */
#define US_CSR_DSR (0x1u << 21) /**< \brief (US_CSR) Image of DSR Input */
#define US_CSR_DCD (0x1u << 22) /**< \brief (US_CSR) Image of DCD Input */
#define US_CSR_CTS (0x1u << 23) /**< \brief (US_CSR) Image of CTS Input */
#define US_CSR_MANERR (0x1u << 24) /**< \brief (US_CSR) Manchester Error */
/* -------- US_RHR : (USART Offset: 0x0018) Receiver Holding Register -------- */
#define US_RHR_RXCHR_Pos 0
#define US_RHR_RXCHR_Msk (0x1ffu << US_RHR_RXCHR_Pos) /**< \brief (US_RHR) Received Character */
#define US_RHR_RXSYNH (0x1u << 15) /**< \brief (US_RHR) Received Sync */
/* -------- US_THR : (USART Offset: 0x001C) Transmitter Holding Register -------- */
#define US_THR_TXCHR_Pos 0
#define US_THR_TXCHR_Msk (0x1ffu << US_THR_TXCHR_Pos) /**< \brief (US_THR) Character to be Transmitted */
#define US_THR_TXCHR(value) ((US_THR_TXCHR_Msk & ((value) << US_THR_TXCHR_Pos)))
#define US_THR_TXSYNH (0x1u << 15) /**< \brief (US_THR) Sync Field to be transmitted */
/* -------- US_BRGR : (USART Offset: 0x0020) Baud Rate Generator Register -------- */
#define US_BRGR_CD_Pos 0
#define US_BRGR_CD_Msk (0xffffu << US_BRGR_CD_Pos) /**< \brief (US_BRGR) Clock Divider */
#define US_BRGR_CD(value) ((US_BRGR_CD_Msk & ((value) << US_BRGR_CD_Pos)))
#define US_BRGR_FP_Pos 16
#define US_BRGR_FP_Msk (0x7u << US_BRGR_FP_Pos) /**< \brief (US_BRGR) Fractional Part */
#define US_BRGR_FP(value) ((US_BRGR_FP_Msk & ((value) << US_BRGR_FP_Pos)))
/* -------- US_RTOR : (USART Offset: 0x0024) Receiver Time-out Register -------- */
#define US_RTOR_TO_Pos 0
#define US_RTOR_TO_Msk (0xffffu << US_RTOR_TO_Pos) /**< \brief (US_RTOR) Time-out Value */
#define US_RTOR_TO(value) ((US_RTOR_TO_Msk & ((value) << US_RTOR_TO_Pos)))
/* -------- US_TTGR : (USART Offset: 0x0028) Transmitter Timeguard Register -------- */
#define US_TTGR_TG_Pos 0
#define US_TTGR_TG_Msk (0xffu << US_TTGR_TG_Pos) /**< \brief (US_TTGR) Timeguard Value */
#define US_TTGR_TG(value) ((US_TTGR_TG_Msk & ((value) << US_TTGR_TG_Pos)))
/* -------- US_FIDI : (USART Offset: 0x0040) FI DI Ratio Register -------- */
#define US_FIDI_FI_DI_RATIO_Pos 0
#define US_FIDI_FI_DI_RATIO_Msk (0x7ffu << US_FIDI_FI_DI_RATIO_Pos) /**< \brief (US_FIDI) FI Over DI Ratio Value */
#define US_FIDI_FI_DI_RATIO(value) ((US_FIDI_FI_DI_RATIO_Msk & ((value) << US_FIDI_FI_DI_RATIO_Pos)))
/* -------- US_NER : (USART Offset: 0x0044) Number of Errors Register -------- */
#define US_NER_NB_ERRORS_Pos 0
#define US_NER_NB_ERRORS_Msk (0xffu << US_NER_NB_ERRORS_Pos) /**< \brief (US_NER) Number of Errors */
/* -------- US_IF : (USART Offset: 0x004C) IrDA Filter Register -------- */
#define US_IF_IRDA_FILTER_Pos 0
#define US_IF_IRDA_FILTER_Msk (0xffu << US_IF_IRDA_FILTER_Pos) /**< \brief (US_IF) IrDA Filter */
#define US_IF_IRDA_FILTER(value) ((US_IF_IRDA_FILTER_Msk & ((value) << US_IF_IRDA_FILTER_Pos)))
/* -------- US_MAN : (USART Offset: 0x0050) Manchester Encoder Decoder Register -------- */
#define US_MAN_TX_PL_Pos 0
#define US_MAN_TX_PL_Msk (0xfu << US_MAN_TX_PL_Pos) /**< \brief (US_MAN) Transmitter Preamble Length */
#define US_MAN_TX_PL(value) ((US_MAN_TX_PL_Msk & ((value) << US_MAN_TX_PL_Pos)))
#define US_MAN_TX_PP_Pos 8
#define US_MAN_TX_PP_Msk (0x3u << US_MAN_TX_PP_Pos) /**< \brief (US_MAN) Transmitter Preamble Pattern */
#define   US_MAN_TX_PP_ALL_ONE (0x0u << 8) /**< \brief (US_MAN) The preamble is composed of '1's */
#define   US_MAN_TX_PP_ALL_ZERO (0x1u << 8) /**< \brief (US_MAN) The preamble is composed of '0's */
#define   US_MAN_TX_PP_ZERO_ONE (0x2u << 8) /**< \brief (US_MAN) The preamble is composed of '01's */
#define   US_MAN_TX_PP_ONE_ZERO (0x3u << 8) /**< \brief (US_MAN) The preamble is composed of '10's */
#define US_MAN_TX_MPOL (0x1u << 12) /**< \brief (US_MAN) Transmitter Manchester Polarity */
#define US_MAN_RX_PL_Pos 16
#define US_MAN_RX_PL_Msk (0xfu << US_MAN_RX_PL_Pos) /**< \brief (US_MAN) Receiver Preamble Length */
#define US_MAN_RX_PL(value) ((US_MAN_RX_PL_Msk & ((value) << US_MAN_RX_PL_Pos)))
#define US_MAN_RX_PP_Pos 24
#define US_MAN_RX_PP_Msk (0x3u << US_MAN_RX_PP_Pos) /**< \brief (US_MAN) Receiver Preamble Pattern detected */
#define   US_MAN_RX_PP_ALL_ONE (0x0u << 24) /**< \brief (US_MAN) The preamble is composed of '1's */
#define   US_MAN_RX_PP_ALL_ZERO (0x1u << 24) /**< \brief (US_MAN) The preamble is composed of '0's */
#define   US_MAN_RX_PP_ZERO_ONE (0x2u << 24) /**< \brief (US_MAN) The preamble is composed of '01's */
#define   US_MAN_RX_PP_ONE_ZERO (0x3u << 24) /**< \brief (US_MAN) The preamble is composed of '10's */
#define US_MAN_RX_MPOL (0x1u << 28) /**< \brief (US_MAN) Receiver Manchester Polarity */
#define US_MAN_STUCKTO1 (0x1u << 29) /**< \brief (US_MAN)  */
#define US_MAN_DRIFT (0x1u << 30) /**< \brief (US_MAN) Drift compensation */
/* -------- US_WPMR : (USART Offset: 0xE4) Write Protect Mode Register -------- */
#define US_WPMR_WPEN (0x1u << 0) /**< \brief (US_WPMR) Write Protect Enable */
#define US_WPMR_WPKEY_Pos 8
#define US_WPMR_WPKEY_Msk (0xffffffu << US_WPMR_WPKEY_Pos) /**< \brief (US_WPMR) Write Protect KEY */
#define US_WPMR_WPKEY(value) ((US_WPMR_WPKEY_Msk & ((value) << US_WPMR_WPKEY_Pos)))
/* -------- US_WPSR : (USART Offset: 0xE8) Write Protect Status Register -------- */
#define US_WPSR_WPVS (0x1u << 0) /**< \brief (US_WPSR) Write Protect Violation Status */
#define US_WPSR_WPVSRC_Pos 8
#define US_WPSR_WPVSRC_Msk (0xffffu << US_WPSR_WPVSRC_Pos) /**< \brief (US_WPSR) Write Protect Violation Source */
/* -------- US_VERSION : (USART Offset: 0xFC) Version Register -------- */
#define US_VERSION_VERSION_Pos 0
#define US_VERSION_VERSION_Msk (0xfffu << US_VERSION_VERSION_Pos) /**< \brief (US_VERSION)  */
#define US_VERSION_MFN_Pos 16
#define US_VERSION_MFN_Msk (0x7u << US_VERSION_MFN_Pos) /**< \brief (US_VERSION)  */
/* -------- US_RPR : (USART Offset: 0x100) Receive Pointer Register -------- */
#define US_RPR_RXPTR_Pos 0
#define US_RPR_RXPTR_Msk (0xffffffffu << US_RPR_RXPTR_Pos) /**< \brief (US_RPR) Receive Pointer Register */
#define US_RPR_RXPTR(value) ((US_RPR_RXPTR_Msk & ((value) << US_RPR_RXPTR_Pos)))
/* -------- US_RCR : (USART Offset: 0x104) Receive Counter Register -------- */
#define US_RCR_RXCTR_Pos 0
#define US_RCR_RXCTR_Msk (0xffffu << US_RCR_RXCTR_Pos) /**< \brief (US_RCR) Receive Counter Register */
#define US_RCR_RXCTR(value) ((US_RCR_RXCTR_Msk & ((value) << US_RCR_RXCTR_Pos)))
/* -------- US_TPR : (USART Offset: 0x108) Transmit Pointer Register -------- */
#define US_TPR_TXPTR_Pos 0
#define US_TPR_TXPTR_Msk (0xffffffffu << US_TPR_TXPTR_Pos) /**< \brief (US_TPR) Transmit Counter Register */
#define US_TPR_TXPTR(value) ((US_TPR_TXPTR_Msk & ((value) << US_TPR_TXPTR_Pos)))
/* -------- US_TCR : (USART Offset: 0x10C) Transmit Counter Register -------- */
#define US_TCR_TXCTR_Pos 0
#define US_TCR_TXCTR_Msk (0xffffu << US_TCR_TXCTR_Pos) /**< \brief (US_TCR) Transmit Counter Register */
#define US_TCR_TXCTR(value) ((US_TCR_TXCTR_Msk & ((value) << US_TCR_TXCTR_Pos)))
/* -------- US_RNPR : (USART Offset: 0x110) Receive Next Pointer Register -------- */
#define US_RNPR_RXNPTR_Pos 0
#define US_RNPR_RXNPTR_Msk (0xffffffffu << US_RNPR_RXNPTR_Pos) /**< \brief (US_RNPR) Receive Next Pointer */
#define US_RNPR_RXNPTR(value) ((US_RNPR_RXNPTR_Msk & ((value) << US_RNPR_RXNPTR_Pos)))
/* -------- US_RNCR : (USART Offset: 0x114) Receive Next Counter Register -------- */
#define US_RNCR_RXNCTR_Pos 0
#define US_RNCR_RXNCTR_Msk (0xffffu << US_RNCR_RXNCTR_Pos) /**< \brief (US_RNCR) Receive Next Counter */
#define US_RNCR_RXNCTR(value) ((US_RNCR_RXNCTR_Msk & ((value) << US_RNCR_RXNCTR_Pos)))
/* -------- US_TNPR : (USART Offset: 0x118) Transmit Next Pointer Register -------- */
#define US_TNPR_TXNPTR_Pos 0
#define US_TNPR_TXNPTR_Msk (0xffffffffu << US_TNPR_TXNPTR_Pos) /**< \brief (US_TNPR) Transmit Next Pointer */
#define US_TNPR_TXNPTR(value) ((US_TNPR_TXNPTR_Msk & ((value) << US_TNPR_TXNPTR_Pos)))
/* -------- US_TNCR : (USART Offset: 0x11C) Transmit Next Counter Register -------- */
#define US_TNCR_TXNCTR_Pos 0
#define US_TNCR_TXNCTR_Msk (0xffffu << US_TNCR_TXNCTR_Pos) /**< \brief (US_TNCR) Transmit Counter Next */
#define US_TNCR_TXNCTR(value) ((US_TNCR_TXNCTR_Msk & ((value) << US_TNCR_TXNCTR_Pos)))
/* -------- US_PTCR : (USART Offset: 0x120) Transfer Control Register -------- */
#define US_PTCR_RXTEN (0x1u << 0) /**< \brief (US_PTCR) Receiver Transfer Enable */
#define US_PTCR_RXTDIS (0x1u << 1) /**< \brief (US_PTCR) Receiver Transfer Disable */
#define US_PTCR_TXTEN (0x1u << 8) /**< \brief (US_PTCR) Transmitter Transfer Enable */
#define US_PTCR_TXTDIS (0x1u << 9) /**< \brief (US_PTCR) Transmitter Transfer Disable */
/* -------- US_PTSR : (USART Offset: 0x124) Transfer Status Register -------- */
#define US_PTSR_RXTEN (0x1u << 0) /**< \brief (US_PTSR) Receiver Transfer Enable */
#define US_PTSR_TXTEN (0x1u << 8) /**< \brief (US_PTSR) Transmitter Transfer Enable */

/*@}*/

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Watchdog Timer */
/* ============================================================================= */
/** \addtogroup SAM3S16_WDT Watchdog Timer */
/*@{*/

#ifndef __ASSEMBLY__
/** \brief Wdt hardware registers */
typedef struct {
  WoReg WDT_CR; /**< \brief (Wdt Offset: 0x00) Control Register */
  RwReg WDT_MR; /**< \brief (Wdt Offset: 0x04) Mode Register */
  RoReg WDT_SR; /**< \brief (Wdt Offset: 0x08) Status Register */
} Wdt;
#endif /* __ASSEMBLY__ */
/* -------- WDT_CR : (WDT Offset: 0x00) Control Register -------- */
#define WDT_CR_WDRSTT (0x1u << 0) /**< \brief (WDT_CR) Watchdog Restart */
#define WDT_CR_KEY_Pos 24
#define WDT_CR_KEY_Msk (0xffu << WDT_CR_KEY_Pos) /**< \brief (WDT_CR) Password */
#define WDT_CR_KEY(value) ((WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos)))
/* -------- WDT_MR : (WDT Offset: 0x04) Mode Register -------- */
#define WDT_MR_WDV_Pos 0
#define WDT_MR_WDV_Msk (0xfffu << WDT_MR_WDV_Pos) /**< \brief (WDT_MR) Watchdog Counter Value */
#define WDT_MR_WDV(value) ((WDT_MR_WDV_Msk & ((value) << WDT_MR_WDV_Pos)))
#define WDT_MR_WDFIEN (0x1u << 12) /**< \brief (WDT_MR) Watchdog Fault Interrupt Enable */
#define WDT_MR_WDRSTEN (0x1u << 13) /**< \brief (WDT_MR) Watchdog Reset Enable */
#define WDT_MR_WDRPROC (0x1u << 14) /**< \brief (WDT_MR) Watchdog Reset Processor */
#define WDT_MR_WDDIS (0x1u << 15) /**< \brief (WDT_MR) Watchdog Disable */
#define WDT_MR_WDD_Pos 16
#define WDT_MR_WDD_Msk (0xfffu << WDT_MR_WDD_Pos) /**< \brief (WDT_MR) Watchdog Delta Value */
#define WDT_MR_WDD(value) ((WDT_MR_WDD_Msk & ((value) << WDT_MR_WDD_Pos)))
#define WDT_MR_WDDBGHLT (0x1u << 28) /**< \brief (WDT_MR) Watchdog Debug Halt */
#define WDT_MR_WDIDLEHLT (0x1u << 29) /**< \brief (WDT_MR) Watchdog Idle Halt */
/* -------- WDT_SR : (WDT Offset: 0x08) Status Register -------- */
#define WDT_SR_WDUNF (0x1u << 0) /**< \brief (WDT_SR) Watchdog Underflow */
#define WDT_SR_WDERR (0x1u << 1) /**< \brief (WDT_SR) Watchdog Error */

/*@}*/

/*@}*/

/* ************************************************************************** */
/*   REGISTER ACCESS DEFINITIONS FOR SAM3S16 */
/* ************************************************************************** */
/** \addtogroup SAM3S16_reg Registers Access Definitions */
/*@{*/

/* ========== Register definition for HSMCI peripheral ========== */
#define REG_HSMCI_CR        REG_ACCESS(WoReg, 0x40000000U) /**< \brief (HSMCI) Control Register */
#define REG_HSMCI_MR        REG_ACCESS(RwReg, 0x40000004U) /**< \brief (HSMCI) Mode Register */
#define REG_HSMCI_DTOR      REG_ACCESS(RwReg, 0x40000008U) /**< \brief (HSMCI) Data Timeout Register */
#define REG_HSMCI_SDCR      REG_ACCESS(RwReg, 0x4000000CU) /**< \brief (HSMCI) SD/SDIO Card Register */
#define REG_HSMCI_ARGR      REG_ACCESS(RwReg, 0x40000010U) /**< \brief (HSMCI) Argument Register */
#define REG_HSMCI_CMDR      REG_ACCESS(WoReg, 0x40000014U) /**< \brief (HSMCI) Command Register */
#define REG_HSMCI_BLKR      REG_ACCESS(RwReg, 0x40000018U) /**< \brief (HSMCI) Block Register */
#define REG_HSMCI_CSTOR     REG_ACCESS(RwReg, 0x4000001CU) /**< \brief (HSMCI) Completion Signal Timeout Register */
#define REG_HSMCI_RSPR      REG_ACCESS(RoReg, 0x40000020U) /**< \brief (HSMCI) Response Register */
#define REG_HSMCI_RDR       REG_ACCESS(RoReg, 0x40000030U) /**< \brief (HSMCI) Receive Data Register */
#define REG_HSMCI_TDR       REG_ACCESS(WoReg, 0x40000034U) /**< \brief (HSMCI) Transmit Data Register */
#define REG_HSMCI_SR        REG_ACCESS(RoReg, 0x40000040U) /**< \brief (HSMCI) Status Register */
#define REG_HSMCI_IER       REG_ACCESS(WoReg, 0x40000044U) /**< \brief (HSMCI) Interrupt Enable Register */
#define REG_HSMCI_IDR       REG_ACCESS(WoReg, 0x40000048U) /**< \brief (HSMCI) Interrupt Disable Register */
#define REG_HSMCI_IMR       REG_ACCESS(RoReg, 0x4000004CU) /**< \brief (HSMCI) Interrupt Mask Register */
#define REG_HSMCI_CFG       REG_ACCESS(RwReg, 0x40000054U) /**< \brief (HSMCI) Configuration Register */
#define REG_HSMCI_WPMR      REG_ACCESS(RwReg, 0x400000E4U) /**< \brief (HSMCI) Write Protection Mode Register */
#define REG_HSMCI_WPSR      REG_ACCESS(RoReg, 0x400000E8U) /**< \brief (HSMCI) Write Protection Status Register */
#define REG_HSMCI_RPR       REG_ACCESS(RwReg, 0x40000100U) /**< \brief (HSMCI) Receive Pointer Register */
#define REG_HSMCI_RCR       REG_ACCESS(RwReg, 0x40000104U) /**< \brief (HSMCI) Receive Counter Register */
#define REG_HSMCI_TPR       REG_ACCESS(RwReg, 0x40000108U) /**< \brief (HSMCI) Transmit Pointer Register */
#define REG_HSMCI_TCR       REG_ACCESS(RwReg, 0x4000010CU) /**< \brief (HSMCI) Transmit Counter Register */
#define REG_HSMCI_RNPR      REG_ACCESS(RwReg, 0x40000110U) /**< \brief (HSMCI) Receive Next Pointer Register */
#define REG_HSMCI_RNCR      REG_ACCESS(RwReg, 0x40000114U) /**< \brief (HSMCI) Receive Next Counter Register */
#define REG_HSMCI_TNPR      REG_ACCESS(RwReg, 0x40000118U) /**< \brief (HSMCI) Transmit Next Pointer Register */
#define REG_HSMCI_TNCR      REG_ACCESS(RwReg, 0x4000011CU) /**< \brief (HSMCI) Transmit Next Counter Register */
#define REG_HSMCI_PTCR      REG_ACCESS(WoReg, 0x40000120U) /**< \brief (HSMCI) Transfer Control Register */
#define REG_HSMCI_PTSR      REG_ACCESS(RoReg, 0x40000124U) /**< \brief (HSMCI) Transfer Status Register */
#define REG_HSMCI_FIFO      REG_ACCESS(RwReg, 0x40000200U) /**< \brief (HSMCI) FIFO Memory Aperture0 */
/* ========== Register definition for SSC peripheral ========== */
#define REG_SSC_CR          REG_ACCESS(WoReg, 0x40004000U) /**< \brief (SSC) Control Register */
#define REG_SSC_CMR         REG_ACCESS(RwReg, 0x40004004U) /**< \brief (SSC) Clock Mode Register */
#define REG_SSC_RCMR        REG_ACCESS(RwReg, 0x40004010U) /**< \brief (SSC) Receive Clock Mode Register */
#define REG_SSC_RFMR        REG_ACCESS(RwReg, 0x40004014U) /**< \brief (SSC) Receive Frame Mode Register */
#define REG_SSC_TCMR        REG_ACCESS(RwReg, 0x40004018U) /**< \brief (SSC) Transmit Clock Mode Register */
#define REG_SSC_TFMR        REG_ACCESS(RwReg, 0x4000401CU) /**< \brief (SSC) Transmit Frame Mode Register */
#define REG_SSC_RHR         REG_ACCESS(RoReg, 0x40004020U) /**< \brief (SSC) Receive Holding Register */
#define REG_SSC_THR         REG_ACCESS(WoReg, 0x40004024U) /**< \brief (SSC) Transmit Holding Register */
#define REG_SSC_RSHR        REG_ACCESS(RoReg, 0x40004030U) /**< \brief (SSC) Receive Sync. Holding Register */
#define REG_SSC_TSHR        REG_ACCESS(RwReg, 0x40004034U) /**< \brief (SSC) Transmit Sync. Holding Register */
#define REG_SSC_RC0R        REG_ACCESS(RwReg, 0x40004038U) /**< \brief (SSC) Receive Compare 0 Register */
#define REG_SSC_RC1R        REG_ACCESS(RwReg, 0x4000403CU) /**< \brief (SSC) Receive Compare 1 Register */
#define REG_SSC_SR          REG_ACCESS(RoReg, 0x40004040U) /**< \brief (SSC) Status Register */
#define REG_SSC_IER         REG_ACCESS(WoReg, 0x40004044U) /**< \brief (SSC) Interrupt Enable Register */
#define REG_SSC_IDR         REG_ACCESS(WoReg, 0x40004048U) /**< \brief (SSC) Interrupt Disable Register */
#define REG_SSC_IMR         REG_ACCESS(RoReg, 0x4000404CU) /**< \brief (SSC) Interrupt Mask Register */
#define REG_SSC_WPMR        REG_ACCESS(RwReg, 0x400040E4U) /**< \brief (SSC) Write Protect Mode Register */
#define REG_SSC_WPSR        REG_ACCESS(RoReg, 0x400040E8U) /**< \brief (SSC) Write Protect Status Register */
#define REG_SSC_RPR         REG_ACCESS(RwReg, 0x40004100U) /**< \brief (SSC) Receive Pointer Register */
#define REG_SSC_RCR         REG_ACCESS(RwReg, 0x40004104U) /**< \brief (SSC) Receive Counter Register */
#define REG_SSC_TPR         REG_ACCESS(RwReg, 0x40004108U) /**< \brief (SSC) Transmit Pointer Register */
#define REG_SSC_TCR         REG_ACCESS(RwReg, 0x4000410CU) /**< \brief (SSC) Transmit Counter Register */
#define REG_SSC_RNPR        REG_ACCESS(RwReg, 0x40004110U) /**< \brief (SSC) Receive Next Pointer Register */
#define REG_SSC_RNCR        REG_ACCESS(RwReg, 0x40004114U) /**< \brief (SSC) Receive Next Counter Register */
#define REG_SSC_TNPR        REG_ACCESS(RwReg, 0x40004118U) /**< \brief (SSC) Transmit Next Pointer Register */
#define REG_SSC_TNCR        REG_ACCESS(RwReg, 0x4000411CU) /**< \brief (SSC) Transmit Next Counter Register */
#define REG_SSC_PTCR        REG_ACCESS(WoReg, 0x40004120U) /**< \brief (SSC) Transfer Control Register */
#define REG_SSC_PTSR        REG_ACCESS(RoReg, 0x40004124U) /**< \brief (SSC) Transfer Status Register */
/* ========== Register definition for SPI peripheral ========== */
#define REG_SPI_CR          REG_ACCESS(WoReg, 0x40008000U) /**< \brief (SPI) Control Register */
#define REG_SPI_MR          REG_ACCESS(RwReg, 0x40008004U) /**< \brief (SPI) Mode Register */
#define REG_SPI_RDR         REG_ACCESS(RoReg, 0x40008008U) /**< \brief (SPI) Receive Data Register */
#define REG_SPI_TDR         REG_ACCESS(WoReg, 0x4000800CU) /**< \brief (SPI) Transmit Data Register */
#define REG_SPI_SR          REG_ACCESS(RoReg, 0x40008010U) /**< \brief (SPI) Status Register */
#define REG_SPI_IER         REG_ACCESS(WoReg, 0x40008014U) /**< \brief (SPI) Interrupt Enable Register */
#define REG_SPI_IDR         REG_ACCESS(WoReg, 0x40008018U) /**< \brief (SPI) Interrupt Disable Register */
#define REG_SPI_IMR         REG_ACCESS(RoReg, 0x4000801CU) /**< \brief (SPI) Interrupt Mask Register */
#define REG_SPI_CSR         REG_ACCESS(RwReg, 0x40008030U) /**< \brief (SPI) Chip Select Register */
#define REG_SPI_WPMR        REG_ACCESS(RwReg, 0x400080E4U) /**< \brief (SPI) Write Protection Control Register */
#define REG_SPI_WPSR        REG_ACCESS(RoReg, 0x400080E8U) /**< \brief (SPI) Write Protection Status Register */
#define REG_SPI_RPR         REG_ACCESS(RwReg, 0x40008100U) /**< \brief (SPI) Receive Pointer Register */
#define REG_SPI_RCR         REG_ACCESS(RwReg, 0x40008104U) /**< \brief (SPI) Receive Counter Register */
#define REG_SPI_TPR         REG_ACCESS(RwReg, 0x40008108U) /**< \brief (SPI) Transmit Pointer Register */
#define REG_SPI_TCR         REG_ACCESS(RwReg, 0x4000810CU) /**< \brief (SPI) Transmit Counter Register */
#define REG_SPI_RNPR        REG_ACCESS(RwReg, 0x40008110U) /**< \brief (SPI) Receive Next Pointer Register */
#define REG_SPI_RNCR        REG_ACCESS(RwReg, 0x40008114U) /**< \brief (SPI) Receive Next Counter Register */
#define REG_SPI_TNPR        REG_ACCESS(RwReg, 0x40008118U) /**< \brief (SPI) Transmit Next Pointer Register */
#define REG_SPI_TNCR        REG_ACCESS(RwReg, 0x4000811CU) /**< \brief (SPI) Transmit Next Counter Register */
#define REG_SPI_PTCR        REG_ACCESS(WoReg, 0x40008120U) /**< \brief (SPI) Transfer Control Register */
#define REG_SPI_PTSR        REG_ACCESS(RoReg, 0x40008124U) /**< \brief (SPI) Transfer Status Register */
/* ========== Register definition for TC0 peripheral ========== */
#define REG_TC0_CCR0        REG_ACCESS(WoReg, 0x40010000U) /**< \brief (TC0) Channel Control Register (channel = 0) */
#define REG_TC0_CMR0        REG_ACCESS(RwReg, 0x40010004U) /**< \brief (TC0) Channel Mode Register (channel = 0) */
#define REG_TC0_SMMR0       REG_ACCESS(RwReg, 0x40010008U) /**< \brief (TC0) Stepper Motor Mode Register (channel = 0) */
#define REG_TC0_CV0         REG_ACCESS(RoReg, 0x40010010U) /**< \brief (TC0) Counter Value (channel = 0) */
#define REG_TC0_RA0         REG_ACCESS(RwReg, 0x40010014U) /**< \brief (TC0) Register A (channel = 0) */
#define REG_TC0_RB0         REG_ACCESS(RwReg, 0x40010018U) /**< \brief (TC0) Register B (channel = 0) */
#define REG_TC0_RC0         REG_ACCESS(RwReg, 0x4001001CU) /**< \brief (TC0) Register C (channel = 0) */
#define REG_TC0_SR0         REG_ACCESS(RoReg, 0x40010020U) /**< \brief (TC0) Status Register (channel = 0) */
#define REG_TC0_IER0        REG_ACCESS(WoReg, 0x40010024U) /**< \brief (TC0) Interrupt Enable Register (channel = 0) */
#define REG_TC0_IDR0        REG_ACCESS(WoReg, 0x40010028U) /**< \brief (TC0) Interrupt Disable Register (channel = 0) */
#define REG_TC0_IMR0        REG_ACCESS(RoReg, 0x4001002CU) /**< \brief (TC0) Interrupt Mask Register (channel = 0) */
#define REG_TC0_CCR1        REG_ACCESS(WoReg, 0x40010040U) /**< \brief (TC0) Channel Control Register (channel = 1) */
#define REG_TC0_CMR1        REG_ACCESS(RwReg, 0x40010044U) /**< \brief (TC0) Channel Mode Register (channel = 1) */
#define REG_TC0_SMMR1       REG_ACCESS(RwReg, 0x40010048U) /**< \brief (TC0) Stepper Motor Mode Register (channel = 1) */
#define REG_TC0_CV1         REG_ACCESS(RoReg, 0x40010050U) /**< \brief (TC0) Counter Value (channel = 1) */
#define REG_TC0_RA1         REG_ACCESS(RwReg, 0x40010054U) /**< \brief (TC0) Register A (channel = 1) */
#define REG_TC0_RB1         REG_ACCESS(RwReg, 0x40010058U) /**< \brief (TC0) Register B (channel = 1) */
#define REG_TC0_RC1         REG_ACCESS(RwReg, 0x4001005CU) /**< \brief (TC0) Register C (channel = 1) */
#define REG_TC0_SR1         REG_ACCESS(RoReg, 0x40010060U) /**< \brief (TC0) Status Register (channel = 1) */
#define REG_TC0_IER1        REG_ACCESS(WoReg, 0x40010064U) /**< \brief (TC0) Interrupt Enable Register (channel = 1) */
#define REG_TC0_IDR1        REG_ACCESS(WoReg, 0x40010068U) /**< \brief (TC0) Interrupt Disable Register (channel = 1) */
#define REG_TC0_IMR1        REG_ACCESS(RoReg, 0x4001006CU) /**< \brief (TC0) Interrupt Mask Register (channel = 1) */
#define REG_TC0_CCR2        REG_ACCESS(WoReg, 0x40010080U) /**< \brief (TC0) Channel Control Register (channel = 2) */
#define REG_TC0_CMR2        REG_ACCESS(RwReg, 0x40010084U) /**< \brief (TC0) Channel Mode Register (channel = 2) */
#define REG_TC0_SMMR2       REG_ACCESS(RwReg, 0x40010088U) /**< \brief (TC0) Stepper Motor Mode Register (channel = 2) */
#define REG_TC0_CV2         REG_ACCESS(RoReg, 0x40010090U) /**< \brief (TC0) Counter Value (channel = 2) */
#define REG_TC0_RA2         REG_ACCESS(RwReg, 0x40010094U) /**< \brief (TC0) Register A (channel = 2) */
#define REG_TC0_RB2         REG_ACCESS(RwReg, 0x40010098U) /**< \brief (TC0) Register B (channel = 2) */
#define REG_TC0_RC2         REG_ACCESS(RwReg, 0x4001009CU) /**< \brief (TC0) Register C (channel = 2) */
#define REG_TC0_SR2         REG_ACCESS(RoReg, 0x400100A0U) /**< \brief (TC0) Status Register (channel = 2) */
#define REG_TC0_IER2        REG_ACCESS(WoReg, 0x400100A4U) /**< \brief (TC0) Interrupt Enable Register (channel = 2) */
#define REG_TC0_IDR2        REG_ACCESS(WoReg, 0x400100A8U) /**< \brief (TC0) Interrupt Disable Register (channel = 2) */
#define REG_TC0_IMR2        REG_ACCESS(RoReg, 0x400100ACU) /**< \brief (TC0) Interrupt Mask Register (channel = 2) */
#define REG_TC0_BCR         REG_ACCESS(WoReg, 0x400100C0U) /**< \brief (TC0) Block Control Register */
#define REG_TC0_BMR         REG_ACCESS(RwReg, 0x400100C4U) /**< \brief (TC0) Block Mode Register */
#define REG_TC0_QIER        REG_ACCESS(WoReg, 0x400100C8U) /**< \brief (TC0) QDEC Interrupt Enable Register */
#define REG_TC0_QIDR        REG_ACCESS(WoReg, 0x400100CCU) /**< \brief (TC0) QDEC Interrupt Disable Register */
#define REG_TC0_QIMR        REG_ACCESS(RoReg, 0x400100D0U) /**< \brief (TC0) QDEC Interrupt Mask Register */
#define REG_TC0_QISR        REG_ACCESS(RoReg, 0x400100D4U) /**< \brief (TC0) QDEC Interrupt Status Register */
#define REG_TC0_FMR         REG_ACCESS(RwReg, 0x400100D8U) /**< \brief (TC0) Fault Mode Register */
#define REG_TC0_WPMR        REG_ACCESS(RwReg, 0x400100E4U) /**< \brief (TC0) Write Protect Mode Register */
/* ========== Register definition for TC1 peripheral ========== */
#define REG_TC1_CCR0        REG_ACCESS(WoReg, 0x40014000U) /**< \brief (TC1) Channel Control Register (channel = 0) */
#define REG_TC1_CMR0        REG_ACCESS(RwReg, 0x40014004U) /**< \brief (TC1) Channel Mode Register (channel = 0) */
#define REG_TC1_SMMR0       REG_ACCESS(RwReg, 0x40014008U) /**< \brief (TC1) Stepper Motor Mode Register (channel = 0) */
#define REG_TC1_CV0         REG_ACCESS(RoReg, 0x40014010U) /**< \brief (TC1) Counter Value (channel = 0) */
#define REG_TC1_RA0         REG_ACCESS(RwReg, 0x40014014U) /**< \brief (TC1) Register A (channel = 0) */
#define REG_TC1_RB0         REG_ACCESS(RwReg, 0x40014018U) /**< \brief (TC1) Register B (channel = 0) */
#define REG_TC1_RC0         REG_ACCESS(RwReg, 0x4001401CU) /**< \brief (TC1) Register C (channel = 0) */
#define REG_TC1_SR0         REG_ACCESS(RoReg, 0x40014020U) /**< \brief (TC1) Status Register (channel = 0) */
#define REG_TC1_IER0        REG_ACCESS(WoReg, 0x40014024U) /**< \brief (TC1) Interrupt Enable Register (channel = 0) */
#define REG_TC1_IDR0        REG_ACCESS(WoReg, 0x40014028U) /**< \brief (TC1) Interrupt Disable Register (channel = 0) */
#define REG_TC1_IMR0        REG_ACCESS(RoReg, 0x4001402CU) /**< \brief (TC1) Interrupt Mask Register (channel = 0) */
#define REG_TC1_CCR1        REG_ACCESS(WoReg, 0x40014040U) /**< \brief (TC1) Channel Control Register (channel = 1) */
#define REG_TC1_CMR1        REG_ACCESS(RwReg, 0x40014044U) /**< \brief (TC1) Channel Mode Register (channel = 1) */
#define REG_TC1_SMMR1       REG_ACCESS(RwReg, 0x40014048U) /**< \brief (TC1) Stepper Motor Mode Register (channel = 1) */
#define REG_TC1_CV1         REG_ACCESS(RoReg, 0x40014050U) /**< \brief (TC1) Counter Value (channel = 1) */
#define REG_TC1_RA1         REG_ACCESS(RwReg, 0x40014054U) /**< \brief (TC1) Register A (channel = 1) */
#define REG_TC1_RB1         REG_ACCESS(RwReg, 0x40014058U) /**< \brief (TC1) Register B (channel = 1) */
#define REG_TC1_RC1         REG_ACCESS(RwReg, 0x4001405CU) /**< \brief (TC1) Register C (channel = 1) */
#define REG_TC1_SR1         REG_ACCESS(RoReg, 0x40014060U) /**< \brief (TC1) Status Register (channel = 1) */
#define REG_TC1_IER1        REG_ACCESS(WoReg, 0x40014064U) /**< \brief (TC1) Interrupt Enable Register (channel = 1) */
#define REG_TC1_IDR1        REG_ACCESS(WoReg, 0x40014068U) /**< \brief (TC1) Interrupt Disable Register (channel = 1) */
#define REG_TC1_IMR1        REG_ACCESS(RoReg, 0x4001406CU) /**< \brief (TC1) Interrupt Mask Register (channel = 1) */
#define REG_TC1_CCR2        REG_ACCESS(WoReg, 0x40014080U) /**< \brief (TC1) Channel Control Register (channel = 2) */
#define REG_TC1_CMR2        REG_ACCESS(RwReg, 0x40014084U) /**< \brief (TC1) Channel Mode Register (channel = 2) */
#define REG_TC1_SMMR2       REG_ACCESS(RwReg, 0x40014088U) /**< \brief (TC1) Stepper Motor Mode Register (channel = 2) */
#define REG_TC1_CV2         REG_ACCESS(RoReg, 0x40014090U) /**< \brief (TC1) Counter Value (channel = 2) */
#define REG_TC1_RA2         REG_ACCESS(RwReg, 0x40014094U) /**< \brief (TC1) Register A (channel = 2) */
#define REG_TC1_RB2         REG_ACCESS(RwReg, 0x40014098U) /**< \brief (TC1) Register B (channel = 2) */
#define REG_TC1_RC2         REG_ACCESS(RwReg, 0x4001409CU) /**< \brief (TC1) Register C (channel = 2) */
#define REG_TC1_SR2         REG_ACCESS(RoReg, 0x400140A0U) /**< \brief (TC1) Status Register (channel = 2) */
#define REG_TC1_IER2        REG_ACCESS(WoReg, 0x400140A4U) /**< \brief (TC1) Interrupt Enable Register (channel = 2) */
#define REG_TC1_IDR2        REG_ACCESS(WoReg, 0x400140A8U) /**< \brief (TC1) Interrupt Disable Register (channel = 2) */
#define REG_TC1_IMR2        REG_ACCESS(RoReg, 0x400140ACU) /**< \brief (TC1) Interrupt Mask Register (channel = 2) */
#define REG_TC1_BCR         REG_ACCESS(WoReg, 0x400140C0U) /**< \brief (TC1) Block Control Register */
#define REG_TC1_BMR         REG_ACCESS(RwReg, 0x400140C4U) /**< \brief (TC1) Block Mode Register */
#define REG_TC1_QIER        REG_ACCESS(WoReg, 0x400140C8U) /**< \brief (TC1) QDEC Interrupt Enable Register */
#define REG_TC1_QIDR        REG_ACCESS(WoReg, 0x400140CCU) /**< \brief (TC1) QDEC Interrupt Disable Register */
#define REG_TC1_QIMR        REG_ACCESS(RoReg, 0x400140D0U) /**< \brief (TC1) QDEC Interrupt Mask Register */
#define REG_TC1_QISR        REG_ACCESS(RoReg, 0x400140D4U) /**< \brief (TC1) QDEC Interrupt Status Register */
#define REG_TC1_FMR         REG_ACCESS(RwReg, 0x400140D8U) /**< \brief (TC1) Fault Mode Register */
#define REG_TC1_WPMR        REG_ACCESS(RwReg, 0x400140E4U) /**< \brief (TC1) Write Protect Mode Register */
/* ========== Register definition for TWI0 peripheral ========== */
#define REG_TWI0_CR         REG_ACCESS(WoReg, 0x40018000U) /**< \brief (TWI0) Control Register */
#define REG_TWI0_MMR        REG_ACCESS(RwReg, 0x40018004U) /**< \brief (TWI0) Master Mode Register */
#define REG_TWI0_SMR        REG_ACCESS(RwReg, 0x40018008U) /**< \brief (TWI0) Slave Mode Register */
#define REG_TWI0_IADR       REG_ACCESS(RwReg, 0x4001800CU) /**< \brief (TWI0) Internal Address Register */
#define REG_TWI0_CWGR       REG_ACCESS(RwReg, 0x40018010U) /**< \brief (TWI0) Clock Waveform Generator Register */
#define REG_TWI0_SR         REG_ACCESS(RoReg, 0x40018020U) /**< \brief (TWI0) Status Register */
#define REG_TWI0_IER        REG_ACCESS(WoReg, 0x40018024U) /**< \brief (TWI0) Interrupt Enable Register */
#define REG_TWI0_IDR        REG_ACCESS(WoReg, 0x40018028U) /**< \brief (TWI0) Interrupt Disable Register */
#define REG_TWI0_IMR        REG_ACCESS(RoReg, 0x4001802CU) /**< \brief (TWI0) Interrupt Mask Register */
#define REG_TWI0_RHR        REG_ACCESS(RoReg, 0x40018030U) /**< \brief (TWI0) Receive Holding Register */
#define REG_TWI0_THR        REG_ACCESS(WoReg, 0x40018034U) /**< \brief (TWI0) Transmit Holding Register */
#define REG_TWI0_RPR        REG_ACCESS(RwReg, 0x40018100U) /**< \brief (TWI0) Receive Pointer Register */
#define REG_TWI0_RCR        REG_ACCESS(RwReg, 0x40018104U) /**< \brief (TWI0) Receive Counter Register */
#define REG_TWI0_TPR        REG_ACCESS(RwReg, 0x40018108U) /**< \brief (TWI0) Transmit Pointer Register */
#define REG_TWI0_TCR        REG_ACCESS(RwReg, 0x4001810CU) /**< \brief (TWI0) Transmit Counter Register */
#define REG_TWI0_RNPR       REG_ACCESS(RwReg, 0x40018110U) /**< \brief (TWI0) Receive Next Pointer Register */
#define REG_TWI0_RNCR       REG_ACCESS(RwReg, 0x40018114U) /**< \brief (TWI0) Receive Next Counter Register */
#define REG_TWI0_TNPR       REG_ACCESS(RwReg, 0x40018118U) /**< \brief (TWI0) Transmit Next Pointer Register */
#define REG_TWI0_TNCR       REG_ACCESS(RwReg, 0x4001811CU) /**< \brief (TWI0) Transmit Next Counter Register */
#define REG_TWI0_PTCR       REG_ACCESS(WoReg, 0x40018120U) /**< \brief (TWI0) Transfer Control Register */
#define REG_TWI0_PTSR       REG_ACCESS(RoReg, 0x40018124U) /**< \brief (TWI0) Transfer Status Register */
/* ========== Register definition for TWI1 peripheral ========== */
#define REG_TWI1_CR         REG_ACCESS(WoReg, 0x4001C000U) /**< \brief (TWI1) Control Register */
#define REG_TWI1_MMR        REG_ACCESS(RwReg, 0x4001C004U) /**< \brief (TWI1) Master Mode Register */
#define REG_TWI1_SMR        REG_ACCESS(RwReg, 0x4001C008U) /**< \brief (TWI1) Slave Mode Register */
#define REG_TWI1_IADR       REG_ACCESS(RwReg, 0x4001C00CU) /**< \brief (TWI1) Internal Address Register */
#define REG_TWI1_CWGR       REG_ACCESS(RwReg, 0x4001C010U) /**< \brief (TWI1) Clock Waveform Generator Register */
#define REG_TWI1_SR         REG_ACCESS(RoReg, 0x4001C020U) /**< \brief (TWI1) Status Register */
#define REG_TWI1_IER        REG_ACCESS(WoReg, 0x4001C024U) /**< \brief (TWI1) Interrupt Enable Register */
#define REG_TWI1_IDR        REG_ACCESS(WoReg, 0x4001C028U) /**< \brief (TWI1) Interrupt Disable Register */
#define REG_TWI1_IMR        REG_ACCESS(RoReg, 0x4001C02CU) /**< \brief (TWI1) Interrupt Mask Register */
#define REG_TWI1_RHR        REG_ACCESS(RoReg, 0x4001C030U) /**< \brief (TWI1) Receive Holding Register */
#define REG_TWI1_THR        REG_ACCESS(WoReg, 0x4001C034U) /**< \brief (TWI1) Transmit Holding Register */
#define REG_TWI1_RPR        REG_ACCESS(RwReg, 0x4001C100U) /**< \brief (TWI1) Receive Pointer Register */
#define REG_TWI1_RCR        REG_ACCESS(RwReg, 0x4001C104U) /**< \brief (TWI1) Receive Counter Register */
#define REG_TWI1_TPR        REG_ACCESS(RwReg, 0x4001C108U) /**< \brief (TWI1) Transmit Pointer Register */
#define REG_TWI1_TCR        REG_ACCESS(RwReg, 0x4001C10CU) /**< \brief (TWI1) Transmit Counter Register */
#define REG_TWI1_RNPR       REG_ACCESS(RwReg, 0x4001C110U) /**< \brief (TWI1) Receive Next Pointer Register */
#define REG_TWI1_RNCR       REG_ACCESS(RwReg, 0x4001C114U) /**< \brief (TWI1) Receive Next Counter Register */
#define REG_TWI1_TNPR       REG_ACCESS(RwReg, 0x4001C118U) /**< \brief (TWI1) Transmit Next Pointer Register */
#define REG_TWI1_TNCR       REG_ACCESS(RwReg, 0x4001C11CU) /**< \brief (TWI1) Transmit Next Counter Register */
#define REG_TWI1_PTCR       REG_ACCESS(WoReg, 0x4001C120U) /**< \brief (TWI1) Transfer Control Register */
#define REG_TWI1_PTSR       REG_ACCESS(RoReg, 0x4001C124U) /**< \brief (TWI1) Transfer Status Register */
/* ========== Register definition for PWM peripheral ========== */
#define REG_PWM_CLK         REG_ACCESS(RwReg, 0x40020000U) /**< \brief (PWM) PWM Clock Register */
#define REG_PWM_ENA         REG_ACCESS(WoReg, 0x40020004U) /**< \brief (PWM) PWM Enable Register */
#define REG_PWM_DIS         REG_ACCESS(WoReg, 0x40020008U) /**< \brief (PWM) PWM Disable Register */
#define REG_PWM_SR          REG_ACCESS(RoReg, 0x4002000CU) /**< \brief (PWM) PWM Status Register */
#define REG_PWM_IER1        REG_ACCESS(WoReg, 0x40020010U) /**< \brief (PWM) PWM Interrupt Enable Register 1 */
#define REG_PWM_IDR1        REG_ACCESS(WoReg, 0x40020014U) /**< \brief (PWM) PWM Interrupt Disable Register 1 */
#define REG_PWM_IMR1        REG_ACCESS(RoReg, 0x40020018U) /**< \brief (PWM) PWM Interrupt Mask Register 1 */
#define REG_PWM_ISR1        REG_ACCESS(RoReg, 0x4002001CU) /**< \brief (PWM) PWM Interrupt Status Register 1 */
#define REG_PWM_SCM         REG_ACCESS(RwReg, 0x40020020U) /**< \brief (PWM) PWM Sync Channels Mode Register */
#define REG_PWM_SCUC        REG_ACCESS(RwReg, 0x40020028U) /**< \brief (PWM) PWM Sync Channels Update Control Register */
#define REG_PWM_SCUP        REG_ACCESS(RwReg, 0x4002002CU) /**< \brief (PWM) PWM Sync Channels Update Period Register */
#define REG_PWM_SCUPUPD     REG_ACCESS(WoReg, 0x40020030U) /**< \brief (PWM) PWM Sync Channels Update Period Update Register */
#define REG_PWM_IER2        REG_ACCESS(WoReg, 0x40020034U) /**< \brief (PWM) PWM Interrupt Enable Register 2 */
#define REG_PWM_IDR2        REG_ACCESS(WoReg, 0x40020038U) /**< \brief (PWM) PWM Interrupt Disable Register 2 */
#define REG_PWM_IMR2        REG_ACCESS(RoReg, 0x4002003CU) /**< \brief (PWM) PWM Interrupt Mask Register 2 */
#define REG_PWM_ISR2        REG_ACCESS(RoReg, 0x40020040U) /**< \brief (PWM) PWM Interrupt Status Register 2 */
#define REG_PWM_OOV         REG_ACCESS(RwReg, 0x40020044U) /**< \brief (PWM) PWM Output Override Value Register */
#define REG_PWM_OS          REG_ACCESS(RwReg, 0x40020048U) /**< \brief (PWM) PWM Output Selection Register */
#define REG_PWM_OSS         REG_ACCESS(WoReg, 0x4002004CU) /**< \brief (PWM) PWM Output Selection Set Register */
#define REG_PWM_OSC         REG_ACCESS(WoReg, 0x40020050U) /**< \brief (PWM) PWM Output Selection Clear Register */
#define REG_PWM_OSSUPD      REG_ACCESS(WoReg, 0x40020054U) /**< \brief (PWM) PWM Output Selection Set Update Register */
#define REG_PWM_OSCUPD      REG_ACCESS(WoReg, 0x40020058U) /**< \brief (PWM) PWM Output Selection Clear Update Register */
#define REG_PWM_FMR         REG_ACCESS(RwReg, 0x4002005CU) /**< \brief (PWM) PWM Fault Mode Register */
#define REG_PWM_FSR         REG_ACCESS(RoReg, 0x40020060U) /**< \brief (PWM) PWM Fault Status Register */
#define REG_PWM_FCR         REG_ACCESS(WoReg, 0x40020064U) /**< \brief (PWM) PWM Fault Clear Register */
#define REG_PWM_FPV         REG_ACCESS(RwReg, 0x40020068U) /**< \brief (PWM) PWM Fault Protection Value Register */
#define REG_PWM_FPE         REG_ACCESS(RwReg, 0x4002006CU) /**< \brief (PWM) PWM Fault Protection Enable Register */
#define REG_PWM_ELMR        REG_ACCESS(RwReg, 0x4002007CU) /**< \brief (PWM) PWM Event Line 0 Mode Register */
#define REG_PWM_SMMR        REG_ACCESS(RwReg, 0x400200B0U) /**< \brief (PWM) PWM Stepper Motor Mode Register */
#define REG_PWM_WPCR        REG_ACCESS(WoReg, 0x400200E4U) /**< \brief (PWM) PWM Write Protect Control Register */
#define REG_PWM_WPSR        REG_ACCESS(RoReg, 0x400200E8U) /**< \brief (PWM) PWM Write Protect Status Register */
#define REG_PWM_RPR         REG_ACCESS(RwReg, 0x40020100U) /**< \brief (PWM) Receive Pointer Register */
#define REG_PWM_RCR         REG_ACCESS(RwReg, 0x40020104U) /**< \brief (PWM) Receive Counter Register */
#define REG_PWM_TPR         REG_ACCESS(RwReg, 0x40020108U) /**< \brief (PWM) Transmit Pointer Register */
#define REG_PWM_TCR         REG_ACCESS(RwReg, 0x4002010CU) /**< \brief (PWM) Transmit Counter Register */
#define REG_PWM_RNPR        REG_ACCESS(RwReg, 0x40020110U) /**< \brief (PWM) Receive Next Pointer Register */
#define REG_PWM_RNCR        REG_ACCESS(RwReg, 0x40020114U) /**< \brief (PWM) Receive Next Counter Register */
#define REG_PWM_TNPR        REG_ACCESS(RwReg, 0x40020118U) /**< \brief (PWM) Transmit Next Pointer Register */
#define REG_PWM_TNCR        REG_ACCESS(RwReg, 0x4002011CU) /**< \brief (PWM) Transmit Next Counter Register */
#define REG_PWM_PTCR        REG_ACCESS(WoReg, 0x40020120U) /**< \brief (PWM) Transfer Control Register */
#define REG_PWM_PTSR        REG_ACCESS(RoReg, 0x40020124U) /**< \brief (PWM) Transfer Status Register */
#define REG_PWM_CMPV0       REG_ACCESS(RwReg, 0x40020130U) /**< \brief (PWM) PWM Comparison 0 Value Register */
#define REG_PWM_CMPVUPD0    REG_ACCESS(WoReg, 0x40020134U) /**< \brief (PWM) PWM Comparison 0 Value Update Register */
#define REG_PWM_CMPM0       REG_ACCESS(RwReg, 0x40020138U) /**< \brief (PWM) PWM Comparison 0 Mode Register */
#define REG_PWM_CMPMUPD0    REG_ACCESS(WoReg, 0x4002013CU) /**< \brief (PWM) PWM Comparison 0 Mode Update Register */
#define REG_PWM_CMPV1       REG_ACCESS(RwReg, 0x40020140U) /**< \brief (PWM) PWM Comparison 1 Value Register */
#define REG_PWM_CMPVUPD1    REG_ACCESS(WoReg, 0x40020144U) /**< \brief (PWM) PWM Comparison 1 Value Update Register */
#define REG_PWM_CMPM1       REG_ACCESS(RwReg, 0x40020148U) /**< \brief (PWM) PWM Comparison 1 Mode Register */
#define REG_PWM_CMPMUPD1    REG_ACCESS(WoReg, 0x4002014CU) /**< \brief (PWM) PWM Comparison 1 Mode Update Register */
#define REG_PWM_CMPV2       REG_ACCESS(RwReg, 0x40020150U) /**< \brief (PWM) PWM Comparison 2 Value Register */
#define REG_PWM_CMPVUPD2    REG_ACCESS(WoReg, 0x40020154U) /**< \brief (PWM) PWM Comparison 2 Value Update Register */
#define REG_PWM_CMPM2       REG_ACCESS(RwReg, 0x40020158U) /**< \brief (PWM) PWM Comparison 2 Mode Register */
#define REG_PWM_CMPMUPD2    REG_ACCESS(WoReg, 0x4002015CU) /**< \brief (PWM) PWM Comparison 2 Mode Update Register */
#define REG_PWM_CMPV3       REG_ACCESS(RwReg, 0x40020160U) /**< \brief (PWM) PWM Comparison 3 Value Register */
#define REG_PWM_CMPVUPD3    REG_ACCESS(WoReg, 0x40020164U) /**< \brief (PWM) PWM Comparison 3 Value Update Register */
#define REG_PWM_CMPM3       REG_ACCESS(RwReg, 0x40020168U) /**< \brief (PWM) PWM Comparison 3 Mode Register */
#define REG_PWM_CMPMUPD3    REG_ACCESS(WoReg, 0x4002016CU) /**< \brief (PWM) PWM Comparison 3 Mode Update Register */
#define REG_PWM_CMPV4       REG_ACCESS(RwReg, 0x40020170U) /**< \brief (PWM) PWM Comparison 4 Value Register */
#define REG_PWM_CMPVUPD4    REG_ACCESS(WoReg, 0x40020174U) /**< \brief (PWM) PWM Comparison 4 Value Update Register */
#define REG_PWM_CMPM4       REG_ACCESS(RwReg, 0x40020178U) /**< \brief (PWM) PWM Comparison 4 Mode Register */
#define REG_PWM_CMPMUPD4    REG_ACCESS(WoReg, 0x4002017CU) /**< \brief (PWM) PWM Comparison 4 Mode Update Register */
#define REG_PWM_CMPV5       REG_ACCESS(RwReg, 0x40020180U) /**< \brief (PWM) PWM Comparison 5 Value Register */
#define REG_PWM_CMPVUPD5    REG_ACCESS(WoReg, 0x40020184U) /**< \brief (PWM) PWM Comparison 5 Value Update Register */
#define REG_PWM_CMPM5       REG_ACCESS(RwReg, 0x40020188U) /**< \brief (PWM) PWM Comparison 5 Mode Register */
#define REG_PWM_CMPMUPD5    REG_ACCESS(WoReg, 0x4002018CU) /**< \brief (PWM) PWM Comparison 5 Mode Update Register */
#define REG_PWM_CMPV6       REG_ACCESS(RwReg, 0x40020190U) /**< \brief (PWM) PWM Comparison 6 Value Register */
#define REG_PWM_CMPVUPD6    REG_ACCESS(WoReg, 0x40020194U) /**< \brief (PWM) PWM Comparison 6 Value Update Register */
#define REG_PWM_CMPM6       REG_ACCESS(RwReg, 0x40020198U) /**< \brief (PWM) PWM Comparison 6 Mode Register */
#define REG_PWM_CMPMUPD6    REG_ACCESS(WoReg, 0x4002019CU) /**< \brief (PWM) PWM Comparison 6 Mode Update Register */
#define REG_PWM_CMPV7       REG_ACCESS(RwReg, 0x400201A0U) /**< \brief (PWM) PWM Comparison 7 Value Register */
#define REG_PWM_CMPVUPD7    REG_ACCESS(WoReg, 0x400201A4U) /**< \brief (PWM) PWM Comparison 7 Value Update Register */
#define REG_PWM_CMPM7       REG_ACCESS(RwReg, 0x400201A8U) /**< \brief (PWM) PWM Comparison 7 Mode Register */
#define REG_PWM_CMPMUPD7    REG_ACCESS(WoReg, 0x400201ACU) /**< \brief (PWM) PWM Comparison 7 Mode Update Register */
#define REG_PWM_CMR0        REG_ACCESS(RwReg, 0x40020200U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 0) */
#define REG_PWM_CDTY0       REG_ACCESS(RwReg, 0x40020204U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 0) */
#define REG_PWM_CDTYUPD0    REG_ACCESS(WoReg, 0x40020208U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 0) */
#define REG_PWM_CPRD0       REG_ACCESS(RwReg, 0x4002020CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 0) */
#define REG_PWM_CPRDUPD0    REG_ACCESS(WoReg, 0x40020210U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 0) */
#define REG_PWM_CCNT0       REG_ACCESS(RoReg, 0x40020214U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 0) */
#define REG_PWM_DT0         REG_ACCESS(RwReg, 0x40020218U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 0) */
#define REG_PWM_DTUPD0      REG_ACCESS(WoReg, 0x4002021CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 0) */
#define REG_PWM_CMR1        REG_ACCESS(RwReg, 0x40020220U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 1) */
#define REG_PWM_CDTY1       REG_ACCESS(RwReg, 0x40020224U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 1) */
#define REG_PWM_CDTYUPD1    REG_ACCESS(WoReg, 0x40020228U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 1) */
#define REG_PWM_CPRD1       REG_ACCESS(RwReg, 0x4002022CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 1) */
#define REG_PWM_CPRDUPD1    REG_ACCESS(WoReg, 0x40020230U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 1) */
#define REG_PWM_CCNT1       REG_ACCESS(RoReg, 0x40020234U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 1) */
#define REG_PWM_DT1         REG_ACCESS(RwReg, 0x40020238U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 1) */
#define REG_PWM_DTUPD1      REG_ACCESS(WoReg, 0x4002023CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 1) */
#define REG_PWM_CMR2        REG_ACCESS(RwReg, 0x40020240U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 2) */
#define REG_PWM_CDTY2       REG_ACCESS(RwReg, 0x40020244U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 2) */
#define REG_PWM_CDTYUPD2    REG_ACCESS(WoReg, 0x40020248U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 2) */
#define REG_PWM_CPRD2       REG_ACCESS(RwReg, 0x4002024CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 2) */
#define REG_PWM_CPRDUPD2    REG_ACCESS(WoReg, 0x40020250U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 2) */
#define REG_PWM_CCNT2       REG_ACCESS(RoReg, 0x40020254U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 2) */
#define REG_PWM_DT2         REG_ACCESS(RwReg, 0x40020258U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 2) */
#define REG_PWM_DTUPD2      REG_ACCESS(WoReg, 0x4002025CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 2) */
#define REG_PWM_CMR3        REG_ACCESS(RwReg, 0x40020260U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 3) */
#define REG_PWM_CDTY3       REG_ACCESS(RwReg, 0x40020264U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 3) */
#define REG_PWM_CDTYUPD3    REG_ACCESS(WoReg, 0x40020268U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 3) */
#define REG_PWM_CPRD3       REG_ACCESS(RwReg, 0x4002026CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 3) */
#define REG_PWM_CPRDUPD3    REG_ACCESS(WoReg, 0x40020270U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 3) */
#define REG_PWM_CCNT3       REG_ACCESS(RoReg, 0x40020274U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 3) */
#define REG_PWM_DT3         REG_ACCESS(RwReg, 0x40020278U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 3) */
#define REG_PWM_DTUPD3      REG_ACCESS(WoReg, 0x4002027CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 3) */
/* ========== Register definition for USART0 peripheral ========== */
#define REG_USART0_CR       REG_ACCESS(WoReg, 0x40024000U) /**< \brief (USART0) Control Register */
#define REG_USART0_MR       REG_ACCESS(RwReg, 0x40024004U) /**< \brief (USART0) Mode Register */
#define REG_USART0_IER      REG_ACCESS(WoReg, 0x40024008U) /**< \brief (USART0) Interrupt Enable Register */
#define REG_USART0_IDR      REG_ACCESS(WoReg, 0x4002400CU) /**< \brief (USART0) Interrupt Disable Register */
#define REG_USART0_IMR      REG_ACCESS(RoReg, 0x40024010U) /**< \brief (USART0) Interrupt Mask Register */
#define REG_USART0_CSR      REG_ACCESS(RoReg, 0x40024014U) /**< \brief (USART0) Channel Status Register */
#define REG_USART0_RHR      REG_ACCESS(RoReg, 0x40024018U) /**< \brief (USART0) Receiver Holding Register */
#define REG_USART0_THR      REG_ACCESS(WoReg, 0x4002401CU) /**< \brief (USART0) Transmitter Holding Register */
#define REG_USART0_BRGR     REG_ACCESS(RwReg, 0x40024020U) /**< \brief (USART0) Baud Rate Generator Register */
#define REG_USART0_RTOR     REG_ACCESS(RwReg, 0x40024024U) /**< \brief (USART0) Receiver Time-out Register */
#define REG_USART0_TTGR     REG_ACCESS(RwReg, 0x40024028U) /**< \brief (USART0) Transmitter Timeguard Register */
#define REG_USART0_FIDI     REG_ACCESS(RwReg, 0x40024040U) /**< \brief (USART0) FI DI Ratio Register */
#define REG_USART0_NER      REG_ACCESS(RoReg, 0x40024044U) /**< \brief (USART0) Number of Errors Register */
#define REG_USART0_IF       REG_ACCESS(RwReg, 0x4002404CU) /**< \brief (USART0) IrDA Filter Register */
#define REG_USART0_MAN      REG_ACCESS(RwReg, 0x40024050U) /**< \brief (USART0) Manchester Encoder Decoder Register */
#define REG_USART0_WPMR     REG_ACCESS(RwReg, 0x400240E4U) /**< \brief (USART0) Write Protect Mode Register */
#define REG_USART0_WPSR     REG_ACCESS(RoReg, 0x400240E8U) /**< \brief (USART0) Write Protect Status Register */
#define REG_USART0_VERSION  REG_ACCESS(RoReg, 0x400240FCU) /**< \brief (USART0) Version Register */
#define REG_USART0_RPR      REG_ACCESS(RwReg, 0x40024100U) /**< \brief (USART0) Receive Pointer Register */
#define REG_USART0_RCR      REG_ACCESS(RwReg, 0x40024104U) /**< \brief (USART0) Receive Counter Register */
#define REG_USART0_TPR      REG_ACCESS(RwReg, 0x40024108U) /**< \brief (USART0) Transmit Pointer Register */
#define REG_USART0_TCR      REG_ACCESS(RwReg, 0x4002410CU) /**< \brief (USART0) Transmit Counter Register */
#define REG_USART0_RNPR     REG_ACCESS(RwReg, 0x40024110U) /**< \brief (USART0) Receive Next Pointer Register */
#define REG_USART0_RNCR     REG_ACCESS(RwReg, 0x40024114U) /**< \brief (USART0) Receive Next Counter Register */
#define REG_USART0_TNPR     REG_ACCESS(RwReg, 0x40024118U) /**< \brief (USART0) Transmit Next Pointer Register */
#define REG_USART0_TNCR     REG_ACCESS(RwReg, 0x4002411CU) /**< \brief (USART0) Transmit Next Counter Register */
#define REG_USART0_PTCR     REG_ACCESS(WoReg, 0x40024120U) /**< \brief (USART0) Transfer Control Register */
#define REG_USART0_PTSR     REG_ACCESS(RoReg, 0x40024124U) /**< \brief (USART0) Transfer Status Register */
/* ========== Register definition for USART1 peripheral ========== */
#define REG_USART1_CR       REG_ACCESS(WoReg, 0x40028000U) /**< \brief (USART1) Control Register */
#define REG_USART1_MR       REG_ACCESS(RwReg, 0x40028004U) /**< \brief (USART1) Mode Register */
#define REG_USART1_IER      REG_ACCESS(WoReg, 0x40028008U) /**< \brief (USART1) Interrupt Enable Register */
#define REG_USART1_IDR      REG_ACCESS(WoReg, 0x4002800CU) /**< \brief (USART1) Interrupt Disable Register */
#define REG_USART1_IMR      REG_ACCESS(RoReg, 0x40028010U) /**< \brief (USART1) Interrupt Mask Register */
#define REG_USART1_CSR      REG_ACCESS(RoReg, 0x40028014U) /**< \brief (USART1) Channel Status Register */
#define REG_USART1_RHR      REG_ACCESS(RoReg, 0x40028018U) /**< \brief (USART1) Receiver Holding Register */
#define REG_USART1_THR      REG_ACCESS(WoReg, 0x4002801CU) /**< \brief (USART1) Transmitter Holding Register */
#define REG_USART1_BRGR     REG_ACCESS(RwReg, 0x40028020U) /**< \brief (USART1) Baud Rate Generator Register */
#define REG_USART1_RTOR     REG_ACCESS(RwReg, 0x40028024U) /**< \brief (USART1) Receiver Time-out Register */
#define REG_USART1_TTGR     REG_ACCESS(RwReg, 0x40028028U) /**< \brief (USART1) Transmitter Timeguard Register */
#define REG_USART1_FIDI     REG_ACCESS(RwReg, 0x40028040U) /**< \brief (USART1) FI DI Ratio Register */
#define REG_USART1_NER      REG_ACCESS(RoReg, 0x40028044U) /**< \brief (USART1) Number of Errors Register */
#define REG_USART1_IF       REG_ACCESS(RwReg, 0x4002804CU) /**< \brief (USART1) IrDA Filter Register */
#define REG_USART1_MAN      REG_ACCESS(RwReg, 0x40028050U) /**< \brief (USART1) Manchester Encoder Decoder Register */
#define REG_USART1_WPMR     REG_ACCESS(RwReg, 0x400280E4U) /**< \brief (USART1) Write Protect Mode Register */
#define REG_USART1_WPSR     REG_ACCESS(RoReg, 0x400280E8U) /**< \brief (USART1) Write Protect Status Register */
#define REG_USART1_VERSION  REG_ACCESS(RoReg, 0x400280FCU) /**< \brief (USART1) Version Register */
#define REG_USART1_RPR      REG_ACCESS(RwReg, 0x40028100U) /**< \brief (USART1) Receive Pointer Register */
#define REG_USART1_RCR      REG_ACCESS(RwReg, 0x40028104U) /**< \brief (USART1) Receive Counter Register */
#define REG_USART1_TPR      REG_ACCESS(RwReg, 0x40028108U) /**< \brief (USART1) Transmit Pointer Register */
#define REG_USART1_TCR      REG_ACCESS(RwReg, 0x4002810CU) /**< \brief (USART1) Transmit Counter Register */
#define REG_USART1_RNPR     REG_ACCESS(RwReg, 0x40028110U) /**< \brief (USART1) Receive Next Pointer Register */
#define REG_USART1_RNCR     REG_ACCESS(RwReg, 0x40028114U) /**< \brief (USART1) Receive Next Counter Register */
#define REG_USART1_TNPR     REG_ACCESS(RwReg, 0x40028118U) /**< \brief (USART1) Transmit Next Pointer Register */
#define REG_USART1_TNCR     REG_ACCESS(RwReg, 0x4002811CU) /**< \brief (USART1) Transmit Next Counter Register */
#define REG_USART1_PTCR     REG_ACCESS(WoReg, 0x40028120U) /**< \brief (USART1) Transfer Control Register */
#define REG_USART1_PTSR     REG_ACCESS(RoReg, 0x40028124U) /**< \brief (USART1) Transfer Status Register */
/* ========== Register definition for UDP peripheral ========== */
#define REG_UDP_FRM_NUM     REG_ACCESS(RoReg, 0x40034000U) /**< \brief (UDP) Frame Number Register */
#define REG_UDP_GLB_STAT    REG_ACCESS(RwReg, 0x40034004U) /**< \brief (UDP) Global State Register */
#define REG_UDP_FADDR       REG_ACCESS(RwReg, 0x40034008U) /**< \brief (UDP) Function Address Register */
#define REG_UDP_IER         REG_ACCESS(WoReg, 0x40034010U) /**< \brief (UDP) Interrupt Enable Register */
#define REG_UDP_IDR         REG_ACCESS(WoReg, 0x40034014U) /**< \brief (UDP) Interrupt Disable Register */
#define REG_UDP_IMR         REG_ACCESS(RoReg, 0x40034018U) /**< \brief (UDP) Interrupt Mask Register */
#define REG_UDP_ISR         REG_ACCESS(RoReg, 0x4003401CU) /**< \brief (UDP) Interrupt Status Register */
#define REG_UDP_ICR         REG_ACCESS(WoReg, 0x40034020U) /**< \brief (UDP) Interrupt Clear Register */
#define REG_UDP_RST_EP      REG_ACCESS(RwReg, 0x40034028U) /**< \brief (UDP) Reset Endpoint Register */
#define REG_UDP_CSR         REG_ACCESS(RwReg, 0x40034030U) /**< \brief (UDP) Endpoint Control and Status Register */
#define REG_UDP_FDR         REG_ACCESS(RwReg, 0x40034050U) /**< \brief (UDP) Endpoint FIFO Data Register */
#define REG_UDP_TXVC        REG_ACCESS(RwReg, 0x40034074U) /**< \brief (UDP) Transceiver Control Register */
/* ========== Register definition for ADC peripheral ========== */
#define REG_ADC_CR          REG_ACCESS(WoReg, 0x40038000U) /**< \brief (ADC) Control Register */
#define REG_ADC_MR          REG_ACCESS(RwReg, 0x40038004U) /**< \brief (ADC) Mode Register */
#define REG_ADC_SEQR1       REG_ACCESS(RwReg, 0x40038008U) /**< \brief (ADC) Channel Sequence Register 1 */
#define REG_ADC_SEQR2       REG_ACCESS(RwReg, 0x4003800CU) /**< \brief (ADC) Channel Sequence Register 2 */
#define REG_ADC_CHER        REG_ACCESS(WoReg, 0x40038010U) /**< \brief (ADC) Channel Enable Register */
#define REG_ADC_CHDR        REG_ACCESS(WoReg, 0x40038014U) /**< \brief (ADC) Channel Disable Register */
#define REG_ADC_CHSR        REG_ACCESS(RoReg, 0x40038018U) /**< \brief (ADC) Channel Status Register */
#define REG_ADC_LCDR        REG_ACCESS(RoReg, 0x40038020U) /**< \brief (ADC) Last Converted Data Register */
#define REG_ADC_IER         REG_ACCESS(WoReg, 0x40038024U) /**< \brief (ADC) Interrupt Enable Register */
#define REG_ADC_IDR         REG_ACCESS(WoReg, 0x40038028U) /**< \brief (ADC) Interrupt Disable Register */
#define REG_ADC_IMR         REG_ACCESS(RoReg, 0x4003802CU) /**< \brief (ADC) Interrupt Mask Register */
#define REG_ADC_ISR         REG_ACCESS(RoReg, 0x40038030U) /**< \brief (ADC) Interrupt Status Register */
#define REG_ADC_OVER        REG_ACCESS(RoReg, 0x4003803CU) /**< \brief (ADC) Overrun Status Register */
#define REG_ADC_EMR         REG_ACCESS(RwReg, 0x40038040U) /**< \brief (ADC) Extended Mode Register */
#define REG_ADC_CWR         REG_ACCESS(RwReg, 0x40038044U) /**< \brief (ADC) Compare Window Register */
#define REG_ADC_CGR         REG_ACCESS(RwReg, 0x40038048U) /**< \brief (ADC) Channel Gain Register */
#define REG_ADC_COR         REG_ACCESS(RwReg, 0x4003804CU) /**< \brief (ADC) Channel Offset Register */
#define REG_ADC_CDR         REG_ACCESS(RoReg, 0x40038050U) /**< \brief (ADC) Channel Data Register */
#define REG_ADC_ACR         REG_ACCESS(RwReg, 0x40038094U) /**< \brief (ADC) Analog Control Register */
#define REG_ADC_TRGR        REG_ACCESS(RwReg, 0x400380C0U) /**< \brief (ADC) Trigger Register */
#define REG_ADC_WPMR        REG_ACCESS(RwReg, 0x400380E4U) /**< \brief (ADC) Write Protect Mode Register */
#define REG_ADC_WPSR        REG_ACCESS(RoReg, 0x400380E8U) /**< \brief (ADC) Write Protect Status Register */
#define REG_ADC_RPR         REG_ACCESS(RwReg, 0x40038100U) /**< \brief (ADC) Receive Pointer Register */
#define REG_ADC_RCR         REG_ACCESS(RwReg, 0x40038104U) /**< \brief (ADC) Receive Counter Register */
#define REG_ADC_TPR         REG_ACCESS(RwReg, 0x40038108U) /**< \brief (ADC) Transmit Pointer Register */
#define REG_ADC_TCR         REG_ACCESS(RwReg, 0x4003810CU) /**< \brief (ADC) Transmit Counter Register */
#define REG_ADC_RNPR        REG_ACCESS(RwReg, 0x40038110U) /**< \brief (ADC) Receive Next Pointer Register */
#define REG_ADC_RNCR        REG_ACCESS(RwReg, 0x40038114U) /**< \brief (ADC) Receive Next Counter Register */
#define REG_ADC_TNPR        REG_ACCESS(RwReg, 0x40038118U) /**< \brief (ADC) Transmit Next Pointer Register */
#define REG_ADC_TNCR        REG_ACCESS(RwReg, 0x4003811CU) /**< \brief (ADC) Transmit Next Counter Register */
#define REG_ADC_PTCR        REG_ACCESS(WoReg, 0x40038120U) /**< \brief (ADC) Transfer Control Register */
#define REG_ADC_PTSR        REG_ACCESS(RoReg, 0x40038124U) /**< \brief (ADC) Transfer Status Register */
/* ========== Register definition for DACC peripheral ========== */
#define REG_DACC_CR         REG_ACCESS(WoReg, 0x4003C000U) /**< \brief (DACC) Control Register */
#define REG_DACC_MR         REG_ACCESS(RwReg, 0x4003C004U) /**< \brief (DACC) Mode Register */
#define REG_DACC_CHER       REG_ACCESS(WoReg, 0x4003C010U) /**< \brief (DACC) Channel Enable Register */
#define REG_DACC_CHDR       REG_ACCESS(WoReg, 0x4003C014U) /**< \brief (DACC) Channel Disable Register */
#define REG_DACC_CHSR       REG_ACCESS(RoReg, 0x4003C018U) /**< \brief (DACC) Channel Status Register */
#define REG_DACC_CDR        REG_ACCESS(WoReg, 0x4003C020U) /**< \brief (DACC) Conversion Data Register */
#define REG_DACC_IER        REG_ACCESS(WoReg, 0x4003C024U) /**< \brief (DACC) Interrupt Enable Register */
#define REG_DACC_IDR        REG_ACCESS(WoReg, 0x4003C028U) /**< \brief (DACC) Interrupt Disable Register */
#define REG_DACC_IMR        REG_ACCESS(RoReg, 0x4003C02CU) /**< \brief (DACC) Interrupt Mask Register */
#define REG_DACC_ISR        REG_ACCESS(RoReg, 0x4003C030U) /**< \brief (DACC) Interrupt Status Register */
#define REG_DACC_ACR        REG_ACCESS(RwReg, 0x4003C094U) /**< \brief (DACC) Analog Current Register */
#define REG_DACC_WPMR       REG_ACCESS(RwReg, 0x4003C0E4U) /**< \brief (DACC) Write Protect Mode register */
#define REG_DACC_WPSR       REG_ACCESS(RoReg, 0x4003C0E8U) /**< \brief (DACC) Write Protect Status register */
#define REG_DACC_RPR        REG_ACCESS(RwReg, 0x4003C100U) /**< \brief (DACC) Receive Pointer Register */
#define REG_DACC_RCR        REG_ACCESS(RwReg, 0x4003C104U) /**< \brief (DACC) Receive Counter Register */
#define REG_DACC_TPR        REG_ACCESS(RwReg, 0x4003C108U) /**< \brief (DACC) Transmit Pointer Register */
#define REG_DACC_TCR        REG_ACCESS(RwReg, 0x4003C10CU) /**< \brief (DACC) Transmit Counter Register */
#define REG_DACC_RNPR       REG_ACCESS(RwReg, 0x4003C110U) /**< \brief (DACC) Receive Next Pointer Register */
#define REG_DACC_RNCR       REG_ACCESS(RwReg, 0x4003C114U) /**< \brief (DACC) Receive Next Counter Register */
#define REG_DACC_TNPR       REG_ACCESS(RwReg, 0x4003C118U) /**< \brief (DACC) Transmit Next Pointer Register */
#define REG_DACC_TNCR       REG_ACCESS(RwReg, 0x4003C11CU) /**< \brief (DACC) Transmit Next Counter Register */
#define REG_DACC_PTCR       REG_ACCESS(WoReg, 0x4003C120U) /**< \brief (DACC) Transfer Control Register */
#define REG_DACC_PTSR       REG_ACCESS(RoReg, 0x4003C124U) /**< \brief (DACC) Transfer Status Register */
/* ========== Register definition for ACC peripheral ========== */
#define REG_ACC_CR          REG_ACCESS(WoReg, 0x40040000U) /**< \brief (ACC) Control Register */
#define REG_ACC_MR          REG_ACCESS(RwReg, 0x40040004U) /**< \brief (ACC) Mode Register */
#define REG_ACC_IER         REG_ACCESS(WoReg, 0x40040024U) /**< \brief (ACC) Interrupt Enable Register */
#define REG_ACC_IDR         REG_ACCESS(WoReg, 0x40040028U) /**< \brief (ACC) Interrupt Disable Register */
#define REG_ACC_IMR         REG_ACCESS(RoReg, 0x4004002CU) /**< \brief (ACC) Interrupt Mask Register */
#define REG_ACC_ISR         REG_ACCESS(RoReg, 0x40040030U) /**< \brief (ACC) Interrupt Status Register */
#define REG_ACC_ACR         REG_ACCESS(RwReg, 0x40040094U) /**< \brief (ACC) Analog Control Register */
#define REG_ACC_WPMR        REG_ACCESS(RwReg, 0x400400E4U) /**< \brief (ACC) Write Protect Mode Register */
#define REG_ACC_WPSR        REG_ACCESS(RoReg, 0x400400E8U) /**< \brief (ACC) Write Protect Status Register */
/* ========== Register definition for CRCCU peripheral ========== */
#define REG_CRCCU_DSCR      REG_ACCESS(RwReg, 0x40044000U) /**< \brief (CRCCU) CRCCU Descriptor Base Register */
#define REG_CRCCU_DMA_EN    REG_ACCESS(WoReg, 0x40044008U) /**< \brief (CRCCU) CRCCU DMA Enable Register */
#define REG_CRCCU_DMA_DIS   REG_ACCESS(WoReg, 0x4004400CU) /**< \brief (CRCCU) CRCCU DMA Disable Register */
#define REG_CRCCU_DMA_SR    REG_ACCESS(RoReg, 0x40044010U) /**< \brief (CRCCU) CRCCU DMA Status Register */
#define REG_CRCCU_DMA_IER   REG_ACCESS(WoReg, 0x40044014U) /**< \brief (CRCCU) CRCCU DMA Interrupt Enable Register */
#define REG_CRCCU_DMA_IDR   REG_ACCESS(WoReg, 0x40044018U) /**< \brief (CRCCU) CRCCU DMA Interrupt Disable Register */
#define REG_CRCCU_DMA_IMR   REG_ACCESS(RoReg, 0x4004401CU) /**< \brief (CRCCU) CRCCU DMA Interrupt Mask Register */
#define REG_CRCCU_DMA_ISR   REG_ACCESS(RoReg, 0x40044020U) /**< \brief (CRCCU) CRCCU DMA Interrupt Status Register */
#define REG_CRCCU_CR        REG_ACCESS(WoReg, 0x40044034U) /**< \brief (CRCCU) CRCCU Control Register */
#define REG_CRCCU_MR        REG_ACCESS(RwReg, 0x40044038U) /**< \brief (CRCCU) CRCCU Mode Register */
#define REG_CRCCU_SR        REG_ACCESS(RoReg, 0x4004403CU) /**< \brief (CRCCU) CRCCU Status Register */
#define REG_CRCCU_IER       REG_ACCESS(WoReg, 0x40044040U) /**< \brief (CRCCU) CRCCU Interrupt Enable Register */
#define REG_CRCCU_IDR       REG_ACCESS(WoReg, 0x40044044U) /**< \brief (CRCCU) CRCCU Interrupt Disable Register */
#define REG_CRCCU_IMR       REG_ACCESS(RoReg, 0x40044048U) /**< \brief (CRCCU) CRCCU Interrupt Mask Register */
#define REG_CRCCU_ISR       REG_ACCESS(RoReg, 0x4004404CU) /**< \brief (CRCCU) CRCCU Interrupt Status Register */
/* ========== Register definition for SMC peripheral ========== */
#define REG_SMC_SETUP0      REG_ACCESS(RwReg, 0x400E0000U) /**< \brief (SMC) SMC Setup Register (CS_number = 0) */
#define REG_SMC_PULSE0      REG_ACCESS(RwReg, 0x400E0004U) /**< \brief (SMC) SMC Pulse Register (CS_number = 0) */
#define REG_SMC_CYCLE0      REG_ACCESS(RwReg, 0x400E0008U) /**< \brief (SMC) SMC Cycle Register (CS_number = 0) */
#define REG_SMC_MODE0       REG_ACCESS(RwReg, 0x400E000CU) /**< \brief (SMC) SMC Mode Register (CS_number = 0) */
#define REG_SMC_SETUP1      REG_ACCESS(RwReg, 0x400E0010U) /**< \brief (SMC) SMC Setup Register (CS_number = 1) */
#define REG_SMC_PULSE1      REG_ACCESS(RwReg, 0x400E0014U) /**< \brief (SMC) SMC Pulse Register (CS_number = 1) */
#define REG_SMC_CYCLE1      REG_ACCESS(RwReg, 0x400E0018U) /**< \brief (SMC) SMC Cycle Register (CS_number = 1) */
#define REG_SMC_MODE1       REG_ACCESS(RwReg, 0x400E001CU) /**< \brief (SMC) SMC Mode Register (CS_number = 1) */
#define REG_SMC_SETUP2      REG_ACCESS(RwReg, 0x400E0020U) /**< \brief (SMC) SMC Setup Register (CS_number = 2) */
#define REG_SMC_PULSE2      REG_ACCESS(RwReg, 0x400E0024U) /**< \brief (SMC) SMC Pulse Register (CS_number = 2) */
#define REG_SMC_CYCLE2      REG_ACCESS(RwReg, 0x400E0028U) /**< \brief (SMC) SMC Cycle Register (CS_number = 2) */
#define REG_SMC_MODE2       REG_ACCESS(RwReg, 0x400E002CU) /**< \brief (SMC) SMC Mode Register (CS_number = 2) */
#define REG_SMC_SETUP3      REG_ACCESS(RwReg, 0x400E0030U) /**< \brief (SMC) SMC Setup Register (CS_number = 3) */
#define REG_SMC_PULSE3      REG_ACCESS(RwReg, 0x400E0034U) /**< \brief (SMC) SMC Pulse Register (CS_number = 3) */
#define REG_SMC_CYCLE3      REG_ACCESS(RwReg, 0x400E0038U) /**< \brief (SMC) SMC Cycle Register (CS_number = 3) */
#define REG_SMC_MODE3       REG_ACCESS(RwReg, 0x400E003CU) /**< \brief (SMC) SMC Mode Register (CS_number = 3) */
#define REG_SMC_SETUP4      REG_ACCESS(RwReg, 0x400E0040U) /**< \brief (SMC) SMC Setup Register (CS_number = 4) */
#define REG_SMC_PULSE4      REG_ACCESS(RwReg, 0x400E0044U) /**< \brief (SMC) SMC Pulse Register (CS_number = 4) */
#define REG_SMC_CYCLE4      REG_ACCESS(RwReg, 0x400E0048U) /**< \brief (SMC) SMC Cycle Register (CS_number = 4) */
#define REG_SMC_MODE4       REG_ACCESS(RwReg, 0x400E004CU) /**< \brief (SMC) SMC Mode Register (CS_number = 4) */
#define REG_SMC_OCMS        REG_ACCESS(RwReg, 0x400E0080U) /**< \brief (SMC) SMC OCMS MODE Register */
#define REG_SMC_KEY1        REG_ACCESS(WoReg, 0x400E0084U) /**< \brief (SMC) SMC OCMS KEY1 Register */
#define REG_SMC_KEY2        REG_ACCESS(WoReg, 0x400E0088U) /**< \brief (SMC) SMC OCMS KEY2 Register */
#define REG_SMC_WPMR        REG_ACCESS(RwReg, 0x400E00E4U) /**< \brief (SMC) SMC Write Protect Mode Register */
#define REG_SMC_WPSR        REG_ACCESS(RoReg, 0x400E00E8U) /**< \brief (SMC) SMC Write Protect Status Register */
/* ========== Register definition for MATRIX peripheral ========== */
#define REG_MATRIX_MCFG     REG_ACCESS(RwReg, 0x400E0200U) /**< \brief (MATRIX) Master Configuration Register */
#define REG_MATRIX_SCFG     REG_ACCESS(RwReg, 0x400E0240U) /**< \brief (MATRIX) Slave Configuration Register */
#define REG_MATRIX_PRAS0    REG_ACCESS(RwReg, 0x400E0280U) /**< \brief (MATRIX) Priority Register A for Slave 0 */
#define REG_MATRIX_PRAS1    REG_ACCESS(RwReg, 0x400E0288U) /**< \brief (MATRIX) Priority Register A for Slave 1 */
#define REG_MATRIX_PRAS2    REG_ACCESS(RwReg, 0x400E0290U) /**< \brief (MATRIX) Priority Register A for Slave 2 */
#define REG_MATRIX_PRAS3    REG_ACCESS(RwReg, 0x400E0298U) /**< \brief (MATRIX) Priority Register A for Slave 3 */
#define REG_MATRIX_PRAS4    REG_ACCESS(RwReg, 0x400E02A0U) /**< \brief (MATRIX) Priority Register A for Slave 4 */
#define REG_CCFG_SYSIO      REG_ACCESS(RwReg, 0x400E0314U) /**< \brief (MATRIX) System I/O Configuration register */
#define REG_CCFG_SMCNFCS    REG_ACCESS(RwReg, 0x400E031CU) /**< \brief (MATRIX) SMC Chip Select NAND Flash Assignment Register */
#define REG_MATRIX_WPMR     REG_ACCESS(RwReg, 0x400E03E4U) /**< \brief (MATRIX) Write Protect Mode Register */
#define REG_MATRIX_WPSR     REG_ACCESS(RoReg, 0x400E03E8U) /**< \brief (MATRIX) Write Protect Status Register */
/* ========== Register definition for PMC peripheral ========== */
#define REG_PMC_SCER        REG_ACCESS(WoReg, 0x400E0400U) /**< \brief (PMC) System Clock Enable Register */
#define REG_PMC_SCDR        REG_ACCESS(WoReg, 0x400E0404U) /**< \brief (PMC) System Clock Disable Register */
#define REG_PMC_SCSR        REG_ACCESS(RoReg, 0x400E0408U) /**< \brief (PMC) System Clock Status Register */
#define REG_PMC_PCER0       REG_ACCESS(WoReg, 0x400E0410U) /**< \brief (PMC) Peripheral Clock Enable Register 0 */
#define REG_PMC_PCDR0       REG_ACCESS(WoReg, 0x400E0414U) /**< \brief (PMC) Peripheral Clock Disable Register 0 */
#define REG_PMC_PCSR0       REG_ACCESS(RoReg, 0x400E0418U) /**< \brief (PMC) Peripheral Clock Status Register 0 */
#define REG_CKGR_MOR        REG_ACCESS(RwReg, 0x400E0420U) /**< \brief (PMC) Main Oscillator Register */
#define REG_CKGR_MCFR       REG_ACCESS(RoReg, 0x400E0424U) /**< \brief (PMC) Main Clock Frequency Register */
#define REG_CKGR_PLLAR      REG_ACCESS(RwReg, 0x400E0428U) /**< \brief (PMC) PLLA Register */
#define REG_CKGR_PLLBR      REG_ACCESS(RwReg, 0x400E042CU) /**< \brief (PMC) PLLB Register */
#define REG_PMC_MCKR        REG_ACCESS(RwReg, 0x400E0430U) /**< \brief (PMC) Master Clock Register */
#define REG_PMC_USB         REG_ACCESS(RwReg, 0x400E0438U) /**< \brief (PMC) USB Clock Register */
#define REG_PMC_PCK         REG_ACCESS(RwReg, 0x400E0440U) /**< \brief (PMC) Programmable Clock 0 Register */
#define REG_PMC_IER         REG_ACCESS(WoReg, 0x400E0460U) /**< \brief (PMC) Interrupt Enable Register */
#define REG_PMC_IDR         REG_ACCESS(WoReg, 0x400E0464U) /**< \brief (PMC) Interrupt Disable Register */
#define REG_PMC_SR          REG_ACCESS(RoReg, 0x400E0468U) /**< \brief (PMC) Status Register */
#define REG_PMC_IMR         REG_ACCESS(RoReg, 0x400E046CU) /**< \brief (PMC) Interrupt Mask Register */
#define REG_PMC_FSMR        REG_ACCESS(RwReg, 0x400E0470U) /**< \brief (PMC) Fast Startup Mode Register */
#define REG_PMC_FSPR        REG_ACCESS(RwReg, 0x400E0474U) /**< \brief (PMC) Fast Startup Polarity Register */
#define REG_PMC_FOCR        REG_ACCESS(WoReg, 0x400E0478U) /**< \brief (PMC) Fault Output Clear Register */
#define REG_PMC_WPMR        REG_ACCESS(RwReg, 0x400E04E4U) /**< \brief (PMC) Write Protect Mode Register */
#define REG_PMC_WPSR        REG_ACCESS(RoReg, 0x400E04E8U) /**< \brief (PMC) Write Protect Status Register */
#define REG_PMC_PCER1       REG_ACCESS(WoReg, 0x400E0500U) /**< \brief (PMC) Peripheral Clock Enable Register 1 */
#define REG_PMC_PCDR1       REG_ACCESS(WoReg, 0x400E0504U) /**< \brief (PMC) Peripheral Clock Disable Register 1 */
#define REG_PMC_PCSR1       REG_ACCESS(RoReg, 0x400E0508U) /**< \brief (PMC) Peripheral Clock Status Register 1 */
#define REG_PMC_OCR         REG_ACCESS(RwReg, 0x400E0510U) /**< \brief (PMC) Oscillator Calibration Register */
/* ========== Register definition for UART0 peripheral ========== */
#define REG_UART0_CR        REG_ACCESS(WoReg, 0x400E0600U) /**< \brief (UART0) Control Register */
#define REG_UART0_MR        REG_ACCESS(RwReg, 0x400E0604U) /**< \brief (UART0) Mode Register */
#define REG_UART0_IER       REG_ACCESS(WoReg, 0x400E0608U) /**< \brief (UART0) Interrupt Enable Register */
#define REG_UART0_IDR       REG_ACCESS(WoReg, 0x400E060CU) /**< \brief (UART0) Interrupt Disable Register */
#define REG_UART0_IMR       REG_ACCESS(RoReg, 0x400E0610U) /**< \brief (UART0) Interrupt Mask Register */
#define REG_UART0_SR        REG_ACCESS(RoReg, 0x400E0614U) /**< \brief (UART0) Status Register */
#define REG_UART0_RHR       REG_ACCESS(RoReg, 0x400E0618U) /**< \brief (UART0) Receive Holding Register */
#define REG_UART0_THR       REG_ACCESS(WoReg, 0x400E061CU) /**< \brief (UART0) Transmit Holding Register */
#define REG_UART0_BRGR      REG_ACCESS(RwReg, 0x400E0620U) /**< \brief (UART0) Baud Rate Generator Register */
#define REG_UART0_RPR       REG_ACCESS(RwReg, 0x400E0700U) /**< \brief (UART0) Receive Pointer Register */
#define REG_UART0_RCR       REG_ACCESS(RwReg, 0x400E0704U) /**< \brief (UART0) Receive Counter Register */
#define REG_UART0_TPR       REG_ACCESS(RwReg, 0x400E0708U) /**< \brief (UART0) Transmit Pointer Register */
#define REG_UART0_TCR       REG_ACCESS(RwReg, 0x400E070CU) /**< \brief (UART0) Transmit Counter Register */
#define REG_UART0_RNPR      REG_ACCESS(RwReg, 0x400E0710U) /**< \brief (UART0) Receive Next Pointer Register */
#define REG_UART0_RNCR      REG_ACCESS(RwReg, 0x400E0714U) /**< \brief (UART0) Receive Next Counter Register */
#define REG_UART0_TNPR      REG_ACCESS(RwReg, 0x400E0718U) /**< \brief (UART0) Transmit Next Pointer Register */
#define REG_UART0_TNCR      REG_ACCESS(RwReg, 0x400E071CU) /**< \brief (UART0) Transmit Next Counter Register */
#define REG_UART0_PTCR      REG_ACCESS(WoReg, 0x400E0720U) /**< \brief (UART0) Transfer Control Register */
#define REG_UART0_PTSR      REG_ACCESS(RoReg, 0x400E0724U) /**< \brief (UART0) Transfer Status Register */
/* ========== Register definition for CHIPID peripheral ========== */
#define REG_CHIPID_CIDR     REG_ACCESS(RoReg, 0x400E0740U) /**< \brief (CHIPID) Chip ID Register */
#define REG_CHIPID_EXID     REG_ACCESS(RoReg, 0x400E0744U) /**< \brief (CHIPID) Chip ID Extension Register */
/* ========== Register definition for UART1 peripheral ========== */
#define REG_UART1_CR        REG_ACCESS(WoReg, 0x400E0800U) /**< \brief (UART1) Control Register */
#define REG_UART1_MR        REG_ACCESS(RwReg, 0x400E0804U) /**< \brief (UART1) Mode Register */
#define REG_UART1_IER       REG_ACCESS(WoReg, 0x400E0808U) /**< \brief (UART1) Interrupt Enable Register */
#define REG_UART1_IDR       REG_ACCESS(WoReg, 0x400E080CU) /**< \brief (UART1) Interrupt Disable Register */
#define REG_UART1_IMR       REG_ACCESS(RoReg, 0x400E0810U) /**< \brief (UART1) Interrupt Mask Register */
#define REG_UART1_SR        REG_ACCESS(RoReg, 0x400E0814U) /**< \brief (UART1) Status Register */
#define REG_UART1_RHR       REG_ACCESS(RoReg, 0x400E0818U) /**< \brief (UART1) Receive Holding Register */
#define REG_UART1_THR       REG_ACCESS(WoReg, 0x400E081CU) /**< \brief (UART1) Transmit Holding Register */
#define REG_UART1_BRGR      REG_ACCESS(RwReg, 0x400E0820U) /**< \brief (UART1) Baud Rate Generator Register */
#define REG_UART1_RPR       REG_ACCESS(RwReg, 0x400E0900U) /**< \brief (UART1) Receive Pointer Register */
#define REG_UART1_RCR       REG_ACCESS(RwReg, 0x400E0904U) /**< \brief (UART1) Receive Counter Register */
#define REG_UART1_TPR       REG_ACCESS(RwReg, 0x400E0908U) /**< \brief (UART1) Transmit Pointer Register */
#define REG_UART1_TCR       REG_ACCESS(RwReg, 0x400E090CU) /**< \brief (UART1) Transmit Counter Register */
#define REG_UART1_RNPR      REG_ACCESS(RwReg, 0x400E0910U) /**< \brief (UART1) Receive Next Pointer Register */
#define REG_UART1_RNCR      REG_ACCESS(RwReg, 0x400E0914U) /**< \brief (UART1) Receive Next Counter Register */
#define REG_UART1_TNPR      REG_ACCESS(RwReg, 0x400E0918U) /**< \brief (UART1) Transmit Next Pointer Register */
#define REG_UART1_TNCR      REG_ACCESS(RwReg, 0x400E091CU) /**< \brief (UART1) Transmit Next Counter Register */
#define REG_UART1_PTCR      REG_ACCESS(WoReg, 0x400E0920U) /**< \brief (UART1) Transfer Control Register */
#define REG_UART1_PTSR      REG_ACCESS(RoReg, 0x400E0924U) /**< \brief (UART1) Transfer Status Register */
/* ========== Register definition for EFC peripheral ========== */
#define REG_EFC_FMR         REG_ACCESS(RwReg, 0x400E0A00U) /**< \brief (EFC) EEFC Flash Mode Register */
#define REG_EFC_FCR         REG_ACCESS(WoReg, 0x400E0A04U) /**< \brief (EFC) EEFC Flash Command Register */
#define REG_EFC_FSR         REG_ACCESS(RoReg, 0x400E0A08U) /**< \brief (EFC) EEFC Flash Status Register */
#define REG_EFC_FRR         REG_ACCESS(RoReg, 0x400E0A0CU) /**< \brief (EFC) EEFC Flash Result Register */
/* ========== Register definition for PIOA peripheral ========== */
#define REG_PIOA_PER        REG_ACCESS(WoReg, 0x400E0E00U) /**< \brief (PIOA) PIO Enable Register */
#define REG_PIOA_PDR        REG_ACCESS(WoReg, 0x400E0E04U) /**< \brief (PIOA) PIO Disable Register */
#define REG_PIOA_PSR        REG_ACCESS(RoReg, 0x400E0E08U) /**< \brief (PIOA) PIO Status Register */
#define REG_PIOA_OER        REG_ACCESS(WoReg, 0x400E0E10U) /**< \brief (PIOA) Output Enable Register */
#define REG_PIOA_ODR        REG_ACCESS(WoReg, 0x400E0E14U) /**< \brief (PIOA) Output Disable Register */
#define REG_PIOA_OSR        REG_ACCESS(RoReg, 0x400E0E18U) /**< \brief (PIOA) Output Status Register */
#define REG_PIOA_IFER       REG_ACCESS(WoReg, 0x400E0E20U) /**< \brief (PIOA) Glitch Input Filter Enable Register */
#define REG_PIOA_IFDR       REG_ACCESS(WoReg, 0x400E0E24U) /**< \brief (PIOA) Glitch Input Filter Disable Register */
#define REG_PIOA_IFSR       REG_ACCESS(RoReg, 0x400E0E28U) /**< \brief (PIOA) Glitch Input Filter Status Register */
#define REG_PIOA_SODR       REG_ACCESS(WoReg, 0x400E0E30U) /**< \brief (PIOA) Set Output Data Register */
#define REG_PIOA_CODR       REG_ACCESS(WoReg, 0x400E0E34U) /**< \brief (PIOA) Clear Output Data Register */
#define REG_PIOA_ODSR       REG_ACCESS(RwReg, 0x400E0E38U) /**< \brief (PIOA) Output Data Status Register */
#define REG_PIOA_PDSR       REG_ACCESS(RoReg, 0x400E0E3CU) /**< \brief (PIOA) Pin Data Status Register */
#define REG_PIOA_IER        REG_ACCESS(WoReg, 0x400E0E40U) /**< \brief (PIOA) Interrupt Enable Register */
#define REG_PIOA_IDR        REG_ACCESS(WoReg, 0x400E0E44U) /**< \brief (PIOA) Interrupt Disable Register */
#define REG_PIOA_IMR        REG_ACCESS(RoReg, 0x400E0E48U) /**< \brief (PIOA) Interrupt Mask Register */
#define REG_PIOA_ISR        REG_ACCESS(RoReg, 0x400E0E4CU) /**< \brief (PIOA) Interrupt Status Register */
#define REG_PIOA_MDER       REG_ACCESS(WoReg, 0x400E0E50U) /**< \brief (PIOA) Multi-driver Enable Register */
#define REG_PIOA_MDDR       REG_ACCESS(WoReg, 0x400E0E54U) /**< \brief (PIOA) Multi-driver Disable Register */
#define REG_PIOA_MDSR       REG_ACCESS(RoReg, 0x400E0E58U) /**< \brief (PIOA) Multi-driver Status Register */
#define REG_PIOA_PUDR       REG_ACCESS(WoReg, 0x400E0E60U) /**< \brief (PIOA) Pull-up Disable Register */
#define REG_PIOA_PUER       REG_ACCESS(WoReg, 0x400E0E64U) /**< \brief (PIOA) Pull-up Enable Register */
#define REG_PIOA_PUSR       REG_ACCESS(RoReg, 0x400E0E68U) /**< \brief (PIOA) Pad Pull-up Status Register */
#define REG_PIOA_ABCDSR     REG_ACCESS(RwReg, 0x400E0E70U) /**< \brief (PIOA) Peripheral Select Register */
#define REG_PIOA_IFSCDR     REG_ACCESS(WoReg, 0x400E0E80U) /**< \brief (PIOA) Input Filter Slow Clock Disable Register */
#define REG_PIOA_IFSCER     REG_ACCESS(WoReg, 0x400E0E84U) /**< \brief (PIOA) Input Filter Slow Clock Enable Register */
#define REG_PIOA_IFSCSR     REG_ACCESS(RoReg, 0x400E0E88U) /**< \brief (PIOA) Input Filter Slow Clock Status Register */
#define REG_PIOA_SCDR       REG_ACCESS(RwReg, 0x400E0E8CU) /**< \brief (PIOA) Slow Clock Divider Debouncing Register */
#define REG_PIOA_PPDDR      REG_ACCESS(WoReg, 0x400E0E90U) /**< \brief (PIOA) Pad Pull-down Disable Register */
#define REG_PIOA_PPDER      REG_ACCESS(WoReg, 0x400E0E94U) /**< \brief (PIOA) Pad Pull-down Enable Register */
#define REG_PIOA_PPDSR      REG_ACCESS(RoReg, 0x400E0E98U) /**< \brief (PIOA) Pad Pull-down Status Register */
#define REG_PIOA_OWER       REG_ACCESS(WoReg, 0x400E0EA0U) /**< \brief (PIOA) Output Write Enable */
#define REG_PIOA_OWDR       REG_ACCESS(WoReg, 0x400E0EA4U) /**< \brief (PIOA) Output Write Disable */
#define REG_PIOA_OWSR       REG_ACCESS(RoReg, 0x400E0EA8U) /**< \brief (PIOA) Output Write Status Register */
#define REG_PIOA_AIMER      REG_ACCESS(WoReg, 0x400E0EB0U) /**< \brief (PIOA) Additional Interrupt Modes Enable Register */
#define REG_PIOA_AIMDR      REG_ACCESS(WoReg, 0x400E0EB4U) /**< \brief (PIOA) Additional Interrupt Modes Disables Register */
#define REG_PIOA_AIMMR      REG_ACCESS(RoReg, 0x400E0EB8U) /**< \brief (PIOA) Additional Interrupt Modes Mask Register */
#define REG_PIOA_ESR        REG_ACCESS(WoReg, 0x400E0EC0U) /**< \brief (PIOA) Edge Select Register */
#define REG_PIOA_LSR        REG_ACCESS(WoReg, 0x400E0EC4U) /**< \brief (PIOA) Level Select Register */
#define REG_PIOA_ELSR       REG_ACCESS(RoReg, 0x400E0EC8U) /**< \brief (PIOA) Edge/Level Status Register */
#define REG_PIOA_FELLSR     REG_ACCESS(WoReg, 0x400E0ED0U) /**< \brief (PIOA) Falling Edge/Low Level Select Register */
#define REG_PIOA_REHLSR     REG_ACCESS(WoReg, 0x400E0ED4U) /**< \brief (PIOA) Rising Edge/ High Level Select Register */
#define REG_PIOA_FRLHSR     REG_ACCESS(RoReg, 0x400E0ED8U) /**< \brief (PIOA) Fall/Rise - Low/High Status Register */
#define REG_PIOA_LOCKSR     REG_ACCESS(RoReg, 0x400E0EE0U) /**< \brief (PIOA) Lock Status */
#define REG_PIOA_WPMR       REG_ACCESS(RwReg, 0x400E0EE4U) /**< \brief (PIOA) Write Protect Mode Register */
#define REG_PIOA_WPSR       REG_ACCESS(RoReg, 0x400E0EE8U) /**< \brief (PIOA) Write Protect Status Register */
#define REG_PIOA_SCHMITT    REG_ACCESS(RwReg, 0x400E0F00U) /**< \brief (PIOA) Schmitt Trigger Register */
#define REG_PIOA_PCMR       REG_ACCESS(RwReg, 0x400E0F50U) /**< \brief (PIOA) Parallel Capture Mode Register */
#define REG_PIOA_PCIER      REG_ACCESS(WoReg, 0x400E0F54U) /**< \brief (PIOA) Parallel Capture Interrupt Enable Register */
#define REG_PIOA_PCIDR      REG_ACCESS(WoReg, 0x400E0F58U) /**< \brief (PIOA) Parallel Capture Interrupt Disable Register */
#define REG_PIOA_PCIMR      REG_ACCESS(RoReg, 0x400E0F5CU) /**< \brief (PIOA) Parallel Capture Interrupt Mask Register */
#define REG_PIOA_PCISR      REG_ACCESS(RoReg, 0x400E0F60U) /**< \brief (PIOA) Parallel Capture Interrupt Status Register */
#define REG_PIOA_PCRHR      REG_ACCESS(RoReg, 0x400E0F64U) /**< \brief (PIOA) Parallel Capture Reception Holding Register */
#define REG_PIOA_RPR        REG_ACCESS(RwReg, 0x400E0F68U) /**< \brief (PIOA) Receive Pointer Register */
#define REG_PIOA_RCR        REG_ACCESS(RwReg, 0x400E0F6CU) /**< \brief (PIOA) Receive Counter Register */
#define REG_PIOA_TPR        REG_ACCESS(RwReg, 0x400E0F70U) /**< \brief (PIOA) Transmit Pointer Register */
#define REG_PIOA_TCR        REG_ACCESS(RwReg, 0x400E0F74U) /**< \brief (PIOA) Transmit Counter Register */
#define REG_PIOA_RNPR       REG_ACCESS(RwReg, 0x400E0F78U) /**< \brief (PIOA) Receive Next Pointer Register */
#define REG_PIOA_RNCR       REG_ACCESS(RwReg, 0x400E0F7CU) /**< \brief (PIOA) Receive Next Counter Register */
#define REG_PIOA_TNPR       REG_ACCESS(RwReg, 0x400E0F80U) /**< \brief (PIOA) Transmit Next Pointer Register */
#define REG_PIOA_TNCR       REG_ACCESS(RwReg, 0x400E0F84U) /**< \brief (PIOA) Transmit Next Counter Register */
#define REG_PIOA_PTCR       REG_ACCESS(WoReg, 0x400E0F88U) /**< \brief (PIOA) Transfer Control Register */
#define REG_PIOA_PTSR       REG_ACCESS(RoReg, 0x400E0F8CU) /**< \brief (PIOA) Transfer Status Register */
/* ========== Register definition for PIOB peripheral ========== */
#define REG_PIOB_PER        REG_ACCESS(WoReg, 0x400E1000U) /**< \brief (PIOB) PIO Enable Register */
#define REG_PIOB_PDR        REG_ACCESS(WoReg, 0x400E1004U) /**< \brief (PIOB) PIO Disable Register */
#define REG_PIOB_PSR        REG_ACCESS(RoReg, 0x400E1008U) /**< \brief (PIOB) PIO Status Register */
#define REG_PIOB_OER        REG_ACCESS(WoReg, 0x400E1010U) /**< \brief (PIOB) Output Enable Register */
#define REG_PIOB_ODR        REG_ACCESS(WoReg, 0x400E1014U) /**< \brief (PIOB) Output Disable Register */
#define REG_PIOB_OSR        REG_ACCESS(RoReg, 0x400E1018U) /**< \brief (PIOB) Output Status Register */
#define REG_PIOB_IFER       REG_ACCESS(WoReg, 0x400E1020U) /**< \brief (PIOB) Glitch Input Filter Enable Register */
#define REG_PIOB_IFDR       REG_ACCESS(WoReg, 0x400E1024U) /**< \brief (PIOB) Glitch Input Filter Disable Register */
#define REG_PIOB_IFSR       REG_ACCESS(RoReg, 0x400E1028U) /**< \brief (PIOB) Glitch Input Filter Status Register */
#define REG_PIOB_SODR       REG_ACCESS(WoReg, 0x400E1030U) /**< \brief (PIOB) Set Output Data Register */
#define REG_PIOB_CODR       REG_ACCESS(WoReg, 0x400E1034U) /**< \brief (PIOB) Clear Output Data Register */
#define REG_PIOB_ODSR       REG_ACCESS(RwReg, 0x400E1038U) /**< \brief (PIOB) Output Data Status Register */
#define REG_PIOB_PDSR       REG_ACCESS(RoReg, 0x400E103CU) /**< \brief (PIOB) Pin Data Status Register */
#define REG_PIOB_IER        REG_ACCESS(WoReg, 0x400E1040U) /**< \brief (PIOB) Interrupt Enable Register */
#define REG_PIOB_IDR        REG_ACCESS(WoReg, 0x400E1044U) /**< \brief (PIOB) Interrupt Disable Register */
#define REG_PIOB_IMR        REG_ACCESS(RoReg, 0x400E1048U) /**< \brief (PIOB) Interrupt Mask Register */
#define REG_PIOB_ISR        REG_ACCESS(RoReg, 0x400E104CU) /**< \brief (PIOB) Interrupt Status Register */
#define REG_PIOB_MDER       REG_ACCESS(WoReg, 0x400E1050U) /**< \brief (PIOB) Multi-driver Enable Register */
#define REG_PIOB_MDDR       REG_ACCESS(WoReg, 0x400E1054U) /**< \brief (PIOB) Multi-driver Disable Register */
#define REG_PIOB_MDSR       REG_ACCESS(RoReg, 0x400E1058U) /**< \brief (PIOB) Multi-driver Status Register */
#define REG_PIOB_PUDR       REG_ACCESS(WoReg, 0x400E1060U) /**< \brief (PIOB) Pull-up Disable Register */
#define REG_PIOB_PUER       REG_ACCESS(WoReg, 0x400E1064U) /**< \brief (PIOB) Pull-up Enable Register */
#define REG_PIOB_PUSR       REG_ACCESS(RoReg, 0x400E1068U) /**< \brief (PIOB) Pad Pull-up Status Register */
#define REG_PIOB_ABCDSR     REG_ACCESS(RwReg, 0x400E1070U) /**< \brief (PIOB) Peripheral Select Register */
#define REG_PIOB_IFSCDR     REG_ACCESS(WoReg, 0x400E1080U) /**< \brief (PIOB) Input Filter Slow Clock Disable Register */
#define REG_PIOB_IFSCER     REG_ACCESS(WoReg, 0x400E1084U) /**< \brief (PIOB) Input Filter Slow Clock Enable Register */
#define REG_PIOB_IFSCSR     REG_ACCESS(RoReg, 0x400E1088U) /**< \brief (PIOB) Input Filter Slow Clock Status Register */
#define REG_PIOB_SCDR       REG_ACCESS(RwReg, 0x400E108CU) /**< \brief (PIOB) Slow Clock Divider Debouncing Register */
#define REG_PIOB_PPDDR      REG_ACCESS(WoReg, 0x400E1090U) /**< \brief (PIOB) Pad Pull-down Disable Register */
#define REG_PIOB_PPDER      REG_ACCESS(WoReg, 0x400E1094U) /**< \brief (PIOB) Pad Pull-down Enable Register */
#define REG_PIOB_PPDSR      REG_ACCESS(RoReg, 0x400E1098U) /**< \brief (PIOB) Pad Pull-down Status Register */
#define REG_PIOB_OWER       REG_ACCESS(WoReg, 0x400E10A0U) /**< \brief (PIOB) Output Write Enable */
#define REG_PIOB_OWDR       REG_ACCESS(WoReg, 0x400E10A4U) /**< \brief (PIOB) Output Write Disable */
#define REG_PIOB_OWSR       REG_ACCESS(RoReg, 0x400E10A8U) /**< \brief (PIOB) Output Write Status Register */
#define REG_PIOB_AIMER      REG_ACCESS(WoReg, 0x400E10B0U) /**< \brief (PIOB) Additional Interrupt Modes Enable Register */
#define REG_PIOB_AIMDR      REG_ACCESS(WoReg, 0x400E10B4U) /**< \brief (PIOB) Additional Interrupt Modes Disables Register */
#define REG_PIOB_AIMMR      REG_ACCESS(RoReg, 0x400E10B8U) /**< \brief (PIOB) Additional Interrupt Modes Mask Register */
#define REG_PIOB_ESR        REG_ACCESS(WoReg, 0x400E10C0U) /**< \brief (PIOB) Edge Select Register */
#define REG_PIOB_LSR        REG_ACCESS(WoReg, 0x400E10C4U) /**< \brief (PIOB) Level Select Register */
#define REG_PIOB_ELSR       REG_ACCESS(RoReg, 0x400E10C8U) /**< \brief (PIOB) Edge/Level Status Register */
#define REG_PIOB_FELLSR     REG_ACCESS(WoReg, 0x400E10D0U) /**< \brief (PIOB) Falling Edge/Low Level Select Register */
#define REG_PIOB_REHLSR     REG_ACCESS(WoReg, 0x400E10D4U) /**< \brief (PIOB) Rising Edge/ High Level Select Register */
#define REG_PIOB_FRLHSR     REG_ACCESS(RoReg, 0x400E10D8U) /**< \brief (PIOB) Fall/Rise - Low/High Status Register */
#define REG_PIOB_LOCKSR     REG_ACCESS(RoReg, 0x400E10E0U) /**< \brief (PIOB) Lock Status */
#define REG_PIOB_WPMR       REG_ACCESS(RwReg, 0x400E10E4U) /**< \brief (PIOB) Write Protect Mode Register */
#define REG_PIOB_WPSR       REG_ACCESS(RoReg, 0x400E10E8U) /**< \brief (PIOB) Write Protect Status Register */
#define REG_PIOB_SCHMITT    REG_ACCESS(RwReg, 0x400E1100U) /**< \brief (PIOB) Schmitt Trigger Register */
#define REG_PIOB_PCMR       REG_ACCESS(RwReg, 0x400E1150U) /**< \brief (PIOB) Parallel Capture Mode Register */
#define REG_PIOB_PCIER      REG_ACCESS(WoReg, 0x400E1154U) /**< \brief (PIOB) Parallel Capture Interrupt Enable Register */
#define REG_PIOB_PCIDR      REG_ACCESS(WoReg, 0x400E1158U) /**< \brief (PIOB) Parallel Capture Interrupt Disable Register */
#define REG_PIOB_PCIMR      REG_ACCESS(RoReg, 0x400E115CU) /**< \brief (PIOB) Parallel Capture Interrupt Mask Register */
#define REG_PIOB_PCISR      REG_ACCESS(RoReg, 0x400E1160U) /**< \brief (PIOB) Parallel Capture Interrupt Status Register */
#define REG_PIOB_PCRHR      REG_ACCESS(RoReg, 0x400E1164U) /**< \brief (PIOB) Parallel Capture Reception Holding Register */
/* ========== Register definition for PIOC peripheral ========== */
#define REG_PIOC_PER        REG_ACCESS(WoReg, 0x400E1200U) /**< \brief (PIOC) PIO Enable Register */
#define REG_PIOC_PDR        REG_ACCESS(WoReg, 0x400E1204U) /**< \brief (PIOC) PIO Disable Register */
#define REG_PIOC_PSR        REG_ACCESS(RoReg, 0x400E1208U) /**< \brief (PIOC) PIO Status Register */
#define REG_PIOC_OER        REG_ACCESS(WoReg, 0x400E1210U) /**< \brief (PIOC) Output Enable Register */
#define REG_PIOC_ODR        REG_ACCESS(WoReg, 0x400E1214U) /**< \brief (PIOC) Output Disable Register */
#define REG_PIOC_OSR        REG_ACCESS(RoReg, 0x400E1218U) /**< \brief (PIOC) Output Status Register */
#define REG_PIOC_IFER       REG_ACCESS(WoReg, 0x400E1220U) /**< \brief (PIOC) Glitch Input Filter Enable Register */
#define REG_PIOC_IFDR       REG_ACCESS(WoReg, 0x400E1224U) /**< \brief (PIOC) Glitch Input Filter Disable Register */
#define REG_PIOC_IFSR       REG_ACCESS(RoReg, 0x400E1228U) /**< \brief (PIOC) Glitch Input Filter Status Register */
#define REG_PIOC_SODR       REG_ACCESS(WoReg, 0x400E1230U) /**< \brief (PIOC) Set Output Data Register */
#define REG_PIOC_CODR       REG_ACCESS(WoReg, 0x400E1234U) /**< \brief (PIOC) Clear Output Data Register */
#define REG_PIOC_ODSR       REG_ACCESS(RwReg, 0x400E1238U) /**< \brief (PIOC) Output Data Status Register */
#define REG_PIOC_PDSR       REG_ACCESS(RoReg, 0x400E123CU) /**< \brief (PIOC) Pin Data Status Register */
#define REG_PIOC_IER        REG_ACCESS(WoReg, 0x400E1240U) /**< \brief (PIOC) Interrupt Enable Register */
#define REG_PIOC_IDR        REG_ACCESS(WoReg, 0x400E1244U) /**< \brief (PIOC) Interrupt Disable Register */
#define REG_PIOC_IMR        REG_ACCESS(RoReg, 0x400E1248U) /**< \brief (PIOC) Interrupt Mask Register */
#define REG_PIOC_ISR        REG_ACCESS(RoReg, 0x400E124CU) /**< \brief (PIOC) Interrupt Status Register */
#define REG_PIOC_MDER       REG_ACCESS(WoReg, 0x400E1250U) /**< \brief (PIOC) Multi-driver Enable Register */
#define REG_PIOC_MDDR       REG_ACCESS(WoReg, 0x400E1254U) /**< \brief (PIOC) Multi-driver Disable Register */
#define REG_PIOC_MDSR       REG_ACCESS(RoReg, 0x400E1258U) /**< \brief (PIOC) Multi-driver Status Register */
#define REG_PIOC_PUDR       REG_ACCESS(WoReg, 0x400E1260U) /**< \brief (PIOC) Pull-up Disable Register */
#define REG_PIOC_PUER       REG_ACCESS(WoReg, 0x400E1264U) /**< \brief (PIOC) Pull-up Enable Register */
#define REG_PIOC_PUSR       REG_ACCESS(RoReg, 0x400E1268U) /**< \brief (PIOC) Pad Pull-up Status Register */
#define REG_PIOC_ABCDSR     REG_ACCESS(RwReg, 0x400E1270U) /**< \brief (PIOC) Peripheral Select Register */
#define REG_PIOC_IFSCDR     REG_ACCESS(WoReg, 0x400E1280U) /**< \brief (PIOC) Input Filter Slow Clock Disable Register */
#define REG_PIOC_IFSCER     REG_ACCESS(WoReg, 0x400E1284U) /**< \brief (PIOC) Input Filter Slow Clock Enable Register */
#define REG_PIOC_IFSCSR     REG_ACCESS(RoReg, 0x400E1288U) /**< \brief (PIOC) Input Filter Slow Clock Status Register */
#define REG_PIOC_SCDR       REG_ACCESS(RwReg, 0x400E128CU) /**< \brief (PIOC) Slow Clock Divider Debouncing Register */
#define REG_PIOC_PPDDR      REG_ACCESS(WoReg, 0x400E1290U) /**< \brief (PIOC) Pad Pull-down Disable Register */
#define REG_PIOC_PPDER      REG_ACCESS(WoReg, 0x400E1294U) /**< \brief (PIOC) Pad Pull-down Enable Register */
#define REG_PIOC_PPDSR      REG_ACCESS(RoReg, 0x400E1298U) /**< \brief (PIOC) Pad Pull-down Status Register */
#define REG_PIOC_OWER       REG_ACCESS(WoReg, 0x400E12A0U) /**< \brief (PIOC) Output Write Enable */
#define REG_PIOC_OWDR       REG_ACCESS(WoReg, 0x400E12A4U) /**< \brief (PIOC) Output Write Disable */
#define REG_PIOC_OWSR       REG_ACCESS(RoReg, 0x400E12A8U) /**< \brief (PIOC) Output Write Status Register */
#define REG_PIOC_AIMER      REG_ACCESS(WoReg, 0x400E12B0U) /**< \brief (PIOC) Additional Interrupt Modes Enable Register */
#define REG_PIOC_AIMDR      REG_ACCESS(WoReg, 0x400E12B4U) /**< \brief (PIOC) Additional Interrupt Modes Disables Register */
#define REG_PIOC_AIMMR      REG_ACCESS(RoReg, 0x400E12B8U) /**< \brief (PIOC) Additional Interrupt Modes Mask Register */
#define REG_PIOC_ESR        REG_ACCESS(WoReg, 0x400E12C0U) /**< \brief (PIOC) Edge Select Register */
#define REG_PIOC_LSR        REG_ACCESS(WoReg, 0x400E12C4U) /**< \brief (PIOC) Level Select Register */
#define REG_PIOC_ELSR       REG_ACCESS(RoReg, 0x400E12C8U) /**< \brief (PIOC) Edge/Level Status Register */
#define REG_PIOC_FELLSR     REG_ACCESS(WoReg, 0x400E12D0U) /**< \brief (PIOC) Falling Edge/Low Level Select Register */
#define REG_PIOC_REHLSR     REG_ACCESS(WoReg, 0x400E12D4U) /**< \brief (PIOC) Rising Edge/ High Level Select Register */
#define REG_PIOC_FRLHSR     REG_ACCESS(RoReg, 0x400E12D8U) /**< \brief (PIOC) Fall/Rise - Low/High Status Register */
#define REG_PIOC_LOCKSR     REG_ACCESS(RoReg, 0x400E12E0U) /**< \brief (PIOC) Lock Status */
#define REG_PIOC_WPMR       REG_ACCESS(RwReg, 0x400E12E4U) /**< \brief (PIOC) Write Protect Mode Register */
#define REG_PIOC_WPSR       REG_ACCESS(RoReg, 0x400E12E8U) /**< \brief (PIOC) Write Protect Status Register */
#define REG_PIOC_SCHMITT    REG_ACCESS(RwReg, 0x400E1300U) /**< \brief (PIOC) Schmitt Trigger Register */
#define REG_PIOC_PCMR       REG_ACCESS(RwReg, 0x400E1350U) /**< \brief (PIOC) Parallel Capture Mode Register */
#define REG_PIOC_PCIER      REG_ACCESS(WoReg, 0x400E1354U) /**< \brief (PIOC) Parallel Capture Interrupt Enable Register */
#define REG_PIOC_PCIDR      REG_ACCESS(WoReg, 0x400E1358U) /**< \brief (PIOC) Parallel Capture Interrupt Disable Register */
#define REG_PIOC_PCIMR      REG_ACCESS(RoReg, 0x400E135CU) /**< \brief (PIOC) Parallel Capture Interrupt Mask Register */
#define REG_PIOC_PCISR      REG_ACCESS(RoReg, 0x400E1360U) /**< \brief (PIOC) Parallel Capture Interrupt Status Register */
#define REG_PIOC_PCRHR      REG_ACCESS(RoReg, 0x400E1364U) /**< \brief (PIOC) Parallel Capture Reception Holding Register */
/* ========== Register definition for RSTC peripheral ========== */
#define REG_RSTC_CR         REG_ACCESS(WoReg, 0x400E1400U) /**< \brief (RSTC) Control Register */
#define REG_RSTC_SR         REG_ACCESS(RoReg, 0x400E1404U) /**< \brief (RSTC) Status Register */
#define REG_RSTC_MR         REG_ACCESS(RwReg, 0x400E1408U) /**< \brief (RSTC) Mode Register */
/* ========== Register definition for SUPC peripheral ========== */
#define REG_SUPC_CR         REG_ACCESS(WoReg, 0x400E1410U) /**< \brief (SUPC) Supply Controller Control Register */
#define REG_SUPC_SMMR       REG_ACCESS(RwReg, 0x400E1414U) /**< \brief (SUPC) Supply Controller Supply Monitor Mode Register */
#define REG_SUPC_MR         REG_ACCESS(RwReg, 0x400E1418U) /**< \brief (SUPC) Supply Controller Mode Register */
#define REG_SUPC_WUMR       REG_ACCESS(RwReg, 0x400E141CU) /**< \brief (SUPC) Supply Controller Wake Up Mode Register */
#define REG_SUPC_WUIR       REG_ACCESS(RwReg, 0x400E1420U) /**< \brief (SUPC) Supply Controller Wake Up Inputs Register */
#define REG_SUPC_SR         REG_ACCESS(RoReg, 0x400E1424U) /**< \brief (SUPC) Supply Controller Status Register */
/* ========== Register definition for RTT peripheral ========== */
#define REG_RTT_MR          REG_ACCESS(RwReg, 0x400E1430U) /**< \brief (RTT) Mode Register */
#define REG_RTT_AR          REG_ACCESS(RwReg, 0x400E1434U) /**< \brief (RTT) Alarm Register */
#define REG_RTT_VR          REG_ACCESS(RoReg, 0x400E1438U) /**< \brief (RTT) Value Register */
#define REG_RTT_SR          REG_ACCESS(RoReg, 0x400E143CU) /**< \brief (RTT) Status Register */
/* ========== Register definition for WDT peripheral ========== */
#define REG_WDT_CR          REG_ACCESS(WoReg, 0x400E1450U) /**< \brief (WDT) Control Register */
#define REG_WDT_MR          REG_ACCESS(RwReg, 0x400E1454U) /**< \brief (WDT) Mode Register */
#define REG_WDT_SR          REG_ACCESS(RoReg, 0x400E1458U) /**< \brief (WDT) Status Register */
/* ========== Register definition for RTC peripheral ========== */
#define REG_RTC_CR          REG_ACCESS(RwReg, 0x400E1460U) /**< \brief (RTC) Control Register */
#define REG_RTC_MR          REG_ACCESS(RwReg, 0x400E1464U) /**< \brief (RTC) Mode Register */
#define REG_RTC_TIMR        REG_ACCESS(RwReg, 0x400E1468U) /**< \brief (RTC) Time Register */
#define REG_RTC_CALR        REG_ACCESS(RwReg, 0x400E146CU) /**< \brief (RTC) Calendar Register */
#define REG_RTC_TIMALR      REG_ACCESS(RwReg, 0x400E1470U) /**< \brief (RTC) Time Alarm Register */
#define REG_RTC_CALALR      REG_ACCESS(RwReg, 0x400E1474U) /**< \brief (RTC) Calendar Alarm Register */
#define REG_RTC_SR          REG_ACCESS(RoReg, 0x400E1478U) /**< \brief (RTC) Status Register */
#define REG_RTC_SCCR        REG_ACCESS(WoReg, 0x400E147CU) /**< \brief (RTC) Status Clear Command Register */
#define REG_RTC_IER         REG_ACCESS(WoReg, 0x400E1480U) /**< \brief (RTC) Interrupt Enable Register */
#define REG_RTC_IDR         REG_ACCESS(WoReg, 0x400E1484U) /**< \brief (RTC) Interrupt Disable Register */
#define REG_RTC_IMR         REG_ACCESS(RoReg, 0x400E1488U) /**< \brief (RTC) Interrupt Mask Register */
#define REG_RTC_VER         REG_ACCESS(RoReg, 0x400E148CU) /**< \brief (RTC) Valid Entry Register */
/* ========== Register definition for GPBR peripheral ========== */
#define REG_GPBR_GPBR0      REG_ACCESS(RwReg, 0x400E1490U) /**< \brief (GPBR) General Purpose Backup Register 0 */
#define REG_GPBR_GPBR1      REG_ACCESS(RwReg, 0x400E1494U) /**< \brief (GPBR) General Purpose Backup Register 1 */
#define REG_GPBR_GPBR2      REG_ACCESS(RwReg, 0x400E1498U) /**< \brief (GPBR) General Purpose Backup Register 2 */
#define REG_GPBR_GPBR3      REG_ACCESS(RwReg, 0x400E149CU) /**< \brief (GPBR) General Purpose Backup Register 3 */
#define REG_GPBR_GPBR4      REG_ACCESS(RwReg, 0x400E14A0U) /**< \brief (GPBR) General Purpose Backup Register 4 */
#define REG_GPBR_GPBR5      REG_ACCESS(RwReg, 0x400E14A4U) /**< \brief (GPBR) General Purpose Backup Register 5 */
#define REG_GPBR_GPBR6      REG_ACCESS(RwReg, 0x400E14A8U) /**< \brief (GPBR) General Purpose Backup Register 6 */
#define REG_GPBR_GPBR7      REG_ACCESS(RwReg, 0x400E14ACU) /**< \brief (GPBR) General Purpose Backup Register 7 */
/*@}*/

/* ************************************************************************** */
/*   PERIPHERAL ID DEFINITIONS FOR SAM3S16 */
/* ************************************************************************** */
/** \addtogroup SAM3S16_id Peripheral Ids Definitions */
/*@{*/

#define ID_SUPC   ( 0) /**< \brief Supply Controller (SUPC) */
#define ID_RSTC   ( 1) /**< \brief Reset Controller (RSTC) */
#define ID_RTC    ( 2) /**< \brief Real Time Clock (RTC) */
#define ID_RTT    ( 3) /**< \brief Real Time Timer (RTT) */
#define ID_WDT    ( 4) /**< \brief Watchdog Timer (WDT) */
#define ID_PMC    ( 5) /**< \brief Power Management Controller (PMC) */
#define ID_EFC    ( 6) /**< \brief Enhanced Embedded Flash Controller (EFC) */
#define ID_UART0  ( 8) /**< \brief UART 0 (UART0) */
#define ID_UART1  ( 9) /**< \brief UART 1 (UART1) */
#define ID_SMC    (10) /**< \brief SMC (SMC) */
#define ID_PIOA   (11) /**< \brief Parallel I/O Controller A (PIOA) */
#define ID_PIOB   (12) /**< \brief Parallel I/O Controller B (PIOB) */
#define ID_PIOC   (13) /**< \brief Parallel I/O Controller C (PIOC) */
#define ID_USART0 (14) /**< \brief USART 0 (USART0) */
#define ID_USART1 (15) /**< \brief USART 1 (USART1) */
#define ID_HSMCI  (18) /**< \brief High Speed Multimedia Card Interface (HSMCI) */
#define ID_TWI0   (19) /**< \brief Two Wire Interface 0 (TWI0) */
#define ID_TWI1   (20) /**< \brief Two Wire Interface 1 (TWI1) */
#define ID_SPI    (21) /**< \brief Serial Peripheral Interface (SPI) */
#define ID_SSC    (22) /**< \brief Synchronous Serial Controller (SSC) */
#define ID_TC0    (23) /**< \brief Timer/Counter 0 (TC0) */
#define ID_TC1    (24) /**< \brief Timer/Counter 1 (TC1) */
#define ID_TC2    (25) /**< \brief Timer/Counter 2 (TC2) */
#define ID_TC3    (26) /**< \brief Timer/Counter 3 (TC3) */
#define ID_TC4    (27) /**< \brief Timer/Counter 4 (TC4) */
#define ID_TC5    (28) /**< \brief Timer/Counter 5 (TC5) */
#define ID_ADC    (29) /**< \brief Analog-to-Digital Converter (ADC) */
#define ID_DACC   (30) /**< \brief Digital-to-Analog Converter (DACC) */
#define ID_PWM    (31) /**< \brief Pulse Width Modulation (PWM) */
#define ID_CRCCU  (32) /**< \brief CRC Calculation Unit (CRCCU) */
#define ID_ACC    (33) /**< \brief Analog Comparator (ACC) */
#define ID_UDP    (34) /**< \brief USB Device Port (UDP) */
/*@}*/

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAM3S16 */
/* ************************************************************************** */
/** \addtogroup SAM3S16_base Peripheral Base Address Definitions */
/*@{*/

#define HSMCI      CAST(Hsmci     , 0x40000000U) /**< \brief (HSMCI     ) Base Address */
#define PDC_HSMCI  CAST(Pdc       , 0x40000100U) /**< \brief (PDC_HSMCI ) Base Address */
#define SSC        CAST(Ssc       , 0x40004000U) /**< \brief (SSC       ) Base Address */
#define PDC_SSC    CAST(Pdc       , 0x40004100U) /**< \brief (PDC_SSC   ) Base Address */
#define SPI        CAST(Spi       , 0x40008000U) /**< \brief (SPI       ) Base Address */
#define PDC_SPI    CAST(Pdc       , 0x40008100U) /**< \brief (PDC_SPI   ) Base Address */
#define TC0        CAST(Tc        , 0x40010000U) /**< \brief (TC0       ) Base Address */
#define TC1        CAST(Tc        , 0x40014000U) /**< \brief (TC1       ) Base Address */
#define TWI0       CAST(Twi       , 0x40018000U) /**< \brief (TWI0      ) Base Address */
#define PDC_TWI0   CAST(Pdc       , 0x40018100U) /**< \brief (PDC_TWI0  ) Base Address */
#define TWI1       CAST(Twi       , 0x4001C000U) /**< \brief (TWI1      ) Base Address */
#define PDC_TWI1   CAST(Pdc       , 0x4001C100U) /**< \brief (PDC_TWI1  ) Base Address */
#define PWM        CAST(Pwm       , 0x40020000U) /**< \brief (PWM       ) Base Address */
#define PDC_PWM    CAST(Pdc       , 0x40020100U) /**< \brief (PDC_PWM   ) Base Address */
#define USART0     CAST(Usart     , 0x40024000U) /**< \brief (USART0    ) Base Address */
#define PDC_USART0 CAST(Pdc       , 0x40024100U) /**< \brief (PDC_USART0) Base Address */
#define USART1     CAST(Usart     , 0x40028000U) /**< \brief (USART1    ) Base Address */
#define PDC_USART1 CAST(Pdc       , 0x40028100U) /**< \brief (PDC_USART1) Base Address */
#define UDP        CAST(Udp       , 0x40034000U) /**< \brief (UDP       ) Base Address */
#define ADC        CAST(Adc       , 0x40038000U) /**< \brief (ADC       ) Base Address */
#define PDC_ADC    CAST(Pdc       , 0x40038100U) /**< \brief (PDC_ADC   ) Base Address */
#define DACC       CAST(Dacc      , 0x4003C000U) /**< \brief (DACC      ) Base Address */
#define PDC_DACC   CAST(Pdc       , 0x4003C100U) /**< \brief (PDC_DACC  ) Base Address */
#define ACC        CAST(Acc       , 0x40040000U) /**< \brief (ACC       ) Base Address */
#define CRCCU      CAST(Crccu     , 0x40044000U) /**< \brief (CRCCU     ) Base Address */
#define SMC        CAST(Smc       , 0x400E0000U) /**< \brief (SMC       ) Base Address */
#define MATRIX     CAST(Matrix    , 0x400E0200U) /**< \brief (MATRIX    ) Base Address */
#define PMC        CAST(Pmc       , 0x400E0400U) /**< \brief (PMC       ) Base Address */
#define UART0      CAST(Uart      , 0x400E0600U) /**< \brief (UART0     ) Base Address */
#define PDC_UART0  CAST(Pdc       , 0x400E0700U) /**< \brief (PDC_UART0 ) Base Address */
#define CHIPID     CAST(Chipid    , 0x400E0740U) /**< \brief (CHIPID    ) Base Address */
#define UART1      CAST(Uart      , 0x400E0800U) /**< \brief (UART1     ) Base Address */
#define PDC_UART1  CAST(Pdc       , 0x400E0900U) /**< \brief (PDC_UART1 ) Base Address */
#define EFC        CAST(Efc       , 0x400E0A00U) /**< \brief (EFC       ) Base Address */
#define PIOA       CAST(Pio       , 0x400E0E00U) /**< \brief (PIOA      ) Base Address */
#define PDC_PIOA   CAST(Pdc       , 0x400E0F00U) /**< \brief (PDC_PIOA  ) Base Address */
#define PIOB       CAST(Pio       , 0x400E1000U) /**< \brief (PIOB      ) Base Address */
#define PIOC       CAST(Pio       , 0x400E1200U) /**< \brief (PIOC      ) Base Address */
#define RSTC       CAST(Rstc      , 0x400E1400U) /**< \brief (RSTC      ) Base Address */
#define SUPC       CAST(Supc      , 0x400E1410U) /**< \brief (SUPC      ) Base Address */
#define RTT        CAST(Rtt       , 0x400E1430U) /**< \brief (RTT       ) Base Address */
#define WDT        CAST(Wdt       , 0x400E1450U) /**< \brief (WDT       ) Base Address */
#define RTC        CAST(Rtc       , 0x400E1460U) /**< \brief (RTC       ) Base Address */
#define GPBR       CAST(Gpbr      , 0x400E1490U) /**< \brief (GPBR      ) Base Address */
/*@}*/

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAM3S16 */
/* ************************************************************************** */
/** \addtogroup SAM3S16_pio Peripheral Pio Definitions */
/*@{*/

#define PIO_PA0                    (1u << 0)  /**< \brief Pin Controlled by PA0 */
#define PIO_PA1                    (1u << 1)  /**< \brief Pin Controlled by PA1 */
#define PIO_PA2                    (1u << 2)  /**< \brief Pin Controlled by PA2 */
#define PIO_PA3                    (1u << 3)  /**< \brief Pin Controlled by PA3 */
#define PIO_PA4                    (1u << 4)  /**< \brief Pin Controlled by PA4 */
#define PIO_PA5                    (1u << 5)  /**< \brief Pin Controlled by PA5 */
#define PIO_PA6                    (1u << 6)  /**< \brief Pin Controlled by PA6 */
#define PIO_PA7                    (1u << 7)  /**< \brief Pin Controlled by PA7 */
#define PIO_PA8                    (1u << 8)  /**< \brief Pin Controlled by PA8 */
#define PIO_PA9                    (1u << 9)  /**< \brief Pin Controlled by PA9 */
#define PIO_PA10                   (1u << 10) /**< \brief Pin Controlled by PA10 */
#define PIO_PA11                   (1u << 11) /**< \brief Pin Controlled by PA11 */
#define PIO_PA12                   (1u << 12) /**< \brief Pin Controlled by PA12 */
#define PIO_PA13                   (1u << 13) /**< \brief Pin Controlled by PA13 */
#define PIO_PA14                   (1u << 14) /**< \brief Pin Controlled by PA14 */
#define PIO_PA15                   (1u << 15) /**< \brief Pin Controlled by PA15 */
#define PIO_PA16                   (1u << 16) /**< \brief Pin Controlled by PA16 */
#define PIO_PA17                   (1u << 17) /**< \brief Pin Controlled by PA17 */
#define PIO_PA18                   (1u << 18) /**< \brief Pin Controlled by PA18 */
#define PIO_PA19                   (1u << 19) /**< \brief Pin Controlled by PA19 */
#define PIO_PA20                   (1u << 20) /**< \brief Pin Controlled by PA20 */
#define PIO_PA21                   (1u << 21) /**< \brief Pin Controlled by PA21 */
#define PIO_PA22                   (1u << 22) /**< \brief Pin Controlled by PA22 */
#define PIO_PA23                   (1u << 23) /**< \brief Pin Controlled by PA23 */
#define PIO_PA24                   (1u << 24) /**< \brief Pin Controlled by PA24 */
#define PIO_PA25                   (1u << 25) /**< \brief Pin Controlled by PA25 */
#define PIO_PA26                   (1u << 26) /**< \brief Pin Controlled by PA26 */
#define PIO_PA27                   (1u << 27) /**< \brief Pin Controlled by PA27 */
#define PIO_PA28                   (1u << 28) /**< \brief Pin Controlled by PA28 */
#define PIO_PA29                   (1u << 29) /**< \brief Pin Controlled by PA29 */
#define PIO_PA30                   (1u << 30) /**< \brief Pin Controlled by PA30 */
#define PIO_PA31                   (1u << 31) /**< \brief Pin Controlled by PA31 */
#define PIO_PB0                    (1u << 0)  /**< \brief Pin Controlled by PB0 */
#define PIO_PB1                    (1u << 1)  /**< \brief Pin Controlled by PB1 */
#define PIO_PB2                    (1u << 2)  /**< \brief Pin Controlled by PB2 */
#define PIO_PB3                    (1u << 3)  /**< \brief Pin Controlled by PB3 */
#define PIO_PB4                    (1u << 4)  /**< \brief Pin Controlled by PB4 */
#define PIO_PB5                    (1u << 5)  /**< \brief Pin Controlled by PB5 */
#define PIO_PB6                    (1u << 6)  /**< \brief Pin Controlled by PB6 */
#define PIO_PB7                    (1u << 7)  /**< \brief Pin Controlled by PB7 */
#define PIO_PB8                    (1u << 8)  /**< \brief Pin Controlled by PB8 */
#define PIO_PB9                    (1u << 9)  /**< \brief Pin Controlled by PB9 */
#define PIO_PB10                   (1u << 10) /**< \brief Pin Controlled by PB10 */
#define PIO_PB11                   (1u << 11) /**< \brief Pin Controlled by PB11 */
#define PIO_PB12                   (1u << 12) /**< \brief Pin Controlled by PB12 */
#define PIO_PB13                   (1u << 13) /**< \brief Pin Controlled by PB13 */
#define PIO_PB14                   (1u << 14) /**< \brief Pin Controlled by PB14 */
#define PIO_PC0                    (1u << 0)  /**< \brief Pin Controlled by PC0 */
#define PIO_PC1                    (1u << 1)  /**< \brief Pin Controlled by PC1 */
#define PIO_PC2                    (1u << 2)  /**< \brief Pin Controlled by PC2 */
#define PIO_PC3                    (1u << 3)  /**< \brief Pin Controlled by PC3 */
#define PIO_PC4                    (1u << 4)  /**< \brief Pin Controlled by PC4 */
#define PIO_PC5                    (1u << 5)  /**< \brief Pin Controlled by PC5 */
#define PIO_PC6                    (1u << 6)  /**< \brief Pin Controlled by PC6 */
#define PIO_PC7                    (1u << 7)  /**< \brief Pin Controlled by PC7 */
#define PIO_PC8                    (1u << 8)  /**< \brief Pin Controlled by PC8 */
#define PIO_PC9                    (1u << 9)  /**< \brief Pin Controlled by PC9 */
#define PIO_PC10                   (1u << 10) /**< \brief Pin Controlled by PC10 */
#define PIO_PC11                   (1u << 11) /**< \brief Pin Controlled by PC11 */
#define PIO_PC12                   (1u << 12) /**< \brief Pin Controlled by PC12 */
#define PIO_PC13                   (1u << 13) /**< \brief Pin Controlled by PC13 */
#define PIO_PC14                   (1u << 14) /**< \brief Pin Controlled by PC14 */
#define PIO_PC15                   (1u << 15) /**< \brief Pin Controlled by PC15 */
#define PIO_PC16                   (1u << 16) /**< \brief Pin Controlled by PC16 */
#define PIO_PC17                   (1u << 17) /**< \brief Pin Controlled by PC17 */
#define PIO_PC18                   (1u << 18) /**< \brief Pin Controlled by PC18 */
#define PIO_PC19                   (1u << 19) /**< \brief Pin Controlled by PC19 */
#define PIO_PC20                   (1u << 20) /**< \brief Pin Controlled by PC20 */
#define PIO_PC21                   (1u << 21) /**< \brief Pin Controlled by PC21 */
#define PIO_PC22                   (1u << 22) /**< \brief Pin Controlled by PC22 */
#define PIO_PC23                   (1u << 23) /**< \brief Pin Controlled by PC23 */
#define PIO_PC24                   (1u << 24) /**< \brief Pin Controlled by PC24 */
#define PIO_PC25                   (1u << 25) /**< \brief Pin Controlled by PC25 */
#define PIO_PC26                   (1u << 26) /**< \brief Pin Controlled by PC26 */
#define PIO_PC27                   (1u << 27) /**< \brief Pin Controlled by PC27 */
#define PIO_PC28                   (1u << 28) /**< \brief Pin Controlled by PC28 */
#define PIO_PC29                   (1u << 29) /**< \brief Pin Controlled by PC29 */
#define PIO_PC30                   (1u << 30) /**< \brief Pin Controlled by PC30 */
#define PIO_PC31                   (1u << 31) /**< \brief Pin Controlled by PC31 */
/* ========== Pio definition for ADC peripheral ========== */
#define PIO_PA17X1_AD0             (1u << 17) /**< \brief Adc signal: AD0 */ 
#define PIO_PA18X1_AD1             (1u << 18) /**< \brief Adc signal: AD1 */ 
#define PIO_PC13X1_AD10            (1u << 13) /**< \brief Adc signal: AD10 */ 
#define PIO_PC15X1_AD11            (1u << 15) /**< \brief Adc signal: AD11 */ 
#define PIO_PC12X1_AD12            (1u << 12) /**< \brief Adc signal: AD12 */ 
#define PIO_PC29X1_AD13            (1u << 29) /**< \brief Adc signal: AD13 */ 
#define PIO_PC30X1_AD14            (1u << 30) /**< \brief Adc signal: AD14 */ 
#define PIO_PA19X1_AD2_WKUP9       (1u << 19) /**< \brief Adc signal: AD2/WKUP9 */ 
#define PIO_PA20X1_AD3_WKUP10      (1u << 20) /**< \brief Adc signal: AD3/WKUP10 */ 
#define PIO_PB0X1_AD4              (1u << 0)  /**< \brief Adc signal: AD4 */ 
#define PIO_PB1X1_AD5              (1u << 1)  /**< \brief Adc signal: AD5 */ 
#define PIO_PB2X1_AD6_WKUP12       (1u << 2)  /**< \brief Adc signal: AD6/WKUP12 */ 
#define PIO_PB3X1_AD7              (1u << 3)  /**< \brief Adc signal: AD7 */ 
#define PIO_PA21X1_AD8             (1u << 21) /**< \brief Adc signal: AD8 */ 
#define PIO_PA22X1_AD9             (1u << 22) /**< \brief Adc signal: AD9 */ 
#define PIO_PA8B_ADTRG             (1u << 8)  /**< \brief Adc signal: ADTRG */ 
/* ========== Pio definition for DACC peripheral ========== */
#define PIO_PB13X1_DAC0            (1u << 13) /**< \brief Dacc signal: DAC0 */ 
#define PIO_PB14X1_DAC1            (1u << 14) /**< \brief Dacc signal: DAC1 */ 
#define PIO_PA2C_DATRG             (1u << 2)  /**< \brief Dacc signal: DATRG */ 
/* ========== Pio definition for EBI peripheral ========== */
#define PIO_PC18A_A0               (1u << 18) /**< \brief Ebi signal: A0 */ 
#define PIO_PC19A_A1               (1u << 19) /**< \brief Ebi signal: A1 */ 
#define PIO_PC28A_A10              (1u << 28) /**< \brief Ebi signal: A10 */ 
#define PIO_PC29A_A11              (1u << 29) /**< \brief Ebi signal: A11 */ 
#define PIO_PC30A_A12              (1u << 30) /**< \brief Ebi signal: A12 */ 
#define PIO_PC31A_A13              (1u << 31) /**< \brief Ebi signal: A13 */ 
#define PIO_PA18C_A14              (1u << 18) /**< \brief Ebi signal: A14 */ 
#define PIO_PA19C_A15              (1u << 19) /**< \brief Ebi signal: A15 */ 
#define PIO_PA20C_A16              (1u << 20) /**< \brief Ebi signal: A16 */ 
#define PIO_PA0C_A17               (1u << 0)  /**< \brief Ebi signal: A17 */ 
#define PIO_PA1C_A18               (1u << 1)  /**< \brief Ebi signal: A18 */ 
#define PIO_PA23C_A19              (1u << 23) /**< \brief Ebi signal: A19 */ 
#define PIO_PC20A_A2               (1u << 20) /**< \brief Ebi signal: A2 */ 
#define PIO_PA24C_A20              (1u << 24) /**< \brief Ebi signal: A20 */ 
#define PIO_PC16A_A21_NANDALE      (1u << 16) /**< \brief Ebi signal: A21/NANDALE */ 
#define PIO_PC17A_A22_NANDCLE      (1u << 17) /**< \brief Ebi signal: A22/NANDCLE */ 
#define PIO_PA25C_A23              (1u << 25) /**< \brief Ebi signal: A23 */ 
#define PIO_PC21A_A3               (1u << 21) /**< \brief Ebi signal: A3 */ 
#define PIO_PC22A_A4               (1u << 22) /**< \brief Ebi signal: A4 */ 
#define PIO_PC23A_A5               (1u << 23) /**< \brief Ebi signal: A5 */ 
#define PIO_PC24A_A6               (1u << 24) /**< \brief Ebi signal: A6 */ 
#define PIO_PC25A_A7               (1u << 25) /**< \brief Ebi signal: A7 */ 
#define PIO_PC26A_A8               (1u << 26) /**< \brief Ebi signal: A8 */ 
#define PIO_PC27A_A9               (1u << 27) /**< \brief Ebi signal: A9 */ 
#define PIO_PC0A_D0                (1u << 0)  /**< \brief Ebi signal: D0 */ 
#define PIO_PC1A_D1                (1u << 1)  /**< \brief Ebi signal: D1 */ 
#define PIO_PC2A_D2                (1u << 2)  /**< \brief Ebi signal: D2 */ 
#define PIO_PC3A_D3                (1u << 3)  /**< \brief Ebi signal: D3 */ 
#define PIO_PC4A_D4                (1u << 4)  /**< \brief Ebi signal: D4 */ 
#define PIO_PC5A_D5                (1u << 5)  /**< \brief Ebi signal: D5 */ 
#define PIO_PC6A_D6                (1u << 6)  /**< \brief Ebi signal: D6 */ 
#define PIO_PC7A_D7                (1u << 7)  /**< \brief Ebi signal: D7 */ 
#define PIO_PC9A_NANDOE            (1u << 9)  /**< \brief Ebi signal: NANDOE */ 
#define PIO_PC10A_NANDWE           (1u << 10) /**< \brief Ebi signal: NANDWE */ 
#define PIO_PC14A_NCS0             (1u << 14) /**< \brief Ebi signal: NCS0 */ 
#define PIO_PC15A_NCS1             (1u << 15) /**< \brief Ebi signal: NCS1 */ 
#define PIO_PA22C_NCS2             (1u << 22) /**< \brief Ebi signal: NCS2 */ 
#define PIO_PC12A_NCS3             (1u << 12) /**< \brief Ebi signal: NCS3 */ 
#define PIO_PC11A_NRD              (1u << 11) /**< \brief Ebi signal: NRD */ 
#define PIO_PC13A_NWAIT            (1u << 13) /**< \brief Ebi signal: NWAIT */ 
#define PIO_PC8A_NWE               (1u << 8)  /**< \brief Ebi signal: NWE */ 
/* ========== Pio definition for HSMCI peripheral ========== */
#define PIO_PA28C_MCCDA            (1u << 28) /**< \brief Hsmci signal: MCCDA */ 
#define PIO_PA29C_MCCK             (1u << 29) /**< \brief Hsmci signal: MCCK */ 
#define PIO_PA30C_MCDA0            (1u << 30) /**< \brief Hsmci signal: MCDA0 */ 
#define PIO_PA31C_MCDA1            (1u << 31) /**< \brief Hsmci signal: MCDA1 */ 
#define PIO_PA26C_MCDA2            (1u << 26) /**< \brief Hsmci signal: MCDA2 */ 
#define PIO_PA27C_MCDA3            (1u << 27) /**< \brief Hsmci signal: MCDA3 */ 
/* ========== Pio definition for PIOA peripheral ========== */
#define PIO_PA24X1_PIODC0          (1u << 24) /**< \brief Pioa signal: PIODC0 */ 
#define PIO_PA25X1_PIODC1          (1u << 25) /**< \brief Pioa signal: PIODC1 */ 
#define PIO_PA26X1_PIODC2          (1u << 26) /**< \brief Pioa signal: PIODC2 */ 
#define PIO_PA27X1_PIODC3          (1u << 27) /**< \brief Pioa signal: PIODC3 */ 
#define PIO_PA28X1_PIODC4          (1u << 28) /**< \brief Pioa signal: PIODC4 */ 
#define PIO_PA29X1_PIODC5          (1u << 29) /**< \brief Pioa signal: PIODC5 */ 
#define PIO_PA31X1_PIODC7          (1u << 31) /**< \brief Pioa signal: PIODC7 */ 
#define PIO_PA23X1_PIODCCLK        (1u << 23) /**< \brief Pioa signal: PIODCCLK */ 
#define PIO_PA30X1_WKUP11_PIODC6   (1u << 30) /**< \brief Pioa signal: WKUP11/PIODC6 */ 
#define PIO_PA15X1_WKUP14_PIODCEN1 (1u << 15) /**< \brief Pioa signal: WKUP14/PIODCEN1 */ 
#define PIO_PA16X1_WKUP15_PIODCEN2 (1u << 16) /**< \brief Pioa signal: WKUP15/PIODCEN2 */ 
/* ========== Pio definition for PMC peripheral ========== */
#define PIO_PA6B_PCK0              (1u << 6)  /**< \brief Pmc signal: PCK0 */ 
#define PIO_PB13B_PCK0             (1u << 13) /**< \brief Pmc signal: PCK0 */ 
#define PIO_PA17B_PCK1             (1u << 17) /**< \brief Pmc signal: PCK1 */ 
#define PIO_PA21B_PCK1             (1u << 21) /**< \brief Pmc signal: PCK1 */ 
#define PIO_PA18B_PCK2             (1u << 18) /**< \brief Pmc signal: PCK2 */ 
#define PIO_PA31B_PCK2             (1u << 31) /**< \brief Pmc signal: PCK2 */ 
#define PIO_PB3B_PCK2              (1u << 3)  /**< \brief Pmc signal: PCK2 */ 
/* ========== Pio definition for PWM peripheral ========== */
#define PIO_PA9C_PWMFI0            (1u << 9)  /**< \brief Pwm signal: PWMFI0 */ 
#define PIO_PA0A_PWMH0             (1u << 0)  /**< \brief Pwm signal: PWMH0 */ 
#define PIO_PA11B_PWMH0            (1u << 11) /**< \brief Pwm signal: PWMH0 */ 
#define PIO_PA23B_PWMH0            (1u << 23) /**< \brief Pwm signal: PWMH0 */ 
#define PIO_PB0A_PWMH0             (1u << 0)  /**< \brief Pwm signal: PWMH0 */ 
#define PIO_PC18B_PWMH0            (1u << 18) /**< \brief Pwm signal: PWMH0 */ 
#define PIO_PA1A_PWMH1             (1u << 1)  /**< \brief Pwm signal: PWMH1 */ 
#define PIO_PA12B_PWMH1            (1u << 12) /**< \brief Pwm signal: PWMH1 */ 
#define PIO_PA24B_PWMH1            (1u << 24) /**< \brief Pwm signal: PWMH1 */ 
#define PIO_PB1A_PWMH1             (1u << 1)  /**< \brief Pwm signal: PWMH1 */ 
#define PIO_PC19B_PWMH1            (1u << 19) /**< \brief Pwm signal: PWMH1 */ 
#define PIO_PA2A_PWMH2             (1u << 2)  /**< \brief Pwm signal: PWMH2 */ 
#define PIO_PA13B_PWMH2            (1u << 13) /**< \brief Pwm signal: PWMH2 */ 
#define PIO_PA25B_PWMH2            (1u << 25) /**< \brief Pwm signal: PWMH2 */ 
#define PIO_PB4B_PWMH2             (1u << 4)  /**< \brief Pwm signal: PWMH2 */ 
#define PIO_PC20B_PWMH2            (1u << 20) /**< \brief Pwm signal: PWMH2 */ 
#define PIO_PA7B_PWMH3             (1u << 7)  /**< \brief Pwm signal: PWMH3 */ 
#define PIO_PA14B_PWMH3            (1u << 14) /**< \brief Pwm signal: PWMH3 */ 
#define PIO_PA17C_PWMH3            (1u << 17) /**< \brief Pwm signal: PWMH3 */ 
#define PIO_PB14B_PWMH3            (1u << 14) /**< \brief Pwm signal: PWMH3 */ 
#define PIO_PC21B_PWMH3            (1u << 21) /**< \brief Pwm signal: PWMH3 */ 
#define PIO_PA19B_PWML0            (1u << 19) /**< \brief Pwm signal: PWML0 */ 
#define PIO_PB5B_PWML0             (1u << 5)  /**< \brief Pwm signal: PWML0 */ 
#define PIO_PC0B_PWML0             (1u << 0)  /**< \brief Pwm signal: PWML0 */ 
#define PIO_PC13B_PWML0            (1u << 13) /**< \brief Pwm signal: PWML0 */ 
#define PIO_PA20B_PWML1            (1u << 20) /**< \brief Pwm signal: PWML1 */ 
#define PIO_PB12A_PWML1            (1u << 12) /**< \brief Pwm signal: PWML1 */ 
#define PIO_PC1B_PWML1             (1u << 1)  /**< \brief Pwm signal: PWML1 */ 
#define PIO_PC15B_PWML1            (1u << 15) /**< \brief Pwm signal: PWML1 */ 
#define PIO_PA16C_PWML2            (1u << 16) /**< \brief Pwm signal: PWML2 */ 
#define PIO_PA30A_PWML2            (1u << 30) /**< \brief Pwm signal: PWML2 */ 
#define PIO_PB13A_PWML2            (1u << 13) /**< \brief Pwm signal: PWML2 */ 
#define PIO_PC2B_PWML2             (1u << 2)  /**< \brief Pwm signal: PWML2 */ 
#define PIO_PA15C_PWML3            (1u << 15) /**< \brief Pwm signal: PWML3 */ 
#define PIO_PC3B_PWML3             (1u << 3)  /**< \brief Pwm signal: PWML3 */ 
#define PIO_PC22B_PWML3            (1u << 22) /**< \brief Pwm signal: PWML3 */ 
/* ========== Pio definition for SPI peripheral ========== */
#define PIO_PA12A_MISO             (1u << 12) /**< \brief Spi signal: MISO */ 
#define PIO_PA13A_MOSI             (1u << 13) /**< \brief Spi signal: MOSI */ 
#define PIO_PA11A_NPCS0            (1u << 11) /**< \brief Spi signal: NPCS0 */ 
#define PIO_PA9B_NPCS1             (1u << 9)  /**< \brief Spi signal: NPCS1 */ 
#define PIO_PA31A_NPCS1            (1u << 31) /**< \brief Spi signal: NPCS1 */ 
#define PIO_PB14A_NPCS1            (1u << 14) /**< \brief Spi signal: NPCS1 */ 
#define PIO_PC4B_NPCS1             (1u << 4)  /**< \brief Spi signal: NPCS1 */ 
#define PIO_PA10B_NPCS2            (1u << 10) /**< \brief Spi signal: NPCS2 */ 
#define PIO_PA30B_NPCS2            (1u << 30) /**< \brief Spi signal: NPCS2 */ 
#define PIO_PB2B_NPCS2             (1u << 2)  /**< \brief Spi signal: NPCS2 */ 
#define PIO_PA3B_NPCS3             (1u << 3)  /**< \brief Spi signal: NPCS3 */ 
#define PIO_PA5B_NPCS3             (1u << 5)  /**< \brief Spi signal: NPCS3 */ 
#define PIO_PA22B_NPCS3            (1u << 22) /**< \brief Spi signal: NPCS3 */ 
#define PIO_PA14A_SPCK             (1u << 14) /**< \brief Spi signal: SPCK */ 
/* ========== Pio definition for SSC peripheral ========== */
#define PIO_PA18A_RD               (1u << 18) /**< \brief Ssc signal: RD */ 
#define PIO_PA20A_RF               (1u << 20) /**< \brief Ssc signal: RF */ 
#define PIO_PA19A_RK               (1u << 19) /**< \brief Ssc signal: RK */ 
#define PIO_PA17A_TD               (1u << 17) /**< \brief Ssc signal: TD */ 
#define PIO_PA15A_TF               (1u << 15) /**< \brief Ssc signal: TF */ 
#define PIO_PA16A_TK               (1u << 16) /**< \brief Ssc signal: TK */ 
/* ========== Pio definition for TC0 peripheral ========== */
#define PIO_PA4B_TCLK0             (1u << 4)  /**< \brief Tc0 signal: TCLK0 */ 
#define PIO_PA28B_TCLK1            (1u << 28) /**< \brief Tc0 signal: TCLK1 */ 
#define PIO_PA29B_TCLK2            (1u << 29) /**< \brief Tc0 signal: TCLK2 */ 
#define PIO_PA0B_TIOA0             (1u << 0)  /**< \brief Tc0 signal: TIOA0 */ 
#define PIO_PA15B_TIOA1            (1u << 15) /**< \brief Tc0 signal: TIOA1 */ 
#define PIO_PA26B_TIOA2            (1u << 26) /**< \brief Tc0 signal: TIOA2 */ 
#define PIO_PA1B_TIOB0             (1u << 1)  /**< \brief Tc0 signal: TIOB0 */ 
#define PIO_PA16B_TIOB1            (1u << 16) /**< \brief Tc0 signal: TIOB1 */ 
#define PIO_PA27B_TIOB2            (1u << 27) /**< \brief Tc0 signal: TIOB2 */ 
/* ========== Pio definition for TC1 peripheral ========== */
#define PIO_PC25B_TCLK3            (1u << 25) /**< \brief Tc1 signal: TCLK3 */ 
#define PIO_PC28B_TCLK4            (1u << 28) /**< \brief Tc1 signal: TCLK4 */ 
#define PIO_PC31B_TCLK5            (1u << 31) /**< \brief Tc1 signal: TCLK5 */ 
#define PIO_PC23B_TIOA3            (1u << 23) /**< \brief Tc1 signal: TIOA3 */ 
#define PIO_PC26B_TIOA4            (1u << 26) /**< \brief Tc1 signal: TIOA4 */ 
#define PIO_PC29B_TIOA5            (1u << 29) /**< \brief Tc1 signal: TIOA5 */ 
#define PIO_PC24B_TIOB3            (1u << 24) /**< \brief Tc1 signal: TIOB3 */ 
#define PIO_PC27B_TIOB4            (1u << 27) /**< \brief Tc1 signal: TIOB4 */ 
#define PIO_PC30B_TIOB5            (1u << 30) /**< \brief Tc1 signal: TIOB5 */ 
/* ========== Pio definition for TWI0 peripheral ========== */
#define PIO_PA4A_TWCK0             (1u << 4)  /**< \brief Twi0 signal: TWCK0 */ 
#define PIO_PA3A_TWD0              (1u << 3)  /**< \brief Twi0 signal: TWD0 */ 
/* ========== Pio definition for TWI1 peripheral ========== */
#define PIO_PB5A_TWCK1             (1u << 5)  /**< \brief Twi1 signal: TWCK1 */ 
#define PIO_PB4A_TWD1              (1u << 4)  /**< \brief Twi1 signal: TWD1 */ 
/* ========== Pio definition for UART0 peripheral ========== */
#define PIO_PA9A_URXD0             (1u << 9)  /**< \brief Uart0 signal: URXD0 */ 
#define PIO_PA10A_UTXD0            (1u << 10) /**< \brief Uart0 signal: UTXD0 */ 
/* ========== Pio definition for UART1 peripheral ========== */
#define PIO_PB2A_URXD1             (1u << 2)  /**< \brief Uart1 signal: URXD1 */ 
#define PIO_PB3A_UTXD1             (1u << 3)  /**< \brief Uart1 signal: UTXD1 */ 
/* ========== Pio definition for USART0 peripheral ========== */
#define PIO_PA8A_CTS0              (1u << 8)  /**< \brief Usart0 signal: CTS0 */ 
#define PIO_PA7A_RTS0              (1u << 7)  /**< \brief Usart0 signal: RTS0 */ 
#define PIO_PA5A_RXD0              (1u << 5)  /**< \brief Usart0 signal: RXD0 */ 
#define PIO_PA2B_SCK0              (1u << 2)  /**< \brief Usart0 signal: SCK0 */ 
#define PIO_PA6A_TXD0              (1u << 6)  /**< \brief Usart0 signal: TXD0 */ 
/* ========== Pio definition for USART1 peripheral ========== */
#define PIO_PA25A_CTS1             (1u << 25) /**< \brief Usart1 signal: CTS1 */ 
#define PIO_PA26A_DCD1             (1u << 26) /**< \brief Usart1 signal: DCD1 */ 
#define PIO_PA28A_DSR1             (1u << 28) /**< \brief Usart1 signal: DSR1 */ 
#define PIO_PA27A_DTR1             (1u << 27) /**< \brief Usart1 signal: DTR1 */ 
#define PIO_PA29A_RI1              (1u << 29) /**< \brief Usart1 signal: RI1 */ 
#define PIO_PA24A_RTS1             (1u << 24) /**< \brief Usart1 signal: RTS1 */ 
#define PIO_PA21A_RXD1             (1u << 21) /**< \brief Usart1 signal: RXD1 */ 
#define PIO_PA23A_SCK1             (1u << 23) /**< \brief Usart1 signal: SCK1 */ 
#define PIO_PA22A_TXD1             (1u << 22) /**< \brief Usart1 signal: TXD1 */ 
/*@}*/

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAM3S16 */
/* ************************************************************************** */

#define IFLASH_SIZE 0x100000
#define IRAM_SIZE   0x20000

#define IFLASH_ADDR  (0x00400000u) /**< Internal Flash base address */
#define IROM_ADDR    (0x00800000u) /**< Internal ROM base address */
#define IRAM_ADDR    (0x20000000u) /**< Internal RAM base address */
#define EBI_CS0_ADDR (0x60000000u) /**< EBI Chip Select 0 base address */
#define EBI_CS1_ADDR (0x61000000u) /**< EBI Chip Select 1 base address */
#define EBI_CS2_ADDR (0x62000000u) /**< EBI Chip Select 2 base address */
#define EBI_CS3_ADDR (0x63000000u) /**< EBI Chip Select 3 base address */

#define IFLASH_PAGE_SIZE        512
#define IFLASH_LOCK_REGION_SIZE 32768
#define IFLASH_NB_OF_PAGES      2048
#define IFLASH_NB_OF_LOCK_BITS  32

#ifdef __cplusplus
}
#endif

/*@}*/

#endif /* SAM3S16_H */
