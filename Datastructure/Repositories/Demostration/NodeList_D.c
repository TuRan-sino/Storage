/*
	双链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../C/Lib/lib_c.h"




typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next; // prior->前向节点, next->后向节点
}DNode, *DLinkList;

bool InitDLinList(DLinkList *L);
bool InsertNextDNode(DNode *p, DNode *s);
bool Creat_List_head(DLinkList *L);
void ShowList(DLinkList L);
bool Creat_List_Tail(DLinkList *L);
void DestoryList(DLinkList *L);
bool DeletNextDNode(DNode *p, ElemType *e);
bool IfEmpty(DLinkList L);
bool InsertPriorDNode(DNode *p, DNode *s);


int main(int argc, char const *argv[])
{
	DLinkList L;

	InitDLinList(&L);


	Creat_List_Tail(&L);


	ShowList(L);


	return 0;
}




// 初始化双链表
bool InitDLinList(DLinkList *L)
{
	*L = (DNode *) malloc(sizeof(DNode));
	if(*L == NULL){
		return FALSE;
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;

	return TRUE;
}

bool IfEmpty(DLinkList L)
{
	if(L->next == NULL){
		return TRUE;
	}else
		return FALSE;
}

// 在p节点后面插入s节点
bool InsertNextDNode(DNode *p, DNode *s)
{
	if(p == NULL || s == NULL){
		return FALSE;
	}
	s->next = p->next;
	if(p->next != NULL)					//如果 P 节点后面没有指针那么就没有必要再去修改 p 节点的后向指针
		p->next->prior = s;
	s->prior = p;
	p->next = s;

	return TRUE;
}

// 在p节点之前插入s节点
bool InsertPriorDNode(DNode *p, DNode *s)
{
	if(p == NULL || s == NULL){
		return FALSE;
	}
	s->prior = p->prior;
	if(p->prior != NULL)
		p->prior->next = s;
	s->next = p;
	p->prior = s;

	return TRUE;
}

// 使用头插法建立双链表
bool Creat_List_head(DLinkList *L)	
{
	if(*L == NULL){
		return FALSE;
	}
	DNode *s;
	(*L)->next = NULL;
	int x;
	scanf("%d", &x);
	while(x != -9999){
		s = (DNode *) malloc(sizeof(DNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &x);
	}

	return TRUE;
}

// 尾插法建立双链表
bool Creat_List_Tail(DLinkList *L)
{
	if(*L == NULL){
		return FALSE;
	}
	DNode *r = NULL;
	(*L)->next = NULL;
	DNode *s = *L;
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		r = (DNode *) malloc(sizeof(DNode));
		r->data = x;
		r->next = s->next;
		s->next = r;
		s = r;
		scanf("%d", &x);
	}

	return TRUE;
}

// 遍历双链表
void ShowList(DLinkList L)
{
	DLinkList p = L->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 销毁双链表
void DestoryList(DLinkList *L)
{
	while((*L)->next != NULL){
		DeletNextDNode(*L);
	}
	free(*L);
	L = NULL;
}

bool DeletNextDNode(DNode *p, ElemType *e)
{
	if(p == NULL)
		return FALSE;
	DNode *q = p->next;
	if(q == NULL)
		return FALSE;
	p->next = q->next;
	if(q->next != NULL){
		q->next->prior = p;
	}
	*e = q->data;
	free(q);

	return TRUE;
}

