#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int cnt = 0;
    int idx = 0;
    int minx = 1e9;
    for(int i = 0; i < n; i++){
        if(a[i] - b[i] < 0){
            cnt++;
            idx = i;
        }else{
            minx = min(a[i] - b[i], minx);
        }
    }
    int ans = 1;
    if(cnt >= 2){
        ans = 0;
    }else{
        if(-a[idx] + b[idx] > minx){
            ans  = 0;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}