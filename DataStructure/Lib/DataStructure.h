#ifndef __DATASTRUCTURE_H__
#define __DATASTRUCTURE_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TRUE 1
#define FALSE 0
#define INITSIZE 20
#define INCSIZE 10

// 重定义数据元素
typedef int ElemType;
// 线性表结构体
typedef struct sqlist{
	ElemType *data;			// 数据域
	int maxsize;		// 最大长度
	int length;			// 已占用长度
}SqList;



#endif