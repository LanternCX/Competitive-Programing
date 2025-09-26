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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum += x;
    }
    sort(a.begin(), a.end());
    a[n - 1]--;
    sort(a.begin(), a.end());

    if(a[n - 1] - a[0] > k || sum % 2 == 0){
        cout << "Jerry\n";
    }else{
        cout << "Tom\n";
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