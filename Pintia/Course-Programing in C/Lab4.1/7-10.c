#include <stdio.h>
int main(){
    int n;
    double h;
    scanf("%lf%d", &h, &n);
    double ans = 0;
    ans += h;
    for(int i = 2; i <= n; i++){
        ans += h;
        h /= 2;
    }
    if (n == 0) {
        ans = 0;
        h = 0;
    }
    printf("%.1lf %.1lf", ans, h / 2);
    return 0;
}