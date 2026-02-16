/*
 * Joystick.h
 *
 *  Created on: Jan 16, 2026
 *      Author: H
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "stm32f3xx_hal.h"
#include <stdint.h>
/* ===== Public variables ===== */
extern uint16_t joystick1_x;
extern uint16_t joystick1_y;
extern uint8_t  joystick1_button;
extern uint16_t joystick2_x;
extern uint16_t joystick2_y;
extern uint8_t  joystick2_button;

/* ===== Public functions ===== */
void Joystick_Init(void);
void Joystick_Update(void);

#endif /* INC_JOYSTICK_H_ */
