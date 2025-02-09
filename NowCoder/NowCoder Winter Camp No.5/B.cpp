#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll n, t, k;
    cin >> n >> t >> k;
    cout << min((n - k) / t, k + 1) << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**1
 * 10 1 9
 */