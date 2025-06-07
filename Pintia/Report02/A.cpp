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
