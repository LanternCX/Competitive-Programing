#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] = arr[i] + pre[i - 1];
    }
    int m;
    cin >> m;
    vector<int> ans;
    for(int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        ans.push_back(pre[r] - pre[l - 1]);
    }
    for(int i : ans){
        cout << i << '\n';
    }
    return 0;
}