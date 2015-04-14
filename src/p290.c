#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

#define demo(X) printf( #X " -> %d\n", X );

int sum_it(int value) {
    static int total = 0;
    total += value;
    return total;
}

int main(int argc, char *argv[]) {
    demo(sum_it(3))
    demo(sum_it(6))
    demo(sum_it(4))
}
