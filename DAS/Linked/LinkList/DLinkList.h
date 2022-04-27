#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__
#include "../../Lib/DAS.h"


bool DLNode_Init(DLinkList *L);
bool DLNode_Creat_Head(DLinkList *L);
void DLNode_Show(DLinkList L);
void DLNode_Show_Reverse(DLinkList L);
bool DLNode_Creat_Tail(DLinkList *L);
bool DLNode_Elem_Insert(DLinkList *L, int location, ElemType num);
bool DLNode_Elem_Delet(DLinkList *L, int location, ElemType *num);
bool DLNode_Elem_Modify(DLinkList *L, int location, ElemType num);
ElemType DLNode_Elem_Find(DLinkList L, int location);

#endif