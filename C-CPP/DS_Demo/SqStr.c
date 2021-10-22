/*
一. 使用顺序结构存储的静态链表

二. 定义
1. SSqStr => Static Sequence string(静态顺序串)
2. HSqStr => Heap Sequence string(堆分配顺序串)

三. 存储方式
char[0]位置作为空位(为的是让数组下标(从0开始) & 位序(从1开始)能够对应起来).	 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STAR "********************"
#define TRUE 1
#define FALSE 0
#define MAXSIZE 255		// 定义线性表的最大长度

// typedef struct SSqStr{
// 	char data[MAXSIZE];
// 	int length;		// 当前字符串的实际长度
// }SSqStr;
// 静态数组(定长的顺序存储), 因为255不可变

typedef struct HSqStr{
	char *data;		// 按照串的长度malloc存储区, ch指向存储区域的基地址
	int length;		// 实际上字符串的现有长度
}HSqStr;
// 动态分配数组, 使用堆分配的方式存储数据. (使用之后记得要free)


bool CreatStr(HSqStr *S);
bool GetNextVal(HSqStr T, int *next);
bool GetNext(HSqStr T, int *next);
int KMP(HSqStr S, HSqStr T);
int StrLength(HSqStr S);
bool DestoryStr(HSqStr *S);
bool StrClean(HSqStr *S);
bool IfEmpty(HSqStr S);
bool StrCpoy(HSqStr *T, HSqStr S);
bool InitStr(HSqStr *S);
bool ShowStr(HSqStr S);
bool StrAssgin(HSqStr *S, char *temp);
bool StrConcat(HSqStr *T, HSqStr S, HSqStr R);
int Index_Simple(HSqStr S, HSqStr T);
int Index(HSqStr S, HSqStr T);

int main(int argc, char const *argv[])
{
	HSqStr S;
	int *next;
	InitStr(&S);

	CreatStr(&S);


	next = (int*)malloc(sizeof(int) * (S.length + 1));
	GetNextVal(S, next);
	for(int i = 1; i < (S.length + 1); i ++){
		printf("%d", next[i]);
	}


	return 0;
}

// 初始化串
bool InitStr(HSqStr *S)
{
	S->length = 0;
	S->data = (char *) malloc(sizeof(char) * MAXSIZE);
	if(!S->data)
		return FALSE;

	return TRUE;

}

// 串赋值操作
bool StrAssgin(HSqStr *S, char *temp)
{
	int i = 1, j = 0;		// 计数器j目标是: char str, 计数器i目标是: S串
	while(temp[j] != '\0'){		// 从第0未开始, 一直到最后一位(\n)之前	
		S->data[i] = temp[j];
		i ++;
		j ++;
		S->length ++;
	}
	

	return TRUE;
}

// 创建str
bool CreatStr(HSqStr *S)
{
	int i = 1, j = 0;
	char temp[MAXSIZE];
	printf("Please input your char\n");
	scanf("%s", temp);
	while(temp[j] != '\0'){
		S->data[i] = temp[j];
		i ++;
		j ++;
		S->length ++;
	}

	return TRUE;
}

// 串拷贝操作. 将串S拷贝到串T
bool StrCpoy(HSqStr *T, HSqStr S)
{
	if(T->data == NULL || S.data == NULL)		// 假设T串和和S串中有一个是空串, 返回false
		return FALSE;
	for(int i = 1; i <= S.length; i ++){		// 从1开始复制所有的数据
		T->data[i] = S.data[i];
	}

	T->length = S.length;

	return TRUE;
}

// 判空
bool IfEmpty(HSqStr S)
{
	if(S.length == 0)
		return TRUE;
	else 
		return FALSE;
}

// 清空串
bool StrClean(HSqStr *S)
{
	S->length = 0;
	// clean只需要将Length设置为0就完事了, 因为S串里面的空数据基本上不需要你管

	return TRUE;
}

// 销毁串
bool DestoryStr(HSqStr *S)
{
	free(S->data);
	S->length = 0;

	return TRUE;
}

// 连接为新串. 将串S1 & S2 链接为一个新串 T
bool StrConcat(HSqStr *T, HSqStr S, HSqStr R)
{	
	int i = 0;		// 计数器1
	int j = 0;		// 计数器2
	if(S.length + R.length - 1 > MAXSIZE)		// 假设S和R串的长度大于maxsize, 返回flase
		return FALSE;
	for(i = 1; i <= S.length; i ++){		// 首先将S串的所有内容复制到T串中
		T->data[i] = S.data[i];
		T->length ++;
	}
	j = T->length + 1;		// 复制R串的计数器j从T的最后一位的后面一位开始
	for(i = 1; i <= R.length; i ++){		// 之后将R串的所有内容复制到T串中
		T->data[j] = R.data[i];
		T->length ++;
		j ++;
	}

	return TRUE;

}

int StrLength(HSqStr S)
{
	return S.length;
}

// 求字串: 使用sub返回串S的第pos(pos是位序, 从1开始)个字符起长度为len的字串
bool SubString(HSqStr *Sub, HSqStr S, int pos, int len)
{
	if(pos + len - 1 > S.length)		// 假设子串越界, 则返回false;
		return FALSE;
	/*
	为什么要-1?
	pos + len相当于你要得到的子串最后一个元素的坐标,
	理论上来说pos不应该被算作一个元素, 但是如果使用pos+len的话pos被算作一个元素了
	因此: 要 - 1, 相当于pos本身不算做一个元素.
	*/
	for(int i = pos; i < pos + len; i ++){
		int j = 1;
		Sub->data[j] = S.data[i];
		j ++;
	}
	Sub->length = S.length;

	return TRUE;
}

// 比较串(S串 > T串 返回 正数 否则返回 负数; 相同返回0)
int StrCompare(HSqStr S, HSqStr T)
{
	for(int i = 1; i < S.length && T.length; i ++){
		if(S.data[i] != T.data[i]){
			return S.data[i] - T.data[i];	
		}
	}		// 从第一个元素开始遍历S串和T串, 一直到S串和T串有一个结束. 假设期间发现了不同的元素直接相减就可以得到+-
	
	if(S.length > T.length)		
		return 1;
	else 
		return -1;
	// 此时S串或者T串有一个已经遍历结束但是还不能得到到底是那个串比较大, 直接比较串长
	// 假设两个串一样长(这个时候的一样长基本上就是相同了)则返回 0
	return 0;
}

// 遍历队列并且输出
bool ShowStr(HSqStr S)
{
	printf("Your String is : ");
	if(S.length < 1)
		return FALSE;
	for(int i = 1; i <= S.length; i ++){
		printf("%c", S.data[i]);
	}
	putchar('\n');

	return TRUE;
}

// 定位子串. 假设主串S中存在与子串T相同的串, 则return主串S中第一次出现的位置. 否则return 0;
int Index(HSqStr S, HSqStr T)
{
	int k = 0;		// 工作变量
	int m = T.length;
	HSqStr sub;		// 暂存器, 作为下一步子串的暂存器
	while(k < S.length - T.length + 1){
		SubString(&sub, S, k, m);		// 取子串存入暂存器
		if(StrCompare(sub, T) == 0)		// 判断暂存器与串T是否相同
			return k;
		else
			return k ++;
	}

	return 0;
}

// 朴素模式匹配算法
int Index_Simple(HSqStr S, HSqStr T)
{
	int k = 0;		// 工作指针: 用来指向当先子串的头
	int i = k, j = 1;		// m: 用来指向子串的的data[m]; n: 用来指向模式串的data[n]
	while(i <= S.length && j <= T.length){		// 假设m或者n有任何一个超过了length, 跳出循环
		if(S.data[i] == T.data[j]){		// 当前二者指向的字符, 相同: 匹配下一个字符; 不同: i++, 重新判断
			i ++;
			j ++;
		}else{
			k ++;
			i = k;
			j = 1;
		}
	}
	if(j > T.length)		// 防止while循环结束是因为 子串提前结束 而结束的
		return 	k;
	else
		return 0;
}

// -----------------------------------------------------------------------

// 普通的kmp算法
int KMP(HSqStr S, HSqStr T)
{
	int i = 1;		// i指向的是主串S
	int j = 0;		// j指向的是模式串t
	int count = 0;	// 用来统计while循环的次数
	int *next;
	next = (int *)malloc(sizeof(int) * (T.length + 1));		// 给next数组动态分配存储空间
	GetNextVal(T, next);
	while(i <= S.length && j <= T.length){		// 循环截止到i 或者 j超出length为止 
		if(j == 0 || T.data[j] == S.data[i]){
		// j == 0(实际上模式串有数据是从1开始的) 的时候 T.data[0]本质上是没有数据的 '\r'
			if(count == 0){
			// 当count == 0 的时候 => j == 0 且 i == 1
			// 说明主串指向的是第一个数, 模式串指向第0个数(StrAssgin中说明第0数是没有数据的)
			// 因此这时要让j++, 使得第一次匹配的时候让S.data[i]和T.data[j]可以匹配的上
				j ++;
				count ++;
			}else{
			// T.data[i] == S.data[j] 因此进行下一步处理, 比较T.data[i + 1] 和 S.data[j + 1]
				i ++;
				j ++;
			}
		}else{
			j = next[j];
			// 匹配失败, 让j返回到next数组指向的位置 
		}
	}

	if(j > T.length){
		return i - T.length;
		// i是j > T.length时指向的最后一个位置, 因此 i - T.length 即能够匹配的上的字串的第一个字符位置
	}else{
		return 0;
	}

	return TRUE;
}

// KMP算法求next数组
bool GetNext(HSqStr T, int *next)
{
	int i = 1, j = 0;		// i初始时指向j后面一个字符
	next[1] = 0;
	while(i < T.length){
		if(j == 0 || T.data[i] == T.data[j]){
		// j == 0 的时候不用讲, next[1]肯定是 = 0 的, i ++; j ++没有毛病
		// T.data[i] = T.data[j]这个时候处于Pj和Pk相同的情况(详见笔记)下, 使next[j+1] = next[j] + 1就行 
			i ++;
			j ++;
			next[i] = j;
		}else{
		// 这是Pj不同于Pk, 让j左移到next[k]处进行下一轮比较
			j = next[j];
		}
	}

	return TRUE;
}

// 优化的KMP算法求节nextval数组
bool GetNextVal(HSqStr T, int *next)
{
	int i = 1, j = 0;
	next[1] = 0;
	while(i < T.length){
		if(j == 0 || T.data[i] == T.data[j]){
			i ++;
			j ++;
			if(T.data[i] != T.data[j])
				next[i] = j;
				// 与GetNext相同, 
			else
				next[i] = next[j];
				// 与GetNext不同, 假设i++; j++之后的next数组仍然是相同的, 递归使得next[i] = next[j];
		}else{
			j = next[j];
		}
	}


	return TRUE;
}