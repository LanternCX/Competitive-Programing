#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int x, y;
    cin >> x >> y;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        ans += x * 2;
        ans += y * 2;
    }
    ans += 4 * m;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        sol();
    }
    return 0;
}