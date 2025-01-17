#include <bits/stdc++.h>
using namespace std;
int x, y;
const int N = 1e3;
stack<int> st;
int cnt[N + 10];
int vis[N + 10];
int num = 0;
void dfs(int begin, vector<vector<int>> mp){
    if(begin == y - 1){
        num++;
        stack<int> temp = st;
        while(!temp.empty()){
            cnt[temp.top()]++;
            // cout << temp.top() << ' ';
            temp.pop();
        }
        // cout << '\n';
        return;
    }
    vis[begin] = 1;
    for(int x : mp[begin]){
        if(vis[x]){
            continue;
        }
        st.push(x);
        
        dfs(x, mp);

        vis[x] = 0;
        st.pop();
    }
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        mp[u - 1].push_back(v - 1);
        mp[v - 1].push_back(u - 1);
    }
    for(auto &arr : mp){
        sort(arr.begin(), arr.end());
    }
    cin >> x >> y;
    st.push(x - 1);
    dfs(x - 1, mp);
    int ans = 0;
    for(int i = 0; i < n; i++){
        // cout << cnt[i] << ' ';
        if(cnt[i] == num){
            ans++;
        }
    }
    // cout << num <<  '\n';
    cout << ans - 2;
    return 0;
}