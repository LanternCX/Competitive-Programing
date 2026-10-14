#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

// caoxin

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        double ans = 0;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            ans += 1.0 / i * (i % 2 == 0 ? -1 : 1);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}