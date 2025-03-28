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
    int a, h, t, id;
    auto operator>(node x)const {
        if(h == x.h){
            if(a == x.a){
                return id < x.id;
            }
            return a < x.a;
        }
        return h < x.h;
    }
};
void sol(){
    int n, u, k, hq;
    cin >> n >> u >> k >> hq;
    vector<node> arr(n);
    for(auto &x : arr){
        cin >> x.a >> x.h;
        x.t = 0;
    }
    for(int i = 0; i < n; i++){
        int a, h;
        cin >> a >> h;
        arr[i] = {a, h, 0, i};
    }
    priority_queue<node, vector<node>, greater<node>> pq;
    multiset<int, greater<int>> st;
    for(auto x : arr){
        pq.push(x);
        st.insert(x.a);
    }
    int ans = 0;
    while(!pq.empty()){
        node now = pq.top();
        pq.pop();
        debug(now.id);
        if(now.t >= k){
            continue;
        }
        if(now.t >= 1){
            now.t++;
            now.h -= u / 2;
            hq -= *st.begin();
            if(hq <= 0){
                break;
            }
            if(now.h <= 0){
                ans++;
                auto it = st.find(now.a);
                st.erase(it);
            }else {
                pq.push(now);
            }
        }else{
            now.t++;
            now.h -= u;
            hq -= *st.begin();
            if(hq <= 0){
                break;
            }
            if(now.h <= 0){
                ans++;
                auto it = st.find(now.a);
                st.erase(it);
            }else {
                pq.push(now);
            }
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
 * to be done
 */