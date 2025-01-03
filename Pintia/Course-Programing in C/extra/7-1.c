#include <stdio.h>

#define N 1000000

int dp[N + 5];

void pre() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 32767;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pre();
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        printf("%d\n", dp[k]);
    }
    return 0;
}
