#include <bits/stdc++.h>
using namespace std;
int a[510][510];
void slove(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    int x, y;
    int minn;
    
    for(int i = 1; i <= n; i++){
        minn = 0;
        x = i;
        y = 1;
        while (x <= n && y <= n) {
            minn = min(a[y][x], minn);
            x += 1;
            y += 1;
        }
        ans += -minn;
    }

    for(int i = 2; i <= n; i++){
        minn = 0;
        y = i;
        x = 1;
        while (x <= n && y <= n) {
            minn = min(a[y][x], minn);
            x += 1;
            y += 1;
        }
        ans += -minn;
    }

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}
/**
 * 
 1  1 -1 -1  3
-3  1  4  4 -4
-1 -1  3  0 -5
 4  5  3 -3 -1
 3  1 -3 -1  5

 -3 -3 -3 -1 -5 -4
 */