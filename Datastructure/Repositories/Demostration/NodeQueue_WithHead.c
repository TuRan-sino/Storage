/*
	链式存储的队列
	带头结点的版本
		front指向头指针
		rear指向最后一个元素	
	入队从rear入;
	出队从front出;
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
bool ShowQueue(LinkQueue Q);
bool OutQueue(LinkQueue *Q, ElemType *x);


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
	Q->front = Q->rear = (LinkNode *) malloc(sizeof(LinkNode));
	if(Q->front == NULL || Q->rear == NULL)
		return FALSE;
	Q->front->next = NULL;

	return TRUE;
}

bool IfEmpty(LinkQueue Q)
{
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;	
}

bool EnQueue(LinkQueue *Q, ElemType x)
{
	LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
	if(s == NULL){
		return FALSE;
	}
	s->data = x;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;

	return TRUE;
}

bool OutQueue(LinkQueue *Q, ElemType *x)
{
	if(IfEmpty(*Q) == 1)
		return FALSE;
	LinkNode *temp;
	temp = Q->front->next;
	*x = Q->front->next->data;
	Q->front->next = Q->front->next->next;
	if(Q->rear == temp)
		Q->rear = Q->front;
	free(temp);

	return TRUE;
}


bool ShowQueue(LinkQueue Q)
{
	LinkNode *temp;
	temp = Q.front;
	if(Q.rear == Q.front)
		return FALSE;
	while(temp->next != NULL){
		temp = temp->next;
		printf("%d ", temp->data);
	}

	return TRUE;
}
