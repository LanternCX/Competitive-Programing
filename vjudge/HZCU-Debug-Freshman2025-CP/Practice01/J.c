#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mx = fmax(mx, x);
    }
    printf("%d", n + mx - 1);
    return 0;
}