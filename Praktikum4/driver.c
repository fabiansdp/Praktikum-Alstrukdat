#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "boolean.h"

int main() {
    TabInt T1,T2;
    int X;
    MakeEmpty(&T1,100);
    MakeEmpty(&T2,100);
    BacaIsi(&T1);
    BacaIsi(&T2);
    TulisIsiTab(T1);
    printf("\n");
    TulisIsiTab(T2);
    printf("\n");
    TulisIsiTab(PlusMinusTab(T1, T2, true));
    printf("\n");
    printf("%d\n", MaxEl(T1));

    return 0;
}