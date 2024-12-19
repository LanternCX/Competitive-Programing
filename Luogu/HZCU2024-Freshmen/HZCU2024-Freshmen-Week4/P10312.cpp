#include <bits/stdc++.h>
using namespace std;
char l[20][100005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 1, y = 1, dx = 1, dy = 1;
    for(int i = 0; i < s.length(); i++){
        l[y][x] = EOF;

        if(y == n && dy == 1){
            dy = -1;
        }
        if(y == 1 && dy == -1){
            dy = 1;
        }

        x += dx;
        y += dy;
    }
    int idx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(l[i][j] == EOF){
                l[i][j] = s[idx];
                idx++;
            }
        }
    }

    string ans;
    x = 1, y = 1, dx = 1, dy = 1;
    for(int i = 0; i < s.length(); i++){
        ans.push_back(l[y][x]);

        if(y == n && dy == 1){
            dy = -1;
        }
        if(y == 1 && dy == -1){
            dy = 1;
        }

        x += dx;
        y += dy;
    }
    cout << ans;
    return 0;
}