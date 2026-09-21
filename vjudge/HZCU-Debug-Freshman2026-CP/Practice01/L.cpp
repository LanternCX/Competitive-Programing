#include <stdio.h>
#include <math.h>

// caoxin

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            while (x - 100 >= 0) {
                x -= 100;
                ans++;
            }
            while (x - 50 >= 0) {
                x -= 50;
                ans++;
            }
            while (x - 10 >= 0) {
                x -= 10;
                ans++;
            }
            while (x - 5 >= 0) {
                x -= 5;
                ans++;
            } 
            while (x - 2 >= 0) {
                x -= 2;
                ans++;
            }
            while (x - 1 >= 0) {
                x -= 1;
                ans++;
            }
        }
        printf("%d", ans);
    }
    return 0;
}
