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
    int val, day, cnt;
    auto operator<(node a)const{
        return val > a.val;
    }
};
void sol(){
    int x, n;
    cin >> x >> n;
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    sort(arr.begin(), arr.end(), [](node a, node b) {
        return a.day > b.day;
    });
    queue<node> q;
    for(auto nd : arr){
        q.push(nd);
    }

    priority_queue<node, vector<node>, less<node>> pq;
    ll ans = 0;
    for(int i = x; i > 0; i--){
        while(!q.empty() && q.front().day >= i){
            pq.push(q.front());
            q.pop();
        }
        if(pq.empty()){
            cout << -1;
            return;
        }
        auto nd = pq.top();
        pq.pop();
        ans += nd.val;
        nd.cnt--;
        if(nd.cnt > 0){
            pq.push(nd);
        }
    }
    cout << ans << '\n';
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
/**
 * 对于第 x 天吃的巧克力 满足
 * 1) day >= x;
 * 显然 val 尽量小的时候更优
 * 
 * 天数越大能选的巧克力越少
 * 显然从 x 天开始考虑
 * 
 * 考虑排序：
 * 第一关键字 - 天数
 * 第二关键字 - 价格
 * 
 * 使用优先队列：
 * 每次都把满足条件的push
 * 按照价格排序
 * 
 */