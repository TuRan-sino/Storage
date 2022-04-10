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
	struct BiTNode *parent;
	// parent写出来单单只是为了方便自己构建树， 遍历的时候不做使用！
}BiTNode, *BiTree;

BiTNode* InsertRightNode(BiTNode *t);
BiTNode* InsertLeftNode(BiTNode *t);
bool CreatTree(BiTree *root);
bool InitTree(BiTree *root);

int main(int argc, char const *argv[])
{
	BiTree root = NULL;
	InitTree(&root);
	CreatTree(&root);
	
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

	return true;
}

bool CreatTree(BiTree *root) 
{
	// 定义了一个节点， 
	BiTNode *position = (*root);
	int level = 1;
	printf("Please enter your choice\n");
	printf("a. InsertLeftChild	b. InsertRightChild\n");
	printf("c. BackFather		d. ShowPosition\n");
	printf("e. GotoLeftChild	f. GotoRightChild\n");
	printf("g. insert		h. exit\n");
	char choose;
	scanf("%c", &choose);
	while(1){
		if(choose == 'a'){
			// 新建一个左节点
			position = InsertLeftNode(position);
			level ++;
		}else if(choose == 'b'){
			// 新建一个右节点
			position = InsertRightNode(position);
			level ++;
		}else if(choose == 'c'){	
			position = position->parent;
			level --;
		}else if(choose == 'd'){
			printf("Your level is %d\n", level);	
		}else if(choose == 'e'){
			position = position->lchild;
			level ++;
		}else if(choose == 'f'){
			position = position->rchild;
			level ++;
		}else if(choose == 'g'){
			printf("Please enter your number: \n");
			int temp = 0;
			fflush(stdin);
			scanf("%d", &temp);
			position->data = temp;
		}else if(choose == 'h'){
			return true;
		}
		printf("Please enter your choice\n");
		printf("a. InsertLeftChild	b. InsertRightChild\n");
		printf("c. BackFather		d. ShowPosition\n");
		printf("e. GotoLeftChild	f. GotoRightChild\n");
		printf("g. insert		h. exit\n");
		fflush(stdin);
		scanf("%c", &choose);
	}

	return true;
}

BiTNode* InsertLeftNode(BiTNode *t)
{
	// 生成一个新的节点p, 这个节点作为源节点的左节点
	BiTNode *p;
	int temp;
	printf("Please enter your number\n");
	fflush(stdin);
	scanf("%d", &temp);
	p = (BiTree)malloc(sizeof(BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = t;
	// 将目标节点节点的父节点指定为源节点
	p->data = temp;
	t->lchild = p; 
	// 将源节点节点的左指针指向目标节点

	return p;
}

BiTNode* InsertRightNode(BiTNode *t)
{
	BiTNode *p;
	printf("Please enter your number\n");
	int temp;
	fflush(stdin);
	scanf("%d", &temp);
	p = (BiTree)malloc(sizeof(BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent =t;
	p->data = temp;
	t->rchild = p;
	// 将源节点节点的左指针指向目标节点

	return p;
}

// bool ShowTree_T(BiTree root)
// {
	
// }