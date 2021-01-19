// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 26 November 2020
// Deskripsi : Merkle Tree

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "bintree.h"
#include "listrek.h"

BinTree MakeMerkle2(List L, int start, int length)
{
    if (length == 1) {
        int i = 0;
        address temp = L;
        while (i < start)
        {
            temp = Next(temp);
            ++i;
        }
        return AlokNode(Info(temp));
    } else {
        BinTree kiri, kanan, temp;
        int n = length/2;
        kiri = MakeMerkle2(L, start, n);
        kanan = MakeMerkle2(L, start+n, length - n);
        temp = AlokNode(Akar(kiri) + Akar(kanan));
        Left(temp) = kiri;
        Right(temp) = kanan;
        return temp;
    }
}

int main() {
    List L;
    
    return 0;
}