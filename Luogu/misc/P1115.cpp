#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max = INT_MIN, temp = 0;
    for (int i = 0; i < n; i++) {
        temp += a[i];
        max = temp > max ? temp : max;
        if (temp < 0) {
            temp = 0;
        }
    }
    cout << max << endl;
    return 0;
}
