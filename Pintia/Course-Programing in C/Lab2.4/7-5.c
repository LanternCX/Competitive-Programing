#include <stdio.h>

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    double ans = 0;
    for(int i = m; i <= n; i++){
        ans += i * i +  1.0 / i;
    }
    printf("sum = %.6f", ans);
    return 0;
}