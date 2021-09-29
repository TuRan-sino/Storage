/*
	静态链表 Static Node
	(未完成)
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
#define MAXSIZE 20

typedef int Elemtype;
typedef struct{
	Elemtype data;		// 数据域
	int cur;		// 游标, 指向下一个节点
}Component, StaticLinkList[MAXSIZE];


int main(int argc, char const *argv[])
{



	return 0;
}

/*
	初始化静态链表, n为存储元素的个数(从1开始)
	一般情况下来说, 静态链表需要分为两个区域(储存区域 & 备用区域)
	第0个节点存储的是备用区域的起始地址
	储存区域从第1个节点开始, 一直到第n个节点(共有n个数)
*/
bool InitList(StaticLinkList *S,int n)
{
	int i,k;
	// i => 工作变量; k => 极限变量
	k = MAXSIZE - 1;
	// 设置k为最后一位
	S[0]->cur = n + 1;
	// 第0位为n+1的值, 也就是把第0位的游标设置成备用区域的起始地址
	S[k]->cur = 1;
	// 设置最后一位的游标为1
 	for(i = 1 ; i < k ;i++){		// i作为工作变量用来选取变量. 从1开始一直到最后一个节点
		S[i]->cur = i + 1;			// 使得每个节点的游标统一指向下一个节点
		if(i <= n){
			S[i]->data = i + 10;
		}
	}

	return TRUE;
}