#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrek.h"


List delNFromStart(List L, int n)
{
    if (n < 1) {
        return L;
    } else if (IsEmpty(L)) {
        return Nil;
    } else if (n == 1) {
        List Temp = Tail(L);
        Dealokasi(L);
        return Temp;
    } else {
        SetNext(L, delNFromStart(Tail(L), n-1));
        return L;
    }
}

List delNFromEnd(List L, int n)
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
{
    return delNFromStart(L, NbElmtList(L) - n + 1);
}