#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int mx = *max_element(arr.begin(), arr.end());

    map<int, int> cnt;
    for(int x : arr){
        cnt[x]++;
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        for(int x = i; x <= N; x += i){
            int y = x ^ i;
            if(x < y && gcd(x, y) == i){
                ans += 1ll * cnt[x] * cnt[y];
            }
        }
    }
    cout << ans;
    return 0;
}
/**
 * a xor b = gcd(a, b);
 * a xor b = a + b - 2 * a and b = gcd(a, b)
 * (a + b) / gcd(a, b) - 2 * a and b / gcd(a, b) = 1
 * a // gcd(a, b), b // gcd(a, b)
 * 
 * gcd(x, x xor y)
 * a xor b = gcd(a, b) ==> x + gcd(a, b) == y
 */