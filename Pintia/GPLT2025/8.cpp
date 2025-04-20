#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int v, x, y;
};
void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mp(n, vector<int>(m));
    vector<int> visx(n), visy(m);
    auto id = [&](int i, int j){
        return i * n + j;
    };
    vector<node> a;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
            a.push_back({mp[i][j], i, j});
        }
    }
    sort(a.begin(), a.end(), [&](node a, node b){
        return a.v > b.v;
    });
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(!visx[a[i].x] && !visy[a[i].y]){
            cnt++;
            // cerr << a[i].v << '\n';
            visx[a[i].x] = 1;
            visy[a[i].y] = 1;
            if(cnt >= k){
                break;
            }
        }
    }

    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(visx[i]){
            continue;
        }
        vector<int> l;
        for(int j = 0; j < m; j++){
            if(visy[j]){
                continue;
            }
            l.push_back(mp[i][j]);
        }
        ans.push_back(l);
    }
    for(auto l : ans){
        for(int i = 0; i < l.size(); i++){
            cout << l[i] << " \n"[i == l.size() - 1];
        }
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}
