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
    int x;
    cin >> x;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(ans = 0; ans < n; ans++) {
        if(arr[ans] >= x){
            break;
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}
