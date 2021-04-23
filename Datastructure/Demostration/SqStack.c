/*
	顺序存储的栈
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20

typedef int ElemType;
typedef struct{
	ElemType *data;
	int top;
}SqStack;



bool InitStack(SqStack *S);
bool IfEmpty(SqStack s);
bool push(SqStack *S, ElemType e);
bool pop(SqStack *S, ElemType *e);
bool ShowList(SqStack S);
bool GetTop(SqStack S, ElemType *e);


int main(int argc, char const *argv[])
{
	SqStack S;
	InitStack(&S);



	push(&S, 3);

	int e;

	GetTop(S, &e);

	printf("%d\n", e);
	// printf("%d\n", S.top);
	// ShowList(S);
	return 0;
}


bool InitStack(SqStack *S)
{
	(*S).data = (ElemType *) malloc(sizeof(ElemType) * MaxSize);
	if(!S->data){
		return FALSE;
	}
	S->top = -1;

	return TRUE;
}

bool IfEmpty(SqStack S)
{
	if(S.top == -1){
		return TRUE;
	}else
		return FALSE;
}

bool push(SqStack *S, ElemType e)
{
	if(S->top == MaxSize - 1){
		return FALSE;
	}
	S->data[++S->top] = e;

	return TRUE;
}

bool pop(SqStack *S, ElemType *e)
{
	if(S->top == -1){
		return FALSE;
	}
	*e = S->data[S->top --];

	return TRUE;
}

bool ShowList(SqStack S)
{
	if(S.top == -1){
		return FALSE;
	}
	for(int i = 0; i <= S.top; i ++){
		printf("%d ", S.data[i]);
	}
	printf("\n");

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

