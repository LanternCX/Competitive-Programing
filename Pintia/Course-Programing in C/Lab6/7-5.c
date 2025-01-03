#include <stdio.h>
int ans[1000];
int main(){
    char ch, temp;
    int n = 0, i = 0;
    while((ch = getchar()) != '\n'){
        if(ch == ' '){
            ans[i] = n;
            n = 0;
            i++;
            continue;
        }
        n++;
    }
    ans[i] = n;
    int is0 = 1;
    for(int j = 0; j <= i; j++){
        if(ans[j] != 0) {
            printf("%d ", ans[j]);
            is0 = 0;
        }
    }
    if (is0) {
        printf("0 ");
    }
    return 0;
}