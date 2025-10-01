#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    int mx = 0, mn = 10;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mx = fmax(mx, x);
        mn = fmin(mn, x);
        sum += x;
    }
    sum -= mx + mn;
    printf("%.2lf", sum / (n - 2));
    return 0;
}