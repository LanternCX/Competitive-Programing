#include<stdio.h>
int ans[3];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int sc;
        scanf("%d", &sc);
        if(sc >= 85){
            ans[0]++;
        }else if(sc < 85 && sc >= 60){
            ans[1]++;
        }else{
            ans[2]++;
        }
    }
    printf("%d %d %d", ans[0], ans[1], ans[2]);
    return 0;
}