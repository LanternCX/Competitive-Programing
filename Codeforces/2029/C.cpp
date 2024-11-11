#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> rate(n + 1);
    for(int i = 1; i <= n; i++){
        if(rate[i - 1] < a[i]){
            rate[i] = rate[i - 1] + 1;
        }else if(rate[i - 1] > a[i]){
            rate[i] = rate[i - 1] - 1;
        }else {
            rate[i] = rate[i - 1];
        }
    }
    int mn = 1e7;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(rate[j] - rate[i - 1] < mn){
                mn = rate[j] - rate[i - 1];
            }
        }
    }

    cout << rate[n] - mn << '\n';
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
/**
 * 1 2 3 4 5 6
 * 
 * 1 2  1 1 1 3 4
 * 1 2  1 1 1 2 3
 * 1 1 -1 0 0 1 2
 * 1 2  1 1 1 2 4
 * sum = 
 */

/**
 * to be done
 */