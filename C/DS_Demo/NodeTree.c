/* 
# 名词解释
BiTNode: binary Tree Node
BiTree: binary Tree
lchild: left child
rchild: right child

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
	// struct BiTNode *parent;
}BiTNode, *BiTree;


int main(int argc, char const *argv[])
{
	BiTree root = NULL;
	
	return 0;
}

// 初始化树
bool InitTree(BiTree *root)
{
	root = (BiTree)malloc(sizeof(BiTNode));
	(*root)->data = 1;
	// 1并没有什么具体作用
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;

}

bool InsertLeftNode(BiTree *root)
{
	BiTNode *p;
	p = (BiTree)malloc(sizeof(BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	(*root)->lchild = p;
	// 将root节点的左指针指向新节点

}