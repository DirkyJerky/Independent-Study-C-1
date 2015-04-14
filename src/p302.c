#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

#define demo(X) printf( #X " -> %d\n", X );

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *fp;

    if((fp = fopen(argv[1], "r+")) == NULL) {
        printf("Unable to open \"%s\"\n", argv[1]);
        exit(1);
    }

    char ch;
    char flip;

    long int location;        

    while((ch = getc(fp)) != EOF) {
        location = ftell(fp);
        location--;
        fseek(fp, location, SEEK_SET);
        flip = ~ch;
        putc(flip, fp);
    }
}
