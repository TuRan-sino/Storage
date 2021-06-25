#ifndef __PWM_H__
#define __PWM_H__ 


#define PWM_PATH "dev/pwm"
#define MAGIC_NUM 'k'
#define BEEP_ON _IO(MAGIC_NUM, 0)
#define BEEP_OFF _IO(MAGIC_NUM, 1)		//_IO(MAGIC_NUM, 1) 当输出参数为1的时候, 返回值为关闭beep
#define BEEP_SETFRE _IO(MAGIC_NUM, 2)	//set frequence


int pwm_init(void);
void beep_on(int fd);
void beep_off(int fd);
void beep_setfre(int fd, int fre);

#endif