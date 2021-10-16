#include <stdio.h>
#include "hotel.h"

int main(int argc, char const *argv[])
{
	int nights; 							//住的天数
	double hotel_rates; 					// 旅店费用
	int code; 								//模式输入

	while((code = menu()) != QUIT){
		switch(code){
			case 1: 	hotel_rates = HOTEL1; break;
			case 2: 	hotel_rates = HOTEL2; break;
			case 3: 	hotel_rates = HOTEL3; break;
			case 4: 	hotel_rates = HOTEL4; break;
			default: 	hotel_rates = 0.0;
						printf("opps\n");
						break;
		}
		nights = get_nights();
		showprice(hotel_rates, nights);
	}
	printf("Thank you for you operating\n");

	return 0;
}