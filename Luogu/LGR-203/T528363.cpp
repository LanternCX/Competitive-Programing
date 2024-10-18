#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> arr(2 * m);
    for(int i = 1; i < m * 2; i += 2){
        arr[i] = 1;
    }
    for(int i = 2; i < m * 2 - 1; i += 2){
        arr[i] = 2;
    }
    for(int i = 0; i < n; i++){
        int x, l ,r;
        cin >> x >> l >> r;
        if(x == 1){
            for(int j = 2 * l; j < 2 * r - 1; j++){
                arr[j] = 0;
            }
        }
        if(x == 2){
            for(int j = 2 * l - 1; j <= 2 * r - 1; j++){
                arr[j] = 0;
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i < m * 2; i += 1){
        if(arr[i] == 1){
            ans1++;
        }
        if(arr[i] == 2){
            ans2++;
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}