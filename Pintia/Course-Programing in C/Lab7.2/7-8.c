#include<stdio.h>
int a[20][20];
int main(){
	int n;
    scanf("%d", &n);

    // 实际值
    int x = 1, y = 1;
    // 增量
    int dx = 1, dy = 0;
    // 边界
    int top = 1, bottom = n, left = 1, right = n;

    for (int i = 1; i <= n * n; i++) {
        a[y][x] = i;

        if (dx == 1 && x == right) {
            dx = 0; 
            dy = 1; 
            top++;
        } else if (dy == 1 && y == bottom) {
            dx = -1; 
            dy = 0; 
            right--;
        } else if (dx == -1 && x == left) {
            dx = 0; 
            dy = -1; 
            bottom--;
        } else if (dy == -1 && y == top) {
            dx = 1; 
            dy = 0; 
            left++;
        }

        x += dx;
        y += dy;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
	return 0;
}