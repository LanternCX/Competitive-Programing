#include <stdio.h>
int arr[100];
void sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int idx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[idx]){
                idx = j;
            }
        }
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i != n - 1) putchar(' ');
    }
    return 0;
}