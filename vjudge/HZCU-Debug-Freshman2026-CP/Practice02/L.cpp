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
        int i = 0, j = strlen(str) - 1;
        int flag = 1;
        while (i < j) {
            i++, j--;
            if (str[i] != str[j]) {
                printf("no\n");
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("yes\n");
        }
    }
    return 0;
}