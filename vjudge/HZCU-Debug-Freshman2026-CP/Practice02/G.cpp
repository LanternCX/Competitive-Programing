#include <string.h>
#include <stdio.h>

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
    int n;
    scanf("%d\n", &n);
    getchar();

    while (n--) {
        char str[100];
        readLine(str, sizeof(str));
        int cnt = 0;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] >= '0' && str[i] <= '9' && i != 0) {
                cnt++;
            }
            if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
                cnt++;
            }
            if (str[i] == '_') {
                cnt++;
            }
        }
        printf(cnt != strlen(str) ? "no\n" : "yes\n"); 
    }
    return 0;
}