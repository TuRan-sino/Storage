/*
	使用数组实现的顺序栈(与SqStack不同的是, SqStack使用的是动态分配方式生成的)
	初始化:
		初始化的时候将S.top指向-1 => 也就意味着top指针始终指向栈顶元素
		(假设S.top指向0 => 意味着top指针始终指向栈顶元素的下一个元素)
	pop:
		栈未满, 先让栈顶指针+1, 之后将元素添加到栈里面.
	push:
		栈未空, 先取栈顶元素的值, 之后再让栈顶元素-1.
	栈空条件: => s.top == -1; 栈满条件: s.top == MAXSIZE - 1(MAXSIZE从1开始有50个元素. 因此MAXSIZE从0开始有49个元素)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 50		// 最大容量

typedef int ElemType;
typedef struct SqStack{
	ElemType data[MAXSIZE];
	int top;
}SqStack;

bool InitStack(SqStack *S);
bool IfEmpty(SqStack S);
bool push(SqStack *S, ElemType x);
bool pop(SqStack *S, ElemType *x);
bool GetHead(SqStack S, ElemType *x);
bool ShowStack(SqStack S);

int main(int argc, char const *argv[])
{
	SqStack S;
	InitStack(&S);

	printf("Please enter your number\n");
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		push(&S, x);
		scanf("%d", &x);
	}

	ShowStack(S);

	return 0;
}

// 初始化
bool InitStack(SqStack *S)
{
	S->top = -1;

	return TRUE;
}


// 判空
bool IfEmpty(SqStack S)
{
	if(S.top == -1)
		return TRUE;
	else
		return FALSE;
}

// 入栈
bool push(SqStack *S, ElemType x)
{
	if(S->top >= MAXSIZE - 1)
		return FALSE;
	S->top ++;
	S->data[S->top] = x;

	return TRUE;
}

// 出栈
bool pop(SqStack *S, ElemType *x)
{
	if(S->top == -1)
		return FALSE;
	*x = S->data[S->top];
	S->top --;

	return TRUE;
}

bool GetHead(SqStack S, ElemType *x)
{
	if(S.top == -1)
		return FALSE;
	*x = S.data[S.top];

	return TRUE;
}

bool ShowStack(SqStack S)
{
	if(S.top == -1)
		return FALSE;
	int i = S.top;
	for(; i >= 0; i --){
		printf("%d ", S.data[i]);
	}

	return TRUE;
}