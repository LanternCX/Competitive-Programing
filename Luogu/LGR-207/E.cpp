#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, n;
    cin >> x >> n;
    vector<int> ans(5);
    for(int i = 0; i < n; i++){
        vector<int> arr(5);
        for(int i = 0; i < 5; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        for(int a : arr){
            if(a <= x){
                x -= a;
                ans[a - 1]++;
                break;
            }
        }
    }
    for(int i : ans){
        cout << i << ' ';
    }
    cout << '\n' << x;
    return 0;
}