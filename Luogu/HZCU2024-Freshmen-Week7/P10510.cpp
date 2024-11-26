#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int s[10010];
ll to10(ll digit){
    ll res = 0;
    for(int i = digit; i >= 0; i--){
        res = res * 3 + s[i];
    }
    return res;
}

ll to3(ll v){
    ll digit = 0;
    while (v > 0) {
        s[digit++] = v % 3;
        v /= 3;
    }
    return digit;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll v, q;
    cin >> v >> q;
    ll digit = to3(v);
    for(int i = 0; i < q; i++){
        ll op, x;
        cin >> op >> x;
        digit = max(x + 1, digit);
        if(op == 1){
			s[x] = (s[x] + 1) % 3;
 		}else if(op == 2){
			s[x] = (s[x] + 2) % 3;
		}else if(op == 3){
			s[x] = (3 - s[x]) % 3;
		};
        cout << to10(digit) << '\n';
    }
    return 0;
}