#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    ll sum1 = 0, sum2 = 0;
    for(int i=1;i<=5;i++){
        int a;
        cin >> a;
        sum1 += a;
    }
    for(int i=1;i<=5;i++){
        int a;
        cin >> a;
        sum2 += a;
    }
    if(sum1 >= sum2) cout << "Blue\n";
    else cout << "Red\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}