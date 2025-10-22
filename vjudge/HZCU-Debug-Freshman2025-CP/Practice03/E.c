#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, a, b, sc;
} node;

int main() {
    int n;
    scanf("%d", &n);
    node arr[1010];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].id, &arr[i].a, &arr[i].b);
        arr[i].sc = arr[i].a * 7 + arr[i].b * 3;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].sc >= 800 && arr[i].a + arr[i].b > 140) {
            printf("Excellent\n");
        } else {
            printf("Not excellent\n");
        }
    }
    return 0;
}