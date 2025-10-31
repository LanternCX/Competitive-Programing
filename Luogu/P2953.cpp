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
    int idx = 1;
    deque<int> q;
    while (n--) {
        char op, dir;
        cin >> op >> dir;
        if (op == 'A') {
            if (dir == 'L') {
                q.push_front(idx++);
            } else {
                q.push_back(idx++);
            }
        }
        if (op == 'D') {
            int k;
            cin >> k;
            if (dir == 'L') {
                for (int i = 0; i < k; i++) {
                    q.pop_front();
                } 
            } else {
                for (int i = 0; i < k; i++) {
                    q.pop_back();
                }
            }
        }
    }
    for (auto x : q) {
        cout << x << '\n';
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