/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "D:\Clion-STM32-FILMs\demo1\Drivers\LED\led.h"
#include "D:\Clion-STM32-FILMs\demo1\Drivers\FONT\font.h"
#include "D:\Clion-STM32-FILMs\demo1\Drivers\LCD\lcd.h"
#include "stdio.h"
#include "string.h"

#include "D:\Clion-STM32-FILMs\demo1\Drivers\KEY\key.h"
#include "D:\Clion-STM32-FILMs\demo1\Drivers\DHT11\dht11.h"
#include "D:\Clion-STM32-FILMs\demo1\Drivers\MPU6050\mpu6050.h"
#include "D:\Clion-STM32-FILMs\demo1\Drivers\MPU6050\eMPL\inv_mpu.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart1 , (uint8_t *)&ch, 1, 0xFFFF);

    //HAL_UART_Receive_IT(&huart1, (uint8_t *)&ch, 1);
    return ch;
}

void LCD_Test(void)
{
    /*演示显示变量*/
    static uint8_t testCNT = 0;
    testCNT++;

    LCD_SetFont(&Font16x32);
    LCD_SetColors(RED,WHITE);

    NT35510_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* 清屏，显示全�??????? */
    /********显示字符串示�???????*******/
    NT35510_DispStringLine_EN(LINE(0),"YH 4.3 inch LCD");
    NT35510_DispStringLine_EN(LINE(1),"resolution:480x800px");
    NT35510_DispStringLine_EN(LINE(2),"LCD driver:NT35510");
    NT35510_DispStringLine_EN(LINE(3),"Touch driver:GT917S");
    LCD_SetTextColor(BLACK);
    NT35510_DispStringLine_EN(LINE(4),"LCD READY!");

    /********显示变量示例*******/
    LCD_SetTextColor(GREEN);

    /*使用c标准库把变量转化成字符串*/
//    sprintf(dispBuff,"Count : %d ",testCNT);
//    NT35510_ClearLine(LINE(6));	/* 清除单行文字 */

    /*然后显示该字符串即可，其它变量也是这样处�???????*/
//    NT35510_DispStringLine_EN(LINE(6),dispBuff);
//    LCD_SetTextColor(BLUE2);
    /*******显示图形示例******/
    /* 画直�??????? */

//    NT35510_ClearLine(LINE(10));/* 清除单行文字 */
//    LCD_SetTextColor(CYAN);
//
//    NT35510_DispStringLine_EN(LINE(10),"You are");

//	LCD_SetTextColor(RED);
//  NT35510_DrawLine(50,270,420,275);
//  NT35510_DrawLine(50,300,420,375);
//
//	LCD_SetTextColor(GREEN);
//  NT35510_DrawLine(50,370,420,475);
//  NT35510_DrawLine(50,400,420,475);
//
//	LCD_SetTextColor(BLUE);
//  NT35510_DrawLine(50,420,420,325);
//  NT35510_DrawLine(50,450,420,395);
//
//    HAL_Delay(100);

//  NT35510_Clear(0,32*7,LCD_X_LENGTH,LCD_Y_LENGTH-32*7);	/* 清屏，显示全�??????? */


    /*画矩�???????*/

//    NT35510_ClearLine(LINE(10));	/* 清除单行文字 */
//    LCD_SetTextColor(GRED);
//
//    NT35510_DispStringLine_EN(LINE(10),"MY");

//	LCD_SetTextColor(RED);
//  NT35510_DrawRectangle(50,300,200,100,1);
//
//	LCD_SetTextColor(GREEN);
//  NT35510_DrawRectangle(100,300,200,120,0);
//
//	LCD_SetTextColor(BLUE);
//  NT35510_DrawRectangle(250,300,200,150,1);
//
//
//    HAL_Delay(100);

//	NT35510_Clear(0,32*7,LCD_X_LENGTH,LCD_Y_LENGTH-32*7);	/* 清屏，显示全�??????? */

    /* 画圆 */
//    NT35510_ClearLine(LINE(10));	/* 清除单行文字 */
//    LCD_SetTextColor(MAGENTA);
//
//    NT35510_DispStringLine_EN(LINE(10),"Little Baby Girl");

//	LCD_SetTextColor(RED);
//	NT35510_DrawCircle(150,400,60,1);

//	LCD_SetTextColor(GREEN);
//	NT35510_DrawCircle(250,400,60,0);

//	LCD_SetTextColor(BLUE);
//	NT35510_DrawCircle(350,400,60,1);

//    HAL_Delay(100);

//  NT35510_Clear(0,32*7,LCD_X_LENGTH,LCD_Y_LENGTH-32*7);	/* 清屏，显示全�??????? */

}

void User_init()
{
    LED_G_OFF();
    LED_B_OFF();
    LED_R_OFF();
    NT35510_Init();
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
    uint8_t key_flag=0;
    //***********************  dht11  ***************************

    uint8_t temperature = 1;                     //温度�??
    uint8_t humidity = 1;                        //湿度�??

    char* CntState = "No Connect!\r\n";          //连接状�??
    uint8_t aTxBuffer_tem[50];                       //打印温度信息
    uint8_t aTxBuffer_hum[50];                       //打印湿度信息
    uint8_t key=0;
    //***********************  mpu6050  ***************************
    float pitch,roll,yaw; 		//欧拉�?
    short aacx,aacy,aacz;		//加�?�度传感器原始数�?
    short gyrox,gyroy,gyroz;	//�?螺仪原始数据
    float temp;					//温度

    char *aTxBuffer_atti[30];     //声明sprintf的存储数�?

    /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_FSMC_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  //*****************  dht11 ***********************************
    DHT11_Rst();                                   //复位DHT11
    while(DHT11_Check())                           //�??测DHT11连接
    {
        HAL_UART_Transmit(&huart1, CntState, strlen(CntState), 200);
        HAL_Delay(500);
    }
    CntState = "Success!\r\n";
    HAL_UART_Transmit(&huart1, CntState, strlen(CntState), 200);
    LCD_SetTextColor(BLACK);
    NT35510_DispStringLine_EN(LINE(6),"DHT11 INIT OK!");

    User_init();

    LCD_Test();
    printf("init OK!\r\n");
    LCD_SetTextColor(BLACK);
    NT35510_DispStringLine_EN(LINE(5),"INIT OK!");
    //******************  mpu6050  **********************************
    HAL_UART_Transmit(&huart1, "UART1 Ready!\r\n", sizeof("UART1 Ready!\r\n"),200);
    LCD_SetTextColor(BLACK);
    NT35510_DispStringLine_EN(LINE(7),"MPU6050 INIT OK!");


    while(MPU_Init());					//初始化MPU6050
    while(mpu_dmp_init())
    {
        HAL_Delay(200);
        HAL_UART_Transmit(&huart1, "MPU6050 Init Wrong!\r\n", sizeof("MPU6050 Init Wrong!\r\n"),200);
    }
    HAL_UART_Transmit(&huart1, "MPU6050 Init OK!\r\n", sizeof("MPU6050 Init OK!\r\n"),200);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
      DHT11_Read_Data(&humidity, &temperature);                        //�??测出温湿度的�??
      sprintf(aTxBuffer_tem, "temperature:%d ^C\r\n", temperature);         //打印温度的�??
      sprintf(aTxBuffer_hum, "humidity:%d%%\r\n", humidity);         //打印湿度的�??

      key = KEY_Scan(0);
      if (key)
      {
          NT35510_ClearLine(LINE(0));
          NT35510_ClearLine(LINE(1));
          NT35510_ClearLine(LINE(2));
          NT35510_ClearLine(LINE(3));
          NT35510_ClearLine(LINE(4));
          NT35510_ClearLine(LINE(5));
          if (key == KEY1_PRES) {
              key_flag=0;
              LED_R_ON();
              LED_G_OFF();
              printf("KEY1 ON \r\nshow temperature & humidity:\r\n");
              printf(aTxBuffer_tem);
              printf(aTxBuffer_hum);
              printf("-------------------------------------------\r\n");
              printf("\r\n");

              LCD_SetTextColor(MAGENTA);
              NT35510_ClearLine(LINE(6));
              NT35510_DispStringLine_EN(LINE(6),"KEY1 ON");
              NT35510_ClearLine(LINE(7));
              NT35510_DispStringLine_EN(LINE(7),"show temperature & humidity:");
              NT35510_ClearLine(LINE(8));
              NT35510_DispStringLine_EN(LINE(8),"please check in Serial Monitor!");
          }
          else if (key == KEY2_PRES)
          {
              key_flag=1;
              LED_G_ON();
              LED_R_OFF();
              printf("KEY2 ON \r\nshow attitude information:\r\n");

              LCD_SetTextColor(CYAN);
              NT35510_ClearLine(LINE(6));
              NT35510_DispStringLine_EN(LINE(6),"KEY2 ON");
              NT35510_ClearLine(LINE(7));
              NT35510_DispStringLine_EN(LINE(7),"show attitude information:");
              NT35510_ClearLine(LINE(8));
              NT35510_DispStringLine_EN(LINE(8),"please check in Serial Monitor!");

          }
      }
      if (key_flag==1)
      {
          if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
          {
//          temp=MPU_Get_Temperature();
//          temp=temp/100.0;                            //得到温度
              MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加�?�度传感器数�?
              MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到�?螺仪数据

              sprintf(aTxBuffer_atti, "Euler Angle:pitch= %f , roll= %f , yaw= %f .\r\n", pitch, roll, yaw);
              //HAL_UART_Transmit(&huart1,aTxBuffer,strlen((const char*)aTxBuffer),200);          //打印欧拉�?
              printf(aTxBuffer_atti);

              sprintf(aTxBuffer_atti, "Accelerometer Raw Data:aacx= %d , aacy= %d , aacz= %d .\r\n", aacx, aacy, aacz);
              // HAL_UART_Transmit(&huart1,aTxBuffer_atti,strlen((const char*)aTxBuffer_atti),200);           //打印加�?�度传感器数�?
              printf(aTxBuffer_atti);
              sprintf(aTxBuffer_atti, "Gyroscope Raw Data:gyrox= %d , gyroy= %d , gyroz= %d .\r\n", gyrox, gyroy, gyroz);
              // HAL_UART_Transmit(&huart1,aTxBuffer_atti,strlen((const char*)aTxBuffer_atti),200);          //打印�?螺仪数据
              printf(aTxBuffer_atti);
              printf("-------------------------------------------\r\n");
              printf("\r\n");

//          sprintf(aTxBuffer_atti,"The current temperature= %f .\r\n", temp);
//          //HAL_UART_Transmit(&huart1,aTxBuffer,strlen((const char*)aTxBuffer),200);          //打印温度
//          printf(aTxBuffer_atti);
//          //HAL_UART_Transmit(&huart1, "\r\n", sizeof("\r\n"),200);
          }
          HAL_Delay(100);
      }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
