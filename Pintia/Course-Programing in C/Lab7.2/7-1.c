#include <stdio.h>
#include <stdlib.h>
int arr[100][100];
int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[m][n]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int a = arr[min(i + 1, m)][j];
            int b = arr[max(i - 1, 0)][j];
            int c = arr[i][min(j + 1, n)];
            int d = arr[i][max(j - 1, n)];
            scanf("%d", &arr[m][n]);
        }
    }
    return 0;
}