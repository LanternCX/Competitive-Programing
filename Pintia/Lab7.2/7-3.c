#include <stdio.h>
int isRun(int n){
    return n % 4 == 0 && n % 100 != 0 || n % 400 == 0;
}
int main(){
    int y, m, d;
    int day[20] = {0, 31,28, 31, 30, 31,30,31, 31, 30,31, 30, 31};
    scanf("%d/%d/%d", &y, &m, &d);
    int ans = d;
    for(int i = 1; i < m; i++){
        int x = day[i];
        ans += x;
    }
    if(m > 2){
        if(isRun(y)){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}