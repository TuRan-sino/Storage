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

BiTNode* InsertRightNode(BiTNode *t);
BiTNode* InsertLeftNode(BiTNode *t);
bool InsertNode(BiTree *root);
bool InitTree(BiTree *root);

int main(int argc, char const *argv[])
{
	BiTree root = NULL;
	InitTree(&root);
	InsertNode(&root);
	
	return 0;
}

// 初始化树
bool InitTree(BiTree *root)
{
	(*root) = (BiTree)malloc(sizeof(BiTNode));
	(*root)->data = 1;
	// 1并没有什么具体作用
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;

}

bool InsertNode(BiTree *root) 
{
	// 定义了一个节点， 
	BiTNode *t = (*root);
	printf("Please select your choice\n");
	printf("a. leftchild	b. rightchild	c. exit\n");
	char choose;
	scanf("%c", &choose);
	while(choose != 'c'){
		if(choose == 'a'){
			// 添加一个左节点
			t = InsertLeftNode(t);
			(*root)->data ++;
		}else if(choose == 'b'){
			// 添加一个右节点
			t = InsertRightNode(t);
			(*root)->data ++;
		}
		printf("Please select your choice\n");
		printf("a. leftchild	b. rightchild	c. exit\n");
		scanf("%d", &choose);
	}

}

BiTNode* InsertLeftNode(BiTNode *t)
{
	BiTNode *p;
	printf("Please enter your number\n");
	int temp;
	scanf("%d", &temp);
	p = (BiTree)malloc(sizeof(BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	p->data = temp;
	t->lchild = p; 
	// 将t（自定义节点）节点的左指针指向新节点

	return p;
}

BiTNode* InsertRightNode(BiTNode *t)
{
	BiTNode *p;
	printf("Please enter your number\n");
	int temp;
	scanf("%d", &temp);
	p = (BiTree)malloc(sizeof(BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	p->data = temp;
	t->rchild = p;
	// 将t（自定义节点）的右指针指向新节点

	}