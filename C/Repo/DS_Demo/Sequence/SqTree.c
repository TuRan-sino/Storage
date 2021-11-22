/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXSIZE 100

typedef int ElemType;
// 节点的结构体
typedef struct TreeNode
{
	// 节点的数据域
	ElemType data;
	// 判断节点是否为空
	bool isempty;
}TreeNode;

bool ShowTree_Pro(TreeNode *t);
bool ShowTree(TreeNode *t);
bool CreatTree(TreeNode *t);
bool InitTree(TreeNode *t);

int main(int argc, char const *argv[])
{
	/*
	定义了一个长度为maxsize的数组t
	按照从上到下从左到右的顺序依次存储依次存储完全二叉树的各个节点
	*/
	TreeNode t[MAXSIZE];
	InitTree(t);
	CreatTree(t);
	ShowTree_Pro(t);

	return 0;
}

bool InitTree(TreeNode *t)
{
	for(int i = 0; i < MAXSIZE; i ++){
		t[i].isempty = false;
	}

	return true;
}

bool CreatTree(TreeNode *t)
{
	int i = 1;
	char choice;
	printf("Please enter your choice\n");
	printf("a. InsertLeftChild	b. InsertRightChild\n");
	printf("c. BackFather		d. ShowPosition\n");
	printf("e. GotoLeftChild	f. GotoRightChild\n");
	printf("g. insert		h. exit\n");
	scanf("%c", &choice);
	while(choice != '!'){
		if(choice == 'g'){
			int num = 0;
			printf("Please enter your number\n");
			scanf("%d", &num);
			t[i].data = num;
			t[i].isempty = true;
		}else if(choice == 'a'){
			int temp = 0;
			temp = 2 * i;
			int num = 0;
			t[temp].data = num;
			t[temp].isempty = 1;
		}else if(choice == 'b'){
			int temp = 0;
			temp = 2 * i + 1;
			int num = 0;
			fflush(stdin);
			scanf("%d", &num);
			t[temp].data = num;
			t[temp].isempty = 1;
		}else if(choice == 'c'){
			int temp = 0;
			temp = floor(i / 2);
			i = temp;
		}else if(choice == 'd'){
			printf("%d\n", i);
			// level表示当前i处于的层级
			double level = 0;
			level = floor(log((double)i) / log(2)) + 1;
			// log2i向下取整 + 1
			printf("Your serial number is %d\n", i);
			printf("Your Level is %d\n", (int)level);
		}else if(choice == 'e'){
			int temp = 0;
			temp = 2 * i;
			i = temp;
		}else if(choice == 'f'){
			int temp = 0;
			temp = 2 * i + 1;
			i = temp;
		}else if(choice == 'h'){
			return true;
		}else{
			printf("Error Input, Please enter again\n");
		}
		fflush(stdin);
		printf("Please enter your choice\n");
		printf("a. InsertLeftChild	b. InsertRightChild\n");
		printf("c. BackFather		d. ShowPosition\n");
		printf("e. GotoLeftChild	f. GotoRightChild\n");
		printf("g. insert		h. exit\n");
		scanf("%c", &choice);
	}

	return true;
}


bool ShowTree(TreeNode *t)
{
	for(int i = 1; i < MAXSIZE; i ++){
		if(t[i].isempty == false){
			printf("0 ");
		}else{
			printf("%d ", t[i].data);
		}
	}

	return true;
}

bool ShowTree_Pro(TreeNode *t)
{	
	if(t[1].isempty == false){
		printf("0");
	}else{
		printf("%d", t[1].data);
	}
		printf("\n");
	for(int i = 2; i <= 3; i ++){
		if (t[i].isempty == false){
			printf("0	");
		}
		else{
			printf("%d	", t[i].data);
		}
	}
		printf("\n");
	for(int i = 4; i <= 7; i ++){
		if (t[i].isempty == false){
			printf("0	");
		}
		else{
			printf("%d	", t[i].data);
		}
	}
		printf("\n");	

	return true;
// g1eg2cfg3ceeg4h(with Enter)
}