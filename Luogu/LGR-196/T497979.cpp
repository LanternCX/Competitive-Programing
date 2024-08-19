#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    vector<int> li;
    
    for(int i = 0; i <= s.length() - 6; i++) {
        if(s.substr(i, 6) == "friend") {
            li.push_back(i);
        }
    }
    
    while (li.size() != 0) {
        if(li.size() > 1 && li[1] - li[0] <= 8) { 
            ans++;
            li.erase(li.begin());
            li.erase(li.begin());
        } else {
            ans++;
            li.erase(li.begin());
        }
    }
    
    cout << ans;
    return 0;
}
