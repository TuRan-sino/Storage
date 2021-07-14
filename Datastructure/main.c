#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITSIZE 10
#define TRUE 1
#define FALSE 0
#define increasenum 10

typedef	struct{
	int *data;
	int length;				
	int Maxsize;
}SqList;



void ShowList(SqList L);
bool IncreaseSize(SqList *L, int len);
bool CreatList(SqList *L);
bool InitList(SqList *L);
int main(int argc, char const *argv[])
{
	SqList L;

	InitList(&L);
	CreatList(&L);
	ShowList(L);

	return 0;
}

bool InitList(SqList *L)
{
	L->data = (int *) malloc(sizeof(int) * INITSIZE);
	if(!L->data){
		return FALSE;
	}

	L->length = 0;
	L->Maxsize = INITSIZE;



	return TRUE;
}

bool IncreaseSize(SqList *L, int len)
{
	// int i = 0;
	int *p = L->data;

	L->data = (int *) malloc(sizeof(int) * (INITSIZE + len));
	for(int i = 0; i < INITSIZE + len; i ++){
		L->data[i] = 0;
	}
	for(int i = 0; i < L->Maxsize; i ++){
		L->data[i] = p[i];
	}

	free(p);


	return TRUE;
}


bool CreatList(SqList *L)
{
	int i = 0;
	int num = 0;
	scanf("%d", &num);
	while(num != -9999){
		if(L->length + 1 > L->Maxsize){
			IncreaseSize(L, increasenum);
		}

		L->data[i] = num;
		i ++;
		L->length ++;
		scanf("%d", &num);
	}

	return TRUE;
}


void ShowList(SqList L)
{
	int i = 0;
	for(i = 0; i < L.length; i ++){
		printf("%d\n", L.data[i]);		
	}
	printf("\n");
}