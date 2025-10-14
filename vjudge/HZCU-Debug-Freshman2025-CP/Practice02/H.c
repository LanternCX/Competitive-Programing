#include <math.h>
#include <stdio.h>
#include <string.h>

int is_prime(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[200];
    scanf("%s", str);
    int cnt[26] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        cnt[str[i] - 'a']++;
    }
    int mx = 0, mn = 1e9;
    for (int i = 0; i < 26; i++) {
        mx = fmax(mx, cnt[i]);
        if (cnt[i] > 0) {
            mn = fmin(mn, cnt[i]);
        }
    }
    int det = mx - mn;
    if (is_prime(det)) {
        printf("Lucky Word\n%d", det);
    } else {
        printf("No Answer\n%d", 0);
    }
    return 0;
}