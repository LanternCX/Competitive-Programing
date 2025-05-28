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
    vector<int> ans1(2);
    vector<int> ans2(6);
    while (n--) {
        int a, b;
        cin >> a >> b;
        a--;
        if (a == 3 || a == 5) {
            continue;
        }
        ans2[a]++;
        ans1[b]++;
    }
    auto mx1 = *max_element(ans1.begin(), ans1.end());
    auto mx2 = *max_element(ans2.begin(), ans2.end());
    if (ans1[0] == ans1[1]) {
        cout << "LOVE " << mx1 << '\n';
    } else {
        for (int i = 0; i < 2; i++) {
            if(ans1[i] == mx1) {
                cout << i << ' ' << mx1 << '\n';
            }
        }
    }
    vector<int> temp;
    for (int i = 0; i < 6; i++) {
        if (i == 3 || i == 5) {
            continue;
        }
        if(ans2[i] == mx2) {
            temp.push_back(i + 1);
        }
    }
    sort(temp.begin(), temp.end());
    cout << mx2 << ' ';
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " \n"[i == temp.size() - 1];
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