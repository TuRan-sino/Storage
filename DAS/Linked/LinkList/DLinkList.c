/****************************************************************************************************
@author: TuRan
@data: 
@des: 	双链表相关代码
		Dual linked list code
****************************************************************************************************/
#include "DLinkList.h"


int main(int argc, char *argv[])
{

}


/**
 * @brief	初始化双链表
 * @param	L [DuLinkList *]
 * @retval	bool
*/
bool DuLNode_Init(DuLinkList *L)
{
	(*L) = malloc(sizeof(DuLNode));
	if(!(*L)) return FALSE;

	(*L)->next = NULL;
	(*L)->data = 0;

	return TRUE;
}