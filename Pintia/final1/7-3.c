#include <stdio.h>
int arr[100];
int ans[2];
int main(){
    int n;
    scanf("%d", &n);
    int idx = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] == 5){
            ans[idx++] = i;
        }
    }
    if(idx == 0){
        printf("Not Found");
        return 0;
    }
    if(idx >= 1){
        arr[ans[0]] = arr[0];
        arr[0] = 5;
    }
    if(idx >= 2){
        arr[ans[1]] = arr[n - 1];
        arr[n - 1] = 5;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}