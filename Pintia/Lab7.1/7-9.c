#include <stdio.h>
int arr1[100000000];
int arr2[100000000];
int main(){
    int n;
    int maxn = -1e7;
    int a;
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        scanf("%d", &n);
        if(n >= 0){
            arr1[n]++;
        }else {
            arr2[-n]++;
        }
        int temp = n > 0 ? n : -n;
        maxn = temp > maxn ? temp : maxn;
    }
    int max = -1e9;
    int ans = 0;
    for(int i = 0; i <= maxn; i++){
        if(max < arr1[i]){
            max = arr1[i];
            ans = i;
        }
        if(max < arr2[i]){
            max = arr2[i];
            ans = -i;
        }
    }
    printf("%d %d", ans, max);
    return 0;
}