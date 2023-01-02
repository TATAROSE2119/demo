//
// Created by Maxwell on 2022-12-24.
//
#include "key.h"


uint8_t KEY_Scan(uint8_t mode)
{
    static uint8_t key_up = 1;//按键按松开标志
    if (mode)key_up = 1;  //支持连按
    if (key_up && (KEY1 == KEY_ON || KEY2 == KEY_ON) )
    {
        HAL_Delay(5);//去抖动
        key_up = 0;
        if (KEY1 == KEY_ON) return KEY1_PRES;
        else if (KEY2 == KEY_ON) return KEY2_PRES;
    } else if (KEY1 == KEY_OFF && KEY2 == KEY_OFF )key_up = 1;
    return 0;// 无按键按下
}