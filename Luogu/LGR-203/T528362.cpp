#include <bits/stdc++.h>
using namespace std;

int isP(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    vector<int> arr;

    for (int i = n; i >= 2; i--) {
        if (isP(i) && i % m == r) {
            arr.push_back(i);
        }
    }

    if (arr.size() < k) {
        cout << -1;
    } else {
        cout << arr[k - 1];
    }

    return 0;
}
