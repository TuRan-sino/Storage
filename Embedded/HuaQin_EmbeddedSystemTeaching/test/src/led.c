#include <exynos_4412.h>
#include <std.h>


void led_init(void)
{
	//把相应的位设置为输出位
	GPF3.CON = GPF3.CON & (~(0xF << 20)) | (0x1 << 20); //GPF3CON[5]初始化设置GPD3.CON第23-20位为1
	GPF3.CON = GPF3.CON & (~(0xF << 16)) | (0x1 << 16); //GPF3CON[4]初始化GPF3.CON第19-16位为1
	GPX1.CON = GPX1.CON & (~(0xF << 0)) | (0x1 << 0); 	//GPX1CON[1]初始化GPX1.CON第3-0位为1
	GPX2.CON = GPX1.CON & (~(0xF << 28)) | (0x1 << 28);	//GPX2CON[6]初始化GPX2.CON第31-28位为1
}


void led_on(unsigned int num)
{
	switch(num){
		case 1:
			//LED5 GPF3_5
			//GPF3DAT[5] = 1
			GPF3.DAT = GPF3.DAT | (0x1 << 5);	//这句话的意思是设置GPF3.DAT第五位 = 1
			break;
		case 2:
			//LED4 GPF3_4
			//GPF3DAT[4] = 1
			GPF3.DAT = GPF3.DAT | (0x1 << 4);	//第四位
			break;
		case 3:
			//LED3 GPX1_0
			//GPX1DAT[0] = 1
			GPX1.DAT = GPX1.DAT | (0x1 << 0);	//GPX1.DAT第0位
			break;
		case 4:
			//LED2 GPX2_7
			//GPX2DAT[7] = 1
			GPX2.DAT = GPX2.DAT | (0x1 << 7);	//GPX2.DAT第5位
			break;
	}


	return;
}


void led_off(unsigned int num)
{
	switch(num){
		case 1:	
			GPF3.DAT = GPF3.DAT & (~(0x1 << 5));
			break;
		case 2:	
			GPF3.DAT = GPF3.DAT & (~(0x1 << 4));
			break;
		case 3:
			GPX1.DAT = GPX1.DAT & (~(0x1 << 0));
			break;
		case 4:
			GPX2.DAT = GPX2.DAT & (~(0x1 << 7));
	}	
}


// 切换led的状态
void led_convert(unsigned int num)
{
	switch(num){
		case 1:
			GPF3.DAT = GPF3.DAT ^ ((0x1 << 5));
			break;
		case 2:
			GPF3.DAT = GPF3.DAT ^ ((0x1 << 4));
			break;
		case 3:
			GPX1.DAT = GPX1.DAT ^ ((0x1 << 0));
			break;
		case 4:
			GPX2.DAT = GPX2.DAT ^ ((0x1 << 7));
			break;
	}

	return ;
}

void led_choice(unsigned int num)
{
	switch(num){
		case 0:
			GPF3.DAT = GPF3.DAT & (~(0x1 << 5));	//关闭第4盏灯
			GPF3.DAT = GPF3.DAT & (~(0x1 << 4));	//关闭第3盏灯
			GPX1.DAT = GPX1.DAT & (~(0x1 << 0));	//关闭第2盏灯
			GPX2.DAT = GPX2.DAT & (~(0x1 << 7));	//关闭第1盏灯
			break;

		case 1:
			GPF3.DAT = GPF3.DAT & (~(0x1 << 4));	//关闭第3盏灯
			GPX1.DAT = GPX1.DAT & (~(0x1 << 0));	//关闭第2盏灯
			GPX2.DAT = GPX2.DAT & (~(0x1 << 7));	//关闭第1盏灯

			
			GPF3.DAT = GPF3.DAT | (0x1 << 5);		//打开第四战灯
			delay_ms(2000);							//设置延迟
			GPF3.DAT = GPF3.DAT & (~(0x1 << 5));	//关闭第四盏灯
			delay_ms(2000);
			GPF3.DAT = GPF3.DAT | (0x1 << 5);		//打开第四战灯
			break;


		case 2: 
			GPF3.DAT = GPF3.DAT | (0x1 << 5);		//打开第4盏灯
			GPF3.DAT = GPF3.DAT | (0x1 << 4);		//打开第3盏灯
			GPX1.DAT = GPX1.DAT & ((0x1 << 0));		//关闭第2盏灯
			GPX2.DAT = GPX2.DAT & (~(0x1 << 7));	//关闭第1盏灯
			break;

		case 3:
			GPF3.DAT = GPF3.DAT | (0x1 << 5);		//打开第4盏灯
			GPF3.DAT = GPF3.DAT | (0x1 << 4);		//打开第3盏灯
			GPX1.DAT = GPX1.DAT | (0x1 << 0);		//打开第2盏灯
			GPX2.DAT = GPX2.DAT & (~(0x1 << 7));	//关闭第1盏灯
			break;


		case 4:
			GPF3.DAT = GPF3.DAT | (0x1 << 5);		
			GPF3.DAT = GPF3.DAT | (0x1 << 4);
			GPX1.DAT = GPX1.DAT | (0x1 << 0);
			GPX2.DAT = GPX2.DAT | (0x1 << 7);
			break;
	}
}