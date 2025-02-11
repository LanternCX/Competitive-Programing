#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void sol(){
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if(y % 2 == 1){
        y /= 2;
        if(y % 2 == x % 2 && (y + 1) % 2 == (x + 1) % 2){
            ans = 1;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
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
/**
 * y = x + x + 1
 * 1 2  3 / 2 = 1
 * 3 4 
 * 5 6
 */