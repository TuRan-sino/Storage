#include "../../Lib/DataStructure.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool List_Init(SqList *L);
bool List_Creat(SqList *L);
void List_Show(SqList L);
bool List_Increase(SqList *L);
bool List_Insert(SqList *L, int location, ElemType data);