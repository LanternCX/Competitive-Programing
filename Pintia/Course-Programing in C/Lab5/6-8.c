#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    
    return 0;
}

double funcos( double e, double x ){
    int opt = 1;
    double an = 1;
    int n = 0;
    double res = 0;
    while (an >= e) {
        res += an * opt;
        an *= (x * x) / ((n + 1) * (n + 2));
        n += 2;
        opt *= -1;
    }
    res += an * opt;
    return res;
}