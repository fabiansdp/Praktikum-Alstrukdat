#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

int main() {
    Stack S;
    infotype X;

    CreateEmpty(&S);
    for (int i=0; i<6; i++) {
        Push(&S,i);
    }
    
    for (int i=0; i<6; i++) {
        Pop(&S,&X);
        printf("%d\n",X);
    }

    return 0;
}