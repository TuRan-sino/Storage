/*
	链式存储的双端队列
	允许从两端插入, 也允许从两端删除
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20

typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front;
	LinkNode *rear;
	int length;			// length表示当前节点个数
}LinkQueue;

int main(int argc, char const *argv[])
{
		



	return 0;
}

bool InitQueue(LinkQueue *Q)
{
	Q->rear = Q->front = (LinkNode *) malloc(sizeof(LinkNode));
	if(Q->front == NULL || Q->rear == NULL)
		return FALSE;
	else
		return TRUE;
}

