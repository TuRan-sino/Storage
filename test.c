#include <stdio.h>
#include <string.h>

#define TSIZE 45
#define FMAX 5

struct film{
	char title[TSIZE];
	int rating;
}

char *s_gets(char str[], int lim);

int main(int argc, char const *argv[])
{
		struct film movies[FMAX];
		int i = 0;
		int j;
		puts("Enter the first movie title");
		while(i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0'){
			puts()
		}



s	return 0;
s}