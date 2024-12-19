#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
bool arr[N];

void solve(int a, const vector<int>& s) {
    int x;
    cin >> x;
    if (arr[x]) {
        cout << "lucky\n";
        return;
    }
    cout << *lower_bound(s.begin(), s.end(), x) << '\n';
}

void init(int a) {
    for (int i = ceil(sqrt(a)); i * i <= N; i++) {
        int mul = i * i;
        for (int j = mul; j <= N; j += mul) {
            arr[j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, n;
    cin >> a >> n;

    init(a);

    vector<int> list;
    for (int i = a; i < N; i++) {
        if (arr[i]) {
            list.push_back(i);
        }
    }

    while (n--) {
        solve(a, list);
    }
    return 0;
}
