#include <stdio.h>
int ans[3];

int main(){
    while(1){
        char ch = getchar();
        if(ch == '\n'){
            break;
        }

        if (ch == ' ') {
            ans[0]++;
        }else if (ch >= '0' && ch <= '9') {
            ans[1]++;
        }else {
            ans[2]++;
        }
    }
    printf("blank = %d, digit = %d, other = %d", ans[0], ans[1], ans[2]);
    return 0;
}