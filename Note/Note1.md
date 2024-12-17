# ACM Note No.1: Misc

### Template


```c++
#include <bits/stdc++.h>
using namespace std;
void slove(){
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}
```

### Sort

```c++
vector<int> arr;
sort(arr.begin(), arr.end(), [](int a, int b) -> int{
    return a > b;
});
```

```c++
void selection_sort(int* a, int n) {
  for (int i = 1; i < n; ++i) {
    int ith = i;
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] < a[ith]) {
        ith = j;
      }
    }
    std::swap(a[i], a[ith]);
  }
}
```

### Permutation

`next_permutation(dict.begin(), dict.end())`可以生成全排列

### Mod

`(a+b)%p=(a%p+b%p)%p`

### long long

`using ll = long long;`

### String 

`str.erase(int index)`是删除index之后的所有字符，不是str[index]的字符
`str.erase(int index, int length)`是删除index之后长度为length的字符

### Get Line

`getline(cin, line);`

### XOR

一个数异或它本身得到0。可以利用这个特性排除重复出现的数据

### Char To int

c++中，若char c(为数字)，那么`int n = c - '0'`代表着`c`对应的ASCILL码减去`'0'`对应的ASCILL码`48`, 以此完成char转int。同理，`int n(n < 10), char c = n + '0'`能完成int转char

### GCD

```c++
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
```

### 埃氏筛

```cpp
const int N = 20000;

bool p[N];
void ai(){
    for(int i = 0; i < N; i++){
        p[i] = true;
    }
    p[0] = p[1] = false;
    for(int i = 2; i * i < N; i++){
        if(p[i]){
            for(int j = i * i; j < N; j += i){
                p[j] = false;
            }
        }
    }
}
```

### 快速幂

```c++
int binpow(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int res = binpow(a, b / 2);
        return res * res;
    }else{
        int res = binpow(a, b - 1);
        return a * res;
    }
}
```

### String

```c++
s.size();
s.substr(int pos, int len);
s.find(char ch) == string::npos;
find(string str, int pos);
s.insert(int pos, string str);
s.replace(int pos, int count, string str);
```

### 时间复杂度

时间复杂度与建议不超过的`n`的范围

- `O(logn)`: long long 内都行
- `O(n)`: 1e7
- `O(nlogn)`: 1e5 ~ 5e5
- `O(n^2)`: 1e3 ~ 5e3
- `O(n^3)`: 200 ~ 500
- `O(2^n)`: 20~24
- `O(n!)`: 12

### getline()

```C++
#include<bits/stdc++.h>
using namespace std;
void slove(){
	string s;
	getline(cin, s);	
	for(int i = s.length() - 1; i >= 0; i--){
		cout << s[i];
	}
	cout << '\n';
}
int main(){
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	getchar();
	while(n--){
		slove();
	}
	return 0;
}
```