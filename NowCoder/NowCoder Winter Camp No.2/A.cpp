#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> a(7);
    int ans = 1;
    for(int i = 0; i < 7; i++){
        int x;
        cin >> x;
        if(x != 1 && x != 2 && x != 3 && x != 5 && x != 6){
            ans = 0;
        }
    }
    cout << (ans ? "YES" : "NO");
    return 0;
}