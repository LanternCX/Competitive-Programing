#include <bits/stdc++.h>
using namespace std;
struct Stu{
    string name;
    int age;
    int sc;
};
Stu calc(Stu stu){
    stu.sc = stu.sc * 1.2 > 600 ? 600 : stu.sc * 1.2;
    stu.age += 1;
    return stu;
}
int main(){
    int n;
    cin >> n;
    vector<Stu> stus;
    for(int i = 0; i < n; i++){
        Stu stu;
        cin >> stu.name >> stu.age >> stu.sc;
        stus.push_back(stu);
    }

    for(Stu s : stus){
        Stu s1 = calc(s);
        cout << s1.name << ' ' << s1.age << ' ' << s1.sc << endl;
    }
    return 0;
}