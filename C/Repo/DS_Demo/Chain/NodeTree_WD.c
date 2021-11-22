#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void test()
{
	
}

int main(int argc, char const *argv[])
{
	BiTree root = NULL;	

	

	return 0;
}

bool InitTree(BiTNode *root)
{
	root = (BiTree)malloc(sizeof(BiTNode));
	if(root == NULL){
		return false;
	}
	root->data = 1;
	root->lchild = NULL;
	root->rchild = NULL;

	return true;
}

bool InsertLeftChild(BiTNode *root)
{
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = 2;
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;

	return true;
}

bool InsertRightChild(BiTNode *root)
{
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = 2;
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;

	return true;
}
