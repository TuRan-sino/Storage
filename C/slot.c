#include <stdio.h>
#include <limits.h>


int main(int argc, char const *argv[])
{


    int min = INT_MAX;
    int a[5] = {2,7,6,8,1};

    int temp = 0;

    for(int i = 0; i < 5; i ++){
        min = INT_MAX;
        for(int j = i; j < 5; j ++){
            if(a[j] < min){
				min = a[j];
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }


    for(int i = 0; i < 5; i ++){
        printf("%d\n", a[i]);
    }


    return 0;
}
