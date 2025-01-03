#include <stdio.h>

int sum( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printf ("%d\n", sum(n));

    return 0;
}

int sum(int n){
    if(n == 1){
        return 1;
    }
    if(n <= 0){
        return 0;
    }
    return sum(n - 1) + n;
}