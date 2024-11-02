#include <bits/stdc++.h>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> m(2);
    for(int i = 0; i < 2 * n; i++){
        int x;
        cin >> x;
        m[x]++;
    }
    cout << max(m[0] % 2, m[1] % 2) << ' ' << min(m[0], m[1]) << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}