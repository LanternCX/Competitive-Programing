#include <stdio.h>

#define G 10
int main(){
    double t = 3;
    double h = 0.5 * G * t * t;
    printf("height = %.2lf", h);
    return 0;
}