#include<stdio.h>

int main(){
    int ans = 0;
    while(1){
        int temp;
        scanf("%d", &temp);
        if(temp <= 0){
            break;
        }
        if(temp % 2 == 1){
            ans += temp;
        }
    }
    printf("%d", ans);
    return 0;
}