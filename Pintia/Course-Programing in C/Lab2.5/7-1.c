#include <stdio.h>
int binpow(int x, int n);

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        printf("pow(3,%d) = %d\n", i, binpow(3, i));
    }
    return 0;
} 

int binpow(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        int res = binpow(x, n / 2);
        return res * res;
    }else {
        int res = binpow(x, n - 1);
        return res * x;
    }
}