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
    printf("%lld", fact(n));
    return 0;
}