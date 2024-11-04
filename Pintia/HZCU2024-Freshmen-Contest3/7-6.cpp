#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    map<int, int> a;
    ll ans = 0, ans2 = 0;
    while(cin >> n){
        if(n == 1){
            int w, c;
            cin >> w >> c;
            if(a.find(c) == a.end()){
                a[c] = w;
            }
        }
        if(n == 2){
            if(!a.empty()){
                auto it = --a.end();
                a.erase(it);
            }
        }
        if(n == 3){
            if(!a.empty()){
                auto it = a.begin();
                a.erase(it);
            }
        }
        if(n == -1){
            break;
        }
    }
    
    for(auto p : a){
        ans += p.second;
        ans2 += p.first;
    }
    
    cout << ans << ' ' << ans2 << '\n';
}
