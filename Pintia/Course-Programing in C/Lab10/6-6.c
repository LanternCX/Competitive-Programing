#include <stdio.h>

void printdigits( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    printdigits(n);

    return 0;
}

void printdigits(int n) {
    if (n < 10) {
        printf("%d\n", n);
        return;
    } 
    printdigits(n / 10);
    printf("%d\n", n % 10);
}