#include <stdio.h>
int arr[100];
int main(){
    int n;
    scanf("%d", &n);
    if(n == 0){
        scanf("%d", &arr[0]);
        printf("%d ", arr[0]);
        return 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);
    for(int i = 0; i < n; i++){
        if(i == 0 && x <= arr[i]){
            printf("%d ", x);
        }
        printf("%d ", arr[i]);
        if(x >= arr[i] && x <= arr[i + 1] || i == n - 1 && x >= arr[i]){
            printf("%d ", x);
        }
    }
    return 0;
}