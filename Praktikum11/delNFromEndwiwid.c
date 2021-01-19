#include "listrek.h"
#include <stdlib.h>

List delNFromStart(List L, int n){
    if (n < 1) return L;
    if (IsEmpty(L)) return Nil;
    if (n == 1){
        List temp = Tail(L);
        Dealokasi(L);
        return temp;
    }else{
        SetNext(L,delNFromStart(Tail(L), n-1));
        return L;
    }
    
}

List delNFromEnd(List L, int n){
    return delNFromStart(L,NbElmtList(L) - n + 1);
}

