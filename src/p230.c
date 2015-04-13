#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 512

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: cp <src> <dest>\n");
        exit(1);
    } 

    FILE *src, *dest;

    if((src = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open file '%s'\n", argv[1]);
        exit(1);
    }

    if((dest = fopen(argv[2], "w")) == NULL) {
        printf("Unable to open/write file '%s'\n", argv[2]);
        exit(1);
    }

    char curr;
    while((curr = getc(src)) != EOF) {
        putc(curr, dest);
    }

    if(src != NULL) {
        fclose(src);
    }
    if(dest != NULL) {
        fclose(dest);
    }

}
