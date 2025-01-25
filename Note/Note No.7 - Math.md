# ACM Note No.7: 数论

## 1. 进制

根据十进制的运算性质很容易能写出将十进制转换为数组倒序存储的方法

```cpp
const int N = 1e4;
int s[N + 10];
int toDex(int num){
    int digit = 0;
    while (num > 0) {
        s[digit++] = num % 10;
        num /= 10;
    }
    return digit;
}
```

类比十进制的转换，我们就可以写出十进制转换为二进制的算法，当然也适用于其他进制

```cpp
const int N = 1e4;
int s[N + 10];
int toBin(int num){
    int digit = 0;
    while (num > 0) {
        s[digit++] = num % 2;
        num /= 2;
    }
    return digit;
}
```

而将二进制转换为十进制则同样简单，同样也可以类比写出其他进制的转换

```cpp
const int N = 1e4;
int s[N + 10];
int toNum(int digit){
    int res = 0;
    for(int i = digit; i >= 0; i--){
        res = res * 2 + s[i];
    }
    return res;
}
```

当然也可以在这些算法的基础上不进行转换直接在算法内进行逐位分析

## 2. 位运算

与位运算有关的题目大多是将十进制数字转换成二进制数字进行构造、贪心、模拟等等操作，位运算较为重要的知识点如下

### 异或

异或有两条重要性质

1. `a ^ a = 0`即一个数异或它本身得到`0`

2. `a ^ b == b ^ a`即在一串异或运算中，改变异或的顺序结果不变

根据这以上两条性质，可以进行**数据的去重**

例：找出给出的长度为`n`的数列中个数为奇数的数字

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int ans;
	cin >> ans;
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		sum ^= x;
	}
	cout << ans;
	return 0;
}
```

利用异或的性质，可以在`O(n)`复杂度内找出答案

### 移位

移位运算可以用来快速代替`2`的幂次方运算：

1. `x << n = x * (2 ^ n) ` 带入 `x == 1`得`1 << n = 2 ^ n`

2. `x >> n = x / (2 ^ n) `

根据移位的运算性质，可以写出计算数字`x`从低到高第`i`位的算法：

```cpp
int bit = (x >> i) & 1;
```

## 3. 模运算

1. **加减法**：`(a + b) % m = [(a % m) + (b % m)] % m` 减法同理
2. **乘法**：`(a × b) % m = [(a % m) × (b % m)] % m`
3. **幂**：`(a^n) % m = [(a % m)^n] % m`

如果题目数据太大需要模以一个题目给定的数（一般是质数），则需要在计算过程中取模

## 4. 同余

**同余**：数论中的一种等价关系，如果存在整数`A`、`B`，除以`P`的余数相同，则称**A，B mod P 同余**，记作`A☰B （mod P）`

**逆元**：若`a*x ☰ 1 mod b` 且`a`，`b`互质，则称`x`为`a`的逆元，标记为`a ^ -1`，逆元也可认为是数论意义上的倒数。

**费马小定理(Fermat’s little theorem)**：如果p是一个质数，而整数a不是p的倍数，则 **a^( P - 1) ☰ 1 mod P**，所以**a ^ (p - 2) 即为 a 的逆元**。前提是a和p互质，不过在算法竞赛中题目所给的模数99.9%都是质数，只要无脑记公式就好

求逆元的三种方法(Luogu P3811)

### 费马小定理

```cpp
// solve2: binpow
ll binpow(ll a, ll b, ll mod){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll res = binpow(a, b / 2, mod) % mod;
        return res * res;
    }else{
        ll res = binpow(a, b - 1, mod) % mod;
        return (a % mod) * res;
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, p;
    cin >> n >> p;
    for(ll i = 1; i <= n; i++){
        cout << binpow(i, p - 2, p) % p << '\n';
    }
    return 0;
}
```

### 扩展欧几里得算法

```cpp
// solve1: exgcd
/**
 * solve ax + by = gcd(a, b)
 */
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int main(){
    ll n, p;
    cin >> n >> p;
    for(ll i = 1; i <= n; i++){
        ll x, k;
        exgcd(i, p, x, k);
        x = (x % p + p) % p;
        cout << x << '\n';
    }

}
/**
 * ax = 1 (mod p)
 * 
 * ax + kp = gcd(a, b) = 1
 */
```

### 递推法

```cpp
int main(){
    int n, p;
    cin >> n >> p;
    array<int, N> inv;
    inv[1] = 1;
    cout << 1 << '\n';
    for (int i = 2; i <= n; ++i) {
        inv[i] = (ll)(p - p / i) * inv[p % i] % p;
        cout << inv[i] << '\n';
    }
    return 0;
}
```

