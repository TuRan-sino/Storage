/*
输入多个字符串,按照第一个字符从小到大的顺序进行排列,在新的一行按下回车输入截至
eg:
输入:
	asdafasda
	xvxcvczxc
	qerqwrq
	svsvofjldfja
输出:
	asdafasda
	qerqwrq
	svsvofjldfja
	xvxcvczxc
*/
#include <stdio.h>
#include <string.h>
#include "D:\Project\C\lib\lib_c.h"

#define SIZE 81
#define LIM 20
#define HALT ""

void sortstring(char *str[], int num);

int main(int argc, char const *argv[])
{
	char input[LIM][SIZE];
	char *ptr[LIM];						//*ptr 是一个数组的指针,说明 prt 这个东西可以作为一个数组, *ptr[LIM] 也就是将他二维化,一个*ptr[LIM] 可以存储 LIM 个数组 (*ptr)
	int count = 0;
	int k;

	while(count < LIM && s_gets(input[count], LIM) != NULL && input[count][0] != '\0'){
		ptr[count] = input[count];		//这里 ptr[count] 和 input[count]都是指针!指向的是该多维数组 count 行的第一个元素,所以这一行也就是把 input[count] 整行的元素传给了 prt[count]
		count ++;
	}

	sortstring(ptr, count);

	
	for(k = 0; k < count; k ++){
		puts(ptr[k]);
	}



	return 0;
}

void sortstring(char *str[], int num)	//使用 char *str[] 而不用 char *str[LIM] 是因为这玩意是形参,不需要整这些有的没的,主要还是看传入的实参
{
	char *temp;							//🚩🚩🚩不知道为什么一个temp类型的指针可以表示二维指针?
	int i, j;

	for(i = 0; i < num - 1; i ++){
		for(j = i + 1; j < num; j ++){
			if(strcmp(str[i],str[j]) > 0){	//这里的 str[i] 和 str[j] 都是数组(也就是元素的集合),不是单单的一个char元素!
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}