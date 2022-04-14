#include "../../Lib/DataStructure.h"

int SqList_Init(SqList *L);
int SqList_Creat(SqList *L);
void SqList_Show(SqList L);
int SqList_Increase(SqList *L);
int SqList_InsertElem(SqList *L, int location, ElemType data);
int SqList_DeletELem(SqList *L, int location, ElemType *data);
int SqList_Destory(SqList *L);
int SqList_ChangeElem(SqList *L, int location, ElemType data);
int SqList_FindElem(SqList *L, int location, ElemType *data);