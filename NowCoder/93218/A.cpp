#include <bits/stdc++.h>
using namespace std;
void slove(){
    int n;
    cin >> n;
    map<int, int> a;
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
        b[i] = x;
    }
    int minn = 1e7;
    int num = 0;
    for(int i : b){
        if(minn > i && a[i] > 2){
            minn = i;
            num = i;
        }
    }
    if(minn == 1e7){
        cout << "no" << "\n";
    }else {
        cout << "yes" << "\n";
        cout << minn * 3 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        slove();
    }
    return 0;
}