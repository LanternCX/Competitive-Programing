#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, c;
    cin >> n >> c;
    map<int, int> m;
    set<ll> arr;
    vector<ll> dif;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.insert(x);
        dif.push_back(x - c);
        m[x]++;
    }
    ll ans = 0;
    for(int x : dif){
        auto it = arr.find(x);
        if(it != arr.end()){
            // cout << x + c << endl;
            ans += m[*it];
        }
    }
    cout << ans;
    return 0;
}
/**
 * a - b = c
 * a - c = b
 */