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

int main(int argc, char const *argv[])
{
	LinkList S;
	InitStr(&S);
	char str[255];
	printf("Please enter your number\n");
	scanf("%s", str);
	printf("This is your result: ");
	
	StrAssgin(&S, str);

	ShowStr(S);
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


// bool DestoryStr(LinkList *S)
// {
// }


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