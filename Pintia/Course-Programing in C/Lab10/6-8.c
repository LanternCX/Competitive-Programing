#include <stdio.h>
# include <math.h>

unsigned int reverse( unsigned int number );

int main()
{
    unsigned int n;

    scanf("%u", &n);
    printf("%u\n", reverse(n));

    return 0;
}

#include <math.h>

int length(unsigned int num) {
    if (num == 0) return 1;
    return (int)log10(num) + 1;
}
unsigned int reverse(unsigned int number ) {
    if (number  < 10) {
        return number ;
    }

    int len = length(number );
    return (number  % 10) * pow(10, len - 1) + reverse(number  / 10);
}
