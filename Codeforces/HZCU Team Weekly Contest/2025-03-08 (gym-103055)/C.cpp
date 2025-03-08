#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
struct node{
    int x, y, z;
};
void sol(){
    vector<node> arr(8);
    for(int i = 0; i < 8; i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }
    auto vec = [&](node a, node b){
        node res = {b.x - a.x, b.y - a.y, b.z - a.z};
        return res;
    };
    auto calc = [&](node a, node b, node c){
        ll x = a.x * b.x + a.y * b.y + a.z * b.z;
        ll y = a.x * c.x + a.y * c.y + a.z * c.z;
        ll z = c.x * b.x + c.y * b.y + c.z * b.z;
        ll distx = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
        ll disty = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y) + (a.z - c.z) * (a.z - c.z);
        ll distz = (c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y) + (c.z - b.z) * (c.z - b.z);
        return x == 0 && y == 0 && z == 0 && (distx == disty && disty == distz);
    };
    for(int a = 0; a < 8; a++){
        vector<node> edge;
        for(int b = 0; b < 8; b++){
            if(b == a){
                continue;
            }
            edge.push_back(vec(arr[a], arr[b]));
        }
        int siz = edge.size();
        int cnt = 0;
        for(int i = 0; i < siz; i++){
            for(int j = i + 1; j < siz; j++){
                for(int k = j + 1; k < siz; k++){
                    cnt += calc(edge[i], edge[j], edge[k]);
                    if(calc(edge[i], edge[j], edge[k])){
                    }
                }
            }
        }
        if(cnt != 1){
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}