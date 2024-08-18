#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    int ans = -1;
    for(int i = 1; i <= (x > y ? x : y); i++){
        if(x == z * i && y == w * i){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}