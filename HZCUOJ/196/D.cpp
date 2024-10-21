#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n;
    while (cin >> n) {
        long long sum = 0;
        int temp = sqrt(n);
        for (int i = 1; i <= temp; i++) {
            sum += n / i;
        }

        for (int i = 1; i <= n / (temp + 1); i++) {
            sum += i * (n / i - n / (i + 1));
        }
        
        cout << sum << '\n';
    }
    return 0;
}