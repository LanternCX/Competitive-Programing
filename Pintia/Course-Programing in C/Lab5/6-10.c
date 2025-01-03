#include <stdio.h>

void hollowPyramid ( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    hollowPyramid ( n );

    return 0;
}

void hollowPyramid( int n ){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++){
            printf(" ");
        }
        if(i != 1) printf("%d", i);
        for(int j = 0; j < 2 * (i - 1) - 1; j++){
            printf(" ");
        }
        printf("%d\n", i);
    }
    for(int i = 0; i < 2 * n - 1; i++){
        printf("%d", n);
    }
}