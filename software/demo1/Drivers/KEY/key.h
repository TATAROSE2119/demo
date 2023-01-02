//
// Created by Maxwell on 2022-12-24.
//

#ifndef DEMO1_KEY_H
#define DEMO1_KEY_H

#include "main.h"
#define KEY_ON  1
#define KEY_OFF 0

#define KEY1  HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)   //读取按键1
#define KEY2  HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)   //读取按键2

#define KEY1_PRES	1	//KEY1按下
#define KEY2_PRES	2	//KEY2按下

uint8_t KEY_Scan(uint8_t mode);


#endif //DEMO1_KEY_H
