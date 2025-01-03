#include <stdio.h>
int arr[1000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        printf("%d", arr[i]);
        if(i != 0){
            putchar(' ');
        }
    }
    return 0;
}