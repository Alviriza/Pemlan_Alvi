#include <stdio.h>
#include <windows.h>

int i,j,t;
int n = 6; 
int A[6] = {22, 10, 15, 3, 8, 2};

void garis(int x) {
	int a;
	for(a = 0; a < x; a++) {
		printf("=");
	}
	printf("\n");
}

void header(char nama[50], char npm[50], 
			char kelas[10], char matkul[50], char dosen[50]) 
{
	garis(50);
	int a;
	printf("\t\tPROGRAM BUBLE SORT\n");
	garis(50);
	printf("Nama\t\t: %s\n", nama);
	printf("NPM\t\t: %s\n", npm);
	printf("Kelas\t\t: %s\n", kelas);
	printf("Matkul\t\t: %s\n", matkul);
	printf("Dosen Pengampu\t: %s\n", dosen);
	garis(50);
}

void tampilarray() {
	printf("\nElemen Array nya adalah : ");
    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");
    garis(50);
}

void bublesort_ascending() {
	for(i=0; i<=(n-1); i++) {
        for(j=n; j>=(i+1); j--) {
            if(A[j-1] > A[j]) {
                t = A[j-1];
                A[j-1] = A[j];
                A[j] = t;
            }
        }
    }
}

void bublesort_descending() {
	for(i=1; i<=(n-1); i++) {
        for(j=n; j>=(i+1); j--) {
            if(A[j-1] < A[j]) {
                t = A[j-1];
                A[j-1] = A[j];
                A[j] = t;
            }
        }
    }
}

void tampildata() {
	printf("\nUrutan Ascendingnya adalah : ");
	bublesort_ascending();
    for(i=1; i<=n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("\nUrutan Descendingnya adalah : ");
	bublesort_descending();
    for(i=1; i<=n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");
    garis(50);
}

int main() {
	system("color 70");
	header("Muhammad Alviriza Ramadhan", "20081010143", 
				"D081", "Pemrograman Lanjut", "Fawwaz Ali Akbar, S.Kom, M.Kom");
	tampilarray();
	tampildata();
    return 0;
}
