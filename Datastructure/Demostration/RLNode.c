/*
	单链表的循环链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../C/Lib/lib_c.h"

typedef int ElemType;
typedef struct RLNode{
	ElemType data;
	struct RLNode *next; 
}RLNode, *LinkList;

bool IfEmpty(LinkList L);
bool IsTail(LinkList L, RLNode *p);
bool InitList(LinkList *L);
bool CreatList_Tail(LinkList *L);
bool ShowList(LinkList L);
bool CreatList_Head(LinkList *L);
int GetElem(LinkList L, int i);
bool DeletElem(LinkList L, int i, ElemType *e);
int GetLength(LinkList L);
bool InsertElem(LinkList L, int i, ElemType e);



int main(int argc, char const *argv[])
{
	LinkList L;
	InitList(&L);
	
	IfEmpty(L);


	printf("Please enter you RLNode\n");
	CreatList_Tail(&L);


	InsertElem(L, 2, 3);



	ShowList(L);


	return 0;
}

bool CreatList_Tail(LinkList *L)
{
	RLNode *p = *L;
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		RLNode *s = (RLNode *) malloc(sizeof(RLNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		p = s;
		scanf("%d", &x);
	}

	return TRUE;
}

bool CreatList_Head(LinkList *L)
{
	RLNode *p;
	p = (RLNode *) malloc(sizeof(RLNode));
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		p->data = x;
		p->next = (*L)->next;
		(*L)->next = p;
		p = (RLNode *) malloc(sizeof(RLNode));
		scanf("%d", &x);
	}

	return TRUE;
}

bool InitList(LinkList *L)
{
	(*L) = (RLNode *) malloc(sizeof(RLNode));
	if((*L) == NULL){
		return FALSE;
	}
	(*L)->next = (*L);
	return TRUE;
}

bool IfEmpty(LinkList L)
{
	if(L->next == L){
		return TRUE;
	}else 
		return FALSE;
}

bool IsTail(LinkList L, RLNode *p)
{
	if(p->next == L){
		return TRUE;
	}else
		return FALSE;
}

bool ShowList(LinkList L)
{
	if(L == NULL || L->next == L){
		return FALSE;
	}
	RLNode *p = L->next;
	while(p != L){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	return TRUE;
}

int GetElem(LinkList L, int i)
{
	int counter = 0;
	RLNode *p = L;
	while(counter < i){
		p = p->next;
		counter ++;
	}

	return p->data;
}

bool DeletElem(LinkList L, int i, ElemType *e)
{
	RLNode *p = L;
	RLNode *temp;
	int counter = 0;
	while(counter < i - 1){
		p = p->next;
		counter ++;
	}
	*e = p->next->data;
	temp = p->next;
	p->next = p->next->next;

	free(temp);


	return TRUE;
}

int GetLength(LinkList L)
{
	int counter	= 1;
	RLNode *p = L->next;
	while(p->next != L){
		p = p->next;
		counter ++;
	}

	return counter;
}

bool InsertElem(LinkList L, int i, ElemType e)
{
	if(i < 0 || i > GetLength(L)){
		return FALSE;
	}
	RLNode *p = L->next;
	if(i == 0){
		RLNode *s = (RLNode *) malloc(sizeof(RLNode));
		s->next = L->next;
		L->next = s;
		s->data = e;

		return TRUE;
	}
	int counter = 1;
	for(; counter < i; counter ++){
		p = p->next;
	}
	RLNode *s = (RLNode *) malloc(sizeof(RLNode));
	s->next = p->next;
	p->next = s;
	s->data = e;


	return TRUE;
}