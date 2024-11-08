#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct person{
    string name;
    string job;
    int score;
    int rank;
    int id;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<person> arr; 
    for(int i = 0; i < n; i++){
        person p;
        cin >> p.name >> p.job >> p.score >> p.rank;
        p.id = i;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end(), [](person a, person b) -> int {
        int res = a.score > b.score;
        if(a.score == b.score){
            res = a.id < b.id;
        }
        return res;
    });

    map<string, int> m;
    m["HuFa"] = 2;
    m["ZhangLao"] = 4;
    m["TangZhu"] = 7;
    m["JingYing"] = 25;
    m["BangZhong"] = 1e7;

    map<string, int> w;
    w["BangZhu"] = 1;
    w["FuBangZhu"] = 2;
    w["HuFa"] = 3;
    w["ZhangLao"] = 4;
    w["TangZhu"] = 5;
    w["JingYing"] = 6;
    w["BangZhong"] = 7;

    vector<string> jobs = { "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};

    for(auto &p : arr){
        for(int i = 0; i < jobs.size(); i++){
            string s = jobs[i];
            if(m[s] > 0 && p.name != "absi2011" && p.job != "BangZhu" && p.job != "FuBangZhu"){
                m[s]--;
                p.job = s;
                break;
            }
        }
    }

    sort(arr.begin(), arr.end(), [w](person a, person b) -> int {
        bool res = w.at(a.job) < w.at(b.job);
        if(w.at(a.job) == w.at(b.job)){
            res = a.rank > b.rank;
            if(a.rank == b.rank){
                res = a.id < b.id;
            }
        }
        return res;
    });

    for(auto p : arr){
        cout << p.name << ' ' << p.job << ' ' << p.rank << '\n';
    }
    return 0;
}