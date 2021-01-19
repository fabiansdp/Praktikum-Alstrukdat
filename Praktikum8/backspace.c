// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 22 Oktober 2020
// Topik : Stack
// Deskripsi : Nomor 2

#include <stdio.h>
#include "boolean.h"
#include "stackt.h"

int main() {
    Stack S1;
    Stack S2;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    int N,M,CC, XPop, X1, X2;

    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=1; i<=N; i++) {
        scanf("%d", &CC);
        if (CC == 0) {
            if (!IsEmpty(S1)) {
                Pop(&S1, &XPop);
            } 
        } else {
            Push(&S1, CC);
        }
    }

    for (int j = 1; j<=M; j++) {
        scanf("%d", &CC);
        if (CC == 0) {
            if (!IsEmpty(S2)) {
                Pop(&S2, &XPop);
            } 
        } else {
            Push(&S2, CC);
        }
    }

    Pop(&S1, &X1);
    Pop(&S2, &X2);
    
    if (X1 == X2) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }

    return 0;
}