#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

// caoxin

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int a[100] = {0};
        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1] + 2;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            if (i % m == 0) {
                printf("%d ", sum / m);
                sum = 0;
            }
        }
        if (n % m != 0) {
            printf("%d ", sum / (n % m));
        }
        printf("\n");
    } 
    return 0;
}