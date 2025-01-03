#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // 读取输入的整数 n

    for (int i = 1; i <= n; i++) {
        // 打印空格
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 打印递增部分的字母
        for (int j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }

        // 打印递减部分的字母
        for (int j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        // 换行
        printf("\n");
    }

    return 0;
}
