#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int op(string a, string b){
    ll idx = 0;
    for(ll i = 0; i < min(a.length(), b.length()); i++){
        if(a[i] != b[i]){
            break;
        }
        idx++;
    }
    return (a.length() - idx) + b.length() - idx;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(auto &s : arr){
        cin >> s;
    }
    int l, r;
    cin >> l >> r;

    sort(arr.begin(), arr.end());
    int ans = arr[0].length() + arr[n - 1].length();
    int mx = arr[0].length();
    for(int i = 1; i < n; i++){
        // cout << i - 1 << ' ' << i << '\n';
        ans += op(arr[i - 1], arr[i]);
        mx = max(mx, (int) arr[i].length());
    }
    cout << ans - mx;
    return 0;
}
/**
days +4
-4
coder + 5
-5
nowdays +7
now -4
nowcoder +5

now 3
-0
nowdays +4
now -4
nowcoder 5

(3 + 7 + 8) * 2 - 5
 */