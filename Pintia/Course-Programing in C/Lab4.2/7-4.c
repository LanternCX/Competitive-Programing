#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int tag = n / 2;
    for(int i = 1; i <= n / 2; i++){
        for(int j = 0; j < tag; j++){
            printf("  ");
        }
        for(int j = 0; j < i * 2 - 1; j++){
            printf("* "); 
        }
        tag--;
        printf("\n");
    }
    for(int i = n / 2 + 1; i >= 1; i--){
        for(int j = 0; j < tag; j++){
            printf("  ");
        }
        for(int j = 0; j < i * 2 - 1; j++){
            printf("* "); 
        }
        tag++;
        printf("\n");
    }
    return 0;
}