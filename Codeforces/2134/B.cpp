#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b==0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll modinv(ll a, ll m) {
    ll x, y;
    ll g = extgcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}

void sol(){
    const int N = 200;
    vector<int> primes;
    vector<int> vis(N + 1, 0);
    for (int i = 2; i <= N; i++){
        if (!vis[i]) {
            primes.push_back(i);
            if ((ll)i * i <= N) {
                for (int j = i * i; j <= N; j += i) {
                    vis[j] = 1;
                } 
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto &x : a) {
            cin >> x;
        }

        ll p = -1;
        ll up = k + 1;
        for (int pr : primes) {
            if ((ll)pr > up) {
                break;
            }
            if (k % pr != 0) { 
                p = pr;
                break; 
            }
        }
        if (p == -1) {
            int LIM2 = min<ll>(2000, up);
            vector<char> isC(LIM2+1, 0);
            for (int i=2;i<=LIM2;i++){
                if (!isC[i]) {
                    if (k % i != 0 && i <= up) { p = i; break; }
                    if ((ll)i*i <= LIM2) {
                        for (int j=i*i;j<=LIM2;j+=i) isC[j]=1;
                    }
                }
            }
        }
        if (p == -1) {
            ll temp = k + 1;
            bool is = (temp >= 2);
            for (ll d=2; d*d <= temp && is; ++d) {
                if (temp % d == 0) {
                    is = 0;
                }
            } 
            if (is && k % temp != 0) {
                p = temp;
            }
        }

        if (p == -1) {
            for (int i=0;i<n;i++) {
                if (i) cout << ' ';
                cout << a[i];
            }
            cout << '\n';
            continue;
        }

        ll invk = modinv(k % p, p);

        vector<ll> ans(n);
        for (int i = 0; i < n; i++){
            ll ai = a[i];
            ll need = ((- (ai % p)) + p) % p;
            ll xi = (need * invk) % p;
            ans[i] = ai + xi * k;
        }

        for (int i = 0; i < n; i++){
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}