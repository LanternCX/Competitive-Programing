#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
struct node{
    string s;
    double n; 
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<node> ans;
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(j == 0){
                continue;
            }
            int x = gcd(i, j);
            if(x == 1){
                string s = to_string(i) + '/' + to_string(j);
                ans.push_back({s, i * 1.0 / j});
                // cout << i << '/' << j << '\n';
            }
        }
    }
    sort(ans.begin(), ans.end(), [](node a, node b) -> int {
        return a.n < b.n;
    });
    for(auto i : ans){
        cout << i.s << '\n';
    }
    return 0;
}