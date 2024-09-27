#include <stdio.h>

int CountDigit( int number, int digit );
    
int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));
    
    return 0;
}

int CountDigit( int number, int digit ){
    int temp = number <= 0 ? -1 * number : number;
    int n = 1;
    for(int i = 1; ; i *= 10){
        if(temp - i <= 0){
            n = i;
            break;
        }
    }
    int res = 0;
    while (temp > 0) {
        n /= 10;
        res = temp / n == digit ? res + 1: res;
        temp %= n;
    }

    if (number == digit && number == 0) {
        res = 1;
    }
    return res;
}