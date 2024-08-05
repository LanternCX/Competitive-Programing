#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    char x;
    cin >> n >> x;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        for(char c : s){
            if(c == x){
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}