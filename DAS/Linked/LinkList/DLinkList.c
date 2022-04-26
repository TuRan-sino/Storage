/***************************************************************************************************
@author: TuRan
@data: 
@des: 	双链表相关代码
		Dual linked list code
****************************************************************************************************/
#include "DLinkList.h"


int main(int argc, char *argv[])
{
	DLinkList L;
	DLNode_Init(&L);
	DLNode_Creat_Tail(&L);
	DLNode_Show(L);
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
	DLNode *p = L->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
	printf("show over\n");
}


/**
 * @brief	双链表输出链表(反转输出)
 * @param	L [DLinkList L]
 * @retval	void
*/
void DLNode_Show_Reverse(DLinkList L)
{
	
	DLNode *p = L->next;
	while(p->next != NULL){
		p = p->next;
	}
	while(p != L){
		printf("%d ", p->data);
		p = p->prior;
	}
	putchar('\n');
	printf("show over\n");
}


/**
 * @brief	
 * @param
 * @note
 * @retval
*/
// bool