/****************************************************************************************************
@title: TuRan
@des:
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "C:\Users\TuRan\WORK\Storage\DAS\Lib\DAS.h"


int SqList_Init(SqList *L)
{
	(*L).data = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);		// 给data malloc数据空间

	if(!L->data) return FALSE;											// 假设L->data不存在, 返回FALSE

	(*L).length = 0;													// 将初始时的length设置为0
	(*L).maxsize = INITSIZE;											// 将初始时的 maxsize 设置为 INITSIZE

	printf("SqList Init Success\n");

	return TRUE;
}


int SqList_Creat(SqList *L)
{
	int i = 0, num = 0;

	scanf("%d", &num);
	while(num != -9999){
		if(L->length + 1 > L->maxsize){		// 假设当前线性表的长度大于最大长度, 则扩大线性表
			SqList_Creat(L);
		}
		L->data[i] = num;
		i ++;
		L->length ++;
		scanf("%d", &num);					// 挨个输入数据
	}
	return TRUE;
}


int lengthOfLongestSubstring()
{
	
}


int main(int argc, char const *argv[])
{
	
	return 0;
}
