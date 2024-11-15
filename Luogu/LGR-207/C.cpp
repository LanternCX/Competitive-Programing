#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
struct node{
    ll k, d, a, id, sc;
};
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n; 
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        int k, d, a;
        scanf("%d/%d/%d", &k, &d, &a);
        node x = {k, d, a, i};
        ll sc = 0;
        if(k - d >= 10){
            sc = k * (k - d) + a;
        }else if(k >= d) {
            sc = (k - d + 1) * 3 + a;
        }else {
            sc = a * 2;
        }
        x.sc = sc;
        arr[i] = x;
    }
    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.sc > b.sc;
    });
    cout << arr[0].id + 1;
    return 0;
}