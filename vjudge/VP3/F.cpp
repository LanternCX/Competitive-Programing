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
void sol(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for(auto &x : arr){
        cin >> x;
        sum ^= x;
    }

    if(sum == 0){
        cout << '0' << '\n';
        return;
    }

    vector<int> bit(64);
    for(auto x : arr){
        int t = 0;
        while((x >> t) > 0){
            bit[t] += (x >> t) % 2;
            t++;
        }
    }
    reverse(bit.begin(), bit.end());

    for(auto x : bit){
        if(x == 0 || x % 2 == 0){
            continue;
        }
        if(x == 1){
            cout << '1' << '\n';
            return;
        }
        if((n - x) % 2 == 0){
            cout << '1' << '\n';
        }else {
            cout << "-1" << '\n';
        }
        return;
    }
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
/**
 * x1 ^ x2 ^ ... ^ xn
 * 
 */