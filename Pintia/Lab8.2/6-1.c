#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char t[MAXN], s[MAXN];
    int m;
    
    scanf("%d\n", &m);
    ReadString(t);
    
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

void ReadString(char s[]){
    int idx = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        s[idx] = ch;
        idx++;
    }
    s[++idx] = '\0';
}

void strmcpy( char *t, int m, char *s ){
    // printf("test: %s\n", t);
    int idx = m - 1;
    int idx0 = 0;
    while(t[idx] != '\0'){
        s[idx0] = t[idx];
        idx++;
        idx0++;
    }
    s[idx0] = '\0';
}
