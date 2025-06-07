#include <stdio.h>

#define MAXN 10

int Height_of_BST( int preorder[], int N );

int main()
{
    int preorder[MAXN], N, i;

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &preorder[i]);
    printf("%d\n", Height_of_BST(preorder, N));

    return 0;
}

int max (int a, int b) {
    return a > b ? a : b;
}

int Height_of_BST(int preorder[], int n) {
    if (n == 1) {
        return 0;
    }
    if (n <= 0) {
        return -1;
    } 

    int rt = preorder[0];

    int idx = 0;
    for (idx = 0; idx < n; idx++) {
        if (preorder[idx] > rt) {
            break;
        }
    }
    int l_siz = idx - 1;
    int r_siz = n - idx;
    
    int l_height = Height_of_BST(preorder + 1, l_siz);
    int r_height = Height_of_BST(preorder + idx, r_siz);

    return max(l_height, r_height) + 1;
}
