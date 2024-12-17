# ACM Note No.2: 前缀和与差分

### 差分

`diff[x] += z;`
`diff[y + 1] -= z;`

```c++
// Luogu P2367
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> diff(n + 1);
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        diff[i] = arr[i] - arr[i - 1];
    }
    for(int i = 1; i <= p; i++){
        int x, y, z;
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    vector<int> a(n + 1);
    int ans = 1e7;
    for(int i = 1; i <= n; i++){
        a[i] = a[i - 1] + diff[i];
        ans = min(ans, a[i]);
    }
    cout << ans << '\n';
    return 0;
}
```

### 前缀和

`pre[r] - pre[l - 1]`

```c++
// Luogu P8218
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] = arr[i] + pre[i - 1];
    }
    int m;
    cin >> m;
    vector<int> ans;
    for(int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        ans.push_back(pre[r] - pre[l - 1]);
    }
    for(int i : ans){
        cout << i << '\n';
    }
    return 0;
}
```

### 二维前缀和

```c++
// Luogu P1719
#include <bits/stdc++.h>
using namespace std;

int a[200][200];
int s[200][200];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int ans = -1e7;

    for (int i1 = 1; i1 <= n; i1++) {
        for (int j1 = 1; j1 <= n; j1++) {
            for (int i2 = i1; i2 <= n; i2++) {
                for (int j2 = j1; j2 <= n; j2++) {
                    int sum = s[i2][j2] - s[i1 - 1][j2] - s[i2][j1 - 1] + s[i1 - 1][j1 - 1];
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

```

