#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = n / 5; i >= 1; i--){
        for(int j = (n - i * 5) / 2; j >= 1; j--){
            int k = n - i * 5 - j * 2;
            if(i == 0 || j == 0 || k == 0){
                continue;
            }
            printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i, j, k, i + j +k);
            sum++;
        }
    }
    printf("count = %d", sum);
    return 0;
}