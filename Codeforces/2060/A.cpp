#include <bits/stdc++.h>
using namespace std;

int calc(int a1, int a2, int a3, int a4, int a5) {
    int count = 0;
    if (a3 == a1 + a2) count++;
    if (a4 == a2 + a3) count++;
    if (a5 == a3 + a4) count++;
    return count;
}
void sol(){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    int ans = 0;
    for (int a3 = -200; a3 <= 200; a3++) {
        ans = max(ans, calc(a1, a2, a3, a4, a5));
    }
    cout << ans << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
