#include <bits/stdc++.h>
using namespace std;
int n, m;
void dfs(int now, vector<int> arr){
    if(arr.size() == m){
        for(int x : arr){
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = now; i <= n - (m - arr.size() - 1); i++){
        vector<int> temp = arr;
        temp.push_back(i);
        dfs(i + 1, temp);
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    dfs(1, {});
    return 0;
}