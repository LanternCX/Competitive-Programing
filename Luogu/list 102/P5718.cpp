#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 114514;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(ans > a){
            ans = a;
        }
    }
    cout << ans;
    return 0;
}