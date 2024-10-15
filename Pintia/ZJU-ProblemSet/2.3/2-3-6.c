#include <stdio.h>
int main(){
    double x;
    scanf("%lf", &x);
    printf("f(%.1lf) = %.1lf", x, x == 10 ? 1 / x : x);
    return 0;
}