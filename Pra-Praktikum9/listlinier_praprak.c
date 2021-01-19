/* File : listlinier.C */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "stdio.h"
#include "stdlib.h"
#include "listlinier.h"

/* #define Nil NULL */

/* typedef int infotype; */
/* typedef struct tElmtlist *address; */
/* typedef struct tElmtlist {  */
/*   infotype info; */
/*   address next; */
/* } ElmtList; */
/* typedef struct { */
/*   address First; */
/* } List; */

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* #define Info(P) (P)->info */
/* #define Next(P) (P)->next */
/* #define First(L) (L).First */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
  return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  address P = (address) malloc(1 * sizeof (ElmtList));
  if (P != Nil) {
    Info(P) = X;
    Next(P) = Nil;
    return P;
  } {
    return Nil;
  }
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  address P;
  boolean bFound = false;

  if (!IsEmpty(L)) {
    P = First(L);
    while (!bFound && P != Nil) {
      if (X == Info(P)) {
        bFound = true;
      } else {
        P = Next(P);
      }
    }

    if (bFound) {
      return P;
    } else {
      return Nil;
    }

  } else {
    return Nil;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  address P = Alokasi(X);
  if (P != Nil) {
    InsertFirst(L, P);
  }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  address P = Alokasi(X);
  if (P != Nil) {
    InsertLast(L, P);
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dtpealokasi */
{
  address P = First(*L);
  *X = Info(P);
  First(*L) = Next(P);
  Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  address P = First(*L);
  address Prec = Nil;

  while (Next(P) != Nil) {
    Prec = P;
    P = Next(P);
  }

  *X = Info(P);
  if (Prec != Nil) {
    Next(Prec) = Nil;
  } else {
    First(*L) = Nil;
  }
  Dealokasi(&P);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
  Next(P) = First(*L);
  First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  address Last;

  if (IsEmpty(*L)) {
    InsertFirst(L, P);
  } else {
    Last = First(*L);
    while (Next(Last) != Nil) {
      Last = Next(Last);
    }
    InsertAfter(L, P, Last);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  *P = First(*L);
  First(*L) = Next(First(*L));
  Next(*P) = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
  address Prec;
  address P;
  boolean bFound = false;

  if (!IsEmpty(*L)) {
    if (X == Info(First(*L))) {
      DelFirst(L, &P);
      Dealokasi(&P);
    } else {
      P = First(*L);
      while (!bFound && P != Nil) {
        if (Info(P) == X) {
          bFound = true;
        } else {
          Prec = P;
          P = Next(P);
        }
      }

      if (bFound) {
        DelAfter(L, &P, Prec);
        Dealokasi(&P);
      }
    }
  }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  address Last = First(*L);
  address PrecLast = Nil;

  while (Next(Last) != Nil) {
    PrecLast = Last;
    Last = Next(Last);
  }

  *P = Last;
  if (PrecLast == Nil) {
    First(*L) = Nil;
  } else {
    Next(PrecLast) = Nil;
  }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  *Pdel = Next(Prec);
  Next(Prec) = Next(Next(Prec));
  Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  address P;
  boolean isFirst = true;

  printf("[");
  if (!IsEmpty(L)) {
    P = First(L);
    while (P != Nil) {
      if (!isFirst) {
        printf(",");
      }
      printf("%d", Info(P));
      isFirst = false;

      P = Next(P);
    }
  }
  printf("]");


}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  int cnt = 0;
  address P;

  if (!IsEmpty(L)) {
    P = First(L);
    while (P != Nil) {
      cnt++;
      P = Next(P);
    }
  }

  return cnt;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
  infotype max_temp = Info(First(L));
  address P = Next(First(L));
  while (P != Nil) {
    if (Info(P) > max_temp) {
      max_temp = Info(P);
    }
    P = Next(P);
  }

  return max_temp;
}

/****************** PROSES TERHADAP LIST ******************/

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  address Last1;

  CreateEmpty(L3);
  if (IsEmpty(*L1)) {
    First(*L3) = First(*L2);
  } else {
    First(*L3) = First(*L1);
    Last1 = First(*L1);
    while (Next(Last1) != Nil) {
      Last1 = Next(Last1);
    }
    Next(Last1) = First(*L2);
  }

  First(*L1) = Nil;
  First(*L2) = Nil;
}

