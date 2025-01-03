#include <stdio.h>
int a[100][100];
void slove(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int tag = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(a[j][i] != 0){
                tag = 0;
            }
        }
    }
    printf("%s", tag ? "YES\n" : "NO\n");
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        slove();
    }
    return 0;
}