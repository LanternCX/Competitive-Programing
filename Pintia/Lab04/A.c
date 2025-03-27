#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

const int N = 1e5;
ElementType Find( List L, int m ){
    int cnt = 0;
    PtrToNode p = L;
    int len = 0;
    ElementType arr[N];
    while (p->Next != NULL) {
        p = p->Next;
        arr[len] = p->Data;
        len++;
    }
    return len >= m ? arr[len - m] : ERROR;
}