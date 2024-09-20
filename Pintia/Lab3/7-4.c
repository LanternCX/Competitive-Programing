#include <stdio.h>
int ans[4];
int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char c = getchar();
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            ans[0]++;
        }else if (c == ' ' || c == '\n') {
            ans[1]++;
        }else if(c >= '0' && c <= '9'){
            ans[2]++;
        }else {
            ans[3]++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", ans[0], ans[1], ans[2], ans[3]);
    return 0;
}