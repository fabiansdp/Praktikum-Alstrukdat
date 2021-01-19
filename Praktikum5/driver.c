#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

int main() {
    MATRIKS M;
    BacaMATRIKS(&M, 2, 3);
    printf("\n");
    TulisMATRIKS(M);
    printf("\n\n");
    printf("%f\n", RataBrs(M,1));
    printf("%f\n", RataKol(M,2));
    return 0;
}