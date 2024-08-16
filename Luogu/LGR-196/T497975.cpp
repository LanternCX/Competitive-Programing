#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a, b;
    int ans = 0;
    cin >> n >> m >> a >> b;
    
    for(int i = 0; i < m; i++){
        int l;
        cin >> l;
        vector<int> c(l);
        for(int i = 0; i < l; i++){
            cin >> c[i];
        }
        bool tag = 0;
        for(int ci : c){
            if (ci == a) {
                tag = 1;
            }
            if(tag == 1 && ci == b){
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}