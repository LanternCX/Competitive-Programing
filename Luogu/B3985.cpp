#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int an[3];
    cin >> an[0] >> an[1] >> an[2];
    map<int, char> m = { {1, 'B'}, {2 , 'Y'}, {3, 'R'}};
    cout << m[an[0]] << m[an[1]] << m[an[2]];
    return 0;
}