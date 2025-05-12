#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

void sol() {
    int n;
    cin >> n;

    vector<vector<int>> ans(n, vector<int>(n));

    int tot = n * n;
    int x = n / 2;
    int y = n / 2;
    int now = 0;
    
    // place 0 at center
    if(x >= 0 && x < n && y >= 0 && y < n){
        ans[x][y] = now++;
    }

    int cnt = 1;
    
    while(now < tot){
        for(int i = 0; i < cnt && now < tot; i++){
            y--;
            if(x >= 0 && x < n && y >= 0 && y < n){
                ans[x][y] = now++;
            }
        }
        for(int i = 0; i < cnt && now < tot; i++){
            x--;
            if(x >= 0 && x < n && y >= 0 && y < n){
                ans[x][y] = now++;
            }
        }

        cnt++;
        for(int i = 0; i < cnt && now < tot; i++){
            y++;
            if(x >= 0 && x < n && y >= 0 && y < n){
                ans[x][y] = now++;
            }
        }
        for(int i = 0; i < cnt && now < tot; i++){
            x++;
            if(x >= 0 && x < n && y >= 0 && y < n){
                ans[x][y] = now++;
            }
        }

        cnt++;
    }

    for(auto &row : ans){
        for(auto x : row){
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 12 13 14 15 
11 6 7 8 
10 5 0 1 
9 4 3 2 

12 13 14 15   
11 2 3 4
10 1 0 5 
9 8 7 6
 */