#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Not triangle\n");
        return 0;
    }
    int mn = fmin(a, fmin(b, c));
    int mx = fmax(a, fmax(b, c));
    int mid = a + b + c - mn - mx;
    if (mn * mn + mid * mid > mx * mx) {
        printf("Acute triangle\n");
    }
    if (mn * mn + mid * mid == mx * mx) {
        printf("Right triangle\n");
    }
    if (mn * mn + mid * mid < mx * mx) {
        printf("Obtuse triangle\n");
    }
    if (a == b || b == c || a == c) {
        printf("Isosceles triangle\n");
    }
    if (a == b && b == c) {
        printf("Equilateral triangle\n");
    }
    return 0;
}