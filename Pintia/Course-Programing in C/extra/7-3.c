#include <stdio.h>

char* dict1[] = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};
char* dict2[] = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"};

void calc(int y) {
    int diff = y - 1984;

    int a = (diff % 10 + 10) % 10; 
    int b = (diff % 12 + 12) % 12;
    printf("%s%s\n", dict1[a], dict2[b]);
}

int main() {
    int T, year;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &year);
        calc(year);
    }

    return 0;
}
