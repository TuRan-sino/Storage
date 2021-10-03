/*
一. 使用链式存储的串

二. 优缺点
1. 优点: 
2. 缺点: 
	1. 存储密度低:(使用char data 的情况) 但是你要知道本文中使用的是(char data[4])
	每个节点有1B的空间存放data, 但是要有4B的空间存放next(指针).
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 255
#define MAXCAPACITY 4

typedef struct StNode{
	char data[MAXCAPACITY];		// 每个节点存放一个字符
	struct StNode *next;
}StNode;
typedef struct Head{
	struct StNode *next;
	int length;
}*LinkList;

bool InitStr(LinkList *S);
bool StrAssgin(LinkList *S, char *str);
bool ShowStr(LinkList S);
bool DestoryStr(LinkList *S);

int main(int argc, char const *argv[])
{
	LinkList S;
	InitStr(&S);
	InitStr(&R);
	InitStr(&T);
	char str0[MAXSIZE] = "wodiaoni";
	char str1[MAXSIZE] = "made";	
	StrAssgin(&S, *str0);
	StrAssgin(&S, *str1);

	StrConcat(&T, S, R);



	return 0;
}

bool InitStr(LinkList *S)
{
	*S = (LinkList) malloc(sizeof(StNode));
	if(!S)
		return FALSE;
	(*S)->next = NULL;
	(*S)->length = 0;

	return TRUE;
}


bool ShowStr(LinkList S)
{
	StNode *s;		// 工作指针, 指向当前指向的节点, 初始值设置为S->next
	s = S->next;
	int length = 1;
	while(length <= S->length){
		for(int i = 0; i < MAXCAPACITY; i ++){
			if(s->data[i] == '\0')
				return TRUE;
			printf("%c", s->data[i]);
			length ++;
		}
		s = s->next;
	}

	return TRUE;
}

// 销毁串
bool DestoryStr(LinkList *S)
{
	if((*S)->length == 0){
		return FALSE;
	}
	StNode *p = (*S)->next;
	StNode *temp = p;
	while(temp->next != NULL){
		p = temp->next;
		free(temp);
		temp = p;
	}
	free(*S);

	return TRUE;
}


bool StrAssgin(LinkList *S, char *str)
{
	if(!*S)
		return FALSE;
	StNode *s, *r;
	int i = 0;
	r = (StNode *)(*S);	
	while(str[i] != '\0'){
		s = (StNode *) malloc(sizeof(StNode)); 
		s->next = r->next;
		if(i < 4)
			(*S)->next = s;
		else
			r->next = s;
		r = s;
		for(int j = 0; j < MAXCAPACITY; j ++){
			if(str[i] == '\0'){
				s->data[i] = '\0';
				(*S)->length ++;
				return TRUE;
			}
			s->data[j] = str[i];
			(*S)->length ++;
			i ++;
		}
	}	

	return TRUE;
}

// 判空操作
bool IfEmpty(LinkList S)
{
	if(S->length == 0)
		return TRUE;
	else
		return FALSE;
}


// 
// bool StrClean()

// 将两个模式串R & S 链接为一个串T
bool StrConcat(LinkList *T, LinkList S, LinkList R)
{
	int length = S.length + R.length;
	int i = 0;
	while((*T)->length <= length){
		for(i; i < S->length; i ++){
			

		}
	}



	return TRUE;
}