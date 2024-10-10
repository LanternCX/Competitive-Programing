#include <math.h>
#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

int narcissistic( int number ){
    int n = 0, x = 1;
    for(; number / x != 0; x *= 10, n++);
    int sum = 0, temp = number;
    for(int i = x / 10; i >= 1; i /= 10){
        int bit = number / i;
        sum += pow(bit, n);
        number %= i;
    }
    return sum == temp;
}

void PrintN( int m, int n ){
    for(int i = m + 1; i < n; i++){
        if(narcissistic(i)){
            printf("%d\n", i);
        }
    }
}