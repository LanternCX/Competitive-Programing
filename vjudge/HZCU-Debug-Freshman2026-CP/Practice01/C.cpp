#include <stdio.h>

#define PI 3.1415927

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        if (t <= 100 && t > 90) { 
            printf("A\n");
        } else if (t <= 89 && t > 80) {
            printf("B\n");
        } else if (t <= 79 && t > 70) {
            printf("C\n");
        } else if (t <= 69 && t > 60) {
            printf("D\n");
        } else if (t <= 59 && t >= 0) {
            printf("E\n");
        } else {
            printf("Score is error!\n");
        }
    }   
    return 0;
}