/* 
	二叉树示例代码
	本代码多次使用了 “递归” 这一技巧， 难度颇高

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

#define MAX_STACK 100

typedef char DataType;
typedef struct BiTNode{
	DataType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	int flag;
}BiTNode, *BiTree;

BiTree * InitTree();
void Traverse_PreOrder(BiTree root);
void Traverse_InOrder(BiTree root);
void Traverse_PostOrder(BiTree root);
void CreatTree_Preorder(BiTree *T);
void CreatTree_PostOrder(BiTree *T);
void CreatTree_Inorder(BiTree *T);

int main(int argc, char const *argv[])
{
	BiTree *T =  InitTree();
	CreatTree_Preorder(T);

	return 0;
}


// 初始化二叉树
BiTree * InitTree()
{
	BiTree *T = (BiTree*)malloc(sizeof(BiTree));
	// BiTree *T是一个二级指针， 同时malloc的返回值BiTree也是一个二级指针
	*T = NULL;

	return T;
	// 使用了函数指针， renturn回的是一个二级指针， 该二级指针指向的是实际指向树的一级指针。 
}

// 先序创建二叉树
// 使用递归的方法先序创建， 输入‘#’进入递归出口
void CreatTree_Preorder(BiTree *T)
{

	DataType data = 0;
	fflush(stdin);
	scanf("%c", &data);
	if(data == '#'){
		*T = NULL;
	}else{
		(*T) = (BiTNode *)malloc(sizeof(BiTNode));
		// 此时T就变了， T不再是BiTree类型的了， 而是BiTNode类型
		(*T)->data = data;
		// 输入data数据
		(*T)->flag = 0;
		CreatTree_Preorder(&((*T)->lchild));
		// 递归的对左孩子进行处理
		CreatTree_Preorder(&((*T)->rchild));
		// 左孩子递归完毕之后对有孩子进行处理
	}
}

// 中序创建二叉树
void CreatTree_Inorder(BiTree *T)
{
	DataType data = getchar();
	if(data == '#'){
		*T = NULL;
	}else{
		CreatTree_Inorder(&((*T)->lchild));
		(*T) = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = data;
		CreatTree_Inorder(&((*T)->rchild));
	}
}

// 后序创建二叉树
void CreatTree_PostOrder(BiTree *T)
{
	DataType data = getchar();
	if(data == '#'){
		*T = NULL;
	}else{
		CreatTree_PostOrder(&((*T)->lchild));
		CreatTree_PostOrder(&((*T)->rchild));
		(*T) = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = data;
	}

}

// 二叉树的先序遍历
void Traverse_PreOrder(BiTree root)
{
	if(root == NULL){
		return;
	}
	printf("%c", root->data);
	Traverse_PreOrder(root->lchild);
	Traverse_PreOrder(root->rchild);
}

// 二叉树的中序遍历
void Traverse_InOrder(BiTree root)
{
	if(root == NULL){
		return;
	}
	Traverse_InOrder(root->lchild);
	printf("%c", root->data);
	Traverse_InOrder(root->rchild);
}

// 二叉树的后序遍历
void Traverse_PostOrder(BiTree root)
{
	if(root == NULL){
		return;
	}
	Traverse_PostOrder(root->lchild);
	Traverse_PostOrder(root->rchild);
	printf("%c", root->data);
}