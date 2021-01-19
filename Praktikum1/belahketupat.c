// NIM: 13519160
// Nama: Jauhar Wibisono
// Tanggal: 27/08/2020
// Topik Praktikum: Praktikum 1
// Deskripsi: menggambar belah ketupat

#include<stdio.h>
#include<stdbool.h>

bool isValid(int n){
	// mengembalikan true jika n positif dan ganjil
	return (n>0 && n%2==1);
}

void GambarBelahKetupat(int n){
	// menggambar belah ketupat berukuran n
	/* KAMUS LOKAL */
	int i, j;
	/* ALGORITMA */
	for (i=0;i<n/2;i++){
		for (j=0;j<n/2-i;j++) printf(" ");
		for (j=0;j<2*i+1;j++) printf("*");
		printf("\n");
	}
	for (i=n/2;i>=0;i--){
		for (j=0;j<n/2-i;j++) printf(" ");
		for (j=0;j<2*i+1;j++) printf("*");
		printf("\n");
	}
	// note: di kanan belah ketupat gaada spasi
}

int main(){
	/* KAMUS */
	int n;
	/* ALGORITMA */
	scanf("%d",&n);
	if (isValid(n)) GambarBelahKetupat(n);
	else printf("Masukan tidak valid\n");
	return 0;
}