
#include <stdio.h>

int IsAutomorphic(int x);
void FindAutomorphic(int lower, int upper);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    FindAutomorphic(a, b);
    return 0;
}

/**
 * 判断x是否为自守数
 */
int IsAutomorphic(int x){
    if(x == 0 || x == 1) return 1;
    int digit = 1;
    for(; x % digit != x; digit *= 10);
    if((x * x - x) % digit == 0){
        return 1;
    }
    return 0;
}
/**
 * 输出在lower和upper区间内的自守数，没有输出None
 */
void FindAutomorphic(int lower, int upper){
    int isHave = 0;
    for(int i = lower; i <= upper; i++){
        if(IsAutomorphic(i)){
            isHave = 1;
            printf("%d\n", i);
        }
    }
    if (!isHave) {
        printf("None");
    }
}