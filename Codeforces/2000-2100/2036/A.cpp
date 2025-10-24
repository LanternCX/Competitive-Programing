#include <bits/stdc++.h>
#include <vector>
using namespace std;
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool ans = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        int x = abs(a[i] - a[i + 1]);
        if(x != 5 && x != 7){
            ans = 0;
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
