#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrek.h"

int main() {
    List L = NULL;
    L = Konso(3, L);
    L = Konso(2, L);
    L = Konso(1, L);
    PrintList(Next(L));
    return 0;
}