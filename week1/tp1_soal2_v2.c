#include <stdio.h>

int main() {
    char pilihan;

    do {
        double totalBelanja;
        int jumlahTransaksi;

        printf("==================================== \n");

        printf("Masukkan total belanja: ");
        scanf("%lf", &totalBelanja);

        printf("Masukkan jumlah transaksi dalam sebulan: ");
        scanf("%d", &jumlahTransaksi);

        double diskon = 0.0;

        if (totalBelanja >= 200000 && totalBelanja < 500000) {
            diskon = 0.1;
        } else if (totalBelanja >= 550000 && totalBelanja <= 1000000) {
            diskon = 0.2;
        } else if (totalBelanja > 1000000) {
            diskon = 0.3;
        }

        if (jumlahTransaksi >= 4) {
            diskon += 0.2;
        }

        double totalDiskon = totalBelanja * diskon;
        double hargaBayar = totalBelanja - totalDiskon;

        printf("Harga yang harus dibayar setelah diskon: %.2lf\n", hargaBayar);

        printf("==================================== \n");


        printf("Apakah Anda ingin melakukan perhitungan lagi? (Y/N): ");
        scanf(" %c", &pilihan); // Menggunakan " %c" untuk membersihkan karakter newline

    } while (pilihan == 'Y' || pilihan == 'y');

    return 0;
}
