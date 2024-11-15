#include <bits/stdc++.h>
using namespace std;
string sol(string s){
    int cnta = 0, cntb = 0;
    int isHall = 0;
    for(char ch : s){
        if(ch == 'H'){
            isHall = 1;
        }
        if(ch == 'A'){
            cnta++;
        }
        if(ch == 'B'){
            cntb++;
        }
    }
    for(char &ch : s){
        if(ch != 'H'){
            ch = '#';
        }
    }
    if(isHall){
        for(int i = 0; i < cnta; i++){
            s[i] = 'A';
        }
        for(int i = s.length() - 1; i >= max(0, (int)s.length() - cntb); i--){
            s[i] = 'B';
        }
    }else {
        if(cnta > cntb){
            for(int i = s.length() - 1; i >= max(0, (int)s.length() - cnta); i--){
                s[i] = 'A';
            }
        }
        if(cnta < cntb){
            for(int i = 0; i < cntb; i++){
                s[i] = 'B';
            }
        }
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        map[i] = sol(s);
    }
    vector<string> temp(map);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 'A'){
                if(i == n - 1 && i != 0){
                    if(map[i - 1][j] == 'A'){
                        temp[i][j] = '#';
                    }
                    continue;
                }
                if(i == 0 && i != n - 1){
                    if(map[i + 1][j] == 'A'){
                        temp[i][j] = '#';
                    }
                    continue;
                }
                if(n != 1){
                    if(map[i + 1][j] == 'A' || map[i - 1][j] == 'A'){
                        temp[i][j] = '#';
                    }else {
                        temp[i][j] = 'A';
                    }
                }
            }
            if(map[i][j] == 'B'){
                if(i == n - 1 && i != 0){
                    if(map[i - 1][j] == 'B'){
                        temp[i][j] = '#';
                    }
                    continue;
                }
                if(i == 0 && i != n - 1){
                    if(map[i + 1][j] == 'B'){
                        temp[i][j] = '#';
                    }
                    continue;
                }
                if(n != 1){
                    if(map[i + 1][j] == 'B' || map[i - 1][j] == 'B'){
                        temp[i][j] = '#';
                    }else {
                        temp[i][j] = 'B';
                    }
                }
            }
        }
    }
    map = temp;
    for(string s : map){
        cout << s << '\n';
    }
    return 0;
}
/**
 * 
1 3
A
A
A
 */