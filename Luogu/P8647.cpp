#include <bits/stdc++.h>
using namespace std;
struct sq{
    int a, b;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<sq> arr(n);
    int l = 1, r = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].b;
        int temp = max(arr[i].a, arr[i].b);
        r = max(temp, r);
    }
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        // cout << l << ' ' << r << ' ' << mid  << '\n';
        int sum = 0;
        for(int i = 0; i < n; i++){
            int a = arr[i].a;
            int b = arr[i].b;
            sum += (a / mid) * (b / mid);
        }
        // cout << "sum: " << sum << '\n';
        if(sum >= k){
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
/**
 * 6 * 5:
 * 1 1 1 1 1 1
 * 1 1 1 1 1 1
 * 1 1 1 1 1 1
 * 1 1 1 1 1 1
 * 1 1 1 1 1 1
 * 
 * a / mid * b / mid
 */