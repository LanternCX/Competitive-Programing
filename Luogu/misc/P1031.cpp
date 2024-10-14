#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int avg = sum / n;
    for(int &n : arr){
        n -= avg;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i]){
            arr[i + 1] += arr[i];
            arr[i] = 0;
            ans++;
        }
    }
    cout << ans;
    return 0;
}