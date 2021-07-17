/*
	带头节点栈的链式表示
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0


typedef int ElemType;
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkList;


bool InitList(LinkList *S);
bool ShowList(LinkList S);
bool CreatList_Head(LinkList S);
bool GetTop(LinkList S, ElemType *e);
bool pop(LinkList S, ElemType *e);
bool push(LinkList S, ElemType e);
bool DestoryList(LinkList S);


int main(int argc, char const *argv[])
{
	LinkList S;
	InitList(&S);

	printf("Please Enter your Stack\n");
	CreatList_Head(S);

	push(S, 3);
	int e;
	pop(S, &e);



	ShowList(S);

	printf("%d\n", e);


	DestoryList(S);
	return 0;
}

bool InitList(LinkList *S)
{
	(*S) = (StackNode *) malloc(sizeof(StackNode));
	(*S)->next = NULL;
	if(*S == NULL){
		return FALSE;
	}

	return TRUE;
}

bool CreatList_Head(LinkList S)
{
	StackNode *p = (StackNode *) malloc(sizeof(StackNode));
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		p->data = x;
		p->next = S->next;
		S->next = p;
		scanf("%d", &x);
		p = (StackNode *) malloc(sizeof(StackNode));
	}

	return TRUE;
}

bool ShowList(LinkList S)
{
	if(S == NULL){
		return FALSE;
	}
	StackNode *p = S->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");


	return TRUE;
}

bool GetTop(LinkList S, ElemType *e)
{
	if(S->next == NULL){
		return FALSE;
	}
	StackNode *p = S->next;
	*e = p->data;

	return TRUE;
}

bool DestoryList(LinkList S)
{
	if(S == NULL){
		return FALSE;
	}
	StackNode *p = S->next;
	while(p != NULL){
		free(S);
		S = p;
		p = p->next;
	}

	return TRUE;
}

bool push(LinkList S, ElemType e)
{
	StackNode *p = (StackNode *) malloc(sizeof(StackNode));
	if(p == NULL){
		return FALSE;
	}
	p->data = e;
	p->next = S->next;
	S->next = p;

	return TRUE;
}

bool pop(LinkList S, ElemType *e)
{
	if(S->next == NULL){
		return FALSE;
	}
	StackNode *p = S->next;
	S->next = p->next;
	*e = p->data;
	free(p);

	return FALSE;
}

