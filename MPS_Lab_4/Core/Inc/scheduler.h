/*
 * scheduler.h
 *
 *  Created on: May 19, 2024
 *      Author: nguyen minh hung
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "stm32f1xx_hal.h"

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);

#endif /* SCHEDULER_H */
