#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> arr(n + 1);
    vector<int> pre(n + 1);
    
    for(int i = 1; i <= n; i++){
        arr[i] = s[i - 1] == 'G' ? 1 : -1;
        pre[i] = pre[i - 1] + arr[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int sum = pre[j] - pre[i - 1];
            if(sum == 0){
                int l = j - i + 1;
                ans = max(l, ans);
            }
        }
    }
    cout << ans;
    return 0;
}