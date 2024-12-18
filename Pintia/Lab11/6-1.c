#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s );

int main()
{
    int n;
    char s[MAXS];
    
    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);

    return 0;
}

int getindex( char *s ){
    const char * list[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday0"};
    for(int i = 0; i < 7; i++){
        int tag = 1;
        for(int j = 0; j < strlen(s); j++){
            if(list[i][j] != s[j]){
                tag = 0;
                break;
            }
        }
        if(tag){
            return i;
        }
    }
    return -1;
}

