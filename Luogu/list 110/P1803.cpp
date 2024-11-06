#include <bits/stdc++.h>
using namespace std;
struct Con{
    int a;
    int b;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Con> cons(n); 
    for(int i = 0; i < n; i++){
        cin >> cons[i].a >> cons[i].b;
    }
    sort(cons.begin(), cons.end(), [](Con a, Con b) -> int {
        return a.b < b.b;
    });
    int ans = 0;
    int end = 0;
    for(auto con : cons){
        if(con.a >= end){
            ans++;
            end = con.b;
        }
    }
    cout << ans;
    return 0;
}