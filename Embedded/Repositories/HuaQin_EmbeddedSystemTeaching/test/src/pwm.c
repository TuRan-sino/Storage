#include <exynos_4412.h>

void pwm_init(void)
{
	GPD0.CON = GPD0.CON & (~(0xF << 0)) | (0x2 << 0);		//设置GPD0_0为pwm输出功能 GPD0CON[3:0] = 0x2
	PWM.TCFG0 = PWM.TCFG0 & (~(0xFF << 0)) | (249 << 0); 	//设置1级分频值 TCFG0[7:0] = 249
	PWM.TCFG1 = PWM.TCFG1 & (~(0xFF << 9)) | (0x2 << 0);	//设置2级分频值 TCFG1[3:0] = 0x2
	PWM.TCNTB0 = 99;										//设置TCNTB0的值, 用来设定PWM方波周期
	PWM.TCMPB0 = 49;										//设置TCMPB0的值, 用来设置pwm方波的占空比 50%
	PWM.TCON |= 0x1 << 1;									//打开手动加载模式  TCON[1] = 1
	PWM.TCON = PWM.TCON & (~(0xF << 0)) | (0x1 << 3) | (0x1 << 0);	//打开自动重载 TCON[3] = 0x1, 关闭手动加载 TCON[1] = 0, 启动pwm定时器 TCON[0] = 1
}

void pwm_close(void)
{
	PWM.TCON &= (~(0x1 << 0)); 								//关闭蜂鸣器TCON[0] = 0

	return ;	
}

void pwm_setfre(unsigned int tcnt, unsigned int tcmp)
{
	PWM.TCNTB0 = tcnt;										//设置TCNTB0 的值, 设置PWM方波的周期 
	PWM.TCMPB0 = tcmp;										//设置TCMPB0的值, 设置pwm方波的占空比, 50%
	PWM.TCON |= 0x1 << 1;									//打开手动加载模式TCON[1] 1
	PWM.TCON = PWM.TCON & (~(0xF << 0)) | (0x1 << 3) | (0x1 << 0);	//打开自动重载 TCON[3] = 0x1, 关闭手动加载 TCON[1] = 0, 启动pwm定时器 TCON[0] = 1

	return ;	
}