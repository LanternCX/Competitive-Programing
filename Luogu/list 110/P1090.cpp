#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int x : arr){
        pq.push(x);
    }
    int ans = 0;
    while (pq.size() > 1) {
        int temp = 0;
        temp += pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();
        ans += temp;
        pq.push(temp);
    }

    cout << ans;
    return 0;
}

/**
 * 1 2 9
 * 
 */