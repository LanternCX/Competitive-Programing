#include <bits/stdc++.h>
using namespace std;
struct node{
    int l, r, idx;
    int operator> (node a) const{
        return r > a.r;
    }
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].l >> arr[i].r;
        arr[i].idx = i;
    }
    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.l < b.l;
    });

    vector<int> ans(n);
    queue<node> q;
    for(auto nd : arr){
        q.push(nd);
    }
    priority_queue<node, vector<node>, greater<node>> pq;
    for(int i = 1; i <= n; i++){
        if(!q.empty()){
            while(q.front().l <= i){
                pq.push(q.front());
                q.pop();
                if(q.empty()){
                    break;
                }
            }
        }
        if(pq.empty()){
            cout << -1; 
            return 0;
        }

        node now = pq.top();
        pq.pop();
        if(now.r < i){
            cout << -1;
            return 0;
        }
        ans[now.idx] = i;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' '; 
    }
    return 0;
}
/**
 * 1 + ... + n = (1 + n) * n / 2 = n^2 / 2 + n / 2 -> n^2 / 2 = 10^10 / 2 = 5e9
 * 
 */