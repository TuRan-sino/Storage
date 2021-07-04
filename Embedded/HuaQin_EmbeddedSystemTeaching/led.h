#ifndef __LED_H__
#define __LED_H__

#define LED_PATH "/dev/led"
#define LED_MAGIC 'k'
#define LED_ON _IO(LED_MAGIC, 0)
#define LED_OFF _IO(LED_MAGIC, 1)


extern int led_init(void);
extern void led_on(int fd, int led_num);
extern void led_off(int fd, int led_num);








#endif