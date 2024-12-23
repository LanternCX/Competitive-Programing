#include <stdio.h>
int main(){
    double n;
    scanf("%lf", &n);
    double ans;
    if(n <= 200){
        ans = n * 3.5;
    }else if(n > 200 && n <= 350) {
        ans = 200 * 3.5 + (n - 200) * 4.25;
    }else if(n > 350) {
        ans = 200 * 3.5 + (350 - 200) * 4.25 + (n - 350) * 5.00;
    }
    printf("%.2lf", ans);
    return 0;
}