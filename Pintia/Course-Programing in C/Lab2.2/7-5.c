#include <stdio.h>
int main(){
    int n = 152;
    int a = 152 / 100;
    int c = 152 % 10;
    int b = (n - c - a * 100) / 10;
    printf("152 = %d + %d*10 + %d*100", c, b, a);
    return 0;
}