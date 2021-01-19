// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 10 September 2020
// Topik Praktikum : Array
// Deskripsi : Nomor 2

#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"

// Deklarasi Fungsi Ngecek Monotonik
boolean isMonoTdkKecil(TabInt T);
boolean isMonoTdkBesar(TabInt T);
boolean isMonoStatik(TabInt T);

int main() {
    TabInt T;
 
    // Input Tab
    BacaIsi(&T);

    // Cek Monotonik
    if (NbElmt(T) == 1) {
        printf("Array monotonik statik\n");
        return 0;
    }

    if (isMonoStatik(T)) {
        printf("Array monotonik statik\n");
    } else if (isMonoTdkBesar(T)) {
        printf("Array monotonik tidak membesar\n");
    } else if (isMonoTdkKecil(T)) {
        printf("Array monotonik tidak mengecil\n");
    } else {
        printf("Array tidak monotonik\n");
    }

    return 0;
}

// Realisasi Fungsi Cek Monotonik
boolean isMonoTdkKecil(TabInt T)
{
    IdxType i;

    for (i = 0; i < GetLastIdx(T); i++) {
        if (Elmt(T,i) > Elmt(T,i+1)) {
            return false;
        }
    }

    return true;
}

boolean isMonoTdkBesar(TabInt T)
{
    IdxType i;

    for (i = 0; i < GetLastIdx(T); i++) {
        if (Elmt(T,i) < Elmt(T, i+1)) {
            return false;
        }
    }
    
    return true;
}

boolean isMonoStatik(TabInt T) 
{
    IdxType i;

    for (i = 0; i < GetLastIdx(T); i++) {
        if (Elmt(T,i) != Elmt(T,i+1)) {
            return false;
        }
    }

    return true;
}