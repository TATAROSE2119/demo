//
// Created by Maxwell on 2022-12-23.
//

#ifndef DEMO1_LED_H
#define DEMO1_LED_H

#include "main.h"

#define LED_R_Pin           GPIO_PIN_6
#define LED_R_GPIO_Port     GPIOF
#define LED_G_Pin           GPIO_PIN_7
#define LED_G_GPIO_Port     GPIOF
#define LED_B_Pin           GPIO_PIN_8
#define LED_B_GPIO_Port     GPIOF

void LED_R_ON();
void LED_G_ON();
void LED_B_ON();

void LED_R_OFF();
void LED_G_OFF();
void LED_B_OFF();

void LED_R_TOG();
void LED_G_TOG();
void LED_B_TOG();

#endif //DEMO1_LED_H
