/*
输入两个整数,将两个整数之间的所有整数计算平方和并标准输出
*/
#include <stdio.h>
#include <stdbool.h>

long get_long(void);
bool bad_limitis(long begin, long end, long low, long high);
double sum_square(long a, long b);

int main(int argc, char const *argv[])
{
	const long MIN = -10000000L;
	const long MAX = +10000000L;
	long start;
	long stop;
	double answer;

	printf("lower limit: ");
	start = get_long();
	printf("upper limit: ");
	stop = get_long();
	while(start != -1 && stop != -1){
		if(bad_limitis(start, stop, MIN, MAX)){
			printf("Please try again\n");
		}else{
			answer = sum_square(start, stop);
			printf("from %ld to %ld is %f\n", start, stop, answer);
		}
		printf("lower limit ");
		start = get_long();
		printf("upper limit: ");
		stop = get_long();
	}
	printf("Fault, because you enter a value which lower than 0\n");
	printf("Done\n");

	return 0;	
}

long get_long(void)
{
	long input;
	char ch;
	while(scanf("%ld", &input) != 1){
		while((ch = getchar()) != '\n'){
			putchar(ch);
		}
		printf(" is not a interger. Please enter a interger \n");
	}

	return input;
}

bool bad_limitis(long begin, long end, long low, long high)
{
	bool not_good = false;
	if(begin > end){
		printf("%ld lagger than %ld. This is a error input\n", begin, end);
		not_good = true;
	}
	if(begin < low || end < low){
		printf("Values must be %ld or greater\n", low);
		not_good = true;
	}
	if(begin >high || end > high){
		printf("Values musht be %ld or less\n", high);
		not_good = true;
	}

	return not_good;
}

double sum_square(long a, long b)
{
	double total = 0;
	for(long i = a; i <= b; i ++){
		total += (double)i * (double)i;
	}

	return total;
	
}


