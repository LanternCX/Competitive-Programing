#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> arr(4);
    int max = 0;
    int idx = 0;
    for(int i = 0; i < 4; i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
            idx = i;
        }
    }
    for(int i = 0; i < 4; i++){
        if(i == idx){
            continue;
        }else {
            cout << max - arr[i] << ' ';
        }
    }
    return 0;
}