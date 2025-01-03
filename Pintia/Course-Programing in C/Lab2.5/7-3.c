#include<stdio.h>
double fact(int n){
    double res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}
int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    double ans = fact(n) / (fact(m) * fact(n - m));
    printf("result = %.0lf", ans);
    return 0;
}