#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; 
    cin >> n;
    vector<int> ans;
    for(int j = 0 ; j < n; j++){
        int an[3];
        for(int i = 0; i < 3; i++) cin >> an[i];

        if(an[0] > an[1]) swap(an[0], an[1]);
        if (an[0] > an[2]) swap(an[0], an[2]);
        if (an[1] > an[2]) swap(an[1], an[2]);

        ans.push_back(fabs(an[1] - an[0]) + fabs(an[1] - an[2]));
    }

    for(int i : ans){
        cout << i << '\n';
    }
    return 0;
}