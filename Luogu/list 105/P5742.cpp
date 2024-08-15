#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Stu{
    int id;
    double sc[3];
    bool isEx;
};
int main(){
    int n;
    cin >> n;
    vector<Stu> stus;
    for(int i = 0; i < n; i++){
        Stu s;
        cin >> s.id >> s.sc[0] >> s.sc[1];
        s.sc[2] = s.sc[0] * 7 + s.sc[1] * 3;
        s.isEx = s.sc[2] >= 800 && s.sc[0] + s.sc[1] > 140;
        stus.push_back(s);
    }
    
    for(Stu s : stus){
        cout << (s.isEx ? "Excellent" : "Not excellent") << endl;
    }
    return 0;
}