#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += pow(2, i);
    }
    printf("result = %d", ans);
    return 0;
}