/*
	顺序存储的栈, L->top指向栈顶元素的情况
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define INCREMENT_SIZE 10

typedef int ElemType;
typedef struct{
	ElemType *data;
	int top;			// 栈顶指针, 没有元素的时候, 从-1开始
}SqStack;


bool InitStack(SqStack *S);
bool IfEmpty(SqStack S);
bool push(SqStack *S);
bool pop(SqStack *S, ElemType *e);
bool GetTop(SqStack S, ElemType *e);
bool ShowList(SqStack S);

int main(int argc, char const *argv[])
{
	SqStack S;

	InitStack(&S);

	push(&S);

	int e = 0;

	pop(&S, &e);

	ShowList(S);

	return 0;
}

bool InitStack(SqStack *S)
{
	S->data = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
	if(S->data == NULL){
		return FALSE;
	}

	S->top = -1;

	return TRUE;
}

// 入栈, top指针永远指向栈顶元素, 因此是 先++top指针, 再复制元素
bool push(SqStack *S)
{	
	int e = 0;	
	scanf("%d", &e);
	if(S->top == MAXSIZE - 1){
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

// 出栈
bool pop(SqStack *S, ElemType *e)
{
	if(S->top == -1){
		return FALSE;
	}
	*e = S->data[S->top];		// 显示用top的值
	S->top --;					// 再让top的值 - 1

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


bool ShowList(SqStack S)
{
	if(S.top == -1){
		return FALSE;
	}
	for(int i = S.top; i >= 0; i --){
		printf("%d  ", S.data[i]);
	}	

	return TRUE;
}