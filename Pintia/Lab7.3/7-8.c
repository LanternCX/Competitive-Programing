#include <stdio.h>
#include <string.h>
int dict[200];
int main(){
    char s[100];
    fgets(s, 100, stdin);
    for(int i = 0; i < strlen(s); i++){
        dict[s[i]]++;
    }
    for(int i = 0; i < 200; i++){
        if(dict[i] && i != '\n'){
            putchar(i);
        }
    }
    return 0;
}