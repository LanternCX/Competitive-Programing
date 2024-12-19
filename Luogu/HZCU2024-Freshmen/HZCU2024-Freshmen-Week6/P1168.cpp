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
    vector<int> temp;
    for(int i = 0; i < n; i++){
        temp.insert(lower_bound(temp.begin(), temp.end(), a[i]), a[i]);
        if(i % 2 == 0){
            cout << *(temp.begin() + temp.size() / 2) << '\n';
        }
    }
    return 0;
}
/**
 * 1 3 5 7 9 11 6
 * 
 * 3 1 5 9 8 7 6
 */