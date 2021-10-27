#include <stdio.h>
#include "hotel.h"

int menu(void)
{
	int code, status;

	printf("\n%s%s\n", STARS, STARS);
	printf("Enter the number of the desired hotel:\n");
	printf("1 Fhotel 		2 Ohotel \n");
	printf("3 chotel 		4 shotel\n");
	printf("5 quit\n");
	printf("\n%s%s\n", STARS, STARS);

	while((status = scanf("%d", &code)) != 1 || code < 1 || code > 5){
		if(status != 1){
			scanf("%*s");
		}
		printf("Enter a interger from 1 to 5\n");
	}

	return code;
}

int get_nights(void)
{
	int nights;
	printf("How many nights you want to stay\n");
	while(scanf("%d", &nights) != 1){
		scanf("%*s");
		printf("Please enter an interger");
	}

	return nights;
}

void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for(n = 1; n <= nights; n ++, factor *= DISCOUNT){
		total += rate * factor;
	}

	printf("This is the last prices: %0.2f$ \n", total);
}