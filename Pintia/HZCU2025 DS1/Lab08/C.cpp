#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

BinTree Insert( BinTree BST, ElementType X ) {
    // 如果是空说明插入的子树不存在，此时就需要新建一个叶子节点完成插入操作
    if (BST == NULL) {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
        return BST;
    }

    if (X < BST->Data) {
        BST->Left = Insert(BST->Left, X);
        return BST;
    }
    
    if (X > BST->Data) {
        BST->Right = Insert(BST->Right, X);
        return BST;
    }

    return BST;
}

Position Find( BinTree BST, ElementType X ) {
    if (BST == NULL) {
        return NULL;
    }
    
    if (BST->Data == X) {
        return BST;
    }

    if (BST->Data < X) {
        return Find(BST->Right, X);
    } 
    
    if (BST->Data > X) {
        return Find(BST->Left, X);
    }

    return NULL;
}

Position FindMin( BinTree BST ) {
    if (BST == NULL) {
        return NULL;
    }
    if (BST->Left == NULL) {
        return BST;
    }
    return FindMin(BST->Left);
}

Position FindMax( BinTree BST ) {
    if (BST == NULL) {
        return NULL;
    }
    if (BST->Right == NULL) {
        return BST;
    }
    return FindMax(BST->Right);
}

BinTree Delete( BinTree BST, ElementType X ) {
    if (BST == NULL) {
        printf("Not Found\n");
        return BST;
    }
    if (X < BST->Data) {
        BST->Left = Delete(BST->Left, X);
        return BST;
    }
    if (X > BST->Data) {
        BST->Right = Delete(BST->Right, X);
        return BST;
    }
    if (X == BST->Data) {
        if (BST->Left && BST->Right) {
            Position alt = FindMin(BST->Right);
            BST->Data = alt->Data;
            BST->Right = Delete(BST->Right, alt->Data);
        } else {
            Position temp = BST;
            if (BST->Left) {
                BST = BST->Left;
            } else {
                BST = BST->Right;
            }
            free(temp);
        }
        return BST;
    }
    return BST;
}



