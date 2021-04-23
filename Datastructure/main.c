/*
	单链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "D:\Project\C\Lib\lib_c.h"
#include <limits.h>


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
int Get_Elem(LinkList L, int i);
bool Delet_Elem(LinkList L, int i, ElemType *e);
bool Delet_Elem_x_2(LinkList L, int x);
bool Delet_min(LinkList L);
bool Reverse_List_1(LinkList L);
bool Sort_Sequence(LinkList L);
bool Delet_Elem_between(LinkList L, int n, int m);
bool Find_Elem_Public(LinkList M, LinkList N, LNode *result);
void Reverse_PrintAndDelet(LinkList L);


int main(int argc, char const *argv[])
{

	LinkList L;
	InitList(&L);

	
	
	Creat_List_Tail(&L);

	// LinkList M,N;
	// InitList(&M);
	// InitList(&N);

	// printf("Please Enter you LNode\n");
	// Creat_List_Tail(&M);
	// printf("Enter your another LNode\n");
	// Creat_List_Tail(&N);


	// ShowList(M);
	// ShowList(N);


	Reverse_PrintAndDelet(L);








	return 0;
}


bool InitList(LinkList *L)						 //为什么 InitList 需要调用*，但是 CreatList_hand 不需要*？
{												//CreatList_hand 返回值就是 LinkList 类型
	*L = (LinkList) malloc(sizeof(LNode));
	if(!L){
		return FALSE;
	}
	(*L)->next = NULL;
	return TRUE;
}

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

void ShowList(LinkList L)
{
	LinkList p = L->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;		
	}
}



bool Creat_List_Head(LinkList *L)
{
	LNode *s;
	*L = (LinkList) malloc(sizeof(LNode));
	if((*L) == NULL){
		return NULL;
	}
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


bool Creat_List_Tail(LinkList *L)
{
	int x; 				// x 用于接受键盘输入
	LNode *s, *r;
	(*L) = (LinkList) malloc(sizeof(LNode));	//建立头节点
	if(*L == NULL)
		return FALSE;
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

int Get_Elem(LinkList L, int i)
{
	int j = 0;
	LinkList p;
	p = L;
	while(j < i){
		p = p->next;
		j ++;
	}
	
	return p->data;
}

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
/*
	2.在带头结点的单链表 L 中,删除所有值为 x 的节点, 并且释放其空间.
	**************************
	本函数解法:	使用一个指针 p 和另一个指针 pre ;
				p 依次往后指, 假设当前 p 节点 data 域为 x ,那么 ....
				假设当前 p 节点 data 域不是 x 那么 .....
*/
bool Delet_Elem_x_1(LinkList L, int x)
{
	LNode *p = L->next;
	LNode *pre = L;
	while(p != NULL){
		if(p->data == x){
			pre->next = p->next;
			free(p);
			p = pre->next;
		}else{
			p = p->next;
			pre = pre->next;
		}
	}

	return TRUE;
}
/*
	2.在带头结点的单链表 L 中,删除所有值为 x 的节点, 并且释放其空间.
	**************************
	解法2: 利用尾插法的性质, 依次扫描所有的节点,假设某一结点值 " 不为 " x, 那么将该节点移动到 L 节点之后
*/
bool Delet_Elem_x_2(LinkList L, int x)
{
	LNode *p = L->next, *r = L;
	LNode *temp;
	while(p != NULL){
		if(p->data != x){
			r->next = p;
			r = p;	
			p = p->next;
		}else if(p->data == x){
			temp = p;
			p = p->next;
			free(temp);
		}
	}

	r->next = NULL;

	return TRUE;
}
/*
	4.设 L 为带头结点的单链表,删除单链表最小值节点
*/
bool Delet_min(LinkList L)
{
	int min = 9999; 
	LNode *p = L->next, *p_pre = L;
	LNode *number, *number_pre;
	while(p != NULL){
		if(p->data < min){
			min = p->data;
			number = p;
			number_pre = p_pre;
		}
		p = p->next;
		p_pre = p_pre->next;
	}
	number_pre->next = number->next;
	free(number);
	return TRUE;
}
/*
	5.编写算法将带头结点的单链表逆置,空间复杂度为 0(1)
	解法一
*/
bool Reverse_List_1(LinkList L)
{
	// LinkList RL;
	LNode *p = L->next, *temp;
	L->next = NULL;
	while(p != NULL){
		temp = p->next;
		p->next = L->next;
		L->next = p;
		p = temp;
	}

	return TRUE;
}
/*
	5.编写算法将带头结点的单链表逆置,空间复杂度为 0(1)
	解法二
*/
bool Reverse_List_2(LinkList L)
{
	LNode *pre, *p = L->next, *r = p->next;
	p->next = NULL;
	while(r != NULL){
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	L->next = p;
	p->next = pre;

	return TRUE;
}
/*
	6.设计一个算法,使得带有头结点的单链表 L 元素有序递增
*/
bool Sort_Sequence(LinkList L)
{
	LNode *p = L->next, *r = p->next;
	LNode *pre;
	p->next = NULL;
	p = r;
	while(p != NULL){
		r = p->next;
		pre = L;
		while(pre->next != NULL && pre->next->data < p->data)		//注意判断边界条件
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}


	return TRUE;
}
/*
	7.在一个带头结点的单链表中删除所有介于给定两个值之间的节点
*/
bool Delet_Elem_between(LinkList L, int n, int m)
{
	LNode *p = L->next, *pre = L;
	LNode *temp;
	while(p != NULL){
		if(p->data <= m && p->data >= n){
			temp = p;
			pre->next = p->next;
			p = p->next;
			free(temp);
		}else{
			p = p->next;
			pre = pre->next;
		}
	}

	return TRUE;
}
/*
	8.给定两个链表,找到两个链表之间的公共节点
*/
bool Find_Elem_Public(LinkList M, LinkList N, LNode *result)
{
	int len_M = 0, len_N = 0;
	int k = 0;
	LNode *m = M->next, *n = N->next;
	for( ; m != NULL; m = m->next)
		len_M ++;
	for( ; n != NULL; n = n->next)
		len_N ++;

	m = M->next;
	n = N->next;

	if(len_M > len_N)
		k = len_M - len_N;
	else if(len_N > len_M)
		k = len_N - len_M;
	if(len_M > len_N){
		for(int i = 0; i < k; i ++){
			m = m->next;
		}
		while(m != NULL && n != NULL){
			if(m->next == n->next){
				result = m->next;
				break;
			}
			m = m->next;
			n = n->next;
		}
		return TRUE;
	}
	if(len_N > len_M){
		for(int i = 0; i < k; i ++)
			n = n->next;
		while(m != NULL && n != NULL){
			if(m->next == n->next){
				result = n->next;
				break;
			}
			m = m->next;
			n = n->next;
		}
		return TRUE;
	}
	if(len_N == len_M){
		while(m != NULL && n != NULL){
			if(m->next == n->next){
				result = m->next;
				break;
			}
			m = m->next;
			n = n->next;
		}
		return TRUE;
	}

	return TRUE;
}
/*
	9.按照逆增次序输出单链表中个结点的数据元素,并且释放节点所占的存储空间
*/
void Reverse_PrintAndDelet(LinkList L)
{
	LNode *p = L->next, *pre = L;
	LNode *temp, *temp_pre;
	int length;
	for(length = 0; p != NULL; length ++, p = p->next);
	for(int i = 0; i < length; i ++){
		p = L->next;
		int min = 9999;
		while(p != NULL){
			if(p->data < min){
				min = p->data;
				temp = p;
				temp_pre = pre;
			}
			p = p->next;
			pre = pre->next;
		}
		temp_pre->next = temp->next;
		printf("%d\n", temp->data);
		free(temp);
	}
}
