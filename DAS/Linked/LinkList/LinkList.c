/****************************************************************************************************
@author: TuRan
@data: 	2022/4/14
@des: 	链表相关代码
		Linked list code
****************************************************************************************************/
#include "LinkList.h"


int main(int argc, char *argv[])
{
	LinkList L;

	LNode_Init(&L);
	LNode_Creat_Tail(&L);
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

	printf("Initial Success\n");

	return TRUE;
}


/**
 * @brief	尾插法创建链表
 * @param	L [LinkList *]
 * @retval	bool
*/
bool LNode_Creat_Tail(LinkList *L)
{
	LNode *r = (*L);		// 建立一个指针r, 始终指向最后一个节点
	ElemType x = 0;
	scanf("%d", &x);

	while(x != -9999){
		LNode *s = malloc(sizeof(LNode));	// 新建一个节点, 用于随后的插入
		s->next = r->next;					// 将新节点的指针指向最后一个指针的next域
		s->data = x;						// 新节点指针data域赋值
		if(s == NULL) return FALSE;			// 假设新节点创建失败, 返回false
		r->next = s;						// 将最后一个指针的next域指向新节点
		r = s;								// 一切完成, r指向新节点, 也就是当前的最后一个指针
		scanf("%d", &x);
	}
	
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
		s = malloc(sizeof(LNode));		// 新建一个节点, 用于随后的插入
		s->data = TempData;				// 新节点data域赋值
		s->next = (*L)->next;			// 将新节点的next域指向头节点后面的那一个节点
		(*L)->next = s;					// 头节点的next域指向新节点
		scanf("%d", &TempData);
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