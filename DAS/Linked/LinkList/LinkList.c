/****************************************************************************************************
@author: TuRan
@data: 	2022/4/14
@des: 	链表相关代码
		Linked list code
*****************************************************************************************************/
#include "LinkList.h"


int main(int argc, char *argv[])
{
	LinkList L;
	ElemType num;

	LNode_Init(&L);
	LNode_Creat_Tail(&L);

	LNode_Delet_Elem(&L, 3, &num);

	printf("%d\n", num);

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
	if(*L == NULL) return FALSE;
	LNode *r = (*L);		// 建立一个指针r, 始终指向最后一个节点
	ElemType x = 0;
	printf("Start input\n");
	scanf("%d", &x);

	while(x != -9999){
		LNode *s = malloc(sizeof(LNode));	// 新建一个节点, 用于随后的插入
		s->next = r->next;					// 将新节点的指针指向最后一个指针的next域
		s->data = x;						// 新节点指针data域赋值
		if(s == NULL) return FALSE;			// 假设新节点创建失败, 返回false
		r->next = s;						// 将最后一个指针的next域指向新节点
		r = s;								// 一切完成, r指向新节点, 也就是当前的最后一个指针
		(*L)->data ++;
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
	if(*L == NULL) return FALSE;
	ElemType x;
	LNode *s = NULL;
	printf("Start input\n");

	scanf("%d", &x);

	while(x != -9999){
		s = malloc(sizeof(LNode));		// 新建一个节点, 用于随后的插入
		s->data = x;				// 新节点data域赋值
		s->next = (*L)->next;			// 将新节点的next域指向头节点后面的那一个节点
		(*L)->next = s;					// 头节点的next域指向新节点
		(*L)->data ++;
		scanf("%d", &x);
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
	printf("Your LinkList is: ");
	LNode *temp;
	temp = L->next;

	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	putchar('\n');
	printf("Show over\n");
}


/**
 * @brief	(增) 在单链表的某一个位置后面插入一个节点
 * @param	L [LinkList *]
 * @param	location [int] 该节点插入的位置
 * @param	num [ElemType] 该节点data域的数据
 * @retval	bool
*/
bool LNode_Insert_Elem(LinkList *L, int locatoin, ElemType num)
{
	LNode *s = malloc(sizeof(LNode));
	LNode *p = (*L)->next;
	s->data = num;

	for(int i = 0; i < locatoin - 1; i ++){
		if(p == NULL) return FALSE;
		p = p->next;
	}

	s->next = p->next;
	p->next = s;

	return TRUE;
}


/**
 * @brief	(删) 删除单链表在某一个位置傻瓜的节点
 * @param	L [LinkList *] 操作的单链表
 * @param	location [int] 删除节点的位置
 * @param	num [ElemType *]	删除的节点的data域
 * @retval	bool
*/
bool LNode_Delet_Elem(LinkList *L, int location, ElemType *num)
{
	LNode *p = (*L)->next;
	LNode *temp;
	for(int i = 0; i < location - 2; i ++){
		if(p->next == NULL) return FALSE;
		p = p->next;
	}
	temp = p->next;
	if(temp == NULL) return FALSE;
	*num = temp->data;
	p->next = p->next->next;

	free(temp);

	return TRUE;
}


/**
 * @brief	(改) 修改单链表某一个位置上的元素
 * @param	L [LinkList]
 * @param	location [int] 该元素在单链表上的位置
 * @param	num [ElemType] 该元素需要修改的内容
 * @retval	bool
*/
bool LNode_Modify_Elem(LinkList L, int location, ElemType num)
{
	LNode *p = L->next;
	for(int i = 0; i < location - 1; i ++){
		if(p == NULL){
			return FALSE;
		}
		p = p->next;
	}

	p->data = num;

	return TRUE;
}


/**
 * @brief	(查)查找单链表中的某一个元素
 * @param	L [LinkList] 被查找的单链表
 * @param	location [int] 该元素在单链表上的位置 (从1开始)
 * @retval	ElemType
*/
ElemType LNode_Find_Elem(LinkList L, int location)
{
	LNode *p = L->next;
	for(int i = 0; i < location - 1; i ++){
		if(p == NULL) return -9999;
		p = p->next;
	}

	return p->data;
}
