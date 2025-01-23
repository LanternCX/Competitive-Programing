#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    map<int, int> mp;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
        cnt++;
    }
    vector<int> arr;
    for(auto p : mp){
        arr.push_back(p.second);
    }
    
    if(arr.size() != 2){
        cout << "No";
    }else if(arr[0] != arr[1]){
        cout << "No";
    }else{
        if(cnt % 2 == 1){
            cout << "No";
        }else {
            cout << "Yes";
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}