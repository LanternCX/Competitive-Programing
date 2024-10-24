#include <bits/stdc++.h>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> arr;
    map<int, int> a;
    map<int, int> idx;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
        idx[x] = i;
    }
    int minx = 1e7;
    int tag = 0;
    sort(a.begin(), a.end());
    for(auto pair : a){
        if(minx > pair.second){
            tag = pair.first;
            minx = pair.second;
        }
    }
    cout << idx[tag] + 1 << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}