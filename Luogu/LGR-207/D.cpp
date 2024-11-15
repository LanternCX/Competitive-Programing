#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int is = 1;
        for(int j = i + 1; j < n; j++){
            if(a[i] <= a[j]){
                is = 0;
            }
        }
        if(is){
            ans++;
        }
    }
    cout << ans;
    return 0;
}