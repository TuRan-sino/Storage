/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     佛祖保佑        永无BUG
*/
#ifndef __DAS_H__
#define __DAS_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TRUE 1
#define FALSE 0
#define INITSIZE 20
#define INCSIZE 10


// 重定义数据元素
typedef int ElemType;


// 线性表结构体
typedef struct Sequence_List{
	ElemType *data;		// 数据域
	int maxsize;		// 最大长度
	int length;			// 已占用长度
}SqList;

// 单链表节点结构体
typedef struct Linked_Node{
	ElemType data;
	struct Linked_Node *next;
}LNode, *LinkList;

// 双链表节点结构体
typedef struct Dual_Linked_Node{
	ElemType data;
	struct Dual_Linked_Node *next;
	struct Dual_Linked_Node *prior;
}DLNode, *DLinkList;


#endif