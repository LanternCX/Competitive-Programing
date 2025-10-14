#include <stdio.h>
char map[5][50] = {
    "XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX",
    "X.X...X...X...X.X.X.X...X.....X.X.X.X.X",
    "X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX",
    "X.X...X.X.....X...X...X.X.X...X.X.X...X",
    "XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX",
};


int main() {
    int n;
    scanf("%d", &n);
    char str[1000];
    scanf("%s", str);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        arr[i] = str[i] - '0';
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            int num = arr[j];
            int idx = num * 4;
            if (j > 0) {
                printf(".");
            }
            for (int k = idx; k < idx + 3; k++) {
                printf("%c", map[i][k]);
            }
        }
        printf("\n");
    }
    return 0;
}