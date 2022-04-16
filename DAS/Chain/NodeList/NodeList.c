/****************************************************************************************************
@author: TuRan
@data: 2022/4/14
@des: 
****************************************************************************************************/
#include <stdio.h>
#include "NodeList.h"


int main(int argc, char *argv[])
{
	LinkList L;

	LNode_Init(&L);
	LNode_Creat_Head(&L);

	LNode_Show(L);
}


/**
 * @brief	初始化单链表
 * @param	L [LinkList *]
 * @note	LinkList 本身就是 LNode 指针类型, LinkList * 也就是 LNode 的二重指针
 * @retval	bool
*/
bool LNode_Init(LinkList *L)
{
	*L = (LNode *)malloc(sizeof(LNode));	// malloc 返回指针类型(LNode * == LinkList), 
											// 为了能够使得 LinkList 的指针得到改变, 此处必须使用 LinkList *类型
	if(!*L) return FALSE;

	(*L)->next = NULL;						// 初始时将L的next节点设置位null, 防止出现问题
	(*L)->length = 0;

	printf("Initial Success\n");

	return TRUE;
}


/**
 * @brief	头插法创建单链表
 * @param	L [LinkList *]
 * @note	每次在头结点的后面创建节点, 这里完全不需要使用LinkList *类型, 但是为了统一起见, 这里也使用 LinkList * 类型
 * 			也就是二重指针
 * @retval	bool
*/
bool LNode_Creat_Head(LinkList *L)
{
	ElemType TempData;
	LNode *s = NULL;

	scanf("%d", &TempData);

	while(TempData != -9999){
		s = malloc(sizeof(LNode));
		s->data = TempData;
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &TempData);
		(*L)->length ++;
	}

	return TRUE;
}


/**
 * @brief	输出单链表
 * @param	L [LinkList]
 * @retval	void
*/
void LNode_Show(LinkList L)
{
	LNode *temp;
	temp = L->next;

	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	putchar('\n');
	printf("show over\n");
}
