#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
map<char, int> tab = {
    {'*', 1},
{'.', 2},
{'F', 3},
{'C', 4},
};

/**
 * enum 0 , 1 , -1
 */
struct Point{
    int y;
    int x;
    int face;
    int euqals(Point p){
        if(p.x == x && p.y == y){
            return true;
        }
        return false;
    }
};
struct Pair{
    Point p1;
    Point p2;
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int map[10][10];
    
    Point cow;
    Point far;
    for(int i = 0 ; i < 10; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 10; j++){
            map[i][j] = tab[s[j]];
            if(s[j] == 'C'){
                cow = {i , j, {}};
            }
            if(s[i] == 'F'){
                far = {i , j};
            }
        }
    }

    vector<Pair> li;
    while (true) {
        if(cow.euqals(far)){
            break;
        }
        Point cow1;
        cow1.face = cow.face;
        switch (cow.face) {
            case 1: 
                cow1.y = cow.y - 1;
                cow1.x = cow.x;
                break;
            case 2:
                cow1.y = cow.y;
                cow1.x = cow.x + 1;
                break;
            case -1:
                cow1.y = cow.y + 1;
                cow1.x = cow.x;
                break;
            case -2:
                cow1.y = cow.y;
                cow1.x = cow.x - 1;
                break;
        }
        if (map[cow1.y][cow1.x] == 1) {
        }

    }
    return 0;
}
/**
 * * : 1
 * . : 2
 * F : 3
 * C : 4
 * 
 * face:
 *  1 N 
 *  -1 S
 *  2 E
 *  -2 w
 */