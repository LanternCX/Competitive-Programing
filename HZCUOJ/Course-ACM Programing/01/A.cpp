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

const int MAX_N = 1e7 + 1;
const int nimo[10] = {0, 5565709, 11733475, 18128484, 24671066, 31323382, 38063145, 44875629, 51750368, 58679537};
const int num[10] = {0, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000};
void sol(){
    int n;
    cin >> n;
    double ans;
    int st;
    for (int i = 9; i >= 0; i--){
        if (n > num[i]){
            ans = nimo[i];
            st = num[i] + 1;
            break;
        }
    }
    for (int i = st; i <= n; i++){
        ans += log10(i);
    }
    printf("%d\n", (int)ans + 1);
	
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}