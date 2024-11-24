# ACM Note No.4: 二分

二分具体分为二分查找与二分答案

若题目的答案具有单调性，则可以使用二分答案，思路类似于暴力搜索不过复杂度是`O(logN)`

当然`C++ STL`有自带的`lower_bound()`和`upper_bound()`在**有序队列**内进行二分查找，在此不过多赘述

使用二分查找之前**一定一定**要对序列进行**排序**

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    sort(arr.begin(), arr.end());
    int num = 3;
    int l, r, mid, idx;
    
     // 找到合法的 r 之后继续向前查找，返回最小的合法idx
    l = 0, r = arr.size() - 1;
    while(l < r){
        mid = (l + r + 1) / 2;
        
        if(arr[mid] >= num){
            r = mid - 1;
        }else {
            l = mid;
        }
    }
     // r - 1 之后使得 while 退出，因此此处的 r 需要 +1
    idx = r + 1;
    cout << idx << '\n';

    // 找到合法的 l 之后继续向后查找，返回最大的合法idx
    l = 0, r = arr.size() - 1;
    while(l < r){
        mid = (l + r) / 2;
        
        if(arr[mid] <= num){
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    // l + 1 之后使得 while 退出，因此此处的 l 需要 -1
    idx = l - 1;
    cout << idx << '\n';


    // 只保证找到不保证找到的位置
    l = 0, r = arr.size() - 1;
    while(l < r){
        mid = (l + r) / 2;
        if(arr[mid] < num){
            l = mid + 1;
        }else if(arr[mid] > num){
            r = mid - 1;
        }else{
            break;
        }
    }
    idx = mid;
    cout << idx << '\n';

    return 0;
}
```

另一种写法如下，但是我不是很能理解所以就当成备用

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    sort(arr.begin(), arr.end());
    int num = 3;
    int l, r, mid, idx;

    // 找到最小的合法 idx
    l = 0, r = arr.size() - 1;
    while(l < r){
        mid = (l + r) / 2;
        if(arr[mid] >= num){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    idx = l; // 或 r
    cout << idx << '\n';

    // 找到最大的合法 idx
    l = 0, r = arr.size() - 1;
    while(l < r){
        mid = (l + r + 1) / 2; // 向上取整
        if(arr[mid] <= num){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    idx = l; // 或 r
    cout << idx << '\n';

    // 找到任意一个等于 num 的索引
    l = 0, r = arr.size() - 1;
    bool found = false;
    while(l <= r){
        mid = (l + r) / 2;
        if(arr[mid] < num){
            l = mid + 1;
        }else if(arr[mid] > num){
            r = mid - 1;
        }else{
            found = true;
            break;
        }
    }
    idx = found ? mid : -1;
    cout << idx << '\n';

    return 0;
}

```

