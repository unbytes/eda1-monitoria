#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula* nova = malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = le->prox;
    le->prox = nova;
}

void imprime(celula* le) {
    while (le->prox != NULL) {
        le = le->prox;
        printf("%d -> ", le->dado);
    }
    printf("NULL\n");
}

void solve() {
    celula* le = malloc(sizeof(celula));
    le->prox = NULL;

    insere_inicio(le, 2);

    printf("%d\n", le->prox->dado);
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}