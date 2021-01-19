// Tanur Rizaldi Rahardjo 13519214

#include "matriks.h"
#include <stdio.h>

// procedure TulisNilaiX (input M : Matriks, input j : indeks, input X : ElType)
// { Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
// { Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
// { Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
// { I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
// { F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
// Jika tidak ada elemen dengan nilai = X, menuliskan [] */
// { Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
// 1 3 3
// 2 5 6
// 7 3 9
// maka jika j = 1 dan X = 3, akan tercetak: [0,2]
// }
void TulisNilaiX(MATRIKS M, int j, int X) {
    int xCt = CountXKol(M,j,X);
    printf("[");
    for (int i = 0 ; i < M.NBrsEff ; i++)
        if ((xCt > 0) && (Elmt(M,i,j) == X))
            (xCt-- == 1) ? printf("%d",i) : printf("%d,",i);
    printf("]");
}


// procedure TulisStatistikMhs (input M : Matriks, input i : indeks)
// { Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
// { Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
// { Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
// { I.S. M terdefinisi, i adalah indeks baris efektif M }
// { F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
// [i] <rata-rata> <nilai max> <nilai min> }
// { Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
// 100 83 83
// 72 55 60
// 77 93 90
// maka jika i = 1 akan tercetak:
// [1] 62.33 72 55
// }
void TulisStatistikMhs(MATRIKS M, int i) {
    int tMax = -9999, tMin = 9999;
    float tRat = RataBrs(M,i);
    MaxMinBrs(M,i,&tMax,&tMin);
    printf("[%d] %.2f %d %d",i,tRat,tMax,tMin);
}

// procedure TulisStatistikMK (input M : Matriks, input j : indeks)
// { Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
// { Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
// { Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
// { I.S. M terdefinisi, j adalah indeks kolom efektif M }
// { F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
// [j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
// { Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
// 100 83 83
// 72 55 60
// 77 93 90
// maka jika j = 1 akan tercetak:
// [1] 77.00 [93 1 [2]] [55 1 [1]]
// }
void TulisStatistikMK(MATRIKS M, int j) {
    int tMax = -9999, tMin = 9999;
    float tRat = RataKol(M,j);
    MaxMinKol(M,j,&tMax,&tMin);
    printf("[%d] %.2f [%d %d ",j,tRat,tMax,CountXKol(M,j,tMax));
    TulisNilaiX(M,j,tMax);
    printf("] [%d %d ",tMin,CountXKol(M,j,tMin));
    TulisNilaiX(M,j,tMin);
    printf("]");
}

int main() {
    MATRIKS S;
    int r = 0, c = 0;
    scanf("%d %d",&r,&c);
    BacaMATRIKS(&S,r,c);
    printf("STATISTIK PER MAHASISWA\n");
    for (int i = 0 ; i < S.NBrsEff ; i++) {
        TulisStatistikMhs(S,i);
        printf("\n");
    }
    printf("STATISTIK PER MATA KULIAH\n");
    for (int j = 0 ; j < S.NKolEff ; j++) {
        TulisStatistikMK(S,j);
        //if (j != (S.NKolEff - 1))
            printf("\n");
    }
    return 0;
}
