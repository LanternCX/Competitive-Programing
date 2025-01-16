#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    cin >> k;
    int mx = 0;
    for(int i = 0; i < k; i++){
        int x; 
        cin >> x;
        mx = max(x, mx);
    }
    cout << mx + k - 1;
    return 0;
}