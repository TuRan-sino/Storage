/*
	双链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../C/Lib/lib_c.h"




typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

bool InitDLinList(DLinkList *L);
bool InsertNextDLNde(DNode *p, DNode *s);
DLinkList Creat_List_head(DLinkList L);
void ShowList(DLinkList L);
DLinkList Creat_List_Tail(DLinkList L);
void DestoryList(DLinkList *L);
bool DeletNextDNode(DNode *p);
bool IfEmpty(DLinkList L);


int main(int argc, char const *argv[])
{

	bool status = 0;


	DLinkList L = NULL;			//DLinkList 仅仅只是申明了一个指针,这个指针指向的区域暂时是没有内存空间的
	printf("Please enter your data\n");
	L = Creat_List_Tail(L);
	ShowList(L);

	// DNode *s = (DNode *) malloc(sizeof(DNode));
	// s->data = 3;
	// InsertNextDLNde(L->next, s);

	ShowList(L);

	DestoryList(&L);

	status = IfEmpty(L);


	printf("%d\n", status);

	return 0;
}





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

bool InsertNextDLNde(DNode *p, DNode *s)
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

DLinkList Creat_List_head(DLinkList L)	//Creat_List_head 不需要初始化了,它里面自带初始化 L 链表
{
	DNode *s;
	L = (DLinkList) malloc(sizeof(DNode));
	L->next = NULL;
	int x;
	scanf("%d", &x);
	while(x != -9999){
		s = (DNode *) malloc(sizeof(DNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}

	return L;
}


DLinkList Creat_List_Tail(DLinkList L)
{
	DNode *r = NULL;
	L = (DLinkList) malloc(sizeof(DNode));
	L->next = NULL;
	DNode *s = L;
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

	return L;
}


void ShowList(DLinkList L)
{
	DLinkList p = L->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void DestoryList(DLinkList *L)
{
	while((*L)->next != NULL){
		DeletNextDNode(*L);
	}
	free(*L);
	L = NULL;
}

bool DeletNextDNode(DNode *p)
{
	if(p == NULL)
		return FALSE;
	DNode *q = p->next;
	p->next = q->next;
	if(q->next != NULL){
		q->next->prior = p;
	}
	free(p);

	return TRUE;
}

