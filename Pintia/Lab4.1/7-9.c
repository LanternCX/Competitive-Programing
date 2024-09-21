#include <stdio.h>
int an[20000];
int main(){
    int n;
    scanf("%d", &n);
    int from = 0;
    int to = 0;
    int ans = 0;
    while (to < n) {
        for(int i = from; i <= to; i++){
            an[i]++;
            if (an[i] == 3) {
                from = i + 1;
                to++;
            }
        }
        to += from;
        ans++;
    }
    if(n == 1){
        ans = 1;
    }
    printf("%d", ans);
    return 0;
}