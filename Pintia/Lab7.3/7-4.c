#include <stdio.h>
#include <string.h>
int main(){
    // ABCDEFGHIJKLMNOPQRSTUVWXYZ
    // abcdefghijklmnopqrstuvwxyz
    char dict1[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char s[100];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        char ch = s[i];
        if(ch >= 'A' && ch <= 'Z'){
            s[i] = dict1[ch - 'A'];
        }
    }
    printf("%s", s);
    return 0;
}