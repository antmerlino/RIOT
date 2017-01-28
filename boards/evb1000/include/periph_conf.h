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
 * @brief       Peripheral MCU configuration for the evb1000 board
 *
 * @author      Anthony Merlino <anthony@vergeaero.com>
 */

#ifndef PERIPH_CONF_H_
#define PERIPH_CONF_H_

#include "periph_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Clock system configuration
 * @{
 */
#define CLOCK_HSE           (12000000U)              /* external oscillator */
#define CLOCK_CORECLOCK     (72000000U)             /* desired core clock frequency */

/* the actual PLL values are automatically generated */
#define CLOCK_PLL_DIV       (1)
#define CLOCK_PLL_MUL       (6)
/* AHB, APB1, APB2 dividers */
#define CLOCK_AHB_DIV       RCC_CFGR_HPRE_DIV1
#define CLOCK_APB2_DIV      RCC_CFGR_PPRE2_DIV1
#define CLOCK_APB1_DIV      RCC_CFGR_PPRE1_DIV2    /* max 36 MHz (!) */
/* resulting bus clocks */
#define CLOCK_AHB           (CLOCK_CORECLOCK / 1)
#define CLOCK_APB1          (CLOCK_CORECLOCK / 2)
#define CLOCK_APB2          (CLOCK_CORECLOCK / 1)

/* Flash latency */
#define CLOCK_FLASH_LATENCY FLASH_ACR_LATENCY_2    /* for >= 72 MHz */
/** @} */

/**
 * @name ADC configuration
 * @{
 */
#define ADC_NUMOF           (0)
/** @} */

/**
 * @brief   DAC configuration
 * @{
 */
#define DAC_NUMOF           (0)
/** @} */

/**
 * @brief   Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev      = TIM2,
        .max      = 0x0000ffff,
        .rcc_mask = RCC_APB1ENR_TIM2EN,
        .bus      = APB1,
        .irqn     = TIM2_IRQn
    },
    {
        .dev      = TIM3,
        .max      = 0x0000ffff,
        .rcc_mask = RCC_APB1ENR_TIM3EN,
        .bus      = APB1,
        .irqn     = TIM3_IRQn
    }
};

#define TIMER_0_ISR         isr_tim2
#define TIMER_1_ISR         isr_tim3

#define TIMER_NUMOF         (sizeof(timer_config) / sizeof(timer_config[0]))
/** @} */

/**
 * @brief UART configuration
 * @{
 */
#define UART_NUMOF          0 
/** @} */

/**
 * @name I2C configuration
 * @{
 */
#define I2C_NUMOF           0 
/** @} */

 /**
 * @brief   SPI configuration
 *
 * @note    The spi_divtable is auto-generated from
 *          `cpu/stm32_common/dist/spi_divtable/spi_divtable.c`
 * @{
 */
static const uint8_t spi_divtable[2][5] = {
    {       /* for APB1 @ 36000000Hz */
        7,  /* -> 140625Hz */
        6,  /* -> 281250Hz */
        4,  /* -> 1125000Hz */
        2,  /* -> 4500000Hz */
        1   /* -> 9000000Hz */
    },
    {       /* for APB2 @ 72000000Hz */
        7,  /* -> 281250Hz */
        7,  /* -> 281250Hz */
        5,  /* -> 1125000Hz */
        3,  /* -> 4500000Hz */
        2   /* -> 9000000Hz */
    }
};

static const spi_conf_t spi_config[] = {
    {
        .dev      = SPI1,
        .mosi_pin = GPIO_PIN(PORT_A, 7),
        .miso_pin = GPIO_PIN(PORT_A, 6),
        .sclk_pin = GPIO_PIN(PORT_A, 5),
        .cs_pin   = GPIO_PIN(PORT_A, 4),
        .rccmask  = RCC_APB2ENR_SPI1EN,
        .apbbus   = APB2
    },
    {
        .dev      = SPI2,
        .mosi_pin = GPIO_PIN(PORT_B, 15),
        .miso_pin = GPIO_PIN(PORT_B, 14),
        .sclk_pin = GPIO_PIN(PORT_B, 13),
        .cs_pin   = GPIO_PIN(PORT_B, 12),
        .rccmask  = RCC_APB1ENR_SPI2EN,
        .apbbus   = APB1
    },
};

#define SPI_NUMOF           (sizeof(spi_config) / sizeof(spi_config[0]))
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H_ */
