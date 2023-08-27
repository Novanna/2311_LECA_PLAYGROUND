#include <stdio.h>

void convertToTime(int totalSeconds, int *hours, int *minutes, int *seconds) {
    *hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    *minutes = totalSeconds / 60;
    *seconds = totalSeconds % 60;
}

int main2() {
    int totalSeconds, hours, minutes, seconds;

    printf("Enter total seconds: ");
    scanf("%d", &totalSeconds);

    convertToTime(totalSeconds, &hours, &minutes, &seconds);

    printf("Converted time: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    return 0;
}
