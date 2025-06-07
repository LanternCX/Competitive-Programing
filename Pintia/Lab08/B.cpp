#include<iostream>
#include<string.h>
#define N 100;
using namespace std;
typedef struct BiNode{
    char data;
    struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T,char a[],int &i){    
    char ch;
    ch=a[i++];
    if(ch=='#')  T=NULL;
    else{                            
        T=new BiTNode;
        T->data=ch;                    
        CreateBiTree(T->lchild,a,i);    
        CreateBiTree(T->rchild,a,i);    
    }                        
}    

bool Isomorphism(BiTree T1,BiTree T2);

int main(){
    BiTree T1,T2;
    int i=0,j=0;
    char a[100];
    char b[100];
    cin>>a>>b;
    CreateBiTree(T1,a,i);
    CreateBiTree(T2,b,j);    
    cout<<Isomorphism(T1,T2);    
    return 0;
}

bool Isomorphism(BiTree T1, BiTree T2) {
    if (T1 == nullptr && T2 == nullptr) {
        return 1;
    }
    if ((T1 == nullptr) ^ (T2 == nullptr)) {
        return 0;
    }

    bool res1 = Isomorphism(T1->lchild, T2->lchild) && Isomorphism(T1->rchild, T2->rchild);
    bool res2 = Isomorphism(T1->rchild, T2->lchild) && Isomorphism(T1->lchild, T2->rchild);
    return res1 || res2;
}
/**
 * t1 左子树 要么和 t2 右子树同构 要么和 t2 左子树同构 
 * t1 右子树同理
 * 
 * 实际上只需要递归判断
 * 
 * 那么递归终点如何设计？
 * 
 * 如果两个节点都是叶子节点那么一定同构
 * 也就是说 t1 t2 都是空
 * 就可以 return
 */
