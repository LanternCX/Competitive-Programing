#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double x;
    while (scanf("%lf", &x) != EOF) {
        printf("%.2lf\n", abs(x));
    }
    return 0;
}