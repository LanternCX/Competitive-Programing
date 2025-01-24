#include <bits/stdc++.h>
using namespace std;
const string work = "work";
const string noon = "noon";
const string slp = "sleep";
using ll = long long;
struct node{
    string id;
    string date;
    string time;
    string stat = "";
    ll ts;
};
ll stot(string time){
    return stoi(time.substr(0, 2)) * 60 * 60 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}
int getMonth(string date){
    return stoi(date.substr(5,2));
}
int getYear(string date){
    return stoi(date.substr(0,4));
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, y, m;
    cin >> n >> y >> m;
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].id >> arr[i].date >> arr[i].time;
        arr[i].ts = stot(arr[i].time);
        if(arr[i].ts >= stot("07:00:00") && arr[i].ts <= stot("09:00:00") ||
            arr[i].ts >= stot("18:00:00") && arr[i].ts <= stot("20:00:00")){
            arr[i].stat = work;
        }
        if(arr[i].ts >= stot("11:00:00") && arr[i].ts <= stot("13:00:00")){
            arr[i].stat = noon;
        }
        if(arr[i].ts >= stot("22:00:00") && arr[i].ts <= stot("24:00:00") ||
        arr[i].ts >= stot("00:00:00") && arr[i].ts <= stot("01:00:00")){
            arr[i].stat = slp;
        }
    }
    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.date < b.date;
    });
    // {idstat, t}
    map<string, int> mp;
    vector<int> ans(3);
    for(node nd : arr){
        string log = nd.id + nd.stat;
        int tagy = getYear(nd.date);
        int tagm = getMonth(nd.date);
        if(tagm == m && tagy == y && mp[log] == 0){
            if(nd.stat == work){
                ans[0]++;
                mp[log]++;
                continue;
            }
            if(nd.stat == noon){
                ans[1]++;
                mp[log]++;
                continue;
            }
            if(nd.stat == slp){
                ans[2]++;
                mp[log]++;
                continue;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
/**
 * 
 */