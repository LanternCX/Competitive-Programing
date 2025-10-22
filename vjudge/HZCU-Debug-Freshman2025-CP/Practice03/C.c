#include <stdio.h>
#include <math.h>

typedef struct {
    char name[1000];
    int a, b, c, sum;
} node;

int main() {
    int n;
    scanf("%d", &n);
    node arr[1010];
    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", arr[i].name, &arr[i].a, &arr[i].b, &arr[i].c);
        arr[i].sum = arr[i].a + arr[i].b + arr[i].c;
        max = fmax(max, arr[i].sum);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].sum == max) {
            printf("%s %d %d %d", arr[i].name, arr[i].a, arr[i].b, arr[i].c);
            break;
        }
    }
    return 0;
}