#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;
    
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

#include <string.h>
char *match( char *s, char ch1, char ch2 ){
    int tag = 0;
    int idx = 0;
    char * ans = NULL;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == ch1){
            tag = 1;
            if(ans == NULL){
                ans = s + i;
            }
        }
        if(tag){
            printf("%c", s[i]);
            idx++;
        }
        if(s[i] == ch2){
            tag = 0;
            break;
        }
    }
    if(ans == NULL){
        ans = "\n";
    }else{
        printf("\n");
    }
    return ans;
}