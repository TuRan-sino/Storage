/*
	链式存储的队列
	不带头结点的版本
		front指向第一个元素
		rear指向最后一个元素	
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
bool IfEmpty(LinkQueue Q);
bool EnQueue(LinkQueue *Q, ElemType x);
bool OutQueue(LinkQueue *Q, ElemType *x);
bool ShowQueue(LinkQueue Q);

int main(int argc, char const *argv[])
{
	LinkQueue Q;
	InitQueue(&Q);

	printf("Please input your number\n");
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		EnQueue(&Q, x);
		scanf("%d", &x);
	}
	ShowQueue(Q);


	return 0;
}

bool InitQueue(LinkQueue *Q)
{	
	Q->front = NULL;
	Q->rear = NULL;	

	return TRUE;
}

bool IfEmpty(LinkQueue Q)
{
	if(Q.front == NULL)		// 也可以判断rear是否指向null
		return TRUE;
	else 
		return FALSE;
}

bool EnQueue(LinkQueue *Q, ElemType x)
{
	LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if(Q->front == NULL){	// 链队列为空的情况下	
		Q->front = s;
		Q->rear = s;
	}else{					// 链队列不为空的情况下
		Q->rear->next = s;
		Q->rear = s;
	}

	return TRUE;
}

bool OutQueue(LinkQueue *Q, ElemType *x)
{
	if(IfEmpty(*Q) == TRUE)
		return FALSE;
	LinkNode *temp = Q->front;
	*x = temp->data;
	Q->front = temp->next;
	if(Q->rear == temp){
		Q->front = NULL;
		Q->rear = NULL;
	}
	free(temp);

	return TRUE;
}

bool ShowQueue(LinkQueue Q)
{
	LinkNode *temp;
	temp = Q.front;
	if(Q.front == NULL)
		return FALSE;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}

	return TRUE;
}