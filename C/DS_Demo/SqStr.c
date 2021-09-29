/*
一. 使用顺序结构存储的静态链表

二. 定义
1. SSqStr => Static Sequence string(静态顺序串)
2. HSqStr => Heap Sequence string(堆分配顺序串)

三. 存储方式
char[0]位置作为空位(为的是让数组下标(从0开始) & 位序(从1开始)能够对应起来).

四. 函数执行方式
1. substring
	 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 255		// 定义线性表的最大长度

// typedef struct SSqStr{
// 	char data[MAXSIZE];
// 	int length;		// 当前字符串的实际长度
// }SSqStr;
// 静态数组(定长的顺序存储), 因为255不可变

typedef struct HSqStr{
	char *data;		// 按照串的长度malloc存储区, ch指向存储区域的基地址
	int length;		// 实际上字符串的现有长度
}HSqStr;
// 动态分配数组, 使用堆分配的方式存储数据. (使用之后记得要free)

int main(int argc, char const *argv[])
{

	return 0;
}

// // 初始化串
// bool InitStr()
// {

// }

int StrLength(HSqStr S)
{
	return S.length;
}

// 求字串: 使用sub返回串S的第pos(pos是位序, 从1开始)个字符起长度为len的字串
bool SubString(HSqStr *Sub, HSqStr S, int pos, int len)
{
	if(pos + len - 1 > S.length)		// 假设子串越界, 则返回false;
		return FALSE;
	/*
	为什么要-1?
	pos + len相当于你要得到的子串最后一个元素的坐标,
	理论上来说pos不应该被算作一个元素, 但是如果使用pos+len的话pos被算作一个元素了
	因此: 要 - 1, 相当于pos本身不算做一个元素.
	*/
	for(int i = pos; i < pos + len; i ++){
		int j = 1;
		Sub->data[j] = S.data[i];
		j ++;
	}
	Sub->length = S.length;

	return TRUE;
}

// 比较串(S串 > T串 返回 正数 否则返回 负数; 相同返回0)
int StrCompare(HSqStr S, HSqStr T)
{
	for(int i = 1; i < S.length && T.length; i ++){
		if(S.data[i] != T.data[i]){
			return S.data[i] - T.data[i];	
		}
	}		// 从第一个元素开始遍历S串和T串, 一直到S串和T串有一个结束. 假设期间发现了不同的元素直接相减就可以得到+-
	
	if(S.length > T.length)		
		return 1;
	else 
		return -1;
	// 此时S串或者T串有一个已经遍历结束但是还不能得到到底是那个串比较大, 直接比较串长

	// 假设两个串一样长(这个时候的一样长基本上就是相同了)则返回 0
	return 0;
}

// 定位子串. 假设主串S中存在与子串T相同的串, 则return主串S中第一次出现的位置. 否则return 0;
int Index(HSqStr S, HSqStr T)
{
	int i = 0;		// 工作变量
	int m = T.length;
	HSqStr sub;		// 暂存器, 作为下一步子串的暂存器
	while(i < S.length - T.length + 1){
		SubString(&sub, S, i, m);		// 取子串存入暂存器
		if(StrCompare(sub, T) == 0)		// 判断暂存器与串T是否相同
			return i;
		else
			return i ++;
	}

	return 0;
}