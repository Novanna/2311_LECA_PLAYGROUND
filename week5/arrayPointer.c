#include<stdio.h>

int main() {
    char kata[] = "aku berharap kamu ada disini";
    printf("Output 1: %s\n", kata);
    printf("Output 2: %s\n", kata);
    
    printf("\n--------------------------------------- \n");

    int kategori[][4] = {{2000, 1998},{17,18,22,25}};
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++) {
            printf("kategori[%d][%d]: %d\n", i,j,kategori[i][j]);
        }
    }
    
    printf("\n--------------------------------------- \n");
    
    int *level;
    int kelas = 7;
    level = &kelas;
    printf("level: %d, kelas: %d\n", *level, kelas);
    printf("memory location:\n[level] %p \n[kelas] %p \n", &level, &kelas);
    
    printf("\n--------------------------------------- \n");

    kelas = 17;
    printf("level: %d, kelas: %d\n", *level, kelas);
    printf("memory location:\n[level] %p \n[kelas] %p \n", &level, &kelas);
    
    printf("\n--------------------------------------- \n");
    
    int num1 = 19, num2 = 20, *numPointer;
    numPointer = &num1;
    numPointer = &num2;
    printf("num1: %d, num2: %d numPointer: %d\n", num1, num2, *numPointer);
    
    int numRay[5] = {99,98,97,96,95};
    int loc = 3;
    int *pointer2 = &numRay[--loc];
    // printf("loc: %d\n", loc);
    printf("numRay: %d, pointer2: %d\n", numRay[loc], *pointer2);
    // printf("loc: %d\n", loc);
    printf("memory location:\n[numRay] %p \n[pointer2] %p \n", &numRay[loc], &pointer2);
    // printf("loc: %d\n", loc);
    
    return 0;
}
