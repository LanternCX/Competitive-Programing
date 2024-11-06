#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    for(int i = len - 1; i >= 0; i--){
        char ch = s[i];
        if(ch != '\n'){
            printf("%c", ch);
        }
    }
    return 0;
}