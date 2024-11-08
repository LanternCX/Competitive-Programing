#include <bits/stdc++.h>
using namespace std;
struct stu{
    int cn;
    int id;
    int sum;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<stu> arr(n);
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        stu s = {a, i + 1, a + b + c};
        arr[i] = s;
    }
    sort(arr.begin(), arr.end(), [](stu a, stu b) -> int {
        int res = a.sum > b.sum;
        if(a.sum == b.sum){
            res = a.cn > b.cn;
            if(a.cn == b.cn){
                res = a.id < b.id;
            }
        }
        return res;
    });
    for(int i = 0; i < 5; i++){
        cout << arr[i].id << ' ' << arr[i].sum << '\n';
    }
    return 0;
}