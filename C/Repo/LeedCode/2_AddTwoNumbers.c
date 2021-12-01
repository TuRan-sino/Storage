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
	while(receiver != -9999){
		scanf("%d", &receiver);
		if(receiver == -9999){
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

	while(l1 != NULL && l2 != NULL){
		result = l1->val + l2->val;
		if(result >= 10){
			result = result - 10;
			carry_last = 1;
		}else{
			carry_last = 0;
		}
		r->val = carry_now + result;
		carry_now = carry_last;

		


		s = (struct ListNode *)malloc(sizeof(struct ListNode));
		s->next = NULL;
		r->next = s;
		r = s;
	}
	
	return ret;
	
}