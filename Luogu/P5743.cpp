#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << ((1 << (n - 1)) * 3 - 2);
    return 0;
}