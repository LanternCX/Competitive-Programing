#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int an[101];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> an[i];
    }

    int ans[101];
    for(int i = 0; i <= 100; i++){
        ans[i] = -1;
    }

    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = i; j >= 0; j--){
            if(an[i] > an[j]){
                temp++;
            }
        }
        ans[i] = temp;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}