#include <stdio.h>
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    if (m > n || m < 100 || n < 100 || m > 999 || n > 999) {
        printf("Invalid Value.");
        return 0;
    }
    int is = 0;
    for(int i = m; i <= n; i++){
        int a = i / 100;
        int c = i % 10;
        int b = (i % 100 - c) / 10;
        if(a * a * a + b * b * b + c * c * c == i){
            is = 1;
            printf("%d\n", i);
        }
    }
    if(!is){
        printf("");
    }
    return 0;
}