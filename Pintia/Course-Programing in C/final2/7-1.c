#include <stdio.h>
#include <math.h>
int a[100];
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            ans += a[j] - a[i] > 0 ? a[j] - a[i] : a[i] - a[j];
        }
    }
    printf("%d", ans);
    return 0;
}