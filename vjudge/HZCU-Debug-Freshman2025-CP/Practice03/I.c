#include <stdio.h>
#include <string.h>
#include <math.h>

int check(int x, int y, int z) {
    int min = fmin(x, fmin(y, z));
    int max = fmax(x, fmax(y, z));
    int mid = x + y + z - min - max;
    return min + mid > max;;
}

int calc(int x) {
    int bit[6];
    for (int i = 0; i < 6; i++) {
        bit[i] = x % 10;
        x /= 10;
    }
    for (int i = 1; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            int is1 = check(bit[0], bit[i], bit[j]);
            int arr[3];
            int idx = 0;
            for (int k = 1; k < 6; k++) {
                if (k != i && k != j) {
                    arr[idx++] = bit[k];
                }
            }
            int is2 = check(arr[0], arr[1], arr[2]);
            if (is1 && is2) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += calc(i);
    }
    printf("%d", ans);
    return 0;
}