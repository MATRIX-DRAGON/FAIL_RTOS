/*
 * user_os_kernal.h
 *
 *  Created on: Jan 21, 2026
 *  Author: rony paul chakiyath
 */

#ifndef USER_OS_KERNAL_H_
#define USER_OS_KERNAL_H_

#include<stdint.h>
#include "stm32f4xx.h"

void os_kernel_init(void);
uint8_t os_kernal_add_thread(void(*thread0)(void),void(*thread1)(void),void(*thread2)(void));
void os_kernal_lanch(uint32_t quanta);
#endif /* USER_OS_KERNAL_H_ */
