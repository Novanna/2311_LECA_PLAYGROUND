#include <stdio.h>

int main1() {
    char c;
    int nc = 0;

    printf("Enter a string of characters (press Enter when done):\n");

    while ((c = getchar()) != '\n') {
        nc++;
    }

    printf("Number of characters: %d\n", nc);

    return 0;
}
