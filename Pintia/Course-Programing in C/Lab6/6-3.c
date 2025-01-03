#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );
    
int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}

int factorsum( int number ){
    int res = 0;
    for(int i = 1; i < number; i++) if(number % i == 0) res += i;
    return res;
}

void PrintPN( int m, int n ){
    int isHave = 0;
    for(int i = m; i <= n; i++){
        if(factorsum(i) == i){
            isHave = 1;
            printf("%d = ", i);
            int is = 0;
            for(int j = 1; j < i; j++){
                if (i % j == 0) {
                    if (is) {
                        printf(" + ");
                    }
                    printf("%d", j);
                    is = 1;
                }
            }
            printf("\n");
        }
    }
    if(!isHave){
        printf("No perfect number");
    }
}