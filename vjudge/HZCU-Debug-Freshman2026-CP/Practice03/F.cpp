#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// caoxin

typedef struct {
    int h, m, s;
} Time;

Time add(Time a, Time b) {
    int s = a.s + b.s;
    int m = s / 60 + a.m + b.m;
    int h = m / 60 + a.h + b.h;
    Time ans = {s % 60, m % 60, h};
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        Time a, b;
        scanf("%d %d %d %d %d %d", &a.h, &a.m, &a.s, &b.h, &b.m, &b.s);
        Time ans = add(a, b);
        printf("%d %d %d\n", ans.s, ans.m, ans.h);
    }
    return 0;
}