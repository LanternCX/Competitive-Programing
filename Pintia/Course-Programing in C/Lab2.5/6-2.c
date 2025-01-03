#include <stdio.h>

double mypow( double x, int n );

int main()
{
    double x;
    int n;
    
    scanf("%lf %d", &x, &n);
    printf("%f\n", mypow(x, n));

    return 0;
}

double mypow( double x, int n ){
    if(n == 0){
        return 1.0;
    }
    if(n % 2 == 0){
        double res = mypow(x, n / 2);
        return res * res;
    }else {
        double res = mypow(x, n - 1);
        return x * res;
    }
}