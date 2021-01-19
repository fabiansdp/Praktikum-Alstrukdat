// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 2 September 2020
// Deskripsi : Driver Point

#include <stdio.h>
#include <math.h>
#include "Jam/boolean.h"
#include "Jam/jam.h"

int main() {
    JAM J1, J2;
    int n;
    
    /*Tes Tulis dan Baca*/
    BacaJAM(&J1);
    printf("Jam ke-1: ");
    TulisJAM(J1); printf("\n");
    BacaJAM(&J2);
    printf("Jam ke-2: \n");
    TulisJAM(J2); printf("\n");
    
    /*Tes JAMToDetik & DetikToJAM*/
    printf("Jam1 jadi detik: %ld\n", JAMToDetik(J1));
    printf("5600 detik jadi jam: ");
    TulisJAM(DetikToJAM(5600));

    /*Tes JEQ, JNEQ, JLT, JGT*/
    printf("JEQ\n");
    if (JEQ(J1,J2)) {
        printf("Jam sama\n");
    } else
    {
        printf("Jam beda\n");
    }

    printf("JNEQ\n");
    if (JNEQ(J1,J2)) {
        printf("Jam beda\n");
    } else
    {
        printf("Jam sama\n");
    }

    printf("JLT\n");
    if (JLT(J1,J2)) {
        printf("J1 kurang dari J2\n");
    } else
    {
        printf("J1 lebih dari J2\n");
    }

    printf("JGT\n");
    if (JGT(J1,J2)) {
        printf("J1 lebih dari J2\n");
    } else
    {
        printf("J1 kurang dari J2\n");
    }
    
    /*Tes Next dan Prev Detik*/
    printf("Next Detik J1: \n");
    TulisJAM(NextDetik(J1));

    printf("Masukkan detik: \n");
    scanf("%d", &n);
    printf("Next n detik J1: \n");
    TulisJAM(NextNDetik(J1, n));

    printf("Prev Detik J2: \n");
    TulisJAM(PrevDetik(J2));

    printf("Masukkan detik: \n");
    scanf("%d", &n);
    printf("Prev n detik J2: \n");
    TulisJAM(PrevNDetik(J2, n));

    /*Tes Durasi*/
    printf("Selisih J1 dan J2: \n");
    printf("%ld detik\n", Durasi(J1, J2));
}