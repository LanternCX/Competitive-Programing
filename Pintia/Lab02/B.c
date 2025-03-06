#include <stdio.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head ){
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main(){
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
    
    return 0;
}

struct ListNode *reverse(struct ListNode *head) {
    if (!head) return NULL;

    struct ListNode *pre = NULL, *now = head, *next = NULL;
    while (now) {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
    }
    return pre;
}

/**
 * pre now next
 * 
 * pre -> now -> next
 * pre <- now <- next
 */