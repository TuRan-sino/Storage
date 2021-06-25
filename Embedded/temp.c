#include <exynos_4412.h>
#include <led.h>
#include <std.h>
#include <uart.h>
#include <adc.h>
#include <pwm.h>

int main(void)
{	
	unsigned int i = 100;
	int num = 0;
	unsigned int retval = 0;
	led_init();					//初始化LED
	adc_init();					//初始化adc
	uart_init();				//初始化uart


	while(1){
		retval = adc_read();		//采集电池电压数据

		retval = retval * 1800 / 4095;


		if(retval <=90){			//电池电量低于5%蜂鸣器报警
			pwm_init();					//初始化pwm
			pwm_setfre(i, i/2);	
		}else{
			pwm_close();
		}


		/*
		判断电池剩余电量以及所需要亮起的灯的数量
		*/
		switch(retval){
			case 0 : 				//0% 亮 0 盏灯打印0%
				num = 0;
				break;

			case 1 ... 180 :			//0% - 10 % 亮 1 盏灯闪烁打印10%
				num = 1;
				break;

			case 181 ... 900 :		//25% - 50% 亮 2 盏灯打印50%
				num = 2;
				break;

			case 901 ... 1350 :		//50% - 75% 亮 3 盏灯打印75%
				num = 3;
				break;

			case 1351 ... 1800 :		//75% - 100% 亮 4 盏灯打印100%
				num = 4;
				break;
		}



		switch(num){
			led_choice(num);
			uart_choice(num);
			printf("The last batteries is %d%\r\n", num * 25);
		}



	}




	return 0;
}