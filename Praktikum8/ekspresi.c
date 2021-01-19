// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 22 Oktober 2020
// Topik : Stack
// Deskripsi : Nomor 1

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "stackt.h"
#include "mesintoken.h"

char CC;
boolean EndToken;
Token CToken;
Stack S;

int hitungToken(int X, int Y, char CC) {
    int hasil;

    switch (CC) {
        case '+':
            hasil = X + Y;
            break;
        case '-':
            hasil = X - Y;
            break;
        case '*':
            hasil = X * Y;
            break;
        case '/':
            hasil = X/Y;
            break;
        case '^':
            hasil = (int) pow(X,Y);
            break;
        default:
            break;
        }
    
    return hasil;
}

int main() {
    int X1, X2;
    CreateEmpty(&S);
    STARTTOKEN();

    if (EndToken) {
        printf("Ekspresi Kosong\n");
    } else {
        do {
            if (CToken.tkn == 'b') {
                Push(&S, CToken.val);
                printf("%d\n", CToken.val);
            } else {
                Pop(&S, &X1);
                Pop(&S, &X2);
                Push(&S, hitungToken(X2, X1, CToken.tkn));
                printf("%d%c%d\n", X2, CToken.tkn, X1);
                printf("%d\n", hitungToken(X2, X1, CToken.tkn));
            }
            ADVTOKEN();
        } while (!EndToken);
        printf("Hasil=%d\n", InfoTop(S));
    }

    return 0;
}