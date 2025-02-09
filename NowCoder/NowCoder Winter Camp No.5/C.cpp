#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ctoi(char ch){
    return ch - '0';
}
void sol(){
    ll n, x, y;
    cin >> n >> x >> y;
    string a, b, c;
    cin >> a >> b >> c;
    vector<vector<ll>> cnt(2, vector<ll>(2));
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        ll ax = ctoi(a[i]);
        ll bx = ctoi(b[i]);
        ll cx = ctoi(c[i]);
        if((ax ^ bx) != cx){
            cnt[ax][bx]++; 
            sum++;
        }
    }
    ll ans = 0;
    if(y >= 2 * x){
        for(auto arr : cnt){
            for(auto num : arr){
                ans += num * x;
            }
        }
    }else if (y < 2 * x) {
        ll mx = 0;
        for(auto arr : cnt){
            for(auto x : arr){
                mx = max(mx, x);
            }
        }
        if(2 * mx > sum){
            ans = (sum - mx) * y + (sum - 2 * (sum - mx)) * x;
        }else{
            ans = sum / 2 * y + sum % 2 * x;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 1e6?
 * 
 * 1010101010
 * 0111010100
 * 1010010110
 * 
 * 对于每一位选择交换或者重置使得代价最小
 * 然后就能使得总代价最小？
 * 
 * 交换两位使得答案正确 贡献为 y / 2
 * 重置一位使得答案正确，贡献为 x
 * 实际上只要全交换或者全重置就好了？
 * 
 * 不满足答案的情况：
 * 1 0 0
 * 0 1 0
 * 1 1 1
 * 0 0 1
 * 
 * 实际上
 * 1 1 1
 * 0 1 0
 * 交换为
 * 0 1 1
 * 1 1 0
 * 也可以
 * 
 * 所以这四组可以进行任意交换
 * 
 * 还有什么不能交换的情况
 * 
 * 
 * 
 */