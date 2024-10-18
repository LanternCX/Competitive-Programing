#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    set<int> ans;
    if(a - b >= 0 && a - b <= n){
       ans.insert(a - b);
    }
    if(a + b >= 0 && a + b <= n){
       ans.insert(a + b);
    }
    for(int i : ans){
        cout << i << ' ';
    }
    if(ans.empty()){
        cout << "No solution";
    }
    return 0;
}