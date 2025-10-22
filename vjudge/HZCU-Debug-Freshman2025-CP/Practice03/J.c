#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[100010];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int diff[100010];
    diff[0] = arr[0];
    for (int i = 1; i < n; i++) {
        diff[i] = arr[i] - arr[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (diff[i] > 0) {
            ans += diff[i] > 0 ? diff[i] : 0;
        }
    }
    printf("%lld", ans);
    return 0;
}
/**
 * 4 3 2 5 3 5 
 * 4 -1 -1 3 -2 2
 */