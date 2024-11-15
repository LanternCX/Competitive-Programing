/**
 * To Be Done(TLE)
 */
#include <bits/stdc++.h>
using namespace std;
int is(int a, int b, int c){
    return a + b > c && a + c > b && b + c > a;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; i++){
        string s = to_string(i);
        vector<int> arr;
        int isok = 1;
        for(char ch : s){
            if(ch == 0){
                isok = 0;
            }
            arr.push_back(ch - '0');
        }
        if(!isok){
            continue;
        }

        isok = 0;
        sort(arr.begin(), arr.end());
        do{
            if(is(arr[0], arr[1], arr[2]) && is(arr[3], arr[4], arr[5])){
                isok = 1;
                break;
            }
        }while(next_permutation(arr.begin(), arr.end()));

        if(isok){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
/**
 * 111 276
 * 
 * 172778
 * 
 * 1 2 7 7 7 8
 * 
 * 1 7 7 2 7 8
 * 
 * 2,2,3,4,5,6
 * 
 * 
 * 6 4 2 
 * 5 3 2
 * 
 */