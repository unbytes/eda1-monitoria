#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node* next;
} node;

node* make_stack() {
    node* sk = (node*)malloc(sizeof(node));
    sk->next = NULL;
    return sk;
}

void push(node* sk, int x) {
    node* nm = make_stack();
    nm->v = x;
    nm->next = sk->next;
    sk->next = nm;
}

void pop(node* sk) {
    if (sk == NULL || sk->next == NULL) return;
    sk->next = sk->next->next;
}

int main() {
    return 0;
}