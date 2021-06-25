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



		if(retval <= 1000){			//电池电量低于5%蜂鸣器报警
			pwm_init();					//初始化pwm
			pwm_setfre(i, i/2);	
		}else{
			pwm_close();
		}


		/*
		判断电池剩余电量以及所需要亮起的灯的数量
		*/
		if(retval <= 4095 && retval >= 3000){
			num = 4;							//开4展灯
		}else if(retval <= 3000 && retval >= 2500){
			num = 3;							//开3盏灯
		}else if(retval <= 2500 && retval >= 2000){
			num = 2;							//开2展灯
		}else if(retval <= 2000 && retval >= 1000){
			num = 1;							//开1盏灯, 闪烁
		}else if(retval < 1000){
			num = 0;							//开0盏灯
		}



		led_choice(num);
		printf("%d% | %d \r\n", retval * 100 / 4095, retval);



	}




	return 0;
}