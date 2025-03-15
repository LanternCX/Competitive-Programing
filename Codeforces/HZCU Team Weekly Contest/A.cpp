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
    ll a, b;
};
void sol(){
    ll n, k;
    cin >> n >> k;
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end(), [&](node a, node b){
        return a.a < b.a;
    });
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].a * k  - sum < arr[i].b){
            cout << "No\n";
            return;
        }
        sum += arr[i].b;
    }
    cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}