
#include <stdio.h>

int main() {
    int n;
    int idx = 0;
    long long sum = 0;
    while(scanf("%d", &n) != EOF) {
        sum += n;
        idx++;
    }
    printf("%lld", sum * (1 << (idx - 1)));
    return 0;
}
/**
 * [1 2] 3 4
 * 1 [2 3] 4
 * 1 2 [3 4]
 * 1 2 3 4
 * 
 * 1 2
 * 1 3
 * 1 4
 * 2 3
 * 2 4
 * 3 4
 * 
 * (1 + 2 + 3 + 4) * 3
 * 
 * 1 2 3 4 * 1
 * 
 * 1 2 3
 * 1 2 4
 * 1 3 4
 * 2 3 4
 * 
 */