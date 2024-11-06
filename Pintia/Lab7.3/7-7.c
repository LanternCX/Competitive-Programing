#include <stdio.h>
#include <string.h>
int set[30];
int main(){
    char s[100];
    fgets(s, 100, stdin);
    int len = strlen(s);
    int tag = 0;
    char ans[100];
    for(int i = 0; i < len; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            int is = 0;
            for(int j = 0; j < strlen(ans); j++){
                if(ans[j] == s[i]){
                    is = 1;
                    break;
                }
            }
            if(!is){
                ans[tag] = s[i];
                tag++;
            }
        }
    }
    if(tag){
        for(int i = 0; i < tag; i++){
            printf("%c", ans[i]);
        }
    }else {
        printf("Not Found");
    }
    return 0;
}