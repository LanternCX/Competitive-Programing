#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int min = 1e7;
    for(int i = 0; i < n; i++){
        int w, d;
        cin >> w >> d;
        int temp = (d - 1) * 7 + w + 1;
        min = min < temp ? min : temp;
    }
    cout << min;
    return 0;
}