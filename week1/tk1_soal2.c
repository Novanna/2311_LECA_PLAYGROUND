#include <stdio.h>

int main3() {
    char kalimat1[100], kalimat2[100], kalimat3[100], gabungan[300], reversed[300];
    int totalHuruf = 0;

    printf("Masukkan Kalimat 1: ");
    scanf("%s", kalimat1);

    printf("Masukkan Kalimat 2: ");
    scanf("%s", kalimat2);

    printf("Masukkan Kalimat 3: ");
    scanf("%s", kalimat3);

    // Menggabungkan kalimat
    // Menggabungkan kalimat
    sprintf(gabungan, "%s %s %s", kalimat1, kalimat2, kalimat3);

    // Membalik kalimat gabungan
    int len = strlen(gabungan);
    for (int i = 0; i < len; i++) {
        reversed[i] = gabungan[len - i - 1];
    }
    reversed[len] = '\0';

    // Menghitung jumlah huruf
    totalHuruf = strlen(kalimat1) + strlen(kalimat2) + strlen(kalimat3);

    // Menampilkan hasil
    printf("Gabungan 3 buah inputan kalimat = %s\n", gabungan);
    printf("Hasil membalik kalimat gabungan = %s\n", reversed);
    printf("Jumlah Huruf kalimat pertama = %d\n", strlen(kalimat1));
    printf("Jumlah Huruf kalimat kedua = %d\n", strlen(kalimat2));
    printf("Jumlah Huruf kalimat ketiga = %d\n", strlen(kalimat3));
    printf("Total Jumlah huruf = %d\n", totalHuruf);

    return 0;
}
