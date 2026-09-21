#include <stdio.h>
#include <math.h>

// caoxin

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", 3 * (int) pow(2, n - 1) - 2);
    }
    return 0;
}

// A(x + 1) = A(x) / 2 - 1
// 2 * A(x + 1) + 2 = A(x)
// A(n) = 1
// B(x) = A(x) + 2
// B(x + 1) = A(x + 1) + 2
// 
// 2B(x + 1) = B(x)
// B(n) = 3