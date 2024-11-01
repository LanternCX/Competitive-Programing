#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int a[10][10];

    a[0][0] = 1;

    for (int i = 0; i < N; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
