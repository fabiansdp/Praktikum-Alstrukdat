// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 2 September 2020
// Deskripsi : Body Point

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

POINT MakePOINT(float X, float Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void BacaPOINT (POINT * P)
{
    float x,y;
    scanf("%f", &x);
    scanf("%f", &y);
    *P = MakePOINT(x,y);
}

void TulisPOINT (POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2)
{
    return ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}

boolean NEQ(POINT P1, POINT P2)
{
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P)
{
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P)
{
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P)
{
    return (Absis(P) == 0);
}

int Kuadran (POINT P)
{
    if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
        return 1;
    }
    else if ((Absis(P) < 0) && (Ordinat(P) > 0)) {
        return 2;
    }
    else if ((Absis(P) < 0) && (Ordinat(P) < 0)) {
        return 3;
    }
    else if ((Absis(P) > 0) && (Ordinat(P) < 0)) {
        return 4;
    }
    else
    {
        return -1;
    }
    
    
}

POINT NextX (POINT P)
{
    Absis(P) = Absis(P) + 1;
    return P;
}

POINT NextY (POINT P)
{
    Ordinat(P) = Ordinat(P) + 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(P) = Ordinat(P) * -1;
        return P;
    }
    else
    {
        Absis(P) = Absis(P) * -1;
        return P;
    }
}

float Jarak0 (POINT P)
{
    return sqrt((Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2)
{
    float jarakX, jarakY;
    jarakX = Absis(P1) - Absis(P2);
    jarakY = Ordinat(P1) - Ordinat(P2);
    return sqrt(jarakX*jarakX + jarakY*jarakY);
}

void Geser (POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P)
{
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P)
{
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(*P) = Ordinat(*P) * -1;
    }
    else
    {
        Absis(*P) = Absis(*P) * -1;
    }
    
}

void Putar (POINT *P, float Sudut)
{
    float absis = Absis(*P);

    Absis(*P) = Absis(*P)*cos(-Sudut) - Ordinat(*P)*sin(-Sudut);
    Ordinat(*P) = absis*sin(-Sudut) + Ordinat(*P)*cos(-Sudut);
}