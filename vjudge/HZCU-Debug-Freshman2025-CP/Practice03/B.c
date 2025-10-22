#include <stdio.h>
#include <math.h>

typedef struct {
    char name[1000];
    int age, sc;
} node;

int main() {
    int n;
    scanf("%d", &n);
    node arr[10];
    for (int i = 0; i < n; i++) {
        char name[1000];
        int age, sc;
        scanf("%s %d %d", arr[i].name, &arr[i].age, &arr[i].sc);
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", arr[i].name, arr[i].age + 1, (int)fmin(arr[i].sc * 1.2, 600));
    }
    return 0;
}