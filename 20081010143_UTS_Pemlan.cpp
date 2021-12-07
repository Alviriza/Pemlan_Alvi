#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>


#define a 10
int ceklevel(int x);
char cari[50];
struct data {
	char provinsi[50];
	char kotakab[50];
	int totalpenduduk;
	int jumlahlansia;
	int totalvaksin;
	int lansiavaksin;
	int levelppkm;
};
data daerah[a] = {
					{"Jawa Timur", "Surabaya", 1000000, 200000, 600000, 130000, ceklevel(0)},
					{"Jawa Barat", "Bandung", 2000000, 340000, 890000, 260000, ceklevel(1)},
					{"Jawa Tengah", "Semarang", 800000, 320000, 400000, 210000, ceklevel(2)},
					{"Yogyakarta", "Sleman", 700000, 440000, 510000, 335000, ceklevel(3)},
					{"Banten", "Tangerang", 1300000, 620000, 960000, 440000, ceklevel(4)},
					{"NTB", "Mataram", 750000, 125000, 560000, 60000, ceklevel(5)},
					{"Sulawesi Selatan", "Makassar", 900000, 240000, 790000, 160000, ceklevel(6)},
					{"Jawa Timur", "Jombang", 200000, 50000, 170000, 21000, ceklevel(7)},
					{"Jawa Timur", "Sidoarjo", 340000, 170000, 220000, 90000, ceklevel(8)},
					{"Jawa Barat", "Tasikmalaya", 800000, 420000, 765000, 170000, ceklevel(9)},
};
data pencarian[10];
int n;

void delay() {
	int delay;
	delay=1;
	while(delay<100000000) {
		delay++;
	}
}

void loadscr() {
	int i;
	char load[] = {'L','O','A','D','I','N','G'};
	for(i=0; i<=6; i++) {
		printf("%c\t", load[i]);
		delay();
	}
	sleep(2);
}

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
	printf("APLIKASI INFORMASI PERKEMBANGAN PPKM\n");
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

void tampildata() {
	int i, j;
	j = 0;
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\t\tMENU TAMPILKAN DATA\n\n");
	for (i = 0; i < a; i++) {
		j = j + 1;
		printf(" Data Daerah Ke - %i\n",j);
		printf(" ------------------------------------\n");
		printf(" Provinsi\t\t: %s\n",daerah[i].provinsi);
		printf(" Kota / Kab\t\t: %s\n",daerah[i].kotakab);
		printf(" Jumlah Penduduk\t: %i\n",daerah[i].totalpenduduk);
		printf(" Jumlah Lansia\t\t: %i\n",daerah[i].jumlahlansia);
		printf(" Total Vaksinasi\t: %i\n",daerah[i].totalvaksin);
		printf(" Lansia Vaksin\t\t: %i\n",daerah[i].lansiavaksin);
		printf(" Level PPKM\t\t: %i\n",daerah[i].levelppkm);
		printf("\n");
	}
	printf(" \nTekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
}

int ceklevel(int x) {
	int l1vaksin = 0.7*daerah[x].totalpenduduk;
	int l1lansia = 0.6*daerah[x].jumlahlansia;
	int l2vaksin = 0.5*daerah[x].totalpenduduk;
	int l2lansia = 0.4*daerah[x].jumlahlansia;
	if (daerah[x].totalvaksin > l1vaksin && daerah[x].lansiavaksin > l1lansia) {
		return 1;
	} else if (daerah[x].totalvaksin > l2vaksin && daerah[x].lansiavaksin >l2lansia) {
		return 2;
	} else {
		return 3;
	}
}

int urut_ascending() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < (a-1); f++) {
 		min = f;
	 	for (g = f+1; g < a; g++) {
	 		if (daerah[min].levelppkm > daerah[g].levelppkm) {
	 			min = g;
	 		}
	 	}
	 	temp = daerah [f];
 		daerah [f] = daerah [min];
 		daerah [min] = temp;
	}
}

void urut_descending() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f <= a-1; f++) {
 		min = f;
	 	for (g = f+1; g < a; g++) {
	 		if (daerah[min].levelppkm < daerah[g].levelppkm) {
	 			min = g;
	 		}
	 	}
	 	temp = daerah [f];
 		daerah [f] = daerah [min];
 		daerah [min] = temp;
	}
}

void tampilcari() {
	int i, j;
	printf("\t\t\t\t\t\tHASIL PENCARIAN\n\n");
	for (i = 0; i < n; i++) {
		j = j + 1;
		printf(" Data Daerah Ke - %i\n",j);
		printf(" ------------------------------------\n");
		printf(" Provinsi\t\t: %s\n",pencarian[i].provinsi);
		printf(" Kota / Kab\t\t: %s\n",pencarian[i].kotakab);
		printf(" Jumlah Penduduk\t: %i\n",pencarian[i].totalpenduduk);
		printf(" Jumlah Lansia\t\t: %i\n",pencarian[i].jumlahlansia);
		printf(" Total Vaksinasi\t: %i\n",pencarian[i].totalvaksin);
		printf(" Lansia Vaksin\t\t: %i\n",pencarian[i].lansiavaksin);
		printf(" Level PPKM\t\t: %i\n",pencarian[i].levelppkm);
		printf("\n");
	}
	printf(" \nTekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
}

void seq_provinsi() {
	int m;
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\tCARI BERDASARKAN PROVINSI\n\n");
	printf("\nInput Nama yang ingin Dicari  : ");
	fflush(stdin);
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, daerah[m].provinsi) == 0)) {
            pencarian[n] = daerah[m];
            n++;
        }
    }
    if(n > 0) {
    	tampilcari();
	} else {
		printf("\nHasil Pencarian\t: Data Tidak Ditemukan!\n");
		printf("\nTekan ENTER Untuk Kembali Ke Menu Sebelumnya\n");
	}
}

void seq_kabkota() {
	int m;
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\tCARI BERDASARKAN KABUPATEN/KOTA\n\n");
	printf("\nInput Nama yang ingin Dicari  : ");
	fflush(stdin);
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, daerah[m].kotakab) == 0)) {
            pencarian[n] = daerah[m];
            n++;
        }
    }
    if(n > 0) {
    	tampilcari();
	} else {
		printf("\nHasil Pencarian\t: Data Tidak Ditemukan!\n");
		printf("\nTekan ENTER Untuk Kembali Ke Menu Sebelumnya\n");
	}
}

void menuurut() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\t\tMENU URUT DATA\n");
	puts("\n Pilih Menu Dibawah Ini Untuk Menentukan Metode Pengurutan");
	puts("  a.  Urut Berdasarkan Level PPKM (Ascending)");
    puts("  b.  Urut Berdasarkan Level PPKM (Descending)");
    garis(120);
    switch(getch()){
		case 'a' : urut_ascending();
		printf(" Menu Pilihan  : Urut Berdasarkan Level PPKM (Ascending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'b' : urut_descending();
        printf(" Menu Pilihan  : Urut Berdasarkan Level PPKM (Descending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
	}
}

void menucari() {
	do {
		system("cls");
		garis(120);
		header("Muhammad Alviriza Ramadhan", "20081010143", 
				"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
		garis(120);
		printf("\t\t\t\t\t\tMENU SEARCHING DATA\n\n");
		puts("\n  Pilih Menu Dibawah Ini Untuk Menentukan Metode Pencarian");
		puts("   1.  Cari Berdasarkan Provinsi");
	    puts("   2.  Cari Berdasarkan Kota/Kabupaten");
	    puts("  00.  Kembali Ke Menu Awal");
		switch(getch()){
			case '1' : seq_provinsi();
	        break;
	        case '2' : seq_kabkota();
	        break;
	        case '0' : goto awal;
	        break;
		}	
	}
	while(getch()!=27);
	awal:;
}
                     
int main() {
	system("color 70");
    gotoxy(32,13);
	loadscr();
	system("CLS");
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
	    puts("  2.  Urutkan Data");
	    puts("  3.  Cari Data");
	    puts(" Esc. Exit\n");
	    switch(getch()){
	        case '1' : tampildata();
	        break;
	        case '2' : menuurut();
	        break;
	        case '3' : menucari();
	        break;
	    }
	}
	while(getch()!=27);
}


