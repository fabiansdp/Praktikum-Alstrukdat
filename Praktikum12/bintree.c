// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 25 November 2020
// Deskripsi : Binary Tree

#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"
#include "boolean.h"
#include "bintree.h"

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
    BinTree T = (BinTree) malloc (sizeof(BinTree));

    if (T != Nil) {
        Akar(T) = Akar;
        Left(T) = L;
        Right(T) = R;
    }

    return T;
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
    *P = Tree(Akar, L, R);
}

BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
{
    if (n == 0) {
        return Nil;
    } else {
        infotype X;
        int nL, nR;
        // Input Nilai Node
        scanf("%d\n", &X);
        addrNode P = AlokNode(X);

        if (P != Nil) {
            // Partisi sisa node sebagai anak kiri dan anak kanan
            nL = div(n,2).quot;
            nR = n - nL - 1;
            // Buat bintree kiri dan kanan
            BinTree Kiri = BuildBalanceTree(nL);
            BinTree Kanan = BuildBalanceTree(nR);
            // Hubungkan tree kanan dan kiri
            Left(P) = Kiri;
            Right(P) = Kanan;
        }
        return P;
    }
}

/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrNode P = (addrNode) malloc (sizeof(addrNode));

    if (P != Nil) {
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }

    return P;
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (P == Nil);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (!IsTreeEmpty(P)) {
        return ((Left(P) == Nil) && (Right(P) == Nil));
    } else {
        return false;
    }
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    if (!IsTreeEmpty(P)) {
        return ((Left(P) != Nil) && (Right(P) == Nil));
    } else {
        return false;
    }
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    if (!IsTreeEmpty(P)) {
        return ((Left(P) == Nil) && (Right(P) != Nil));
    } else {
        return false;
    }
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    if (!IsTreeEmpty(P)) {
        return ((Left(P) != Nil) && (Right(P) != Nil));
    } else {
        return false;
    }
}

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    printf("(");

    if (!IsTreeEmpty(P)) {
        printf("%d", Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
    }

    printf(")");
}

void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    printf("(");

    if (!IsTreeEmpty(P)) {
        PrintInorder(Left(P));
        printf("%d", Akar(P));
        PrintInorder(Right(P));
    }

    printf(")");
}

void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    printf("(");

    if (!IsTreeEmpty(P)) {
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d", Akar(P));
    }

    printf(")");
}

void PrintRecursive(BinTree P, int h, int currLine) {
    if(!IsTreeEmpty(P)){
      printf("%*s%d\n", currLine, "",Akar(P));
      PrintRecursive(Left(P), h, currLine + h);
      PrintRecursive(Right(P), h, currLine + h);
   }
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    PrintRecursive(P, h, 0);
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        if (Akar(P) == X) {
            return true;
        } else {
            return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
        }
    }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if (IsTreeEmpty(P)) {
        return 0;
    } else {
        return (NbElmt(Left(P)) + NbElmt(Right(P)) + 1);
    }
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if (IsTreeEmpty(P)) {
        return 0;
    } else {
        if (IsTreeOneElmt(P)) {
            return 1;
        } else {
            return (NbDaun(Left(P)) + NbDaun(Right(P)));
        }
    }
}

boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
    if (IsTreeEmpty(P)) {
        return true;
    } else if (IsTreeOneElmt(P)) {
        return true;
    } else {
        return (IsSkewLeft(Left(P)) && (Right(P) == Nil));
    }
}

boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
    if (IsTreeEmpty(P)) {
        return true;
    } else if (IsTreeOneElmt(P)) {
        return true;
    } else {
        return (IsSkewRight(Right(P)) && (Left(P) == Nil));
    }
}

int Level(BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
    if (SearchTree(Left(P), X)) {
        return 1 + Level(Left(P), X);
    } else if (SearchTree(Right(P), X)) {
        return 1 + Level(Right(P), X);
    } else {
        return 1;
    }
}

int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
    if (IsTreeEmpty(P)) {
        return 0;
    } else {
        int tinggiKiri = Tinggi(Left(P));
        int tinggiKanan = Tinggi(Right(P));

        if (tinggiKiri > tinggiKanan) {
            return 1 + tinggiKiri;
        } else {
            return 1 + tinggiKanan;
        }
    }
}

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
    if (IsTreeEmpty(*P)) {
        *P = Tree(X, Nil, Nil);
    } else {
        AddDaunTerkiri(&Left(*P), X);
    }
}

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
    if (IsTreeOneElmt(*P) && Akar(*P) == X) {
        if (Kiri) {
            Left(*P) = Tree(Y, Nil, Nil);
        } else {
            Right(*P) = Tree(Y, Nil, Nil);
        }

    } else {
        if (SearchTree(Left(*P), X)) {
            AddDaun(&Left(*P), X, Y, Kiri);
        } else if (SearchTree(Right(*P), X)) {
            AddDaun(&Right(*P), X, Y, Kiri);
        }

    }
}

void DelDaunTerkiri(BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
{
    if (IsTreeOneElmt(*P)) {
        *X = Akar(*P);
        addrNode DelNode = *P;
        *P = Nil;
        DealokNode(DelNode);
    } else {
        if (IsUnerRight(*P)) {
            DelDaunTerkiri(&Right(*P), X);
        } else {
            DelDaunTerkiri(&Left(*P), X);
        }
    }
}

void DelDaun(BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
    if (!IsTreeEmpty(*P)) {
        if (IsTreeOneElmt(*P) && Akar(*P) == X) {
            addrNode DelNode = *P;
            *P = Nil;
            DealokNode(DelNode);
        } else {
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

List MakeListDaun(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
    if (IsTreeEmpty(P)) {
        return Nil;
    } else if (IsTreeOneElmt(P)) {
        return Alokasi(Akar(P));
    } else {
        List Kiri = MakeListDaun(Left(P));
        List Kanan = MakeListDaun(Right(P));

        return Concat(Kiri, Kanan);
    }
}

List MakeListPreorder(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   dengan urutan preorder, jika semua alokasi berhasil.   
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
    if (IsTreeEmpty(P)) {
        return Nil;
    } else {
        List Kiri = MakeListPreorder(Left(P));
        List Kanan = MakeListPreorder(Right(P));

        return Concat(Konso(Akar(P), Kiri), Kanan);
    }
}

List MakeListLevel(BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
    if (IsTreeEmpty(P)) {
        return Nil;
    } else if (N==1) {
        return Alokasi(Akar(P));
    } else {
        List Kiri = MakeListLevel(Left(P), N-1);
        List Kanan = MakeListLevel(Right(P), N-1);

        return Concat(Kiri, Kanan);
    }
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    return SearchTree(P, X);
}

void InsSearch(BinTree *P, infotype X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */
{
    if (IsTreeEmpty(*P)) {
        MakeTree(X, Nil, Nil, P);
    } else {
        if (X <= Akar(*P)) {
            InsSearch(&Left(*P), X);
        } else {
            InsSearch(&Right(*P), X);
        }
    }
}

void DelNode(BinTree *P, BinTree *Q)
{
    if (Right(*P) == Nil) {
        Akar(*Q) = Akar(*P);
        *Q = *P;
        *P = Left(*P);
    } else {
        DelNode(&Right(*P), Q);
    }
}

void DelBtree(BinTree *P, infotype X)
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
{
    if (X < Akar(*P)) {
        DelBtree(&Left(*P), X);
    } else if (X > Akar(*P)) {
        DelBtree(&Right(*P), X);
    } else {
        addrNode Delete = *P;

        if (IsTreeOneElmt(Delete)) {
            *P = Nil;
        } else if (IsUnerLeft(Delete)) {
            *P = Left(*P);
        } else if (IsUnerRight(Delete)) {
            *P = Right(*P);
        } else if (IsBiner(Delete)) {
            DelNode(&Left(Delete),&Delete);
        }
        DealokNode(Delete);
    }
}