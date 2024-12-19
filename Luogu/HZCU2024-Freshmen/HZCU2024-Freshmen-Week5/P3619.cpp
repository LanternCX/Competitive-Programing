#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    ll t;
    ll b;
};
void sol(){
    ll n, T;
    cin >> n >> T;
    vector<node> arr1;
    vector<node> arr2;
    for(int i = 0; i < n; i++){
        node x;
        cin >> x.t >> x.b;
        if(x.b < 0){
            arr2.push_back(x);
        }else {
            arr1.push_back(x);
        }
    }
    sort(arr1.begin(), arr1.end(), [](node a, node b) -> int {
        return a.t < b.t;
    });
    sort(arr2.begin(), arr2.end(), [](node a, node b) -> int {
        return a.b + a.t > b.b + b.t;
    });
    
    for(node x : arr1){
        if(x.t < T){
            T += x.b;
        }else {
            cout << "-1s\n";
            return;
        }
    }
    for(node x : arr2){
        if(x.t < T){
            T += x.b;
        }else {
            cout << "-1s\n";
            return;
        }
        if(T <= 0){
            cout << "-1s\n";
            return;
        }
    }
    cout << "+1s\n";
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