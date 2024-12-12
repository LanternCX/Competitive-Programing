#include <stdio.h>
struct time{
    int h, m, s;
};

int main(){
    struct time t;
    scanf("%d:%d:%d", &t.h, &t.m, &t.s);
    int n;
    scanf("%d", &n);
    t.s += n;
    t.m += t.s / 60;
    t.s %= 60;
    t.h += t.m / 60;
    t.m %= 60;
    t.h %= 24;
    printf("%02d:%02d:%02d", t.h, t.m, t.s);
    return 0;
}