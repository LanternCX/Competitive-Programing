#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void sol(){
    int n;
    cin >> n;
    vector<int> arr(1);
    cin >> arr[0];
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        if(arr[arr.size() - 1] == x){
            continue;
        }
        arr.push_back(x);
    }
    cout << arr.size() << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}