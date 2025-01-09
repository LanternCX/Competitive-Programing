#include<stdio.h>


int substring(char *s, char *t);
int main()
{
    char s[80], t[40];
    fgets(s, 80, stdin);
    fgets(t, 60, stdin);
    printf("%d\n", substring( s , t ) );

    return 0;

}
#include <string.h>
int substring(char *s, char *t){
    int res = -1;
    for(int i = 0; i < strlen(s) - strlen(t) + 1; i++){
        int tag = 1;
        for(int j = 0; j < strlen(t); j++){
            if(s[i + j] != t[j]){
                tag = 0;
                break;
            }
        }
        if(tag == 1){
            res = i + 1;
            break;
        }
    }
    return res;
}
