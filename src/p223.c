#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_BUF 512

#define ALPHABET 26

int main(int argc, char *argv[]) {
    FILE *fp;
    int count[ALPHABET];
    char curr;

    for(int i = 0; i < ALPHABET; i++) {
        count[i] = 0;
    }

    if(argc != 2) {
        printf("Usage: <file>\n");
        exit(1);
    }
    
    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file");
        exit(1);
    }

    while ((curr = fgetc(fp)) != EOF) {
        curr = toupper(curr);
        if ('A' <= curr && curr <= 'Z') {
            curr -= 'A';
            count[curr]++;
        }
    }


    for(int i = 0; i < ALPHABET; i++) {
        printf("'%c': %d\n", (i + 'A'), count[i]);
    }

}
