#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct seq{
    int a;
    int idx;
};
vector<seq> sort(vector<seq> arr){
    int n = arr.size();
    vector<int> res(arr.size());
    for(int i = 0; i < n; i++){
        int idx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[idx].a > arr[j].a){
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
    return arr;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<seq> arr(n);
    for(int i = 0 ; i < n; i++){
        cin >> arr[i].a;
        arr[i].idx = i;
    }
    vector<seq> ans = sort(arr);
    for(seq i : ans){
        printf("%d ", i.idx + 1);
    }
    ll sum = 0;
    ll ans2 = 0;
    for(int i = 0; i < n - 1; i++){
        sum += ans[i].a;
        ans2 += sum;
    }
    printf("\n%.2lf", ans2 * 1.0 / n);
    return 0;
}