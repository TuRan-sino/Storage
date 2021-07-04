#include <exynos_4412.h>

void adc_init(void)
{
	ADCCON |= 0x1 << 16;				//设置ADC的精度, ADCCON[16] = 1
	ADCCON |= 0x1 << 14;				//设置始能分频器 ADCCON[14] = 1
	ADCCON |= 0xFF << 6;				//设置分频器的值, 设置ADC转化速率, ADCCON[13: 6]  = 255
	ADCCON &= (~(0x1 << 2));			//设置ADC工作模式 正常模式 ADCCON[2] = 0

	ADCMUX = ADCMUX & (~(0xF << 0)) | (0x3 << 0);	//设置ADC通道, 为通道3 ADCMUX[3:0] = 0x3

	return ;
}

unsigned short adc_read(void)
{
	unsigned short value;

	ADCCON |= (0x1 << 0);				//开启ad转换, ACCON[0] = 1
	while(!(ADCCON & (0x1 << 15)));		//等待AD转换完成

	value = ADCDAT & 0xFFF;				//获取转换之后的值, ADCDAT[11:0]

	return value;
}