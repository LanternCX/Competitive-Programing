#include <stdio.h>
#define ll long long
ll fact(int n){
    ll res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}
int main(){
    int n;
    scanf("%d", &n);
    double ans = 0;
    if(n > 10){
        ans = 2.71828183;
    }else {
        for(int i = 0; i <= n; i++){
            ans += 1.0 / fact(i);
        }
    }
    printf("%.8lf", ans);
    return 0;
}