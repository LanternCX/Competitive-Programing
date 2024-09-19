#include<stdio.h>
long long fact(int n){
    long long res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}
int main(){
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans += fact(i);
    }
    printf("%lld\n", ans);
    return 0;
}