/***************************************************************************************************
@author: TuRan
@data: 
@des: 	双链表相关代码
		Dual linked list code
****************************************************************************************************/
#include "DLinkList.h"


int main(int argc, char *argv[])
{
	ElemType temp;
	DLinkList L;
	DLNode_Init(&L);
	DLNode_Creat_Tail(&L);


	DLNode_Elem_Modify(&L, 3, 0);

	DLNode_Show(L);
	DLNode_Show_Reverse(L);
}


/**
 * @brief	初始化双链表
 * @param	L [DLinkList *]
 * @retval	bool
*/
bool DLNode_Init(DLinkList *L)
{
	(*L) = malloc(sizeof(DLNode));
	if(!(*L)) return FALSE;

	(*L)->next = NULL;
	(*L)->data = 0;

	printf("Init Success\n");

	return TRUE;
}


/**
 * @brief	双链表使用头插法创建链表
 * @param	L [DLinkList *]
 * @retval	bool
*/
bool DLNode_Creat_Head(DLinkList *L)
{
	if(*L == NULL) return FALSE;
	printf("Start input\n");
	int x = 0;
	scanf("%d", &x);

	while(x != -9999){
		DLNode *s = malloc(sizeof(DLNode));
		
		if(!s) return FALSE;
		s->next = (*L)->next;
		if((*L)->next != NULL){
			(*L)->next->prior = s;
		}
		(*L)->next = s;
		s->prior = *L;
		s->data = x;
		scanf("%d", &x);
		(*L)->data ++;
	}

	return TRUE;
}


/**
 * @brief	双链表使用尾插法创建链表
 * @param	L [DLinkList *]
 * @retval	bool
*/
bool DLNode_Creat_Tail(DLinkList *L)
{
	DLNode *r = (*L);
	int x = 0;

	if((*L) == NULL) return FALSE;
	printf("Start input\n");

	scanf("%d", &x);
	while(x != -9999){
		DLNode *s = malloc(sizeof(DLNode));
		if(!s) return FALSE;
		s->data = x;
		s->next = r->next;
		r->next = s;
		s->prior = r;
		r = s;
		scanf("%d", &x);
	}

	return TRUE;
	
}


/**
 * @brief	双链表输出链表
 * @param	L [DLinkList]
 * @retval	void
*/
void DLNode_Show(DLinkList L)
{
	printf("Your DLNode is :");
	DLNode *p = L->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
}


/**
 * @brief	双链表输出链表(反转输出)
 * @param	L [DLinkList L]
 * @retval	void
*/
void DLNode_Show_Reverse(DLinkList L)
{
	printf("Your DLNode reverse is :");
	DLNode *p = L->next;
	while(p->next != NULL){
		p = p->next;
	}
	while(p != L){
		printf("%d ", p->data);
		p = p->prior;
	}
	putchar('\n');
}


/**
 * @brief	(增) 双链表在某一个节点后面增加一个节点
 * @param	L [DLinkList *] 需要修改的双链表
 * @param	location [int] 插入节点的位置
 * @param	num [ElemType] 新建节点的数据域内容
 * @retval	bool
*/
bool DLNode_Elem_Insert(DLinkList *L, int location, ElemType num)
{
	DLNode *p = (*L)->next;
	DLNode *s = malloc(sizeof(DLNode));
	if(!(*L)) return FALSE;

	s->data = num;

	for(int i = 0; i < location - 1; i ++){
		if(p == NULL) return FALSE;
		p = p->next;
	}
	
	if(p->next != NULL){
		p->next->prior = s;
	}
	s->next = p->next;
	p->next = s;
	s->prior = p;

	return TRUE;
}


/**
 * @brief	(删) 删除双链表的某一个节点, 并返回该节点的数据域内容
 * @param	L [DLinkList *] 进行操作双链表
 * @param	location [int] 需要删除节点的位置
 * @param	num [ElemType *] 被删除的数据域内容
 * @retval	bool
*/
bool DLNode_Elem_Delet(DLinkList *L, int location, ElemType *num)
{
	DLNode *p = (*L)->next;
	DLNode *temp;
	if(!(*L)) return FALSE;

	for(int i = 0; i < location - 1; i ++){
		if(p->next == NULL) return FALSE;
		p = p->next;
	}

	*num = p->data;

	p->prior->next = p->next;
	if(p->next != NULL){
		p->next->prior = p->prior;
	}

	free(p);

	return TRUE;
}


/**
 * @brief	(改) 修改双链表某一个节点上面的数值
 * @param	L [DLinkList *] 需要修改的双链表
 * @param	location [int] 需要修改的节点的位置
 * @param	num [ElemType] 需要修改的数据
 * @retval	bool
*/
bool DLNode_Elem_Modify(DLinkList *L, int location, ElemType num)
{
	DLNode *p = (*L)->next;
	if(!(*L)) return FALSE;

	for(int i = 0; i < location - 1; i ++){
		p = p->next;
		if(p == NULL) return FALSE;
	}

	p->data = num;

	return TRUE;
}


/**
 * @brief	(查)查询当前双链表某一个节点的数据域
 * @param	L [DLinkList] 需要查询的双链表
 * @param	location [int] 需要查询的双链表的节点的位置
 * @retval	ElemType 查询到的双链表节点的数据域内容
*/
ElemType DLNode_Elem_Find(DLinkList L, int location)
{
	DLNode *p = L->next;
	for(int i = 0; i < location; i ++){
		p = p->next;
		if(p == NULL) return FALSE;
	}

	return p->data;
}