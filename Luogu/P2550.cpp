#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int an[8];
    int ans[8];
    for(int i = 0; i < 7; i++){
        ans[i] = 0;
    }
    for(int i = 0; i < 7; i++){
        cin >> an[i];
    }
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = 0; j < 7; j++){
            int bn;
            cin >> bn;
            for(int k = 0; k < 7; k++){
                if(bn == an[k]){
                    temp++;
                }
            }
        }
        ans[7 - temp]++;
    }

    for(int i = 0; i < 7; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}