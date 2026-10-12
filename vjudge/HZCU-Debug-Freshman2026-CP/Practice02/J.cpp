#include <string.h>
#include <stdio.h>
#include <math.h>

void readLine(char s[], int size) {
    int i = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < size - 1) {
            s[i++] = (char)c;
        }
    }

    s[i] = '\0';
}

int main() {
    char str[100];
    while (scanf("%c", &str[0]) != EOF) {
        readLine(str + 1, sizeof(str) - 1);
        for (int i = 0; i < strlen(str); i++) {
            int flag = 0;
            if (str[i] >= 'a' && str[i] <= 'z') {
                if (i == 0) {
                    flag = 1;
                } else if (str[i - 1] == ' ') {
                    flag = 1;
                }

                if (flag) {
                    str[i] += 'A' - 'a';
                }
            }
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}