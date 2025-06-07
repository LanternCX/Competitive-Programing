## 二、数据结构定义与分析

本次实验中主要定义了以下数据结构：

- `struct TreeNode` 表达式树的节点结构体，包含以下成员：
  - `string val`：当前节点的值，可以是操作数（如 `"3.14"`）或操作符（如 `"+"`、`"*"`）。
  - `TreeNode* left` 和 `TreeNode* right`：指向左右子树的指针。

此外，程序中还使用了以下 STL 容器与变量：

- `vector<string> preorder`：前序遍历序列，表示表达式树的构建顺序。
- `vector<string> inorder`：中序遍历序列，表示表达式的结构。
- `string input`：用于暂存每一行输入。
- `string token`：用于从一行输入中提取独立的表达式单元（如数值或运算符）。

## 三、算法分析

本题要求通过给定的前序遍历和中序遍历恢复一棵表达式树，并对该表达式进行求值。我们可以简单地将问题分为两个部分：通过前序遍历与中序遍历构建表达式树和对表达式树进行求值。

对于构建表达式树部分，首先需要对输入的字符串进行解析并生成前序与后序遍历序列。根据前序遍历与后序遍历的定义，前序首元素为当前根节点的原则，定位中序序列中节点的对应位置，从而划分左右子树，因此可以递归构建整棵树。

对于表达式求值部分，观察数据结构可以发现，可以使用后序遍历的方式计算表达式树的值。通过观察，我们发现构建出的表达式树的叶子节点都是需要计算的值，而对于每一个非叶子节点，当前节点的值就是节点的左儿子的值通过该节点的操作 `op` 与右儿子的值运算的结果。由此发现对于每一个非叶子节点只需要递归地计算其左子树的值和右子树的值就，遇到叶子节点就返回。而这个过程与后序遍历的过程一致，因此可以用后序遍历解决这个问题。

## 四、 算法的时间复杂度分析

- 构建表达式树：
  - 每个节点最多遍历一次，时间复杂度为 $O(n)$；
  - 每次在中序序列中查找元素位置，最坏为 $O(n)$
  - 整体时间复杂度为 $O(n^2)$
- 递归求值：
  - 每个节点遍历一次，时间复杂度为 $O(n)$。

因此，总时间复杂度为 $O(n^2)$，其中 $n$ 为表达式节点总数。

## 五、测试用例的选择原因以及测试结果

### 1. 样例测试

**输入：**

```in
*1 + 1.89 2.78 *2 4.67 - 5.345
1.89 + 2.78 *1 4.67 *2 - 5.345
```

**预期输出：**

```
-116.569
```

**实际输出：**



### 2. 1 + 1

**输入：**

```in
+ 1 1
1 + 1
```

**预期输出：**

```
2.000
```

**实际输出：**



### 3. 单个数字节点

**输入：**

```in
114514
```

**预期输出：**

```
114514.000
```

**实际输出：**



### 4. 复杂表达式

**输入：**

```in
- + 7.5 -3.0 * 2.0 4.0
7.5 + -3.0 - 2.0 * 4.0
```

**预期输出：**

```
-3.500
```

**实际输出：**



## 六、存在问题及可能原因

1. **表达式运算顺序不正确**
   - **问题**：表达式运算顺序不正确
   - **原因**：可能是没有正确构造表达式树
2. **运算结果不正确**
   - **问题**：表达式运算结果不正确
   - **原因**：可能存在精度问题

## 七、附源代码以及代码相应注释

```c++
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
/**
 * @brief 表达式树根节点
 */
struct TreeNode {
    // 节点存储的值
    string val;
    // 左子树         
    TreeNode* left;
    // 右子树
    TreeNode* right;
    // 构造函数
    TreeNode(string v) : val(v), left(nullptr), right(nullptr) {}
};

/**
 * @brief 根据前序和中序遍历构造表达式树
 */
TreeNode* buildTree(vector<string> preorder, int preL, int preR, vector<string> inorder, int inL, int inR) {
    // 空区间返回空树
    if (preL > preR || inL > inR) {
        return nullptr;
    }

    // 前序第一个为根节点
    string rootVal = preorder[preL];
    // 创建根节点    
    TreeNode* root = new TreeNode(rootVal);

    // 查找中序遍历中根节点的位置
    int pos;
    for (pos = inL; pos <= inR; pos++){
        if (inorder[pos] == rootVal) {
            break;
        }
    }

    // 左子树的大小
    int leftSize = pos - inL;

    // 递归构建左右子树
    root->left = buildTree(preorder, preL + 1, preL + leftSize, inorder, inL, pos - 1);
    root->right = buildTree(preorder, preL + leftSize + 1, preR, inorder, pos + 1, inR);

    return root;
}

/**
 * @brief 后序遍历计算表达式树的值
 * @param 树的根节点
 */
double calc(TreeNode* root) {
    // 空树特判
    if (!root) {
        return 0;
    }

    // 如果当前节点是叶子节点那么直接返回节点的值不做计算
    if (!root->left && !root->right) {
        return stof(root->val);
    }

    // 左子树表达式值
    double left = calc(root->left);
    // 右子树表达式值      
    double right = calc(root->right);

    // 操作符取第一个字符
    char op = root->val[0];

    // 执行计算
    if (op == '+') return left + right;
    if (op == '-') return left - right;
    if (op == '*') return left * right;
    if (op == '/') return left / right;

    return 0;
}

int main() {
    cout << fixed << setprecision(3);
    // 输入的字符串，按行输入
    string input;
    // 前序遍历，中序遍历
    vector<string> preorder, inorder;
    // 从每一行输入中提取的单个 token
    string token;

    // 解析前序遍历
    getline(cin, input);
    for (char ch : input) {
        if (ch == ' ' || ch == '\n') {
            preorder.push_back(token);
            token.clear(); continue;
        }
        token.push_back(ch);
    }
    preorder.push_back(token);
    token.clear();

    // 解析中序遍历
    getline(cin, input);
    for (char ch : input) {
        if (ch == ' ' || ch == '\n') {
            inorder.push_back(token);
            token.clear(); continue;
        }
        token.push_back(ch);
    }
    inorder.push_back(token);
    token.clear();

    // 构造表达式树
    TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    // 对表达式树进行求值
    double ans = calc(root);

    // 打印答案
    cout << ans << '\n';
    return 0;
}
```



## 八、实验创新点或合理化建议

这个题目重点需要实现的是二叉树的构建与表达式的计算，需要对二叉树的三种遍历方式的定义以及用遍历序列构建二叉树的过程有较为深刻的理解。应当在接下来的练习中加强对二叉树的基本操作的学习，巩固知识。

 