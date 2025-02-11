#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const string tag = "CHICKEN";
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c;
    for(int i = 0; i < n; i++){
        if(s[i] == 'C'){
            c.push_back(i);
        }
    }
    int ans = 0;
    for(auto i : c){
        int idx = 0;
        int now = i;
        int ok = 0;
        string str = s.substr(0, now);
        while(1){
            if(s[now] == tag[idx]){
                idx++;
            }else {
                str += s[now];
            }
            now++;
            if(now == s.length() && idx != tag.length()){
                break;
            }
            if(idx == tag.length()){
                ok = 1;
                break;
            }
        }
        str += s.substr(now, s.length());
        if(ok){
            // cout << str << '\n';
            vector<int> arr(26);
            for(char ch : str){
                arr[ch - 'A']++;
            }
            int mx = *max_element(arr.begin(), arr.end());
            int sum = str.length();
            if(sum % 2 == 0 && sum / 2 >= mx){
                ans = 1;
            }
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * ZZYX
 * 1 1 2
 * 
 * ZZZAAK
 * 
 */