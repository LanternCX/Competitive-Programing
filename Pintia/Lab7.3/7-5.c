#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    char dict1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char dict2[] = "abcdefghijklmnopqrstuvwxyz";
    char s[100];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    int x;
    scanf("%d", &x);
    x %= 26;
    for(int i = 0; i < len; i++){

        if(s[i] >= 'a' && s[i] <= 'z'){
            if(x >= 0){
                for(int j = 0; j < x; j++){
                    if(++s[i] > 'z'){
                        s[i] = 'a';
                    }
                }
            }
            if(x < 0){ 
                for(int j = 0; j < fabs((double)x); j++){
                    if(--s[i] < 'a'){
                        s[i] = 'z';
                    }
                }
            }
        }

        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(x >= 0){
                for(int j = 0; j < x; j++){
                    if(++s[i] > 'Z'){
                        s[i] = 'A';
                    }
                }
            }
            if(x < 0){
                for(int j = 0; j < fabs((double)x); j++){
                    if(--s[i] < 'A'){
                        s[i] = 'Z';
                    }
                }
            }
        }
    }

    printf("%s", s);
    return 0;
}