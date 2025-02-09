#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int idx;
    ll sum;
};
void sol(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    vector<node> idx;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        idx.push_back({i, sum});
    }

    auto work = [&](vector<int> a){
        ll res = 0;
        ll sum = 0;
        for(auto x : a){
            sum += x;
            res += sum;
        }
        return res;
    };

    sort(idx.begin(), idx.end(), [&](node a, node b){
        return a.sum > b.sum;
    });

    vector<int> a;
    for(auto nd : idx){
        for(auto x : arr[nd.idx]){
            a.push_back(x);
        }
    }
    cout << work(a) << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * sc?
 * 
 */