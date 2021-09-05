/*
	静态链表 Static Node
	工作原理:
		分配一整片的数据空间, 各个数据元素存放在该静态链表的某一个位置
		每一个小的数据空间分割成两个部分, 一个data域一个游标域, 该游标指向下一个节点的存储位置
			头结点的游标为0, 尾节点游标为-1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20

typedef int ElemType;
typedef struct SNode{
	ElemType data;	// 数据元素
	int next;		// 下一个元素的数组下标(游标)
}SNode, SLinkList[MaxSize];

bool InitSNode(SLinkList *L);

int main(int argc, char const *argv[])
{
	SLinkList L;

	InitSNode(&L);


	return 0;
}

// 初始化
bool InitSNode(SLinkList *L)
{
	for(int i = 0; i < MaxSize; i ++){
		L[i]->data = -9999;				// 将脏数据设置为-9999
		if(i == MaxSize - 1){
			L[i]->next = -9999				// 最后一个节点的next域设置为-9999
		}else
			L[i]->next = L[i + 1];			// 初始化的时候将所有结点的的next域放置在该节点的下一个部分

	}

	return TRUE;
}

bool InsertSNode(SLinkList *L)
{		
	int i = 0
	for(i = 0; i < MaxSize; i ++){		// 找到第一个未被使用过的数据域
		if(L[i] != -9999){
			break;
		}
	}									

	int j = 0;
	while(L[j]->next != -9999){			// 顺序寻找找到最后一个使用过的数据域
		
	}
}

bool Traverse(SLinkList L)
{

}