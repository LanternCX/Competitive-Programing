#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[1000];
    int a, b, c, sum;
} node;

int main() {
    int n;
    scanf("%d", &n);
    node arr[1010];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", arr[i].name, &arr[i].a, &arr[i].b, &arr[i].c);
        arr[i].sum = arr[i].a + arr[i].b + arr[i].c;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i].a - arr[j].a) <= 5 && 
                abs(arr[i].b - arr[j].b) <= 5 && 
                abs(arr[i].c - arr[j].c) <= 5 && 
                abs(arr[i].sum - arr[j].sum) <= 10
            ) {
                printf("%s %s\n", arr[i].name, arr[j].name);
            }
        }
    }
    return 0;
}