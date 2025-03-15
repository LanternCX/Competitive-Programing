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
struct node{
    int x, y, h, w;
};
void sol(){
    int n;
    int x1, y1;
    cin >> n >> x1 >> y1;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    vector<node> ans;
    int x2 = y1, y2 = x1;
    debug(x1, y1, x2, y2);
    for(int i = min(x1, x2); i <= max(x1, x2); i++){
        for(int j = min(y1, y2); j <= max(y1, y2); j++){
            mp[i][j] = 1;
        }
    }
    auto work = [&](int x, int y, int h, int w){
        ans.push_back({x, y, h, w});
    };
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << mp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << "Yes\n";
    {
        int cnt = 1;
        int tag = x1 < y1 ? -1 : 1;
        while (x1 != x2 && y1 != y2) {
            debug(x1, y1);
            x1 += x1 < x2 ? 1 : -1;
            y1 += y1 < y2 ? 1 : -1;
            cnt++;
            work(x1, y1, tag * (cnt - 1), -tag * (cnt - 1));
        }
    }
    
    {
        int cnt = n;
        int x = 0, y = 0;
        while(1){
            x++;
            y++;
            if(mp[x][y] == 1){
                break;
            }
            work(x, y, cnt - 1, cnt - 1);
            cnt--;
        }

        cnt = n - (n - cnt);
        x = n + 1, y = n + 1;
        while(1){
            x--;
            y--;
            if(mp[x][y] == 1){
                break;
            }
            work(x, y, -(cnt - 1), -(cnt - 1));
            cnt--;
        }
    }
    cout << ans.size() << '\n';
    for(auto [x, y, h, w] : ans){
        cout << x << ' ' << y << ' ' << h << ' ' << w << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}