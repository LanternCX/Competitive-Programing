#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    vector<int> arr;
    map<int, int> mp1;
    map<int, int> mp2;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(mp1.find(x) == mp1.end()){
            mp1[x] = i;
        }
        mp2[x] = i;
        arr.push_back(x);
    }
    int det = 0;
    set<int> tags;
    for(int x : arr){
        int temp = mp2[x] - mp1[x];
        if(temp >= det){
            if(temp == det){
                tags.insert(x);
            }else {
                tags = {x};
            }
            det = temp;
        }
    }
    int ans = 1;
    for(int tag : tags){
        int isLoop = 1;
        int x1 = mp1[tag];
        int x2 = mp2[tag];
        for(int i = 0; i <= (x2 - x1) / 2; i++){
            if(arr[x1 + i] != arr[x2 - i]){
                isLoop = 0;
                break;
            }
        }
        if(isLoop){
            ans = max(ans, x2 - x1 + 1);
        }
    }
    cout << ans << '\n';
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
/**
 * To Be Done
 * 1 9 1 9 8 10
 * 1 2 3 2 1
 */