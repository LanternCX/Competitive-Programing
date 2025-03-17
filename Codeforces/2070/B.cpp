#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    ll n, x, k;
    cin >> n >> x >> k;
    string op;
    cin >> op;
    int now = x;
    int temp = 0 ,cnt = 0;
    for(auto ch : op){
        now += ch == 'R' ? 1 : -1;
        temp++;
        if(now == 0){
            cnt = temp;
            break;
        }
    }
    if(cnt == 0 || cnt > k){
        cout << 0 << '\n';
        return;
    }
    int len = 0;
    temp = 0;
    for(auto ch : op){
        now += ch == 'R' ? 1 : -1;
        temp++;
        if(now == 0){
            len = temp;
            break;
        }
    }
    if(len == 0){
        cout <<  (cnt != 0) << '\n';
        return;
    }
    cout <<  max((k - cnt), 0LL) / len + (cnt != 0) << '\n';
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