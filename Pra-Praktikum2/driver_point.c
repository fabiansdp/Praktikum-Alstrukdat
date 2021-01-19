// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 2 September 2020
// Deskripsi : Driver Point

#include <stdio.h>
#include <math.h>
#include "Point/src/boolean.h"
#include "Point/src/point.h"

int main() {
    /* KAMUS */
    POINT P1, P2;
    float dx, dy, sudut;
    /* ALGORITMA */
    /* Test Baca dan Tulis */
    printf("Masukkan nilai absis dan ordinat : \n");
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    printf("Titik yang dibaca\n");
    TulisPOINT(P1);
    printf("\n");
    TulisPOINT(P2);
    printf("\n");

    /*Tes EQ dan NEQ*/
    if (EQ(P1,P2))
        printf("EQ : True\n");
    else
        printf("EQ : False\n");

    if (NEQ(P1,P2))
        printf("NEQ : True\n");
    else
        printf("NEQ : False\n");

    /*Tes IsOrigin, IsOnSbX, IsOnSbY*/
    if (IsOrigin(P1))
        printf("IsOrigin : True\n");
    else
        printf("IsOrigin : False\n");

    if (IsOnSbX(P1))
        printf("IsOnSbX : True\n");
    else
        printf("IsOnSbX : False\n");

    if (IsOnSbY(P1))
        printf("IsOnSbY : True\n");
    else
        printf("IsOnSbY : False\n");

    /*Tes Kuadran*/
    printf("Kuadran:\n");
    printf("%d", Kuadran(P1));
    printf("\n");

    /*Tes NextX dan NextY*/
    printf("Next X:\n");
    TulisPOINT(NextX(P1));
    printf("\n");
    printf("Next Y:\n");
    TulisPOINT(NextY(P1));
    printf("\n");

    /*Tes PlusDelta*/
    printf("Masukkan dx dan dy:\n");
    scanf("%f", &dx);
    scanf("%f", &dy);
    printf("PlusDelta:\n");
    TulisPOINT(PlusDelta(P1, dx, dy));
    printf("\n");

    /*Tes MirrorOf*/
    printf("Mirror Of:\n");
    TulisPOINT(MirrorOf(P1, IsOnSbX(P1)));
    printf("\n");

    /*Tes Jarak0*/
    printf("Jarak ke (0,0):\n");
    printf("%f", Jarak0(P1));
    printf("\n");

    /*Tes Panjang*/
    printf("Panjang antara dua titik:\n");
    printf("%f", Panjang(P1,P2));
    printf("\n");

    /*Tes Geser, GeserKeSbX, GeserKeSbY*/
    printf("Masukkan dx dan dy:\n");
    scanf("%f", &dx);
    scanf("%f", &dy);
    printf("Geser menurut dx dan dy:\n");
    Geser(&P1, dx, dy);
    TulisPOINT(P1);
    printf("\n");

    printf("GeserKeSbX:\n");
    GeserKeSbX(&P1);
    TulisPOINT(P1);
    printf("\n");

    printf("GeserKeSbY:\n");
    GeserKeSbY(&P1);
    TulisPOINT(P1);
    printf("\n");

    /*Tes Mirror dan Putar*/
    printf("Mirror P1:\n");
    Mirror(&P1, IsOnSbX(P1));
    TulisPOINT(P1);
    printf("\n");

    printf("Masukkan sudut:\n");
    scanf("%f", &sudut);
    printf("Putar P1:\n");
    Putar(&P1, sudut);
    TulisPOINT(P1);
    printf("\n");

    return 0;
}