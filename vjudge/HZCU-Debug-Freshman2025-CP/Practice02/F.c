#include <stdio.h>
#include <string.h>

int is_run(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int a[10000] = {0};
    int idx = 0;
    for (int i = x; i <= y; i++) {
        if (is_run(i)) {
            a[idx++] = i;
        }
    }
    printf("%d\n", idx);
    for (int i = 0; i < idx; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}