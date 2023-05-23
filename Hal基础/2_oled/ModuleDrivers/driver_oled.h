#ifndef _DRIVER_OLED_H
#define _DRIVER_OLED_H
#include "stm32f1xx_hal.h"

typedef enum
{
    H_ADDR_MODE     = 0,    // 水平地址模式
    V_ADDR_MODE     = 1,    // 垂直地址模式
    PAGE_ADDR_MODE  = 2,    // 页地址模式
}MEM_MODE;  // 内存地址模式


/*从机地址 第一种形式*/
#define OLED_WRITE_ADDR 0x78
#define OLED_READ_ADDR	0x79
/*从机地址 第二种形式*/
#define OLED_ADDR 0x78
#define OLED_WRITE 0x00
#define OLED_READ 0x01

void OLED_WriteCmd(uint8_t);
void OLED_WriteData(uint8_t);
void OLED_WriteNBytes(uint8_t *buf,uint16_t length);



typedef enum{
    H_RIGHT     = 0x26,
    H_LEFT      = 0x27,
}H_SCROLL_DIR;  // 水平滚动方向

typedef enum{
	HV_RIGHT	=0x29,
	HV_LEFT		=0x2A
	
}HV_SCROLL_DIR;


typedef enum
{
    COM_PIN_SEQ     = 0,
    COM_PIN_ALT     = 1,
}COM_PINS_MODE; // COM引脚属性
typedef enum
{
    COM_NOREMAP     = 0,
    COM_REMAP       = 1,
}COM_REMAP_STATE;   // COM引脚翻转

typedef enum
{
    PUMP_DISABLE    = 0,
    PUMP_ENABLE     = 1,
}CHARGE_PUMP_STATE; // 打开或者关闭电荷泵

/***************1、基本命令功能函数*************/
void OLED_SetContrastValue(uint8_t);
#define ENTIRE_DISPLAY_OFF() OLED_WriteCmd(0xA4)
#define ENTIRE_DISPLAY_ON() OLED_WriteCmd(0xA5)

#define NOMAL_DISPALY() OLED_WriteCmd(0xA6)
#define INVERSE_DISPALY() OLED_WriteCmd(0xA7)

#define Set_DISP_OFF() OLED_WriteCmd(0xAE)
#define Set_DISP_ON() OLED_WriteCmd(0xAF)

/***************2、滚动命令功能函数*************/

void OLED_H_Scroll(H_SCROLL_DIR dir,uint8_t start,uint8_t interval_each_scroll,uint8_t end);
void OLED_HV_Scroll(HV_SCROLL_DIR dir,uint8_t start,uint8_t interval_each_scroll,uint8_t end,uint8_t row_offset);
void OLED_Set_V_Scroll_Area(uint8_t fixedEnd,uint8_t rowNums);


#define SCROLL_OFF() OLED_WriteCmd(0x2E)
#define SCROLL_ON() OLED_WriteCmd(0x2F)


/***************3、地址设置命令功能函数*************/
void OLED_SetMemAddrMode(uint8_t);
void OLED_SetPageAddr_Page(uint8_t);
void OLED_SetColAddr_Page(uint8_t);
void OLED_SetPosition(uint8_t page,uint8_t col);

/***************4、硬件配置命令功能函数*************/
void OLED_SetDispStartLine(uint8_t line);

#define OLED_SEG_REMAP() OLED_WriteCmd(0XA1)
#define OLED_SEG_NOREMAP() OLED_WriteCmd(0XA0)

void OLED_SetMuxRatio(uint8_t ratio);
void OLED_SetDispOffset(uint8_t offset);

#define OLED_SCAN_NORMAL() OLED_WriteCmd(0xC0)
#define OLED_SCAN_REMAP() OLED_WriteCmd(0xC8)

void OLED_SetDispOffset(uint8_t offset);
void OLED_SetComConfig(COM_PINS_MODE mode, COM_REMAP_STATE state);

/***************5、时间设置功能函数*************/
/*
 *  函数名：OLED_SetDCLK_Freq
 *  功能描述：设置OLED的扫描周期和晶振频率
 *  输入参数：div-->时钟分频系数
 *            freq-->晶振频率
 *  输出参数：无
 *  返回值：无
*/

extern void OLED_SetDCLK_Freq(uint8_t div, uint8_t freq);

/*
 *  函数名：OLED_SetPreChargePeriod
 *  功能描述：设置OLED的预充电周期
 *  输入参数：phase1-->预充电阶段1时间
 *            phase2-->预充电阶段2时间
 *  输出参数：无
 *  返回值：无
*/
extern void OLED_SetPreChargePeriod(uint8_t phase1, uint8_t phase2);
    
typedef enum
{
    LEVEL_0     = 0x00,
    LEVEL_1     = 0x20,
    LEVEL_2     = 0x30,
}VCOMH_LEVEL;   // 电压等级
/*
 *  函数名：OLED_SetVcomhLevel
 *  功能描述：设置OLED的电压等级
 *  输入参数：level-->电压等级
 *  输出参数：无
 *  返回值：无
*/
extern void OLED_SetVcomhLevel(VCOMH_LEVEL level);


/************** 6. 电荷碰撞功能函数 **************/
/*
 *  函数名：OLED_SetChargePump
 *  功能描述：打开或关闭OLED的电荷泵
 *  输入参数：state-->电荷泵打开或关闭
 *  输出参数：无
 *  返回值：无
*/
void OLED_SetChargePump(CHARGE_PUMP_STATE state);
#endif








void OLED_Clear();