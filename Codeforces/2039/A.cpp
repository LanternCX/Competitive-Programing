#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    // vector<int> arr;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= 100; j++){
    //         if(j % i == i - 1 && lower_bound(arr.begin(), arr.end(), j) == arr.end()){
    //             arr.push_back(j);
    //             break;
    //         }
    //     }
    // }
    // for(int x : arr){
    //     cout << x << ' ';
    // }
    for(int i = 1; i < n * 2; i += 2){
        cout << i << ' ';
    }
    cout << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * n = 3
 * 1 2 3
 * 2 % 1 = 0
 * 3 % 2 = 1
 * 5 % 3 = 2
 * 19 % 4 = 3
 * 
 */