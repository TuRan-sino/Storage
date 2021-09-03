/*
	线性表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../C/Lib/lib_c.h"

#define INITSIZE 20
#define INCREMENT_SIZE 10



typedef int ElemType;
typedef struct{
	int *data;				
	int Maxsize;			//最大长度
	int length;				//已占用长度, 从1开始计数
}SqList;

bool InitList(SqList *L);
bool IncreaseSize(SqList *, int );
bool ListInsert(SqList *, int , int );
bool ListDelet(SqList *, int ,int *);
void ShowList(SqList );
int LocateElem(SqList , int);
int Getelem(SqList , int );
bool CreatList(SqList *L);
bool ChangeList(SqList *L);
bool DestroyList(SqList *L);
bool Delet_Elem_similar_x(SqList *L, int x);
bool InsertElem(SqList *L, int i, ElemType e);
bool Delet_Elem_between_j_and_i_ordered(SqList *L, int start, int end);
bool Delet_Elem_between_j_and_i_Unordered(SqList *L, int start,int end);
bool Delet_repetitive_Elem(SqList *L);
bool Link_Sqlist(SqList A, SqList B, SqList *C);
bool Insert_or_change_elem_between_i_and_j(SqList *L, int x);
bool Insert_or_change_elem_between_i_and_j_pro(SqList *L, int x);
bool test_10(SqList *L, int p);
bool test_11_basic(SqList *N, SqList *M);  
int test_12_basic(SqList L);
int test_13_basic(SqList L);

int main(int argc, char const *argv[])
{
	SqList L;
	InitList(&L);

	int i = 0, j = 0;
	int_gets(&j);
	while(j != -9999){
		InsertElem(&L, i + 1, j);
		int_gets(&j);
		i ++;
	}


	puts(STAR);
	ShowList(L);


	int number = test_13_basic(L);

	printf("%d\n", number);

	printf("%d;\n", L.length);


	return 0;
}

bool InitList(SqList *L)
{
	(*L).data = (int *) malloc(sizeof(int) * INITSIZE);
	if(!L->data){
		return FALSE;
	}
	(*L).length = 0;
	(*L).Maxsize = INITSIZE;

	return TRUE;
}


bool IncreaseSize(SqList *L, int len)
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



bool ListInsert(SqList *L, int i, int e)
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

bool ListDelet(SqList *L, int i, int *e)
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

void ShowList(SqList L)
{
	int i;
	for(i = 0; i < L.length; i ++){
		printf("%d ", L.data[i]);
	}

	putchar('\n');
}

int Getelem(SqList L, int i)
{
	if(i < 1 || i > L.length){
		return -1;
	}

	return L.data[i - 1];
}


int LocateElem(SqList L, int i)
{
	for(int j = 0; j < L.length; j ++){
		if(i == L.data[j]){
			return j + 1;
		}
	}


	return -1;
}



bool CreatList(SqList *L)
{
	int i = 0, num;
	int increasenum = 5;
	int_gets(&num);
	while(num != -9999){
		if(L->length + 1 > L->Maxsize){
			IncreaseSize(L, increasenum);
		}
		L->data[i] = num;
		i ++;
		L->length ++;
		int_gets(&num);
	}

	return TRUE;

}

bool DestroyList(SqList *L)
{
	free(L->data);
	L->length = 0;
	L->Maxsize = 0;
	return TRUE;
}


bool InsertElem(SqList *L, int i, ElemType e)			//这里面的 i 实际上表示的是位序,而不是数组下标
{
	ElemType *new;
	if (i < 1 || i > L->length + 1){
		return FALSE;
	}
	if (L->length >= L->Maxsize){
		new = (ElemType*) realloc(L->data, (L->Maxsize + INCREMENT_SIZE) * sizeof(ElemType));
		if (!new){
			return FALSE;
		}
		L->data = new;
		L->Maxsize += INCREMENT_SIZE;
	}
	ElemType *p = &L->data[i - 1];
	ElemType *q = &L->data[L->length - 1];
	for (; q >= p; q--){
		*(q + 1) = *q;
	}
	*p = e;
	L->length ++;
	return TRUE;
}







/*删除线性表中所有值为x的元素*/
bool Delet_Elem_similar_x(SqList *L, int x)
{
	int k = 0;
	for(int i = 0; i < L->length; i ++){
		if(L->data[i] != x){
			L->data[k] = L->data[i];
			k ++;
		}
	}
	L->length = k;

	return TRUE;
}


/*
逆置所有元素
*/
bool ChangeList(SqList *L)
{
	int i = L->length;
	int j;
	int temp;
	if(i % 2 == 0){
		j = 0;
		while(j < i / 2){
			temp = L->data[j];
			L->data[j] = L->data[i - 1 - j];
			L->data[i - 1 - j] = temp;
			j ++;
		}
	}else if(i % 2 != 0){
		j = 0;
		while(j < i / 2){
			temp = L->data[j];
			L->data[j] = L->data[i - 1 - j];
			L->data[i - 1 - j] = temp;
			j ++;
		}
	}
	return TRUE;
}

/*
删除有序顺序表在给定值 i 和 j 之间的元素
*/
bool Delet_Elem_between_j_and_i_ordered(SqList *L, int start, int end)
{
	int i, j;
	for(i = 0; L->data[i] < start; i ++);
	if(i > L->length && start < end){
		printf("the number of i is too big\n");
		return FALSE;
	}
	for(j = i; L->data[j] <= end; j ++);
	for(; j < L->length; j ++, i ++){
		L->data[i] = L->data[j];
	}
	L->length = L->length - (end - start + 1);
	return TRUE;
}


/*
删除顺序表在给定值 i 和 j 之间的元素
*/
bool Delet_Elem_between_j_and_i_Unordered(SqList *L, int start, int end)
{
	int i = 0, j;
	if(start > L->length || start > end){
		return FALSE;
	}
	while(L->data[i] < start || L->data[i] > end)
		i ++;
	j = i + 1;
	while(j < L->length){
		if(L->data[j] < start || L->data[j] > end){
			L->data[i] = L->data[j];
			j ++;
			i ++;
		}
		j ++;
	}
	L->length = i;

	return TRUE;
}

/*
删除有序顺序表中所有重复的元素
*/
bool Delet_repetitive_Elem(SqList *L)
{
	int i = 0, j = 0;
	while(j < L->length){
		if(L->data[i] == L->data[j]){
			j ++;
		}else{
			i ++;
			L->data[i] = L->data[j];
		}
	}

	L->length = i + 1;


	return TRUE;
}

/*
将两个有序顺序表合并为一个有序的顺序表
*/
bool Link_Sqlist(SqList A, SqList B, SqList *C)
{
	if(A.length + B.length > C->Maxsize)
		return FALSE;
	int i = 0, j = 0, k = 0;
	while(i < A.length && j < B.length){
		if(A.data[i] <= B.data[j])
			C->data[k ++] = A.data[i ++];
		else
			C->data[k ++] = B.data[j ++];
	}
	while(i < A.length){
		C->data[k ++] = A.data[i ++];
	}
	while(j < B.length){
		C->data[k ++] = B.data[j ++];
	}
	C->length = k;
	return TRUE;
}

/*
在表中查找数值为 x 的元素,若找到则与后继元素交换
若没找到,则插入表中使得表任然有序
*/
bool Insert_or_change_elem_between_i_and_j(SqList *L, int x)
{
	int i = 1;
	while(i <= L->length){
		if(x > L->data[i - 1] && x < L->data[i + 1]){
			if(x == L->data[i]){
				int temp;
				temp = L->data[i];
				L->data[i] = L->data[i + 1];
				L->data[i + 1] = temp;
			}else{
				if(L->data[i] > x){
					ListInsert(L, i + 1, x);
				}else if(L->data[i] < x){
					ListInsert(L, i + 2, x);
				}
			}
			break;
		}
	i ++;
	}
	return TRUE;
}

bool Insert_or_change_elem_between_i_and_j_pro(SqList *L, int x){
	int low = 0, high = L->length - 1, mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(L->data[mid] == x) break;
		else if(L->data[mid] < x)
			low = mid + 1;
		else
			high =mid - 1;
	}
	if(L->data
		[mid] == x && mid != L->length - 1){
		int temp;
		temp = L->data[mid];
		L->data[mid] = L->data[mid + 1];
		L->data[mid + 1] = temp;
	}
	if(low > high){
		int i;
		for( i = L->length - 1; i > high; i --);
		L->data[i + 1] = x;
	}

	return TRUE;
}


/*
左移循环数组 p 位
*/
bool test_10(SqList *L, int p)
{
	int i;
	int mid_front = (p - 1 + 0) / 2;
	for(i = 0; i <= mid_front; i ++){
		int temp;
		temp = L->data[i];
		L->data[i] = L->data[p - 1 - i];
		L->data[p - 1 - i] = temp;
	}
	int mid_behind = (L->length - 1 - p) / 2;
	for(i = 0; i <= mid_behind; i ++){
		int temp;
		temp = L->data[p + i];
		L->data[p + i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 - i] = temp;
	}
	int mid = (L->length - 1) / 2;
	for(i = 0; i <= mid; i ++){
		int temp;
		temp = L->data[i];
		L->data[i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 - i] = temp;
	}

	return TRUE;
}


/*
	找出两个顺序序列合并之后的中位数
*/
bool test_11_basic(SqList *N, SqList *M)
{
	int length_N = N->length;
	int length_M = M->length;
	int temp;
	int length = length_N + length_M;
	int n = 0, m = 0;
	for(int i = 0; i <= length / 2 - 1; i ++){
		if(N->data[n] < M->data[m]){
			temp = N->data[n];
			n ++;
		}else if(M->data[m] < N->data[n]){
			temp = M->data[m];
			m ++;
		}else if(N->data[n] == M->data[m]){
			temp = N->data[n];
			n ++;
		}
	}
	printf("%d\n", temp);


	return TRUE;
}


/*
	找到一个线性表里面的主元素,并输出,如果没有主元素那么输出-1
*/
int test_12_basic(SqList L)
{
	int temp = 0;
	int count = 0;
	int number = 0;
	for(int i = 0; i < L.length; i ++){
		if(L.data[i] > temp){
			temp = L.data[i];
		}
	}
	int array[temp];
	for(int i = 0; i < temp; i ++){
		array[i] = 0;
	}
	for(int i = 0; i < L.length; i ++){
		array[L.data[i]] ++;
	}
	for(int i = 0; i < temp; i ++){
		if(array[i] > count){
			count = array[i];
			number = i;
		}
	}


	if(count > L.length / 2)
		return number;
	else 
		return -1;
}


/*
	找到一个数组之中未出现的最小整数
*/
int test_13_basic(SqList L)
{
	int number;
	int temp = 0;
	for(int i = 0; i < L.length; i ++){
		if(L.data[i] > temp)
			temp = L.data[i];
	}
	temp += 1;
	int array[2][temp];					 				//声明二维数组 array 其中第一个参数 0 即是正数, 1 既是负数
	for(int i = 0; i < temp; i ++){						//初始化 array 数组
			array[0][i] = 0;
	}
	for(int i = 0; i < L.length; i ++){					//遍历 L.data 数组并且使得对应的在 array 上面的映射加一
		if(L.data[i] > 0){
			array[0][L.data[i]] ++;
		}else if(L.data[i] < 0){
			L.data[i] = - L.data[i];
			array[1][L.data[i]] ++;
		}
	}
	int i = 0;
	for(i = 1; i < temp; i ++){							//找出改元素对应的数组下标
		if(array[0][i] == 0){
			number = i;
			break;
		}
	}

	if(array[0][i - 1] != 0)
		return i;
	if(array[0][i - 1] == 0)
		return number;


	return -1;
}


