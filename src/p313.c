#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

#define demo_int(X) printf( #X " -> %d\n", (X) );
#define demo_string(X) printf( #X " -> %s\n", (X) );
#define demo_float(X) printf( #X " -> %f\n", (X) );
#define demo(X) demo_int(X)

void showBinary(char c) {
    for(int i = 128; i != 0; i /= 2) {
        if(c & i) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
}

int main(int argc, char *argv[]) {
    char test;
    printf("Please enter a character: ");
    scanf("%c", &test);
    showBinary(test); putchar('\n');
    char leftS = (test << 4), 
         rightS = (test >> 4);
    char result = (leftS | rightS);
    printf("Swapped bits --> %c\n", result);
    showBinary(result); putchar('\n');
}
