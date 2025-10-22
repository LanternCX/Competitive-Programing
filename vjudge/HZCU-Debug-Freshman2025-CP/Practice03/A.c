#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", (1 << (n - 1)) * 3 - 2);
    return 0;
}
/**
 * 1
 * (1 + 1) * 2
 * (((1 + 1) * 2) + 1) * 2
 * 
 */