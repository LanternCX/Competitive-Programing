#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0;
    map<char, int> mp;
    for(int i = n - 1; i >= 0; i--){
        char ch = s[i];
        if(mp.find(ch) == mp.end()){
            mp[ch] = i;
        }else {
            mx = max(mx, i + 1);
        } 
    }
    map<char, int> mp2;
    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(mp2.find(ch) == mp2.end()){
            mp2[ch] = i;
        }else {
            mx = max(mx, n - i);
        }
    }
    cout << mx;
    return 0;
}
/**
 * 4 3
 * aaaa
 * 6 2
 * ababcdefghijklmn
 */