/*
	顺序实现的循环队列, 先进先出;
	插入操作只能在队尾(rear), 删除操作只能在对头(front);
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20

typedef int ElemType;
typedef struct SqQueue{
	ElemType *data;
	int front;	// 队头指针
	int rear;	// 队尾指针
}SqQueue;

bool InitQueue(SqQueue *Q);
bool IfEmpty(SqQueue Q);
bool EnQueue(SqQueue *Q, ElemType x);
bool OutQueue(SqQueue *Q, ElemType *x);
bool GetHead(SqQueue Q, ElemType *x);
int QueueLength(SqQueue Q);
int ShowQueue(SqQueue Q);
bool DestoryQueue(SqQueue *Q);

int main(int argc, char const *argv[])
{
	SqQueue Q;
	InitQueue(&Q);

	int output = 0;
	int x = 0;
	printf("Please enter your number\n");
	scanf("%d", &x);
	while(x != -9999){
		EnQueue(&Q, x);
		scanf("%d", &x);
	}

	GetHead(Q, &output);

	printf("%d\n", output);

	DestoryQueue(&Q);


	return 0;
}

bool InitQueue(SqQueue *Q)
{
	(*Q).data = (ElemType *) malloc(sizeof(ElemType) * MaxSize);
	if(Q == NULL)
		return FALSE;
	Q->front = Q->rear = 0;

	return TRUE;
}

bool IfEmpty(SqQueue Q)
{
	if(Q.front == Q.rear){	// 初始化的时候设置对头和队尾指针都指向同一个为位置
		return TRUE;
	}else
		return FALSE;
}

// 入队
bool EnQueue(SqQueue *Q, ElemType x)
{
	if((Q->rear + 1) % MaxSize == Q->front)
		return FALSE;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) %MaxSize;

	return TRUE;
}

// 出队
bool OutQueue(SqQueue *Q, ElemType *x)
{
	if(Q->rear == Q->front)
		return FALSE;
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;

	return TRUE;
}

bool GetHead(SqQueue Q, ElemType *x)
{
	if(Q.front == Q.rear)
		return FALSE;
	*x = Q.data[Q.front];

	return TRUE;
}

int QueueLength(SqQueue Q)
{
	int x = 0;
	x = (Q.rear + MaxSize - Q.front) % MaxSize;

	return x;
}

int ShowQueue(SqQueue Q)
{
	if(Q.front == Q.rear){
		return FALSE;
	}
	int i = Q.front;
	while(i % MaxSize != Q.rear){
		printf("%d ", Q.data[i]);
		i = (i + 1) % MaxSize;
	}

	return TRUE;
}

bool DestoryQueue(SqQueue *Q)
{
	free(Q->data);

	Q->rear = 0;
	Q->front = 0;

	return TRUE;
}