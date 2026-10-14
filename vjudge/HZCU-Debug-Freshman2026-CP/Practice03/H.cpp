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

char map[] = "aeiou";

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        char str[100];
        read_line(str, sizeof(str));
        char * p = str;
        int cnt[] = {0, 0, 0, 0, 0};
        while (*p != '\0') {
            for (int i = 0; i < 5; i++) {
                cnt[i] += *p == map[i];
            }
            p++;
        }

        for (int i = 0; i < 5; i++) {
            printf("%c:%d\n", map[i], cnt[i]);
        }

        printf("\n");
    }
    return 0;
}