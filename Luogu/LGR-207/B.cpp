#include <bits/stdc++.h>
using namespace std;
int ans[3];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if(a + b >= k){
        ans[0] = 1;
    }
    if(a + c >= k){
        ans[1] = 1;
    }
    if(b + c >= k){
        ans[2] = 1;
    }
    for(int i = 0; i < 3; i++){
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
    return 0;
}