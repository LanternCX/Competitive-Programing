#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int an[3500];
    for(int i = 0; i < n; i++){
        cin >> an[i];
    }
    int ans = 1145141419;
    for(int i = 0; i < (m == n ? 1 : n - m); i++){
        int sum = 0;
        for(int j = i; j < i + m; j++){
            sum += an[j];
        }
        ans = ans < sum ? ans : sum;
    }
    cout << ans;
    return 0;
}

