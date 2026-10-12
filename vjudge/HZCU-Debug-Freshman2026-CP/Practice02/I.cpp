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
        char max = '\0';
        for (int i = 0; i < strlen(str); i++) {
            max = fmax(str[i], max);
        }
        for (int i = 0; i < strlen(str); i++) {
            printf("%c", str[i]);
            if (str[i] == max) {
                printf("(max)");
            }
        }
        printf("\n");
    }
    return 0;
}
