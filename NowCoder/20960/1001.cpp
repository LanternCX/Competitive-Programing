#include <bits/stdc++.h>
using namespace std;
int isChar(char ch){
    return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
}
int lower(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return 'a' + ch - 'A';
    }
    return ch;
}
int upper(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return 'A' + ch - 'a';
    }
    return ch;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    string ans;
    int head = 0;
    for(int i = 0; i < s.length(); i++){
        head = i;
        if(s[i] != '-'){    
            break;
        } 
    }
    for(int i = 0; i < head; i++){
        ans.push_back('-');
    }
    for(int i = head; i < s.length(); i++){
        char ch = s[i];
        if(ch == '-' && !(isChar(s[i - 1]) ^ isChar(s[i + 1]))){
            if(p3 == 1){
                char begin = min(s[i + 1] - 1, s[i - 1] + 1);
                char end = max(s[i + 1] - 1, s[i - 1] + 1);
                if(s[i + 1] <= s[i - 1]){
                    ans.push_back('-');
                    continue;
                }
                if(abs(s[i + 1] - s[i - 1]) == 1){
                    continue;
                }
                
                for(char c = begin; c <= end; c++){
                    char temp = c;
                    if(p1 == 1){
                        temp = lower(temp);
                    }
                    if(p1 == 2){
                        temp = upper(temp);
                    }
                    if(p1 == 3){
                        temp = '*';
                    }
                    for(int j = 0; j < p2; j++){
                        ans.push_back(temp);
                    }
                    if(begin == end){
                        break;
                    }
                }
            }
            if(p3 == 2){
                char begin = s[i + 1] - 1;
                char end = s[i - 1] + 1;
                if(s[i + 1] <= s[i - 1]){
                    ans.push_back('-');
                    continue;
                }
                if(abs(s[i + 1] - s[i - 1]) == 1){
                    continue;
                }
                for(char c = begin; c >= end; c--){
                    char temp = c;
                    if(p1 == 1){
                        temp = lower(temp);
                    }
                    if(p1 == 2){
                        temp = upper(temp);
                    }
                    if(p1 == 3){
                        temp = '*';
                    }
                    for(int j = 0; j < p2; j++){
                        ans.push_back(temp);
                    }
                    if(begin == end){
                        break;
                    }
                }
            }
            continue;
        }
        ans.push_back(s[i]);
    }
    
    cout << ans;
    return 0;
}