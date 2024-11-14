#include <bits/stdc++.h>
using namespace std;
struct node{
    int t;
    int pay;
    double w;
};
struct cmp {
    bool operator()(node a, node b) const {
        return a.pay > b.pay;
    }
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].t;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i].pay;
        // arr[i].w = arr[i].pay * 1.0 / arr[i].t;
    }
    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.t < b.t;
    });
    int time = 0;
    int ans = 0;
    queue<node> que;
    for(node i : arr){
        que.push(i);
    }
    priority_queue<node, vector<node>, cmp> pq;
    for(int i = 1; i < n; i++){
        time++;
        while (que.front().t == time) {
            pq.push(que.front());
            que.pop();
            while(pq.size() > time){
                ans += pq.top().pay;
                pq.pop();
            }
        }
        if(que.empty()){
            break;
        }
    }
    cout << m - ans;
    return 0;
}
/**
 * 
4  2  4  3  1  4  6
70 60 50 40 30 20 10
 */