#include <stdio.h>

int reverse( int number );
    
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

int reverse(int number) {
    int temp = number > 0 ? number : -number, res = 0; 
    for(; temp > 0; temp /= 10) res = res * 10 + temp % 10;
    return number > 0 ? res : -res;
}