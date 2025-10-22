
#include <stdio.h>

int mp[110][110];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch = '\n';
            while (ch != '*' && ch != '?') {
                scanf("%c", &ch);
            }

            if (ch != '*') {
                continue;
            }
            mp[i][j] = -1;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (i + x < 0 || j + y < 0) {
                        continue;
                    }
                    if (mp[i + x][j + y] == -1) {
                        continue;
                    }
                    mp[i + x][j + y]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == -1) {
                printf("*");
            } else {
                printf("%d", mp[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}