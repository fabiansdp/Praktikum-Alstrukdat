// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 3 September 2020
// Deskripsi : Soal 1

#include <stdio.h>
#include "boolean.h"
#include "jam.h"


int main() {
    JAM J1, J2, jAwal, jAkhir, temp;
    int i = 0;
    int jmlh;

    scanf("%d", &jmlh);
    /*Inisialisasi jawal dan jakhir*/
    Hour(jAwal) = 23;
    Minute(jAwal) = 59;
    Second(jAwal) = 59;
    Hour(jAkhir) = 0;
    Minute(jAkhir) = 0;
    Second(jAkhir) = 0;

    while (i<jmlh)
    {
        /*Input Jam*/
        printf("[%d]\n", i+1);
        BacaJAM(&J1);
        BacaJAM(&J2);

        if (JLT(J1,J2)) {
            printf("%ld\n", Durasi(J1,J2));
        } else
        {
            temp = J1;
            J1 = J2;
            J2 = temp;
            printf("%ld\n", Durasi(J1,J2));
        }

        if (JLT(J1,jAwal)) {
            jAwal = J1;
        }

        if (JGT(J2, jAkhir)) {
            jAkhir = J2;
        }
        
        i++;
    }

    TulisJAM(jAwal);
    printf("\n");
    TulisJAM(jAkhir);
    printf("\n");
    
    return 0;
}