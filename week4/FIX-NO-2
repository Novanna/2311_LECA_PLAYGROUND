#include <stdio.h>
#include <stdlib.h>

int main()
{
    int jam1, jam2, totalJam, biaya;
    float totalDiskon = 0;
    
    // variable constant
    float diskon10 = 0.10;
    float diskon15 = 0.15;
    float diskon20 = 0.20;
    float diskon25 = 0.25;

    // Masukan input jam Mulai dan Jam Berakhir
    printf("                      ***********************");
    printf("\n                      -----Program Billing-----");
    printf("\n                      ***********************");
    printf("\n                        Tarif 1 Jam = Rp 10000 ");
    printf("\n              *******************************************");
    printf("\n");
    printf("\nMasukkan Jam Mulai : ");
    scanf("%d",&jam1);
    printf("********************************\n");
    printf("Masukkan Jam Keluar : ");
    scanf("%d",&jam2);
    
    // Menghitung total jam
    totalJam = jam2 - jam1;
    
    if (totalJam == 0) {
        biaya = 10000;
    } else if (totalJam>0 && totalJam<=4) {
        biaya = totalJam*10000;
    } else if (totalJam>4 && totalJam<=6) {
        totalDiskon = diskon10;
        biaya = (1-totalDiskon)*(totalJam*10000);
    } else if (totalJam>6 && totalJam<=8) { 
        totalDiskon = diskon15;
        biaya = (1-totalDiskon)*(totalJam*10000);
    } else if (totalJam>8 && totalJam<=10) { 
        totalDiskon = diskon20;
        biaya = (1-totalDiskon)*(totalJam*10000);
    } else { 
        totalDiskon = diskon25;
        biaya = (1-totalDiskon)*(totalJam*10000);
    }

    printf("********************************\n");
    printf("Lama Pemakaian: %d jam\n", totalJam);
    printf("Total Diskon: %.0f %\n", totalDiskon*100);
    printf ("Total Biaya : %d Rupiah", biaya);
    
   return 0;
}
