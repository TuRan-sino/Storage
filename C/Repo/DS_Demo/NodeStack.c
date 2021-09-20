/*
	链式存储的栈_带头节点的版本
		规定只能再链头(头节点之后的那个节点)插入或者删除, 链头相当栈顶指针top
		!!!使用头插法建立单链表的方式来进栈, 表头的位置删除来出栈;
		(一般情况下, 使用不带头节点方式建立代码)
	init:	S->next 指向 NULL
	push:	先创建一个新的节点p
			节点p的内容(data)设置为x
			使节点p的下一个节点为头节点S的下一个节点
			再将头节点S的下一个节点设置为节点p, 头插法插入p节点
	pop:	声明一个新的StackNode类型的节点p指向S->next
			使得S->next指向p->next(S->next指向下下个节点)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

 
typedef int ElemType;
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkList;


bool InitList(LinkList *S);
bool ShowList(LinkList S);
bool GetTop(LinkList S, ElemType *e);
bool pop(LinkList *S, ElemType *e);
bool DestoryList(LinkList S);
bool push(LinkList *S, ElemType x);


int main(int argc, char const *argv[])
{
	LinkList S;
	InitList(&S);

	printf("Please enter your number\n");
	int x = 0;
	scanf("%d", &x);	
	while(x != -9999){
		push(&S, x);
		scanf("%d", &x);
	}


	int y = 0;
	pop(&S, &y);
	printf("%d\n", y);

	ShowList(S);

	DestoryList(S);
}

// 初始化栈
bool InitList(LinkList *S)
{
	(*S) = (StackNode *) malloc(sizeof(StackNode));		// 为S分配新的物理空间
	(*S)->next = NULL;		// 是S->next == NULL, 老生常谈了
	if(*S == NULL){
		return FALSE;
	}

	return TRUE;
}

// 遍历并打印栈
bool ShowList(LinkList S)
{
	if(S == NULL)
		return FALSE;		// 分配不成功 || S不存在
	StackNode *p = S->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");


	return TRUE;
}

// 获取栈顶元素
bool GetTop(LinkList S, ElemType *e)
{
	if(S->next == NULL)
		return FALSE;
	StackNode *p = S->next;		// S->next相当于栈顶指针
	*e = p->data;

	return TRUE;
}

// 销毁栈
bool DestoryList(LinkList S)
{
	if(S == NULL){
		return FALSE;
	}
	StackNode *p = S->next;
	while(p != NULL){
		free(S);
		S = p;
		p = p->next;
	}

	return TRUE;
}

// 入栈
bool push(LinkList *S, ElemType x)
{
	StackNode *p = (StackNode *) malloc(sizeof(StackNode));		// 创建一个新的节点p并且动态分配物理空间
	if(p == NULL)
		return FALSE;		// 创建失败
	p->data = x;			// 给p节点的data域赋值
	p->next = (*S)->next;		// 使得p节点的后一个节点指向S节点的后一个节点
	(*S)->next = p;		// S->next指向p节点, 至此就形成了S - p - NULL(其他节点)
	
	return TRUE;
}

// 出栈, 要出栈的节点就相当于使头节点的后面一个节点
bool pop(LinkList *S, ElemType *e)
{
	if((*S)->next == NULL){
		return FALSE;
	}
	StackNode *p = (*S)->next;		// 声明一个新的节点指向S->next
	(*S)->next = p->next;		// S->next = p->next = S->next->next, 也就是S->next指向S的下下个节点
	*e = p->data;		// 传出出战节点的值
	free(p);

	return FALSE;
}

