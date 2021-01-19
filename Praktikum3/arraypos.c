// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 9 September 2020
// Topik Praktikum : Array
// Deskripsi : Body Arraypos

#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"

void MakeEmpty (TabInt * T)
{
    IdxType i;
    for (i = IdxMin; i < IdxMax+1; i++)
    {
        Elmt(*T,i) = ValUndef;
    }
    
}

int NbElmt (TabInt T)
{
    IdxType i = IdxMin;
    int Neff = 0;
    
    while (((Elmt(T,i)) != ValUndef) && (i<=IdxMax))
    {
        Neff+=1;
        i++;
    }
    
    return Neff;
}

IdxType GetFirstIdx (TabInt T)
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
{
    return (NbElmt(T)-1);
}

int MaxNbEl (TabInt T)
{
    return (IdxMax - IdxMin + 1);
}

boolean IsIdxValid (TabInt T, IdxType i)
{
    return ((i>=IdxMin) && (i<=IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
{
    return ((i>=GetFirstIdx(T))&&(i<=GetLastIdx(T)));
}

boolean IsEmpty (TabInt T)
{
    return (NbElmt(T) == 0);
}

boolean IsFull (TabInt T)
{
    return (NbElmt(T) == MaxNbEl(T));
}

void BacaIsi (TabInt * T)
{
    IdxType i;
    int N;
    MakeEmpty(T);

    do {
        scanf("%d", &N);
    } while (!((N >= 0) && (N <= MaxNbEl(*T))));

    if (N==0) {
        return;
    } else
    {
        for (i=IdxMin; i<=N-1; i++) {
            scanf("%d", &Elmt(*T,i));
        }
    }
}

void TulisIsiTab (TabInt T)
{
    IdxType i;

    if (IsEmpty(T)) {
        printf("[]");
    } else
    {
        printf("[");
        for (i = IdxMin; i <= GetLastIdx(T); i++)
        {
            if (i!=GetLastIdx(T)) {
                printf("%d,", Elmt(T,i));
            } else {
                printf("%d", Elmt(T,i));
            }
        }
        printf("]");
    }
    
}

TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
{
    IdxType i;

    if (NbElmt(T1)==NbElmt(T2)) {
        TabInt TResult;
        MakeEmpty(&TResult);
        if (plus) {
            for (i = 0; i <= GetLastIdx(T1); i++)
            {
                Elmt(TResult,i) = Elmt(T1,i) + Elmt(T2,i);
            }
        } else
        {
            for (i = 0; i <= GetLastIdx(T1); i++)
            {
                Elmt(TResult,i) = Elmt(T1,i) - Elmt(T2,i);
            }
        }
        return TResult;
    }

    return T1;
}

boolean IsEQ (TabInt T1, TabInt T2)
{
    IdxType i;

    if (NbElmt(T1)==NbElmt(T2)) {
        for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
        {
            if (Elmt(T1,i)!=Elmt(T2,i)) {
                return false;
            }
        }

        return true;
    }

    return false;
}

IdxType Search1 (TabInt T, ElType X)
{
    IdxType i = GetFirstIdx(T);

    while ((i<=GetLastIdx(T))) {
        if (Elmt(T,i) == X)
        {
            return i;
        } else {
            i++;
        }
    }

    return IdxUndef;
}

boolean SearchB (TabInt T, ElType X)
{
    return (Search1(T,X) != IdxUndef);
}

void MaxMin (TabInt T, ElType * Max, ElType * Min)
{
    IdxType i;
    *Max = Elmt(T, 0);
    *Min = Elmt(T, 0);

    for (i = GetFirstIdx(T); i<= GetLastIdx(T); i++) {
        if (Elmt(T,i) > (*Max)) {
            *Max = Elmt(T,i);
        }

        if (Elmt(T,i) < (*Min)) {
            *Min = Elmt(T,i);
        }
    }
}

ElType SumTab (TabInt T)
{
    IdxType i;
    int sumTab = 0;

    if (IsEmpty(T)) {
        return 0;
    } else
    {
        for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++) {
            sumTab += Elmt(T,i);
        }    
    }

    return sumTab;
}

int CountX (TabInt T, ElType X)
{
    IdxType i;
    int count=0;

    if (IsEmpty(T)) {
        return 0;
    } else
    {
        for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
            if (Elmt(T,i) == X) {
                count += 1;
            }
        }
    }
    
    return count;
}

boolean IsAllGenap (TabInt T)
{
    IdxType i;

    for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
        if ((Elmt(T,i)%2) != 0) {
            return false;
        }
    }

    return true;
}

void Sort (TabInt * T, boolean asc)
{
    // Memakai Bubble Sort
    if (!IsEmpty(*T)) {
        IdxType i,j;
        int temp;

        if (asc) {
            for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
                for (j = GetFirstIdx(*T); j <= GetLastIdx(*T)-1; j++)
                {
                    if (Elmt(*T,j) > Elmt(*T,j+1)) {
                        temp = Elmt(*T,j);
                        Elmt(*T,j) = Elmt(*T,j+1);
                        Elmt(*T,j+1) = temp;
                    }
                }                
            }
        } else {
            for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
                for (j = GetFirstIdx(*T); j <= GetLastIdx(*T)-1; j++)
                {
                    if (Elmt(*T,j) < Elmt(*T,j+1)) {
                        temp = Elmt(*T,j);
                        Elmt(*T,j) = Elmt(*T,j+1);
                        Elmt(*T,j+1) = temp;
                    }
                }             
            }
        }
    }
}

void AddAsLastEl (TabInt * T, ElType X)
{
    if (!IsFull(*T)) {
        Elmt(*T,GetLastIdx(*T) + 1) = X;
    }
}

void DelLastEl (TabInt * T, ElType * X)
{
    if (!IsEmpty(*T)) {
        *X = Elmt(*T,GetLastIdx(*T));
        Elmt(*T,GetLastIdx(*T)) = ValUndef;
    }
}