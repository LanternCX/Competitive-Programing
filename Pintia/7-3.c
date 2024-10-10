#include <stdio.h>
int main(){
    char ch, temp = ' ';
    while ((ch = getchar()) != '\n') {
        if(temp == ' ' && ch <= 'z' && ch >= 'a'){
            putchar('A' + ch - 'a');
        }else {
            putchar(ch);
        }
        temp = ch;
    }
    return 0;
}