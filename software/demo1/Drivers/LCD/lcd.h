//
// Created by Maxwell on 2022-12-24.
//

#ifndef DEMO1_LCD_H
#define DEMO1_LCD_H

#include "main.h"

#include "../FONT/font.h"


/***************************************************************************************
2^26 =0X0400 0000 = 64MB,每个 BANK 有4*64MB = 256MB
64MB:FSMC_Bank1_NORSRAM1:0X6000 0000 ~ 0X63FF FFFF
64MB:FSMC_Bank1_NORSRAM2:0X6400 0000 ~ 0X67FF FFFF
64MB:FSMC_Bank1_NORSRAM3:0X6800 0000 ~ 0X6BFF FFFF
64MB:FSMC_Bank1_NORSRAM4:0X6C00 0000 ~ 0X6FFF FFFF

选择BANK1-BORSRAM3 连接 TFT，地址范围为0X6800 0000 ~ 0X6BFF FFFF
FSMC_A0 接LCD的DC(寄存器/数据选择)脚
寄存器基地址 = 0X6C00 0000
RAM基地址 = 0X6D00 0000 = 0X6C00 0000+2^0*2 = 0X6800 0000 + 0X2 = 0X6800 0002
当选择不同的地址线时，地址要重新计算
****************************************************************************************/

/******************************* NT35510 显示屏的 FSMC 参数定义 ***************************/
//FSMC_Bank1_NORSRAM用于LCD命令操作的地址
#define      FSMC_Addr_NT35510_CMD         ( ( uint32_t ) 0x68000000 )

//FSMC_Bank1_NORSRAM用于LCD数据操作的地址
#define      FSMC_Addr_NT35510_DATA        ( ( uint32_t ) 0x68000002 )

//由片选引脚决定的NOR/SRAM块
#define      FSMC_Bank1_NORSRAMx           FSMC_Bank1_NORSRAM3


/******************************* NT35510 显示屏8080通讯引脚定义 ***************************/
/******控制信号线******/


/*************************************** 调试预用 ******************************************/
#define      DEBUG_DELAY()               Delay(0x5000)

/***************************** ILI934 显示区域的起始坐标和总行列数 ***************************/
#define      NT35510_DispWindow_X_Star		    0     //起始点的X坐标
#define      NT35510_DispWindow_Y_Star		    0     //起始点的Y坐标

#define 			NT35510_LESS_PIXEL	  		480			//液晶屏较短方向的像素宽度
#define 			NT35510_MORE_PIXEL	 		800			//液晶屏较长方向的像素宽度

//根据液晶扫描方向而变化的XY像素宽度
//调用NT35510_GramScan函数设置方向时会自动更改
extern uint16_t LCD_X_LENGTH,LCD_Y_LENGTH;

//液晶屏扫描模式
//参数可选值为0-7
extern uint8_t LCD_SCAN_MODE;

/******************************* 定义 ILI934 显示屏常用颜色 ********************************/
#define      BACKGROUND		                BLACK   //默认背景颜色

#define      WHITE		 		           0xFFFF	   //白色
#define      BLACK                         0x0000	   //黑色
#define      GREY                          0xF7DE	   //灰色
#define      BLUE                          0x001F	   //蓝色
#define      BLUE2                         0x051F	   //浅蓝色
#define      RED                           0xF800	   //红色
#define      MAGENTA                       0xF81F	   //红紫色，洋红色
#define      GREEN                         0x07E0	   //绿色
#define      CYAN                          0x7FFF	   //蓝绿色，青色
#define      YELLOW                        0xFFE0	   //黄色
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF

#define      LIGTHPINK                     0xFFB6C1  		//浅粉色



/******************************* 定义 ILI934 常用命令 ********************************/
#define      CMD_SetCoordinateX		 		    0x2A00	     //设置X坐标
#define      CMD_SetCoordinateY		 		    0x2B00	     //设置Y坐标
#define      CMD_SetPixel		 		          0x2C00	     //填充像素




/********************************** 声明 ILI934 函数 ***************************************/
void                     NT35510_Init                    ( void );
void                     NT35510_Rst                     ( void );
void                     NT35510_BackLed_Control         ( FunctionalState enumState );
void                     NT35510_GramScan                ( uint8_t ucOtion );
void                     NT35510_OpenWindow              ( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight );
void                     NT35510_Clear                   ( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight );
void                     NT35510_SetPointPixel           ( uint16_t usX, uint16_t usY );
uint16_t                 NT35510_GetPointPixel           ( uint16_t usX , uint16_t usY );
void                     NT35510_DrawLine                ( uint16_t usX1, uint16_t usY1, uint16_t usX2, uint16_t usY2 );
void                     NT35510_DrawRectangle           ( uint16_t usX_Start, uint16_t usY_Start, uint16_t usWidth, uint16_t usHeight,uint8_t ucFilled );
void                     NT35510_DrawCircle              ( uint16_t usX_Center, uint16_t usY_Center, uint16_t usRadius, uint8_t ucFilled );
void                     NT35510_DispChar_EN             ( uint16_t usX, uint16_t usY, const char cChar );
void                     NT35510_DispStringLine_EN      ( uint16_t line, char * pStr );
void                     NT35510_DispString_EN      			( uint16_t usX, uint16_t usY, char * pStr );
void 											NT35510_DispString_EN_YDir 		(   uint16_t usX,uint16_t usY ,  char * pStr );
void                     NT35510_DispChar_CH             ( uint16_t usX, uint16_t usY, uint16_t usChar );
void                     NT35510_DispString_CH           ( uint16_t usX, uint16_t usY,  char * pStr );
void                     NT35510_DispString_EN_CH        (	uint16_t usX, uint16_t usY,  char * pStr );
void 											NT35510_DispStringLine_EN_CH 	(  uint16_t line, char * pStr );
void 											NT35510_DispString_EN_YDir 		(   uint16_t usX,uint16_t usY ,  char * pStr );
void 											NT35510_DispString_EN_CH_YDir 	(   uint16_t usX,uint16_t usY , char * pStr );

void 											LCD_SetFont											(sFONT *fonts);
sFONT 										*LCD_GetFont											(void);
void 											NT35510_ClearLine										(uint16_t Line);
void 											LCD_SetBackColor								(uint16_t Color);
void 											LCD_SetTextColor								(uint16_t Color)	;
void 											LCD_SetColors										(uint16_t TextColor, uint16_t BackColor);
void 											LCD_GetColors										(uint16_t *TextColor, uint16_t *BackColor);

#define 									LCD_ClearLine 						NT35510_ClearLine

void NT35510_DisplayStringEx(uint16_t x, 		//字符显示位置x
                             uint16_t y, 				//字符显示位置y
                             uint16_t Font_width,	//要显示的字体宽度，英文字符在此基础上/2。注意为偶数
                             uint16_t Font_Height,	//要显示的字体高度，注意为偶数
                             uint8_t *ptr,					//显示的字符内容
                             uint16_t DrawModel);  //是否反色显示

void NT35510_DisplayStringEx_YDir(uint16_t x, 		//字符显示位置x
                                  uint16_t y, 				//字符显示位置y
                                  uint16_t Font_width,	//要显示的字体宽度，英文字符在此基础上/2。注意为偶数
                                  uint16_t Font_Height,	//要显示的字体高度，注意为偶数
                                  uint8_t *ptr,					//显示的字符内容
                                  uint16_t DrawModel);  //是否反色显示

#endif //DEMO1_LCD_H
