#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node* left, * right;
} node;

node* make(int x) {
    node* nm = (node*)malloc(sizeof(node));
    nm->left = NULL;
    nm->right = NULL;
    nm->v = x;
    return nm;
}

void add(node* p, int x) {
    if (p->v == x) return;
    if (x < p->v) {
        if (p->left == NULL) {
            p->left = make(x);
            return;
        }
        add(p->left, x);
    } else {
        if (p->right == NULL) {
            p->right = make(x);
            return;
        }
        add(p->right, x);
    }
}

/*
0 = não achou
1 = achou
*/
int search(node* p, int x) {
    if (p == NULL) return 0;
    if (p->v == x) return 1;
    if (x < p->v) return search(p->left, x);
    else return search(p->right, x);
} 

int main() {
    return 0;
}