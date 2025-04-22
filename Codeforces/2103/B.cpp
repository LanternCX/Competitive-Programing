#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    char now = '0';
    for(auto ch : s){
        if(ch != now){
            cnt += 2;
            now = ch;
        }else{
            cnt += 1;
        }
    }
    int a = 0, b = 0;
    s.insert(s.begin(), '0');
    for(int i = 0; i < n; i++){
        if(s.substr(i, 2) == "10"){
            a++;
        }
        if(s.substr(i, 2) == "01"){
            b++;
        }
    }
    if(a >= 2 || b >= 2){
        cout << cnt - 2 << '\n';
        return;
    }
    if(a == 1 && b == 1){
        cout << cnt - 1 << '\n';
        return;
    }
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 01
 * 
 * 1000000
 * 
 * 10101
 * 
 * 011110
 */