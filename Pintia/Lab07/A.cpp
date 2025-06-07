#include<iostream>
#include <string>
#include <stack>
#include <queue> 
using namespace std;
typedef struct node *BTree;
typedef struct node{
    char data;
    BTree lchild;
    BTree rchild;
}TNode;
void CreateBTree(BTree &bt,string str);//创建二叉树 
void  DispBTree(BTree bt);//括号法输出二叉树
void PreOrder( BTree bt );//先序遍历二叉树
void InOrder(BTree bt);//中序遍历二叉树
void PostOrder(BTree bt);//后序遍历二叉树 
void LevelOrder(BTree bt);//层次遍历二叉树 
int flag=0;
int main()
{
    string str;
    BTree bt,p;
    str="A(B(D,F(E)),C(G(,H),I))";
    CreateBTree(bt,str);
    cout<<"btree:";
    DispBTree(bt);
    cout<<endl<<"preorder:";
    PreOrder(bt);
    flag=0;
    cout<<endl<<"inorder:";
    InOrder(bt);
    flag=0;
    cout<<endl<<"postorder:";
    PostOrder(bt);
    flag=0;
    cout<<endl<<"levelorder:";
     LevelOrder(bt);  
 } 
// 创建二叉树 
void CreateBTree(BTree &bt, string str) {
    stack<BTree> st;
    BTree now = nullptr;
    // 1 left, 2 right
    int kid = 0;
    bt = nullptr;
    for (auto ch : str) {
        if (ch == '(') {
            // 左括号 接下来就构建当前节点的左子树
            kid = 1;
            st.push(now);
            continue;
        } else if (ch == ',') {
            // 逗号 接下来就构建当前节点的右子树
            kid = 2;   
            continue;
        } else if (ch == ')') {
            // 右括号 说明当前节点的子树构建完毕
            now = st.top();
            st.pop();
            continue;
        } else {
            // 普通字符 新建一个节点
            now = new TNode;
            now->data = ch;
            now->lchild = nullptr;
            now->rchild = nullptr;
            if (!bt) {
                bt = now;
            } else if (kid == 1 && !st.empty()) {
                st.top()->lchild = now;
            } else if (kid == 2 && !st.empty()) {
                st.top()->rchild = now;
            }
        }
    }
}

// 括号法输出二叉树
void DispBTree(BTree bt) {
    if (!bt) {
        return;
    }
    cout << bt->data;
    if (bt->lchild || bt->rchild) {
        cout << '(';
    }
    if (bt->lchild) {
        DispBTree(bt->lchild);
    }
    if (bt->rchild) {
        cout << ',';
        DispBTree(bt->rchild);
    }
    if (bt->lchild || bt->rchild) {
        cout << ')';
    }
}

// 先序遍历二叉树 根 左 右
void PreOrder(BTree bt) {
    if (!bt) {
        return;
    }
    if (flag) {
        cout << ' ';
    }
    cout << bt->data;
    flag = 1;
    if (bt->lchild) {
        PreOrder(bt->lchild);
    }
    if (bt->rchild) {
        PreOrder(bt->rchild);
    }
}

// 中序遍历二叉树 左 根 右
void InOrder(BTree bt) {
    if (!bt) {
        return;
    }
    
    if (bt->lchild) {
        InOrder(bt->lchild);
    }

    if (flag) {
        cout << ' ';
    }
    flag = 1;
    cout << bt->data;
    
    if (bt->rchild) {
        InOrder(bt->rchild);
    }
}

// 后序遍历二叉树 左 右 根
void PostOrder(BTree bt) {
    if (!bt) {
        return;
    }
    
    if (bt->lchild) {
        PostOrder(bt->lchild);
    }

    if (bt->rchild) {
        PostOrder(bt->rchild);
    }

    if (flag) {
        cout << ' ';
    }
    flag = 1;
    cout << bt->data;
    
}

// 层次遍历二叉树 
void LevelOrder(BTree bt) {
    if (!bt) {
        return;
    }
    queue<BTree> q;
    q.push(bt);
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if (now->lchild) {
            q.push(now->lchild);
        }
        if (now->rchild) {
            q.push(now->rchild);
        }
        cout << now->data;
        if (!q.empty()) {
            cout << ' ';
        }
    }
}