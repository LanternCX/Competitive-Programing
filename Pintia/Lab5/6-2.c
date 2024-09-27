#include <stdio.h>

int sign( int x );

int main()
{
    int x;

    scanf("%d", &x);
    printf("sign(%d) = %d\n", x, sign(x));
    
    return 0;
}

int sign( int x ){
    return x > 0 ? x == 0 ? 0 : 1 : x == 0 ? 0 : -1;
}