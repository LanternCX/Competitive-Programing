#include <stdio.h>
int main(){
    char s[100];
    fgets(s, 100, stdin);
    int l, r;
    scanf("%d %d", &l, &r);
    for(int i = l - 1; i <= r; i++){
        printf("%c", s[i]);
    }
    return 0;
}