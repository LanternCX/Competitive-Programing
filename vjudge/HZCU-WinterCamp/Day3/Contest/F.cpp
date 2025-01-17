#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int fa[N + 10];
using ll = long long;
int root(int x){
    return fa[x] = fa[x] == x ? x : root(fa[x]);
}
void merge(int x, int y){
    fa[root(x)] = fa[root(y)];
}
int query(int x, int y){
    return root(x) == root(y); 
}
struct node{
    ll x, y;
};
struct route{
    int x, y;
    double w;
};
double dist(node a, node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int s, p;
    cin >> s >> p;
    vector<node> arr(p);
    for(int i = 0; i < p; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    vector<route> routes;
    for(int i = 0; i < p; i++){
        for(int j = i + 1; j < p; j++){
            routes.push_back({i, j, dist(arr[i], arr[j])});
        }
    }
    sort(routes.begin(), routes.end(), [](route a, route b) -> int {
        return a.w < b.w;
    });
    for(int i = 0; i <= p; i++){
        fa[i] = i;
    }
    // for(int i = routes.size() - 1; i >= 0; i--){
    //     if(!query(routes[i].x, routes[i].y)){
    //         merge(routes[i].x, routes[i].y);
    //         s--;
    //     }
    //     if(s <= 0){
    //         break;
    //     }
    // }
    // for(int i = 0; i < p; i++){
    //     cout << fa[i] << ' ';
    // }
    // cout << '\n';
    vector<route> ans;
    int cnt = 0;
    for(route nd : routes){
        if(!query(nd.x, nd.y)){
            ans.push_back(nd);
            merge(nd.x, nd.y);
            cnt++;
        }
        if(cnt >= p - s){
            break;
        }
    }

    // for(int i = 0; i < p; i++){
    //     cout << fa[i] << ' ';
    // }
    // cout << '\n';
    double mx = 0;
    for(route nd : ans){
        mx = max(nd.w, mx);
    }
    if(ans.empty()){
        printf("%.2lf", 0.0);
    }else {
        printf("%.2lf", mx);
    }
    return 0;
}