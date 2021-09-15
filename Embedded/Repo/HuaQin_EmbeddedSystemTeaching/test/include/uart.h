#ifndef __UART_H__
#define __UART_H__



extern void uart_init(void);
extern void uart_putc(unsigned char ch);
extern unsigned char uart_getc(void);
extern void uart_puts(const char *str);
extern void uart_gets(char *str, int n);
extern void uart_choice(unsigned int num);


#endif