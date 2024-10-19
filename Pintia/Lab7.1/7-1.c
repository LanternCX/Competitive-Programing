#include <stdio.h>
int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int ans = -1;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        if(a == x){
            ans = i;
        }
    }
    if(ans == -1){
        printf("Not Found");
    }else {
        printf("%d", ans);
    }
    return 0;
}