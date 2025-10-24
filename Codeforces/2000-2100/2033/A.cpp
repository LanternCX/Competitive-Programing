#include <bits/stdc++.h>
using namespace std;
void slove(){
    int n;
    cin >> n;
    int i = 1;
    int x = 0;
    while (abs(x) <= n) {
        int tag = i % 2 == 0 ? 1 : -1;
        x += tag * (2 * i - 1);
        i++;
    }
    string ans = i % 2 == 1 ? "Kosuke" : "Sakurako";
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}