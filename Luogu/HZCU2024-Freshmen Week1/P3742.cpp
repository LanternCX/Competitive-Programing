#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    string ans;
    if(s1 == s2){
        cout << s1;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(s1[i] == 'a' && s2[i] != s1[i] 
            || s1[i] < s2[i]){
            cout << -1;
            return 0;
        }
        if(s1[i] == s2[i]){
            ans.push_back(s1[i] + 1);
            if(s1[i] + 1 > 'z'){
                cout << -1;
                return 0;
            }
        }else {
            ans.push_back(s2[i]);
        }
    }
    
    cout << ans;
    return 0;
}