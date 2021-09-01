/*
	单链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "D:\Project\C\Lib\lib_c.h"


#define FALSE 0
#define TRUE 1




typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;


bool InitList(LinkList *L);
bool DestoryList(LinkList L);
void ShowList(LinkList L);
bool InsertList_num_basic(LinkList L, int i, ElemType e);
bool Creat_List_Head(LinkList *L);
int GetLength(LinkList L);
bool Creat_List_Tail(LinkList *L);
int GetElem(LinkList L, int i);
bool Delet_Elem(LinkList L, int i, ElemType *e);
bool InsertPriorNode(LNode *p, ElemType *e);
LNode * GetElem_Point(LinkList *L, int i);
LNode *LocateElem_Point(LinkList *L, ElemType e);


int main(int argc, char const *argv[])
{

	LinkList L;
	InitList(&L);
	printf("Plaese Enter your number\n");
	Creat_List_Tail(&L);


	ShowList(L);

	LNode *p = NULL;

	p = LocateElem_Point(&L, 3);

	printf("\nyour number is \n");
	printf("%d\n", p->data);
	

	return 0;
}

// 初始化
bool InitList(LinkList *L)						 //为什么 InitList 需要调用*，但是 CreatList_hand 不需要*？
{												//CreatList_hand 返回值就是 LinkList 类型
	*L = (LinkList) malloc(sizeof(LNode));
	if(!L){
		return FALSE;
	}
	(*L)->next = NULL;
	return TRUE;
}


// 销毁链表
bool DestoryList(LinkList L)
{
	LinkList temp;
	if(L == NULL){
		return FALSE;
	}
	while(L){
		temp = L->next;
		free(L);
		L = temp;
	}
	return TRUE;
}

// 遍历链表并打印
void ShowList(LinkList L)
{
	LinkList p = L->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;		
	}
}


// 头插法创立链表
bool Creat_List_Head(LinkList *L)
{
	LNode *s;
	(*L)->next = NULL;
	int x;
	scanf("%d", &x);
	while(x != -9999){
		s = (LNode *) malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &x);
	}

	return TRUE;
}


// 插入(基本), 在某一结点后插入一个新的节点
bool InsertList_num_basic(LinkList L, int i, ElemType e)
{
	if(i < 1)
		return FALSE;
	LNode *p;
	int j = 0;
	p = L;
	while(p != NULL && j < i - 1){
		p = p->next;
		j ++;
	}

	if(p == NULL){
		return FALSE;
	}

	LNode *s = (LinkList) malloc(sizeof(LNode));
	if(s == NULL){
		return FALSE;
	}

	s->next = p->next;
	p->next = s;
	s->data = e;

	return TRUE;
}

// 获取链表长度
int GetLength(LinkList L)
{
	LinkList p;
	p = L->next;			//为什么要设置 p = L->next ;而不是 p = L？
	int i = 0;				//因为 p = L->next 本身就是一个循环项了，i = 1！
	while(p){
		i ++;
		p = p->next;		
	}
	
	return i;
}

// 尾插法创立链表
bool Creat_List_Tail(LinkList *L)
{
	int x; 				// x 用于接受键盘输入
	LNode *s, *r;
	r = (*L);
	(*L)->next = NULL;
	scanf("%d", &x);
	while(x != -9999){
		s = (LNode *) malloc(sizeof(LNode));	//建立尾节点
		s->data = x;
		s->next = r->next;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	
	
	return TRUE;
}

// 按位查找的指针函数, 通过位序返回节点
LNode * GetElem_Point(LinkList *L, int i)
{
	if(i < 0)
		return NULL;
	LNode *p;	// p指针指向扫描的节点, 作为工作指针
	int j = 0;
	p = *L;
	while(p != NULL && j < i){
		p = p->next;
		j ++;
	}

	return p;
}



// 按位查找, 通过位序找到data, i表示第几个元素
int GetElem(LinkList L, int i)
{
	if(i < 0)
		return FALSE;
	int j = 0;
	LinkList p;
	p = L;
	while(j < i){
		p = p->next;
		j ++;
	}
	
	return p->data;
}


// 删除某一个位置的元素, i表示第几个元素
bool Delet_Elem(LinkList L, int i, ElemType *e)
{
	int j = 0;
	LNode *p;
	LNode *temp;
	p = L;
	while(j < i - 1){
		p = p->next;
		j ++;
	}
	*e = p->next->data;
	temp = p->next;
	p->next = p->next->next;
	free(temp);


	return TRUE;
}


// 在某一结点之前插入一个新的节点
bool InsertPriorNode(LNode *p, ElemType *e)
{
	/*
		具体解决方法, 
		节点p为你所需要插入的节点, elemtype e是你需要插入的数据
		找到节点p的p->next, 之后讲节点p的数据复制到p->next->data中
		之后讲elemtype e复制到节点p中	
	*/


	return TRUE;
}

// 按值查找, 通过数据找到值为e的节点并且返回
LNode *LocateElem_Point(LinkList *L, ElemType e)
{
	LNode *p = (*L)->next;
	while(p != NULL && p->data != e){
		p = p->next;
	}
	if(p == NULL)
		return NULL;

	return p;
}