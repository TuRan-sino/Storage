/*
	顺序存储的循环队列, 先进先出.
		本例中虽然没有表示next域, 但是可以知道的是
	插入操作只能在队尾实现(rear), 删除操作只能在对头实现(front).
	初始化的时候Q->front & Q->rear 都为0; 且Q->rear永远指向尾节点的下一个节点
	不同普通循环队列的是: front & rear 在本例中都是 ++
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20	// 设置最大容量为20

typedef int ElemType;
typedef struct SqQueue{
	ElemType *data;
	int front;		// 这里的标识符类型为int型, 本例中循环队列为顺序存储; front 表示对头
	int rear;		// rear表示队尾
}SqQueue;


bool InitQueue(SqQueue *Q);
bool IfEmpty(SqQueue Q);
bool EnQueue(SqQueue *Q, ElemType x);
bool OutQueue(SqQueue *Q, ElemType *x);
bool GetHead(SqQueue Q, ElemType *x);
int QueueLength(SqQueue Q);
bool ShowQueue(SqQueue Q);
bool DestoryQueue(SqQueue *Q);
bool Select(SqQueue *Q);

int main(int argc, char const *argv[])
{


	SqQueue Q;
	InitQueue(&Q);	

	Select(&Q);


	DestoryQueue(&Q);

	return 0;

}

// 初始化
bool InitQueue(SqQueue *Q)
{
	(*Q).data = (ElemType *) malloc(sizeof(ElemType) * MaxSize);		// 创建头节点, Q是一个指针类型, 指向头节点
	if(Q == NULL)
		return FALSE;		// 创建失败
	Q->front = Q->rear = 0;		// 初始化的时候使得Q->front & Q->rear 都指向0这个位置, 因为rear始终指向尾节点的下一个节点, 因此当rear和front同时指向0的时候, 队空

	return TRUE;
}

// 判断队空
bool IfEmpty(SqQueue Q)
{
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

// 入队
bool EnQueue(SqQueue *Q, ElemType x)
{
	if((Q->rear + 1 ) % MaxSize == Q->front)
		return FALSE;		
	/*
		(rear + 1) % MaxSize 也就是表示rear + 1 对MaxSize 取余.
			MaxSize的作用: 因为本例是循环链表, 因此无论如何不可以超过MaxSize;
			为什么不是Maxsize - 1? : 因为MaxSize是从1开始的(rear & front 是从0开始的), 
				因此理论上的MaxSize(从0开始的话)为Maxsize - 1;
			因此设置模的时候要将实际上的Maxsize 加上 1, 也就是MaxSize - 1 + 1 = MaxSize;
				当rear = MaxSize - 1的时候相当于满了, 取余 = Maxsize - 1, 相当于满员;
				当rear = MaxSize的时候超出一个, 取余 = 1;
			eg: Maxsize = 10 实际的Maxsize(从0开始的话) = 9;
			假设 	rear = 9 => 取余之后的rear = 9;
					rear = 10 => 取余之后的rear = 0;
	*/
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;

	return TRUE;
}

// 出队
bool OutQueue(SqQueue *Q, ElemType *x)
{
	if(Q->rear == Q->front)
		return FALSE;
	*x = Q->data[Q->front];		// 将front的date赋值给x;
	Q->front = (Q->front + 1) % MaxSize;		// front + 1;

	return TRUE;
}

// 获取队头元素
bool GetHead(SqQueue Q, ElemType *x)
{
	if(Q.front == Q.rear)
		return FALSE;
	*x = Q.data[Q.front];		// data是一个数组, 将data数组里面的第Q.front个元素赋值给x

	return TRUE;
}

// 求队长
int QueueLength(SqQueue Q)
{
	int x = 0;		// 工作int ,用来记录队长
	x = (Q.rear + MaxSize - Q.front) % MaxSize;
	/*
			
	*/

	return x;
}

// 遍历队列并打印
bool ShowQueue(SqQueue Q)
{
	if(Q.front == Q.rear)
		return FALSE;
	int i = Q.front;		// i作为工作计数器
	while(i % MaxSize != Q.rear){
		/*
			i是从front开始的, 给i取余一直到i到rear为止
		*/
		printf("%d ", Q.data[i]);
		i = (i + 1) % MaxSize;
	}

	printf("\n");

	return TRUE;
}

// 销毁队列
bool DestoryQueue(SqQueue *Q)
{
	free(Q->data);

	Q->rear = 0;
	Q->front = 0;

	return TRUE;
}

bool Select(SqQueue *Q)
{
	printf("Please down enter to start this program\n");
	while(1){
		char x;
		getchar();
		printf("Please enter your choice\n");
		printf("a. Enqueue	b. OutQueue\n");
		printf("c. ShowQueue	d. exit\n");	
		scanf("%c", &x);
		if(x == 'a'){
			printf("Please enter your number\n");
			int y = 0;
			scanf("%d", &y);
			while(y != -9999){	
				EnQueue(Q, y);
				scanf("%d", &y);
			}
			printf("\n");
		}else if(x == 'b'){
			int y = 0;
			OutQueue(Q, &y);
			printf("your OutQueue number is %d\n", y);
			printf("\n");
		}else if(x == 'c'){
			printf("Your queue is\n");
			ShowQueue(*Q);
			printf("\n");
		}else if(x == 'd'){
			return FALSE;
		}
	}
}