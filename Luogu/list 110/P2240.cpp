#include <bits/stdc++.h>
using namespace std;
struct Bag {
    int m;
    int v;
};
vector<Bag> sort(vector<Bag> bags){
    int n = bags.size();
    vector<Bag> res = bags;
    for(int i = 0; i < n; i++){
        int idx = i;
        for(int j = i + 1; j < n; j++){
            if(res[idx].v * 1.0 / res[idx].m < res[j].v * 1.0 / res[j].m){
                idx = j;
            }
        }
        swap(res[i], res[idx]);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<Bag> arr(n);
    for(int i = 0; i < n; i++){
        int a, b;
        Bag bag;
        cin >> bag.m >> bag.v;
        arr[i] = bag;
    }
    arr = sort(arr);
    double ans = 0;
    for(Bag b : arr){
        if(t == 0){
            break;
        }
        if(t - b.m <= 0){
            ans += t * (b.v * 1.0 / b.m);
            break;
        }else {
            t -= b.m;
            ans += b.v;
        }
    }
    printf("%.2lf", ans);
    return 0;
}