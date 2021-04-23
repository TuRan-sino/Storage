/*=========================
 * 栈的顺序存储结构（顺序栈）
 ==========================*/

#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "String.h"    //**▲04 串**//

/* 宏定义 */
#define STACK_INIT_SIZE 100     // 顺序栈存储空间的初始分配量
#define STACKINCREMENT  10      // 顺序栈存储空间的分配增量

/*
 * 顺序栈元素类型定义
 *
 *【注】
 * 这里的元素类型为字符串
 */
typedef StringType SElemType;

// 顺序栈元素结构
typedef struct {
    SElemType* base;               // 栈底指针
    SElemType* top;                // 栈顶指针
    int stacksize;                 // 当前已分配的存储空间，以元素为单位
} SqStack;


/*
 * 初始化
 *
 * 构造一个空栈。初始化成功则返回OK，否则返回ERROR。
 */
Status InitStack(SqStack* S);

/*
 * 取值
 *
 * 返回栈顶元素，并用e接收。
 */
Status GetTop(SqStack S, SElemType* e);

/*
 * 入栈
 *
 * 将元素e压入到栈顶。
 */
Status Push(SqStack* S, SElemType e);

/*
 * 出栈
 *
 * 将栈顶元素弹出，并用e接收。
 */
Status Pop(SqStack* S, SElemType* e);

#endif
