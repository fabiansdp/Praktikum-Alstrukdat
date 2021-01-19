#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

void InvertBtree(BinTree *P)
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
{
    addrNode Temp;

    if (IsBiner(*P)) {
      InvertBtree(&Left(*P));
      InvertBtree(&Right(*P));

      Temp = Left(*P);
      Left(*P) = Right(*P);
      Right(*P) = Temp;

    } else if (IsUnerLeft(*P)) {
      InvertBtree(&Left(*P));

      Temp = Left(*P);
      Left(*P) = Nil;
      Right(*P) = Temp;

    } else if (IsUnerRight(*P)) {
      InvertBtree(&Right(*P));
      
      Temp = Right(*P);
      Right(*P) = Nil;
      Left(*P) = Temp;
    }
}