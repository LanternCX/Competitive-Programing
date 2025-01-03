#include <stdio.h>
#include <string.h>
int arr[10];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char s[1000];
        scanf("%s", s);
        for(int i = 0; i < strlen(s); i++){
            arr[s[i] - '0']++;
        }
    }
    int max = -1e7;
    for(int i = 0; i < 10; i++){
        max = max > arr[i] ? max : arr[i];
    }
    printf("%d:", max);
    for(int i = 0; i < 10; i++){
        if(arr[i] == max){
            printf(" %d", i);
        }
    }
    return 0;
}