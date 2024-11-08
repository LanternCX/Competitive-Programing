#include <bits/stdc++.h>
using namespace std;
int bubble_sort(vector<int> &a){
    int res = 0;
    bool tag = true;
    while (tag) {
        tag = false;
        for(int i = 1; i < a.size(); i++){
            if(a[i] < a[i - 1]){
                tag = true;
                swap(a[i], a[i - 1]);
                res++;
            }
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = bubble_sort(a);
    cout << ans;
    return 0;
}