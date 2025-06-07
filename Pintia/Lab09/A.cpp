#include <stdio.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

void PercolateUp(int p, PriorityQueue H) {
    ElementType temp = H->Elements[p];
    // 下标 p 节点的父节点的下标为 p / 2
    while (p > 1 && H->Elements[p / 2] > temp) {
        // 如果 p 节点的父节点 依旧小于需要上滤的 p 那么就继续移动空位
        H->Elements[p] = H->Elements[p / 2];
        p /= 2;
    } 
    H->Elements[p] = temp;
}

void PercolateDown(int p, PriorityQueue H) {
    ElementType temp = H->Elements[p];
    // p * 2 是节点 p 的左子节点
    // 偶数位都存储左子节点，奇数位都存储右子节点
    int child;
    while (p * 2 <= H->Size) {
        int left = p * 2;
        int right = left + 1;
        // 找到较小的子节点向上替换
        if (right <= H->Size && H->Elements[right] < H->Elements[left]) {
            child = right;
        } else {
            child = left;
        }

        if (H->Elements[child] < temp) {
            H->Elements[p] = H->Elements[child];
            p = child;
        } else {
            break;
        }
    }
    H->Elements[p] = temp;
}