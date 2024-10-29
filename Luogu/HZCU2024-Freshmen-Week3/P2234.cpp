#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = a[0];
    for(int i = 1; i < n; i++){
        int minx = 1e7;
        for(int j = i - 1; j >= 0; j--){
            minx = min(minx, abs(a[j] - a[i]));
        }
        ans += minx;
    }
    cout << ans;
    return 0;
}