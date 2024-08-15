#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Stu{
    string name;
    int sc[3];
};

struct Pair{ 
    Stu a;
    Stu b;
};

int main(){
    vector<Stu> stus;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        Stu n;
        cin >> n.name >> n.sc[0] >> n.sc[1] >> n.sc[2];
        stus.push_back(n);
    }

    vector<Pair> ans;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bool tag = true;
            for(int k = 0; k < 3; k++){
                if(stus[i].sc[k] - stus[j].sc[k] < 0 ? stus[i].sc[k] - stus[j].sc[k] < -5 : stus[i].sc[k] - stus[j].sc[k] > 5){
                    tag = false;
                }
            }
            int sum[2] = {stus[i].sc[0] + stus[i].sc[1] + stus[i].sc[2], stus[j].sc[0] + stus[j].sc[1] + stus[j].sc[2]};
            if (sum[0] - sum[1] < 0 ? sum[0] - sum[1] < -10 : sum[0] - sum[1] > 10) {
                tag = false;
            }
            if(tag){
                Pair p = {stus[i], stus[j]};
                ans.push_back(p);
            }
        }
    }

    for(Pair p : ans){
        cout << p.a.name << ' ' << p.b.name << endl;
    }
    return 0;
}