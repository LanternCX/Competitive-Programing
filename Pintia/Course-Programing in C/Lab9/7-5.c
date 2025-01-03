#include <stdio.h>
struct node{
    int a, b;
    double val;
};
int main(){
    struct node x[2];
    for(int i = 0; i < 2; i++){
        scanf("%d/%d", &x[i].a, &x[i].b);
        x[i].val = x[i].a * 1.0 / x[i].b * 1.0;
    }
    if(x[0].val > x[1].val){
        printf("%d/%d > %d/%d", x[0].a, x[0].b, x[1].a, x[1].b);
    }
    if(x[0].val < x[1].val){
        printf("%d/%d < %d/%d", x[0].a, x[0].b, x[1].a, x[1].b);
    }
    if(x[0].val == x[1].val){
        printf("%d/%d = %d/%d", x[0].a, x[0].b, x[1].a, x[1].b);
    }
    return 0;
}