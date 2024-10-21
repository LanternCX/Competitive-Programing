#include<bits/stdc++.h>
using namespace std;
int a[20][20];
void solve() {
    int n, m;
    cin >> n >> m;

    // 实际值
    int x = 1, y = 1;
    // 增量
    int dx = 1, dy = 0;
    // 边界
    int top = 1, bottom = n, left = 1, right = m;

    for (int i = 1; i <= m * n; i++) {
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
        for (int j = 1; j <= m; j++) {
            printf("%2d%c", a[i][j], j == m ? '\n' : ' ');
        }
    }
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		solve();
	}
	return 0;
}