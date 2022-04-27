#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include "../../Lib/DAS.h"


bool LNode_Creat_Head(LinkList *L);
bool LNode_Init(LinkList *L);
void LNode_Show(LinkList L);
bool LNode_Creat_Tail(LinkList *L);
ElemType LNode_Find_Elem(LinkList L, int location);
bool LNode_Modify_Elem(LinkList L, int location, ElemType num);
bool LNode_Insert_Elem(LinkList *L, int locatoin, ElemType num);
bool LNode_Delet_Elem(LinkList *L, int location, ElemType *num);


#endif