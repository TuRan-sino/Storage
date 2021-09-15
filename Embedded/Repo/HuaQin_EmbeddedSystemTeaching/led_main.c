#include <stdio.h>
#include "led.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd;
	int i;
	int led_num;

	fd = led_init();


	for(i = 0; ; i ++){
		led_num = i % 4 + 1;
		led_on(fd, led_num);
		usleep(0.5 * 1000000);			//延迟函数, 参数是微秒级别
		led_off(fd, led_num);


	}

	close(fd);


	return 0;
}