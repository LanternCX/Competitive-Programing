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
    int t, begin, id, time, v;
    int end = begin + time;
    int operator<(node nd) const{
        return nd.end < end;
    }
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    }
    vector<node> task(m);
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        b--;
        task[i] = {i, a, b, c, d, a + c};
    }
    // sort(task.begin(), task.end(), [&](node a, node b){
    //     return a.begin < b.begin;
    // });
    
    vector<priority_queue<node, vector<node>, less<node>>> pq(n);
    vector<int> ans(m);
    for(auto nd : task){
        int id = nd.id;
        int begin = nd.begin;
        int vx = nd.v;
        while (!pq[id].empty() && pq[id].top().end <= begin) {
            v[id] += pq[id].top().v;
            pq[id].pop();
            if(pq.empty()){
                break;
            }
        }
        if(v[id] >= nd.v){
            pq[id].push(nd);
            v[id] -= vx;
            ans[nd.t] = v[id];
        }else {
            ans[nd.t] = -1;
        }
    }
    for(auto x : ans){
        cout << x << '\n';
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