#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    char s[100];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    int tag = 0;
    int x = 1;
    int idx = -1;
    char hex[100];
    for(int i = 0; i < len; i++){
        char ch = s[i];
        if(ch == '-' && idx == -1){
            x = -1;
        }
        if(ch >= 'A' && ch <= 'F'){
            ch -= 'A' - 'a';
        }
        if(ch >= 'a' && ch <= 'f' || ch >= '0' && ch <= '9'){
            hex[tag] = ch;
            idx = idx == -1 ? i : idx;
            tag++;
        }
    }
    int digit = 1;
    int ans = 0;
    for(int i = tag - 1; i >= 0; i--){
        char ch = hex[i];
        if(ch >= 'a' && ch <= 'f'){
            ans += (ch - 'a' + 10) * pow(16, digit - 1); 
        }else{
            ans += (ch - '0') * pow(16, digit - 1); 
        }
        digit++;
    }
    printf("%d", ans * x);
    return 0;
}