#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat( char *s, char *t );

int main()
{
    char *p;
    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};
    
    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);
    
    return 0;
}

char *str_cat( char *s, char *t ){
    unsigned int len1 = strlen(s);
    unsigned int len2 = strlen(t);
    for(int i = len1; i < len1 + len2; i++){
        s[i] = t[i - len1];
    }
    s[len1 + len2] = '\0';
    return s;
}