#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    int l = s.length() - 1;
    for(char ch : s){
        if(ch != '0'){
            ans.append(to_string((ch- '0')) +  '*' + n + '^' + to_string(l) + '+') ;
        }
        l--;
    }
    ans.erase(ans.length() - 1, 1);
    cout << ans;
    return 0;
}