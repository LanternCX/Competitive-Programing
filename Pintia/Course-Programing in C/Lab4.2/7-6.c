#include <stdio.h>
const int N = 2000000;
int p[2000005];
void ai(int n){
    for(int i = 0; i <= N; i++){
        p[i] = 1;
    }

    p[0] = p[1] = 0;
    for(int i = 2; i * i <= N; i++){
        if (p[i]) {
            for(int j = i * i; j <= N; j += i){
                p[j] = 0;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    ai(n);
    for(int i = 0; i <= n; i++){
        int temp = (2 << (i - 1)) - 1;
        if(p[temp]){
            printf("%d\n", temp);
        }
    }
    if (n == 1) {
        printf("None");
    }
    return 0;
}