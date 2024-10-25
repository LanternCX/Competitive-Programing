#include <bits/stdc++.h>
using namespace std;
string slove(){
    string s;
    cin >> s;
    int ans = 1;
    if(s.find("@") == string::npos){
        ans = 0;
        return "No";
    }
    
    int idx = s.find("@");
    string local = s.substr(0, idx);
    string domain = s.substr(idx + 1, s.size() - idx);
    if(local.size() > 64 || local.empty()){
        return "No";
    }
    if(local[0] == '.' || local[local.length() - 1] == '.'){
        return "No";
    }
    if(local[0] == '-' || local[local.length() - 1] == '-'){
        return "No";
    }
    int num = 0;
    for(char ch : local){
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '.'){
            num++;
        }
    }
    if(num != local.length()){
        return "No";
    }

    if (domain.size() > 255 || domain.empty()) {
        return "No";
    }
    if(domain[0] == '.' || domain[domain.length() - 1] == '.'){
        return "No";
    }
    if(domain[0] == '-' || domain[domain.length() - 1] == '-'){
        return "No";
    }
    num = 0;
    for(char ch : domain){
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '.' || ch == '-'){
            num++;
        }
    }
    if(num != domain.length()){
        return "No";
    }
    return "Yes";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        string ans = slove();
        cout << ans << '\n';
    }
    return 0;
}
/**
 * 
1
1
1
4
4
8
8
8
8
16
16
16
16
16
16
16
16
32
32
32
 */