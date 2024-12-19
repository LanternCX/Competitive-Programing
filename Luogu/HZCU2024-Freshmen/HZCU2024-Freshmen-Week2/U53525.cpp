#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> pre(n);
    pre[0] = arr[0];
    for(int i = 1; i < n; i++){
        pre[i] = arr[i] + pre[i - 1];
    }
    for(int i : pre){
        cout << i << ' ';
    }
    return 0;
}