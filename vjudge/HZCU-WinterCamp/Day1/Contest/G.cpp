#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    set<ll> s;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(arr[i] % k == 0 && s.find(arr[i] / k) != s.end()){
            continue;
        }
        s.insert(arr[i]);
    }
    cout << s.size();
    return 0;
}
/**
 * y = kx
 * y % k == 0
 * x = y / k
 */