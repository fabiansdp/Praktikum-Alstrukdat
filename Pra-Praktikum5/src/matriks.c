// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 22 September 2020
// Topik : Matriks
// Deskripsi : Body matriks

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return (i>=BrsMin && i<=BrsMax) && (j>=KolMin && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M)-1;
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M)-1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i>=BrsMin) && (i<=GetLastIdxBrs(M))) && ((j>=KolMin) && (j<=GetLastIdxKol(M)));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for (int i=0; i<=GetLastIdxBrs(MIn); i++) {
        for (int j=0; j<=GetLastIdxKol(MIn); j++) {
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    MakeMATRIKS(NB,NK,M);
    if (IsIdxValid (NB, NK)) {
        for (int i=0; i<=GetLastIdxBrs(*M); i++) {
            for (int j=0; j<=GetLastIdxKol(*M); j++) {
                scanf("%d", &Elmt(*M,i,j));
            }
        }   
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for (int i=0; i<=GetLastIdxBrs(M); i++) {
        for (int j=0; j<=GetLastIdxKol(M); j++) {
            if ((i==GetLastIdxKol(M)) && (j==GetLastIdxBrs(M))) {
                printf("%d", Elmt(M,i,j));
            } else if (j==GetLastIdxBrs(M)) {
                printf("%d\n", Elmt(M,i,j));
            } else {
                printf("%d ", Elmt(M,i,j));
            }
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    MATRIKS MHasil;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHasil);
    
    for (int i=0; i<=GetLastIdxBrs(M1); i++) {
        for (int j=0; j<=GetLastIdxKol(M1); j++) {
            Elmt(MHasil,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }

    return MHasil;
} 

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    MATRIKS MHasil;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHasil);
    
    for (int i=0; i<=GetLastIdxBrs(M1); i++) {
        for (int j=0; j<=GetLastIdxKol(M1); j++) {
            Elmt(MHasil,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }    

    return MHasil;
} 

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    MATRIKS MHasil;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MHasil);
    
    for (int i=0; i<=GetLastIdxBrs(M1); i++) {
        for (int j=0; j<=GetLastIdxKol(M2); j++) {
            Elmt(MHasil,i,j) = 0;
            for (int k=0; k<=GetLastIdxBrs(M2); k++) {
                Elmt(MHasil,i,j) = Elmt(MHasil,i,j) + Elmt(M1,i,k)*Elmt(M2,k,j);
            }
        }
    }      

    return MHasil;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    MATRIKS MHasil;
    MakeMATRIKS(NBrsEff(M),NKolEff(M),&MHasil);
    
    for (int i=0; i<=GetLastIdxBrs(M); i++) {
        for (int j=0; j<=GetLastIdxKol(M); j++) {
            Elmt(MHasil,i,j) = Elmt(M,i,j) * X;
        }
    }    

    return MHasil;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    for (int i=0; i<=GetLastIdxBrs(*M); i++) {
        for (int j=0; j<=GetLastIdxKol(*M); j++) {
            Elmt(*M,i,j) = Elmt(*M,i,j) * K;
        }
    }   
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    if ((NBElmt(M1)==NBElmt(M2)) && (GetFirstIdxBrs(M1)==GetFirstIdxBrs(M2)) && (GetLastIdxKol(M1) && GetLastIdxKol(M2))) {
        for (int i = 0; i < NBrsEff(M1); i++) {
            for (int j = 0; j < NKolEff(M1); j++) {
                if (Elmt(M1,i,j) != Elmt(M2,i,j)) {
                    return false;
                }
            }
        }
        return true;               
    }
    return false;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return (!EQ(M1,M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return NBrsEff(M)*NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    if (IsBujurSangkar(M)) {
        for (int i = 0; i < NBrsEff(M); i++)
        {
            for (int j = 0; j < NKolEff(M); j++) {
                if (Elmt(M,i,j) != Elmt(M,j,i)) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
    if (IsBujurSangkar(M)) {
        for (int i = 0; i < NBrsEff(M); i++) {
            if (Elmt(M,i,i) != 1) {
                return false;
            }
            for (int j = 0; j < NKolEff(M); j++) {
                if ((i!=j) && (Elmt(M,i,j) != 0)) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
    int count = 0;

    for (int i=0; i<=GetLastIdxBrs(M); i++) {
        for (int j=0; j<=GetLastIdxKol(M); j++) {
            if (Elmt(M,i,j)!=0) {
                count += 1;
            }
        }
    }     
    
    return (count <= (NBElmt(M)/20));
    
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    MATRIKS MHsl;
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);

    for (int i=0; i<=GetLastIdxBrs(M); i++) {
        for (int j=0; j<=GetLastIdxKol(M); j++) {
            Elmt(MHsl,i,j) = (-1)*Elmt(M,i,j);
        }
    } 

    return MHsl;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    float det;

    if (NBElmt(M)==4) {
        det = (Elmt(M,0,0)*Elmt(M,1,1))-(Elmt(M,1,0)*Elmt(M,0,1));
    } else {
        MATRIKS Res;
        MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1, &Res);
        det=0;
        int sign=1, p=BrsMin;
        for (int i = BrsMin ; i < NBrsEff(M) ; i++) {
        // modified copy matriks minor
            p = BrsMin;
            boolean skip = false;
            for (int j = BrsMin; j < NBrsEff(Res) ; j++) {
                for (int k = KolMin ; k < NKolEff(Res) ; k++) {
                        if ((j == i) && !skip) {
                            p++;
                            skip = true;
                        }
                        Elmt(Res,j,k) = Elmt(M,p,k + 1);
                        //printf("pointer read row %d\n",p+1);
                }
                p++;
            }
            det += (Elmt(M,i,KolMin) * Determinan(Res) * sign);
            sign = sign * (-1);
        }        
    }
    return det;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    PKaliKons(M,(-1));
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    if (IsBujurSangkar(*M)) {
        int temp;
        for (int i=0; i<=GetLastIdxKol(*M); i++) {
            for (int j=0; j<i; j++) {
                temp = Elmt(*M,i,j);
                Elmt(*M,i,j) = Elmt(*M,j,i);
                Elmt(*M,j,i) = temp;
            }
        }         
    }
}