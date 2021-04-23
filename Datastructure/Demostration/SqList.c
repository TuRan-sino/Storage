/*
	线性表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "D:\Project\C\Lib\lib_c.h"

#define INITSIZE 20
#define INCREMENT_SIZE 10



typedef int Elemtype;
typedef struct{
	int *data;
	int Maxsize;
	int length;
}Sqlist;

bool InitList(Sqlist *L);
bool IncreaseSize(Sqlist *, int );
bool ListInsert(Sqlist *, int , int );
bool ListDelet(Sqlist *, int ,int *);
void ShowList(Sqlist );
int LocateElem(Sqlist , int);
int Getelem(Sqlist , int );
bool CreatList(Sqlist *L);
bool DestroyList(Sqlist *L);
bool InsertElem(Sqlist *L, int i, Elemtype e);
int main(int argc, char const *argv[])
{
	Sqlist L;


	InitList(&L);

	int i = 0; int j = 0;
	int_gets(&j);
	while(j != -9999){
		InsertElem(&L, i + 1, j);
		int_gets(&j);
		i ++;
	}



	InsertElem(&L, 3, 3);


	ShowList(L);

	return 0;
}

bool InitList(Sqlist *L)
{
	(*L).data = (int *) malloc(sizeof(int) * INITSIZE);
	if(!L->data){
		return FALSE;
	}
	(*L).length = 0;
	(*L).Maxsize = INITSIZE;

	return TRUE;;
}


bool IncreaseSize(Sqlist *L, int len)
{
	int i = 0;
	int *p = (*L).data;
	(*L).data = (int *) malloc(sizeof(int) * (INITSIZE + len));	//注意,这里是直接你妈的新创建了一个数据空间!!!
	for(i = 0; i < ((*L).Maxsize + len); i ++){
		(*L).data[i] = 0;
	}
	for(i = 0; i < L->Maxsize; i ++){							//这个for函数把原来数据空间的值转移到了新的数据空间
		(*L).data[i] = p[i];
	}

	(*L).Maxsize = (*L).Maxsize + len;

	free(p);													//释放原来内存


	return TRUE;;
}



bool ListInsert(Sqlist *L, int i, int e)
{
	if(i < 1 || i > (*L).length){
		return FALSE;
	}else if((*L).length > (*L).Maxsize){
		return FALSE;
	}

	for(int j = (*L).length; j >= i - 1; j --){
		(*L).data[j + 1] = (*L).data[j];
	}
	(*L).data[i - 1] = e;
	(*L).length ++;


	return TRUE;;
}

bool ListDelet(Sqlist *L, int i, int *e)
{
	if(i < 1 || i > (*L).length){
		return FALSE;
	}else if((*L).length < 1){
		return FALSE;
	}
	*e = (*L).data[i - 1];
	for(int j = i; j < (*L).length; j ++){
		(*L).data[j - 1] = (*L).data[j];
	}

	(*L).length --;
	


	return TRUE;;
}

void ShowList(Sqlist L)
{
	int i;
	for(i = 0; i < L.length; i ++){
		printf("%d ", L.data[i]);
	}

	putchar('\n');
}

int Getelem(Sqlist L, int i)
{
	if(i < 1 || i > L.length){
		return -1;
	}

	return L.data[i - 1];
}


int LocateElem(Sqlist L, int i)
{
	for(int j = 0; j < L.length; j ++){
		if(i == L.data[j]){
			return j + 1;
		}
	}


	return -1;
}



bool CreatList(Sqlist *L)
{
	int i = 0, num;
	int increasenum = 5;
	int_gets(&num);
	while(num != -9999){
		if(L->length + 1> L->Maxsize){
			IncreaseSize(L, increasenum);
		}
		L->data[i] = num;
		i ++;
		L->length ++;
		int_gets(&num);
	}

	return TRUE;

}

bool DestroyList(Sqlist *L)
{
	free(L->data);
	L->length = 0;
	L->Maxsize = 0;
	return TRUE;
}


bool InsertElem(Sqlist *L, int i, Elemtype e)			//这里面的 i 实际上表示的是位序,而不是数组下标
{
	Elemtype *new;
	if (i < 1 || i > L->length + 1){
		return FALSE;
	}
	if (L->length >= L->Maxsize){
		new = (Elemtype*) realloc(L->data, (L->Maxsize + INCREMENT_SIZE) * sizeof(Elemtype));
		if (!new){
			return FALSE;
		}
		L->data = new;
		L->Maxsize += INCREMENT_SIZE;
	}
	Elemtype *p = &L->data[i - 1];
	Elemtype *q = &L->data[L->length - 1];
	for (; q >= p; q--){
		*(q + 1) = *q;
	}
	*p = e;
	L->length ++;
	return TRUE;
}

