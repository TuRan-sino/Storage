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

void int_gets(int *integer);
//this function is amied at getting integer;
//if input num is not integer this funtion will printf "Please input again"
//the parameter is a pointer which could be used in message deliver between different funtion


















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