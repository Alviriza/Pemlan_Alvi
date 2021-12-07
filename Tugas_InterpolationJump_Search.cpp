#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <windows.h>

int konversi(int x);
char carijudul[30];
int carikode;
int kunci;
int posisi;
int ditemukan;

struct data {
	int kode;
	char judul[30];
	char pengarang[20];
	int angka;
};
data buku[10] = {
					{3031, "C Programming", "James Lee", konversi(0)},
					{101, "Wordpress Expert", "Andrew Octa", konversi(1)},
					{8812, "Web From Zero to Hero", "David Guetta", konversi(2)},
					{790, "Laravel", "Hans Jackson", konversi(3)},
					{66, "Master Flutter", "Ozur Haskels", konversi(4)},
					{111, "CodeIgniter 4 the guide", "Gantz Patrick", konversi(5)},
					{678, "Raspberry Pi 4", "Tony Watts", konversi(6)},
					{901, "Building Robotic AI", "Leny Imelda", konversi(7)},
					{303, "Data Science with Python", "Ranya Sundar", konversi(8)},
					{4089, "Go Lang Introduction", "Brian Macakzie", konversi(9)},
};
data pencarian[10];
int n = sizeof(buku) / sizeof(buku[0]);

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void garis(int x) {
	int z;
	for(z = 0; z < x; z++) {
		printf("=");
	}
	printf("\n");
}

void header(char nama[50], char npm[50], char kelas[10], 
			char matkul[50], char dosen[50]) 
{
	gotoxy(44,1);
	printf("PROGRAM MANAJEMEN BUKU PERPUSTAKAAN\n");
	garis(120);
	gotoxy(40,3);
	printf("Nama\t\t: %s\n", nama);
	gotoxy(40,4);
	printf("NPM\t\t: %s\n", npm);
	gotoxy(40,5);
	printf("Kelas\t\t: %s\n", kelas);
	gotoxy(40,6);
	printf("Matkul\t\t: %s\n", matkul);
	gotoxy(40,7);
	printf("Dosen Pengampu\t: %s\n", dosen);
}

int konversi(int x) {
    int i, digit, hasil = 0;
    int pjg = strlen(buku[x].judul);
    for(i = 0; i < pjg; i++) {
        digit = buku[x].judul[i];
        hasil = hasil + digit;
    }
    return hasil;
}

int konvertcari(char string[]) {
    int digit, hasil = 0;
    int pjg = strlen(string);
    for(int i = 0; i < pjg; i++) {
        digit = string[i];
        hasil = hasil + digit;
    }
    return hasil;
}

void urut_judul() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < 9; f++) {
 		min = f;
	 	for (g = f+1; g < 10; g++) {
	 		if (buku[min].angka > buku[g].angka) {
	 			min = g;
	 		}
	 	}
	 	temp = buku [f];
 		buku [f] = buku [min];
 		buku [min] = temp;
	}
}

void urut_kode() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < 9; f++) {
 		min = f;
	 	for (g = f+1; g < 10; g++) {
	 		if (buku[min].kode > buku[g].kode) {
	 			min = g;
	 		}
	 	}
	 	temp = buku [f];
 		buku [f] = buku [min];
 		buku [min] = temp;
	}
}

void tampilcari() {
	int i;
	printf("\n\n\t\t\t\t\t\tHASIL PENCARIAN\n\n");
	for(i = 0; i < ditemukan; i++) {
		printf(" Kode Buku\t: %i\n",pencarian[i].kode);
		printf(" Judul Buku\t: %s\n",pencarian[i].judul);
		printf(" Pengarang\t: %s\n\n",pencarian[i].pengarang);
	}
	printf(" Tekan ENTER untuk kembali ke menu utama. \n");
	printf(" Tekan ESC untuk keluar dari program. \n");
}

void jump_search(int kunci, int n) {
    int i;
	int mulai = 0;
	int selesai = sqrt(n);
	ditemukan = 0;
    urut_kode();
    while (buku[selesai].kode <= kunci && selesai < n) {
        mulai = selesai;
        selesai += sqrt(n);
        if (selesai > n-1) {
        	selesai = n;
		}
    }
    for(i = mulai; i < selesai; i++) {
    	if (buku[i].kode == kunci) {
    		pencarian[ditemukan] = buku[i];
        	ditemukan++;
		}
	}
	if(ditemukan > 0) {
    	tampilcari();
	} else {
		printf("\n Hasil Pencarian\t: Data Tidak Ditemukan!\n\n");
		printf(" Tekan ENTER untuk kembali ke menu utama. \n");
		printf(" Tekan ESC untuk keluar dari program. \n");
	}
}

void interpolation_search(int bawah, int atas, int kunci) {
    int tengah;
    urut_judul();
    ditemukan = 0;
    while (bawah <= atas) {
        tengah = bawah + (atas - bawah)*((kunci-buku[bawah].angka)/(buku[atas].angka-buku[bawah].angka));
        if (kunci == buku[tengah].angka) {
        	pencarian[ditemukan] = buku[tengah];
        	ditemukan++;
		}
        if (kunci < buku[tengah].angka) {
            atas = tengah - 1;        	
		}
        else {
            bawah = tengah + 1;        	
		}
    }
    if(ditemukan > 0) {
    	tampilcari();
	} else {
		printf("\n Hasil Pencarian\t: Data Tidak Ditemukan!\n\n");
		printf(" Tekan ENTER untuk kembali ke menu utama. \n");
		printf(" Tekan ESC untuk keluar dari program. \n");
	}
}

void tampildata() {
	int i, j = 0;
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\t\tMENU TAMPIL DATA\n\n");
	for(i = 0; i < 10; i++) {
		j = j + 1;
		printf(" Data Buku Ke - %i\n", j);
		printf(" Kode Buku\t: %i\n",buku[i].kode);
		printf(" Judul Buku\t: %s\n",buku[i].judul);
		printf(" Pengarang\t: %s\n\n",buku[i].pengarang);
	}
	printf(" Tekan ENTER untuk kembali ke menu utama. \n");
	printf(" Tekan ESC untuk keluar dari program. \n");
}

void menujump() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\tPENCARIAN KODE BUKU - JUMP SEARCH\n\n");
	printf("\n Masukkan Kode Buku yang ingin Dicari  : ");
	fflush(stdin);
	scanf("%i", &carikode);
	jump_search(carikode, n);
}

void menuinter() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\tPENCARIAN JUDUL BUKU - INTERPOLATION SEARCH\n\n");
	printf("\n Masukkan Judul Buku yang ingin Dicari  : ");
	fflush(stdin);
	gets(carijudul);
	kunci = konvertcari(carijudul);
	interpolation_search(0, n-1, kunci);
}

int main() {
	system("color 70");
	do {
		system("cls");
		garis(120);
		header("Muhammad Alviriza Ramadhan", "20081010143", 
				"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
		garis(120);
		gotoxy(55,9);
		printf("MENU UTAMA\n");
	    puts("\n Pilih Menu dibawah ini untuk menjalankan aplikasi");
	    puts("  1.  Tampilkan Data");
	    puts("  2.  Pencarian Kode Buku - Jump Search");
	    puts("  3.  Pencarian Judul Buku - interpolation Search");
	    puts(" Esc. Exit\n");
	    switch(getch()){
	        case '1' : tampildata();
	        break;
	        case '2' : menujump();
	        break;
	        case '3' : menuinter();
	        break;
	    }
	}
	while(getch()!=27);
	return 0;
}
