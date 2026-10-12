#include <stdio.h>
#include <math.h>

int a[100 + 10];

int get_max(int a[], int n) {
    int mx = -1e9;
    for (int i = 0; i < n; i++) {
        mx = fmax(a[i], mx);
    }
    return mx;
}


int get_min(int a[], int n) {
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        mn = fmin(a[i], mn);
    }
    return mn;
}

int get_sum(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
       sum += a[i];
    }
    return sum;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%.2lf\n", double(get_sum(a, n) - get_max(a, n) - get_min(a, n)) / (n - 2));
    }
    return 0;
}