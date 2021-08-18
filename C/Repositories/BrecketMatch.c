#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 20

typedef struct{
	char *data;
	int top;
}SqStack;

bool InitStack(SqStack *S);
bool IfEmpty(SqStack S);
bool push(SqStack *S, char e);
bool ShowList_TopToDown(SqStack S);
bool BracketMatch(char str[], int length);
bool pop(SqStack *S, char *e);

int main(int argc, char const *argv[])
{

	int length = 10;
	char str[10] = "()()()()()";

	int i = BracketMatch(str, length);

	
	if(i == 1)
		printf("TRUE\n");	
	else
		printf("FALSE\n");
	return 0;
}

/*
	length表示char数组的长度
	str表示工作数组
*/
bool BracketMatch(char str[], int length)
{
	SqStack S;
	InitStack(&S);
	for(int i = 0; i < length; i ++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{')
			push(&S, str[i]);
		else{
			if(IfEmpty(S))
				return FALSE;
			else{
				char temp;
				pop(&S, &temp);
				if(str[i] == ')' && temp != '(')
					return FALSE;
				if(str[i] == ']' && temp != '[')
					return FALSE;
				if(str[i] == '}' && temp != '{')
					return FALSE;
			}
		}
	}
	if(IfEmpty(S))
		return TRUE;
	else
		return FALSE;
}

bool InitStack(SqStack *S)
{
	S->data = (char *) malloc(sizeof(char) * MaxSize);
	if(S->data == NULL)
		return FALSE;
	S->top = -1;

	return TRUE;
}

bool IfEmpty(SqStack S)
{
	if(S.top == -1)
		return TRUE;
	else
		return FALSE;
}

bool pop(SqStack *S, char *e)
{
	if(S->top == -1)
		return FALSE;
	*e = S->data[S->top --];

	return TRUE;
}

bool push(SqStack *S, char e)
{
	if(S->top == MaxSize - 1){
		return FALSE;
	}
	S->top ++;
	S->data[S->top] = e;	

	return TRUE;
}

bool ShowList_TopToDown(SqStack S)
{
	if(S.top == -1){
		return FALSE;
	}
	for(int i = S.top; i >= 0; i --){
		printf("%c ", S.data[i]);
	}	

	return TRUE;
}

