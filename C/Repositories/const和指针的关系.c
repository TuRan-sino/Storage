#include <stdio.h>

int main(int argc, char const *argv[])
{
	char name[10] = "fuck y";
	char *const sturdy = name;
	sturdy[5] = 'm';				//sturdy 是 *const char,因此该指针的地址值不能更改,但是可以更改其指向的值


	char const *haha;				//haha 是 const *haha,因此 haha 的指针本身可以改变,但是不能改变他指向的值
	haha = name;
	// haha[5] = 'm'


				 					//看看删改你二者之间的联系 const 在 * 前面 (const *haha),那么就是限定了指针指向的值, const 在 * 后面 (*const hah) 就是限定了指针的值
	puts(haha); 
}