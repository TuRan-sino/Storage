/*
一. 使用链式存储的串

二. 优缺点
1. 优点: 
2. 缺点: 
	1. 存储密度低:
	每个节点有1B的空间存放data, 但是要有4B的空间存放next(指针).

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef struct StNode{
	char data[4];		// 每个节点存放一个字符
	struct StNode *next;
}StNode, *String;
// string: *类型的 StNode

int main(int argc, char const *argv[])
{
	
	return 0;
}