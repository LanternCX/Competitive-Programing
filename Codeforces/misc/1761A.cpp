#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    if(a + b < n - 1 || a == b && a == n){
        ans = 1;
    }
    cout << (ans ? "Yes\n" : "No\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}