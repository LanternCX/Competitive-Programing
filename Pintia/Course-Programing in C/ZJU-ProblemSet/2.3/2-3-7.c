#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n < 0){
        printf("Invalid Value!");
        return 0;
    }
    double ans;
    if(n >= 0 && n <= 50){
        ans = n * 0.53;
    }else{
        ans = 50 * 0.53 + (0.53 + 0.05) * (n - 50);
    }
    printf("cost = %.2lf", ans);
    return 0;
}