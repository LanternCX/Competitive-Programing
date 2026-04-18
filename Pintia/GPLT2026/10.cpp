#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void sol() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
    }
    map<int, int> idx;
    for (int i = 0; i < n; i++) {
        if (!idx.count(arr[i])) {
            idx[arr[i]] = i;
        }
    }
    
    int mx = *max_element(arr.begin(), arr.end());
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] == mx) {
            temp.push_back(i);
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] + 1 << " \n"[i == temp.size() - 1];
    }

    sort(arr.begin(), arr.end());

    int t;
    cin >> t;
    vector<int> ans;
    while (t--) {
        int x;
        cin >> x;
        auto it = upper_bound(arr.begin(), arr.end(), x);
        if (it == arr.end()) {
            ans.push_back(0);
        } else {
            ans.push_back(idx[*it] + 1);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];;
        if (i != ans.size() - 1) {
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}