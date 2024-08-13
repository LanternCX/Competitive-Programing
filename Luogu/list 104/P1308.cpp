#include <bits/stdc++.h>
using namespace std;
string low(string s){
    string res = "";
    for(char c : s){
        if(c <= 'Z' && c >= 'A'){
            res.push_back(c + ('a' - 'A'));
        }else {
            res.push_back(c);
        }
    }
    return res;
}

string high(string s){
    string res = s;
    if(res[0] <= 'z' && res[0] >= 'a'){
           res[0] -= ('a' - 'A'); 
    }
    return res;
}

int main(){
    string s;
    getline(cin, s);
    string text;
    getline(cin, text);

    map<int, string> dict;
    string str = "";
    for(int i = 0; i < text.length(); i++){
        if(text[i] == ' '){
            dict[i - str.length()] = str;
            str = "";
            continue;
        }
        str.push_back(text[i]);
    }
    dict[text.length() - str.length()] = str;

    int ans1 = 0;
    int ans2 = -1;
    for(auto pair : dict){
        string tag = pair.second;
        if(high(tag) == s || low(tag) == s){
            ans2 = ans2 == -1 ? pair.first : ans2;
            ans1++;
        }
    }
    cout << (ans1 == 0 ? "-1" : to_string(ans1) + " " + to_string(ans2));
    return 0;
}
/*
to
be or not to be is a question
*/