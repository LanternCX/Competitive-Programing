#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, b;
    cin >> n >> b;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end(), greater<int>());
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum += h[i];
        ans++;
        if(sum >= b){
            break;
        }
    }
    cout << ans;
    return 0;
}