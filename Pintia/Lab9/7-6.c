#include <stdio.h>
#include <math.h>

struct node {
    double x, y;
};

int main() {
    struct node arr[2];
    for (int i = 0; i < 2; i++) {
        scanf("%lf %lf", &arr[i].x, &arr[i].y);
    }

    double a = arr[0].x + arr[1].x;
    double b = arr[0].y + arr[1].y;

    if(a > -0.05 && a < 0){
        a = 0;
    }

    if(b > -0.05 && b < 0){
        b = 0;
    }
    
    printf("(%.1lf, %.1lf)", a, b);
    return 0;
}
