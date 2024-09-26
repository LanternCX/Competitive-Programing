#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    double ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (i % 2 == 0 ? -1.0 : 1.0) * i / (i * 2 - 1);
    }
    printf("%.3lf", ans);
    return 0;
}