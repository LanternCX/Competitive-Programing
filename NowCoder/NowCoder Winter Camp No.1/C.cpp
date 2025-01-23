#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char x;
            cin >> x;
            mp[i][j] = x - '0';
        }
    }
    vector<array<int, 4>> ans;
    auto step = [&](int x0, int y0, int x1, int y1) -> void {
        swap(mp[x1][y1], mp[x0][y0]);
        ans.push_back({x0, y0, x1, y1});
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         cout << mp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    };
    auto move = [&](int x0, int y0, int x1, int y1) -> void {
        auto movex = [&](){
            while(x0 < x1){
                step(x0, y0, x0 + 1, y0);
                x0++;
            }
            while(x0 > x1){
                step(x0, y0, x0 - 1, y0);
                x0--;
            }
        };
        auto movey = [&]() {
            while(y0 < y1){
                step(x0, y0, x0, y0 + 1);
                y0++;
            }
            while(y0 > y1){
                step(x0, y0, x0, y0 - 1);
                y0--;
            }
        };
        if(x0 >= x1){
            movey();
            movex();
        }else {
            movex();
            movey();
        }
    };
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            while(mp[i][j] == 1){
                move(i, j, x, y);
                mp[x][y] = -1;
                y++;
                if(y == n / 2){
                    y = 0;
                    x++;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto p : ans){
        cout << p[0] + 1 << ' ' << p[1] + 1 << ' ' << p[2] + 1 << ' ' << p[3] + 1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}