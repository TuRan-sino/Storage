#include <stdio.h>


int main(int argc, char const *argv[])
{
	int i = 0;
	int *p = &i;


	printf("%p\n", &p);
	printf("%p\n", &i);

	return 0;
}