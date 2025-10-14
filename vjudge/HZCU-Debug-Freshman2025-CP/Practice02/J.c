#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int l, n;
    scanf("%d %d", &l, &n);
    int arr[5005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        ans1 = fmax(ans1, fmin(l + 1 - arr[i], arr[i]));
        ans2 = fmax(ans2, fmax(l + 1 - arr[i], arr[i]));
    }
    printf("%d %d", ans1, ans2);
    return 0;
}