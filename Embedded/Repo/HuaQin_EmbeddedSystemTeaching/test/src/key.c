#include <exynos_4412.h>
#include <std.h>

void key_init(void)
{
	GPX1.CON = GPX1.CON & (~(0xF << 4)); 		//对key2初始化, 将GPX1_1设置为输出模式, GPX1CON[7:4] = 0x0
	GPX1.CON = GPX1.CON & (~(0xF << 8)); 		//对key3初始化, 将GPX1_2设置为输入模式, GPX1CON[11:8] = 0x0
	GPX3.CON = GPX3.CON & (~(0xF << 8));		//对key4初始化, 将GPX3_3设置为输入模式, GPX3CON[11:8] = 0x0

	return ;
}

unsigned char key_read(void)
{
	/*
	判断是否按下按键,
	假设 GPX1DAT[1] = 1 => 没有按下按键
	假设 GPX1DAT[1] = 0 => 按下了按键
	*/

	while(1){
		// key2
		if(!(GPX1.DAT & (0x1 << 1))){				//假设按下了按键
			delay_ms(10);							//按键消抖
			if(!(GPX1.DAT & (0x1 << 1))){	
				while(!(GPX1.DAT & (0x1 << 1)));	//与之前不同的是, 按键被按下了, 现在要等待按键松开 
				printf("key-2 input \r\n");
				return 2;
			}
		}

		//key3
		if(!(GPX1.DAT & (0x1 << 2))){
			delay_ms(10);							//按键消抖
			if(!(GPX1.DAT & (0x1 << 2))){
				while(!(GPX1.DAT & (0x1 << 2)));	//等待按键松开
				printf("key-3 input\r\n");
				return 3;
			}
		}

		// key4
		if(!(GPX3.DAT & (0x1 << 2))){
			delay_ms(10);							//按键消抖
			if(!(GPX3.DAT & (0x1 << 2))){
				while(!(GPX3.DAT & (0x1 << 2)));	//等待按键松开
				printf("key-3 input\r\n");
				return 4;
			}
		}
	}


	return 0;
}

int key_CloseBeep(void)
{
	if(!(GPX3.DAT & (0x1 << 2))){				//按下按键
			while(!(GPX3.DAT & (0x1 << 2))){;	//等待按键松开
			return 1; 	
			}						//按键确实松开了, 返回1
	}else{
		return 0;								//根本没有按下按键, 返回0
	}
}