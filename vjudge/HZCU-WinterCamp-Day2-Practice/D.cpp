#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> u(n), a(n);
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        u[i] = x - 1;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 1; i--){
        a[u[i]] += a[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}