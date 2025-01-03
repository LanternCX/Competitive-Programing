#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

void ReadString(char s[]){
    int idx = 0;
    char ch;
    while ((ch = getchar()) != EOF) {
        s[idx] = ch;
        idx++;
    }
    s[++idx] = '\0';
}

void StringCount( char *s ){
    int idx = 0;
    int cnt[5] = {0, 0, 0, 0, 0};
    while (s[idx] != '\0') {
        char c = s[idx];
        if( (c >= 'A' && c <= 'Z')){
            cnt[0]++;
        }else if((c >= 'a' && c <= 'z')){
            cnt[1]++;
        }else if (c == ' ') {
            cnt[2]++;
        }else if(c >= '0' && c <= '9'){
            cnt[3]++;
        }else {
            cnt[4]++;
        }
        idx++;
    }
    for(int i = 0; i < 5; i++){
        printf("%d", cnt[i]);
        if(i != 4) putchar(' ');
    }
}