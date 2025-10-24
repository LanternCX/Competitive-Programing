#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    if(n == 1){
        cout << "YES\n";
        return;
    }

    sort(b.begin(), b.end());
    a[0] = min(*min_element(b.begin(), b.end()) - a[0], a[0]);
    int ans = 1;
    for(int i = 1; i < n; i++){
        auto it = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
        if(it != b.end()){
            int temp = *it - a[i];
            if(a[i] < a[i - 1]){
                a[i] = temp;
            }else if(a[i] - a[i - 1] <= temp - a[i - 1]){
                a[i] = a[i];
            }else{
                a[i] = temp;
            }
        }
        
    }
    for(int i = 1; i < n - 1; i++){
        if(a[i] > a[i + 1]){
            ans = 0;
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    cout << (ans ? "YES\n" : "NO\n");
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
/**
 * x = b[j] - a[i] >= a[i - 1]
 * b[j] >= a[i - 1] + a[i]
 */