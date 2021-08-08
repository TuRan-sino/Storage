/*
	顺序存储的栈
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20
#define INCREMENT_SIZE 10

typedef int ElemType;
typedef struct{
	ElemType *data;
	int top;
}SqStack;


bool InitStack(SqStack *S);
bool IfEmpty(SqStack S);
bool push(SqStack *S);
bool pop(SqStack *S, ElemType *e);
bool GetTop(SqStack S, ElemType *e);
bool ShowList_TopToDown(SqStack S);

int main(int argc, char const *argv[])
{
	SqStack S;

	InitStack(&S);

	push(&S);

	int e = 0;

	pop(&S, &e);

	ShowList_TopToDown(S);

	return 0;
}

bool InitStack(SqStack *S)
{
	S->data = (ElemType *) malloc(sizeof(ElemType) * MaxSize);
	if(S->data == NULL){
		return FALSE;
	}

	S->top = -1;

	return TRUE;
}

bool push(SqStack *S)
{	int e = 0;
	scanf("%d", &e);
	if(S->top == MaxSize - 1){
		return FALSE;
	}else{
		while(e != -9999){
			S->data[++S->top] = e;
			scanf("%d", &e);
		}
	}

	return TRUE;
}

bool IfEmpty(SqStack S)
{
	if(S.top == -1){
		return TRUE;
	}else{
		return FALSE;
	}
}

bool pop(SqStack *S, ElemType *e)
{
	if(S->top == -1){
		return FALSE;
	}
	*e = S->data[S->top];
	S->top --;

	return TRUE;
}


bool GetTop(SqStack S, ElemType *e)
{
	if(S.top == -1){
		return FALSE;
	}
	*e = S.data[S.top];

	return TRUE;
}


bool ShowList_TopToDown(SqStack S)
{
	if(S.top == -1){
		return FALSE;
	}
	for(int i = S.top; i >= 0; i --){
		printf("%d  ", S.data[i]);
	}	

	return TRUE;
}