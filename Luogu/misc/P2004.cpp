#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int maxn = -1e9;
    int x, y;
    for(int i = 1; i <= n - (c - 1);i++){
        for(int j = 1; j <= m - (c - 1); j++){
            int sum = a[i + c - 1][j + c - 1] - a[i - 1][j + c - 1] - a[i + c - 1][j - 1] + a[i - 1][j - 1];  
            if(sum > maxn){
                maxn = sum;
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y;
    return 0;
}