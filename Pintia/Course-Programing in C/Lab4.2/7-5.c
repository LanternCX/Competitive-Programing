#include <stdio.h>
#include <math.h>
#define ll long long
int main(){
    ll n;
    scanf("%lld", &n);
    ll temp = n;
    int dig = 0;
    while (temp > 0) {
        temp /= 10;
        dig++;
    }
    if(n == 0){
        printf("%d ", 0);
    }
    for(int i = dig; i >= 1; i--){
        int d = pow(10, i - 1);
        int a = n / d;
        printf("%d ", a);
        n %= d;
    }
    return 0;
}