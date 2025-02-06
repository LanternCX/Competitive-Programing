#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto val = [&](string s) -> int {
        int res = 0;
        array<int, 2> cnt = {0, 0};
        for(int i = 0; i < n; i++){
            if(s.substr(i, 2) == "01"){
                cnt[0]++;
            }
            if(s.substr(i, 2) == "10"){
                cnt[1]++;
            }
        }
        // cout << s << ' ' << cnt[0] << ' ' << cnt[1] << '\n';
        for(int i = 0; i < n; i++){
            array<int, 2> temp = cnt;
            if(s[i] == '0'){
                if(i > 0){
                    if(s[i - 1] == '0'){
                        temp[0]++;
                    }
                    if(s[i - 1] == '1'){
                        temp[1]--;
                    }
                }
                if(i < n - 1){
                    if(s[i + 1] == '1'){
                        temp[0]--;
                    }
                    if(s[i + 1] == '0'){
                        temp[1]++;
                    }
                }
            }
            if(s[i] == '1'){
                if(i > 0){
                    if(s[i - 1] == '0'){
                        temp[0]--;
                    }
                    if(s[i - 1] == '1'){
                        temp[1]++;
                    }
                }
                if(i < n - 1){
                    if(s[i + 1] == '1'){
                        temp[0]++;
                    }
                    if(s[i + 1] == '0'){
                        temp[1]--;
                    }
                }
            }
            res += temp[0] == temp[1];
        }
        return res;
    };

    ll sum = 0;
    auto dfs = [&](auto&& dfs, string str, int idx) -> void {
        // cout << str << '\n';
        if(idx == str.length()){
            // cout << '\n';
            sum += val(str) % p;
            return;
        }
        string temp = str;
        int next = n;
        for(int i = idx + 1; i < (int) str.length(); i++){
            if(str[i] == '?'){
                next = i;
                break;
            }
        }
        if(next == n){
            dfs(dfs, temp, next);
        }else{
            if(temp[next] == '?'){
                temp[next] = '0';
            }
            dfs(dfs, temp, next);
            temp = str;
            if(temp[next] == '?'){
                temp[next] = '1';
            }
            dfs(dfs, temp, next);
        }
    };
    dfs(dfs, s, -1);
    cout << sum << '\n';
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
/**
 * 01010101
 * 1101 01: 2 / 10: 1
 * 
 * 00 -> 01
 * 01 -> 
 * 101
 * 001
 * 000
 * 100
 */