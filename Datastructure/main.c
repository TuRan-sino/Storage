#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;


bool InitList(LinkList *L);
bool Creat_List_Head(LinkList *L);
bool ShowList(LinkList L);
bool Creat_List_Tail(LinkList *L);

int main(int argc, char const *argv[])
{
	LinkList L;

	InitList(&L);


	Creat_List_Tail(&L);


	ShowList(L);








	return 0;
}


bool InitList(LinkList *L)
{
	*L = (LinkList) malloc(sizeof(LNode));
	if(!L){
		return FALSE;
	}
	(*L)->next = NULL;

	return TRUE;
}

bool Creat_List_Head(LinkList *L)
{
	LNode *s;
	(*L)->next = NULL;
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		s = (LinkList) malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &x);
	}


	return TRUE;

}

bool Creat_List_Tail(LinkList *L)
{
	LNode *temp;
	LNode *s;
	(*L)->next = NULL;
	temp = *L;
	int x = 0;
	scanf("%d", &x);
	while(x != -9999){
		s = (LinkList) malloc(sizeof(LNode));
		s->data = x;
		s->next = temp->next;
		temp->next = s;
		temp = s;
		scanf("%d", &x);
	}

	return TRUE;
}

bool ShowList(LinkList L)
{
	int i = 1;
	LNode *p = L->next;

	while(L != NULL){
		printf("your %d num is %d\n", i, p->data);
		p = p->next;
		i ++;
	}

	

	return TRUE;
}


