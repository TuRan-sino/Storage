#include "../../Lib/DataStructure.h"
#include <stdio.h>
#include <stdlib.h>

int List_Init(SqList *L);
int List_Creat(SqList *L);
void List_Show(SqList L);
int List_Increase(SqList *L);
int List_InsertElem(SqList *L, int location, ElemType data);
int List_DeletELem(SqList *L, int location, ElemType *data);
int List_Destory(SqList *L);
int List_ChangeElem(SqList *L, int location, ElemType data);
int List_FindElem(SqList *L, int location, ElemType *data);