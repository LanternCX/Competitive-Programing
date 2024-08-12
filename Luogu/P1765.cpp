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
    for(int i = 0; i < key.size(); i++){
        string s = key[i];
        int index = s.find(c);
        if(index == string::npos){
            continue;
        }
        return index + 1;
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