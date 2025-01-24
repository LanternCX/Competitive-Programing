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
    sort(arr.begin(), arr.end());
    cout << arr[ceil(n / 2)] - 1;
    return 0;
}
/**
 * 1 2 3 4 5
 * 1 2 3 4 5 6
 */