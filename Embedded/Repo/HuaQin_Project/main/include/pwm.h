#ifndef	__PWM_H__
#define __PWM_H__

extern void pwm_init(void);
extern void pwm_close(void);
extern void pwm_setfre(unsigned int tcnt, unsigned int tcmp);

#endif