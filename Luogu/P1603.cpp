#include <bits/stdc++.h>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> dict = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"a", 1},
    {"both", 2},
    {"another", 1},
    {"first", 1},
    {"second", 2},
    {"third", 3},
};
int main(){
    vector<int> numList;
    for(int i = 0; i < 6; i++){
        string s;
        cin >> s;
        if (dict.find(s) == dict.end()) {
            continue;
        }

        int n = dict[s];
        int num = (n * n) % 100;

        int idx = 0;
        if (numList.empty()) {
            numList.insert(numList.begin() + idx, num);
            continue;
        }
        for(int i = 0; i < numList.size(); i++){
            if(numList[i] < num && numList[i + 1] > num){
                idx = i + 1;
            }
        }
        idx = idx == 0 ? (numList[0] > num ? 0 : numList.size()) : idx;
        numList.insert(numList.begin() + idx, num);
    }
    
    string ans = "";
    for(int s : numList){
        ans += s < 10 ? "0" + to_string(s) : to_string(s);
    }
    cout << (ans[0] == '0' ? ans.erase(0, 1) : ans);
    if (numList.empty()) {
        cout << 0;
    }
    return 0;
}
/*
one two three four five six
*/