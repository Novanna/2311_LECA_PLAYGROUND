#include <stdio.h>

int main5() {
    double totalBelanja;
    int jumlahTransaksi;

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

    return 0;
}
