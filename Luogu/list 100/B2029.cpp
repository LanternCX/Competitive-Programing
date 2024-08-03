#include<bits/stdc++.h>

using namespace std;

int main(){
    int h,r;
    cin >> h >> r;
    double pai = 3.14;
    int n = ceil(20 / (pai * r * r * h/1000));
    cout << n;
    return 0;
}