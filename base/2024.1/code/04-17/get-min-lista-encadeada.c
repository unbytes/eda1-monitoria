#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula* prox;
} celula;

void insert(celula* cabeca, int valor) { // O(N), sendo N o tamanho atual da lista
    celula* atual = cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    celula* nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = NULL;
    atual->prox = nova;
}

int get_min(celula* no, int ans) {
    if (no == NULL) return ans;
    if (no->valor < ans) ans = no->valor;
    get_min(no->prox, ans);
}

int main() {
    celula* cabeca = malloc(sizeof(celula));

    int N;
    scanf("%d", &N);

    int valor;
    for (int i = 0; i < N; i++) {
        scanf(" %d", &valor);
        insert(cabeca, valor);
    }

    if (N == 0) {
        printf("-1\n");
        return 0;
    }

    int ans = cabeca->prox->valor;
    int final = get_min(cabeca->prox, ans);

    printf("%d\n", final);

    return 0;
}

/*
ans = 10
cabeca -> 10 2 8 6 3 1 9 7 -> NULL
*/