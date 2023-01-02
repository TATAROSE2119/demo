//
// Created by Maxwell on 2022-12-29.
//

#ifndef DEMO1_MPU6050_H
#define DEMO1_MPU6050_H
#include "main.h"

//#define MPU_ACCEL_OFFS_REG		0X06	//accel_offs锟侥达拷锟斤拷,锟缴讹拷取锟芥本锟斤拷,锟侥达拷锟斤拷锟街诧拷未锟结到
//#define MPU_PROD_ID_REG			0X0C	//prod id锟侥达拷锟斤拷,锟节寄达拷锟斤拷锟街诧拷未锟结到
#define MPU_SELF_TESTX_REG		0X0D	//锟皆硷拷拇锟斤拷锟絏
#define MPU_SELF_TESTY_REG		0X0E	//锟皆硷拷拇锟斤拷锟結
#define MPU_SELF_TESTZ_REG		0X0F	//锟皆硷拷拇锟斤拷锟絑
#define MPU_SELF_TESTA_REG		0X10	//锟皆硷拷拇锟斤拷锟紸
#define MPU_SAMPLE_RATE_REG		0X19	//锟斤拷锟斤拷频锟绞凤拷频锟斤拷
#define MPU_CFG_REG				0X1A	//锟斤拷锟矫寄达拷锟斤拷
#define MPU_GYRO_CFG_REG		0X1B	//锟斤拷锟斤拷锟斤拷锟斤拷锟矫寄达拷锟斤拷
#define MPU_ACCEL_CFG_REG		0X1C	//锟斤拷锟劫度硷拷锟斤拷锟矫寄达拷锟斤拷
#define MPU_MOTION_DET_REG		0X1F	//锟剿讹拷锟斤拷夥е碉拷锟斤拷眉拇锟斤拷锟�
#define MPU_FIFO_EN_REG			0X23	//FIFO使锟杰寄达拷锟斤拷
#define MPU_I2CMST_CTRL_REG		0X24	//IIC锟斤拷锟斤拷锟斤拷锟狡寄达拷锟斤拷
#define MPU_I2CSLV0_ADDR_REG	0X25	//IIC锟接伙拷0锟斤拷锟斤拷锟斤拷址锟侥达拷锟斤拷
#define MPU_I2CSLV0_REG			0X26	//IIC锟接伙拷0锟斤拷锟捷碉拷址锟侥达拷锟斤拷
#define MPU_I2CSLV0_CTRL_REG	0X27	//IIC锟接伙拷0锟斤拷锟狡寄达拷锟斤拷
#define MPU_I2CSLV1_ADDR_REG	0X28	//IIC锟接伙拷1锟斤拷锟斤拷锟斤拷址锟侥达拷锟斤拷
#define MPU_I2CSLV1_REG			0X29	//IIC锟接伙拷1锟斤拷锟捷碉拷址锟侥达拷锟斤拷
#define MPU_I2CSLV1_CTRL_REG	0X2A	//IIC锟接伙拷1锟斤拷锟狡寄达拷锟斤拷
#define MPU_I2CSLV2_ADDR_REG	0X2B	//IIC锟接伙拷2锟斤拷锟斤拷锟斤拷址锟侥达拷锟斤拷
#define MPU_I2CSLV2_REG			0X2C	//IIC锟接伙拷2锟斤拷锟捷碉拷址锟侥达拷锟斤拷
#define MPU_I2CSLV2_CTRL_REG	0X2D	//IIC锟接伙拷2锟斤拷锟狡寄达拷锟斤拷
#define MPU_I2CSLV3_ADDR_REG	0X2E	//IIC锟接伙拷3锟斤拷锟斤拷锟斤拷址锟侥达拷锟斤拷
#define MPU_I2CSLV3_REG			0X2F	//IIC锟接伙拷3锟斤拷锟捷碉拷址锟侥达拷锟斤拷
#define MPU_I2CSLV3_CTRL_REG	0X30	//IIC锟接伙拷3锟斤拷锟狡寄达拷锟斤拷
#define MPU_I2CSLV4_ADDR_REG	0X31	//IIC锟接伙拷4锟斤拷锟斤拷锟斤拷址锟侥达拷锟斤拷
#define MPU_I2CSLV4_REG			0X32	//IIC锟接伙拷4锟斤拷锟捷碉拷址锟侥达拷锟斤拷
#define MPU_I2CSLV4_DO_REG		0X33	//IIC锟接伙拷4写锟斤拷锟捷寄达拷锟斤拷
#define MPU_I2CSLV4_CTRL_REG	0X34	//IIC锟接伙拷4锟斤拷锟狡寄达拷锟斤拷
#define MPU_I2CSLV4_DI_REG		0X35	//IIC锟接伙拷4锟斤拷锟斤拷锟捷寄达拷锟斤拷

#define MPU_I2CMST_STA_REG		0X36	//IIC锟斤拷锟斤拷状态锟侥达拷锟斤拷
#define MPU_INTBP_CFG_REG		0X37	//锟叫讹拷/锟斤拷路锟斤拷锟矫寄达拷锟斤拷
#define MPU_INT_EN_REG			0X38	//锟叫讹拷使锟杰寄达拷锟斤拷
#define MPU_INT_STA_REG			0X3A	//锟叫讹拷状态锟侥达拷锟斤拷

#define MPU_ACCEL_XOUTH_REG		0X3B	//锟斤拷锟劫讹拷值,X锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_ACCEL_XOUTL_REG		0X3C	//锟斤拷锟劫讹拷值,X锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_ACCEL_YOUTH_REG		0X3D	//锟斤拷锟劫讹拷值,Y锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_ACCEL_YOUTL_REG		0X3E	//锟斤拷锟劫讹拷值,Y锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_ACCEL_ZOUTH_REG		0X3F	//锟斤拷锟劫讹拷值,Z锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_ACCEL_ZOUTL_REG		0X40	//锟斤拷锟劫讹拷值,Z锟斤拷锟�8位锟侥达拷锟斤拷

#define MPU_TEMP_OUTH_REG		0X41	//锟铰讹拷值锟竭帮拷位锟侥达拷锟斤拷
#define MPU_TEMP_OUTL_REG		0X42	//锟铰讹拷值锟斤拷8位锟侥达拷锟斤拷

#define MPU_GYRO_XOUTH_REG		0X43	//锟斤拷锟斤拷锟斤拷值,X锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_GYRO_XOUTL_REG		0X44	//锟斤拷锟斤拷锟斤拷值,X锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_GYRO_YOUTH_REG		0X45	//锟斤拷锟斤拷锟斤拷值,Y锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_GYRO_YOUTL_REG		0X46	//锟斤拷锟斤拷锟斤拷值,Y锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_GYRO_ZOUTH_REG		0X47	//锟斤拷锟斤拷锟斤拷值,Z锟斤拷锟�8位锟侥达拷锟斤拷
#define MPU_GYRO_ZOUTL_REG		0X48	//锟斤拷锟斤拷锟斤拷值,Z锟斤拷锟�8位锟侥达拷锟斤拷

#define MPU_I2CSLV0_DO_REG		0X63	//IIC锟接伙拷0锟斤拷锟捷寄达拷锟斤拷
#define MPU_I2CSLV1_DO_REG		0X64	//IIC锟接伙拷1锟斤拷锟捷寄达拷锟斤拷
#define MPU_I2CSLV2_DO_REG		0X65	//IIC锟接伙拷2锟斤拷锟捷寄达拷锟斤拷
#define MPU_I2CSLV3_DO_REG		0X66	//IIC锟接伙拷3锟斤拷锟捷寄达拷锟斤拷

#define MPU_I2CMST_DELAY_REG	0X67	//IIC锟斤拷锟斤拷锟斤拷时锟斤拷锟斤拷拇锟斤拷锟�
#define MPU_SIGPATH_RST_REG		0X68	//锟脚猴拷通锟斤拷锟斤拷位锟侥达拷锟斤拷
#define MPU_MDETECT_CTRL_REG	0X69	//锟剿讹拷锟斤拷锟斤拷锟狡寄达拷锟斤拷
#define MPU_USER_CTRL_REG		0X6A	//锟矫伙拷锟斤拷锟狡寄达拷锟斤拷
#define MPU_PWR_MGMT1_REG		0X6B	//锟斤拷源锟斤拷锟斤拷拇锟斤拷锟�1
#define MPU_PWR_MGMT2_REG		0X6C	//锟斤拷源锟斤拷锟斤拷拇锟斤拷锟�2
#define MPU_FIFO_CNTH_REG		0X72	//FIFO锟斤拷锟斤拷锟侥达拷锟斤拷锟竭帮拷位
#define MPU_FIFO_CNTL_REG		0X73	//FIFO锟斤拷锟斤拷锟侥达拷锟斤拷锟酵帮拷位
#define MPU_FIFO_RW_REG			0X74	//FIFO锟斤拷写锟侥达拷锟斤拷
#define MPU_DEVICE_ID_REG		0X75	//锟斤拷锟斤拷ID锟侥达拷锟斤拷

//锟斤拷锟紸D0锟斤拷(9锟斤拷)锟接碉拷,IIC锟斤拷址为0X68(锟斤拷锟斤拷锟斤拷锟斤拷锟轿�).
//锟斤拷锟斤拷锟絍3.3,锟斤拷IIC锟斤拷址为0X69(锟斤拷锟斤拷锟斤拷锟斤拷锟轿�).
#define MPU_ADDR				0X68

#define  u8 uint8_t
#define  u16 uint16_t

////锟斤拷为锟斤拷锟斤拷锟斤拷锟紾ND,锟斤拷锟斤拷转为锟斤拷写锟斤拷址锟斤拷,为0XD1锟斤拷0XD0(锟斤拷锟斤拷锟紾ND,锟斤拷为0XD3锟斤拷0XD2)
//#define MPU_READ    0XD1
//#define MPU_WRITE   0XD0

u8 MPU_Init(void); 								//锟斤拷始锟斤拷MPU6050
u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf);//IIC锟斤拷锟斤拷写
u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf); //IIC锟斤拷锟斤拷锟斤拷
u8 MPU_Write_Byte(u8 reg,u8 data);				//IIC写一锟斤拷锟街斤拷
u8 MPU_Read_Byte(u8 reg);						//IIC锟斤拷一锟斤拷锟街斤拷

u8 MPU_Set_Gyro_Fsr(u8 fsr);
u8 MPU_Set_Accel_Fsr(u8 fsr);
u8 MPU_Set_LPF(u16 lpf);
u8 MPU_Set_Rate(u16 rate);
u8 MPU_Set_Fifo(u8 sens);

short MPU_Get_Temperature(void);
u8 MPU_Get_Gyroscope(short *gx,short *gy,short *gz);
u8 MPU_Get_Accelerometer(short *ax,short *ay,short *az);
#endif //DEMO1_MPU6050_H
