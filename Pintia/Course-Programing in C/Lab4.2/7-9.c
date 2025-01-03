#include <stdio.h>
#include <math.h>

int isPrime(long long num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;  
    scanf("%d", &n);  
    for (int p = 2; p <= n / 2; p++) {
        if (isPrime(p)) {
            int q = n - p;
            if (isPrime(q)) {
                printf("%d = %d + %d\n", n, p, q);
                break;
            }
        }
    }
    return 0;
}
