// NIM: 13519160
// Nama: Jauhar Wibisono
// Tanggal: 27/08/2020
// Topik Praktikum: Praktikum 1
// Deskripsi: mencari maksimum 3 bilangan

#include<stdio.h>
#include<stdbool.h>

int main(){
	/* KAMUS */
	int a, b, c;
	/* ALGORITMA */
	scanf("%d %d %d", &a, &b, &c);
	if (a>=b && a>=c) printf("%d\n",a);
	else if (b>=a && b>=c) printf("%d\n",b);
	else printf("%d\n",c);
	return 0;
}