#include <bits/stdc++.h>
using namespace std;
int isLoop(string s){
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i] != s[s.length() - i - 1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n; 
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int idx0 = -1, idx1 = -1;

        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == 'l' || ch == 'q' || ch == 'b'){
                idx0 = i;
            }else {
                break;
            }
        }

        for(int i = s.length() - 1; i >= 0; i--){
            char ch = s[i];
            if(ch == 'l' || ch == 'q' || ch == 'b'){
                idx1 = i;
            }else {
                break;
            }
        }

        int len0 = 0, len1 = 0;
        if(idx0 != -1){
            len0 = idx0 + 1;
        }

        if(idx1 != -1){
            len1 = s.length() - idx1;
        }

        int begin = s.length();
        if(idx1 != -1){
            begin = idx1 + len0;
        }

        begin = min(begin, (int)s.length() - 1);
        int cnt = s.length() - begin;
        if(len1 != 0){
            s.erase(begin, cnt);
        }
        
        if(isLoop(s)){
            cout << "Yes\n";
        }else {
            cout << "No\n";
        }
    }
    return 0;
}