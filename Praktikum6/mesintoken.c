// Nama : Fabian Savero Diaz Pranoto
// NIM : 135191140
// Tanggal : 1 Oktober 2020
// Topik : Mesin Karakter
// Deskripsi : Soal 1

#include "boolean.h"
#include "mesintoken.h"

char CC;
boolean EndToken;
Token CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC==BLANK) {
        ADV();
    }
}

void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
    START();
    IgnoreBlank();
    if (CC==MARK) {
        EndToken = true;
    } else {
        EndToken = false;
        SalinToken();
    }
}

void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC==MARK) {
        EndToken = true;
    } else {
        SalinToken();
        IgnoreBlank();
    }
}

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    CToken.val = 0;

    while ((CC!=MARK) && (CC!=BLANK) && (i<NMax)) {
        if ((CC=='+') || (CC=='-') || (CC=='*') || (CC=='/') || (CC=='^')) {
            CToken.tkn = CC;
            CToken.val = -1;
        } else {
            int num = CC - '0';
            CToken.tkn = 'b';
            CToken.val = (CToken.val*10) + num;
        }
        ADV();
        i++;
    }
}