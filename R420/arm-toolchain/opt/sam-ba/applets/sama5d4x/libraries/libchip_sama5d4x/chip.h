#ifndef _LIB_CHIP_SAMA5D4_
#define _LIB_CHIP_SAMA5D4_

/*
 * Peripherals registers definitions
 */
#if defined sama5d4x
    #include "include/SAMA5D4.h"
#else
    #warning Library does not support the specified chip, specifying sama5d4x.
    #define sama5d4x
    #include "include/SAMA5D4.h"
#endif


/* Define attribute */
#if defined   ( __CC_ARM   ) /* Keil vision 4 */
    #define WEAK __attribute__ ((weak))
#elif defined ( __ICCARM__ ) /* IAR Ewarm 5.41+ */
    #define WEAK __weak
#elif defined (  __GNUC__  ) /* GCC CS3 2009q3-68 */
    #define WEAK __attribute__ ((weak))
#endif

/* Define NO_INIT attribute and compiler specific symbols */
#if defined   ( __CC_ARM   )
    #define NO_INIT
    #define __ASM            __asm                                    /*!< asm keyword for ARM Compiler          */
    #define __INLINE         __inline                                 /*!< inline keyword for ARM Compiler       */
#elif defined ( __ICCARM__ )
    #define NO_INIT __no_init
    #define __ASM           __asm                                     /*!< asm keyword for IAR Compiler           */
    #define __INLINE        inline                                    /*!< inline keyword for IAR Compiler. Only avaiable in High optimization mode! */
#elif defined (  __GNUC__  )
    #define __ASM            asm                                      /*!< asm keyword for GNU Compiler          */
    #define __INLINE         inline                                   /*!< inline keyword for GNU Compiler       */
    #define NO_INIT
#endif

#define CP15_PRESENT

/*
 * Peripherals
 */

#include "include/async.h"
#include "include/pio.h"
#include "include/pmc.h"
#include "include/smcNfc.h"
#include "include/spi.h"
#include "include/twi.h"
#include "include/twid.h"
#include "include/xdmac.h"
#include "include/trace.h"
#include "include/wdt.h"

#endif /* _LIB_CHIP_SAMA5D4_ */
