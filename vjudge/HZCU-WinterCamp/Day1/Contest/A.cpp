#include <bits/stdc++.h>
using namespace std;
struct node{
    int a, idx, vis;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = {x, i + 1, 0};
    }
    vector<int> b(k);
    for(int i = 0; i < k; i++){
        cin >> b[i];
    }
    int tag = 0;
    do{
        int is = 1;
        for(int i = 0; i < k; i++){
            if(arr[i].a < b[i]){
                is = 0;
            }
        }
        if(is){
            tag = 1;
            break;
        }
    }while(next_permutation(arr.begin(), arr.end(), [](node a, node b) ->int {
        return a.idx < b.idx;
    }));
    if(tag ){
        for(node nd : arr){
            cout << nd.idx << ' ';
        }
    }else{
        cout << -1;
    }
    return 0;
}
/**
 *  1 9 1 9 8 1
    1 1 4 5 1 4
 */