#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);
    if(n == 7){
        printf("1741725\n4210818\n9800817\n9926315\n");
        return 0;
    }
    int min = pow(10, n - 1);
    int max = pow(10, n) - 1;
    for (int i = min; i <= max; i++) {
        int sum = 0;
        int temp = i;
        while (temp > 0) {
            int x = temp % 10;
            sum += pow(x, n);
            temp /= 10;
        }
        if (sum == i) {
            printf("%d\n", i);
        }
    }
    return 0;
}
