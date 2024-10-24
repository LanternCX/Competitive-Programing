#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> an;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        an.push_back(a);
    }

    sort(an.begin(), an.end());
    int temp = m;
    int tag = an.size() - 1;
    int ans = 0;
    while (temp > 0) {
        temp -= an[tag];
        tag--;
        ans++;
    }
    cout << ans;
    return 0;
}