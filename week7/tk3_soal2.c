#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data pegawai
struct Pegawai {
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[15];
    char jabatan[50];
    char golongan[3];
};

// Fungsi untuk menampilkan pesan error
void invalidMsg() {
    printf("\n==============================================================\n");
    printf("ERROR\t: Golongan tidak valid");
    printf("\n==============================================================");
}

// Fungsi untuk menampilkan pesan error
void stopMsg() {
    printf("\n==============================================================\n");
    printf("Program berhenti karena terdapat kesalahan");
    printf("\n==============================================================");
}

// Fungsi untuk menghitung gaji berdasarkan golongan
int hitungGajiPokok(char golongan[3]) {
    if (strcmp(golongan, "D1") == 0) {
        return 2500000;
    } else if (strcmp(golongan, "D2") == 0) {
        return 2000000;
    } else if (strcmp(golongan, "D3") == 0) {
        return 1500000;
    } else {
        invalidMsg();
        return 1;
    }
}

// Fungsi untuk menghitung gaji lemburan
int hitungGajiLembur(char golongan[3], int jamLembur) {
    if (strcmp(golongan, "D1") == 0) {
        return 10000 * jamLembur;
    } else if (strcmp(golongan, "D2") == 0) {
        return 5000 * jamLembur;
    } else if (strcmp(golongan, "D3") == 0) {
        return 2500 * jamLembur;
    } else {
        invalidMsg();
        return 1;
    }
}

int main() {
    struct Pegawai pegawai;
    
    printf("==============================================================\n");
    printf("PROGRAM MENGHITUNG GAJI BERDASARKAN GOLONGAN DAN GAJI LEMBURAN\n");
    printf("==============================================================\n");
    
    // Input 1
    printf(">\tMenghitung Gaji Berdasarkan Golongan\t<\n\n");
    printf("NIP\t\t\t: ");
    scanf("%s", pegawai.nip);
    printf("Nama\t\t: ");
    scanf("%s", pegawai.nama);
    printf("Alamat\t\t: ");
    scanf("%s", pegawai.alamat);
    printf("No HP\t\t: ");
    scanf("%s", pegawai.no_hp);
    printf("Jabatan\t\t: ");
    scanf("%s", pegawai.jabatan);
    printf("Golongan\t: ");
    scanf("%s", pegawai.golongan);

    // Process: Hitung gaji pokok
    int gajiPokok = hitungGajiPokok(pegawai.golongan);
    
    // Check return value dari hitungGajiPokok
    if (gajiPokok == 1) {
        // Handle kesalahan dan keluar dari program dengan return value yang sesuai
        stopMsg();
        return 1;
    }
    
    // Output 1
    printf("\n>\tInformasi Gaji Berdasarkan Golongan\t<\n\n");
    printf("NIP\t\t\t: %s\n", pegawai.nip);
    printf("Nama\t\t: %s\n", pegawai.nama);
    printf("Alamat\t\t: %s\n", pegawai.alamat);
    printf("No HP\t\t: %s\n", pegawai.no_hp);
    printf("Jabatan\t\t: %s\n", pegawai.jabatan);
    printf("Golongan\t: %s\n", pegawai.golongan);
    printf("Gaji\t\t: Rp. %d,00\n\n", gajiPokok);

    printf("==============================================================\n");

    // Input 2
    int jamLembur;
    printf(">\tMenghitung Gaji Lemburan\t<\n\n");
    printf("NIP\t\t\t\t\t: ");
    scanf("%s", pegawai.nip);
    printf("Golongan\t\t\t: ");
    scanf("%s", pegawai.golongan);
    printf("Jumlah Jam Lembur\t: ");
    scanf("%d", &jamLembur);

    // Hitung gaji lemburan
    int gajiLembur = hitungGajiLembur(pegawai.golongan, jamLembur);
    
    // Check return value dari hitungGajiPokok
    if (gajiLembur == 1) {
        // Handle kesalahan dan keluar dari program dengan return value yang sesuai
        stopMsg();
        return 1;
    }

    // Output 2
    printf("\n>\tHasil Perhitungan Gaji Lemburan\t<\n\n");
    printf("NIP\t\t\t\t\t\t: %s\n", pegawai.nip);
    printf("Golongan\t\t\t\t: %s\n", pegawai.golongan);
    printf("Lembur\t\t\t\t\t: %d\n", jamLembur);
    printf("Total Gaji Bulan ini\t: Rp. %d,00\n", gajiPokok + gajiLembur);
    
    printf("==============================================================\n");


    return 0; // Exit program dengan sukses
}
