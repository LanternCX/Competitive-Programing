#include <stdio.h>
#include <string.h>

void copy(char *t, char *s) {
    while ((*s++ = *t++) != '\0');
}

int cmp(char *a, char *b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int len = len1 < len2 ? len1 : len2;
    for (int i = 0; i < len; i++) {
        if(a[i] == b[i]) continue;
        return a[i] > b[i];
    }
    return len1 < len2;
}

void swap(char a[], char b[]){
    char temp[1000];
    copy(a, temp);
    copy(b, a);
    copy(temp, b);
}

void sort(char strings[][1000], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(strings[i], strings[j])) {
                swap(strings[i], strings[j]);
            }
        }
    }
}

int main() {
    char strings[5][1000];
    for (int i = 0; i < 5; i++) {
        scanf("%s", strings[i]);
    }
    sort(strings, 5);
    printf("After sorted:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", strings[i]);
    }
    return 0;
}
