/* 
Nama : Fabian Savero Diaz Pranoto
NIM : 13519140
Tanggal : 15 September 2020
Topik : Array Eksplisit
Deskripsi : Body Arraydin
*/
#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "boolean.h"

void MakeEmpty(TabInt *T, int maxel)
{
      TI(*T) = (int*) malloc (maxel * sizeof(int));
      Neff(*T) = 0;
      MaxEl(*T) = maxel;
}

void Dealokasi(TabInt *T)
{
      free(TI(*T));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
{
      return Neff(T);
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
{
      return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
{
      return IdxMin;
}

IdxType GetLastIdx(TabInt T)
{
      return Neff(T) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
{
      return ((i>=GetFirstIdx(T)) && (i<=MaxElement(T)));
}

boolean IsIdxEff(TabInt T, IdxType i)
{
      return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
{
      return (NbElmt(T)==0);
}

boolean IsFull(TabInt T)
{
      return (NbElmt(T)==MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
      IdxType i;
      int N;
      do {
            scanf("%d", &N);
      } while (!((N >= 0) && (N <= MaxElement(*T))));

      Neff(*T) = N;

      if (N==0) {
            return;
      } else {
            for (i=IdxMin; i<=N-1; i++) {
                  scanf("%d", &Elmt(*T,i));
            }
      }
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
      IdxType i;

      if (IsEmpty(T)) {
            printf("[]");
      } else
      {
        printf("[");
        for (i = IdxMin; i <= GetLastIdx(T); i++)
        {
            if (i!=GetLastIdx(T)) {
                printf("%d,", Elmt(T,i));
            } else {
                printf("%d", Elmt(T,i));
            }
        }
        printf("]");
      }      
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
      IdxType i;

      if (NbElmt(T1)==NbElmt(T2)) {
            TabInt TResult;
            MakeEmpty(&TResult, MaxElement(T1));
            Neff(TResult) = Neff(T1);
            if (plus) {
                  for (i = 0; i <= GetLastIdx(TResult); i++)
                  {
                        Elmt(TResult,i) = Elmt(T1,i) + Elmt(T2,i);
                  }
            } else
            {
                  for (i = 0; i <= GetLastIdx(TResult); i++)
                  {
                        Elmt(TResult,i) = Elmt(T1,i) - Elmt(T2,i);
                  }
            }
            return TResult;            
      }
      
      return T1;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
      IdxType i;

      if (NbElmt(T1)==NbElmt(T2)) {
            for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
            {
                  if (Elmt(T1,i)!=Elmt(T2,i)) {
                  return false;
                  }
            }

            return true;
      }

      return false;      
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
      IdxType i = GetFirstIdx(T);

      while ((i<=GetLastIdx(T))) {
            if (Elmt(T,i) == X)
            {
                  return i;
            } else {
                  i++;
            }
      }

      return IdxUndef;
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
      return (Search1(T,X) != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
      IdxType i;
      *Max = Elmt(T, 0);
      *Min = Elmt(T, 0);

      for (i = GetFirstIdx(T); i<= GetLastIdx(T); i++) {
            if (Elmt(T,i) > (*Max)) {
                  *Max = Elmt(T,i);
            }

            if (Elmt(T,i) < (*Min)) {
                  *Min = Elmt(T,i);
            }
      }
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
      IdxType i;

      MakeEmpty(Tout, MaxElement(Tin));
      Neff(*Tout) = Neff(Tin);
      for (i=IdxMin; i<=GetLastIdx(Tin); i++) {
            Elmt(*Tout, i) = Elmt(Tin, i);
      }
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
      IdxType i;
      int sumTab = 0;

      if (IsEmpty(T)) {
            return 0;
      } else
      {
            for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++) {
                  sumTab += Elmt(T,i);
            }    
      }

      return sumTab;
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    IdxType i;
    int count=0;

    if (IsEmpty(T)) {
        return 0;
    } else
    {
        for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
            if (Elmt(T,i) == X) {
                count += 1;
            }
        }
    }
    
    return count;
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    IdxType i;

    for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
        if ((Elmt(T,i)%2) != 0) {
            return false;
        }
    }

    return true;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
      // Memakai Bubble Sort
      if (!IsEmpty(*T)) {
            IdxType i,j;
            int temp;

            if (asc) {
                  for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
                        for (j = GetFirstIdx(*T); j <= GetLastIdx(*T)-1; j++)
                        {
                              if (Elmt(*T,j) > Elmt(*T,j+1)) {
                                    temp = Elmt(*T,j);
                                    Elmt(*T,j) = Elmt(*T,j+1);
                                    Elmt(*T,j+1) = temp;
                              }
                        }                
                  }
            } else {
                  for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
                        for (j = GetFirstIdx(*T); j <= GetLastIdx(*T)-1; j++)
                        {
                              if (Elmt(*T,j) < Elmt(*T,j+1)) {
                                    temp = Elmt(*T,j);
                                    Elmt(*T,j) = Elmt(*T,j+1);
                                    Elmt(*T,j+1) = temp;
                              }
                        }             
                  }
            }
      }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
      if (!IsFull(*T)) {
            Elmt(*T,GetLastIdx(*T) + 1) = X;
            Neff(*T) += 1;
      }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
      if (!IsEmpty(*T)) {
            *X = Elmt(*T,GetLastIdx(*T));
            Neff(*T) -= 1;
      }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
      MaxEl(*T) += num;
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
      MaxEl(*T) -= num; 
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
      if (!IsEmpty(*T)) {
            MaxEl(*T) = Neff(*T);
      }
}