// Nama : Fabian Savero Diaz Pranoto
// NIM : 13519140
// Tanggal : 8 Oktober 2020
// Topik : Queue
// Deskripsi : Nomor 2

#include <stdio.h>
#include "prioqueuechar.h"


int main() {
    PrioQueueChar Q;
    infotype X;
    int N;
    int urutan = 1;

    // Input N dan buat empty queue
    scanf("%d", &N);
    MakeEmpty(&Q, N);
    
    for (int i=0; i<N; i++) {
        scanf("%d %c", &Prio(X), &Info(X));
        Enqueue(&Q,X);
        
        while (Prio(InfoHead(Q)) == urutan) {
            Dequeue(&Q, &X);
            printf("%d %c\n", i+1, Info(X));
            urutan += 1;
        }
    }

    return 0;
}