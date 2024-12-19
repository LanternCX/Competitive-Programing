#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> pre[i];
    }
    for(int i = n - 1; i > 0; i--){
        arr[i] = pre[i] - pre[i - 1];
    }
    arr[0] = pre[0];
    for(int i : arr){
        cout << i << ' ';
    }
    return 0;
}