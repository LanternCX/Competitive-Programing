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

char map[] = "~!@#$%^";

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        char str[100];
        read_line(str, sizeof(str));
        if (strlen(str) < 8 || strlen(str) > 16) {
            printf("NO\n");
            continue;
        }

        int cnt[] = {0, 0, 0, 0, 0};
        for (int i = 0; i < strlen(str); i++) {
            int flag = 0;
            for (int j = 0; j < 7; j++) {
                if (str[i] == map[j]) {
                    flag = 1;
                    break;
                }
            }
            if (str[i] >= '0' && str[i] <= '9') {
                flag = 2;
            }
            if (str[i] >= 'a' && str[i] <= 'z') {
                flag = 3;
            }
            if (str[i] >= 'A' && str[i] <= 'Z') {
                flag = 4;
            }
            cnt[flag]++;
        }

        int ans = 0;
        for (int i = 1; i <= 4; i++) {
            if (cnt[i] != 0) {
                ans++;
            }
        }
        if (cnt[0] != 0) {
            printf("NO\n");
            continue;
        }
        if (ans >= 3) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}