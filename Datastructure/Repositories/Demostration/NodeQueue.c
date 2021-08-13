/*
	链式存储的队列
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct LinkNode{	// 链式结点
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{				// 队列结点
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;

bool InitQueue(LinkQueue *Q);

int main(int argc, char const *argv[])
{
	LinkQueue Q;
	InitQueue(&Q);	


	return 0;
}

bool InitQueue(LinkQueue *Q)
{
	// Q = (LinkQueue *) malloc(sizeof(LinkQueue));	// 这句话可以省略, 因为在主函数声明的时候就已经声明变量了, 本质上不就是几个指针吗?	
	if(Q == NULL)
		return FALSE;
	Q->front = NULL;
	Q->rear = NULL;

	return TRUE;
}

bool IfEmpty(LinkQueue Q)
{
	if(Q.front == NULL)
		return TRUE;
	else 
		return FALSE;
}

bool EnQueue(LinkQueue *Q, ElemType X)
{
		
}