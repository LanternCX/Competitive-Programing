#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    vector<int> c;
    for(int i = 0; i < n; i++){
        if(x[i] <= a + b){
            c.push_back(y[i]);
        }
    }
    sort(c.begin(), c.end());
    int ans = 0;
    for(int i : c){
        s -= i;
        if(s < 0){
            break;
        }
        ans++;
    }
    cout << ans;
    return 0;
}