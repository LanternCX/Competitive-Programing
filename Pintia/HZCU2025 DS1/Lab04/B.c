#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput( List L1, List L2 ); /* 裁判实现，细节不表 */
void PrintSublist( PtrToNode StartP ); /* 裁判实现，细节不表 */
PtrToNode Suffix( List L1, List L2 );

int main()
{
    List L1, L2;
    PtrToNode P;

    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput( L1, L2 );
    P = Suffix( L1, L2 );
    PrintSublist( P );

    return 0;
}

PtrToNode Suffix( List L1, List L2 ){
    PtrToNode a = L1;
    PtrToNode b = L2;
    int len[2] = {0, 0};
    while (a != NULL) {
        len[0]++;
        a = a->Next;
    }
    while (b != NULL) {
        len[1]++;
        b = b->Next;
    };
    
    if(len[1] > len[0]){
        a = L2;
        b = L1;
        int temp = len[1];
        len[1] = len[0];
        len[0] = temp;
    }else{
        a = L1;
        b = L2;
    }

    for(int i = 0; i < len[0] - len[1]; i++){
        if(a != NULL){
            a = a->Next;
        }else {
            return NULL;
        }
    }

    PtrToNode res = NULL;
    while (a != NULL && b != NULL) {
        if(a == b){
            res = a;
            break;
        }
        a = a->Next;
        b = b->Next;
    }
    return res;
}
