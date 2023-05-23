#include "driver_oled.h"
#include "driver_i2c.h"
#include "ascii_font.c"
static MEM_MODE mem_mode = PAGE_ADDR_MODE;  // 静态局部变量，保存OLED的地址模式的




/*给OLED写命令*/
void OLED_WriteCmd(uint8_t cmd){
	I2C_Start();
	I2C_WriteByte(OLED_WRITE_ADDR);
	//I2C_WriteByte(OLED_ADDR | OLED_WRITE)
	I2C_WriteByte(0x00);
	I2C_WriteByte(cmd);
	I2C_Stop();
}

/*给OLED写显存数据*/
void OLED_WriteData(uint8_t data){
	I2C_Start();
	I2C_WriteByte(OLED_WRITE_ADDR);
	//I2C_WriteByte(OLED_ADDR | OLED_WRITE)
	I2C_WriteByte(0x40);
	I2C_WriteByte(data);
	I2C_Stop();
}

/*给OLED写多字节显存数据*/
void OLED_WriteNBytes(uint8_t *buf,uint16_t length){
	if(buf==NULL)
		return;
	I2C_Start();
	I2C_WriteByte(OLED_WRITE_ADDR);
	//I2C_WriteByte(OLED_ADDR | OLED_WRITE)
	I2C_WriteByte(0x40);
	for(uint8_t i = 0; i <length ; i++){
		I2C_WriteByte(buf[i]);
	}
	I2C_Stop();
}



/*设置对比度*/
void OLED_SetContrastValue(uint8_t value){
	OLED_WriteCmd(0x81);
	OLED_WriteCmd(value);
}

/*设置水平滚动*/
void OLED_H_Scroll(H_SCROLL_DIR dir,uint8_t start,uint8_t interval_each_scroll,uint8_t end){
	if(dir != H_RIGHT || dir != H_LEFT)
		return;
	if(start >0x07 || end >0x07 || interval_each_scroll > 0x07)
		return;
	
	OLED_WriteCmd(dir);
	OLED_WriteCmd(0x00);
	OLED_WriteCmd(start);
	OLED_WriteCmd(interval_each_scroll);
	OLED_WriteCmd(end);
	OLED_WriteCmd(0x00);
	OLED_WriteCmd(0xFF);
}

/*设置垂直和水平滚动*/
void OLED_HV_Scroll(HV_SCROLL_DIR dir,uint8_t start,uint8_t interval_each_scroll,uint8_t end,uint8_t row_offset){
	if(dir != HV_RIGHT || dir != HV_LEFT)
		return;
	if(start >0x07 || end >0x07 || interval_each_scroll > 0x07)
		return;
	if(row_offset > 0x3F)
		return;
	OLED_WriteCmd(dir);
	OLED_WriteCmd(0x00);
	OLED_WriteCmd(start);
	OLED_WriteCmd(interval_each_scroll);
	OLED_WriteCmd(end);
	OLED_WriteCmd(row_offset);
}

/*设置垂直滚动区域*/
void OLED_Set_V_Scroll_Area(uint8_t fixedEnd,uint8_t rowNums){
	if( fixedEnd > 0x3F || rowNums > 0x7F)
		return;
	OLED_WriteCmd(fixedEnd);
	OLED_WriteCmd(rowNums);
}


/*设置显存地址模式*/
void OLED_SetMemAddrMode(uint8_t mode){
	if(mode >0x3)
		return;
	OLED_WriteCmd(0x20);
	OLED_WriteCmd(mode);
}


/*设置页地址*/
void OLED_SetPageAddr_Page(uint8_t addr){
	if(mem_mode != PAGE_ADDR_MODE || addr > 7)
		return;
	OLED_WriteCmd(0xB0+addr);	
}

/*设置列地址*/
void OLED_SetColAddr_Page(uint8_t addr){
	if(mem_mode != PAGE_ADDR_MODE || addr > 127)
		return;
	OLED_WriteCmd(0x00 + (addr & 0xF));
	OLED_WriteCmd(0x10 + (addr >> 4));
}


/*设置页地址和列地址*/
void OLED_SetPosition(uint8_t page,uint8_t col){
	OLED_SetPageAddr_Page(page);
	OLED_SetColAddr_Page(col);
}

/*设置开始显示行*/
void OLED_SetDispStartLine(uint8_t line){
	if(line > 0x3F)
		return;
	OLED_WriteCmd(0x40+line);
}

/*设置复用率*/
void OLED_SetMuxRatio(uint8_t ratio){
	if(ratio < 15 || ratio > 63)
		return;
	OLED_WriteCmd(0xA8);
	OLED_WriteCmd(ratio);
}

void OLED_SetDispOffset(uint8_t offset){
	 if(offset > 63)     return;
    OLED_WriteCmd(0xD3);
    OLED_WriteCmd(offset);
}

void OLED_SetComConfig(COM_PINS_MODE mode, COM_REMAP_STATE state)
{
    if((mode != COM_PIN_SEQ) && (mode != COM_PIN_ALT))      return;
    if((state != COM_NOREMAP) && (state != COM_REMAP))      return;
    
    OLED_WriteCmd(0xDA);
    OLED_WriteCmd(0x02 + (mode << 4) + (state << 5));
}

/************** 5. 时间设置功能函数 **************/
/*
 *  函数名：OLED_SetDCLK_Freq
 *  功能描述：设置OLED的扫描周期和晶振频率
 *  输入参数：div-->时钟分频系数
 *            freq-->晶振频率
 *  输出参数：无
 *  返回值：无
*/
void OLED_SetDCLK_Freq(uint8_t div, uint8_t freq)
{
    if((div>0x0F) || (freq>0x0F))       return;
    OLED_WriteCmd(0xD5);
    OLED_WriteCmd(div + (freq<<4));
}

/*
 *  函数名：OLED_SetPreChargePeriod
 *  功能描述：设置OLED的预充电周期
 *  输入参数：phase1-->预充电阶段1时间
 *            phase2-->预充电阶段2时间
 *  输出参数：无
 *  返回值：无
*/
void OLED_SetPreChargePeriod(uint8_t phase1, uint8_t phase2)
{
    if((phase1>0x0F) || (phase2>0x0F))       return;
    OLED_WriteCmd(0xD9);
    OLED_WriteCmd(phase1 + (phase2<<4));    
}

/*
 *  函数名：OLED_SetVcomhLevel
 *  功能描述：设置OLED的电压等级
 *  输入参数：level-->电压等级
 *  输出参数：无
 *  返回值：无
*/
void OLED_SetVcomhLevel(VCOMH_LEVEL level)
{
    if((level != LEVEL_0) && (level != LEVEL_1) && (level != LEVEL_2))      return;
    OLED_WriteCmd(0xDB);
    OLED_WriteCmd(level);
}

/************** 6. 电荷碰撞功能函数 **************/
/*
 *  函数名：OLED_SetChargePump
 *  功能描述：打开或关闭OLED的电荷泵
 *  输入参数：state-->电荷泵打开或关闭
 *  输出参数：无
 *  返回值：无
*/
void OLED_SetChargePump(CHARGE_PUMP_STATE state)
{
    if((state != PUMP_DISABLE) && (state != PUMP_ENABLE))   return;
    OLED_WriteCmd(0x8D);
    OLED_WriteCmd((state<<2) + 0x10);
}


void OLED_Init(void){
	OLED_SetMemAddrMode(0x10);
	OLED_SetMuxRatio(0x3F);
	OLED_SetDispOffset(0x00);
	OLED_SetDispStartLine(0x40);
	OLED_SEG_REMAP();
	OLED_SCAN_REMAP();
	OLED_SetComConfig(COM_PIN_ALT,COM_NOREMAP);
	OLED_SetContrastValue(0X7F);
	ENTIRE_DISPLAY_OFF();
	NOMAL_DISPALY();
	//INVERSE_DISPALY();
	OLED_SetDCLK_Freq(0x0,0x08);
	OLED_SetChargePump(PUMP_ENABLE);
	Set_DISP_ON();	
}

void OLED_Clear(){
	OLED_SetPosition(0,0);
	for(uint8_t i=0;i<8;i++){
		uint8_t a[128] = {0};
		OLED_SetPosition(i,0);
		OLED_WriteNBytes(a,128);
	}
}

void OLED_PutChar(uint8_t page,uint8_t col,char c){
  OLED_SetPosition(page,col);
  OLED_WriteNBytes((uint8_t *)&ascii_font[c][0],8);
  OLED_SetPosition(page+1,col);
  OLED_WriteNBytes((uint8_t *)&ascii_font[c][8],8);
}

void OLED_PrintString(uint8_t page,uint8_t col,char * string){
	char * ch = string;
	while(*ch){
		if(col > (120)){
			col = 0;
			page += 2;
			if(page > 7)
				page = 0;
		}
		OLED_PutChar(page,col,*ch);
		col += 8;
		if(col > 127){
			col = 0;
			page += 2;
			if(page > 7)
				page = 0;
		}
		ch++;
	}
}

