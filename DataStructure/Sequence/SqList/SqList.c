/****************************************************************************************************
@author:	TuRan
@data:	2022/4/10
@des: 	线性表相关代码
****************************************************************************************************/
#include "SqList.h"


int main()
{
	SqList L;
	Init_List(&L);

	Creat_List(&L);
	
	Show_List(L);
	printf("%d", L.maxsize);



	return TRUE;
}


/**
 * @brief	初始化线性表
 * @param	L [SqList *] 线性表的地址
 * @param	len [int] 线性表的长度
*/
bool Init_List(SqList *L)
{
	(*L).data = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);		// 给data malloc数据空间

	if(!L->data) return FALSE;											// 假设L->data不存在, 返回FALSE

	(*L).length = 0;													// 将初始时的length设置为0
	(*L).maxsize = INITSIZE;											// 将初始时的 maxsize 设置为 INITSIZE

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
		if(L->length + 1 > L->maxsize){		// 假设当前线性表的长度大于最大长度, 则扩大线性表
			Creat_List(L);
		}
		L->data[i] = num;
		i ++;
		L->length ++;
		scanf("%d", &num);					// 挨个输入数据
	}
	return TRUE;
}



/**
 * @brief	遍历链表
 * @param	L [SqList *]
 * @retval	void
*/
void Show_List(SqList L)
{
	int i;
	for(i = 0; i < L.length; i ++){
		printf("%d ", L.data[i]);
	}

	putchar('\n');
}


/**
 * @brief	延长链表
 * @param	L [SqList *]
 * @note 	重新创建一个数据域, 该数据域的长度为原来数据域的最大长度 + INCSIZE
 * 			之后将原来的数据域的地址设置为新的数据域
 * 			并且将原来的数据域free了
*/
bool Increase_List(SqList *L)
{
	ElemType *data;
	data = (ElemType *)malloc(sizeof(ElemType) * L->maxsize + INCSIZE);		// 新建一个数据域
	if(!data) return FALSE;													// 假设数据域创建失败, 返回false

	for(int i = 0; i < L->length; i ++) data[i] = L->data[i];				// 挨个将数据传到新的数据域中


	free(L->data);															// 释放原先的链表的数据域

	// 将原先的链表的指针域以及各个域全部都设置为新的
	L->data = data;
	L->maxsize = L->maxsize + INCSIZE;


	return TRUE;
}