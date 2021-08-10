/*
	静态链表 Static Node
	工作原理:
		分配一整片的数据空间, 各个数据元素存放在该静态链表的某一个位置
		每一个小的数据空间分割成两个部分, 一个data域一个游标域, 头结点的游标为0, 该游标指向下一个节点的存储位置
				
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20

