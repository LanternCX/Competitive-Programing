#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char c;
    string s;
    while (true) {
        string temp;
        cin >> temp;
        s.append(temp);
        if (temp.find("E") != string::npos) {
            s.erase(s.find('E'));
            break;
        }
    }
    vector<string> ans1;
    int a[2] = {0 ,0};
    for(char c : s){
        if(c == 'W'){
            a[0]++;
        }
        if(c == 'L'){
            a[1]++;
        }

        if((a[0] >= 11 || a[1] >= 11) && abs(a[0] - a[1]) >= 2){
            ans1.push_back(to_string(a[0]) + ":" + to_string(a[1]));
            a[0] = 0;
            a[1] = 0;
        }
    }
    ans1.push_back(to_string(a[0]) + ":" + to_string(a[1]));

    a[0] = 0;
    a[1] = 0;
    vector<string> ans2;
    for(char c : s){
        if(c == 'W'){
            a[0]++;
        }
        if(c == 'L'){
            a[1]++;
        }

        if((a[0] >= 21 || a[1] >= 21) && abs(a[0] - a[1]) >= 2){
            ans2.push_back(to_string(a[0]) + ":" + to_string(a[1]));
            a[0] = 0;
            a[1] = 0;
        }
    }
    ans2.push_back(to_string(a[0]) + ":" + to_string(a[1]));

    for(string str : ans1){
        cout << str << '\n';
    }
    cout << '\n';
    for(string str : ans2){
        cout << str << '\n';
    }
    return 0;
}