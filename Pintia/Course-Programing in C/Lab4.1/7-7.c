#include <stdio.h>

int main(){
    int ans = 0;
    int a, n;
    scanf("%d%d", &a, &n);
    int temp = 0;
    for(int i = 0; i < n; i++){
        temp *= 10;
        temp += a;
        ans += temp;
    }
    printf("s = %d", ans);
    return 0;
}