// Nama : Fabian Savero Diaz Pranoto
// NIM : 135191140
// Tanggal : 1 Oktober 2020
// Topik : Mesin Karakter
// Deskripsi : Soal 2

#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

boolean EndKata;
boolean EOP;
char CC;
Kata CKata;

boolean IsKataSama(Kata K1, Kata K2) {
    if (K1.Length == K2.Length) {
        for (int i=0; i<K1.Length; i++) {
            if (K1.TabKata[i] != K2.TabKata[i]) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}

int main() {
    int biaya, katareg, katapjg, jumlah = 0;
    int harga;
    // Inisialisasi Koma dan Titik
    Kata KOMA;
    Kata TITIK;

    KOMA.Length = 4;
    KOMA.TabKata[0] = 'K';
    KOMA.TabKata[1] = 'O';
    KOMA.TabKata[2] = 'M';
    KOMA.TabKata[3] = 'A';

    TITIK.Length = 5;
    TITIK.TabKata[0] = 'T';
    TITIK.TabKata[1] = 'I';
    TITIK.TabKata[2] = 'T';
    TITIK.TabKata[3] = 'I';
    TITIK.TabKata[4] = 'K';

    STARTKATA();

    while (!EndKata) {
        if (!IsKataSama(CKata, KOMA) && !IsKataSama(CKata, TITIK)) {
            if (jumlah > 0) {
                printf(" ");
            }

            for (int i=0; i<CKata.Length; i++) {
                printf("%c", CKata.TabKata[i]);
            }

            if (CKata.Length < 10) {
                katareg += 1;
            } else {
                katapjg += 1;
            }

        } else {
            if (IsKataSama(CKata, KOMA)) {
                printf(",");
            }
            if (IsKataSama(CKata, TITIK)) {
                printf(".");
            } 
        }
        jumlah += 1;
        IgnoreBlank();
        ADVKATA();
    }

    harga = (katareg*1000) + (katapjg*1500);
    if (jumlah>10) {
        harga -= harga/10;
    }

    printf("\n");
    printf("%d\n", katareg);
    printf("%d\n", katapjg);
    printf("%d\n", harga);
    return 0;
}