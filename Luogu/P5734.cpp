#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<string> ans;
    for(int i = 0; i < n; i++){
        int tag;
        cin >> tag;
        switch (tag) {
            case 1: {
                string s;
                cin >> s;
                str += s;
                ans.push_back(str);
                break;
            }
            case 2: {
                int a,b;
                cin >> a >> b;
                str = str.substr(a, b);
                ans.push_back(str);
                break;
            }
            case 3: {
                int a;
                string s;
                cin >> a >> s;
                str = str.insert(a,s);
                ans.push_back(str);
                break;
            }
            case 4:{
                string s;
                cin >> s;
                int a = str.find(s) == string::npos ? -1 : str.find(s);
                ans.push_back(to_string(a));
            }
        }
    }
    for(string s : ans){
        cout << s << endl;
    }
    return 0;
}
/**
 *
4
ILove
1 Luogu
2 5 5
3 3 guGugu
4 ai
*/