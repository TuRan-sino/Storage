#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0


bool pop(LinkList *S, ElemType *e)
bool push(LinkList *S, ElemType x)
bool ShowList(LinkList S)
bool BracketMatch(char *str)
bool InitList(LinkList *S)
int main(int argc, char const *argv[])
{
	

	return 0;
}

bool BracketMatch(char *str)
{
	InitStack(&S);
	int i = 0;		// 工作变量: 计数器
	int e = 0;		// 工作变量: 暂存器
	while(str[i] != '\0'){
		switch(str[i]){
			case '(': push(&S, '('); break;
			case '[': push(&S, '('); break;
			case '{': push(&S, '{'); break;
			// 遇到左括号的时候将左括号入栈
			case ')': pop(&S, &e);
				if(e != '(')
					return FALSE;
				break;
			case ']': pop(&S, &e);
				if(e != '[')
					return FALSE;
				break;
			case '}': pop(&S, &e);
				if(e != '}')
					return FALSE;
				break;
			default : break; 
		}
		i ++;
	}
	if(!IfEmpty(S)){
		printf("括号不匹配\n");
		return FALSE;
	}else{
		printf("括号匹配\n");
		return TRUE;
	}
}

bool InitList(LinkList *S)
{
	(*S) = (StackNode *) malloc(sizeof(StackNode));		// 为S分配新的物理空间
	(*S)->next = NULL;		// 是S->next == NULL, 老生常谈了
	if(*S == NULL){
		return FALSE;
	}

	return TRUE;
}

bool ShowList(LinkList S)
{
	if(S == NULL)
		return FALSE;		// 分配不成功 || S不存在
	StackNode *p = S->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");


	return TRUE;
}

bool push(LinkList *S, ElemType x)
{
	StackNode *p = (StackNode *) malloc(sizeof(StackNode));		// 创建一个新的节点p并且动态分配物理空间
	if(p == NULL)
		return FALSE;		// 创建失败
	p->data = x;			// 给p节点的data域赋值
	p->next = (*S)->next;		// 使得p节点的后一个节点指向S节点的后一个节点
	(*S)->next = p;		// S->next指向p节点, 至此就形成了S - p - NULL(其他节点)
	
	return TRUE;
}

bool pop(LinkList *S, ElemType *e)
{
	if((*S)->next == NULL){
		return FALSE;
	}
	StackNode *p = (*S)->next;		// 声明一个新的节点指向S->next
	(*S)->next = p->next;		// S->next = p->next = S->next->next, 也就是S->next指向S的下下个节点
	*e = p->data;		// 传出出战节点的值
	free(p);

	return FALSE;
}