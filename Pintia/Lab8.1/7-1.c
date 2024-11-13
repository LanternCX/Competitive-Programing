#include <stdio.h>
double max( double arr[], int n ){
    double res = -1e7;
    for(int i = 0; i < n; i++){
        res = res > arr[i] ? res : arr[i];
    }
    return res;
}

double min( double arr[], int n ){
    double res = 1e7;
    for(int i = 0; i < n; i++){
        res = res < arr[i] ? res : arr[i];
    }
    return res;
}

double average( double arr[], int n ){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum / n;
}
int main(){
    int n;
    scanf("%d", &n);
    double a[10000];
    for(int i = 0; i < n; i++){
        scanf("%lf", &a[i]);
    }
    double mx, mn, avg;
    mx = max(a, n);
    mn = min(a, n);
    avg = average(a, n);
    printf("average = %.2lf\nmax = %.2lf\nmin = %0.2lf", avg, mx, mn);
    return 0;
}