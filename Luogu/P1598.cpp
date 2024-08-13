#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans[26];
    for(int i = 0; i < 26; i++){
        ans[i] = 0;
    }
    for(int i = 0; i < 4; i++){
        string str;
        getline(cin, str);
        for(char c : str){
            if(c < 'A' || c > 'Z'){
                continue;
            }
            ans[c - 'A']++;
        }
    }
    int max = -114514;
    for(int n : ans){
        max = max > n ? max : n;
    }
    
    for(int i = max; i > 0; i--){
        for(int j = 0; j < 26; j++){
            if(ans[j] < i){
                cout << ' ';
            }else {
                cout << '*';
            }
            cout << ' ';
        }
        cout << endl;
    }
    for(char c = 'A'; c <= 'Z'; c++){
        cout << c << ' ';
    }
    return 0;
}