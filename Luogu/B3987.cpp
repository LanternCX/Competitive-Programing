#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int an[100005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    int max = -1e9, min = 1e9;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> an[i];
        max = max > an[i] ? max : an[i];
        min = min < an[i] ? min : an[i];
    }
    ll sum = max + min;
    for(int i = 0; i < n; i++){
        cout << sum - an[i] << ' ';
    }
    return 0;
}