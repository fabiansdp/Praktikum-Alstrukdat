// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 5 November 2020
// Deskripsi : Cache

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listlinier.h"

int main() {
    int N, Q, x;
    address P;
    List L;

    CreateEmpty(&L);
    scanf("%d", &N);
    scanf("%d", &Q);

    for (int i=1; i<=N; i++) {
        InsVLast(&L, i);
    }

    for (int j=0; j<Q; j++) {
        scanf("%d", &x);
        if (Search(L, x) != Nil) {
            DelP(&L, x);
            InsVFirst(&L, x);
            printf("hit ");
            PrintInfo(L);
            printf("\n");
        } else {
            DelLast(&L, &P);
            Dealokasi(&P);
            InsVFirst(&L, x);
            printf("miss ");
            PrintInfo(L);
            printf("\n");
        }
    }
    return 0;
}