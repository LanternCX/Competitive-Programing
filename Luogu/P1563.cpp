#include <bits/stdc++.h>
using namespace std;
struct Man{
    string name;
    bool face;
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Man> li;
    for(int i = 0; i < n; i++){
        Man m;
        cin >> m.face >> m.name;
        li.push_back(m);
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        int a, s;
        cin >> a >> s;
        if (li[ans].face ^ a) {
            ans = ans + s > n - 1 ? ans + s - n : ans + s;
        }else {
            ans = ans - s < 0 ? ans - s + n : ans - s;
        }
    }
    cout << li[ans].name;
    return 0;
}