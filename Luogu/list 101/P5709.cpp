#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,t,s;
    cin >> m >> t >> s;
    if (t == 0 || m == 0){
        cout << 0;
        return 0;
    }
    int ans = m - ceil(s * 1.0 / t);
    cout << (ans <= 0 ? 0 : ans);
    return 0;
}
/**
 * 记得写特判
 */