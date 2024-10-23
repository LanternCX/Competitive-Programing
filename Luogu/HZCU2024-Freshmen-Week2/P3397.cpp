#include <bits/stdc++.h>
using namespace std;
int maps[1010][1010];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++){
                maps[i][j]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << maps[i][j] << (j == n ? '\n' : ' ');
        }
    }
    return 0;
}