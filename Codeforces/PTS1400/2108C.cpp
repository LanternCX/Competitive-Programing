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
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    map<int, vector<int>> idx;
    set<int, greater<int>> st;
    for(int i = 0; i < n; i++){
        idx[a[i]].push_back(i);
        st.insert(a[i]);
    }

    if(n == 1){
        cout << 1 << '\n';
        return;
    }

    vector<int> dx = {1, -1};
    vector<int> vis(n);
    int ans = 0;
    for(auto x : st){
        sort(idx[x].begin(), idx[x].end());
        vector<int> temp = idx[x];
        int len = temp.size();
        vector<pii> next;
        for(int l = 0, r = 0; l < len && r < len;){
            while(r - l == abs(temp[r] - temp[l]) && r < len){
                r++;
            }
            next.push_back({temp[l], temp[r - 1]});
            l = r;
        }
        
        for(auto [l, r] : next){
            debug(l, r);
            vis[l] = 1;
            vis[r] = 1;
            int tag = 0;
            if(r + 1 < n){
                if(vis[r + 1]){
                    tag = 1;
                }
            }
            if(l - 1 >= 0){
                if(vis[l - 1]){
                    tag = 1;
                }
            }
            ans += !tag;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        debug(t);
        sol();
    }
    return 0;
}
/**
 * 对于每一个块
 * 
 * 首先肯定是从最大的按顺序往下走
 * 
 * 如果某一个点左右两边存在 vis 那么就直接merge
 * 不然就作为根
 * 
 * 连续递增或者递减的段一定是一起的所以可以直接合并
 * 双指针
 */