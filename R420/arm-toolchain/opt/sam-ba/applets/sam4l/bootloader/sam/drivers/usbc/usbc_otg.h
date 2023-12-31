/**
 * \file
 *
 * \brief USBC OTG Driver header file.
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _USBC_OTG_H_
#define _USBC_OTG_H_

#include "compiler.h"
#include "preprocessor.h"

// These defines are missing in the toolchain header files
#ifndef USBC_EPT_NUM
#  define USBC_EPT_NUM 7
#endif

// To simplify the macros definition of this file
#define USBC_CLR_BITS(reg, bit) \
		(Clr_bits(USBC->reg,\
		(uint32_t)TPASTE4(USBC_,reg,_,bit)))
#define USBC_SET_BITS(reg, bit) \
		(Set_bits(USBC->reg,\
		(uint32_t)TPASTE4(USBC_,reg,_,bit)))
#define USBC_TST_BITS(reg, bit) \
		(Tst_bits(USBC->reg,\
		(uint32_t)TPASTE4(USBC_,reg,_,bit)))
#define USBC_RD_BITFIELD(reg, bit) \
		((Rd_bits(USBC->reg,\
		TPASTE5(USBC_,reg,_,bit,_Msk))) >> TPASTE5(USBC_,reg,_,bit,_Pos))
#define USBC_WR_BITFIELD(reg, bit, value) \
		(Wr_bits(USBC->reg,\
		(uint32_t)TPASTE5(USBC_,reg,_,bit,_Msk), (value << TPASTE5(USBC_,reg,_,bit,_Pos))))
#define USBC_REG_CLR(reg, bit) \
		((USBC->TPASTE2(reg,CLR)) =\
		(uint32_t)TPASTE5(USBC_,reg,CLR_,bit,C))
#define USBC_REG_SET(reg, bit) \
		((USBC->TPASTE2(reg,SET)) =\
		(uint32_t)TPASTE5(USBC_,reg,SET_,bit,S))

//! \ingroup usb_group
//! \defgroup otg_group USB OTG Driver (OTG)
//! USBC low-level driver for OTG features
//!
//! @warning Bit-masks are used instead of bit-fields because PB registers
//! require 32-bit write accesses while AVR32-GCC 4.0.2 builds 8-bit
//! accesses even when volatile unsigned int bit-fields are specified.
//! @{

/**
 * \brief Initialize the dual role
 * This function is implemented in usbc_host.c file.
 *
 * \return \c true if the ID pin management has been started, otherwise \c false.
 */
bool otg_dual_enable(void);

/**
 * \brief Uninitialize the dual role
 * This function is implemented in usbc_host.c file.
 */
void otg_dual_disable(void);

//! @name USBC IP properties
//! These macros give access to IP properties
//! @{

//! Get IP name part 1 or 2
#define  otg_get_ip_name() \
		(((uint64_t)USBC->UNAME2<<32)|(uint64_t)USBC->UNAME1)
//! Instruction to access at a peripheral register after interrupt clear,
//! see AVR32002 - AVR32UC Technical reference $6.6 Memory barriers
#define  otg_data_memory_barrier()           (USBC->UVERS)
//! Get IP version
#define  otg_get_ip_version()                USBC_RD_BITFIELD(UVERS,VERSION_NUM)
//! Get size of USBC PB address space
#define  otg_get_ip_paddress_size()          (USBC->UADDRSIZE)
//! @}

//! @name USBC OTG ID pin management
//! The ID pin come from the USB OTG connector (A and B receptable) and
//! allows to select the USB mode host or device.
//! The USBC hardware can manage it automaticaly. This feature is optional.
//! When otg_ID_PIN equals true in conf_usb_host.h, the USB_ID must be defined in board.h.
//!
//! @{

//! Pin and function for OTG_ID according to configuration from USB_ID
#define  OTG_ID_PIN                          ATPASTE2(USB_ID, PIN)
#define  OTG_ID_FUNCTION                     ATPASTE2(USB_ID, FUNCTION)

//! Input USB_ID from its pin
#define  otg_input_id_pin() {\
	(Tst_bits(OTG_ID_FUNCTION, 0x01)) ?\
	(AVR32_GPIO.port[OTG_ID_PIN >> 5].pmr0s = 1 << (OTG_ID_PIN & 0x1F)) :\
	(AVR32_GPIO.port[OTG_ID_PIN >> 5].pmr0c = 1 << (OTG_ID_PIN & 0x1F)); \
	(Tst_bits(OTG_ID_FUNCTION, 0x02)) ?\
	(AVR32_GPIO.port[OTG_ID_PIN >> 5].pmr1s = 1 << (OTG_ID_PIN & 0x1F)) :\
	(AVR32_GPIO.port[OTG_ID_PIN >> 5].pmr1c = 1 << (OTG_ID_PIN & 0x1F)); \
	AVR32_GPIO.port[OTG_ID_PIN >> 5].gperc = 1 << (OTG_ID_PIN & 0x1F);\
	AVR32_GPIO.port[OTG_ID_PIN >> 5].puers = 1 << (OTG_ID_PIN & 0x1F); }

#define  otg_force_device_mode()             USBC_SET_BITS(USBCON,UIMOD)
#define  Is_otg_device_mode_forced()         USBC_TST_BITS(USBCON,UIMOD)
#define  otg_force_host_mode()               USBC_CLR_BITS(USBCON,UIMOD)
#define  Is_otg_host_mode_forced()           (!Is_otg_device_mode_forced())

//! @}

//! @name USBC OTG Vbus management
//! @{
#define  Is_otg_vbus_high()                  USBC_TST_BITS(USBSTA,VBUS)
#define  Is_otg_vbus_low()                   (!Is_otg_vbus_high())
//! @}

//! @name USBC OTG main management
//! These macros allows to enable/disable pad and USBC hardware
//! @{
#define  otg_enable()                        USBC_SET_BITS(USBCON,USBE)
#define  otg_disable()                       USBC_CLR_BITS(USBCON,USBE)

#define otg_register_desc_tab(addr) \
		(USBC->UDESC = USBC_UDESC_UDESCA((uint32_t)addr))

//! Check USB interface clock usable
#define  Is_otg_clock_usable()               USBC_TST_BITS(USBSTA,CLKUSABLE)

#define  otg_freeze_clock()                  USBC_SET_BITS(USBCON,FRZCLK)
//#define  otg_freeze_clock()
#define  otg_unfreeze_clock()                USBC_CLR_BITS(USBCON,FRZCLK)
#define  Is_otg_clock_frozen()               USBC_TST_BITS(USBCON,FRZCLK)
//! @}

//! @name USBC OTG hardware protocol
//! These macros manages the hardware OTG protocol
//! @{

//! Configure time-out of specified OTG timer
#define  otg_configure_timeout(timer, timeout) \
		(USBC_SET_BITS(USBCON,UNLOCK),\
		USBC_WR_BITFIELD(USBCON,TIMPAGE,timer),\
		USBC_WR_BITFIELD(USBCON,TIMVALUE,timeout),\
		USBC_CLR_BITS(USBCON,UNLOCK))
//! Get configured time-out of specified OTG timer
#define  otg_get_timeout(timer) \
		(USBC_SET_BITS(USBCON,UNLOCK),\
		USBC_WR_BITFIELD(USBCON,TIMPAGE,timer),\
		USBC_CLR_BITS(USBCON,UNLOCK),\
		USBC_RD_BITFIELD(USBCON,TIMVALUE))
//! Get the dual-role device state of the internal USB finite state machine of the USBC controller
#define  otg_get_fsm_drd_state()             USBC_RD_BITFIELD(USBFSM,DRDSTATE)

//! Host Negociation Protocol
//! @{
#define  otg_device_initiate_hnp()           USBC_SET_BITS(USBCON,HNPREQ)
#define  otg_host_accept_hnp()               USBC_SET_BITS(USBCON,HNPREQ)
#define  otg_host_reject_hnp()               USBC_CLR_BITS(USBCON,HNPREQ)
#define  Is_otg_hnp()                        USBC_TST_BITS(USBCON,HNPREQ)
#define  otg_enable_hnp_error_interrupt()    USBC_SET_BITS(USBCON,HNPERRE)
#define  otg_disable_hnp_error_interrupt()   USBC_CLR_BITS(USBCON,HNPERRE)
#define  Is_otg_hnp_error_interrupt_enabled() USBC_TST_BITS(USBCON,HNPERRE)
#define  otg_ack_hnp_error_interrupt()       USBC_REG_CLR(USBSTA,HNPERRI)
#define  Is_otg_hnp_error_interrupt()        USBC_TST_BITS(USBSTA,HNPERRI)
//! @}

//! Session Request Protocol
//! @{
#define  otg_device_initiate_srp()           USBC_SET_BITS(USBCON,SRPREQ)
#define  Is_otg_device_srp()                 USBC_TST_BITS(USBCON,SRPREQ)
#define  otg_select_vbus_srp_method()        USBC_SET_BITS(USBCON,SRPSEL)
#define  Is_otg_vbus_srp_method_selected()   USBC_TST_BITS(USBCON,SRPSEL)
#define  otg_select_data_srp_method()        USBC_CLR_BITS(USBCON,SRPSEL)
#define  Is_otg_data_srp_method_selected()   (!Is_otg_vbus_srp_method_selected())
#define  otg_enable_srp_interrupt()          USBC_SET_BITS(USBCON,SRPE)
#define  otg_disable_srp_interrupt()         USBC_CLR_BITS(USBCON,SRPE)
#define  Is_otg_srp_interrupt_enabled()      USBC_TST_BITS(USBCON,SRPE)
#define  otg_ack_srp_interrupt()             USBC_REG_CLR(USBSTA,SRPI)
#define  Is_otg_srp_interrupt()              USBC_TST_BITS(USBSTA,SRPI)
//! @}

//! Role exchange interrupt
//! @{
#define  otg_enable_role_exchange_interrupt()     USBC_SET_BITS(USBCON,ROLEEXE)
#define  otg_disable_role_exchange_interrupt()    USBC_CLR_BITS(USBCON,ROLEEXE)
#define  Is_otg_role_exchange_interrupt_enabled() USBC_TST_BITS(USBCON,ROLEEXE)
#define  otg_ack_role_exchange_interrupt()        USBC_REG_CLR(USBSTA,ROLEEXI)
#define  otg_raise_role_exchange_interrupt()      USBC_REG_SET(USBSTA,ROLEEXI)
#define  Is_otg_role_exchange_interrupt()         USBC_TST_BITS(USBSTA,ROLEEXI)
//! @}
//! @}

//! @}

#endif // _USBC_OTG_H_
