#include <stdio.h>
int main(){
    int s, v;
    scanf("%d %d", &s, &v);
    int t = (s + v - 1) / v + 10;
    if (t <= 8 * 60) {
        int h = 8 - t / 60 - ((t % 60) > 0);
        int m = (60 - t % 60) % 60;
        printf("%02d:%02d", h, m);
    } else {
        t -= 8 * 60;
        int h = 24 - t / 60 - ((t % 60) > 0);
        int m = (60 - t % 60) % 60;
        printf("%02d:%02d", h, m);
    }
    return 0;
}