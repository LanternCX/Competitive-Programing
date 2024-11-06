#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    int ans = 0;
    for(int i = 0; i < len; i++){
        char ch = s[i];
        if(ch >= 'A' && ch <= 'Z' && ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U'){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}