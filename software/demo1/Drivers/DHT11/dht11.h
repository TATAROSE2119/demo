//
// Created by Maxwell on 2022-12-29.
//

#ifndef DEMO1_DHT11_H
#define DEMO1_DHT11_H
#include "main.h"
#include "tim.h"
void Delay_us(uint16_t delay);                   //通过TIM3定时器微秒级延时
void Dht11_DATA_OUT(void);                       //设置数据交互口为输出
void Dht11_DATA_IN(void);                        //设置数据交互口为输入
void DHT11_Rst(void);                            //复位DHT11
uint8_t DHT11_Check(void);                       //DHT11状态反馈
uint8_t DHT11_Read_Bit(void);                    //读DHT11一位数据
uint8_t DHT11_Read_Byte(void);                   //读DHT11一字节数据
uint8_t DHT11_Read_Data(uint8_t* humi,uint8_t* temp);     //DHT11数据显示
#endif //DEMO1_DHT11_H
