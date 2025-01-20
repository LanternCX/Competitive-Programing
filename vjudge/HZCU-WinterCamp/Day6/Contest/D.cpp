#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
const int N = 4e4 + 10;
const int L = 500 + 10;
using  ll = long long;
ll dp[N][L];
int isloop(int n){
    string s = to_string(n);
    string temp = s;
    reverse(s.begin(), s.end());
    if(s == temp){
        return 1;
    }
    return 0;
}
void sol(int x){
    int n;
    cin >> n;
    cout << dp[n][x - 1] << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    vector<int> arr;
    for(int i = 0; i <= N; i++){
        if(isloop(i)){
            arr.push_back(i);
        }
    }
    for(int i = 0; i < arr.size(); i++){
        dp[0][i] = 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] <= i){
                dp[i][j] = (dp[i][j - 1] % p + dp[i - arr[j]][j] % p) % p;
            }else {
                dp[i][j] = dp[i][j - 1] % p;
            }
        }
    }
    while(t--){
        sol(arr.size());
    }
    // cout << arr.size();
    return 0;
}
/**
 * dp[i][j] = (dp[i][j - 1] + dp[i - arr[j]][j] )
 */