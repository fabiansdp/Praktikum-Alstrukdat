/*
Nama : Fabian Savero Diaz Pranoto
NIM : 13519140
Tanggal : 17 September 2020
Topik : Array Dinamis
Deskripsi : Soal 1
*/
#include <stdio.h>
#include "arraydin.h"
#include "boolean.h"

int main() {
    TabInt T;
    int maxel, Q, op, num, X;
    // Buat Empty Array
    scanf("%d", &maxel);
    MakeEmpty(&T, maxel);
    // Baca Isi Array
    BacaIsi(&T);
    // Baca Q
    scanf("%d", &Q);

    for (int i=0; i<Q; i++) {
        scanf("%d", &op);
        if (op==1) {
            scanf("%d", &num);
            if (!IsFull(T)) {
                AddAsLastEl(&T, num);
                printf("%d ", MaxElement(T));
                TulisIsiTab(T);
                printf("\n");
            } else {
                printf("array sudah penuh\n");
            }
        }
        if (op==2) {
            scanf("%d", &num);
            GrowTab(&T, num);
            printf("%d ", MaxElement(T));
            TulisIsiTab(T);
            printf("\n");
        }
        if (op==3) {
            scanf("%d", &num);
            if ((MaxElement(T) > num)) {
                ShrinkTab(&T, num);
                if (NbElmt(T) > MaxElement(T)) {
                    Neff(T) = MaxElement(T);
                }
                printf("%d ", MaxElement(T));
                TulisIsiTab(T);
                printf("\n");
            } else {
                printf("array terlalu kecil\n");
            }
        }
        if (op==4) {
            CompactTab(&T);
            printf("%d ", MaxElement(T));
            TulisIsiTab(T);
            printf("\n");
        }
    }
    
    Dealokasi(&T);
    return 0;
}