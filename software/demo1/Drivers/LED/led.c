//
// Created by Maxwell on 2022-12-23.
//
#include "led.h"

void LED_R_ON()
{
    HAL_GPIO_WritePin(LED_R_GPIO_Port,LED_R_Pin,GPIO_PIN_RESET);
}
void LED_G_ON()
{
    HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin,GPIO_PIN_RESET);
}
void LED_B_ON()
{
    HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin,GPIO_PIN_RESET);
}

void LED_R_OFF()
{
    HAL_GPIO_WritePin(LED_R_GPIO_Port,LED_R_Pin,GPIO_PIN_SET);

}
void LED_G_OFF()
{
    HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin,GPIO_PIN_SET);

}
void LED_B_OFF()
{
    HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin,GPIO_PIN_SET);

}

void LED_R_TOG()
{
    HAL_GPIO_TogglePin(LED_R_GPIO_Port,LED_R_Pin);
}
void LED_G_TOG()
{
    HAL_GPIO_TogglePin(LED_G_GPIO_Port,LED_G_Pin);
}
void LED_B_TOG()
{
    HAL_GPIO_TogglePin(LED_B_GPIO_Port,LED_B_Pin);

}


