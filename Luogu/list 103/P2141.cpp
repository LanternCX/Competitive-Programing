#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int an[105];
    bool bn[105];
    for(int i = 0; i < 105; i++){
        bn[i] = false;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> an[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = 0; k < n; k++){
                if(an[i] + an[j] == an[k] && k != i && k != j && !bn[k]){
                    ans ++;
                    bn[k] = true;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
/**
 * 
 */

