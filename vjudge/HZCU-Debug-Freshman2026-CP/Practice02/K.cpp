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

char map[] = "aeiou";

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        char str[100];
        readLine(str, sizeof(str));
        int count[5] = {0, 0, 0,0,0 };
        for (int i = 0; i < strlen(str); i++) {
            for (int j = 0; j < 5; j++) {
                count[j] += str[i] == map[j] ? 1 : 0;
            }
        }
        for (int i = 0; i < 5; i++) {
            printf("%c:%d\n", map[i], count[i]);
        }
        printf("\n");
    }
    return 0;
}