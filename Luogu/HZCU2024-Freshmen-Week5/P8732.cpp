#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct stu{
    ll s;
    ll a;
    ll e;
    ll sum;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<stu> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].s >> arr[i].a >> arr[i].e;
        arr[i].sum = arr[i].s + arr[i].a + arr[i].e;
    }
    sort(arr.begin(), arr.end(), [](stu a, stu b) -> int {
        // int res = a.sum < b.sum;
        // if(a.sum == b.sum){
        //     res = a.s + a.a < b.s + b.a;
        // }
        return a.sum < b.sum;
    });
    ll time = arr[0].a + arr[0].s;
    ll ans = time;
    for(int i = 1; i < n; i++){
        time +=  arr[i].a + arr[i].s + arr[i - 1].e;
        // cout << time << '\n';
        ans += time;
    }
    cout << ans;
    return 0;
}