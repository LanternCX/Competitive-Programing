#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, m;
    cin >> l >> m;
    bool an[10001];
    for(int i = 0; i <= l; i++){
        an[i] = true;
    }

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;

        for(int j = a; j <= b; j++){
            an[j] = false;
        }
    }

    int ans = 0;
    for(int i = 0; i <= l; i++){
        if(an[i] == true){
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}