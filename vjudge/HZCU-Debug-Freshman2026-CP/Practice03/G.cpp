#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// caoxin

void read_line(char s[], int size) {
    int i = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < size - 1) {
            s[i++] = (char)c;
        }
    }

    s[i] = '\0';
}

void print(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        putchar(str[i]);
    }
    putchar('\n');
}

int main() {
    char str[100];
    while (scanf("%c", &str[0]) != EOF) {
        read_line(str + 1, sizeof(str) - 1);
        char * p = str;
        while (*p != '\0') {
            if (p == str || *(p - 1) == ' ') {
                *p += 'A' - 'a'; 
            }
            p++;
        }
        print(str);
    }
    return 0;
}