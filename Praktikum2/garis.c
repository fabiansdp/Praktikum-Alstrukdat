// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 3 September 2020
// Deskripsi : Soal 2

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "garis.h"

void MakeGARIS (POINT P1, POINT P2, GARIS * L)
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS * L)
{
    POINT P1, P2;

    do {
        BacaPOINT(&P1);
        BacaPOINT(&P2); 

        if (EQ(P1,P2)) {
            printf("Garis tidak valid\n");
        }
    } while (EQ(P1,P2));

    MakeGARIS(P1,P2,L);
}

void TulisGARIS(GARIS L)
{
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)));
}

float PanjangGARIS (GARIS L)
{
    Panjang(PAwal(L), PAkhir(L));
}

float Gradien(GARIS L)
{
    float m;

    m = (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L)));
    return m;
}

void GeserGARIS(GARIS * L, float deltaX, float deltaY)
{
    Absis(PAwal(*L)) += deltaX;
    Absis(PAkhir(*L)) += deltaX;
    Ordinat(PAwal(*L)) += deltaY;
    Ordinat(PAkhir(*L)) += deltaY;
}

boolean IsTegakLurus(GARIS L1, GARIS L2)
{
    return ((Gradien(L1)*Gradien(L2))== -1);
}

boolean IsSejajar(GARIS L1, GARIS L2)
{
    return (Gradien(L1) == Gradien(L2));
}