#include <stdio.h>

#define MAX 20

char *s_gets(char *st, int n);

int main(int argc, char const *argv[])
{
	

	





	return 0;
}


char *s_gets(char *st, int n)
{
	char *result;
	int i = 0;

	result = fgets(st, n, stdin);
	if(result){
		while(st[i] != '\n' && st[i] != '\0')
			i ++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}

	return result;
}