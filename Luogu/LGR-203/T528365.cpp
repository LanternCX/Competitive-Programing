#include <bits/stdc++.h>
using namespace std;
struct Stu{
    int id;
    int sc;
    int w;
};
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
string getAns(int sum, int count){
    if(sum % count == 0){
        return to_string(sum / count);
    }
    int d = gcd(sum, count);
    sum /= d;
    count /= d;
    int n = sum / count;
    sum -= n * count;
    string res;
    if(n != 0){
        res += to_string(n) + '+';
    }
    res += to_string(sum) +  '/' + to_string(count);
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<Stu>> clss;
    for(int k = 0; k < n; k++){
        int p;
        cin >> p;
        vector<int> id(p);
        vector<int> sc(p);
        vector<int> w(p);
        for(int i = 0; i < p; i++){
            cin >> id[i];
        }
        for(int i = 0; i < p; i++){
            cin >> sc[i];
        }
        for(int i = 0; i < p; i++){
            cin >> w[i];
        }
        sort(id.begin(), id.end());
        vector<Stu> cls;
        for(int i = 0; i < p; i++){
            Stu s;
            s.id = id[i];
            s.sc = sc[i];
            cls.push_back(s);
        }
        sort(cls.begin(), cls.end(), [](Stu a, Stu b) -> int {
            return a.sc > b.sc;
        });
        for(int i = 0; i < cls.size(); i++){
            cls[i].w = w[i];
        }
        clss.push_back(cls);
    }
    int tag;
    cin >> tag;
    int sum = 0;
    int count = 0;
    for(int k = 0; k < n; k++){
        for(auto s : clss[k]){
            if (s.id == tag) {
                count ++;
                sum += s.w;
            }
        }
    }
    
    cout << getAns(sum, count);
    return 0;
}
/**
 * To be submit
 */