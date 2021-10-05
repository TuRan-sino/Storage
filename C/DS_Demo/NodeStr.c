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
bool StrConcat(LinkList *T, LinkList S, LinkList R);

int main(int argc, char const *argv[])
{
	LinkList S;
	LinkList R;
	LinkList T;
	InitStr(&S);
	InitStr(&R);
	InitStr(&T);
	char str0[MAXSIZE] = "wodiaoniadasadssaasdjkhnhjkhgbkhgkhghkhjkhk ";
	char str1[MAXSIZE] = "made";	
	StrAssgin(&S, str0);
	StrAssgin(&R, str1);

	StrConcat(&T, S, R);

	ShowStr(T);


	// LinkList S;
	// char str[MAXSIZE] = "wodiaonimade";
	// StrAssgin(&S, str);

	// ShowStr(S);

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

// 
bool CreatStr_Tail(LinkList *S)
{


	return TRUE;
}


bool StrAssgin(LinkList *S, char *str)
{
	if(!*S)		// 假设S节点不存在, 返回false
		return FALSE;
	StNode *s, *r;		// 声明两个节点: s=>每次创建出来的节点, r=>始终指向尾节点的节点
	int i = 0;		// 工作指针, 指向str(char字符串)当前的位置
	r = (StNode *)(*S);		// r指针现在指向头节点(LinkList类型)
	while(str[i] != '\0'){
		s = (StNode *) malloc(sizeof(StNode));
		s->next = r->next;		// s的next指向r->next的位置
		if(i < 4)
			(*S)->next = s;		// 假设当前节点数小于4, 让头指针的next指向s, 因为r是格式转换来的, 因此r这个指针不能对s进行操作
		else
			r->next = s;		// 假设当前的节点数大于4, 让最后一个节点的next域指向s
		r = s;		// 最后一个节点指向s
		for(int j = 0; j < MAXCAPACITY; j ++){		// 以MAXCAPACITY为循环, 把str的字符送给s
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
bool StrClean(LinkList S)
{

	return TRUE;
}

// 将两个模式串R & S 链接为一个串T
bool StrConcat(LinkList *T, LinkList S, LinkList R)
{

	StNode *s = S->next;
	StNode *r = R->next;
	StNode *t = (StNode *)(*T);
	int i = 0;
	int length = 0;
	StNode *temp = (StNode *)(*T);
	while(length < S->length){
		t = (StNode *)malloc(sizeof(StNode));
		t->next = temp->next;
		if((*T)->length < 4){
			(*T)->next = t;
		}else{
			temp->next = t;
		}
		temp = t;
		for(i = 0; i < MAXCAPACITY; i ++){
			t->data[i] = s->data[i];
			length ++;
			(*T)->length ++;
		}
		s = s->next;
	}
	length = 0;
	while(length < R->length){
		t = (StNode *)malloc(sizeof(StNode));
		t->next = temp->next;
		temp->next = t;
		temp = t;
		for(i = 0;i < MAXCAPACITY; i ++){
			t->data[i] = r->data[i];
			length ++;
			(*T)->length ++;
		}
		r = r->next;
	}

	return TRUE;
}