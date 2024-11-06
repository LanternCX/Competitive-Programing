#include <stdio.h>
#include <string.h>
int main(){
    char c;
    scanf("%c\n", &c);
    char s[100];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    int idx = -1;
    for(int i = len - 1; i >= 0; i--){
        char ch = s[i];
        if(ch == c){
            idx = i;
            break;
        }
    }
    if(idx != -1){
        printf("index = %d", idx);
    }else{
        printf("Not Found");
    }
    return 0;
}