#include <stdio.h>
#include "listsirkuler.h"

int main() {
    List L;
    int N,X;

    CreateEmpty(&L);
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &X);
        InsVFirst(&L,X);
    }
    PrintInfo(L);
    printf("\n");
    return 0;
}