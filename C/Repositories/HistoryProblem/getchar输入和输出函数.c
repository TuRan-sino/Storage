/*
算法输入:一个字符 和这个字符将要答应的行数和列数
算法输出:输出rows行和clos列的字符
*/
#include <stdio.h>

void display(char ch, int lines, int width);

int main(int argc, char const *argv[])
{
	int ch;
	int rows, clos;

	printf("Enter a character and two intergers;\n");
	while((ch = getchar()) != '\n'){
		if (scanf("%d %d", &rows, &clos) != 2){
			break;
		}
		display(ch, rows, clos);
		while(getchar() != '\n'){
			continue;
		}
		printf("Enter an character and two intergers\n");
		printf("Enter a newline to quit\n");
	}
	printf("BYE\n");

	return 0;
}

void display(char ch, int lines, int width)
{
	int rows, clos;
	for(rows = 0; rows < lines; rows ++){
		for(clos = 0; clos < width; clos ++){
			putchar(ch);
		}
		putchar('\n');
	}
}