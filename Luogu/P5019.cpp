#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> arr(N + 5);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int tag = 0;
    int ans = 0;
    int isTag = 0;
    for(int i = 0; i <= n + 1; i++){
        if(arr[i] == 0 && arr[i + 1] != 0 && !isTag){
            tag = i;
            isTag = 1;
        }
        if(arr[i] != 0 && arr[i + 1] == 0){
            int min = INT_MAX;
            for(int j = tag + 1; j <= i; j++){
                min = min > arr[j] ? arr[j] : min;
            }
            for(int j = tag + 1; j <= i; j++){
                arr[j] -= min;
            }
            i = 0;
            isTag = 0;
            ans += min;
        }
    }
    cout << ans;
    return 0;
}
/**
 * 4 3 2 5 3 5
 */