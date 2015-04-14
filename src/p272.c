#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

int main(int argc, char *argv[]) {
    struct them_bits {
        signed a: 3;
        signed b: 3;
        signed c: 2;
    } example;

    example.a = 1 | 2 | 4 | 8; 
    example.b = -14;
    example.c = 117;
    printf("(1 | 2 | 4 | 8): %d\n-14: %d\n117: %d\n", example.a, example.b, example.c);

   
}
