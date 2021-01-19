// NIM: 13519160
// Nama: Jauhar Wibisono
// Tanggal: 27/08/2020
// Topik Praktikum: Praktikum 1
// Deskripsi: mengonversikan suhu dari satuan Celcius ke satuan lain

#include<stdio.h>
#include<stdbool.h>

int main(){
	/* KAMUS */
	float a;
	char c;
	/* ALGORITMA */
	scanf("%f %c",&a,&c);
	if (c=='R') printf("%.2f\n",4.0/5.0*a);
	else if (c=='F') printf("%.2f\n",(9.0/5.0*a)+32);
	else printf("%.2f\n",a+273.15);
	return 0;
}