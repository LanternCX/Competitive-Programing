#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(2 * n + 1);
    int ans = 1;
    for(int i = 1; i <= 2 * n; i++){
        cin >> arr[i];
        if(arr[i] == i){
            ans = 0;
        }
    }
    for(int i = 1; i <= 2 * n; i++){
        if(arr[arr[i]] != i){
            ans = 0;
        }
    }
    cout << (ans ? "Yes" : "No");
    return 0;
}