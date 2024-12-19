#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    map<int, map<int, int>> a;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        if(x == 1){
            int x, y, k;
            cin >> x >> y >> k;
            a[x][y] = k;
        }else {
            int x, y;
            cin >> x >> y;
            cout << a[x][y] << endl;
        }
    }
    return 0;
}