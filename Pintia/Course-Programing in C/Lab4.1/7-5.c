#include <stdio.h>
int main(){
    int min = 1e9;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        min = min > a ? a : min;
    }
    printf("min = %d", min);
    return 0;
}