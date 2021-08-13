/*
	带头节点栈的链式表示
	规定只能再链头(头节点之后的那个节点)插入或者删除
		使用头插法建立单链表的方式来进栈,
		再表头的位置删除来出栈;
	一般情况下, 使用不带头节点方式建立代码 	
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
bool GetTop(LinkList S, ElemType *e);
bool pop(LinkList *S, ElemType *e);
bool push(LinkList *S);
bool DestoryList(LinkList S);


int main(int argc, char const *argv[])
{
	LinkList S;
	InitList(&S);

	printf("Please enter your number\n");
	push(&S);

	int e = 0;
	pop(&S, &e);
	pop(&S, &e);



	ShowList(S);

	printf("出栈元素: ");
	printf("%d\n", e);

	DestoryList(S);
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

bool push(LinkList *S)
{
	int e = 0;
	scanf("%d", &e);
	while(e != -9999){
		StackNode *p = (StackNode *) malloc(sizeof(StackNode));
		if(p == NULL){
			return FALSE;
		}
		p->data = e;
		p->next = (*S)->next;
		(*S)->next = p;
		scanf("%d", &e);
	}
	

	return TRUE;
}

bool pop(LinkList *S, ElemType *e)
{
	if((*S)->next == NULL){
		return FALSE;
	}
	StackNode *p = (*S)->next;
	(*S)->next = p->next;
	*e = p->data;
	free(p);

	return FALSE;
}

