#include <stdio.h>

int main() {
    double eps;
    scanf("%lf", &eps);
    double ans = 0;
    for(int i = 1; 1.0 / i >= eps; i += 3){
        double xn = (i % 2 == 1 ? 1.0 : -1.0) / i;
        ans += xn;
    }
    if(eps > 1){
        ans = 1.0;
    }
    printf("sum = %.6lf\n", ans);
    return 0;
}