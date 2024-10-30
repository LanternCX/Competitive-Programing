#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    map<int, int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    for(auto i : a){
        ans = max(ans, i.second);
    }
    cout << ans;
    return 0;
}