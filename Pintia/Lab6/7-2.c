#include <stdio.h>

int main() {
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + 1) % 26 + 'A';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + 1) % 26 + 'a';
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}