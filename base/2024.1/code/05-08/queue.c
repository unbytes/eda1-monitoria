#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node* next;
} node;

node* make_queue() {
    node* q = (node*)malloc(sizeof(node)); // inicializa ponteiro para node
    q->next = NULL;
    return q;
}

node* push(node* last, int x) {
    node* nm = make_queue(); // cria novo (último) nó
    nm->next = last->next;
    last->next = nm;
    last->v = x;
    // novo nó virou o último e o valor foi colocado no antigo
    return nm;
}

void pop(node* f) {
    f->next = f->next->next;
}

int main() {
    return 0;
}