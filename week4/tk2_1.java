#include <stdio.h>

int main() {
    int totalJam;
    double hargaPerJam = 10000.0;
    double totalBayar;

    printf("Selamat datang di Game Online!\n");
    printf("Masukkan total jam pemakaian: ");
    scanf("%d", &totalJam);

    if (totalJam > 8) {
        totalBayar = totalJam * hargaPerJam * 0.75; // Diskon 25%
    } else if (totalJam > 6) {
        totalBayar = totalJam * hargaPerJam * 0.80; // Diskon 20%
    } else if (totalJam > 4) {
        totalBayar = totalJam * hargaPerJam * 0.85; // Diskon 15%
    } else if (totalJam > 0) {
        totalBayar = totalJam * hargaPerJam; // Tidak ada diskon
    } else {
        printf("Total jam pemakaian tidak valid.\n");
        return 1; // Keluar program dengan kode error
    }

    printf("Total biaya yang harus dibayarkan: Rp %.2lf\n", totalBayar);

    return 0;
}
