#include <stdio.h>
int main(){
    char op;
    double ans = 0;
    while(scanf("%c", &op)){
        if(op == 'n'){
            break;
        }
        if(op == 'c'){
            double r;
            scanf("%lf", &r);
            ans += 3.14 * r * r;
        }
        if(op == 'r'){
            double a, b;
            scanf("%lf%lf", &a, &b);
            ans += a * b;
        }
    }
    printf("%.2lf", ans);
    return 0;
}