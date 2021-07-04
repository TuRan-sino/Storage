#include "pwm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int pwm_init(void)
{
	int fd;										//设备标识符fd
	fd = open(PWM_PATH, O_RDWR | O_NONBLOCK);	//fd获取open所返回的设备标识符
	if(-1 == fd){
		perror("open pwm failed");				//打印错误信息
		exit(EXIT_FAILURE);						//返回错误信息
	}

	return fd;
}


//打开蜂鸣器
void beep_on(int fd)
{
	int retval;									//定义, 接收值return value
	retval = ioctl(fd, BEEP_ON);
	if(retval == -1){
		perror("beep on failed");
		exit(EXIT_FAILURE);
	}

	return ;

}

// 关闭蜂鸣器
void beep_off(int fd)
{
	int retval;
	retval = ioctl(fd, BEEP_OFF);
	if(retval == -1){
		perror("beep off failed");
		exit(EXIT_FAILURE);
	}

	return ;
}

void beep_setfre(int fd, int fre)
{
	int retval;
	retval = ioctl(fd, BEEP_SETFRE, fre);
	if(retval == -1){
		perror("beep setfre failed");
		exit(EXIT_FAILURE);
	}

	return ;
}

