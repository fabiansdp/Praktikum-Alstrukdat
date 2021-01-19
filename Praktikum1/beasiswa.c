// NIM: 13519160
// Nama: Jauhar Wibisono
// Tanggal: 27/08/2020
// Topik Praktikum: Praktikum 1
// Deskripsi: mencari kelompok beasiswa berdasarkan IP dan pendapatan orang tua

#include<stdio.h>
#include<stdbool.h>

int main(){
	/* KAMUS */
	float ip, pot;
	/* ALGORITMA */
	scanf("%f %f",&ip,&pot);
	if (ip>=3.5) printf("4\n");
	else if (pot<1 && ip<3.5) printf("1\n");
	else if (pot>=1 && pot<5 && ip>=2) printf("3\n");
	else if (pot>=1 && pot<5 && ip<2) printf("2\n");
	else printf("0\n");
	return 0;
}