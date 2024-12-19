#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int idx = 0;
    while (!a.empty()) {
        idx = (idx + m - 1) % a.size();
        cout << a[idx] << ' ';
        a.erase(a.begin() + idx);
    }
    return 0;
}