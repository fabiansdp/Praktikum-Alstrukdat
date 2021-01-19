#include "listlinier.h"
#include "stdio.h"

int main() {
  List L;
  int value, max, min;
  float average;
  CreateEmpty(&L);
    scanf("%d", &value);
  while ((0 <= value) && (value <= 100)) {
    InsVFirst(&L, value);
    scanf("%d", &value);
  }

  if (IsEmpty(L)) {
    printf("Daftar nilai kosong\n");
  } else {
    printf("%d\n", NbElmt(L));
    printf("%d\n", Max(L));
    printf("%d\n", Min(L));
    printf("%.2f\n", Average(L));
    InversList(&L);
    PrintInfo(L);
    printf("\n");
    InversList(&L);
    PrintInfo(L);
    printf("\n");
  }

  return 0;
}