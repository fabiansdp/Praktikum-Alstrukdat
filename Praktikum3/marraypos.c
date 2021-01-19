// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 10 September 2020
// Topik Praktikum : Array
// Deskripsi : Nomor 1

#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"

int main() {
    TabInt T;
    ElType Max, Min, Median;
    int X; 

    // Input Tabel
    BacaIsi(&T);
    scanf("%d", &X);

    // Print Tabel
    TulisIsiTab(T);
    printf("\n");

    // Cari X
    if (SearchB(T,X)) {
        printf("%d\n", Search1(T,X));
    } else {
        printf("%d tidak ada\n", X);
        return 0;
    }

    // Sorting dan cari min, maks, median
    Sort(&T, true);
    MaxMin(T, &Max, &Min);

    // Print min, maks, atau median
    if (X == Max) {
        printf("maksimum\n");
    }

    if (X == Min) {
        printf("minimum\n");
    }

   if(((NbElmt(T)) % 2) == 1) {
		if (X == Elmt(T,((NbElmt(T))/2))) {
			printf("median\n");
		}
	}
	else {
		if (X == Elmt(T,((NbElmt(T))/2)-1)) {
			printf("median\n");
		}
	}

    return 0;
}