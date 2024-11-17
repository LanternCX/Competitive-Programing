# ACM Note No.3: STL

## Introduce

STL有六大组件

1. 容器（Containers）
2. 算法（Algorithms）
3. 迭代器（Iterators）
4. 仿函数（Functros）
5. 适配器（Adapters）
6. 配置器（Allocators)

在算法竞赛中，主要使用的是**STL容器**与**STL算法**，并使用**STL迭代器**连接两者

虽然网上资料很多但是我还是比较喜欢“Show Me The Code”类型的文档于是就自己写了一份

## STL数据结构

### 容器

![img](https://oi-wiki.org/lang/csl/images/container1.png)

### 容器适配器

- **栈**(`stack`) 后进先出 (LIFO) 的容器，默认是对双端队列（`deque`）的包装。
- **队列**(`queue`) 先进先出 (FIFO) 的容器，默认是对双端队列（`deque`）的包装。
- **优先队列**(`priority_queue`) 元素的次序是由作用于所存储的值对上的某种谓词决定的的一种队列，默认是对向量（`vector`）的包装。

### vector

可变长度数组

#### 声明与初始化

```c++
// 空的vector
vector<int> vec;
// 长度为1的vector
vector<int> vec(1);
// 长度为1，元素值全为10
vector<int> vec(5, 10);
```

#### 元素操作

```c++
vector<int> vec;

// 在末尾插入元素
vec.push_back(1);
// 删除末尾元素
vec.pop_back();
// 清除所有元素
vec.clear();
// 在idx = 1插入
vec.insert(vec.begin() + 1, 1);
// 删除idx = 1的元素
vec.erase(vec.begin() + 1);
// idx = 1的元素值，带边界检查
int a1 = vec.at(1);
// idx = 1的元素值，不带边界检查
int a2 = vec[1];
// 第一个元素值
int b = vec.front();
// 最后一个元素的值
int c = vec.back();
```

#### 容器操作

```c++
vector<int> vec;

// 是否为空
vec.empty();
// 元素数量
vec.size();
// 指向首元素的迭代器
auto a = vec.begin();
int x = *a;
// 指向末尾元素的下一个元素的迭代器
auto a = vec.begin();
// 交换两个容器
vector<int> vec1;
vec.swap(vec1);
// for each式遍历
for(auto i : vec){
    cout << i;
}
```

### deque

双端队列，支持在首位线性复杂度的插入与删除

除元素操作外与vector相同

#### 元素操作

相比vector多出了`push_front()`和`pop_front()`，其余与vector一致

```c++
deque<int> myDeque;

// 在首部插入元素
myDeque.push_front(5);
// 在首部删除元素
myDeque.pop_front();
```

### list

双向链表，能够提供**线性复杂度的随机访问**，以及**常数复杂度的插入和删除**

随机访问需要使用迭代器，因此随机访问为线性复杂度

```c++
list<int> li;

// 第一个元素
int front = li.front();
// 最后一个元素
int back = li.back(); 
// idx = 1 的元素
int at(list<int>& myList, int index) {
    auto it = myList.begin();
    advance(it, index); // 移动迭代器到指定位置
    return *it;
}
int n = at(li, 1);
```

#### set & multiset & unordered_set

集合，按照一定的顺序排列，默认按照升序排列，即从小到大（例如对于字符串默认按照字典序升序排列）

其中`multiset`可以当作优先队列`priority_queue`使用

可以利用集合自动排序的特性解决一些题目

**set**: 元素不重复

**multiset**: 元素可重复

**unordered_set**： 元素无序

#### 初始化

```c++
// 自定义比较函数与使用初始值列表初始化
struct Cmp {
    bool operator()(int a, int b) const {
        return a > b; // 逆序
    }
};
set<int, Cmp> mySet = {5, 2, 3, 1, 4};
// 从另一个容器初始化，可以用于vector去重
vector<int> vec = {1, 2, 3, 4, 5};
set<int> mySet(vec.begin(), vec.end());

// 按照int降序排列（从大到小）
set<int, greater<int>>
```

#### 元素操作

```cpp
set<int> mySet; 

// 插入元素
mySet.insert(1);
// 删除值为 x 的所有元素，返回删除元素的个数。
int n = mySet.erase(1);
// 删除idx = 0的元素
mySet.erase(mySet.begin());
// 删除从元素3的下标到元素7的下标的所有元素
mySet.erase(mySet.find(3), mySet.find(7));
```

#### 容器操作

```c++
set<int> mySet;

// 返回set内键为 x 的元素数量
mySet.count(3);
// 查找
auto it = mySet.find(x);
if(it != mySet.end()){
    int x = *it;
}
// 查找指向首个 <= 3 的元素的迭代器
auto lower = mySet.lower_bound(3);
if(it != mySet.end()){
    int x = *lower;
}
// 返回指向首个 > 3 的元素的迭代器
auto upper = mySet.upper_bound(3);
if(it != mySet.end()){
    int x = *upper;
}
// 是否为空
mySet.empty();
// 集合大小
mySet.size();
```

**注意**：`set` 自带的 `lower_bound` 和 `upper_bound` 的时间复杂度为 ![O(\log n)](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)。但使用 `algorithm` 库中的 `lower_bound` 和 `upper_bound` 函数对 `set` 中的元素进行查询，时间复杂度为 ![O(n)](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)。

### map & unordered_map

字典，搜索、移除和插入操作拥有对数复杂度

**map**：元素按照键的顺序排列

**unordered_map**： 元素无序

#### 初始化

```c++
// 自定义比较函数与使用初始值列表初始化
struct Cmp {
    bool operator()(int a, int b) const {
        return a > b; // 逆序
    }
};
map<int, string, Cmp> myMap = {{5, "5"}, {2, "2"}};
// 从另一个容器初始化
vector<pair<int, string>> vec = {{1, "one"}, {2, "two"}};
map<int, string> myMap(vec.begin(), vec.end());
// 按照int降序排列（从大到小）
map<int, string, greater<int>> myMap = {{5, "five"}, {3, "three"}};
```

**注意**：`map`是**依靠键排序**的，因此即使是使用自定义比较函数也**无法使`map`依靠值排序**

#### 元素操作

相比`set`，`map`可以使用运算符`[]`访问与插入键对应的值

```cpp
map<int, string> myMap;
// 插入键为 1 的值 "one"
myMap[1] = "one";
// 访问键 1 的值
string one = myMap[1];
// 访问不存在的键, 初始化为默认值 empty = ""
string empty = myMap[2];
```

### stack

栈，后进先出（Last In, First Out）

**注意**：栈**不支持迭代器**，访问元素只能通过`top()`

#### 初始化

```c++
stack<int> st;
// 使用 vector 初始化
vector<int> vec = {1, 2, 3};
stack<int, vector<int>> st(vec);
stack<int, vector<int>> st({10, 20, 30});
// 使用 deque / list / stack 等容器初始化同理
deque<int> deq = {4, 5, 6};
stack<int, deque<int>> st(deq);
```

### 操作

```c++
stack<int> st;

// 插入元素
st.push(10);
// 访问栈顶元素
int top = st.top();
// 删除栈顶元素
st.pop();
// 查询元素数量
int size = st.size();
// 检查是否为空
bool isEmpty = st.empty();
```

### queue

队列，先进先出（First In, First Out）
接口与栈相同，唯一的区别在于访问队首元素使用`front()`

```c++
queue<int> que;

// 访问队首元素
int top = que.front();
```

### priority_queue

优先队列，默认是最大堆，按照从大到小的顺序排列

**注意**：尽管优先队列默认使用`less<T>`排序但是与`set`的默认按照降序不同

### 初始化

```c++
priority_queue<int> pq
// 自定义比较函数
auto cmp = [](int a, int b) { return abs(a) > abs(b); };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
// 自定义比较函数（法二）
struct Cmp {
    bool operator()(int a, int b) const {
        return abs(a) > abs(b); // 按绝对值升序排序
    }
};
priority_queue<int, vector<int>, Cmp> pq
// 同样也可以像其他容器一样用其他已有容器进行初始化
```

### 操作

```c++
priority_queue<int> pq;

// 插入元素
pq.push(10);
// 访问堆顶元素
int top = pq.top();
// 检查是否为空
bool isEmpty = pq.empty();
// 查询元素数量
int size = pq.size();
// 删除堆顶元素
pq.pop();
```

## STL迭代器

所有STL容器都有`begin()`与`end()`方法，这两个方法返回不同的迭代器：

`begin()`：返回指向开头元素的迭代器。

`end()`：返回指**向末尾的下一个元素**的迭代器。`end()` 不指向某个元素，但它是末尾元素的后继。

大部分STL容器还有`rbegin()`和`rend()`

`rend()`：返回指向逆向数组末元素后一位置的迭代器，对应容器首的前一个位置，没有元素。

`rbegin()`：返回指向逆向数组的首元素的逆向迭代器，可以理解为正向容器的末元素。

迭代器主要支持两个运算符`++`和`*`

```cpp
vector<int> data(10);

for (auto iter = data.begin(); iter != data.end(); iter++){
    cout << *iter << endl;  // 使用迭代器访问元素
}
```

## STL算法

### find() & binary_search()

```c++
vector<int> vec = {1, 2, 3 ,4};

// find()顺序查找
auto it = find(vec.begin(), vec.end(), 1);
if(it != vec.end()){
    int n = *it;
	int idx = it - vec.begin();
}

// binary_search() 二分搜索，仅用于判断元素是否存在
sort(vec.begin(), vec.end());  // 先排序
bool found = binary_search(vec.begin(), vec.end(), 4);
// binary_search() 自定义比较函数
struct Person {
    int age;
    string name;
};
bool cmp(const Person& a, const Person& b) {
    return a.age < b.age;
}
Person target = {30, "Bob"};
binary_search(people.begin(), people.end(), target, cmp);
```

### sort() & partial_sort() & stable_sort()

```c++
// sort() 排序、stable_sort() 稳定排序，用法相同
vector<int> vec = {5, 2, 9, 1, 5, 6};
sort(vec.begin(), vec.end());
// 使用匿名函数进行自定义比较
sort(vec.begin(), vec.end(), [](int a, int b) -> int {
    return a > b;
});
// 使用预设的greater<>比较器进行自定义比较
sort(vec.begin(), vec.end(), greater<int>());
// partial_sort()对区间排序，用法与sort类似
partial_sort(vec.begin(), vec.begin() + 3, vec.end());
partial_sort(vec.begin(), vec.begin() + 3, vec.end(), greater<int>());
```

### next_permutation() & prev_permutation()

`next_permutation` 生成字典序的下一个排列，如果没有下一个排列则返回 false

`prev_permutation`则生成字典序的上一个排列

`next_permutation()`是按照字典序进行全排列的生成的，因此需要先对容器进行排序

```c++
vector<int> vec = {1, 2, 3 ,4};
sort(numbers.begin(), numbers.end());
do{
    for (int i : vec){
        cout << i << " ";
    }
    cout << '\n';
}while(next_permutation(vec.begin(), vec.end()));

// 自定义排序比较方法
bool cmp(const Person& a, const Person& b) {
    return a.name < b.name;
}
next_permutation(people.begin(), people.end(), cmp)
```

### lower_bound() & upper_bound()

在容器内进行二分查找，**需要先对元素进行排序**

`lower_bound()`返回指向第一个**大于等于**`x`的元素的位置的迭代器，如果不存在这样的元素，则返回尾迭代器

`upper_bound()`返回指向第一个**大于**`x`的元素的位置的迭代器，如果不存在这样的元素，则返回尾迭代器

```c++
vector<int> vec = {1,1,4,5,1,5};
// 自定义比较函数
auto comp = [](int a, int b) { return a > b; };
auto it = upper_bound(vec.begin(), vec.end(), 4, comp);
if (it != vec.end()) {
    int idx = it - vec.begin();
}
```

### accmulate()

`accumulate()` 是一个用于求和、求积、以及累积各种其他操作的函数，常用于处理序列上的聚合操作

```c++
// 0 为初值，对区间内的元素进行op操作，默认为加法
vector<int> vec = {1,2,3,4,5};
int sum = accumulate(vec.begin(), vec.end(), 0);
// 使用 accumulate 计算乘积，初始值为 1
int mul = accumulate(vec.begin(), vec.end(), 1, multiplies<int>());
// 使用 accumulate 拼接字符串，初始值为空字符串
vector<string> words = {"Hello", "World", "!"};
string result = accumulate(words.begin(), words.end(), string(""));
// 使用 accumulate 计算累积的差值
int difference = accumulate(vec.begin(), vec.end(), 0, [](int a, int b) {
	return a - b;
});
```

### nth_element()

`nth_element()` 是一种用于部分排序的算法，适合在需要找到第 n 小/大的元素或部分排序时使用

```c++
vector<int> nums = {4, 1, 7, 3, 9, 2, 5};
// 找到第 3 小的元素（即第 4 小，因为索引从 0 开始）
nth_element(nums.begin(), nums.begin() + 3, nums.end());
cout << "第 3 小的元素是：" << nums[3];
// 使用自定义比较函数进行降序排序
nth_element(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
cout << "第 2 大的元素是：" << nums[k];
// 应用：查找中位数
nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
cout << "中位数是：" << nums[nums.size() / 2] << '\n';
```

