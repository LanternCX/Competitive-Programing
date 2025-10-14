#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char ch = str[i] + n;
        if (str[i] + n > 'z') {
            str[i] = ch - ('z' - 'a') - 1;
        } else {
            str[i] = ch;
        }
    }
    printf("%s", str);
    return 0;
}