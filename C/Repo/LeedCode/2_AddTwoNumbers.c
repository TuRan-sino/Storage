/*  
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
bool ShowList(ListNode L);
bool InitList(ListNode *L);
bool CreatList(ListNode *L);

int main(int argc, char const *argv[])
{
	ListNode l1;
	InitList(&l1);	
	ListNode l2;
	InitList(&l2);

	CreatList(&l1);
	CreatList(&l2);

	ListNode *ret =  addTwoNumbers(&l1, &l2);

	ShowList(*ret);

	return 0;
}

bool InitList(ListNode *L)
{
	L = (ListNode *)malloc(sizeof(ListNode));
	L->val = 0;
	L->next = NULL;
	if(!L){
		return false;
	}else
		return true;

}

bool CreatList(ListNode *L)
{
	L->next = NULL;
	ListNode *s, *r;
	r = L;
	int receiver = 0;
	printf("Please enter your number\n");
	scanf("%d", &receiver);
	L->val = receiver;
	while(receiver != -1){
		scanf("%d", &receiver);
		if(receiver == -1){
			return true;
		}
		s = (ListNode *)malloc(sizeof(ListNode));
		s->val = receiver;
		s->next = NULL;
		r->next = s;
		r = s;
	}

	return true;
}

bool ShowList(ListNode L)
{
	ListNode *temp = &L;
	printf("This is your list\n");
	while(temp != NULL){
		printf("%d ", temp->val);
		temp = temp->next;
	}

	return true;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
	ret->next = NULL;
	struct ListNode *s, *r;
	r = ret;
	int carry_last = 0;
	int carry_now = 0;
	int result = 0;
	int tag = 0;

	while(l1 != NULL && l2 != NULL){
		result = l1->val + l2->val + carry_now;
		if(result >= 10){
			tag = 1;
			result = result - 10;
			carry_last = 1;
		}else{
			carry_last = 0;
		}
		r->val =result;
		carry_now = carry_last;

		if(l1->next == NULL && l2->next == NULL){
			if(tag == 1 && carry_last == 1){
				s = (struct ListNode *)malloc(sizeof(struct ListNode));
				s->val = 1;
				s->next = NULL;
				r->next = s;
				r = s;
			}
			break;
		}else if(l1->next == NULL && l2->next != NULL){
			l2 = l2->next;
			l1->val = 0;
		}else if(l1->next != NULL && l2->next == NULL){
			l1 = l1->next;
			l2->val = 0;
		}else{
			l1 = l1->next;
			l2 = l2->next;
		}

		s = (struct ListNode *)malloc(sizeof(struct ListNode));
		s->next = NULL;
		r->next = s;
		r = s;
	}

	
	return ret;
	
}