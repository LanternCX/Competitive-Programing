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
#define int long long
void sol(){
    int n;
    cin >> n;
    vector<int> ans(n);
    string a(n, ' ');
    for(int i = 0; i < n ; i++){
        a[i] = 'a' + i % 26;
    }
    cout << "? " << a << '\n';
    string ax;
    cin >> ax;
    for(int i = 0; i < n; i++){
        ans[i] += (ax[i] - 'a'); 
    }

    string b(n, ' ');
    int idx = 0;
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(int i = 0; i < 26 && idx < n; i++){
            b[idx] = ch;
            idx++;
        }
    }
    cout << "? " << b << '\n';
    string bx;
    cin >> bx;
    for(int i = 0; i < n; i++){
        ans[i] += (bx[i] - 'a') * 26; 
    }
    
    string c(n, ' ');
    idx = 0;
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(int i = 0; i < 26 * 26 && idx < n; i++){
            c[idx] = ch;
            idx++;
        }
    }
    cout << "? " << c << '\n';
    string cx;
    cin >> cx;
    for(int i = 0; i < n; i++){
        ans[i] += (cx[i] - 'a') * 26 * 26; 
    }
    
    string d(n, ' ');
    idx = 0;
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(int i = 0; i < 26 * 26 * 26 && idx < n; i++){
            d[idx] = ch;
            idx++;
        }
    }
    cout << "? " << d << '\n';
    string dx;
    cin >> dx;
    for(int i = 0; i < n; i++){
        ans[i] += (dx[i] - 'a') * 26 * 26 * 26; 
    }

    cout << "! ";
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        res[ans[i]] = i;
    }
    for(auto x : res){
        cout << x + 1 << ' ';
    }
}
signed main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 1 3 2 4 5
 * abc...zabc...zabc...zabc...z
 * aaa...abbb...bccc...cddd...d
 * 
 * (ch - 'a')^x
 */