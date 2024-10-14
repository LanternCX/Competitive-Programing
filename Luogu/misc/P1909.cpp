#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int min = INT_MAX;
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        int res = (n % a == 0 ? n / a : n / a + 1) * b;
        min = res > min ? min : res;
    }
    cout << min;
    return 0;
}