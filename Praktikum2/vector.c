// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 3 September 2020
// Deskripsi :

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "vector.h"

VECTOR MakeVector(float x, float Y)
{
    VECTOR V;
    AbsisComponent(V) = x;
    OrdinatComponent(V) = Y;
    return V;
}

void TulisVector(VECTOR V)
{
    printf("<%.2f,%.2f>", AbsisComponent(V),OrdinatComponent(V));
}

float Magnitude(VECTOR V)
{
    return sqrt(AbsisComponent(V)*AbsisComponent(V)+OrdinatComponent(V)*OrdinatComponent(V));
}

VECTOR Add(VECTOR a, VECTOR b)
{
    VECTOR c;

    AbsisComponent(c) = AbsisComponent(a)+AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a)+OrdinatComponent(b);
    return c;
}

VECTOR Substract(VECTOR a, VECTOR b)
{
    VECTOR c;

    AbsisComponent(c) = AbsisComponent(a)-AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a)-OrdinatComponent(b);
    return c;
}

float Dot(VECTOR a, VECTOR b)
{
    float absis, ordinat;

    absis = AbsisComponent(a)*AbsisComponent(b);
    ordinat = OrdinatComponent(a)*OrdinatComponent(b);

    return (absis+ordinat);
}

VECTOR Multiply(VECTOR V, float s)
{
    VECTOR a;

    AbsisComponent(a) = s*AbsisComponent(V);
    OrdinatComponent(a) = s*OrdinatComponent(V);

    return a;
}