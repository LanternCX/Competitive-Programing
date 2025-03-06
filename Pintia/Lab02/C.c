#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *get(int idx, node *head) {
    node *now = head;
    int nowIdx = 0;
    while (now && nowIdx < idx) {
        now = now->next;
        nowIdx++;
    }
    return now; 
}

int find(int val, node *head) {
    node *now = head;
    int idx = 0;
    while (now) {
        if (now->data == val) return -1;
        if (now->data > val) return idx;
        now = now->next;
        idx++;
    }
    return idx;
}

node *insert(int idx, int data, node *head) {
    node *new = malloc(sizeof(node));
    new->data = data;

    if (idx == 0) {
        new->next = head;
        return new;
    }
    
    node *pre = get(idx - 1, head);
    new->next = pre->next;
    pre->next = new;
    
    return head;
}

void print(node *head) {
    node *now = head;
    while (now) {
        printf("%d", now->data);
        if (now->next) printf(" ");
        now = now->next;
    }
    printf("\n");
}

node *build(int *arr, int len) {
    if (len == 0) return NULL;
    node *head = malloc(sizeof(node));
    head->data = arr[0];
    head->next = NULL;

    node *now = head;
    for (int i = 1; i < len; i++) {
        node *new = malloc(sizeof(node));
        new->data = arr[i];
        new->next = NULL;
        now->next = new;
        now = new;
    }
    return head;
}

int main() {
    int n, val;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    node *head = build(arr, n);
    scanf("%d", &val);

    int idx = find(val, head);
    if (idx != -1) {
        head = insert(idx, val, head);
    }
    print(head);

    return 0;
}
