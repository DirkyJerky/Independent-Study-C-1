#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

#define demo_int(X) printf( #X " -> %d\n", (X) );
#define demo_string(X) printf( #X " -> %s\n", (X) );
#define demo_float(X) printf( #X " -> %f\n", (X) );
#define demo(X) demo_int(X)

int main(int argc, char *argv[]) {
    for(int i = 0, j = -50, k = i + j; i <= 100; i++, j++, k = i + j) {
        printf("%d\n", k);
    }   
}
