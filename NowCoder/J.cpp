#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int v = 0;
    ll ans = 0;
    int temp = 0;
    vector<int> arr;
    for(char ch : s){
        v = temp == 0 ? v : temp;
        temp = 0;
        if(ch == '0'){
            v += 10;
        }
        if(ch == '1'){
            v -= 5;
            v = max(0, v);
        }
        if(ch == '2'){
            temp = v;
            v -= 10;
            v = max(0, v);
        }
        // cout << v << '\n';
        arr.push_back(v);
    }
    for(auto v : arr){
        ans += v;
    }
    ans -= arr[0];
    cout << ans + arr[0];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**1
 * 10 1 9
 */