// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 2 September 2020
// Deskripsi : Body Jam


#include <stdio.h>
#include "boolean.h"
#include "jam.h"

boolean IsJAMValid (int H, int M, int S)
{
    return ((H>=0 && H<24) && (M>=0 && M<60) && (S>=0 && S<60));
}

JAM MakeJAM (int HH, int MM, int SS)
{
    JAM J;

    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS;

    return J;
}

void BacaJAM (JAM * J)
{
    int h,m,s;

    do {
        scanf("%d", &h);
        scanf("%d", &m);
        scanf("%d", &s);

        if (!IsJAMValid(h,m,s)) {
            printf("Jam tidak valid\n");
        }
    } while (!IsJAMValid(h,m,s));

    *J = MakeJAM(h,m,s);
}

void TulisJAM (JAM J)
{
    printf("%d:%d:%d\n",Hour(J), Minute(J), Second(J));
}

long JAMToDetik (JAM J)
{
    return(3600 * Hour(J) + 60 * Minute(J) + Second(J));
}

JAM DetikToJAM (long N)
{
    int sisa;
    JAM JOut;
    /* Algoritma */
    N = N % 86400; // harus ditambah ini agar valid
    Hour(JOut) = N / 3600;
    sisa = N % 3600;
    Minute(JOut) = sisa / 60;
    Second(JOut) = sisa % 60;
    return JOut;
}

boolean JEQ (JAM J1, JAM J2)
{
    return ((Hour(J1)==Hour(J2)) && (Minute(J1)==Minute(J2)) && (Second(J1)==Second(J2)));
}

boolean JNEQ (JAM J1, JAM J2)
{
    return ((Hour(J1)!=Hour(J2)) && (Minute(J1)!=Minute(J2)) && (Second(J1)!=Second(J2)));
}

boolean JLT (JAM J1, JAM J2)
{
    long jam1, jam2;

    jam1 = JAMToDetik(J1);
    jam2 = JAMToDetik(J2);

    return (jam1 < jam2);
}

boolean JGT (JAM J1, JAM J2)
{
    long jam1, jam2;

    jam1 = JAMToDetik(J1);
    jam2 = JAMToDetik(J2);

    return (jam1 > jam2);
}

JAM NextDetik (JAM J)
{
    long detik = JAMToDetik(J);

    detik += 1;

    return DetikToJAM(detik);
}

JAM NextNDetik (JAM J, int N)
{
    long detik = JAMToDetik(J);

    detik += N;

    return DetikToJAM(detik);
}

JAM PrevDetik (JAM J)
{
    long detik = JAMToDetik(J);

    detik -= 1;

    return DetikToJAM(detik);
}

JAM PrevNDetik (JAM J, int N)
{
    long detik = JAMToDetik(J);

    detik -= N;

    return DetikToJAM(detik);
}

long Durasi (JAM JAw, JAM JAkh)
{
    long j1, j2;

    j1 = JAMToDetik(JAw);
    j2 = JAMToDetik(JAkh);

    if (j1>j2)
    {
        j2 += 86400;
    }

    return (j2-j1);
}