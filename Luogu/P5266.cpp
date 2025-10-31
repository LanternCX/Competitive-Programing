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
    map<string, int> mp;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            string s;
            int sc;
            cin >> s >> sc;
            mp[s] = sc;
            cout << "OK\n";
        }
        if (op == 2) {
            string s;
            cin >> s;
            if (!mp.count(s)) {
                cout << "Not found\n";
            } else {
                cout << mp[s] << '\n';
            }
        }
        if (op == 3) {
            string s;
            cin >> s;
            if (!mp.count(s)) {
                cout << "Not found\n";
            } else {
                mp.erase(s);
                cout << "Deleted successfully\n";
            }
        }
        if (op == 4) {
            cout << mp.size() << '\n';
        }
    }   
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