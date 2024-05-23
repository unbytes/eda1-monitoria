#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef ll T;

/*
e = elemento neutro da operação
N = nº de elementos do vetor original
seg = vetor para a árvore segtree

Para inicializar o vetor de 'seg' você deve utilizar
'calloc' em sua função 'main' passando o tamanho como
2*N, ou seja, o dobro do tamanho do vetor original
*/

T e = 0;
ll N;
ll* seg;

// operação de soma
ll op(ll a, ll b) { return a + b; }

// coloca o elemento v na posição i
void assign(ll i, T v) {
    i += N;
    seg[i] = v;
    for (i >>= 1; i; i >>= 1) seg[i] = op(seg[2 * i], seg[2 * i + 1]);
}

// retorna a soma dos elementos no range [l, r]
T query(ll l, ll r) {
    T la = e, ra = e;
    l += N;
    r += N;

    while (l <= r) {
        if (l & 1) la = op(la, seg[l++]);
        if (~r & 1) ra = op(seg[r--], ra);
        l >>= 1;
        r >>= 1;
    }

    return op(la, ra);
}

/*
Exemplo de implementação da main:

int main() {
    ll q;
    // le a qtd de elementos do vetor e a qtd de queries
    scanf("%lld %lld", &N, &q);

    // define segtree com tamanho de 2*N do vetor original
    seg = calloc(N + N, sizeof(ll));

    for (ll i = 0; i < N; i++) {
        // prepara a segtree para as queries colocando cada
        // elemento na posição correta com a func 'assign'
        assign(i, arr[i]);
    }

    // aqui você pode fazer cada uma das queries com [l, r]

    return 0;
}
*/