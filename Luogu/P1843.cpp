#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int l = 0, r = 5e5 + 10;
    while(l <= r){
        int mid = (l + r) / 2;
        int sum = 0;
        for(int x : arr){
            if(x <= mid * a){
                continue;
            }
            sum += (x - mid * a) / b;
            if((x - mid * a) % b != 0){
                sum++;
            }
        }
        if(sum <= mid){
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
/**
 * 1 2 3 
 * 2 2 3
 * 
 * 1 3 4
 * 2 3 2
 * 0 0 2
 * 
 */