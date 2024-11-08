#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    set<int> b;
    for(int i = 1; i < n; i++){
        b.insert(abs(a[i] - a[i - 1]));
    }
    int temp = 1;
    bool ans = b.size() == n - 1;
    for(int i : b){
        if(temp != i){
            ans = 0;
            break;
        }
        temp++;
    }
    cout << (ans ? "Jolly" : "Not jolly");
    return 0;
}