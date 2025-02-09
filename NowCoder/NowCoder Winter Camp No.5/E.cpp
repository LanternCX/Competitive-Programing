#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int x, y;
};
void sol(){
    vector<vector<char>> mp(3, vector<char>(3));
    vector<int> cnt(2);
    vector<node> arr;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 'O'){
                cnt[0]++;
            }else if(mp[i][j] == 'X'){
                cnt[1]++;
            }else {
                arr.push_back({i, j});
            }
        }
    }
    int ans = 0;
    if(cnt[0] == 1 || cnt[0] == 2 || cnt[0] == 0){
        ans = 1;
    }
    if(cnt[0] == 4 || cnt[0]  == 3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(mp[i][j] != 'X') {
                    continue;
                }
 
                if(mp[i][0] != 'O' && mp[i][1] != 'O' && mp[i][2] != 'O'){
                    ans = 1;
                }

                if(mp[0][j] != 'O' && mp[1][j] != 'O' && mp[2][j] != 'O'){
                    ans = 1;
                }
                 
                if(i == j && mp[0][0] != 'O' && mp[1][1] != 'O' && mp[2][2] != 'O'){
                    ans = 1;
                }
                
                if(i + j == 2 && mp[0][2] != 'O' && mp[1][1] != 'O' && mp[2][0] != 'O'){
                    ans = 1;
                }
 
                if(ans){
                    break;
                }
            }
            if(ans){
                break;
            }
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}