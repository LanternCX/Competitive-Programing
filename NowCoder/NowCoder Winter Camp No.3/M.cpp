#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<char, int> mp;
    string s;
    cin >> s;
    for(auto ch : s){
        mp[ch]++;
    }
    int ans = 0;
    if(mp['n'] == 1 && mp['o'] == 2 && mp['w'] == 1 && mp['c'] == 1 && mp['d'] == 1 && mp['e'] == 1 && mp['r'] == 1){
        ans = 1;
    }
    cout << (ans ? "happy new year" : "I AK IOI");
    return 0;
}