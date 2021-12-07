#include <stdio.h>

int pangkat(int a, int b) {
	int hasil;
	int i;
	for (i=b; i>1; i--) {
		hasil = hasil*a;
		return hasil;
	}
}

int main() {
	int a, b;
	printf("Masukkan bilangan yang ingin dipangkatkan :");
	scanf("%d", &a);
	printf("Masukkan jumlah pangkat : ");
	scanf("%d", &b);
	printf("Hasil dari %d pangkat %d adalah : %d\n", a, b, pangkat(a, b));
}
