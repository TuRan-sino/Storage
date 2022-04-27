#include "../../Lib/DAS.h"

int SqList_Init(SqList *L);
int SqList_Creat(SqList *L);
void SqList_Show(SqList L);
int SqList_Increase(SqList *L);
int SqList_Insert_Elem(SqList *L, int location, ElemType data);
int SqList_Delet_ELem(SqList *L, int location, ElemType *data);
int SqList_Destory(SqList *L);
int SqList_Modify_Elem(SqList *L, int location, ElemType data);
int SqList_Find_Elem(SqList *L, int location, ElemType *data);