/*
 * Joystick.c
 *
 *  Created on: Jan 16, 2026
 *      Author: H
 */

#include "Joystick.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
/* ===== CubeMX handles (defined in main.c) ===== */
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

/* ===== Public variables (declared extern in Joystick.h) ===== */
uint16_t joystick1_x = 0;
uint16_t joystick1_y = 0;
uint8_t  joystick1_button = 0;   // TOGGLE state: 0/1
uint16_t joystick2_x = 0;
uint16_t joystick2_y = 0;
uint8_t  joystick2_button = 0;

char buffer [50];

/* ===== Private DMA buffer ===== */
static uint32_t adc_dma_buffer[4] = {0, 0, 0, 0};

void Joystick_Init(void)
{
	 HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_dma_buffer, 4);
}

void Joystick_Update(void)
{
    /* ADC mapping (same as your original) */
    joystick1_x = (uint16_t)adc_dma_buffer[0];
    joystick1_y = (uint16_t)adc_dma_buffer[1];
    joystick1_button = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);

    joystick2_x = (uint16_t)adc_dma_buffer[2];
    joystick2_y = (uint16_t)adc_dma_buffer[3];
    joystick2_button = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);

    snprintf(buffer, sizeof(buffer),"J1:(%d,%d,B:%d)  J2:(%d,%d,B:%d)\r\n",joystick1_x, joystick1_y, joystick1_button,joystick2_x, joystick2_y, joystick2_button);

    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
    HAL_Delay(500);
}
