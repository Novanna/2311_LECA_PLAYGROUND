#include <stdio.h>

int main() {
    int jumlahMahasiswa, i;
    double nilaiQuis, nilaiTugas, nilaiAbsensi, nilaiPraktek, nilaiUAS, nilaiRataRata;
    char grade;
    int tidakLulus = 0;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlahMahasiswa);

    for (i = 1; i <= jumlahMahasiswa; i++) {
        printf("Mahasiswa ke-%d\n", i);
        printf("Nilai Quis: ");
        scanf("%lf", &nilaiQuis);
        printf("Nilai Tugas: ");
        scanf("%lf", &nilaiTugas);
        printf("Nilai Absensi: ");
        scanf("%lf", &nilaiAbsensi);
        printf("Nilai Praktek: ");
        scanf("%lf", &nilaiPraktek);
        printf("Nilai UAS: ");
        scanf("%lf", &nilaiUAS);

        nilaiRataRata = (nilaiQuis + nilaiTugas + nilaiAbsensi + nilaiPraktek + nilaiUAS) / 5.0;

        if (nilaiRataRata <= 55) {
            grade = 'E';
            tidakLulus++;
        } else if (nilaiRataRata <= 65) {
            grade = 'D';
            tidakLulus++;
        } else if (nilaiRataRata <= 75) {
            grade = 'C';
        } else if (nilaiRataRata <= 85) {
            grade = 'B';
        } else if (nilaiRataRata <= 100) {
            grade = 'A';
        } else {
            printf("Input nilai tidak valid.\n");
            return 1; // Keluar program dengan kode error
        }

        printf("Rata-rata nilai mahasiswa ke-%d: %.2lf (Grade %c)\n", i, nilaiRataRata, grade);
    }

    if (tidakLulus > 0) {
        printf("Tidak Lulus: %d mahasiswa\n", tidakLulus);
    } else {
        printf("Semua mahasiswa Lulus.\n");
    }

    return 0;
}
