#include <stdio.h>
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a * b > 0){
        printf("like signs");
    }
    if(a * b < 0){
        printf("unlike signs");
    }
    if(a == 0 && b == 0){
        printf("two zeros");
        return 0;
    }
    if(a == 0 || b == 0){
        printf("one zero");
    }
    return 0;
}