#include <bits/stdc++.h>
using namespace std;
vector<int> bsort(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}
int main(){
    int a,b,c;cin >> a >> b >> c;
    vector<int> arr = {a,b,c};
    vector<int> ans = bsort(arr);
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}