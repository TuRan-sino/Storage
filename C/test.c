#include <stdio.h>

int main(int argc, char const *argv[])
{
	// int a = (!(0xf <<));
	unsigned int a = (0x1 << 5);
	unsigned int b = 0x20;

	printf("%u\n", a);
	printf("%u\n", b);


	return 0;
}