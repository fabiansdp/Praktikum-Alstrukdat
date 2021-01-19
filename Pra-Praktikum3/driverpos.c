#include <stdio.h>
#include "src/arraypos.h"
#include "src/boolean.h"


void IsiTabelPenuh(TabInt *T) {
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 100 elemen dari 1 hingga 100 */
  MakeEmpty(T);
  int i;
  for (i = IdxMin; i <= IdxMax; i++) {
    Elmt(*T, i) = i + 1;
  }
}

void IsiTabelAcak(TabInt *T) {
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 5 elemen acak */
  MakeEmpty(T);
  Elmt(*T, IdxMin) = 2;
  Elmt(*T, IdxMin + 1) = 3;
  Elmt(*T, IdxMin + 2) = 5;
  Elmt(*T, IdxMin + 3) = 1;
  Elmt(*T, IdxMin + 4) = 4;
}

int main() {
    ElType Max, Min, X;
    TabInt T;
    BacaIsi(&T);
    TulisIsiTab(T);
    printf("\n");
}