/*
 * Copyright (C) 2017 Anthony Merlino
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_evb1000
 * @{
 *
 * @file
 * @brief       Board specific implementations for the evb1000 board
 *
 * @author      Anthony Merlino <anthony@vergeaero.com>
 *
 * @}
 */

#include "board.h"
#include "periph/gpio.h"

void board_init(void)
{
    /* initialize the CPU */
    cpu_init();

    /* initialize the boards LEDs */
    gpio_init(LED0_PIN, GPIO_OUT);
}
