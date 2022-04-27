/****************************************************************************************************
@author: TuRan
@data: 2022/4/10
@des: 	线性表相关代码
		Sequence list code
****************************************************************************************************/
#include "SqList.h"
int main(int argc, char *argv[])
{
	SqList L;
	ElemType data;

	SqList_Init(&L);
	SqList_Creat(&L);
	SqList_Show(L);

	
	SqList_Destory(&L);


	return TRUE;
}


/**
 * @brief	初始化线性表
 * @param	L [SqList *] 线性表的地址
 * @param	len [int] 线性表的长度
*/
int SqList_Init(SqList *L)
{
	(*L).data = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);		// 给data malloc数据空间

	if(!L->data) return FALSE;											// 假设L->data不存在, 返回FALSE

	(*L).length = 0;													// 将初始时的length设置为0
	(*L).maxsize = INITSIZE;											// 将初始时的 maxsize 设置为 INITSIZE

	printf("SqList Init Success\n");

	return TRUE;
}


/**
 * @brief	创建线性表
 * @param	L [SqList *] 线性表的头指针
*/
int SqList_Creat(SqList *L)
{
	int i = 0, num = 0;

	scanf("%d", &num);
	while(num != -9999){
		if(L->length + 1 > L->maxsize){		// 假设当前线性表的长度大于最大长度, 则扩大线性表
			SqList_Creat(L);
		}
		L->data[i] = num;
		i ++;
		L->length ++;
		scanf("%d", &num);					// 挨个输入数据
	}
	return TRUE;
}


/**
 * @brief	销毁线性表
 * @param	L [SqList *]
 * @retval	int
*/
int SqList_Destory(SqList *L)
{
	free(L->data);
	L->length = 0;
	L->maxsize = 0;

	printf("Destory Success\n");

	return TRUE;
}


/**
 * @brief	延长链表
 * @param	L [SqList *] 线性表的指针
 * @note 	重新创建一个数据域, 该数据域的长度为原来数据域的最大长度 + INCSIZE
 * 			之后将原来的数据域的地址设置为新的数据域
 * 			并且将原来的数据域free了
*/
int SqList_Increase(SqList *L)
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


/**
 * @brief	遍历链表
 * @param	L [SqList *] 线性表的指针
 * @retval	void
*/
void SqList_Show(SqList L)
{
	int i;
	for(i = 0; i < L.length; i ++){
		printf("%d ", L.data[i]);
	}

	putchar('\n');
}


/**
 * @brief	(增)在线性表中某一个位置后面插入某一个元素
 * @param	L [SqList *] 线性表的指针
 * @param	location [int] 插入的位置, Location 从 1 开始计数
 * @param	data [ElemType] 所需要插入的数据
 * @note	location是从1开始计数的, 因此location作为插入位置比实际上的插入位置location' 多了一个位
 * @retval	int
*/
int SqList_Insert_Elem(SqList *L, int location, ElemType data)
{
	if(L->length + 1 > L->maxsize){
		SqList_Increase(L);
	}

	for(int i = L->length; i >= location; i --){		// 将 L->length 一直到 location(location' + 1)全部都向后移一位
		L->data[i] = L->data[i - 1];
	}

	L->data[location] = data;							// 将data插入在 location' + 1 的位置上
	
	L->length ++;										// L->length 加一

	return TRUE;	
}


/**
 * @brief	(删)在线性表某一位位置上删除一个元素, 并且返回元素内
 * @param	L [SqList *] 线性表的指针
 * @param	location [int] 需要删除的位置
 * @param	data [ElemType *] 删除的元素的内容
 * @retval	int
*/
int SqList_Delet_ELem(SqList *L, int location, ElemType *data)
{
	if(location > L->length || L->length == 0) return FALSE;		// 假设location 比 L的长度大, 或者L的长度本身就位0,  返回false

	*data  = L->data[location - 1];									// 将data传过去

	for(int i = location - 1; i < L->length; i ++){					// 从location' 处开始, 所有数据一次向左移一位
		L->data[i] = L->data[i + 1];
	}

	L->length --;

	return TRUE;
}


/**
 * @brief	(改)修改某一个位置上面的元素
 * @param	L [SqList *] 线性表的指针
 * @param	location [int] 需要修改的元素所在的位置
 * @param	data [ElemType] 需要修改的元素的内容
 * @retval	int
*/
int SqList_Modify_Elem(SqList *L, int location, ElemType data)
{
	if(location > L->length) return FALSE;

	L->data[location - 1] = data;

	return TRUE;
}


/**
 * @brief	(查)查找某一个位置上面的元素并且返回
 * @param	L [SqList *] 线性表的指针
 * @param	location [int] 元素的位置
 * @param	data [ElemType *] 返回的元素
 * @retval	int
*/
int SqList_Find_Elem(SqList *L, int location, ElemType *data)
{
	if(location > L->length) return FALSE;

	*data = L->data[location - 1];

	return TRUE;
}