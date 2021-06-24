#include <exynos_4412.h>

void uart_init(void)
{
	//设置gpio为串口功能, GPA1CON[3:0] = 2; GPA1CON[7:4] = 0x2
	GPA1.CON = GPA1.CON & (~(0xFF << 0)) | (0x22 << 0);


	/*
		设置串口工作模式
		UCON2[1:0] = 0x1;
		UCON2[3:2] = 0x1;
	*/
	UART2.UCON2 = UART2.UCON2 & (~(0xF << 0)) | (0x5 << 0);


	//设置数据格式
	/*
		ULCON2[6] = 0
		ULCON2[5:3] = 0
		ULCON2[2] = 0
		ULCON2[1:0] = 0x3
	*/
	UART2.ULCON2 = UART2.ULCON2 & (~(0x7F << 0)) | (0x3 << 0);

	//设置波特率115200
	/*
		UBRDIV2 = 53
		UFRACVAL2 = 4
	*/
	UART2.UBRDIV2 = 53;
	UART2.UFRACVAL2 = 4;

	return;
}

//通过串口发送八位(1byte)的数据
void uart_putc(unsigned char ch)
{
	//循环判断UTRSTAT2[1] = 1, 来确定是否可以发送数据
	while(! (UART2.UTRSTAT2 & (0x1 << 1)));

	UART2.UTXH2 = ch;			//将发送的数据放置与UTXH2[7:0]

	if(ch == '\n'){
		uart_putc('\r');
	}

	return;
}

//通过串口接受一个1byte的数据
char uart_getc(void)
{
	char ch;

	while(! (UART2.UTRSTAT2 & (0x1 << 0)));		//循环判断UTRSTAT2[0] = 1 缓冲区有数据, 可以接收

	ch = UART2.URXH2;							//从URXH2[7:0] 接收数据


	return ch;
}

//输出字符串
void uart_puts(const char *str)
{
	while(*str != '\0'){
		uart_putc(*str);
		str ++;
	}
}

//获取一行指定长度的字符串
void uart_gets(char *str, int n)
{
	int i ;

	for(i = 0; i < n - 1; i ++){
		str[i] = uart_getc();
		uart_putc(str[i]);

		if(str[i] == '\r'){
			str[i + 1] = '\n';
			str[i + 2] = '\0';
			uart_putc('\n');
			break;
		}
	}

	return;
}