#include <stdio.h>

// LanternCX
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    // a > b 就交换 a b 的值
  	if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // 第一次交换后，如果 b > c，就交换 b c 的值 
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    // 前两次交换后，如果 a > b，就交换 a b 的值
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    printf("%d %d %d", a, b, c);
  	return 0;
}
