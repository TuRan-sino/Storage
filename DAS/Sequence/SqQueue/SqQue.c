/****************************************************************************************************
@author: TuRan
@des: 	顺序队列相关代码
		Sequence queue code
****************************************************************************************************/
#include "SqQue.h"

int main(int argc, char *argv[])
{
	
}


/**
 * @brief	顺序队列初始化函数
 * @param	Q [SqQue *] 需要初始化的顺序队列
 * @retval	bool
*/
bool SqQue_Init(SqQue *Q)
{
	(*Q).data = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);
	if(!Q) return FALSE;
	Q->front = Q->rear = 0;

	return TRUE;
}