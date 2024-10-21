#include <bits/stdc++.h>
using namespace std;
int slove(){
    int n;
    cin >> n;
    if(n == 0){
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x % 3 == 0){
            ans++;
        }
    }
    cout << ans << '\n';
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (slove() != 0);
    return 0;
}