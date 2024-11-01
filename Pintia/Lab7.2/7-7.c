#include <stdio.h>
int a[10][10];
int c[10];
int r[10];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int max = -1e7;
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
            max = max > a[i][j] ? max : a[i][j];
        }
        r[i] = max;
    }
    for(int i = 0; i < n; i++){
        int min = 1e7;
        for(int j = 0; j < n; j++){
            min = min < a[j][i] ? min : a[j][i];
        }
        c[i] = min;
    }

    int is = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(r[i] == c[j]){
                printf("%d %d\n", i , j);
                is = 1;
            }
        }
    }
    if(!is){
        printf("NONE");
    }
    return 0;
}