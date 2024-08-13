#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<string> list;
    int n;
    cin >> n;
    string pre = "";
    for(int i = 0; i < n; i++){
        string type;
        cin >> type;
        string s = "";
        if(type == "a"){
            pre = "a";
            int a,b;
            cin >> a >> b;
            s += to_string(a) + "+" + to_string(b) + "=" + to_string(a + b);
            list.push_back(s);
            continue;
        }
        if(type == "c"){
            pre = "c";
            int a,b;
            cin >> a >> b;
            s += to_string(a) + "*" + to_string(b) + "=" + to_string(a * b);
            list.push_back(s);
            continue;
        }
        if(type == "b"){
            pre = "b";
            int a,b;
            cin >> a >> b;
            s += to_string(a) + "-" + to_string(b) + "=" + to_string(a - b);
            list.push_back(s);
            continue;
        }

        if(pre == "a"){
            int b;
            int a = stoi(type);
            cin >> b;
            s += to_string(a) + "+" + to_string(b) + "=" + to_string(a + b);
            list.push_back(s);
            continue;
        }
        if(pre == "b"){
            int b;
            int a = stoi(type);
            cin >> b;
            s += to_string(a) + "-" + to_string(b) + "=" + to_string(a - b);
            list.push_back(s);
            continue;
        }
        if(pre == "c"){
            int b;
            int a = stoi(type);
            cin >> b;
            s += to_string(a) + "*" + to_string(b) + "=" + to_string(a * b);
            list.push_back(s);
            continue;
        }
    }

    for(string s : list){
        cout << s << endl;
        cout << s.length() << endl;
    }
    return 0;
}