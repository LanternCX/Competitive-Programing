#include <bits/stdc++.h>
using namespace std;
vector<string> key = {
    " ",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};
int getNum(char c){
    for(string s : key){
        int idx = s.find(c);
        if(idx == string::npos){
            continue;
        }
        return idx + 1;
    }
    return 0;
}

int main(){
    string s;
    getline(cin, s);
    int ans = 0;
    for(char c : s){
        ans += getNum(c);
    }
    cout << ans;
    return 0;
}