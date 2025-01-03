#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 32;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<int> bin(N);
    int idx = 0;
    int temp = abs(n);
    while (temp > 0) {
        bin[idx++] = temp % 2;
        temp /= 2;
    }

    if(n < 0){
        for(int i = 0; i < N; i++){
            bin[i] = !bin[i];
        }
        bin[0]++;
        for(int i = 0; i < N; i++){
            if(bin[i] > 1){
                bin[i + 1] += bin[i] % 2;
            }
        }
    }
    
    int op;
    idx--;
    while(cin >> op){
        int x; 
        cin >> x;
        if(op == 1){
            bin[x] = 0;
        }
        if(op == 2){
            bin[x] = 1;
        }
        if(op == 3){
            bin[x] = !bin[x];
        }
    }

    int ans = 0;
    for(int i = N - 1; i >= 0; i--){
        ans = ans * 2 + bin[i];
    }
    cout << ans;
    return 0;
}