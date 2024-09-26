#include <stdio.h>
int main(){
    double n;
    scanf("%lf", &n);
    double rate;
    if (n <= 1600) {
        rate = 0;
    }
    if (n > 1600 && n <= 2500) {
        rate = 5e-2;
    }
    if (n > 2500 && n <= 3500){
        rate = 10e-2;
    }
    if (n > 3500 && n <= 4500) {
        rate = 15e-2;
    }
    if (n > 4500) {
        rate = 20e-2;
    }
    if (n <= 1600) {
        printf("0.00");
        return 0;
    }
    printf("%.2lf", rate * (n - 1600));
    return 0;
}