#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    vector<int> ans;
    for(int i  = x; i <= y; i++){
        if(i % 4 == 0 && i % 100 != 0){
            ans.push_back(i);
        }else if (i % 400 == 0) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}