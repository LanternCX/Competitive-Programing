#include <bits/stdc++.h>
using namespace std;int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = n - (k - 2 * n);
    cout << (ans < 0 ? 0 : ans);
    return 0;
}