#include <stdio.h>

struct complex{
    int real;
    int imag;
};

struct complex multiply(struct complex x, struct complex y);

int main()
{
    struct complex product, x, y;

    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n", 
            x.real, x.imag, y.real, y.imag, product.real, product.imag);
    
    return 0;
}

struct complex multiply(struct complex x, struct complex y){
    int a = x.real;
    int b = x.imag;
    int c = y.real;
    int d = y.imag;
    struct complex res = {a * c - b * d, a * d + b * c};
    return res;
}