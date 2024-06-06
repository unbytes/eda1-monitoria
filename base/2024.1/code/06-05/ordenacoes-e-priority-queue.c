#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selection_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int* el = &arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < *el) el = &arr[j];
        }
        swap(el, &arr[i]);
    }
}
//  0  1  2  3  4
// [5, 1, 3, 4, 2]

int min_index(int* arr, int i, int j) {
    if (i == j) return i;

    int k = min_index(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}

void selection_sort_rec(int* arr, int n, int i) {
    if (i == n) return;

    int k = min_index(arr, i, n - 1);
    swap(&arr[i], &arr[k]);
    selection_sort_rec(arr, n, i + 1);
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) swap(&arr[j - 1], &arr[j]);
        }
    }
}

void insertion_sort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// l = 0, r = 8
void shell_sort(int* arr, int l, int r) {
    int h = 1;
    int tam = (r - l) / 3;
    while (h < tam) h = 3 * h + 1;

    for (; h > 0; h /= 3) {
        for (int i = l + h; i < r; i++) {
            for (int j = i; j >= l + h && arr[j] < arr[j - h]; j -= h) {
                swap(&arr[j], &arr[j - h]);
            }
        }
    }
}

void merge(int* arr, int l, int q, int r) {
    int* z = malloc((r - l) * sizeof(int));

    // i = vetor a esquerda
    // j = vertor a direita
    int i = l, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = l; i < r; i++) arr[i] = z[i - l];
    free(z);
}

void merge_sort(int* arr, int l, int r) {
    if (l >= r - 1) return;

    int q = l + (r - l) / 2;
    merge_sort(arr, l, q);
    merge_sort(arr, q, r);
    merge(arr, l, q, r);
}

#define MAX 17 // max 17 - 1 = 16

int N = 0;
int pq[MAX];

void fixUp(int k) {
    while (k > 1 && pq[k / 2] < pq[k]) {
        swap(&pq[k / 2], &pq[k]);
        k /= 2;
    }
}

void fixDown(int k, int N) {
    int j;
    while (2 * k <= N) {
        j = 2 * k;
        // se o filho a direita existe e ele é maior que esquerda
        // então vou usa-lo para trocar se necessário
        if (j < N && pq[j] < pq[j + 1]) j++;
        if (pq[k] >= pq[j]) break;
        swap(&pq[k], &pq[j]);
        k = j;
    }
}

void push(int x) {
    pq[++N] = x;
    fixUp(N);
}

void pop() {
    swap(&pq[1], &pq[N]);
    fixDown(1, N - 1);
    N--;
}

int main() {
    return 0;
}