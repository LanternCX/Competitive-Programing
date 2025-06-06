#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    fgets(str, sizeof(str), stdin);
    delchar(str, c);
    printf("%s\n", str);
    
    return 0;
}

void delchar(char *str, char c) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != c) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}