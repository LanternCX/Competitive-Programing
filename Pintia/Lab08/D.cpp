#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* details omitted */
BinTree KthLargest ( BinTree T, int K );

int main()
{
    BinTree T, P;
    int K;

    T = BuildTree();
    scanf("%d", &K);
    P = KthLargest(T, K);
    printf("%d\n", P->Key);
    if (P->Left) printf("%d\n", P->Left->Key);
    else printf("NULL\n");
    if (P->Right) printf("%d\n", P->Right->Key);
    else printf("NULL\n");

    return 0;
}

BinTree res = NULL;
int cnt = 0;
void find (BinTree T, int K) {
    if (res || !T) {
        return;
    }
    find (T->Right, K);
    cnt++;
    if (cnt == K) {
        res = T;
        return;
    }
    find(T->Left, K);
}
BinTree KthLargest ( BinTree T, int K ) {
    cnt = 0;
    res = NULL;
    find(T, K);
    return res;
}