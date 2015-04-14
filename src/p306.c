#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

#define demo_int(X) printf( #X " -> %d\n", (X) );
#define demo_string(X) printf( #X " -> %s\n", (X) );
#define demo_float(X) printf( #X " -> %f\n", (X) );
#define demo(X) demo_int(X)

int main(int argc, char *argv[]) {
    printf("Please enter two integers: ");
    int i1, i2;
    scanf("%d %d", &i1, &i2);
    i2 = i2 ? i2 : 1;
    printf("%d / %d = %d\n", i1, i2, i1 / i2);

}
