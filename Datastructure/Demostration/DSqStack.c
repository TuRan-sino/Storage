/*
	顺序实现的栈的共享栈
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20
#define STAR "********************"

typedef int ElemType;
typedef struct{
	ElemType *data;
	int top_up;			//从下往上存储的栈
	int top_down;		//从上往下存储的栈
}SqStack;

bool InitStack(SqStack *S);
bool IfEmpty(SqStack S);
bool push_up(SqStack *S, ElemType e);
bool push_down(SqStack *S, ElemType e);
bool pop_up(SqStack *S, ElemType *e);
bool pop_down(SqStack *S, ElemType *e);
bool ShowList(SqStack S);
bool GetTop(SqStack S, ElemType *m, ElemType *n);

int main(int argc, char const *argv[])
{
	SqStack S;
	InitStack(&S);
	int e;

	push_up(&S, 3);
	push_down(&S,3);


	pop_up(&S, &e);

	ShowList(S);


	int m, n;
	GetTop(S, &m, &n);
	printf("%d\n", m);
	printf("%d\n", n);


	return 0;
}

bool InitStack(SqStack *S)
{
	(*S).data = (ElemType *) malloc(sizeof(ElemType) * MaxSize);
	if(!S->data){
		return FALSE;
	}
	S->top_up = -1;
	S->top_down = MaxSize;

	return TRUE;
}

bool IfEmpty(SqStack S)
{
	if(S.top_up == -1 && S.top_down == MaxSize){
		return TRUE;
	}else
		return FALSE;
}

bool push_up(SqStack *S, ElemType e)
{
	if(S->top_down - S->top_up == 1){
		return FALSE;
	}
	S->data[++ S->top_up] = e;

	return TRUE;
}

bool push_down(SqStack *S, ElemType e)
{
	if(S->top_down - S->top_up == 1){
		return FALSE;
	}
	S->data[-- S->top_down] = e;

	return TRUE;
}

bool pop_up(SqStack *S, ElemType *e)
{
	if(S->top_up == -1){
		return FALSE;
	}
	*e = S->data[S->top_up --];

	return TRUE;
}

bool pop_down(SqStack *S, ElemType *e)
{
	if(S->top_down == MaxSize){
		return FALSE;
	}
	*e = S->data[S->top_down ++];

	return TRUE;
}

bool ShowList(SqStack S)
{
	if(S.top_up == -1 && S.top_down == MaxSize){
		return FALSE;
	}
	if(S.top_up == -1)
		goto break0;
	for(int i = 0; i <= S.top_up; i ++){
		printf("%d ", S.data[i]);
	}
	printf("\n");
break0:
	puts(STAR);	
	if(S.top_down == MaxSize)
		goto break1;
	for(int j = MaxSize - 1; j >= S.top_down; j --){
		printf("%d\n", S.data[j]);
	}
	printf("\n");


break1:

	return TRUE;
}

bool GetTop(SqStack S, ElemType *m, ElemType *n)
{
	if(S.top_up == -1 && S.top_down == MaxSize){
		return FALSE;
	}

	if(S.top_up == -1){
		*m = -9999;
	}else{
		*m = S.data[S.top_up];
	}

	if(S.top_down == MaxSize){
		*n = -9999;
	}else{
		*n = S.data[S.top_down];
	}






	return TRUE;
}

