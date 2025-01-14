#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int t, b;
};
void sol(){
    int n;
    ll t;
    cin >> n >> t;
    vector<node> arr(n);
    vector<node> a, b;
    for(int i = 0; i < n; i++){
        node x;
        cin >> x.t >> x.b;
        if(x.b > 0){
            a.push_back(x);
        }else {
            b.push_back(x);
        }
    }
    int ans = 1;
    sort(a.begin(), a.end(), [](node a, node b) -> int {
        return a.t < b.t;
    });
    for(node nd : a){
        if(nd.t < t){
            t += nd.b;
        }else {
            ans = 0;
        }
    }
    sort(b.begin(), b.end(), [](node a, node b) -> int {
        return a.b + a.t > b.b + b.t;
    });
    for(node nd : b){
        if(nd.t < t){
            t += nd.b;
        }else {
            ans = 0;
        }
        if(t <= 0){
            ans = 0;
        }
    }
    cout << (ans ? "+1s\n" : "-1s\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}