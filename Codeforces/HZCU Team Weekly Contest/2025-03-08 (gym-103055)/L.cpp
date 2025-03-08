#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    string s;
    int len;
    cin >> len >> s;
    if(len == 1){
        cout << "Correct\n";
        return;
    }

    int l = 0, r = -1;
    vector<int> next(len + 1);
    next[0] = -1; 

    while(l < len){
        if(r == -1 || s[l] == s[r]){
            l++, r++;
            next[l] = r;
            continue;
        }
        r = next[r];
    }

    int ans = 0;
    for(int i = 1; i <= len; i++){
        if(next[i]){
            ans = 1;
            break;
        }
    }
    cout << (ans ? "Wrong Answer\n" : "Correct\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}