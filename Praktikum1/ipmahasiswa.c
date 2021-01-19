// NIM: 13519160
// Nama: Jauhar Wibisono
// Tanggal: 27/08/2020
// Topik Praktikum: Praktikum 1
// Deskripsi: menghitung jumlah mahasiswa, jumlah mahasiswa lulus, jumlah mahasiswa tidak lulus, dan rata-rata IP

#include<stdio.h>
#include<stdbool.h>

bool isWithinRange(float x, float min, float max){
	// Menghasilkan true jika min <= x <= max, menghasilkan false jika tidak
	return (min<=x && x<=max);
}

int main(){
	/* KAMUS */
	int cnt_mahasiswa=0, cnt_lulus=0;
	float total_ip=0, curr_ip;
	/* ALGORITMA */
	do{
		scanf("%f",&curr_ip);
		if (isWithinRange(curr_ip,0,4)){
			cnt_mahasiswa++;
			total_ip+=curr_ip;
			if (curr_ip>=2.75) cnt_lulus++;
		}
	} while ((curr_ip+999<0 ? -(curr_ip+999) : (curr_ip+999))>1e-6);
	if (cnt_mahasiswa==0) printf("Tidak ada data\n");
	else printf("%d\n%d\n%d\n%.2f\n",cnt_mahasiswa,cnt_lulus,cnt_mahasiswa-cnt_lulus,total_ip/cnt_mahasiswa);
	return 0;
}