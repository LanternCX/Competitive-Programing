#include<stdio.h>
#include<math.h>

int main(){
    double x;
    scanf("%lf", &x);
    printf("f(%.2lf) = %.2lf", x, (x >= 0 ? pow(x, 0.5) : (x + 1) * (x + 1) + 2 * x + 1.0 / x));
    return 0;
}