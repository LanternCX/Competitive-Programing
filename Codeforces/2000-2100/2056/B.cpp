#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int mp[N + 10][N + 10];
struct node{
    int id, n;
};
void sol(){
    int n;
    cin >> n;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            mp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char ch;
            cin >> ch;
            mp[i][j] = ch - '0';
            // cin >> mp[i][j];
        }
    }
    vector<int> ans;
    while(ans.size() < n){
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = i; j <= n; j++){
                if(mp[i][j] == 1){
                    cnt++;
                }
            }
            for(int j = 1; j < i; j++){
                if(mp[i][j] == 0){
                    cnt++;
                }
            }
            if(cnt == n - ans.size() - 1){
                ans.push_back(i);
            }
        }
    }
    for(int x : ans){
        cout << x << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        sol();
    }
    return 0;
}
/**
1
5
01100
10100
11001
00001
00110
 */