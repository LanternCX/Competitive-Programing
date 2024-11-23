#include <bits/stdc++.h>
using namespace std;
void sol(){
    string s;
    cin >> s;
    bool tag = 0;
    if(s.length() > 2){
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == s[i + 1]){
                cout << s.substr(i, 2);
                tag = 1;
                break;
            }
        }
        if(!tag){
            for(int i = 0; i < s.length() - 2; i++){
                if(s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i]){
                    cout << s.substr(i, 3);
                    tag = 1;
                    break;
                }
            }
        }
    }
    
    if(s.length() == 1){
        tag = 0;
    }
    if(s.length() == 2 && s[0] != s[1]){
        tag = 0;
    }
    if(s.length() == 2 && s[0] == s[1]){
        tag = 1;
        cout << s;
    }

    if(!tag){
        cout << -1;
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * abc
 * a b c ab bc abc = 6
 * abb
 * a b ab bb abb = 5
 * but f(bb) = 2
 * aab
 * a b aa ab aab = 5
 * aa
 * a aa = 2
 * ab
 * a b ab = 3
 */