/*
 * Copyright (C) 2017 Anthony Merlino
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    boards_evb1000 evb1000
 * @ingroup     boards
 * @brief       Board specific files for the evb1000 board
 * @{
 *
 * @file
 * @brief       Board specific definitions for the evb1000 board
 *
 * @author      Anthony Merlino <anthony@vergeaero.com>
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "periph_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief LED pin definitions and handlers
 * @{
 */
#define LED0_PIN            GPIO_PIN(PORT_C, 6)
#define LED0_MASK           (1 << 6) 

#define LED_CREG            BRR
#define LED_SREG            BSRR

#define LED0_ON             (GPIOC->LED_SREG = LED0_MASK)
#define LED0_OFF            (GPIOC->LED_CREG = LED0_MASK)
#define LED0_TOGGLE         (GPIOC->ODR     ^= LED0_MASK)
/** @} */

/**
 * @brief   Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

/**
 * @name xtimer configuration
 */
#define XTIMER_WIDTH        (16)
#define XTIMER_BACKOFF      5
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H_ */
/** @} */
