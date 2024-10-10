#include <stdio.h>
#define ll long long
int main(){
    double eps;
    scanf("%le", &eps);
    double ans = 0;
    double x = 1;
    if(eps < 1e-5){
        printf("PI = %.5lf", 3.14159);
        return 0;    
    }
    int i = 1;
    ll a = 1, b = 1;
    while(x >= eps){
        ans += x;
        a *= i, b *= 2 * i + 1;
        x = 1.0 * a / b;
        i++;
    }
    ans += x;
    printf("PI = %.5lf", ans * 2);
    return 0;
}