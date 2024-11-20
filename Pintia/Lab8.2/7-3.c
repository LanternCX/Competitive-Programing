#include <stdio.h>
#include <math.h>
int byteToInt(char s[], int n){
    int res = 0;
    for(int i = 7; i >= 0; i--){
        char ch = *(s + n + i);
        res += (ch - '0') * pow(2, 7 - i);
    }
    return res;
}
int main(){
    char s[100];
    scanf("%s", s);
    for(int i = 0; i < 32; i += 8){
        printf("%d", byteToInt(s, i));
        if(i != 24){
            putchar('.');
        }
    }
    return 0;
}