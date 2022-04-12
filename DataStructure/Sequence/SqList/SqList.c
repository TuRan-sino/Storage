/****************************************************************************************************
@author:	TuRan
@data:	2022/4/10
@des: 	线性表相关代码
****************************************************************************************************/
#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
	SqList L;
	Init_List(&L, INITSIZE);

	Creat_List(&L);

	Show_List(&L);


	return TRUE;
}


/**
 * @brief	初始化线性表
 * @param	L [SqList *] 线性表的地址
 * @param	len [int] 线性表的长度
*/
bool Init_List(SqList *L, int len)
{
	(*L).data = (int *)malloc(sizeof(int) * INITSIZE);		// 给data malloc数据空间

	if(!L->data) return FALSE;								// 假设L->data不存在, 返回FALSE

	(*L).length = 0;										// 将初始时的length设置为0
	(*L).maxsize = INITSIZE;								// 将初始时的 maxsize 设置为 INITSIZE

	return TRUE;
}


/**
 * @brief	创建线性表
 * @param	L [SqList *] 线性表的头指针
*/
bool Creat_List(SqList *L)
{
	int i = 0, num = 0;

	scanf("%d", &num);
	while(num != -9999){
		// if(L->length + 1 > L->maxsize){
			
		// }
		L->data[i] = num;
		i ++;
		L->length ++;
		scanf("%d", &num);
	}
	return TRUE;
}



/**
 * @brief	遍历链表
 * @param	L [SqList *]
 * @retval	void
*/
void Show_List(SqList *L)
{
	int i;
	for(i = 0; i < L->length; i ++){
		printf("%d ", L->data[i]);
	}

	putchar('\n');
}


/**
 * @brief	延长链表
 * @param	L [SqList *]
*/
void Inc_List(SqList *L)
{
	
}