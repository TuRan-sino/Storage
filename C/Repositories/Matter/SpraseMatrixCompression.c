/*
	使用了经典的是十字链表法， 用来压缩稀疏矩阵。
	十字链表法有向右和向下两种方式， 本例中使用的是向右
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef struct LNode{
	int row;
	int colum;
	int value;
	struct LNode *next;
	struct LNode *down;
}Node, *LinkList;

int main(int argc, char const *argv[])
{
	
}

bool InitList(LinkList *L)
{
	*L = (LinkList) malloc(sizeof(LNode));
	if(!L){
		return FALSE;
	}
	(*L)->next = NULL;
}




