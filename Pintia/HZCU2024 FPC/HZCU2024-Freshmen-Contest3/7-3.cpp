#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> a;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        string temp;
        bool isLower = 0;
        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                isLower = 1;
            }
        }
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch >= 'A' && ch <= 'Z' && isLower){
                temp.push_back('_');
                temp.push_back(ch);
            }else if(ch >= 'a' && ch <= 'z'){
                char tag = ch - ('a' - 'A');
                temp.push_back(tag);
            }else {
                temp.push_back(ch);
            }
        }
        if(find(a.begin(), a.end(), temp) == a.end()){
            a.push_back(temp);
        }
    }
    cout << a.size() << '\n';
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
        if(i != a.size() - 1){
            cout << '\n';
        }
    }
    return 0;
}
/**
    10
    code_attribute
    lineNumberTable
    LINE_NUMBER_TABLE
    FIELD_INFO
    codeAttribute
    javaClass
    CODE_ATTRIBUTE
    field_info
    line_number_table
    JAVA_CLASS
 */