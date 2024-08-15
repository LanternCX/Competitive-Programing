#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n2(int n){
    ll res = 1;
    for(int i = 0; i < n; i++){
        res *= 2;
    }
    return res;
}
int main(){
    string s;
    getline(cin, s); 
    string temp = "";
    set<ll> nums;
    for(char c : s){
        if(c == ' '){
            nums.insert(stoi(temp));
            temp = "";
        }
        temp.push_back(c);
    }
    nums.insert(stoi(temp));
    ll sum = 0;
    for(ll n : nums){
        sum += n;
    }
    cout << (sum * n2(nums.size() - 1));
    return 0;
}