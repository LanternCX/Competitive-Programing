#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    string s;
    cin >> s;
    vector<int> arr(26);
    unordered_map<char, int> cnt;
    for(auto &x : arr){
        cin >> x;
    }
    int ans = 0;
    for(auto ch : s){
        ans += arr[ch - 'a'];
        cnt[ch]++;
    }
    for(auto ch = 'a'; ch <= 'z'; ch++){
        // cout << ch << ' ';
        cout << cnt[ch];
        if(ch != 'z'){
            cout << ' ';
        }
    }
    cout << '\n';
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){     
        sol();
    }
}
