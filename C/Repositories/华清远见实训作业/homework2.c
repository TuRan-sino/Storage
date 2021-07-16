#include <stdio.h>

#define MAX 40

char *s_gets(char *st, int n);


int main(int argc, char const *argv[])
{
	char s[MAX];
	int i = 0;
	int j = 0;
	int count = 0;
	printf("Please enter your string\n");
	s_gets(s, MAX);


	int a[MAX];

	while(s[i] != '\0'){
		if(((int)s[i] <= 90 && (int)s[i] >= 65) || ((int)s[i] <= 122 && (int)s[i] >= 97)){
			a[j] = s[i];
			j ++;
			count ++;
		}

		i ++;
	}




	i = 0;
	while(s[i] != '\0'){
		printf("%c", s[i]);
		i ++;
	}

	printf("\n");
	i = 0;

	while(a[i] != '\0'){
		printf("%c\n", a[i]);
	}



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