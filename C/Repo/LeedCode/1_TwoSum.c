/* 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int *nums, int numsSize, int target, int *returnSize);

int main()
{
	int n, target, i, returnSize;
	printf("please enter the number of this array: \n");
	scanf("%d", &n);

	printf("Please enter your array: \n");
	int nums[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}
	printf("Please enter your target: \n");
	scanf("%d", &target);

	int *output;

	output = twoSum(nums, n, target, &returnSize);

	printf("%d ", output[0]);
	printf("%d", output[1]);

	
	return 0;
}

// 找到两函数之和
// nums： 输入的数组， numSize： 输入数组的大小， target： 需要找到的数值， returnsize： 返回值的大小
int* twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int i = 0, j = 0;
	int *ret = NULL;
	// 设置将要return数组：ret。
	ret = (int *)malloc(sizeof(int) * 2);
	// 题目标注需要使用动态申请返回值
	for(i = 0; i < numsSize; i ++){
		for(j = i + 1; j < numsSize; j ++){
			// j从i后面一个书开始， 一直到numsize结束
			if(nums[i] + nums[j] == target){
				ret[0] = i;
				ret[1] = j;

				*returnSize = 2;
				return ret;
			}
		}
	}
	*returnSize = 2;

	return ret;

}