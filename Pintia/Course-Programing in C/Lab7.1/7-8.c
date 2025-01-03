#include <stdio.h>

int arr1[20];
int arr2[20];
int ans[40];

int main() {
    int n1, n2;
    int idx = 0;
    
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < n1; i++) {
        int isHave = 0;
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                isHave = 1;
                break;
            }
        }
        if (!isHave) {
            for (int j = 0; j < idx; j++) {
                if (ans[j] == arr1[i]) {
                    isHave = 1;
                    break;
                }
            }
            if (!isHave) {
                ans[idx++] = arr1[i];
            }
        }
    }

    for (int i = 0; i < n2; i++) {
        int isHave = 0;
        for (int j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j]) {
                isHave = 1;
                break;
            }
        }
        if (!isHave) {
            for (int j = 0; j < idx; j++) {
                if (ans[j] == arr2[i]) {
                    isHave = 1;
                    break;
                }
            }
            if (!isHave) {
                ans[idx++] = arr2[i];
            }
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%d", ans[i]);
        if (i != idx - 1) putchar(' ');
    }
    
    return 0;
}
