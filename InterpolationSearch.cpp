#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int konversi(int x);
struct data {
	char nama[10];
	int angka;
};
data buah[10] = {
					{"Mangga", konversi(0)},
					{"Durian", konversi(1)},
					{"Leci", konversi(2)},
					{"Anggur", konversi(3)},
					{"Sawo", konversi(4)},
					{"Nangka", konversi(5)},
					{"Pear", konversi(6)},
					{"Manggis", konversi(7)},
					{"Kiwi", konversi(8)},
					{"Apel", konversi(9)},
};

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
	printf("PROGRAM INTERPOLATION SEARCH\n");
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
    int pjg = strlen(buah[x].nama);
    for(i = 0; i < pjg; i++) {
        digit = buah[x].nama[i];
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

void urut_ascending() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < 9; f++) {
 		min = f;
	 	for (g = f+1; g < 10; g++) {
	 		if (buah[min].angka > buah[g].angka) {
	 			min = g;
	 		}
	 	}
	 	temp = buah [f];
 		buah [f] = buah [min];
 		buah [min] = temp;
	}
}

int interpolation_search(int kunci) {
    int tengah;
    int bawah = 0;
    int atas = 9;
    while (bawah <= atas) {
        tengah = bawah + (atas - bawah)*((kunci-buah[bawah].angka)/(buah[atas].angka-buah[bawah].angka));
        if (kunci == buah[tengah].angka)
            return tengah + 1;
        if (kunci < buah[tengah].angka)
            atas = tengah - 1;
        else
            bawah = tengah + 1;
    }
    return -1;
}

int main() {
	system("color 70");
	char string[10];
	int i, posisi;
	int kunci;
	do {
		system("cls");
		urut_ascending();
		garis(120);
			header("Muhammad Alviriza Ramadhan", "20081010143", 
					"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
		garis(120);
		printf("\n Berikut ini adalah daftar nama-nama buah yang tersedia : \n");
		printf(" ");
		for (i = 0; i < 10; i++) {
			if(i <= 8) {
				printf("%s, ",buah[i].nama);
			} else {
				printf("%s.",buah[i].nama);
			}
		
		}
		printf("\n\n");
		garis(120);
		printf(" Masukkan nama buah yang ingin dicari : ");
		fflush(stdin);
		scanf("%s", string);
		kunci = konvertcari(string);
//		printf(" %i\n", kunci);
		garis(120);
		posisi = interpolation_search(kunci);
	    if (posisi == -1) {
	    	printf("\n Buah %s Tidak Ditemukan!\n\n", string);
		} 
	    else {
	    	printf("\n Buah %s ditemukan pada index ke %d.\n\n", string, posisi);
		}
		garis(120);	
		printf(" Tekan ENTER untuk melakukan lagi. \n");
		printf(" Tekan ESC untuk keluar dari program. \n");
	}
	while(getch()!=27);
}
