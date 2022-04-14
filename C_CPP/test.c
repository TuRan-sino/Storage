#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList *L);

int main()
{
}

bool InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if(!*L)
		return FALSE;	
	(*L)->next = NULL;
	return TRUE;
}
