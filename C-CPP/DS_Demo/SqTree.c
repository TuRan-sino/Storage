/*
	顺序存储的二叉树（不存在链表的next域， 因此是顺序存储）
		因为: 二叉树的逻辑结构不能像线性表那样定义一个头节点（SqList）,
			然后再头结点中定义一个数组, 每个节点实际上就是数组的某一项
		因此: 二叉树必须单独定义节点, 使用TreeNode单独定义一个节点
	存储方式:
		t[0]:一般情况下使t[0]位置空缺, 从而使得完全二叉树的标号从1开始与数组对应起来[本例中使t[0] = length(节点的总数)]
		TreeNode 属于我们定义的结构体， 实际上真正的数据结构是一个数组
	节点逻辑结构的实现方式
		i的左孩子		2i
		i的右孩子		2i + 1
		i的父节点		i/2
		i所在的层级		log2(n + 1) 向下取整
		
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef int ElemType;
// 节点的结构体
typedef struct TreeNode
{
	// 节点的data
	ElemType data;
	// 判断节点是否为空
	bool isempty;
}TreeNode;

int main(int argc, char const *argv[])
{
	/*
	定义了一个长度为maxsize的数组t
	按照从上到下从左到右的顺序依次存储依次存储完全二叉树的各个节点
	*/
	TreeNode t[MAXSIZE];

	return 0;
}

bool InitTree(TreeNode *t)
{
	for(int i = 0; i < MAXSIZE; i ++){
		t[i].isempty = true;
	}
}