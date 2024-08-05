#include <bits/stdc++.h>
using namespace std;
string flip(string s,int a){
    string ss = s;
    if(a == 1){
        ss[0] = '-';
    }
    for(int i = a; i <= s.length() - 1; i++){
        ss[i] = s[s.length() - i - 1 + a];
    }
    return ss;
}
int main(){
    string s;
    cin >> s;
    string ans = "";
    if(s.length() == 1){
        cout << s;
        return 0;
    }
    for(int i = s.length() - 1; i >= 0 ; i--){
        if(s[i] == '0'){
            s.erase(i,1);
        }else{
            break;
        }
    }
    if(s[0] == '-'){
        ans = flip(s, 1);
    }else{
        ans = flip(s, 0);
    }
    cout << ans;
    return 0;
}