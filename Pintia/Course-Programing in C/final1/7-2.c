#include <stdio.h>
int arr[100];
int isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        int isP = isPrime(arr[i]);
        if(isP && arr[i] % 10 == 3){
            sum1++;
        }
        
        if(isP && arr[i] % 10 == 7){
            sum2++;
        }
    }
    printf("3:%d\n", sum1);
    
    printf("7:%d", sum2);
    return 0;
}