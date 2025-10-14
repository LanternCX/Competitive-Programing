#include <stdio.h>
#include <string.h>

int main() {
	int n;
    scanf("%d", &n);
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] + n > 'z') {
            str[i] = str[i] + n - ('z' - 'a') - 1;
        } else {
            str[i] = str[i] + n;
        }
    }
    printf("%s", str);
	return 0;
}