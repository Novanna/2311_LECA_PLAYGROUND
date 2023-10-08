#include <stdio.h>

// Fungsi untuk menghitung kupon undian dan diskon
void hitungPromo(int totalPembelian, int *kuponUndian, int *diskon) {
    // Check jika total pembelian kurang dari Rp. 100.000,00
    if (totalPembelian < 100000) {
        printf("Maaf, total pembelian kurang dari Rp. 100.000,00.\n");
        *kuponUndian = 0;
        *diskon = 0;
    } else {
        // Hitung kupon undian
        *kuponUndian = totalPembelian / 100000;

        // Hitung diskon, kali hasil kuponUndian
        *diskon = ((5 * totalPembelian) / 100) * *kuponUndian;
    }
}

int main() {
    int totalPembelian, kuponUndian, diskon;

    // Input total pembelian dengan error check
    printf("Masukkan total pembelian (Rp): ");
    if (scanf("%d", &totalPembelian) != 1 || totalPembelian <= 0) {
        printf("Input tidak valid.\n");
        return 1; // Exit program dengan error code 1
    }

    // Panggil fungsi untuk menghitung kupon undian dan diskon
    hitungPromo(totalPembelian, &kuponUndian, &diskon);

    // Output hasil
    printf("Total kupon undian: %d lembar\n", kuponUndian);
    printf("Diskon: Rp. %d,00\n", diskon);
    printf("Total yang dibayar: Rp. %d,00\n", totalPembelian - diskon);

    return 0; // Exit program dengan sukses
}
