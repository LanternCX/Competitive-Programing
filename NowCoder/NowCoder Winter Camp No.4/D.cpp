#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if(n < m){
        swap(n, m);
        swap(a, b);
    }
    map<char, int> mp;
    vector<int> cnt(26, 0);
    for(auto ch : a){
        cnt[ch - 'a']++;
    }
    int sum = 0;
    for(auto ch : b){
        if(cnt[ch - 'a'] > 0){
            cnt[ch - 'a']--;
            continue;
        }
        sum++;
    }
    int ans = 0;
    for(auto x : cnt){
        ans += x % 2 == 1;
    }
    if(sum >= ans){
        ans = sum;
    }else{
        ans -= sum;
        ans /= 2;
        ans += sum;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}