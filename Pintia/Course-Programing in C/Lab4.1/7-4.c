#include <stdio.h>
int main(){
    int ans1 = 0;
    int ans2 = 0;
    while (1) {
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
        ans1++;
        ans2 += ch - '0';
    }
    printf("%d %d", ans1, ans2);
    return 0;
}