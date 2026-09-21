#include <stdio.h>
#include <math.h>

// caoxin

int main() {
    int x, y;
    while (1) {
        scanf("%d %d", &x , &y);
        if (x == 0 && y == 0) {
            break;
        }
        int ans = 1;
        for (int i = x; i <= y; i++) {
            int x = i * i + i + 41;
            int is_prime = 1;
            if (x <= 1) {
                is_prime = 0;
            } else {
                for (int j = 2; j < x; j++) {
                    if (x % j == 0) {
                        is_prime = 0;
                    }
                }
            }

            if (!is_prime) {
                ans = 0;
                break;
            }
        }
        if (ans) {
            printf("OK\n");
        } else {
            printf("Sorry\n");
        }
    }
    return 0;
}