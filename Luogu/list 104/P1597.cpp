#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
int get(char c){
    if(c == 'a'){
        return 0;
    }
    if(c == 'b'){
        return 1;
    }
    if(c == 'c'){
        return 2;
    }
    return 0;
}
int main(){
    string s;
    cin >> s;
    vector<string> sn;
    string temp = "";
    for(char c : s){
        if(c == ';'){
            sn.push_back(temp);
            temp = "";
            continue;
        }
        temp.push_back(c);
    }

    int ans[3] = {0 ,0 ,0};
    for(string s : sn){
       int l, r;
       l = get(s[0]);
       r = get(s[s.length() - 1]);
       if (s[s.length() - 1] - '0' <= 9 && s[s.length() - 1] - '0' >= 0) {
            ans[l] = s[s.length() - 1] - '0';
       }else {
            ans[l] = ans[r];
       }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}
/**
 * a:=3;b:=a;c:=5;
 */