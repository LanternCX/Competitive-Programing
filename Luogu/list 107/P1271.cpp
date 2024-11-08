#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i++){
        cout << a[i] << ' ';
    }
    return 0;
}