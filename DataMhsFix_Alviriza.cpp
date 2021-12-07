#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

char cari[50];
struct data {
	char npm[20];
	char nama[50];
	char kelas[10];
	char asal[20];
	char lahir[15];
	char jurusan[20];
};
data maks[50];
data pencarian[50];
int a, b, c, d, m, n;

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
	printf("PROGRAM MANAJEMEN DATA MAHASISWA\n");
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

void tambahdata() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\t\tMENU TAMBAH DATA\n\n");
	printf("Masukkan Jumlah Data Yang Akan diinput : ");
	scanf("%i", &b);
	printf("\nUntuk Bagian NPM pada Data kedua dan seterusnya tambahkan Spasi Terlebih Dahulu!\n");
	printf("Format Tanggal : dd-mm-yyyy\n");
	d = 0;
	for(c = 0; c < b; c++) {
		d = d+1;
		printf("\nData ke - %d\n", d);
		printf("NPM\t\t:");
		getchar();
		gets(maks[a].npm);
		printf("Nama\t\t: ");
		gets(maks[a].nama);
		printf("Kelas\t\t: ");
		gets(maks[a].kelas);
		printf("Asal\t\t: ");
		gets(maks[a].asal);
		printf("Tanggal Lahir\t: ");
		gets(maks[a].lahir);
		printf("Jurusan\t\t: ");
		gets(maks[a].jurusan);
		a++;
	}
}

void tampildata() {
	int i, j;
	int x;
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\t\tMENU TAMPILKAN DATA\n\n");
	garis(120);
	printf("||  NO  ||\tNPM\t||\t\tNama\t\t||  Kelas  ||      Asal     || Tanggal Lahir ||    Jurusan    ||\n");
	j = 0;
	for(i = 0; i < a; i++) {
		j = j + 1;
		garis(120);
		printf("||  %i", j);
		if (j < 10) {
			printf("   ");
		} else {
			printf("  ");
		}
		printf("||");
		//Panjang tabel NPM 14 karakter
		printf("%s",maks[i].npm);
		for(x = 0; x < 14-strlen(maks[i].npm); x++) {
			printf(" ");
		}
		printf("||");
		//Panjang tabel nama 30 karakter
		printf("%s",maks[i].nama);
		for(x = 0; x < 30-strlen(maks[i].nama); x++) {
			printf(" ");
		}
		printf("||");
		//Panjang tabel kelas 9 karakter
		printf("%s",maks[i].kelas);
		for(x = 0; x < 9-strlen(maks[i].kelas); x++) {
			printf(" ");
		}
		printf("||");
		//Panjang tabel asal 15 karakter
		printf("%s",maks[i].asal);
		for(x = 0; x < 15-strlen(maks[i].asal); x++) {
			printf(" ");
		}
		printf("||");
		//Panjang tabel tanggal lahir 15 karakter
		printf("%s",maks[i].lahir);
		for(x = 0; x < 15-strlen(maks[i].lahir); x++) {
			printf(" ");
		}
		printf("||");
		printf("%s",maks[i].jurusan);
		for(x = 0; x < 15-strlen(maks[i].jurusan); x++) {
			printf(" ");
		}
		printf("||");
		printf("\n");
	}
	garis(120);
	printf("\n Tekan ENTER untuk kembali ke Menu Utama.\n");
}

void ubahdata() {
	int k, l;
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\t\tMENU EDIT DATA\n\n");
	printf("Masukan Nomor Data yang akan diedit : ");
	scanf("%i", &k);
	l = k-1;
	printf("\nMasukkan Data Baru. \n");
	printf("NPM\t\t: ");
	getchar();
	gets(maks[l].npm);
	printf("Nama\t\t: ");
	gets(maks[l].nama);
	printf("Kelas\t\t: ");
	gets(maks[l].kelas);
	printf("Asal\t\t: ");
	gets(maks[l].asal);
	printf("Tanggal Lahir\t: ");
	gets(maks[l].lahir);
	printf("Jurusan\t\t: ");
	gets(maks[l].jurusan);
	printf("\nData Ke - %i Telah Berhasil Diubah!\n", k);
	printf("\nSilahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.\n\n");
}

void hapusdata() {
	int i, x, y;
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\t\tMENU HAPUS DATA\n\n");
	printf("Masukkan Nomor Data Yang Ingin Dihapus : ");
	scanf("%i", &x);
	y = x-1;
	a--;
	for(i = y; i < a; i++) {
		maks[i] = maks[i+1];
	}
	printf("\nData ke - %d Telah Terhapus!\n\n", x);
}

void buble_npm_ascending(data total []) {
	int f;
 	int g;
 	data temp;
	for(f = 0; f < (a-1); f++) {
        for(g = 0; g < a-f-1; g++) {
            if((strcmp (total[g].npm, total[g+1].npm) > 0)) {
                temp = total [g];
		 		total [g] = total [g+1];
		 		total [g+1] = temp;
            }
        }
    }
}

void buble_npm_descending(data total []) {
	int f;
 	int g;
 	data temp;
	for(f = 0; f < (a-1); f++) {
        for(g = 0; g < a-f-1; g++) {
            if((strcmp (total[g].npm, total[g+1].npm) < 0)) {
                temp = total [g];
		 		total [g] = total [g+1];
		 		total [g+1] = temp;
            }
        }
    }
}

void buble_nama_ascending(data total []) {
	int f;
 	int g;
 	data temp;
	for(f = 0; f < (a-1); f++) {
        for(g = 0; g < a-f-1; g++) {
            if((strcmp (total[g].nama, total[g+1].nama) > 0)) {
                temp = total [g];
		 		total [g] = total [g+1];
		 		total [g+1] = temp;
            }
        }
    }
}

void buble_nama_descending(data total []) {
	int f;
 	int g;
 	data temp;
	for(f = 0; f < (a-1); f++) {
        for(g = 0; g < a-f-1; g++) {
            if((strcmp (total[g].nama, total[g+1].nama) < 0)) {
                temp = total [g];
		 		total [g] = total [g+1];
		 		total [g+1] = temp;
            }
        }
    }
}

void select_npm_ascending(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> npm,(total + g) -> npm)) > 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void select_npm_descending(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> npm,(total + g) -> npm)) < 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void select_nama_ascending(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> nama,(total + g) -> nama)) > 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void select_nama_descending(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> nama,(total + g) -> nama)) < 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void insert_npm_ascending(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].npm, total[g].npm) > 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void insert_npm_descending(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].npm, total[g].npm) < 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void insert_nama_ascending(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].nama, total[g].nama) > 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void insert_nama_descending(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].nama, total[g].nama) < 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void tampilcari() {
	int i, x, z;
	printf("\n\t\t\t\t\t\tHASIL PENCARIAN\n");
    	garis(120);
		printf("||  NO  ||\tNPM\t||\t\tNama\t\t||  Kelas  ||      Asal     || Tanggal Lahir ||    Jurusan    ||\n");
		z = 0;
		for(i = 0; i < n; i++) {
			z = z + 1;
			garis(120);
			printf("||  %i", z);
			if (z < 10) {
				printf("   ");
			} else {
				printf("  ");
			}
			printf("||");
			//Panjang tabel NPM 14 karakter
			printf("%s",pencarian[i].npm);
			for(x = 0; x < 14-strlen(pencarian[i].npm); x++) {
				printf(" ");
			}
			printf("||");
			//Panjang tabel nama 30 karakter
			printf("%s",pencarian[i].nama);
			for(x = 0; x < 30-strlen(pencarian[i].nama); x++) {
				printf(" ");
			}
			printf("||");
			//Panjang tabel kelas 9 karakter
			printf("%s",pencarian[i].kelas);
			for(x = 0; x < 9-strlen(pencarian[i].kelas); x++) {
				printf(" ");
			}
			printf("||");
			//Panjang tabel asal 15 karakter
			printf("%s",pencarian[i].asal);
			for(x = 0; x < 15-strlen(pencarian[i].asal); x++) {
				printf(" ");
			}
			printf("||");
			//Panjang tabel tanggal lahir 15 karakter
			printf("%s",pencarian[i].lahir);
			for(x = 0; x < 15-strlen(pencarian[i].lahir); x++) {
				printf(" ");
			}
			printf("||");
			printf("%s",pencarian[i].jurusan);
			for(x = 0; x < 15-strlen(pencarian[i].jurusan); x++) {
				printf(" ");
			}
			printf("||");
			printf("\n");
		}
		garis(120);
		printf("\n");
}

void seq_npm() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\tSEQUENTIAL SEARCH - CARI BERDASARKAN NPM\n\n");
	printf("\nInput NPM yang ingin Dicari  : ");
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, maks[m].npm) == 0)) {
            pencarian[n] = maks[m];
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

void seq_nama() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	printf("\t\t\t\t\tSEQUENTIAL SEARCH - CARI BERDASARKAN NAMA\n\n");
	printf("\nInput Nama yang ingin Dicari  : ");
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, maks[m].nama) == 0)) {
            pencarian[n] = maks[m];
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

void bin_npm() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	int bawah = 0;
	int atas = a;
	buble_npm_ascending(maks);
	printf("\t\t\t\t\tBINARY SEARCH - CARI BERDASARKAN NPM\n\n");
	printf("\nInput NPM yang ingin Dicari  : ");
    gets(cari);
	n = 0;
    while(bawah <= atas) {
    	m = (bawah + atas) / 2;
        if((strcmp (cari, maks[m].npm) == 0)) {
            pencarian[n] = maks[m];
            n++;
            break;
        } else if((strcmp (cari, maks[m].npm) > 0)) {
        	bawah = m + 1;
    	} else {
    		atas = m - 1;
    	}
    }
    
    if(n > 0) {
    	tampilcari();
	} else {
		printf("\nHasil Pencarian\t: Data Tidak Ditemukan!\n");
		printf("\nTekan ENTER Untuk Kembali Ke Menu Sebelumnya\n");
	}
}

void bin_nama() {
	system("cls");
	garis(120);
	header("Muhammad Alviriza Ramadhan", "20081010143", 
			"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	garis(120);
	int bawah = 0;
	int atas = a;
	buble_nama_ascending(maks);
	printf("\t\t\t\t\tBINARY SEARCH - CARI BERDASARKAN NAMA\n\n");
	printf("\nInput Nama yang ingin Dicari  : ");
    gets(cari);
	n = 0;
    while(bawah <= atas) {
    	m = (bawah + atas) / 2;
        if((strcmp (cari, maks[m].nama) == 0)) {
            pencarian[n] = maks[m];
            n++;
            break;
        } else if((strcmp (cari, maks[m].nama) > 0)) {
        	bawah = m + 1;
    	} else {
    		atas = m - 1;
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
	puts("  a.  Buble Sort - Urut Berdasarkan NPM (Ascending)");
    puts("  b.  Buble Sort - Urut Berdasarkan NPM (Descending)");
    puts("  c.  Buble Sort - Urut Berdasarkan Nama (Ascending)");
    puts("  d.  Buble Sort - Urut Berdasarkan Nama (Descending)");
    puts("  e.  Selection Sort - Urut Berdasarkan NPM (Ascending)");
    puts("  f.  Selection Sort - Urut Berdasarkan NPM (Descending)");
    puts("  g.  Selection Sort - Urut Berdasarkan Nama (Ascending)");
    puts("  h.  Selection Sort - Urut Berdasarkan Nama (Descending)");
    puts("  i.  Insertion Sort - Urut Berdasarkan NPM (Ascending)");
    puts("  j.  Insertion Sort - Urut Berdasarkan NPM (Descending)");
    puts("  k.  Insertion Sort - Urut Berdasarkan Nama (Ascending)");
    puts("  l.  Insertion Sort - Urut Berdasarkan Nama (Descending)");
    garis(120);
    switch(getch()){
		case 'a' : buble_npm_ascending(maks);
		printf(" Menu Pilihan  : Buble Sort - NPM (Ascending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'b' : buble_npm_descending(maks);
        printf(" Menu Pilihan  : Buble Sort - NPM (Descending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'c' : buble_nama_ascending(maks);
        printf(" Menu Pilihan  : Buble Sort - Nama (Ascending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'd' : buble_nama_descending(maks);
        printf(" Menu Pilihan  : Buble Sort - Nama (Descending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
		case 'e' : select_npm_ascending(maks);
        printf(" Menu Pilihan  : Selection Sort - NPM (Ascending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'f' : select_npm_descending(maks);
        printf(" Menu Pilihan  : Selection Sort - NPM (Descending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'g' : select_nama_ascending(maks);
        printf(" Menu Pilihan  : Selection Sort - Nama (Ascending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'h' : select_nama_descending(maks);
        printf(" Menu Pilihan  : Selection Sort - Nama (Descending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'i' : insert_npm_ascending(maks);
        printf(" Menu Pilihan  : Insertion Sort - NPM (Ascending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'j' : insert_npm_descending(maks);
        printf(" Menu Pilihan  : Insertion Sort - NPM (Descending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'k' : insert_nama_ascending(maks);
        printf(" Menu Pilihan  : Insertion Sort - Nama (Ascending)");
        printf("\n Data Telah Berhasil Diurutkan!");
        printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        break;
        case 'l' : insert_nama_descending(maks);
        printf(" Menu Pilihan  : Insertion Sort - Nama (Descending)");
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
		puts("   1.  Sequential Search - Cari Berdasarkan NPM");
	    puts("   2.  Sequential Search - Cari Berdasarkan Nama");
	    puts("   3.  Binary Search - Cari Berdasarkan NPM");
	    puts("   4.  Binary Search - Cari Berdasarkan Nama");
	    puts("  00.  Kembali Ke Menu Awal");
		switch(getch()){
			case '1' : seq_npm();
	        break;
	        case '2' : seq_nama();
	        break;
	        case '3' : bin_npm();
	        break;
	        case '4' : bin_nama();
	        break;
	        case '0' : goto awal;
	        break;
		}	
	}
	while(getch()!=27);
	awal:;
}
int main(int argc, char *argv[]) {
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
	    puts("  1.  Tambah Data");
	    puts("  2.  Tampilkan Data");
	    puts("  3.  Ubah Data");
	    puts("  4.  Hapus Data");
	    puts("  5.  Urutkan Data");
	    puts("  6.  Cari Data");
	    puts(" Esc. Exit\n");
	    switch(getch()){
	        case '1' : tambahdata();
	        garis(120);
	        break;
	        case '2' : tampildata();
	        break;
	        case '3' : ubahdata();
	        break;
	        case '4' : hapusdata();
	        break;
	        case '5' : menuurut();
	        break;
	        case '6' : menucari();
	        break;
	    }
	}
	while(getch()!=27);
    return 0;
}
