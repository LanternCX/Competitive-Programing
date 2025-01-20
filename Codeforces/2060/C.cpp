#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    int cnt = 0;

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == k) {
            cnt++;
            l++;
            r--;
        } else if (sum < k) {
            l++;
        } else {
            r--;
        }
    }
    cout << cnt << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
