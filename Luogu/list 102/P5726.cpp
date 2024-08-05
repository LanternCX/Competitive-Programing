#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int an[1005];
    int max = -114514, min = 114514;
    for(int i = 0; i < n; i++){
        cin >> an[i]; 
        max = max < an[i] ? an[i] : max;
        min = min > an[i] ? an[i] : min;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += an[i];
    }
    sum -= max;
    sum -= min;
    cout << fixed << setprecision(2) << (sum * 1.0 / (n - 2));
    return 0;
}