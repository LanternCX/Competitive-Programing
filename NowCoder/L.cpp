#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> mp(n + 2, vector<int>(n + 2));
    int x = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            mp[i][j] = x++;
        }
    }
    vector<int> ans;
    auto work = [&](int i, int j){
        if(ans.empty()){
            ans.push_back(mp[i][j]);
        }else if(ans[ans.size() - 1] != mp[i][j]){
            ans.push_back(mp[i][j]);
        }
    };
    for(int i = n; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            work(i, j);
        }

        for(int j = 0; j <= i - 1; j++){
            work(i - 1, j);
            if(j != i - 1){
                work(i, j + 1);
            }
        }
    }
    for(int i = 0; i <= n; i++){
        work(i, i);
    }
    cout << "Yes\n";
    for(auto x : ans){
        cout << x << ' ';
    }
    return 0;
}
/**
 * (1 + (n + 1)) * n / 2
 */