#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__
#include "../../Lib/DAS.h"


bool DLNode_Init(DLinkList *L);
bool DLNode_Creat_Head(DLinkList *L);
void DLNode_Show(DLinkList L);
void DLNode_Show_Reverse(DLinkList L);
bool DLNode_Creat_Tail(DLinkList *L);

#endif