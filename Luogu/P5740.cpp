#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> names;
    int sc[1000][3];
    int max = -114514;
    int idx;
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        names.push_back(name);
        cin >> sc[i][0] >> sc[i][1] >> sc[i][2];
        int sum = sc[i][0] + sc[i][1] + sc[i][2];
        if(max < sum){
            max = sum;
            idx = i;
        }
    }
    cout << names[idx] << ' ' << sc[idx][0] << ' ' << sc[idx][1] << ' ' << sc[idx][2];
    return 0;
}