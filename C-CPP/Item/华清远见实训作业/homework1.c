#include <stdio.h>

void step(int *s);

int main(int argc, char const *argv[])
{
	int frequency = 0;
	int i = 0;
	int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("Please enter the input for back step all array, the number is between 0 to 9\n");
	scanf("%d", &frequency);

	for(i = 0; i < frequency; i ++){
			step(s);
	}



	for(int i = 0; i < 9; i ++){
		printf("%d  ", s[i]);
	}

	return 0;
}


void step(int *s)
{
	int i = 0;
	int temp = 0;
	temp = s[8];
	for(i = 8; i > 0; i --){
		s[i] = s[i - 1];
	}

	s[0] = temp;
}
