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
/*
	这里定义的LinkList是指针类型的LNode变量
	因此:	假设这里有一个 LinkList L,
			也就是LNode *L;
			换言之就是定义了一个指针L, 指向了链表的头节点
*/


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

	LinkList L;			// LNode *L
	InitList(&L);		// 给InitList传入的参数就是LinkList L 的地址. 相当于一个指针, 指针指向L
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
bool InitList(LinkList *L)
{	
	*L = (LinkList) malloc(sizeof(LNode));
	if(!L){
		return FALSE;							// 假设L不存在, 返回FALSE
	}
	(*L)->next = NULL;							// 初始化的时候设置头节点L的next域位NULL, tips: (*L)->next双重解引
	return TRUE;
}


// 销毁链表
bool DestoryList(LinkList L)
{
	LinkList temp;
	if(L == NULL){								// L == NULL 表示L是空表, 返回false, 不需要删除
		return FALSE;
	}
	while(L){
		temp = L->next;							// 设置一个新的LinkList指针变量temp, 使得temp指向L后面一个节点, 暂存头节点
		free(L);
		L = temp;								// 使得L指向之前暂存的L->next	
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
	LNode *s;				// 即将插入的节点
	(*L)->next = NULL;		// L为头节点, 使得L后面一个节点指向NULL
	int x;					// 即将插入的数
	scanf("%d", &x);
	while(x != -9999){
		s = (LNode *) malloc(sizeof(LNode));		// 给之前申明的S节点动态的赋予空间
		s->data = x;		
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &x);
	}

	return TRUE;
}


// 插入(基本), 在某一结点后插入一个新的节点, i从0开始的
bool InsertList_num_basic(LinkList L, int i, ElemType e)
{
	if(i < 1)		// i < 1 即代表: 在头节点前面插入节点, return FASLE
		return FALSE;
	LNode *p;
	int j = 0;		// 工作计数器, 通过j找到要找到的那个节点
	p = L;			// 工作LinkList指针, 通过p找到需要找到的那个节点
	while(p != NULL && j < i - 1){		// 这里j < i - 1. (j是从0考试的, i也是从0开始的)我们需要找到i节点前面一个节点才好插入
		p = p->next;
		j ++;
	}

	if(p == NULL){
		return FALSE;
	}

	LNode *s = (LinkList) malloc(sizeof(LNode));	// 给即将插入的那个节点malloc一个存储空间
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
	p = L->next
	int i = 0;
	while(p){		// 只要p存在, 就一直使p 指向 p->next
		i ++;
		p = p->next;		
	}
	
	return i;
}

// 尾插法创立链表
bool Creat_List_Tail(LinkList *L)
{
	int x; 				// x 用于接受键盘输入
	LNode *s, *r; 		// r指针始终指向链表的最后一个元素. s指针就是工作指针, 每次插进去的就是这个
	r = (*L);
	(*L)->next = NULL;
	scanf("%d", &x);
	while(x != -9999){
		s = (LNode *) malloc(sizeof(LNode));	//建立尾节点, 动态malloc s指针
		s->data = x;		// x为该节点的值, 附到s指针的data域
		s->next = r->next;		// 新创建的指针的next域 指向 链表最后一个元素(r指针)的next域
		r->next = s;		// s节点插入之前的链表的最后一个元素(节点插入之后链表的倒数第二个元素)的next域指向 s节点
		r = s;		// 所有步骤进行完毕, 使得r指针指向s指针.
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