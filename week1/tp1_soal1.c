#include <stdio.h>

int main4() {
    double kilometer;
    printf("==================================== \n");
    printf("Masukkan jarak dalam kilometer: ");
    scanf("%lf", &kilometer);
    printf("==================================== \n");
    double meter = kilometer * 1000;
    double centimeter = kilometer * 100000;
    getchar();
    printf("%.2f kilometer = %.2f meter \n", kilometer, meter);
    printf("Enter to continue \n");
    getchar();
    printf("%.2f kilometer = %.2f centimeter \n", kilometer, centimeter);
    return 0;
}
