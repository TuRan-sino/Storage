#include <stdio.h>

void UpAndDown(int);

int	main(int argc, char const *argv[])
{
	UpAndDown(1);


	return 0;
}

void UpAndDown(int n)
{
	// printf("%d %p\n", n, &n);
	if(n < 4)
		UpAndDown(n + 1);
	printf("%d %p\n", n, &n);
}