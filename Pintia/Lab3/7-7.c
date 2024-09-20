#include <stdio.h>
int main(){
    int a, b;
    char c;
    scanf("%d %d %c", &a, &b, &c);
    double per;
    switch (b) {
        case 90:
            per = 6.95;
            break;
        case 93:
            per = 7.44;
            break;
        case 97:
            per = 7.93;
            break;
    }
    double ans = 1.0 * a * per * (c == 'm' ? 0.95 : 0.97);
    printf("%0.2lf", ans);
    return 0;
}