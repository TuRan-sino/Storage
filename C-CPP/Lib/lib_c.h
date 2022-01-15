/*
*File Path in windows:   D:\Project\C\Lib\lib_c.h
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define STAR "********************"

char *s_gets(char *st, int n);
//this funtion is aimed at getting char string form stdin
//this funtion include 2 parameter. first is string pointer second is length limit
//if target string is smaller than n then everything is ok
//else this funtion will discard remainder element and return a null pointer
//tips: this funtion is depend on fgets(), so this funtion will retain '\n'
/*
本函数意在从标准输入输出stdin中获取字符串
该函数包括了2个参数, 第一个是字符串指针, 第二个是最大长度
假设字符串比最大长度n小, 啥事没有
否则(字符串比n大), 本函数将会舍弃剩余的元素并且返回一个空指针
*/



void int_gets(int *integer);
//this function is amied at getting integer;
//if input num is not integer this funtion will printf "Please input again"
//the parameter is a pointer which could be used in message deliver between different funtion
/*
本函数意在获取一个int型
假设输入的数不是一个int型, 该函数会printf一个"Please input again"
intger参数是一个指针, 可以用在不同函数的消息传递中
*/

















char *s_gets(char *st, int n)
{
	char *result;
	int i = 0;

	result = fgets(st, n, stdin);
	if(result){
		while(st[i] != '\n' && st[i] != '\0')
			i ++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}

	return result;
}



void int_gets(int *integer)
{
	int i;

	i = scanf("%d",integer);
	while(i != 1){
		printf("This input is illegal, ");
		printf("Please input again\n");
		fflush(stdin);
		i = scanf("%d",integer);
	}

}