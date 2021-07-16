#include "led.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int led_init(void)
{
	int fd;
	fd = open(LED_PATH, O_RDWR | O_NONBLOCK);
	if(fd == -1){
		perror("open led failed");
		exit(EXIT_FAILURE);
	}
	return fd;
}


void led_on(int fd, int led_num)
{
	int retval;
	retval = ioctl(fd, LED_ON, led_num);
	if(-1 == retval){
		perror("led on failed");
		exit(EXIT_FAILURE);
	}

	return ;
}

void led_off(int fd, int led_num)
{
	int retval;
	retval = ioctl(fd, LED_OFF, led_num);
	if(-1 == retval){
		perror("led off failed");
		exit(EXIT_FAILURE);
	}

	return ;
}