#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[1010] = {0};
    for (int i = 0; i < m; i++) {
        char op[100];
        scanf("%s", op);
        if (strcmp(op, "water") == 0) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--, r--;
            for (int j = l; j <= r; j++) {
                arr[j]++;
            }
        }
        if (strcmp(op, "rise") == 0) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            l--, r--;
            int res = 0;
            for (int j = l; j <= r; j++) {
                if (arr[j] >= k) {
                    res++;
                    arr[j] = 0;
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}