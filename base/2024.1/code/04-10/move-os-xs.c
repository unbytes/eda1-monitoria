// Move os Xs
// 2024.1/docs/move-os-xs.pdf

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void moveX(char* string) {
    if (*string == '\n') return;
    if (*string != 'x') printf("%c", *string);
    moveX(string + 1);
    if (*string == 'x') printf("%c", *string);
}

int main() {
    char string[MAX];
    fgets(string, sizeof(string), stdin);

    moveX(string);
    printf("\n");

    return 0;
}