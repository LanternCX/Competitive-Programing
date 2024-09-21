#include <stdio.h>
const int N = 500;
int p[505];
void ai(){
    for(int i = 0; i <= N; i++){
        p[i] = 1;
    }

    p[0] = p[1] = 0;

    for(int i = 2; i * i <= N; i++){
        if(p[i]){
            for(int j = i * i; j <= N; j += i){
                p[j] = 0;
            }
        }
    }
}
int main(){
    ai();
    int m, n;
    scanf("%d %d", &m, &n);
    int ans1 = 0, ans2 = 0;
    for(int i = m; i <= n; i++){
        if(p[i]){
            ans1++;
            ans2 += i;
        }
    }
    printf("%d %d", ans1, ans2);
    return 0;
}