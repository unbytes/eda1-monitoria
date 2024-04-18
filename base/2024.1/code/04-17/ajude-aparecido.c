#include <stdio.h>

int ler(int n, int soma) {
    if (n == 0) return soma;
    int tmp;
    scanf(" %d", &tmp); // tmp = 8
    ler(n - 1, soma + tmp); // soma = 6 + 8 = 14 e n = 0
}

/*
3 = N
1 5 8 = ci's
14 = T
*/

int main() {
    int N, T;
    scanf("%d", &N);

    int soma = ler(N, 0);

    scanf("%d", &T);

    if (T == soma) {
        printf("Acertou\n");
    }
    else {
        printf("Errou\n");
    }

    return 0;
}